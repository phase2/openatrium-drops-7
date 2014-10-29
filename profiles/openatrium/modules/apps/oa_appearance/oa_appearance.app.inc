<?php
/**
 * @file
 * Provides app info for oa analytics.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_appearance_apps_app_info() {
  return array(
    'configure form' => 'oa_core_app_configure_form',
  );
}
