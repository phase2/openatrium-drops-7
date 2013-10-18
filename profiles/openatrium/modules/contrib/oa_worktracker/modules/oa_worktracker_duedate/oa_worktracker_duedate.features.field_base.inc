<?php
/**
 * @file
 * oa_worktracker_duedate.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oa_worktracker_duedate_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_oa_worktracker_duedate'
  $field_bases['field_oa_worktracker_duedate'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_worktracker_duedate',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'repeat' => 0,
      'timezone_db' => 'UTC',
      'todate' => '',
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  return $field_bases;
}
