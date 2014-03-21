<?php
/**
 * @file
 * oa_clone.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_clone_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
