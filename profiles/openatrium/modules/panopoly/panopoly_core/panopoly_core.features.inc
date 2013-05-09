<?php
/**
 * @file
 * panopoly_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function panopoly_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function panopoly_core_views_api() {
  return array("api" => "3.0");
}
