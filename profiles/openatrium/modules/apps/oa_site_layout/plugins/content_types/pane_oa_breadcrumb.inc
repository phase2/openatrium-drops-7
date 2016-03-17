<?php

/**
 * @file
 * Plugin to handle the page breadcrumbs.
 */

$plugin = array(
  'title' => t('Page breadcrumbs'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A general pane to display just the page breadcrumbs.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

/**
 * Output function for the 'pane_tabs' content type.
 *
 * Outputs the tabs (local tasks) of the current page.
 */
function oa_site_layout_pane_oa_breadcrumb_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $block->content = theme('pane_oa_breadcrumb');
  return $block;
}

function oa_site_layout_pane_oa_breadcrumb_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('Page breadcrumbs');
  $block->content = t('A general pane to display just the page breadcrumbs.');
  return $block;
}
