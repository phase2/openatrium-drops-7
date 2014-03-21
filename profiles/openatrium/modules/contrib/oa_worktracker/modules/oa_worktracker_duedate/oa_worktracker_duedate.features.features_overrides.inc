<?php
/**
 * @file
 * oa_worktracker_duedate.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_worktracker_duedate_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_group
  $overrides["field_group.group_oa_worktracker_task_info|comment|comment_node_oa_worktracker_task|form.data|children|5"] = 'comment_alter_field_oa_worktracker_duedate';
  $overrides["field_group.group_oa_worktracker_task_info|node|oa_worktracker_task|default.data|children|5"] = 'field_oa_worktracker_duedate';
  $overrides["field_group.group_oa_worktracker_task_info|node|oa_worktracker_task|form.data|children|5"] = 'field_oa_worktracker_duedate';

  // Exported overrides for: panelizer_defaults
  $overrides["panelizer_defaults.node:oa_section:oa_section_worktracker.display|content|new-3|configuration|fields_override|field_oa_worktracker_duedate"] = 1;

  // Exported overrides for: variable
  $overrides["variable.field_bundle_settings_comment__comment_node_oa_worktracker_task.value|extra_fields|form|comment_alter_field_oa_worktracker_duedate"] = array(
    'weight' => 10,
  );

  // Exported overrides for: views_view
  $overrides["views_view.oa_worktracker.display|task_list|display_options|fields|field_oa_worktracker_duedate"] = array(
    'id' => 'field_oa_worktracker_duedate',
    'table' => 'field_data_field_oa_worktracker_duedate',
    'field' => 'field_oa_worktracker_duedate',
    'settings' => array(
      'format_type' => 'oa_date',
      'fromto' => 'both',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'show_repeat_rule' => 'show',
    ),
  );
  $overrides["views_view.oa_worktracker.display|task_list|display_options|style_options|columns|field_oa_worktracker_duedate"] = 'field_oa_worktracker_duedate';

 return $overrides;
}
