<?php
/**
 * @file
 * oa_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: create oa_group content.
  $permissions['create oa_group content'] = array(
    'name' => 'create oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create oa_space content.
  $permissions['create oa_space content'] = array(
    'name' => 'create oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any oa_group content.
  $permissions['delete any oa_group content'] = array(
    'name' => 'delete any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any oa_space content.
  $permissions['delete any oa_space content'] = array(
    'name' => 'delete any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own oa_group content.
  $permissions['delete own oa_group content'] = array(
    'name' => 'delete own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own oa_space content.
  $permissions['delete own oa_space content'] = array(
    'name' => 'delete own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any oa_group content.
  $permissions['edit any oa_group content'] = array(
    'name' => 'edit any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any oa_space content.
  $permissions['edit any oa_space content'] = array(
    'name' => 'edit any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own oa_group content.
  $permissions['edit own oa_group content'] = array(
    'name' => 'edit own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own oa_space content.
  $permissions['edit own oa_space content'] = array(
    'name' => 'edit own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: trash any oa_group content.
  $permissions['trash any oa_group content'] = array(
    'name' => 'trash any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash any oa_space content.
  $permissions['trash any oa_space content'] = array(
    'name' => 'trash any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_group content.
  $permissions['trash own oa_group content'] = array(
    'name' => 'trash own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_space content.
  $permissions['trash own oa_space content'] = array(
    'name' => 'trash own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_group content.
  $permissions['untrash any oa_group content'] = array(
    'name' => 'untrash any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_space content.
  $permissions['untrash any oa_space content'] = array(
    'name' => 'untrash any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_group content.
  $permissions['untrash own oa_group content'] = array(
    'name' => 'untrash own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_space content.
  $permissions['untrash own oa_space content'] = array(
    'name' => 'untrash own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}
