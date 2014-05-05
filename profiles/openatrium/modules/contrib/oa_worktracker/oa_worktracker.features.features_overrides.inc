<?php
/**
 * @file
 * oa_worktracker.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_worktracker_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: panelizer_defaults
  $overrides["panelizer_defaults.user:user:default.display|content|new-7e2787f8-3f6c-4b3b-a1bb-e11225e395d5"] = (object) array(
      'pid' => 'new-7e2787f8-3f6c-4b3b-a1bb-e11225e395d5',
      'panel' => 'contentheader',
      'type' => 'views_panes',
      'subtype' => 'oa_worktracker-user_tasks',
      'shown' => TRUE,
      'access' => array(),
      'configuration' => array(
        'show_exposed_form' => 1,
        'items_per_page' => 10,
        'fields_override' => array(
          'title' => 1,
          'timestamp' => 1,
          'realname_1' => 0,
          'realname' => 0,
          'title_1' => 1,
          'field_oa_worktracker_priority' => 1,
          'field_oa_worktracker_task_type' => 1,
          'field_oa_worktracker_task_status' => 1,
          'comment_count' => 1,
          'last_updated' => 1,
        ),
        'exposed' => array(
          'field_oa_worktracker_task_status_value' => array(),
          'field_oa_worktracker_priority_value' => array(),
          'field_oa_worktracker_task_type_value' => array(),
        ),
        'override_title' => '',
        'override_title_text' => '',
        'view_mode' => 'teaser',
        'widget_title' => 'Your Tasks',
        'use_pager' => NULL,
        'pager_id' => NULL,
        'offset' => NULL,
        'link_to_view' => NULL,
        'more_link' => NULL,
        'path' => NULL,
        'view_settings' => 'fields',
        'header_type' => 'none',
        'context' => array(
          0 => 'panelizer',
        ),
      ),
      'cache' => array(),
      'css' => array(),
      'extras' => array(),
      'position' => 3,
      'locks' => array(),
      'uuid' => '7e2787f8-3f6c-4b3b-a1bb-e11225e395d5',
    );
  $overrides["panelizer_defaults.user:user:default.display|panels|contentheader|3"] = 'new-7e2787f8-3f6c-4b3b-a1bb-e11225e395d5';

 return $overrides;
}
