<?php

/**
 * @file
 * Plugin to handle the 'page' content type which allows the standard page
 * template variables to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Page navigation'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A general page navigation block that includes primary links, secondary links and breadcrumb. This can be easily modified by overriding pane-navigation.tpl.php in your theme.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

function panels_everywhere_pane_navigation_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $block->content = theme('pane_navigation');
  return $block;
}

function panels_everywhere_pane_navigation_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->title = t('Page primary navigation and breadcrumb');
  $block->content = t('A general page navigation block that includes primary links, secondary links and breadcrumb. This can be easily modified by overriding pane-navigation.tpl.php in your theme.');
  return $block;
}
