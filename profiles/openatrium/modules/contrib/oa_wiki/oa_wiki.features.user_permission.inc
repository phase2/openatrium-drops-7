<?php
/**
 * @file
 * oa_wiki.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_wiki_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node oa_wiki_page breadcrumbs.
  $permissions['administer panelizer node oa_wiki_page breadcrumbs'] = array(
    'name' => 'administer panelizer node oa_wiki_page breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page content.
  $permissions['administer panelizer node oa_wiki_page content'] = array(
    'name' => 'administer panelizer node oa_wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page context.
  $permissions['administer panelizer node oa_wiki_page context'] = array(
    'name' => 'administer panelizer node oa_wiki_page context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page defaults.
  $permissions['administer panelizer node oa_wiki_page defaults'] = array(
    'name' => 'administer panelizer node oa_wiki_page defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page layout.
  $permissions['administer panelizer node oa_wiki_page layout'] = array(
    'name' => 'administer panelizer node oa_wiki_page layout',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page overview.
  $permissions['administer panelizer node oa_wiki_page overview'] = array(
    'name' => 'administer panelizer node oa_wiki_page overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page settings.
  $permissions['administer panelizer node oa_wiki_page settings'] = array(
    'name' => 'administer panelizer node oa_wiki_page settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: create oa_wiki_page content.
  $permissions['create oa_wiki_page content'] = array(
    'name' => 'create oa_wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any oa_wiki_page content.
  $permissions['delete any oa_wiki_page content'] = array(
    'name' => 'delete any oa_wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own oa_wiki_page content.
  $permissions['delete own oa_wiki_page content'] = array(
    'name' => 'delete own oa_wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any oa_wiki_page content.
  $permissions['edit any oa_wiki_page content'] = array(
    'name' => 'edit any oa_wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own oa_wiki_page content.
  $permissions['edit own oa_wiki_page content'] = array(
    'name' => 'edit own oa_wiki_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: trash any oa_wiki_page content.
  $permissions['trash any oa_wiki_page content'] = array(
    'name' => 'trash any oa_wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_wiki_page content.
  $permissions['trash own oa_wiki_page content'] = array(
    'name' => 'trash own oa_wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_wiki_page content.
  $permissions['untrash any oa_wiki_page content'] = array(
    'name' => 'untrash any oa_wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_wiki_page content.
  $permissions['untrash own oa_wiki_page content'] = array(
    'name' => 'untrash own oa_wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}
