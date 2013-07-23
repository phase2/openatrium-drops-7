<?php
/**
 * @file
 * trash_flag.features.inc
 */

/**
 * Implements hook_views_api().
 */
function trash_flag_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function trash_flag_flag_default_flags() {
  $flags = array();
  // Exported flag: "Trash".
  $flags['trash'] = array(
    'content_type' => 'node',
    'title' => 'Trash',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'Move to Trash',
    'flag_long' => 'Move item to the site trash bin.',
    'flag_message' => 'Item has been trashed',
    'unflag_short' => 'Remove from Trash',
    'unflag_long' => 'Remove from trash item and restore previous access settings.',
    'unflag_message' => 'Item removed from Trash',
    'unflag_denied_text' => 'trashed',
    'link_type' => 'confirm',
    'roles' => array(
      'flag' => array(),
      'unflag' => array(),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to trash this item? You may be unable to access it after trashing.',
    'unflag_confirmation' => 'Are you sure you want to remove this item from trash?',
    'module' => 'trash_flag',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}
