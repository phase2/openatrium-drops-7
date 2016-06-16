<?php
/**
 * @file
 * Theme and preprocess functions for contrib modules.
 */

/**
 * Preprocess function for Date pager template.
 */
function oa_basetheme_preprocess_date_views_pager(&$variables) {
  // Render pagers controls as buttons.
  $variables['prev_options']['attributes']['class'][] = 'btn';
  $variables['prev_options']['attributes']['class'][] = 'btn-default';
  $variables['next_options']['attributes']['class'][] = 'btn';
  $variables['next_options']['attributes']['class'][] = 'btn-default';
}

/**
 * Implements hook_libraries_info_alter().
 * DEPRECATED
 */
function oa_basetheme_libraries_info_alter(&$libraries) {
  // The code that used to set the Bootstrap vs jQuery weight is now part of oa_core
  // Subthemes no longer need to call this function
}
