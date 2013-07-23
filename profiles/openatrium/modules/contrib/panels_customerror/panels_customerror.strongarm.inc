<?php
/**
 * @file
 * panels_customerror.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function panels_customerror_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_403';
  $strongarm->value = 'access-denied';
  $export['site_403'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_404';
  $strongarm->value = 'page-not-found';
  $export['site_404'] = $strongarm;

  return $export;
}
