<?php
/**
 * @file
 * oa_discussion.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function oa_discussion_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:oa_group:create oa_discussion_post content'
  $permissions['node:oa_group:create oa_discussion_post content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_space:create oa_discussion_post content'
  $permissions['node:oa_space:create oa_discussion_post content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}
