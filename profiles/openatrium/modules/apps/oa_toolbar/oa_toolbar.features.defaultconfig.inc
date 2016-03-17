<?php
/**
 * @file
 * oa_toolbar.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function oa_toolbar_defaultconfig_features() {
  return array(
    'oa_toolbar' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function oa_toolbar_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oa_toolbar_mouseover';
  $strongarm->value = 1;
  $export['oa_toolbar_mouseover'] = $strongarm;

  return $export;
}
