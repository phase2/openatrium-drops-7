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
    'entity_type' => 'node',
    'title' => 'Favorite Space',
    'global' => 0,
    'types' => array(
      0 => 'oa_space',
    ),
    'flag_short' => 'Mark as Favorite',
    'flag_long' => 'Mark Space as Favorite',
    'flag_message' => 'Favorited!',
    'unflag_short' => 'Remove as Favorite',
    'unflag_long' => 'Unmark Space as Favorite',
    'unflag_message' => 'Unfavorited!',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => TRUE,
      'full' => TRUE,
    ),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'oa_favorites',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
