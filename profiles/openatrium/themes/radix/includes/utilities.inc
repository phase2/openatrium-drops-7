<?php
/**
 * @file
 * Helper functions for the Radix theme.
 */

/**
 * Returns Bootstrap panel classes.
 */
function _radix_get_bootstrap_panel_classes() {
  return array(
    'panel-default',
    'panel-primary',
    'panel-success',
    'panel-info',
    'panel-warning',
    'panel-danger'
  );
}

/**
 * Returns the current active theme.
 */
function _radix_current_theme() {
  global $custom_theme, $theme;

  if (!empty($custom_theme)) {
    $current_theme = $custom_theme;
  }
  else {
    $current_theme = $theme ? $theme : variable_get('theme_default', 'garland');
  }

  return $current_theme;
}

/**
 * Returns the current base theme.
 */
function _radix_base_theme() {
  $current_theme = _radix_current_theme();

  // Special case to return quickly if theme is radix, since we already
  // know the answer to this question.
  if ($current_theme == 'radix') {
    return NULL;
  }

  $themes = list_themes();
  $theme_object = $themes[$current_theme];
  return !empty($theme_object->info['base theme']) ? $theme_object->info['base theme'] : NULL;
}
