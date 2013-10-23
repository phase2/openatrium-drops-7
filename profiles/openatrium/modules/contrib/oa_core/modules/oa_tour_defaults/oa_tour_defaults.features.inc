<?php
/**
 * @file
 * oa_tour_defaults.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_tour_defaults_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bootstrap_tour" && $api == "bootstrap_tour_tour") {
    return array("version" => "1");
  }
}
