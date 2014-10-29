<?php
/**
 * @file
 * Provides app info for oa markdown.
 */

/**
 * Implements hook_apps_app_info().
 */
function oa_markdown_apps_app_info() {
  return array(
    'permissions' => array(
      'use text format markdown' => array(
        'administrator' => 'administrator',
      ),
    ),
  );
}
