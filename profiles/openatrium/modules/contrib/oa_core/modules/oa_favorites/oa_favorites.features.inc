<?php
/**
 * @file
 * oa_favorites.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function oa_favorites_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorite Space".
  $flags['favorite_space'] = array(
    'content_type' => 'node',
    'title' => 'Favorite Space',
    'global' => 0,
    'types' => array(
      0 => 'oa_space',
    ),
    'flag_short' => 'Favorite',
    'flag_long' => 'Mark Space as Favorite',
    'flag_message' => 'Favorited!',
    'unflag_short' => 'Remove Favorite',
    'unflag_long' => 'Unmark Space as Favorite',
    'unflag_message' => 'Unfavorited!',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'oa_favorites',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}
