<?php
/**
 * @file
 * Provides a panels pane that displays a toolbar line separator.
 */

$plugin = array(
  'title' => t('Toolbar vertical separator'),
  'description' => t('A vertical line between items in the toolbar.'),
  'category' => array(t('OA Admin'), -9),
  'render callback' => 'oa_toolbar_oa_separator_render',
  'defaults' => array(
  ),
);

/**
 * Render callback.
 */
function oa_toolbar_oa_separator_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $vars = array();
  $block->content = theme('oa_separator', $vars);
  return $block;
}
