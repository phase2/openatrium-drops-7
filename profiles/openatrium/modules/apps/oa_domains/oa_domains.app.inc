<?php
/**
 * @file
 * Provides app info for oa_domains.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_domains_apps_app_info() {
  return array(
    'configure form' => 'oa_core_app_configure_form',
  );
}
