<?php
/**
 * @file
 * oa_appearance.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oa_appearance_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_banner|node|oa_space|form';
  $field_group->group_name = 'group_oa_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_space';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '42',
    'children' => array(
      0 => 'field_oa_banner',
      1 => 'field_oa_banner_position',
      2 => 'field_oa_banner_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-oa-banner field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_oa_banner|node|oa_space|form'] = $field_group;

  return $export;
}
