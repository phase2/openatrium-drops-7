<?php

/**
 * @file
 * Provides Color integration on behalf of og.module.
 */

/**
 * Implements hook_colors_info().
 */
function og_colors_info() {
  return array(
    'og' => array(
      'title' => 'Organic groups',
      'short_description' => t('Enable colors for organic groups'),
      'long_description' => t('Colors for organic groups. If enabled, you may set colors for each node type below.'),
      'function' => '_colors_og_callback',
    ),
  );
}

/**
 * Generates classes based on both entity_type and eid
 *
 * @return array
 *   An array keyed by group ID, containing the group label.
 */
function _colors_og_callback() {
  $groups = array();
  foreach (og_get_all_group_entity() as $entity_type => $label) {
    $entities = og_get_all_group($entity_type);
    foreach ($entities as $id) {
      $entity = entity_load_single($entity_type, $id);
      list($id) = entity_extract_ids($entity_type, $entity);
      $groups[$entity_type . '_' . $id] = entity_label($entity_type, $entity);
    }
  }
  return $groups;
}

/**
 * Implements hook_colors_classes().
 *
 * Provide colors per og type.
 */
function og_colors_classes($entity) {
  $class_names = array();
  if (variable_get('colors_og_enabled', FALSE)) {
    list($id) = entity_extract_ids($entity->entity_type, $entity);
    if (!empty($id)) {
      foreach (og_get_entity_groups($entity->entity_type, $entity) as $gid) {
        foreach ($gid as $id) {
          $class_names[] = 'colors_og_' . $entity->entity_type . '_' . $id;
        }
      }
    }
  }
  return $class_names;
}
