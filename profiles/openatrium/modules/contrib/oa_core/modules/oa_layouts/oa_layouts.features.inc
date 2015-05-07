<?php
/**
 * @file
 * oa_layouts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_layouts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "pipelines") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function oa_layouts_default_page_manager_handlers_alter(&$data) {
  if (isset($data['node_edit_panel_context'])) {
    $data['node_edit_panel_context']->conf['display']->content['new-c0926cca-059c-4bb1-bccd-2838ec7a93f2']->position = 7; /* WAS: 6 */
    $data['node_edit_panel_context']->conf['display']->content['new-f2ca947f-f14f-4b9e-ac1f-2f8d94ca01a6'] = (object) array(
          'pid' => 'new-f2ca947f-f14f-4b9e-ac1f-2f8d94ca01a6',
          'panel' => 'sidebar',
          'type' => 'node_form_comment',
          'subtype' => 'node_form_comment',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'context' => 'argument_node_edit_1',
            'override_title' => 0,
            'override_title_text' => '',
            'override_title_heading' => 'h2',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 6,
          'locks' => array(),
          'uuid' => 'f2ca947f-f14f-4b9e-ac1f-2f8d94ca01a6',
        ); /* WAS: '' */
    $data['node_edit_panel_context']->conf['display']->panels['sidebar'][6] = 'new-f2ca947f-f14f-4b9e-ac1f-2f8d94ca01a6'; /* WAS: 'new-c0926cca-059c-4bb1-bccd-2838ec7a93f2' */
    $data['node_edit_panel_context']->conf['display']->panels['sidebar'][7] = 'new-c0926cca-059c-4bb1-bccd-2838ec7a93f2'; /* WAS: '' */
  }
}
