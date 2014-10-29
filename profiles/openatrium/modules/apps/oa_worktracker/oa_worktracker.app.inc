<?php
/**
 * @file
 * Provides app info for oa_worktracker.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_worktracker_apps_app_info() {
  $permissions = array();
  $permissions['node:oa_space:create oa_worktracker_task content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );

  $permissions['node:oa_space:update any oa_worktracker_task content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );

  return array(
    'configure form' => 'oa_worktracker_apps_configure_form',
    'og permissions' => $permissions,
  );
}
