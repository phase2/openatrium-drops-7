<?php
/**
 * @file
 * oa_teams.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_teams_user_default_permissions() {
  $permissions = array();

  // Exported permission: create oa_team content.
  $permissions['create oa_team content'] = array(
    'name' => 'create oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any oa_team content.
  $permissions['delete any oa_team content'] = array(
    'name' => 'delete any oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own oa_team content.
  $permissions['delete own oa_team content'] = array(
    'name' => 'delete own oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any oa_team content.
  $permissions['edit any oa_team content'] = array(
    'name' => 'edit any oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own oa_team content.
  $permissions['edit own oa_team content'] = array(
    'name' => 'edit own oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: trash any oa_team content.
  $permissions['trash any oa_team content'] = array(
    'name' => 'trash any oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_team content.
  $permissions['trash own oa_team content'] = array(
    'name' => 'trash own oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_team content.
  $permissions['untrash any oa_team content'] = array(
    'name' => 'untrash any oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_team content.
  $permissions['untrash own oa_team content'] = array(
    'name' => 'untrash own oa_team content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}
