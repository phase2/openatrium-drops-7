<?php
/**
 * @file
 * oa_contextual_tabs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_contextual_tabs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
