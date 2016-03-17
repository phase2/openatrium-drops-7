<?php

/**
 * @file
 * Plugin to handle the 'page' content type which allows the standard page
 * template variables to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Page header'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A general page header block that includes site name, logo and a search box. This can be easily modified by overriding pane-header.tpl.php in your theme.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

/**
 * Output function for the 'pane_tabs' content type.
 *
 * Outputs the tabs (local tasks) of the current page.
 */
function panels_everywhere_pane_header_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $block->content = theme('pane_header');
  return $block;
}

function panels_everywhere_pane_header_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('Page header elements');
  $block->content = t('By default, this pane will contain the site name, logo and search box. Its actual contents can be easily themed by editing pane-header.tpl.php in the site theme.');
  return $block;
}
