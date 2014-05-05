<?php
/**
 * @file
 * oa_worktracker.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_worktracker_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_oa_worktracker_task';
  $strongarm->value = 0;
  $export['comment_anonymous_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_oa_worktracker_task';
  $strongarm->value = 1;
  $export['comment_default_mode_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_oa_worktracker_task';
  $strongarm->value = '50';
  $export['comment_default_per_page_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_oa_worktracker_task';
  $strongarm->value = 1;
  $export['comment_form_location_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_oa_worktracker_task';
  $strongarm->value = '2';
  $export['comment_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_oa_worktracker_task';
  $strongarm->value = '1';
  $export['comment_preview_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_oa_worktracker_task';
  $strongarm->value = 0;
  $export['comment_subject_field_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_oa_worktracker_task';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'field_oa_worktracker_assigned_to' => array(
          'weight' => '6',
        ),
        'field_oa_worktracker_task_status' => array(
          'weight' => '7',
        ),
        'field_oa_worktracker_priority' => array(
          'weight' => '8',
        ),
        'field_oa_worktracker_task_type' => array(
          'weight' => '9',
        ),
        'oa_section_ref' => array(
          'weight' => '5',
        ),
        'field_oa_media' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(
        'comment_alter' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__oa_worktracker_task_update';
  $strongarm->value = array(
    'view_modes' => array(
      'message_notify_email_subject' => array(
        'custom_settings' => TRUE,
      ),
      'message_notify_email_body' => array(
        'custom_settings' => TRUE,
      ),
      'oa_river_header' => array(
        'custom_settings' => TRUE,
      ),
      'oa_river_accordian' => array(
        'custom_settings' => TRUE,
      ),
      'oa_river_body' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'oa_river_header' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'oa_river_accordian' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'oa_river_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__4' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__oa_worktracker_task_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__oa_worktracker_task';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '1',
        ),
        'oa_worktracker_assigned_to_multiple' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(
        'oa_worktracker_submitted' => array(
          'default' => array(
            'weight' => '14',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_oa_worktracker_task';
  $strongarm->value = array();
  $export['menu_options_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_oa_worktracker_task';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_oa_worktracker_task';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_oa_worktracker_task';
  $strongarm->value = '1';
  $export['node_preview_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_oa_worktracker_task';
  $strongarm->value = 0;
  $export['node_submitted_oa_worktracker_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_oa_worktracker_task';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'featured' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_oa_worktracker_task'] = $strongarm;

  return $export;
}
