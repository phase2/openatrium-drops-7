<?php
/**
 * @file
 * oa_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: create oa_event content.
  $permissions['create oa_event content'] = array(
    'name' => 'create oa_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any oa_event content.
  $permissions['delete any oa_event content'] = array(
    'name' => 'delete any oa_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own oa_event content.
  $permissions['delete own oa_event content'] = array(
    'name' => 'delete own oa_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any oa_event content.
  $permissions['edit any oa_event content'] = array(
    'name' => 'edit any oa_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own oa_event content.
  $permissions['edit own oa_event content'] = array(
    'name' => 'edit own oa_event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: trash any oa_event content.
  $permissions['trash any oa_event content'] = array(
    'name' => 'trash any oa_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_event content.
  $permissions['trash own oa_event content'] = array(
    'name' => 'trash own oa_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_event content.
  $permissions['untrash any oa_event content'] = array(
    'name' => 'untrash any oa_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_event content.
  $permissions['untrash own oa_event content'] = array(
    'name' => 'untrash own oa_event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}
