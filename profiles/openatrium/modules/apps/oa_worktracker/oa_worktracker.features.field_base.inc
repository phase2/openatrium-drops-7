<?php
/**
 * @file
 * oa_worktracker.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oa_worktracker_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_oa_worktracker_assigned_to'
  $field_bases['field_oa_worktracker_assigned_to'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_worktracker_assigned_to',
    'foreign keys' => array(
      'users' => array(
        'columns' => array(
          'target_id' => 'uid',
        ),
        'table' => 'users',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'oa_worktracker_assigned',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
      ),
      'target_type' => 'user',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_oa_worktracker_priority'
  $field_bases['field_oa_worktracker_priority'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_worktracker_priority',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        2 => 'Low',
        5 => 'Normal',
        8 => 'High',
      ),
      'allowed_values_function' => 'oa_worktracker_allowed_values_callback',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_oa_worktracker_task_status'
  $field_bases['field_oa_worktracker_task_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_worktracker_task_status',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'open' => 'Open',
        'duplicate' => 'Duplicate',
        'deferred' => 'Deferred',
        'resolved' => 'Resolved',
        'closed' => 'Closed',
      ),
      'allowed_values_function' => 'oa_worktracker_allowed_values_callback',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_oa_worktracker_task_type'
  $field_bases['field_oa_worktracker_task_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_worktracker_task_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'problem' => 'Problem',
        'feature' => 'Feature Request',
        'task' => 'Task',
      ),
      'allowed_values_function' => 'oa_worktracker_allowed_values_callback',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
