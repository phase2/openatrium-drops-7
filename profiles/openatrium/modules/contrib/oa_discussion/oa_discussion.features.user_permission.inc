<?php
/**
 * @file
 * oa_discussion.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_discussion_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node oa_discussion_post breadcrumbs.
  $permissions['administer panelizer node oa_discussion_post breadcrumbs'] = array(
    'name' => 'administer panelizer node oa_discussion_post breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post content.
  $permissions['administer panelizer node oa_discussion_post content'] = array(
    'name' => 'administer panelizer node oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post context.
  $permissions['administer panelizer node oa_discussion_post context'] = array(
    'name' => 'administer panelizer node oa_discussion_post context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post defaults.
  $permissions['administer panelizer node oa_discussion_post defaults'] = array(
    'name' => 'administer panelizer node oa_discussion_post defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post layout.
  $permissions['administer panelizer node oa_discussion_post layout'] = array(
    'name' => 'administer panelizer node oa_discussion_post layout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post overview.
  $permissions['administer panelizer node oa_discussion_post overview'] = array(
    'name' => 'administer panelizer node oa_discussion_post overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post settings.
  $permissions['administer panelizer node oa_discussion_post settings'] = array(
    'name' => 'administer panelizer node oa_discussion_post settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: create oa_discussion_post content.
  $permissions['create oa_discussion_post content'] = array(
    'name' => 'create oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any oa_discussion_post content.
  $permissions['delete any oa_discussion_post content'] = array(
    'name' => 'delete any oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own oa_discussion_post content.
  $permissions['delete own oa_discussion_post content'] = array(
    'name' => 'delete own oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any oa_discussion_post content.
  $permissions['edit any oa_discussion_post content'] = array(
    'name' => 'edit any oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own oa_discussion_post content.
  $permissions['edit own oa_discussion_post content'] = array(
    'name' => 'edit own oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: trash any oa_discussion_post content.
  $permissions['trash any oa_discussion_post content'] = array(
    'name' => 'trash any oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_discussion_post content.
  $permissions['trash own oa_discussion_post content'] = array(
    'name' => 'trash own oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_discussion_post content.
  $permissions['untrash any oa_discussion_post content'] = array(
    'name' => 'untrash any oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_discussion_post content.
  $permissions['untrash own oa_discussion_post content'] = array(
    'name' => 'untrash own oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}
