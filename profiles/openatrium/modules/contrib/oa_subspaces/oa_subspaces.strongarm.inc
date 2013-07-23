<?php
/**
 * @file
 * oa_subspaces.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_subspaces_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_subgroups_default_fields_node';
  $strongarm->value = array(
    0 => 'oa_parent_space',
  );
  $export['og_subgroups_default_fields_node'] = $strongarm;

  return $export;
}
