<?php

/**
 * @file
 * Provides Color integration on behalf of node.module.
 */

/**
 * Implements hook_colors_info().
 */
function node_colors_info() {
  return array(
    'node_type' => array(
      'title' => 'Node type',
      'short_description' => t('Enable colors for node types'),
      'long_description' => t('Colors for node types. If enabled, you may set colors for each node type below.'),
      'function' => 'node_type_get_names',
    ),
  );
}

/**
 * Implements hook_colors_classes().
 *
 * Provide colors per node type.
 */
function node_colors_classes($entity) {
  $class_names = array();
  if (variable_get('colors_node_type_enabled', FALSE)) {
    if ($entity->entity_type == 'node') {
      $class_names[] = 'colors-node-type-' . $entity->type;
    }
  }
  return $class_names;
}
