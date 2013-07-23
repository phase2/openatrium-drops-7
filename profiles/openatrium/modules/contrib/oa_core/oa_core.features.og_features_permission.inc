<?php
/**
 * @file
 * oa_core.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function oa_core_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:oa_group:create oa_space content'
  $permissions['node:oa_group:create oa_space content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_group:delete any oa_space content'
  $permissions['node:oa_group:delete any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:delete own oa_space content'
  $permissions['node:oa_group:delete own oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:trash any oa_group content'
  $permissions['node:oa_group:trash any oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:trash any oa_space content'
  $permissions['node:oa_group:trash any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:trash own oa_group content'
  $permissions['node:oa_group:trash own oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:trash own oa_space content'
  $permissions['node:oa_group:trash own oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:untrash any oa_group content'
  $permissions['node:oa_group:untrash any oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:untrash any oa_space content'
  $permissions['node:oa_group:untrash any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:untrash own oa_group content'
  $permissions['node:oa_group:untrash own oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:untrash own oa_space content'
  $permissions['node:oa_group:untrash own oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:update any oa_space content'
  $permissions['node:oa_group:update any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:update own oa_space content'
  $permissions['node:oa_group:update own oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:create oa_space content'
  $permissions['node:oa_space:create oa_space content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_space:delete any oa_space content'
  $permissions['node:oa_space:delete any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:delete own oa_space content'
  $permissions['node:oa_space:delete own oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:trash any oa_group content'
  $permissions['node:oa_space:trash any oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:trash any oa_space content'
  $permissions['node:oa_space:trash any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:trash own oa_group content'
  $permissions['node:oa_space:trash own oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:trash own oa_space content'
  $permissions['node:oa_space:trash own oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:untrash any oa_group content'
  $permissions['node:oa_space:untrash any oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:untrash any oa_space content'
  $permissions['node:oa_space:untrash any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:untrash own oa_group content'
  $permissions['node:oa_space:untrash own oa_group content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:untrash own oa_space content'
  $permissions['node:oa_space:untrash own oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:update any oa_space content'
  $permissions['node:oa_space:update any oa_space content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:update own oa_space content'
  $permissions['node:oa_space:update own oa_space content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
