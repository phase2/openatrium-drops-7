<?php
/**
 * @file
 * oa_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index_alter().
 */
function oa_search_default_search_api_index_alter(&$data) {
  if (isset($data['database_node_index'])) {
    $data['database_node_index']->options['fields']['created']['type'] = 'date'; /* WAS: 'integer' */
    $data['database_node_index']->options['fields']['oa_section_ref:title'] = array(
      'type' => 'string',
    ); /* WAS: '' */
    $data['database_node_index']->options['fields']['og_group_ref:title'] = array(
      'type' => 'string',
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_default_search_api_server_alter().
 */
function oa_search_default_search_api_server_alter(&$data) {
  if (isset($data['database_server'])) {
    $data['database_server']->options['indexes']['database_node_index']['created']['type'] = 'date'; /* WAS: 'integer' */
    $data['database_server']->options['indexes']['database_node_index']['oa_section_ref:title'] = array(
      'table' => 'search_api_db_database_node_index_oa_section_ref_title',
      'type' => 'string',
      'boost' => 1,
    ); /* WAS: '' */
    $data['database_server']->options['indexes']['database_node_index']['og_group_ref:title'] = array(
      'table' => 'search_api_db_database_node_index_og_group_ref_title',
      'type' => 'string',
      'boost' => 1,
    ); /* WAS: '' */
  }
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
