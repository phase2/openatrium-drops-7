<?php

/**
 * @file
 * Provides a panels pane that shows the default home page
 * This is a simple pane that just renders a tpl template that
 * you can override in your own theme
 */

$plugin = array(
  'title' => t('Default Home Panel'),
  'description' => t('A panel displays the default Open Atrium home page.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_home_default_edit_form',
  'render callback' => 'oa_home_default_render',
);


/**
 * Render callback for the panel.
 */
function oa_home_default_render($subtype, $conf, $args, $context = NULL) {
  global $user;
  if (!empty($conf)) {
    // $conf is empty during popup previews, so don't load css
    drupal_add_css(drupal_get_path('module', 'oa_home') . '/oa_home_default.css');
    // Add any brand-specific styling.
    module_invoke_all('oa_core_brand');
  }
  $block = new stdClass();
  $block->title = '';
  $vars = array();
  if (!$user->uid) {
    $login_block = block_load('user', 'login');
    $vars['login'] = _block_get_renderable_array(_block_render_blocks(array($login_block)));
  }
  else {
    $user_record = user_load($user->uid);
    $name = oa_core_realname($user_record);
    $vars['username'] = $name;
  }
  $block->content = theme('oa_home_default', $vars);
  oa_core_body_classes('oa-home');
  return $block;
}


/**
 * Edit form for the panel.
 */
function oa_home_default_edit_form($form, &$form_state) {
  return $form;
}
