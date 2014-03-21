<?php
/**
 * @file
 * oa_clone.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_clone_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_use_node_type_name';
  $strongarm->value = '1';
  $export['clone_use_node_type_name'] = $strongarm;

  return $export;
}
