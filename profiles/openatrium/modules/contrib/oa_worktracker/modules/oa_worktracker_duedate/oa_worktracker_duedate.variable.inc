<?php

/**
 * @file
 * Hook implementations for the Variable module.
 */

/**
 * Implements hook_variable_info().
 */
function oa_worktracker_duedate_variable_info($options) {
  $variable = array();
  $variable['oa_worktracker_duedate_default_time'] = array(
    'type' => 'string',
    'title' => t('Default due date time'),
    'default' => '05:00pm',
    'description' => t('The default time used for the Due Date field if no time is given. For example: <em>05:00pm</em>'),
    'group' => 'oa_worktracker',
  );
  return $variable;
}
