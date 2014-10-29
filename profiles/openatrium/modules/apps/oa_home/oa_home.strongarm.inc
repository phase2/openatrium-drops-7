<?php
/**
 * @file
 * oa_home.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_home_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorizer_cssbase';
  $strongarm->value = 'assets/stylesheets/colorizer.css.php';
  $export['colorizer_cssbase'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorizer_cssfile';
  $strongarm->value = 'assets/stylesheets/colorizer.css';
  $export['colorizer_cssfile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorizer_incfile';
  $strongarm->value = 'colorizer.inc';
  $export['colorizer_incfile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorizer_previewfile';
  $strongarm->value = 'templates/colorizer.htm';
  $export['colorizer_previewfile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'home';
  $export['site_frontpage'] = $strongarm;

  return $export;
}
