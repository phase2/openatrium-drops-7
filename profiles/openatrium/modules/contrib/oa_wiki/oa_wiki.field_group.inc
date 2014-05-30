<?php
/**
 * @file
 * oa_wiki.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oa_wiki_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_access|node|oa_wiki_page|form';
  $field_group->group_name = 'group_oa_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_wiki_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '10',
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
  $export['group_oa_access|node|oa_wiki_page|form'] = $field_group;

  return $export;
}
