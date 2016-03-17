<?php

/**
 * @file
 * Plugin to handle the page tabs.
 */

$plugin = array(
  'title' => t('Page tabs'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A general pane to display just the page tabs (primary and secondary).'),
  'category' => t('Page elements'),
  'render last' => TRUE,
  'edit form' => 'oa_site_layout_pane_oa_tabs_edit_form',
  'defaults' => array(
    'hide_primary' => FALSE,
    'hide_secondary' => FALSE,
  ),
);

/**
 * Output function for the 'pane_tabs' content type.
 *
 * Outputs the tabs (local tasks) of the current page.
 */
function oa_site_layout_pane_oa_tabs_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $block->content = theme('pane_oa_tabs', $conf);
  return $block;
}

function oa_site_layout_pane_oa_tabs_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('Page tabs element');
  $block->content = t('By default, this pane will contain just the primary and secondary tabs of the page.');
  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_site_layout_pane_oa_tabs_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['hide_primary'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide primary tabs'),
    '#default_value' => (isset($conf['hide_primary'])) ? $conf['hide_primary'] : FALSE,
  );
  $form['hide_secondary'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide secondary tabs'),
    '#default_value' => (isset($conf['hide_secondary'])) ? $conf['hide_secondary'] : FALSE,
  );
  return $form;
}

function oa_site_layout_pane_oa_tabs_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
