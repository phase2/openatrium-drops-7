<?php
/**
 * @file
 * oa_worktracker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_worktracker_ctools_plugin_api($module = NULL, $api = NULL) {
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
function oa_worktracker_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_panelizer_defaults_override_alter().
 */
function oa_worktracker_panelizer_defaults_override_alter(&$data) {
  if (isset($data['user:user:default'])) {
    $data['user:user:default']->display->content['new-7e2787f8-3f6c-4b3b-a1bb-e11225e395d5'] = (object) array(
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
        ); /* WAS: '' */
    $data['user:user:default']->display->panels['contentheader']['3'] = 'new-7e2787f8-3f6c-4b3b-a1bb-e11225e395d5'; /* WAS: '' */
  }
}

/**
 * Implements hook_default_message_type().
 */
function oa_worktracker_default_message_type() {
  $items = array();
  $items['oa_worktracker_task_update'] = entity_import('message_type', '{
    "name" : "oa_worktracker_task_update",
    "description" : "Work Tracker Task update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[[message:field-oa-message-space]] @{message:user:name} updated [message:field-oa-node-ref:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[[message:field-oa-message-space]] @{message:user:name} updated [message:field-oa-node-ref:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:timestamp:oa_date]\\u003Cbr \\/\\u003E\\u003Ch3\\u003E@{message:user:name} updated \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\r\\n[message:field-oa-message-text:value] [message:field-oa-comment-ref:comment-body:value]\\r\\n[message:field-oa-node-ref:oa-diff:@{message:field-oa-node-ref:vid}]\\r\\n\\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003EClick here\\u003C\\/a\\u003E to see the task and its history.",
          "format" : "full_html",
          "safe_value" : "[message:timestamp:oa_date]\\u003Cbr \\/\\u003E\\u003Ch3\\u003E@{message:user:name} updated \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\n[message:field-oa-message-text:value] [message:field-oa-comment-ref:comment-body:value]\\n[message:field-oa-node-ref:oa-diff:@{message:field-oa-node-ref:vid}]\\n\\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003EClick here\\u003C\\/a\\u003E to see the task and its history."
        },
        {
          "value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E updated \\u003Ca href=\\u0022\\/comment\\/[message:field-oa-comment-ref:cid]#comment-[message:field-oa-comment-ref:cid]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E updated \\u003Ca href=\\u0022\\/comment\\/[message:field-oa-comment-ref:cid]#comment-[message:field-oa-comment-ref:cid]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E"
        },
        {
          "value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:title]",
          "format" : "panopoly_html_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-oa-message-text:value] [message:field-oa-node-ref:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-oa-comment-ref:comment-body:value]",
          "format" : "panopoly_html_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-oa-comment-ref:comment-body:value]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function oa_worktracker_node_info() {
  $items = array(
    'oa_worktracker_task' => array(
      'name' => t('Task'),
      'base' => 'node_content',
      'description' => t('A unit of work to be performed.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
