<?php
/**
 * @file
 * Theme and preprocess functions for menus
 */

/**
 * Implements theme_menu_tree().
 */
function oa_radix_menu_tree(&$variables) {
  // override Radix menu.inc with default Drupal behavior
  return theme_menu_tree($variables);
}

/**
 * Implements theme_menu_link().
 */
function oa_radix_menu_link(&$variables) {
  // override Radix menu.inc with default Drupal behavior
  return theme_menu_link($variables);
}

/**
 * Implements theme_menu_tree__MENU_NAME().
 */
function oa_radix_menu_tree__oa_navigation(&$variables) {
  return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_menu_link__MENU_NAME().
 */
function oa_radix_menu_link__oa_navigation(&$variables) {
  return radix_menu_link($variables);
}
