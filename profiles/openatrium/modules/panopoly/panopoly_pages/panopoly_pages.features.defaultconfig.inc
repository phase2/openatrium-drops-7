<?php
/**
 * @file
 * panopoly_pages.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function panopoly_pages_defaultconfig_features() {
  return array(
    'panopoly_pages' => array(
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function panopoly_pages_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create panopoly_page content'.
  $permissions['create panopoly_page content'] = array(
    'name' => 'create panopoly_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any panopoly_page content'.
  $permissions['delete any panopoly_page content'] = array(
    'name' => 'delete any panopoly_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own panopoly_page content'.
  $permissions['delete own panopoly_page content'] = array(
    'name' => 'delete own panopoly_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any panopoly_page content'.
  $permissions['edit any panopoly_page content'] = array(
    'name' => 'edit any panopoly_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own panopoly_page content'.
  $permissions['edit own panopoly_page content'] = array(
    'name' => 'edit own panopoly_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
