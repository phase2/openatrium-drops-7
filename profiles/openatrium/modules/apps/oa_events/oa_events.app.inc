<?php
/**
 * @file
 * Provides app info for oa_events.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_events_apps_app_info() {
  $permissions = array();
  // Exported og permission: 'node:oa_group:create oa_event content'
  $permissions['node:oa_group:create oa_event content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );

  // Exported og permission: 'node:oa_space:create oa_event content'
  $permissions['node:oa_space:create oa_event content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );

  return array(
    'og permissions' => $permissions,
    'configure form' => 'oa_core_app_configure_form',
  );
}
