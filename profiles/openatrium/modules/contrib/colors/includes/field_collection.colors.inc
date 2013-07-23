<?php

/**
 * @file
 * Provides Colors integration on behalf of Field collection.
 */

/**
 * Implements hook_colors_classes().
 *
 * Reuse the colors of the field collection item's host entity.
 */
function field_collection_colors_classes($entity) {
  $classes = array();
  if ($entity->entity_type == 'field_collection_item') {
    $host_entity = $entity->hostEntity();
    $host_entity->entity_type = $entity->hostEntityType();
    $classes = module_invoke($host_entity->entity_type, 'colors_classes', $host_entity);
  }
  return $classes;
}
