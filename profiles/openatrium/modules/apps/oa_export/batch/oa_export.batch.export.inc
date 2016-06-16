<?php

//require_once '../entity/oa_export.entity.export.inc';
//require_once '../fields/oa_export.fields.export.inc';

/**
 * Prepare the export and create a batch process.
 *
 * @param object $blueprint
 *   The fully loaded blueprint entity.
 * @param string $export_type
 *   Defaults to 'file' but could also be 'module'. This will allow to define different types of exports when
 *   triggering an export.
 */
function oa_export_batch_export($blueprint, $export_type = 'file') {

  switch ($export_type) {
    case 'file':
      // Start storing session variables for file download.
      $_SESSION['oa_export'] = array();

      // Store the export directory in the session variable.
      if ($_SESSION['oa_export']['directory'] = oa_export_create_temp_export_directory($blueprint->name, file_directory_temp())) {
        // Create the file directory.
        $file_dir = oa_export_create_directories($_SESSION['oa_export']['directory'] . '/' . OA_EXPORT_FILES);
        if ($file_dir) {
          // Store the files directory in session. It is needed later when copying files.
          $_SESSION['oa_export']['files_directory'] = $file_dir;

          // Temporary directory for system. Gets the path of system-appropriate temporary directory.
          $tmp_dir = file_directory_temp();
          if (!is_writable($tmp_dir)) {
            drupal_set_message(t('In order for this export to work "%dir" needs to be writable.', array('%dir' => $tmp_dir)), 'error');
            oa_export_cleanup($_SESSION['oa_export']['directory'], OA_EXPORT_REDIRECT);
          }

          $batch = array(
            'title' => t('Blueprint Download'),
            'init_message' => t('Preparing to download "!name" blueprint to a file.', array('!name' => $blueprint->name)),
            'finished' => 'oa_export_batch_file_download_finished',
          );

          // Defines batch operations for the batch.
          oa_export_batch_export_operations($batch, $blueprint);

          batch_set($batch);
          // Redirect the user to a page to download the file.
          batch_process('oa_export/download');
        }
        else {
          drupal_set_message(t('Could not create @file_dir', array('@file_dir' => $file_dir)), 'error');
          oa_export_cleanup($_SESSION['oa_export']['directory'], OA_EXPORT_REDIRECT);
        }
      }
      else {
        drupal_set_message(t('Could not create a directory in your system temporary directory.'), 'error');
        oa_export_cleanup($_SESSION['oa_export']['directory'], OA_EXPORT_REDIRECT);
      }
      break;

    case 'module':
      $batch = array(
        'title' => t('Blueprint Module Export'),
        'init_message' => t('Preparing to export the "!name" blueprint to a module.', array('!name' => $blueprint->name)),
        'finished' => 'oa_export_batch_module_export_finished',
      );

      // Defines batch operations for the batch.
      oa_export_batch_export_operations($batch, $blueprint);

      batch_set($batch);
      break;

    default:
      break;
  }
}

/**
 * Defines batch operations for the file download batch.
 *
 * @param array $batch
 *   The current batch.
 * @param object $blueprint
 *   The fully loaded blueprint entity.
 */
function oa_export_batch_export_operations(&$batch, $blueprint) {

  // Get the entity reference of the space this blueprint is built on.
  $wrapper = entity_metadata_wrapper('taxonomy_term', $blueprint);
  $space = $wrapper->{BLUEPRINT_SPACE}->value();

  // The blueprint.
  $batch['operations'][] = array('_oa_export_batch_export_blueprint', array($blueprint, $space));

  // Entities that are sub groups of the space.
  //
  // @todo: Possibly create two directories: previous/last to store ids of the
  // export/import which might allow us to re-create exports without duplicate
  // content.
  $groups = oa_core_get_groups_by_parent($space->nid, NULL, NULL, FALSE, NULL, TRUE);

  // Iterate over the sub groups.
  foreach ($groups as $id) {
    // Load the sub group entity.
    $entity = entity_load_single('node', $id);

    // Define a batch operation to export the entity.
    $batch['operations'][] = array('_oa_export_batch_export_dependency', array($entity));
  }
}

/**
 * A batch operation to export a blueprint. We want to export the blueprint but don't want the parents of the space the
 * blueprint is being built on.
 *
 * @param object $blueprint
 *   The fully loaded blueprint entity.
 * @param object $space
 *   The space being exported.
 * @param array $context
 *   Passed around between batch operations.
 */
function _oa_export_batch_export_blueprint($blueprint, $space, &$context) {

  // As of now we only allow one blueprint export at a time.
  if (empty($context['sandbox']['max'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = 1;
    $context['results']['export'] = array();
    $context['results']['messages'] = array();
    $context['results']['total'] = (!empty($context['results']['total']) ? $context['results']['total'] : 0) + $context['sandbox']['max'];
  }

  // Store the reference to the space the blueprint is referencing.
  $space_reference = $blueprint->field_oa_clone_space;

  // Export the blueprint.
  oa_export_entity_export('taxonomy_term', $blueprint, $context['results']);

  // Put the reference to the space back so we can reference it during our import.
  $context['results']['export']['taxonomy_term:' . $blueprint->tid]->field_oa_clone_space = $space_reference;

  // Remove the oa_parent_space reference so we don't get this space's parent space and all of its dependencies.
  $space->oa_parent_space = array();

  // Export the space without reference to its parent space.
  oa_export_entity_export('node', $space, $context['results']);

  // Bump the progress indicator.
  $context['sandbox']['progress']++;

  // We are finished with a single space.
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
 * Exports an entity that is a dependency for this blueprint.
 *
 * @param object $entity
 *   The entity that is being exported.
 * @param array $context
 *   Passed around between batch operations.
 */
function _oa_export_batch_export_dependency($entity, &$context) {

  // As of now we only allow one blueprint export at a time.
  if (empty($context['sandbox']['max'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = 1;
    $context['results']['total'] = (!empty($context['results']['total']) ? $context['results']['total'] : 0) + $context['sandbox']['max'];
  }

  // Export the entity.
  oa_export_entity_export('node', $entity, $context['results']);

  // Bump the progress indicator.
  $context['sandbox']['progress']++;

  // We are finished with a single space.
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
 * Finish function for the batch process.
 *
 * @param bool $success
 *   TRUE if the batch succeeds.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 * @param $operations
 * @throws Exception
 */
function oa_export_batch_file_download_finished($success, $results, $operations) {
  if ($success) {
    try {
      // Generate a file name that matches our directory.
      $base = basename($_SESSION['oa_export']['directory']);
      $tmp_dir = file_directory_temp();
      $_SESSION['oa_export']['file'] = $tmp_dir . '/' . $base . '.tar.gz';

      // Create a json file to add to our export directory that contains the blueprint.
      if (!oa_export_create_json_export(OA_EXPORT_JSON_FILE, $results['export'], $_SESSION['oa_export']['directory'])) {
        drupal_set_message(t('There was an error creating the export file.'), 'error');
        oa_export_cleanup(isset($clean_dir) ? $clean_dir : NULL, OA_EXPORT_REDIRECT);
      }
      else {
        // Build a compressed file from our blueprint.
        $new_tar = new Archive_Tar($_SESSION['oa_export']['file']);

        // We call this directly so we can modify the directory structure for our
        // tar file. This will remove the base directory from the tar.
        $new_tar->createModify(array($_SESSION['oa_export']['directory']), '', $tmp_dir);

        // Get the public file directory.
        $public = variable_get('file_public_path', conf_path() . '/files');

        // Copy the compressed file to a path we can download.
        if ($copy = file_unmanaged_copy($_SESSION['oa_export']['file'], $public, FILE_EXISTS_REPLACE)) {
          $_SESSION['oa_export']['download_path'] = $copy;
        }
        else {
          drupal_set_message(t('There was a problem copying the export to !public', array('!public' => $public), 'error'));
          oa_export_cleanup($_SESSION['oa_export']['directory'], OA_EXPORT_REDIRECT);
        }

        // Display a message telling the user the export is done.
        drupal_set_message(t('Finished exporting your Blueprint. Check below for notices.'), 'status');
        foreach ($results['messages'] as $message) {
          // Messages should already be formatted correctly with t().
          drupal_set_message($message, 'warning');
        }
        if (isset($_SESSION['oa_export']['module'])) {
          // Just remove the oa_export directory. Doesn't matter if this is a new or existing module. We should have
          // an archive now so we don't need it.
          oa_export_cleanup($_SESSION['oa_export']['directory'], OA_EXPORT_REDIRECT);
        }
      }
    }
    catch (Exception $e) {
      drupal_set_message(t('Error: %message', array('%message' => $e->getMessage())));
      // If this is a new module it removes the module other wise just removes the oa_export directory, clears session
      // storage and redirects the user.
      oa_export_cleanup($_SESSION['oa_export']['directory'], OA_EXPORT_REDIRECT);
    }
  }
  else {
    drupal_set_message(t('The batch export was unsuccessful'), 'error');
    // If this is a new module it removes the module other wise just removes the oa_export directory, clears session
    // storage and redirects the user.
    oa_export_cleanup($_SESSION['oa_export']['directory'], OA_EXPORT_REDIRECT);
  }
}

function oa_export_batch_module_export_finished($success, $results, $operations) {
  $module_path = drupal_get_path('module', $_SESSION['oa_export']['module']);
  if ($_SESSION['oa_export']['type'] == 'new') {
    $export_path = $module_path;
  }
  else if ($_SESSION['oa_export']['type'] == 'existing') {
    $export_path = $module_path . '/' . OA_EXPORT_DIR;
  }
  if ($success) {
    // Create a json file to add to the oa_export directory in our module.
    $file = oa_export_create_json_export(OA_EXPORT_JSON_FILE, $results['export'], $module_path . '/' . OA_EXPORT_DIR);
    // Make sure the file in place and give the user a message accordingly. If the file was successfully written
    // then we know the module was created as well.
    if ($file) {
      // Let the user know the module was created.
      drupal_set_message(
        t('The @module module was created at @location.', array(
          '@module' => $_SESSION['oa_export']['module'],
          '@location' => $module_path)
        ), 'status'
      );
      // Give them a brief instructions on what they can do now.
      $message = 'If you exported the blueprint as a new module then just enable the module on the system you want to import the blueprint to. ';
      $message .= 'If you exported the blueprint to an existing module, update the existing module on the system you are running the import and run a database update.';
      drupal_set_message(t($message), 'warning');
      // Clean up any old exports
      if (file_exists($module_path . '/' . OA_EXPORT_TEMP_DIR)) {
        file_unmanaged_delete_recursive($module_path . '/' . OA_EXPORT_TEMP_DIR);
      }
      // Clean up just the session variables.
      oa_export_cleanup();
    }
    else {
      drupal_set_message(t('Unable to create the file for the entity export!'), 'error');
      oa_export_cleanup($export_path, OA_EXPORT_REDIRECT);
    }
  }
  else {
    drupal_set_message(t('The batch finished but something went wrong. Try again or contact your system administrator.'), 'error');
    oa_export_cleanup($export_path, OA_EXPORT_REDIRECT);
  }
}

/**
 * Helper function that handles the file download.
 */
function oa_export_batch_file_download_finished_redirect() {

  if (empty($_SESSION['oa_export']['directory']) || empty($_SESSION['oa_export']['file'])) {
    return t('The file cannot be found.');
  }

  // Redirect to the download file.
  $redirect = base_path() . $_SESSION['oa_export']['download_path'];
  drupal_add_js('setTimeout(function() { window.location.href = "' . $redirect . '"; }, 2000);', 'inline');

  // Remove the temporary directory we created.
  oa_export_remove_directory($_SESSION['oa_export']['directory']);

  $output = theme('blueprint_download_page', array());

  // Remove the temporary tar file.
  unlink($_SESSION['oa_export']['file']);

  // Clear the session variables we stored.
  oa_export_cleanup();

  return $output;
}
