<?php
/**
 * @file
 * oa_buttons.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function oa_buttons_taxonomy_default_vocabularies() {
  return array(
    'section_type' => array(
      'name' => 'Section Type',
      'machine_name' => 'section_type',
      'description' => 'Allow selection of Open Atrium sections',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'space_type' => array(
      'name' => 'Space Type',
      'machine_name' => 'space_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
