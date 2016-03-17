<?php
/**
 * @file
 * oa_site_layout_defaults.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function oa_contextual_tabs_defaultconfig_features() {
  return array(
    'oa_contextual_tabs' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function oa_contextual_tabs_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oa_contextual_move_ipe';
  $strongarm->value = 1;
  $export['oa_contextual_move_ipe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oa_contextual_restrict';
  $strongarm->value = 1;
  $export['oa_contextual_restrict'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oa_space_config_pages';
  $strongarm->value = 'node/*/map
node/*/content
node/*/oa_clone_create_space_type
node/*/archive
node/*/members';
  $export['oa_space_config_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oa_tasks_contextual';
  $strongarm->value = 'node/*/edit
node/*/view
node/*/moderation
node/*/revisions
node/*/clone*
node/*/archive-content';
  $export['oa_tasks_contextual'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oa_user_config_pages';
  $strongarm->value = 'user/*/settings
user/*/activity
user/*/bookmarks
user/*/subscribed
user/*/spaces
user/*/groups';
  $export['oa_user_config_pages'] = $strongarm;

  return $export;
}
