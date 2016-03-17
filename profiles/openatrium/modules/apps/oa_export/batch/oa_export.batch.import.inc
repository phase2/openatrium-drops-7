<?php

//require_once '../entity/oa_export.entity.import.inc';
//require_once '../menus/oa_export.menus.import.inc';

/**
 * Prepare the import and create a batch process.
 *
 * @param object $data
 *   The file that contains the export data.
 * @param string $import_type
 *   Defaults to 'file' but could also be 'module'. This will allow to define different types of exports when
 *   triggering an import.
 */
function oa_export_batch_import($data, $import_type = 'file') {

  $batch = array(
    'title' => t('Importing Blueprint'),
    'init_message' => t('Preparing to import the blueprint'),
    'finished' => 'oa_export_import_batch_finished',
    'file' => drupal_get_path('module', 'oa_export') . '/oa_export.batch.import.inc',
  );

  switch ($import_type) {
    case 'file':
      // Define batch operations.
      oa_export_batch_file_download_operations($batch, $data);
      break;

    case 'module':
      oa_export_batch_module_import_operations($batch, $data);
      break;

    default:
      break;
  }

  if (drupal_is_cli()) {
    $batch['progressive'] = FALSE;
    batch_set($batch);
    if (function_exists('drush_backend_batch_process')) {
      // Running via drush, to start the batch processing.
      drush_backend_batch_process();
    }
  }
  else {
    // Running interactively via form submission, so just set the batch.
    batch_set($batch);
    if ($import_type == 'module') {
      batch_process('/');
    }
  }
}

/**
 * Defines batch operations for the batch.
 *
 * @param array $batch
 *   The current batch.
 * @param object $file
 *   The file that contains the export data.
 */
function oa_export_batch_file_download_operations(&$batch, $file) {

  // Extracts the archive.
  $batch['operations'][] = array('_oa_export_batch_import_archive', array($file));

  oa_export_batch_combined_operations($batch);
}

/**
 * Defines batch operations for the batch.
 *
 * @param array $batch
 *   The current batch.
 * @param object $data
 *   The export data.
 */
function oa_export_batch_module_import_operations(&$batch, $path) {

  // Extracts the archive.
  $batch['operations'][] = array('_oa_export_batch_import_module_data', array($path));

  oa_export_batch_combined_operations($batch);
}

function oa_export_batch_combined_operations(&$batch) {
  // Imports the entities.
  $batch['operations'][] = array('_oa_export_batch_import_entities', array());
  // Imports menus for the entities.
  $batch['operations'][] = array('_oa_export_batch_import_menus', array());

  // Imports group metadata such as roles and permissions. @todo: Fix this...
//  $batch['operations'][] = array('_oa_export_batch_import_metadata', array());
}

/**
 * Extract the file being imported and store the entities in the batch context.
 *
 * @param object $file
 *   The file that contains the export data.
 * @param array $context
 *   Passed around between batch operations.
 * @throws Exception
 *
 * @see update_manager_archive_extract().
 */
function _oa_export_batch_import_archive($file, &$context) {

  if (empty($context['sandbox']['max'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = 1;
    $context['results']['total'] = (!empty($context['results']['total']) ? $context['results']['total'] : 0) + $context['sandbox']['max'];
  }

  // The temporary directory to extract files to.
  $directory = file_directory_temp();

  $archiver = archiver_get_archiver($file->uri);
  if (!$archiver) {
    throw new Exception(t('Cannot extract %archive, not a valid archive.', array ('%archive' => $file)));
  }

  // Remove the directory if it exists, otherwise it might contain a mixture of
  // old files mixed with the new files (e.g. in cases where files were removed
  // from a later release).
  $files = $archiver->listContents();

  // Unfortunately, we can only use the directory name to determine the project
  // name. Some archivers list the first file as the directory (i.e., MODULE/)
  // and others list an actual file (i.e., MODULE/README.TXT).
  $project = strtok($files[0], '/\\');

  $extraction_location = $directory . '/' . $project;
  if (file_exists($extraction_location)) {
    file_unmanaged_delete_recursive($extraction_location);
  }

  $archiver->extract($directory);

  // Get the actual path to our json file that contains our entities.
  $real_path = realpath($extraction_location . '/' . OA_EXPORT_JSON_FILE . '.json');

  // Store the entities.
  $context['results']['entities'] = oa_export_import_decode_data($real_path);
  // Will store a map for new entity ids.
  $context['results']['map'] = array();

  // Store the location we will be extracting the file contents to.
  $_SESSION['oa_export']['extract_location'] = $extraction_location;

  // Bump the progress indicator.
  $context['sandbox']['progress']++;

  // We are finished un-archiving the entities.
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
 * Extract the file being imported and store the entities in the batch context.
 *
 * @param string $path
 *   The realpath to the oa_export directory in the module.
 * @param array $context
 *   Passed around between batch operations.
 * @throws Exception
 *
 * @see update_manager_archive_extract().
 */
function _oa_export_batch_import_module_data($path, &$context) {

  if (empty($context['sandbox']['max'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = 1;
    $context['results']['total'] = (!empty($context['results']['total']) ? $context['results']['total'] : 0) + $context['sandbox']['max'];
  }

  // This is where the import looks for files.
  $_SESSION['oa_export']['extract_location'] = $path;

  // Decode the json file and store the entities for the batch.
  $context['results']['entities'] = oa_export_import_decode_data($path . '/' . OA_EXPORT_JSON_FILE . '.json');
  // Will store a map for new entity ids.
  $context['results']['map'] = array();

  // Bump the progress indicator.
  $context['sandbox']['progress']++;

  // We are finished un-archiving the entities.
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
 * Imports the entities.
 *
 * @param array $context
 *   Passed around between batch operations.
 */
function _oa_export_batch_import_entities(&$context) {

  if (empty($context['sandbox']['max'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = 1;
    $context['results']['total'] = (!empty($context['results']['total']) ? $context['results']['total'] : 0) + $context['sandbox']['max'];
    $context['results']['ids_key'] = array();
  }

  $entities = $context['results']['entities'];

  $map = &$context['results']['map'];

  // Allows un-setting entity types that you may not want to import.
  drupal_alter('oa_import_remove_entity', $entities);

  // Iterate over the entities and try to import them.
  foreach ($entities as $key => &$entity) {

    // Get the entity type and its original id.
    list($entity_type, $entity_id) = explode(':', $key);

    // The new entity id if it hasn't been imported yet, FALSE if it has.
    $new_id = oa_export_import($entity_type, $entity, $key, $entities, $map);
  }

  // Bump the progress indicator.
  $context['sandbox']['progress']++;

  // We are finished with the import.
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
 * Imports the entities.
 *
 * @param array $context
 *   Passed around between batch operations.
 */
function _oa_export_batch_import_menus(&$context) {

  $imports = $context['results']['entities'];
  $map = $context['results']['map'];

  // Iterate over entities looking for menu entries.
  foreach ($imports as $key => $import) {
    if (isset($imports['menu:' . $key])) {
      // Get entity type.
      list($entity_type, $old_id) = explode(':', $key);
      // Found a menu array for this entity.
      oa_export_menus_import($imports['menu:' . $key], $old_id, $map[$key], $entity_type, $map);
    }
  }

  // We are finished with the import.
  $context['finished'] = 1;
}

/**
 * Decides if an entity is imported and adds new entity ids to the map.
 *
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param object $entity
 *   The fully loaded entity.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 *
 * @return integer
 *   The entity id of the entity that was imported.
 */
function oa_export_import($entity_type, $entity, $key, &$imports, &$map) {
  // Check if entity has already been mapped
  if (isset($map[$key])) {
    $new_id = $map[$key];
  }
  else {
    $new_id = FALSE;
    $info = entity_get_info($entity_type);
    if (!empty($info)) {
      // We are importing a proper entity.
      $new_id = oa_export_entity_import($entity_type, $entity, $key, $imports, $map);
    }
    if (($new_id !== FALSE) && !isset($map[$key])) {
      $map[$key] = $new_id;
    }
  }

  return $new_id;
}

/**
 * Finish function for the batch process.
 *
 * @param bool $success
 *   TRUE if the batch succeeds.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 * @param $operations
 */
function oa_export_import_batch_finished($success, $results, $operations) {
  if ($success && isset($results['messages'])) {
    foreach ($results['messages'] as $message) {
      drupal_set_message($message, 'status');
    }
    // Count the number of entities, links, permissions etc.
    $entity_count = count($results['entities']);
    drupal_set_message(t('Successfully imported !count items.', array('!count' => $entity_count)));
  }
}
