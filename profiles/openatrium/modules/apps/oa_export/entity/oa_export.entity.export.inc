<?php
/**
 * @file
 * oa_export.entity.export.inc
 *
 * Exports entities by entity type.
 */

//require_once '../menus/oa_export.menus.export.inc';

/**
 * Helper function to export entities.
 *
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param object $entity
 *   The fully loaded entity.
 * @param array $results
 *   The $batch['context']['results'] used to store the entities throughout
 *   the batch process.
 */
function oa_export_entity_export($entity_type, $entity, &$results) {
  list($entity_id) = entity_extract_ids($entity_type, $entity);

  // Look for the exported entity in our map.
  if (!isset($results['export'][$entity_type . ':' . $entity_id])) {
    foreach (module_implements('oa_export_entity_' . $entity_type) as $module) {
      $function = $module . '_oa_export_entity_' . $entity_type;
      $function($entity, $results);
    }
    // If the entity is fieldable try to import its fields.
    if (entity_type_is_fieldable($entity_type)) {
      oa_export_fields_export($entity, $entity_type, $results);
    }
    // Check for comments on this entity.
    oa_export_comments_export($entity_id, $results);

    // Check for menus.
    oa_export_menus_export($entity, $entity_id, $entity_type, $results);
  }
}

/**
 * Implements hook_oa_export_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param array $results
 *   The $batch['context']['results'] used to store the entities throughout
 *   the batch process.
 *
 * @todo: Do we want to export users that created the node?
 */
function oa_export_oa_export_entity_node($entity, &$results) {
  // Remove properties added by user.module that we don't want to export
  unset($entity->name);
  unset($entity->picture);
  unset($entity->data);
  $results['export']['node:' . $entity->nid] = _oa_export_remove_recursion($entity);
}

/**
 * Implements hook_oa_export_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param array $results
 *   The $batch['context']['results'] used to store the entities throughout
 *   the batch process.
 */
function oa_export_oa_export_entity_paragraphs_item($entity, &$results) {
  $results['export']['paragraphs_item:' . $entity->item_id] = _oa_export_remove_recursion($entity);
}

/**
 * Implements hook_oa_export_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param array $results
 *   The $batch['context']['results'] used to store the entities throughout
 *   the batch process.
 */
function oa_export_oa_export_entity_taxonomy_term($entity, &$results) {
  // Make a copy of the taxonomy entity here so we can unset the field to
  // prevent recursive space blueprint export.
  // _oa_export_remove_recursion does a copy
  $results['export']['taxonomy_term:' . $entity->tid] = _oa_export_remove_recursion($entity);

  // Remove the space reference for now so it doesn't get exported yet.
  // We don't want recursive blueprints exported.
  unset($entity->field_oa_clone_space);
}

/**
 * Implements hook_oa_export_entity_ENTITY_TYPE().
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param array $results
 *   The $batch['context']['results'] used to store the entities throughout
 *   the batch process.
 */
function oa_export_oa_export_entity_comment($entity, &$results) {
  $results['export']['comment:' . $entity->cid] = _oa_export_remove_recursion($entity);
}

/**
 * Implements hook_oa_export_entity_ENTITY_TYPE().
 *
 * We need to not only create a new entry for the file but we need to copy the
 * file to the export directory as well. This accomplishes both.
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param array $results
 *   The $batch['context']['results'] used to store the entities throughout
 *   the batch process.
 */
function oa_export_oa_export_entity_file($entity, &$results) {
  // Add the file to the export.
  $file = _oa_export_remove_recursion($entity);
  $results['export']['file:' . $entity->fid] = $file;
  oa_export_file($file);
}
