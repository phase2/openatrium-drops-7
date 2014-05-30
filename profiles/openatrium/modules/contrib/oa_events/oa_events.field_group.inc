<?php
/**
 * @file
 * oa_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oa_events_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_access|node|oa_event|form';
  $field_group->group_name = 'group_oa_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '7',
    'children' => array(
      0 => 'oa_section_ref',
      1 => 'og_group_ref',
      2 => 'oa_other_spaces_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Access',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_oa_access|node|oa_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_event_location|node|oa_event|form';
  $field_group->group_name = 'group_oa_event_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_oa_event_location|node|oa_event|form'] = $field_group;

  return $export;
}
