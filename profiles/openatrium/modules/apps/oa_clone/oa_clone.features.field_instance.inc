<?php
/**
 * @file
 * oa_clone.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oa_clone_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-space_type-field_oa_clone_enabled'
  $field_instances['taxonomy_term-space_type-field_oa_clone_enabled'] = array(
    'bundle' => 'space_type',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_oa_clone_enabled',
    'label' => 'Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-space_type-field_oa_clone_space'
  $field_instances['taxonomy_term-space_type-field_oa_clone_space'] = array(
    'bundle' => 'space_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Rather than specifying a layout and node types, insteady you can specify a Space to clone.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_oa_clone_space',
    'label' => 'Space to clone',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(),
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Rather than specifying a layout and node types, insteady you can specify a Space to clone.');
  t('Space to clone');
  t('Type');

  return $field_instances;
}
