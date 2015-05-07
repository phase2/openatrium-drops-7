<?php
/**
 * @file
 * oa_layouts.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_layouts_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.node_edit_panel_context.conf|display|content|new-c0926cca-059c-4bb1-bccd-2838ec7a93f2|position"] = 7;
  $overrides["page_manager_handlers.node_edit_panel_context.conf|display|content|new-f2ca947f-f14f-4b9e-ac1f-2f8d94ca01a6"] = (object) array(
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
    );
  $overrides["page_manager_handlers.node_edit_panel_context.conf|display|panels|sidebar|6"] = 'new-f2ca947f-f14f-4b9e-ac1f-2f8d94ca01a6';
  $overrides["page_manager_handlers.node_edit_panel_context.conf|display|panels|sidebar|7"] = 'new-c0926cca-059c-4bb1-bccd-2838ec7a93f2';

 return $overrides;
}
