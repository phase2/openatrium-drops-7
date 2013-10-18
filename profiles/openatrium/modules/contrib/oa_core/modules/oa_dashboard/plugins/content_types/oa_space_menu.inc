<?php
/**
 * @file
 * Provides a panels pane that displays the OA Space Menu in the toolbar.
 */

$plugin = array(
  'title' => t('Open Atrium Space Menu'),
  'description' => t('The Open Atrium space-specific navigation menu.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
);

/**
 * Render callback.
 */
function oa_dashboard_oa_space_menu_content_type_render($subtype, $conf, $anel_args) {

  $node = menu_get_object();
  $front_panel = drupal_is_front_page() && !(isset($node) && ($node->type == OA_SPACE_TYPE));
  if ($front_panel) {
    return;
  }

  // grab the basic group menu from og_menu_single's content-type
  $space_menu = ctools_content_render('og_menu_single_menu', '', array(
    'og_menu_single_depth' => 1,
    'og_menu_single_parent' => '0',
    'override_title_text' => '',
    'override_title' => TRUE,
  ), array());
  if (!empty($space_menu->content)) {
    if (!empty($space_menu->content)) {
      // Format and add menu to template.
      $space_menu->content['#theme_wrappers'] = array('menu_tree__oa_navigation');
      foreach (element_children($space_menu->content) as $mlid) {
        // Render the links as Radix defaults.
        $space_menu->content[$mlid]['#theme'] = 'menu_link__oa_navigation';
      }
    }
    foreach ($space_menu->content as $key => $value) {
      if (!empty($value['#original_link']['menu_name'])) {
        // rename menu to prevent DHTML menu from hooking into this
        $space_menu->content[$key]['#original_link']['menu_name'] = 'oa-space-menu';
      }
    }
  }

  $block = new stdClass();
  $block->module = 'oa_dashboard';
  $block->content = (!empty($space_menu->content)) ? theme('oa_space_menu', array('menu' => $space_menu->content)) : '';

  return $block;
}

/**
 * Edit form callback.
 */
function oa_dashboard_oa_space_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
