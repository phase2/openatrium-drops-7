<?php
/**
 * @file
 * panopoly_wysiwyg.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function panopoly_wysiwyg_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
