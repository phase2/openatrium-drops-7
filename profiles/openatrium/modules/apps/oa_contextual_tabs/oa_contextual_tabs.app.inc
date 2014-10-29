<?php
/**
 * @file
 * Provides app info for oa_contextual_tabs.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_contextual_tabs_apps_app_info() {
  return array(
    'configure form' => 'oa_core_app_configure_form',
  );
}
