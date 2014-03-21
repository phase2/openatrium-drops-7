<?php
/**
 * @file
 * oa_wiki.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_wiki_ctools_plugin_api($module = NULL, $api = NULL) {
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
function oa_wiki_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oa_wiki_node_info() {
  $items = array(
    'oa_wiki_page' => array(
      'name' => t('Document Page'),
      'base' => 'node_content',
      'description' => t('An Open Atrium Document/Wiki page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
