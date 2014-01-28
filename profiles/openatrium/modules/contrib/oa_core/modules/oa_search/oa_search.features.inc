<?php
/**
 * @file
 * oa_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_strongarm_alter().
 */
function oa_search_strongarm_alter(&$data) {
  if (isset($data['search_active_modules'])) {
    $data['search_active_modules']->value['file_entity'] = 0; /* WAS: '' */
    $data['search_active_modules']->value['user'] = 'user'; /* WAS: 0 */
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function oa_search_default_search_api_index() {
  $items = array();
  $items['user_index'] = entity_import('search_api_index', '{
    "name" : "User Index",
    "machine_name" : "user_index",
    "description" : null,
    "server" : "database_server",
    "item_type" : "user",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "name" : { "type" : "text" },
        "mail" : { "type" : "text" },
        "og_user_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_user_display_name" : { "type" : "text", "boost" : "5.0" },
        "search_api_language" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
