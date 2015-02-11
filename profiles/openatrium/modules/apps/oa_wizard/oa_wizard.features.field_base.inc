<?php
/**
 * @file
 * oa_wizard.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oa_wizard_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_wizard_steps'
  $field_bases['field_wizard_steps'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wizard_steps',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_wizard_type'
  $field_bases['field_wizard_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wizard_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'oa_space' => 'oa_space',
      ),
      'allowed_values_function' => 'node_type_get_names',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
