<?php

/**
 * @file
 * Provides a panels pane that shows space banner
 */

$plugin = array(
  'title' => t('Space Banner'),
  'description' => t('A panel for the space banner image.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_space_banner_edit_form',
  'render callback' => 'oa_space_banner_render',
  'defaults' => array(
    'banner_position' => 2,
  ),
);


/**
 * Render callback for the panel.
 */
function oa_space_banner_render($subtype, $conf, $args, $context = NULL) {
  global $base_url;

  $space_id = oa_core_get_space_home_context();
  $position = isset($conf['banner_position']) ? $conf['banner_position'] : OA_SPACE_BANNER_BELOW;

  $banner = oa_appearance_get_space_banner($space_id, $position);
  if ($banner['position'] == 0) {
    return;
  }

  drupal_add_js(drupal_get_path('module', 'oa_appearance') . '/oa_appearance.js');

  $vars = array();

  $vars['banner_class'] = ($position == 1) ? 'oa-banner-before' : 'oa-banner-after';
  $vars['banner'] = !empty($banner['image']) ? theme('image', $banner['image']) : '';
  $vars['width'] = isset($banner['image']['width']) ? $banner['image']['width'] : 0;
  $vars['height'] = isset($banner['image']['height']) ? $banner['image']['height'] : 0;
  $vars['text'] = $banner['text'];
  $vars['slogan'] = $banner['slogan'];
  $vars['banner_text_class'] = 'oa-banner-overlay';
  $vars['banner_slogan_class'] = 'oa-banner-slogan-overlay';
  if (empty($banner['image']) || !$banner['stretch']) {
    $vars['banner_text_class'] = 'oa-banner-text';
    $vars['banner_slogan_class'] = 'oa-banner-slogan';
  }

  $block = new stdClass();
  $block->title = '';
  $block->content = theme('oa_space_banner', $vars);
  return $block;
}


/**
 * Edit form for the panel.
 */
function oa_space_banner_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['banner_position'] = array(
    '#type' => 'select',
    '#options' => array(
      0 => 'Hidden',
      1 => 'Above toolbar',
      2 => 'Below toolbar',
    ),
    '#title' => 'Banner Position',
    '#empty_option' => '--Banner Position--',
    '#default_value' => $conf['banner_position'],
  );

  return $form;
}

function oa_space_banner_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
