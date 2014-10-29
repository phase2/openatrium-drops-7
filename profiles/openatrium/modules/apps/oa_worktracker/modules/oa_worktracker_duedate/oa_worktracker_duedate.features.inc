<?php
/**
 * @file
 * oa_worktracker_duedate.features.inc
 */

/**
 * Implements hook_field_group_info_alter().
 */
function oa_worktracker_duedate_field_group_info_alter(&$data) {
  if (isset($data['group_oa_worktracker_task_info|comment|comment_node_oa_worktracker_task|form'])) {
    $data['group_oa_worktracker_task_info|comment|comment_node_oa_worktracker_task|form']->data['children']['5'] = 'field_oa_worktracker_duedate'; /* WAS: '' */
  }
  if (isset($data['group_oa_worktracker_task_info|node|oa_worktracker_task|default'])) {
    $data['group_oa_worktracker_task_info|node|oa_worktracker_task|default']->data['children']['6'] = 'field_oa_worktracker_duedate'; /* WAS: '' */
  }
  if (isset($data['group_oa_worktracker_task_info|node|oa_worktracker_task|form'])) {
    $data['group_oa_worktracker_task_info|node|oa_worktracker_task|form']->data['children']['6'] = 'field_oa_worktracker_duedate'; /* WAS: '' */
  }
}

/**
 * Implements hook_panelizer_defaults_override_alter().
 */
function oa_worktracker_duedate_panelizer_defaults_override_alter(&$data) {
  if (isset($data['node:oa_section:oa_section_worktracker'])) {
    $data['node:oa_section:oa_section_worktracker']->display->content['new-083432ea-5fb3-4e40-8c9d-09ed848deab7']->configuration['fields_override']['field_oa_worktracker_duedate'] = 1; /* WAS: '' */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function oa_worktracker_duedate_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_comment__comment_node_oa_worktracker_task'])) {
    $data['field_bundle_settings_comment__comment_node_oa_worktracker_task']->value['extra_fields']['form']['field_oa_worktracker_duedate'] = array(
      'weight' => 10,
    ); /* WAS: '' */
  }
}
