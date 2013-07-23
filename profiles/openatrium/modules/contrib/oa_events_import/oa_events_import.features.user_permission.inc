<?php
/**
 * @file
 * oa_events_import.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_events_import_user_default_permissions() {
  $permissions = array();

  // Exported permission: create oa_ical_importer content.
  $permissions['create oa_ical_importer content'] = array(
    'name' => 'create oa_ical_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any oa_ical_importer content.
  $permissions['delete any oa_ical_importer content'] = array(
    'name' => 'delete any oa_ical_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own oa_ical_importer content.
  $permissions['delete own oa_ical_importer content'] = array(
    'name' => 'delete own oa_ical_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any oa_ical_importer content.
  $permissions['edit any oa_ical_importer content'] = array(
    'name' => 'edit any oa_ical_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own oa_ical_importer content.
  $permissions['edit own oa_ical_importer content'] = array(
    'name' => 'edit own oa_ical_importer content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: trash any oa_ical_importer content.
  $permissions['trash any oa_ical_importer content'] = array(
    'name' => 'trash any oa_ical_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_ical_importer content.
  $permissions['trash own oa_ical_importer content'] = array(
    'name' => 'trash own oa_ical_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_ical_importer content.
  $permissions['untrash any oa_ical_importer content'] = array(
    'name' => 'untrash any oa_ical_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_ical_importer content.
  $permissions['untrash own oa_ical_importer content'] = array(
    'name' => 'untrash own oa_ical_importer content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}
