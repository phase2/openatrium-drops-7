<?php
/**
 * @file
 * oa_files.features.inc
 */

/**
 * Implements hook_default_command_button().
 */
function oa_files_default_command_button() {
  $items = array();
  $items['add_file'] = entity_import('command_button', '{
    "bundle" : "button",
    "name" : "add_file",
    "title" : "Add File",
    "language" : "und",
    "field_command_link" : { "und" : [
        { "url" : "oa-files\\/upload", "title" : "Add File", "attributes" : [] }
      ]
    },
    "field_link_icon" : { "und" : [ { "value" : "icon-upload" } ] }
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_files_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
