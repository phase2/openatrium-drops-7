<?php

/**
 * @file
 * Plugin to provide access control based on user permission strings in a group.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Node: current access to current node"),
  'description' => t('Control access by current node for current user.'),
  'callback' => 'node_access_current_node_ctools_access_check',
  'default' => array('perm' => ''),
  'settings form' => 'node_access_current_node_ctools_access_settings',
  'summary' => 'node_access_current_node_ctools_access_summary',
);

/**
 * Settings form for the 'by perm' access plugin
 */
function node_access_current_node_ctools_access_settings($form, &$form_state, $conf) {
  $perms = array();
  // Get list of permissions
  foreach (og_get_permissions() as $perm => $value) {
    // By keeping them keyed by module we can use optgroups with the
    // 'select' type.
    $perms[$value['module']][$perm] = $value['title'];
  }

  $form['settings']['op'] = array(
    '#type' => 'select',
    '#options' => array(
      'view' => t('View'),
      'update' => t('Edit'),
      'delete' => t('Delete')
    ),
    '#title' => t('Operation'),
    '#default_value' => isset($conf['perm']) ? $conf['perm'] : 'view',
    '#description' => t('Only users with the ability to selected operation on current node may.'),
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Check for access.
 */
function node_access_current_node_ctools_access_check($conf, $context) {
  global $user;
  $node = menu_get_object();
  if (!$node) {
    return FALSE;
  }
  return node_access($conf['op'], $node);
}

/**
 * Provide a summary description based upon the checked permissions.
 */
function node_access_current_node_ctools_access_summary($conf, $context) {
  return t('Current has @op permission from node via URL', array('@op' => $conf['op']));
}

