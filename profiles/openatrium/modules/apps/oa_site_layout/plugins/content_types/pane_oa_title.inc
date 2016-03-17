<?php

/**
 * @file
 * Plugin to handle the page help text.
 */

$plugin = array(
  'title' => t('Page title'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A pane to show just the page title.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

function oa_site_layout_pane_oa_title_content_type_render($subtype, $conf, $panel_args) {
  if (!empty($GLOBALS['oa_hide_page_title'])) {
    // allow a global removal of page title if used in other widgets
    return FALSE;
  }

  $block = new stdClass();
  $block->content = theme('pane_oa_title');
  return $block;
}

function oa_site_layout_pane_oa_title_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('Page title');
  $block->content = t('A pane to show just the page title.');
  return $block;
}
