<?php
/**
 * @file
 * oa_subspaces.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oa_subspaces_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_space_inheritence|node|oa_space|form';
  $field_group->group_name = 'group_oa_space_inheritence';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_space';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inheritence',
    'weight' => '6',
    'children' => array(
      0 => 'og_roles_permissions',
      1 => 'oa_parent_space',
      2 => 'og_user_inheritance',
      3 => 'og_user_permission_inheritance',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Inheritence',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-oa-space-inheritence field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_oa_space_inheritence|node|oa_space|form'] = $field_group;

  return $export;
}
