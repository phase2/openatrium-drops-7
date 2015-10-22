<?php

/**
 * @file
 * Provides a panels pane that shows the content's visibility.
 */

$plugin = array(
  'title' => t('Powered by Open Atrium'),
  'description' => t('Show powered-by logo.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_brand_powered_by_edit_form',
  'render callback' => 'oa_brand_powered_by_render',
);

/**
 * Render callback for the content visibility panel.
 */
function oa_brand_powered_by_render($subtype, $conf, $args, $context = NULL) {
  if (!empty($conf)) {
    // $conf is empty during popup previews, so don't load css
    drupal_add_css(drupal_get_path('module', 'oa_brand') . '/oa_brand_logo.css');
  }
  $block = new stdClass();

  $block->title = '';
  $block->content = l(t('Powered by'), 'http://openatrium.com',
    array('attributes' => array('class' => 'oa_powered_link')));
  return $block;
}

/**
 * Custom edit form for options
 */
function oa_brand_powered_by_edit_form($form, &$form_state) {
  return $form;
}


