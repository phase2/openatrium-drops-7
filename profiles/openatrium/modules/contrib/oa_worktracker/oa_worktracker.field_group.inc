<?php
/**
 * @file
 * oa_worktracker.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oa_worktracker_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_access|node|oa_worktracker_task|form';
  $field_group->group_name = 'group_oa_access';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_worktracker_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access',
    'weight' => '6',
    'children' => array(
      0 => 'og_group_ref',
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
  $export['group_oa_access|node|oa_worktracker_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_worktracker_task_info|comment|comment_node_oa_worktracker_task|form';
  $field_group->group_name = 'group_oa_worktracker_task_info';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_oa_worktracker_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Task information',
    'weight' => '0',
    'children' => array(
      0 => 'comment_alter_field_oa_worktracker_assigned_to',
      1 => 'comment_alter_field_oa_worktracker_priority',
      2 => 'comment_alter_field_oa_worktracker_task_status',
      3 => 'comment_alter_field_oa_worktracker_task_type',
      4 => 'comment_alter_oa_section_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Task information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_oa_worktracker_task_info|comment|comment_node_oa_worktracker_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_worktracker_task_info|node|oa_worktracker_task|default';
  $field_group->group_name = 'group_oa_worktracker_task_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_worktracker_task';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Task information',
    'weight' => '0',
    'children' => array(
      0 => 'field_oa_worktracker_assigned_to',
      1 => 'field_oa_worktracker_priority',
      2 => 'field_oa_worktracker_task_status',
      3 => 'field_oa_worktracker_task_type',
      4 => 'oa_section_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Task information',
      'instance_settings' => array(
        'classes' => 'group-oa-worktracker-task-info-display',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_oa_worktracker_task_info|node|oa_worktracker_task|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_oa_worktracker_task_info|node|oa_worktracker_task|form';
  $field_group->group_name = 'group_oa_worktracker_task_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'oa_worktracker_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Task information',
    'weight' => '2',
    'children' => array(
      0 => 'field_oa_worktracker_assigned_to',
      1 => 'field_oa_worktracker_priority',
      2 => 'field_oa_worktracker_task_status',
      3 => 'field_oa_worktracker_task_type',
      4 => 'oa_section_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Task information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_oa_worktracker_task_info|node|oa_worktracker_task|form'] = $field_group;

  return $export;
}
