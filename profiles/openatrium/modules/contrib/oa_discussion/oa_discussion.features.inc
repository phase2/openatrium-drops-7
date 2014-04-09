<?php
/**
 * @file
 * oa_discussion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_discussion_ctools_plugin_api($module = NULL, $api = NULL) {
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
function oa_discussion_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function oa_discussion_default_message_type() {
  $items = array();
  $items['oa_reply'] = entity_import('message_type', '{
    "name" : "oa_reply",
    "description" : "Discussion Replies",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" },
      "token options" : { "clear" : 1 }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[[message:field-oa-message-space]] @{message:user:name} replied to [message:field-oa-node-ref:oa-parent:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[[message:field-oa-message-space]] @{message:user:name} replied to [message:field-oa-node-ref:oa-parent:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:timestamp:oa_date]\\u003Cbr \\\\u003E\\u003Ch3\\u003E@{message:user:name} replied to \\u003Ca href=\\u0022[message:field-oa-node-ref:oa-parent:url]\\u0022\\u003E[message:field-oa-node-ref:oa-parent:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\n[message:field-oa-message-text:value] [message:field-oa-node-ref:body]\\r\\n\\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003EClick here\\u003C\\/a\\u003E to see the discussion.",
          "format" : "full_html",
          "safe_value" : "[message:timestamp:oa_date]\\u003Cbr \\\\u003E\\u003Ch3\\u003E@{message:user:name} replied to \\u003Ca href=\\u0022[message:field-oa-node-ref:oa-parent:url]\\u0022\\u003E[message:field-oa-node-ref:oa-parent:title]\\u003C\\/a\\u003E\\u003C\\/h3\\u003E\\n[message:field-oa-message-text:value] [message:field-oa-node-ref:body]\\n\\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003EClick here\\u003C\\/a\\u003E to see the discussion."
        },
        {
          "value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E replied to \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:oa-parent:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ca href=\\u0022[site:url]user\\/@{message:user:uid}\\u0022 class=\\u0022oa-userlink\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E replied to \\u003Ca href=\\u0022[message:field-oa-node-ref:url]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:oa-parent:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E"
        },
        {
          "value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:title]",
          "format" : "full_html",
          "safe_value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:title]"
        },
        {
          "value" : "[message:field-oa-node-ref:body]",
          "format" : "full_html",
          "safe_value" : "[message:field-oa-node-ref:body]"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function oa_discussion_node_info() {
  $items = array(
    'oa_discussion_post' => array(
      'name' => t('Discussion Post'),
      'base' => 'node_content',
      'description' => t('An Open Atrium discussion post'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
