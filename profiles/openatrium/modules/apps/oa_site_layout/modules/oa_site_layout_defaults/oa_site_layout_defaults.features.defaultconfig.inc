<?php
/**
 * @file
 * oa_site_layout_defaults.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function oa_site_layout_defaults_defaultconfig_features() {
  return array(
    'oa_site_layout_defaults' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function oa_site_layout_defaults_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oa_show_visibility_panel';
  $strongarm->value = 0;
  $export['oa_show_visibility_panel'] = $strongarm;

  return $export;
}
