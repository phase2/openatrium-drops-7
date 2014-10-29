<?php

/**
 * @file
 * Hook implementations for the Variable module.
 */

/**
 * Implements hook_variable_info().
 */
function oa_worktracker_variable_info($options) {
  $description  = t('The possible values this field can contain.');

  $variable = array();
  $variable['oa_worktracker_assigned_to_users'] = array(
    'type' => 'select',
    'title' => t('Assign to users'),
    'options' => array(
      OA_WORKTRACKER_ASSIGN_TO_INHERITED_USERS => t('Members of the current space including inherited users.'),
      OA_WORKTRACKER_ASSIGN_TO_ONLY_LOCAL_USERS => t('Only members of the current space (excluding inherited users).'),
      OA_WORKTRACKER_ASSIGN_TO_ANY_USERS => t('Any user who can access the current space.'),
    ),
    'default' => OA_WORKTRACKER_ASSIGN_TO_INHERITED_USERS,
    'element' => array(
      '#type' => 'radios',
    ),
    'description' => t("Choose which users you'd like to be able to assign Tasks to."),
    'group' => 'oa_worktracker',
  );
  $variable['oa_worktracker_assigned_to_multiple'] = array(
    'type' => 'select',
    'title' => t('Copy for multiple'),
    'options' => array(
      0 => t('Disabled'),
      1 => t('Enabled'),
    ),
    'default' => 1,
    'description' => t("Allow users to select 'Copy for multiple' as the assigned user when creating new Tasks."),
    'group' => 'oa_worktracker',
  );
  $variable['oa_worktracker_allowed_values_priority'] = array(
    'type' => 'oa_worktracker_allowed_values',
    'title' => t('Priority values'),
    'numeric' => TRUE,
    'default' => array(
      'options' => array(
        2 => 'Low',
        5 => 'Normal',
        8 => 'High',
      ),
      'default_value' => 5,
    ),
    'description' => $description,
    'group' => 'oa_worktracker',
  );
  $variable['oa_worktracker_allowed_values_task_status'] = array(
    'type' => 'oa_worktracker_allowed_values',
    'title' => t('Status values'),
    'default' => array(
      'options' => array(
        'open' => 'Open',
        'duplicate' => 'Duplicate',
        'deferred' => 'Deferred',
        'closed' => 'Closed',
      ),
      'default_value' => 'open',
    ),
    'description' => $description,
    'group' => 'oa_worktracker',
  );
  $variable['oa_worktracker_allowed_values_task_type'] = array(
    'type' => 'oa_worktracker_allowed_values',
    'title' => t('Type values'),
    'default' => array(
      'options' => array(
        'task' => 'Task',
        'problem' => 'Problem',
        'feature' => 'Feature Request',
      ),
      'default_value' => 'task',
    ),
    'description' => $description,
    'group' => 'oa_worktracker',
  );
  return $variable;
}

/**
 * Implements hook_variable_group_info().
 */
function oa_worktracker_variable_group_info() {
  $groups = array();
  $groups['oa_worktracker'] = array(
    'title' => t('Work Tracker settings'),
    'description' => t('Settings for Open Atrium Work Tracker'),
    'access' => 'administer oa_worktracker',
  );
  return $groups;
}

/**
 * Implements hook_variable_type_info().
 */
function oa_worktracker_variable_type_info() {
  $types = array();
  $types['oa_worktracker_allowed_values'] = array(
    'title' => t('Allowed values'),
    'element' => array(
      '#type' => 'options',
      '#key_type' => 'custom',
      '#key_type_toggled' => TRUE,
    ),
    'default' => array('options' => array(), 'default_value' => ''),
    'element callback' => 'oa_worktracker_form_element_allowed_values',
    'validate callback' => 'oa_worktracker_form_element_validate_allowed_values',
  );
  return $types;
}

/**
 * Build $element array for 'oa_worktracker_allowed_values' variables.
 */
function oa_worktracker_form_element_allowed_values($variable, $options = array()) {
  $element = variable_form_element_default($variable, $options);
  $element['#options'] = $element['#default_value']['options'];
  $element['#default_value'] = $element['#default_value']['default_value'];

  // Add some text attempting to explain the key/value thing
  $element['#description'] .= ' ' . t('The key is what gets stored in the database and <em>sholdn\'t</em> be changed when there is already data using it. However, the value can be changed as much as you like!');

  // If this is a numeric field, be sure to tell the user!
  $numeric = isset($variable['numeric']) ? (bool)$variable['numeric'] : FALSE;
  if ($numeric) {
    $element['#description'] .= ' <strong>' . t('The keys for this field must be whole numbers.') . '</strong>';
  }

  return $element;
}

/**
 * Validate that the allowed values data is valid.
 */
function oa_worktracker_form_element_validate_allowed_values($variable) {
  $numeric = isset($variable['numeric']) ? (bool)$variable['numeric'] : FALSE;
  foreach ($variable['value']['options'] as $key => $value) {
    if ($numeric && !is_numeric($key)) {
      return t('The key %key is not a number.', array('%key' => $key));
    }
    if (strpos($value, '|') !== FALSE) {
      return t("Values cannot contain the pipe character '|'.");
    }
  }
  if ($numeric && !is_numeric($variable['value']['default_value'])) {
    return t('The default value must be a number.');
  }
}

