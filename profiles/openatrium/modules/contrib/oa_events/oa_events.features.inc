<?php
/**
 * @file
 * oa_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function oa_events_default_message_type() {
  $items = array();
  $items['oa_event_notification'] = entity_import('message_type', '{
    "name" : "oa_event_notification",
    "description" : "Event Reminders",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "Event Reminder: [message:field-oa-node-ref:title] : @{message:field-oa-date:0:value:short}",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EEvent Reminder: [message:field-oa-node-ref:title] : @{message:field-oa-date:0:value:short}\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Reminder: [message:field-oa-node-ref:title] : [message:field-oa-date-0:value:short]\\r\\n\\r\\n[message:field-oa-node-ref:body]\\r\\n",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EReminder: [message:field-oa-node-ref:title] : [message:field-oa-date-0:value:short]\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-oa-node-ref:body]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function oa_events_node_info() {
  $items = array(
    'oa_event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An Open Atrium Event'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
