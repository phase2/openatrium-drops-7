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
    0 => 'oa_layouts_minipanel_header',
    1 => 'oa_layouts_minipanel_footer',
    2 => 'oa_wiki_vocab',
    3 => 'oa_worktracker_assigned_to_users',
    4 => 'oa_worktracker_allowed_values_priority',
    5 => 'oa_worktracker_allowed_values_task_status',
    6 => 'oa_worktracker_allowed_values_task_type',
    7 => 'site_name',
    8 => 'site_mail',
  );
  $export['variable_realm_list_og'] = $strongarm;

  return $export;
}
