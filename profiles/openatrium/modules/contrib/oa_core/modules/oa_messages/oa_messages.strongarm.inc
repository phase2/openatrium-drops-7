<?php
/**
 * @file
 * oa_messages.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_messages_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__oa_create';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'oa_river_header' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
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
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'oa_river_accordian' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
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
            'weight' => '3',
            'visible' => TRUE,
          ),
          'oa_river_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__4' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
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
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__oa_create'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__oa_delete';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'oa_river_header' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
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
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'oa_river_accordian' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
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
            'weight' => '3',
            'visible' => TRUE,
          ),
          'oa_river_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__4' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
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
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__oa_delete'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__oa_member';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'oa_river_header' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
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
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'oa_river_accordian' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
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
            'weight' => '3',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__4' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
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
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__oa_member'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__oa_update';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'oa_river_header' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
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
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'oa_river_accordian' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__3' => array(
          'message_notify_email_subject' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'oa_river_header' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'oa_river_accordian' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'oa_river_body' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__4' => array(
          'message_notify_email_subject' => array(
            'weight' => '4',
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
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__oa_update'] = $strongarm;

  return $export;
}
