<?php
/**
 * @file
 * oa_events.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function oa_events_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:oa_group:create oa_event content'
  $permissions['node:oa_group:create oa_event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_space:create oa_event content'
  $permissions['node:oa_space:create oa_event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}
