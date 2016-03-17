<?php
/**
 * @file
 * oa_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_project_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
