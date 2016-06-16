<?php
/**
 * @file
 * oa_export.entity.import.inc
 *
 * Imports entities.
 */

/**
 * Helper function to import entities.
 *
 * This is what handles importing anything associated with the entity.
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
function oa_export_entity_import($entity_type, $entity, $key, $imports, &$map) {
  if (isset($map[$key])) {
    return $map[$key];
  }

  if (!isset($entity)) {
    return FALSE;
  }

  // Make sure this entity hasn't been imported already.
  if (!isset($entity->oa_imported)) {

    // Otherwise, load entity from import data.
    foreach (module_implements('oa_import_entity_' . $entity_type) as $module) {
      $function = $module . '_oa_import_entity_' . $entity_type;
      $function($entity, $key, $imports, $map);
    }
    // Save the raw entity BEFORE importing fields to map the new entity_id
    if (!isset($entity->oa_imported)) {
      $entity_id = _oa_export_new_entity_id($entity_type, $entity);
      if (isset($entity_id)) {
        // Update the map so we don't import this again recursively.
        // Otherwise the field_import might do this again.
        $map[$key] = $entity_id;
      }
    }

    // PANELIZER: If the entity is panelized then we need to prepare the panelizer for import.
    oa_export_entity_panelizer_import($entity, $key, $imports, $map);

    // If the entity if fieldable check for fields that may need to be imported.
    // FIELDS: If the entity if fieldable check for fields that may need to be imported.
    if (entity_type_is_fieldable($entity_type)) {
      oa_export_entity_fields_import($entity_type, $entity, $key, $imports, $map);
    }

    // Allow anyone to alter the clone one last time.
    $context = array(
      'entity_type' => $entity_type,
      'key' => $key,
      'imports' => $imports,
      'map' => $map,
    );
    drupal_alter('oa_import_clone_entity', $entity, $context);
  }

  // Now save the entity if it hasn't been already.
  if (!isset($entity->oa_imported)) {
    entity_save($entity_type, $entity);
    // Mark the entity as imported.
    $entity->oa_imported = TRUE;
  }

  // Get the entity's new id and return it.
  list($entity_id) = entity_extract_ids($entity_type, $entity);

  if (isset($entity_id) && !isset($map[$key])) {
    $map[$key] = $entity_id;
  }

  return (isset($entity_id)) ? $entity_id : FALSE;
}

/**
 * Helper function to create and return a new entity_id based on an
 * existing entity
 *
 * Some code taken from core entity_extract_ids() function.
 *
 * @param $entity_type
 *   The type of entity passed in $entity
 * @param $entity
 *   entity that we want a new instance of
 *   This is updated with the new id/revision
 * @return int the entity_id of the new entity
 */
function _oa_export_new_entity_id($entity_type, &$entity) {
  // To create an entity, we need to know the bundle-key and the bundle-value
  $info = entity_get_info($entity_type);
  // Get the bundle key from the entity info array
  $bundle_key = $info['entity keys']['bundle'];
  // Get the actual bundle from the entity itself
  $bundle = $entity->{$bundle_key};
  // Create a new entity of that same type and bundle
  $new_entity = entity_create($entity_type, array($bundle_key => $bundle));
  // Save it so it gets a new entity_id
  entity_save($entity_type, $new_entity);
  // Grab the new entity_id
  $entity_id = $new_entity->{$info['entity keys']['id']};
  // Update original $entity with the new id/vid
  $entity->{$info['entity keys']['id']} = $new_entity->{$info['entity keys']['id']};
  if (!empty($info['entity keys']['revision'])) {
    $entity->{$info['entity keys']['revision']} = $new_entity->{$info['entity keys']['revision']};
  }
  $entity->original = $new_entity;

  return $entity_id;
}

/**
 * Implements hook_oa_import_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 */
function oa_export_oa_import_entity_node($entity, $key, $imports, &$map) {
  global $user;
  $entity->nid = NULL;
  $entity->uid = $user->uid;
  $entity->tnid = NULL;
  $entity->vid = NULL;
  $entity->created = NULL;
  $entity->changed = NULL;
  $entity->path = NULL;
  $entity->revision_timestamp = NULL;
}

/**
 * Implements hook_oa_import_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 */
function oa_export_oa_import_entity_paragraphs_item($entity, $key, $imports, &$map) {
  // Don't save this entity. It will be saved when the entity it is attached to
  // is saved.
  $entity->oa_imported = TRUE;
}

/**
 * Implements hook_oa_import_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 */
function oa_export_oa_import_entity_taxonomy_term($entity, $key, $imports, &$map) {
  // Check for an existing vocabulary.
  // See if there are any terms in the vocabulary with the same name.
  $terms = taxonomy_get_term_by_name($entity->name, $entity->vocabulary_machine_name);
  foreach ($terms as $tid => $term) {
    // We found an existing term.
    // Update the term id
    $entity->tid = $term->tid;
    // Just pretend we already imported it.
    $entity->oa_imported = TRUE;
    return;
  }
  // If we didn't find an existing term then create a new one.
  $entity->tid = NULL;
  $vocab = taxonomy_vocabulary_machine_name_load($entity->vocabulary_machine_name);
  if (empty($vocab)) {
    // Vocabulary doesn't exist, so create it.
    $vocab = new stdClass();
    $vocab->name = $entity->vocabulary_machine_name;
    $vocab->machine_name = $entity->vocabulary_machine_name;
    taxonomy_vocabulary_save($vocab);
  }
  // Associate this taxonomy term with the correct vocabulary.
  $entity->vid = $vocab->vid;
}

/**
 * Implements hook_oa_import_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 */
function oa_export_oa_import_entity_comment($entity, $key, $imports, &$map) {
  // See if the entity has already been imported. As of now comments can only
  // be added to 'node' entities.
  $node_key = 'node:' . $entity->nid;
  if (isset($map[$node_key])) {
    $entity_id = $map[$node_key];
  }
  else {
    // Import the entity now.
    $entity_id = oa_export_entity_import('node', $imports[$node_key], $node_key, $imports, $map);
  }

  if (!empty($entity_id)) {
    // Set the new comment nid.
    $entity->cid = NULL;
    $entity->created = NULL;
    $entity->changed = NULL;
    $entity->nid = $entity_id;
  }
}

/**
 * Implements hook_oa_import_entity_ENTITY_TYPE().
 *
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
 * We need to not only create a new entry for the file but we need to copy the
 * file to it's new location as well. This accomplishes both.
 */
function oa_export_oa_import_entity_file(&$entity, $key, $imports, &$map) {
  // The files that were exported are located here.
  $file_location = $_SESSION['oa_export']['extract_location'] . DIRECTORY_SEPARATOR . OA_EXPORT_FILES;

  // Location where the file will be saved.
  $destination = drupal_dirname($entity->uri);

  // The name of the file.
  $filename = drupal_basename($entity->uri);

  // Find the actual file we need to import.
  $file_contents = file_get_contents(realpath(oa_export_file_full_path($file_location, $filename)));

  // Save the file by the same name to its new location. This calls file_save() for us.
  if (file_prepare_directory($destination, FILE_CREATE_DIRECTORY || FILE_MODIFY_PERMISSIONS)
    && $new_file = file_save_data($file_contents, oa_export_file_full_path($destination, $filename))) {
    // Copy any fields from the import into the new file
    oa_export_copy_field_data($entity, $new_file);
    $entity = $new_file;
    $entity->fid = $new_file->fid;

    // Add the imported file to our map.
    $map[$key] = $entity->fid;
  }
  else {
    watchdog('oa_export', 'The file %file could not be saved because the destination %destination is invalid. This may be related to a permissions issue. Please contact your site administrator', array('%file' => $entity->uri, '%destination' => $destination));
    drupal_set_message(t('The file %file could not be saved, because the destination is invalid. More information is available in the system log.', array('%file' => $entity->uri)), 'error');
  }
  // This will stop the file from trying to be saved a second time.
  $entity->oa_imported = TRUE;
}

/**
 * Looks for panelizers in an entity.
 *
 * @param object $entity
 * @param string $key
 * @param array $imports
 * @param array $map
 */
function oa_export_entity_panelizer_import($entity, $key, $imports, &$map) {

  // If the entity is panelized then we need to prepare the panelizer for import.
  if (isset($entity->panelizer)) {
    foreach ($entity->panelizer as $view_mode => &$panelizer) {
      // Only import custom displays.
      if (!isset($panelizer->name) || empty($panelizer->name)) {
        if (isset($panelizer->revision_id)) {
          $panelizer->revision_id = NULL;
        }
        if (isset($panelizer->entity_id)) {
          $panelizer->entity_id = NULL;
        }
        if (is_numeric($panelizer->did)) {
          $panelizer->did = 'new';
        }
        $panelizer->display_is_modified = TRUE;

        // There's a possibility that a pane could be referencing a custom
        // piece of content. An example of this would be referencing a node
        // via its nid. This will allow a module to define a hook to handle
        // ensuring the old nid is replaced with the new nid.
        foreach ($panelizer->display->content as $pid => &$content) {
          // Let other modules handle customizing the import further.
          foreach (module_implements('oa_import_panelizer_' . $content->type) as $module) {
            $function = $module . '_oa_import_panelizer_' . $content->type;
            $function($content, $key, $imports, $map);
          }
        }
      }
    }
  }
}
