<?php

/**
 * @file
 * Plugin to handle the page messages.
 */

$plugin = array(
  'title' => t('Page messages'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A general pane to display just the page messages.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

/**
 * Output function for the 'pane_messages' content type.
 *
 * Outputs the messages of the current page.
 */
function oa_site_layout_pane_oa_messages_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $block->content = theme('pane_oa_messages');
  return $block;
}

function oa_site_layout_pane_oa_messages_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('Page messages');
  $block->content = t('A general pane to display just the page messages.');
  return $block;
}
