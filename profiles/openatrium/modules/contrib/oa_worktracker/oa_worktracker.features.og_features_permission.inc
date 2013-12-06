<?php
/**
 * @file
 * oa_worktracker.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function oa_worktracker_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:oa_space:create oa_worktracker_task content'
  $permissions['node:oa_space:create oa_worktracker_task content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_space:update any oa_worktracker_task content'
  $permissions['node:oa_space:update any oa_worktracker_task content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}
