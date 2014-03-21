<?php
/**
 * @file
 * command_buttons.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function command_buttons_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
