<?php
/**
 * @file
 * Provides app info for oa wiki.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_wiki_apps_app_info() {
  $permissions = array();
  $permissions['node:oa_group:create oa_wiki_page content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );
  $permissions['node:oa_space:create oa_wiki_page content'] = array(
    'administrator member' => 'administrator member',
    'member' => 'member',
  );

  return array(
    'og permissions' => $permissions,
  );
}
