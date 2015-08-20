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
          "value" : "[[message:field-oa-message-space]] [message:field-oa-node-ref:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[[message:field-oa-message-space]] [message:field-oa-node-ref:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ch3\\u003E@{message:user:name} updated \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\r\\n[message:field-oa-message-text:value] [message:field-oa-comment-ref:comment-body:value]\\r\\n[message:field-oa-node-ref:oa-diff:@{message:field-oa-node-ref:vid}]",
          "format" : "full_html",
          "safe_value" : "\\u003Ch3\\u003E@{message:user:name} updated \\u003Ca href=\\u0022[message:field-oa-comment-ref:url]\\u0022\\u003E[message:field-oa-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\n[message:field-oa-message-text:value] [message:field-oa-comment-ref:comment-body:value]\\n[message:field-oa-node-ref:oa-diff:@{message:field-oa-node-ref:vid}]"
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
  drupal_alter('node_info', $items);
  return $items;
}
