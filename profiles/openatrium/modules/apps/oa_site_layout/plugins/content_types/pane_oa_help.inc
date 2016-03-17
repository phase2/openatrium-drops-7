<?php

/**
 * @file
 * Plugin to handle the page help text.
 */

$plugin = array(
  'title' => t('Page help'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A pane to show just the help text for the page.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

function oa_site_layout_pane_oa_help_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $block->content = theme('pane_oa_help');
  return $block;
}

function oa_site_layout_pane_oa_help_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('Page help');
  $block->content = t('A pane to show just the help text for the page.');
  return $block;
}
