<?php
/**
 * @file
 * oa_contextual_tabs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_contextual_tabs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
