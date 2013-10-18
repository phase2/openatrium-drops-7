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
 * Implements hook_strongarm_alter().
 */
function oa_search_strongarm_alter(&$data) {
  if (isset($data['search_active_modules'])) {
    $data['search_active_modules']->value['file_entity'] = 0; /* WAS: '' */
    $data['search_active_modules']->value['user'] = 'user'; /* WAS: 0 */
  }
}
