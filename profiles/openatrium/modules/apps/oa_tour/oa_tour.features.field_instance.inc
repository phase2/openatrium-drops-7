<?php
/**
 * @file
 * oa_tour.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oa_tour_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bootstrap_tour-bootstrap_tour-field_bootstrap_tour_spaces'
  $field_instances['bootstrap_tour-bootstrap_tour-field_bootstrap_tour_spaces'] = array(
    'bundle' => 'bootstrap_tour',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bootstrap_tour',
    'field_name' => 'field_bootstrap_tour_spaces',
    'label' => 'Spaces',
    'options_limit' => FALSE,
    'options_limit_empty_behaviour' => 0,
    'options_limit_fields' => array(),
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select2widget',
      'settings' => array(
        'select2widgetajax' => array(
          'match_operator' => 'CONTAINS',
          'min_char' => 0,
          'view_mode' => 'select2widget_labels',
          'width' => '100%',
        ),
      ),
      'type' => 'select2widgetajax',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Spaces');

  return $field_instances;
}
