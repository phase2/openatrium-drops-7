<?php

/**
 * @file
 * Plugin to handle the page action_links.
 */

$plugin = array(
  'title' => t('Page action links'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A pane to show just the action links for a page as buttons.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

/**
 * Output function for the 'pane_action_links' content type.
 *
 * Outputs the action links of the current page.
 */
function oa_site_layout_pane_oa_action_links_content_type_render($subtype, $conf, $panel_messagesrgs) {
  $block = new stdClass();
  $block->content = theme('pane_oa_action_links');
  return $block;
}

function oa_site_layout_pane_oa_action_links_content_type_admin_info($subtype, $conf) {
  $block = new stdClass;
  $block->title = t('Page action links');
  $block->content = t('A pane to show just the action links for a page as buttons.');
  return $block;
}
