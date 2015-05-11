<?php
/**
 * @file
 * Provides app info for oa wiki.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_discussion_apps_app_info() {
  $permissions = array();
  $permissions['node:oa_group:create oa_discussion_post content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );
  $permissions['node:oa_space:create oa_discussion_post content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );

  return array(
    'og permissions' => $permissions,
  );
}
