<?php
/**
 * @file
 * oa_export.fields.export.inc
 *
 * Exports fields on entities by field type.
 */

/**
 * Helper function to export entity fields.
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_fields_export($entity, $entity_type, &$results) {
  foreach (field_info_fields() as $field_name => $field) {
    if (isset($entity->$field_name) && !empty($entity->$field_name)) {
      // We don't use module_invoke because we want to pass the results
      // by reference.
      foreach (module_implements('oa_export_field_' . $field['type']) as $module) {
        $function = $module . '_oa_export_field_' . $field['type'];
        $function($entity, $entity_type, $field_name, $results);
      }
    }
  }
}

/**
 * Implements hook_oa_export_field_FIELD_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param string $field_name
 *   The name of the field.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_oa_export_field_entityreference($entity, $entity_type, $field_name, &$results) {
  foreach ($entity->{$field_name} as $language => $targets) {
    foreach ($targets as $delta => $target) {
      oa_export_entity_reference_field($target['target_id'], $entity, $entity_type, $field_name, $results);
    }
  }
}

/**
 * Implements hook_oa_export_field_FIELD_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param string $field_name
 *   The name of the field.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_oa_export_field_paragraphs($entity, $entity_type, $field_name, &$results) {
  foreach ($entity->{$field_name} as $language => $items) {
    foreach ($items as $delta => $item) {
      // Look for the exported entity in our map.
      // The paragraph items are stored as integer values.
      if (!isset($results['export']['paragraph_item:' . $item['value']])) {

        // Load the paragraph item entity.
        $paragraph = paragraphs_field_get_entity($item);

        // Special handling for paragraph items. These values don't get set
        // because they are protected properties. We don't really care as we
        // can set them here. This is easier then extending the class and
        // writing our own 'jsonExport()' method.
        $paragraph->host_id = $paragraph->hostEntityId();
        $paragraph->host_type = $paragraph->hostEntitytype();

        // Add the final paragraph export to our results.
        $results['export'][$paragraph->entityType() . ':' . $paragraph->item_id] = $paragraph;

        // Export fields on the paragraph item.
        oa_export_fields_export($paragraph, 'paragraphs_item', $results);
      }
    }
  }
}

/**
 * Implements hook_oa_export_field_FIELD_TYPE().
 *
 *@param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param string $field_name
 *   The name of the field.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_oa_export_field_file($entity, $entity_type, $field_name, &$results) {
  oa_export_file_field($entity, $field_name, $results);
}

/**
 * Implements hook_oa_export_field_FIELD_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param string $field_name
 *   The name of the field.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_oa_export_field_image($entity, $entity_type, $field_name, &$results) {
  oa_export_file_field($entity, $field_name, $results);
}

/**
 * Implements hook_oa_export_field_FIELD_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param string $field_name
 *   The name of the field.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_oa_export_field_document($entity, $entity_type, $field_name, &$results) {
  oa_export_file_field($entity, $field_name, $results);
}

/**
 * Implements hook_oa_export_field_FIELD_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param string $field_name
 *   The name of the field.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_oa_export_field_taxonomy_term_reference($entity, $entity_type, $field_name, &$results) {
  foreach ($entity->{$field_name} as $language => $targets) {
    foreach ($targets as $delta => $target) {
      // Look for the exported entity in our map.
      if (!isset($results['export']['taxonomy_term:' . $target['tid']])) {
        if ($term = entity_load_single('taxonomy_term', $target['tid'])) {
          // Export the entity.
          oa_export_entity_export('taxonomy_term', $term, $results);
        }
        // The reference entity couldn't be loaded so we set the referencing field
        // to an empty array.
        else {
          oa_export_remove_missing_entity($entity, $entity_type, $field_name, $results);
        }
      }
    }
  }
}

/**
 * Helper function to export entity references.
 *
 * @param int $entity_id
 *   The id of the entity that is being referenced.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_entity_reference_field($entity_id, $entity, $entity_type, $field_name, &$results) {
  // We need to check the settings on this field.
  $field_info = field_info_field($field_name);
  // We only want reference fields that are tageting nodes.
  if ($field_info['settings']['target_type'] === 'node') {
    // Look for the exported entity in our map.
    if (!isset($results['export']['node:' . $entity_id])) {
      // It is possible for the entity to not exists, I guess...
      if ($export = entity_load_single('node', $entity_id)) {
        // Add the entity reference to our export.
        oa_export_entity_export('node', $export, $results);
      }
      // The reference entity couldn't be loaded so we set the referencing field
      // to an empty array.
      else {
        oa_export_remove_missing_entity($entity, $entity_type, $field_name, $results);
      }
    }
  }
}

/**
 * Helper function to export file fields along with the file.
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $field_name
 *   The name of the field.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_file_field($entity, $field_name, &$results) {
  foreach ($entity->{$field_name} as $language => $targets) {
    foreach ($targets as $delta => $target) {
      $target = (object) $target;
      // Look for the exported entity in our map.
      if (!isset($results['export']['file:' . $target->fid])) {
        // Add the file entity to our export.
        $results['export']['file:' . $target->fid] = $target;
        oa_export_file($target);
      }
    }
  }
}
