<?php
/**
 * @file
 * oa_analytics.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function oa_analytics_defaultconfig_features() {
  return array(
    'oa_analytics' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function oa_analytics_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_custom_var';
  $strongarm->value = array(
    'slots' => array(
      1 => array(
        'slot' => 1,
        'name' => 'oa_group',
        'value' => '',
        'scope' => '3',
      ),
      2 => array(
        'slot' => 2,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
      3 => array(
        'slot' => 3,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
      4 => array(
        'slot' => 4,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
      5 => array(
        'slot' => 5,
        'name' => '',
        'value' => '',
        'scope' => '3',
      ),
    ),
  );
  $export['googleanalytics_custom_var'] = $strongarm;

  return $export;
}
