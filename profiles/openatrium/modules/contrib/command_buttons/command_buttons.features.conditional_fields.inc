<?php
/**
 * @file
 * command_buttons.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function command_buttons_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'fieldable_panels_pane',
    'bundle' => 'command_buttons',
    'dependent' => 'field_css_class',
    'dependee' => 'field_button_style',
    'options' => array(
      'state' => 'visible',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(),
      'element_edit' => array(
        1 => 1,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(),
      'selector' => '',
      'values_set' => 1,
      'value_form' => 'other',
      'value' => array(
        0 => array(
          'value' => 'other',
        ),
      ),
      'values' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'fieldable_panels_pane',
    'bundle' => 'command_buttons',
    'dependent' => 'field_dropdown_label',
    'dependee' => 'field_use_dropdowns',
    'options' => array(
      'state' => 'visible',
      'condition' => 'checked',
      'grouping' => 'AND',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => 1,
        2 => 2,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(),
      'element_edit' => array(
        1 => 1,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(),
      'selector' => '',
      'values_set' => 1,
      'value' => array(),
      'values' => array(),
      'value_form' => array(),
    ),
  );

  return $items;
}
