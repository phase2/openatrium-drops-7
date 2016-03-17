<?php
/**
 * @file
 * oa_toolbar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_toolbar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
