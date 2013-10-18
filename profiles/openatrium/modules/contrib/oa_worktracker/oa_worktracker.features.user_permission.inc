<?php
/**
 * @file
 * oa_worktracker.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_worktracker_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node oa_worktracker_task breadcrumbs'.
  $permissions['administer panelizer node oa_worktracker_task breadcrumbs'] = array(
    'name' => 'administer panelizer node oa_worktracker_task breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node oa_worktracker_task content'.
  $permissions['administer panelizer node oa_worktracker_task content'] = array(
    'name' => 'administer panelizer node oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node oa_worktracker_task context'.
  $permissions['administer panelizer node oa_worktracker_task context'] = array(
    'name' => 'administer panelizer node oa_worktracker_task context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node oa_worktracker_task defaults'.
  $permissions['administer panelizer node oa_worktracker_task defaults'] = array(
    'name' => 'administer panelizer node oa_worktracker_task defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node oa_worktracker_task layout'.
  $permissions['administer panelizer node oa_worktracker_task layout'] = array(
    'name' => 'administer panelizer node oa_worktracker_task layout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node oa_worktracker_task overview'.
  $permissions['administer panelizer node oa_worktracker_task overview'] = array(
    'name' => 'administer panelizer node oa_worktracker_task overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node oa_worktracker_task settings'.
  $permissions['administer panelizer node oa_worktracker_task settings'] = array(
    'name' => 'administer panelizer node oa_worktracker_task settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'create oa_worktracker_task content'.
  $permissions['create oa_worktracker_task content'] = array(
    'name' => 'create oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any oa_worktracker_task content'.
  $permissions['delete any oa_worktracker_task content'] = array(
    'name' => 'delete any oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own oa_worktracker_task content'.
  $permissions['delete own oa_worktracker_task content'] = array(
    'name' => 'delete own oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any oa_worktracker_task content'.
  $permissions['edit any oa_worktracker_task content'] = array(
    'name' => 'edit any oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own oa_worktracker_task content'.
  $permissions['edit own oa_worktracker_task content'] = array(
    'name' => 'edit own oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'trash any oa_worktracker_task content'.
  $permissions['trash any oa_worktracker_task content'] = array(
    'name' => 'trash any oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: 'trash own oa_worktracker_task content'.
  $permissions['trash own oa_worktracker_task content'] = array(
    'name' => 'trash own oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: 'untrash any oa_worktracker_task content'.
  $permissions['untrash any oa_worktracker_task content'] = array(
    'name' => 'untrash any oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: 'untrash own oa_worktracker_task content'.
  $permissions['untrash own oa_worktracker_task content'] = array(
    'name' => 'untrash own oa_worktracker_task content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}
