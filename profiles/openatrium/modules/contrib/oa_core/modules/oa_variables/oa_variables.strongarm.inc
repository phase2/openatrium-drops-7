<?php
/**
 * @file
 * oa_variables.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_variables_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'variable_realm_list_og';
  $strongarm->value = array(
    0 => 'site_name',
    1 => 'site_mail',
  );
  $export['variable_realm_list_og'] = $strongarm;

  return $export;
}
