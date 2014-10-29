<?php
/**
 * @file
 * Code for Theme functions for OpenAtrium favorites widgets
 */


/**
 * Implements hook_theme()
 */
function oa_favorites_theme() {
  return array(
    'oa_favorites_favorites_button' => array(
      'template'  => 'oa-favorites-favorites-button',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => drupal_get_path('module', 'oa_favorites') . '/templates',
    ),
  );
}
