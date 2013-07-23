<?php

/**
 * @file
 * Provides Color integration on behalf of user.module.
 */

/**
 * Implements hook_colors_info().
 */
function user_colors_info() {
  return array(
    'user_role' => array(
      'title' => 'User role',
      'short_description' => t('Enable colors for user role'),
      'long_description' => t('Colors for user roles. If enabled, you may set colors for each user role below.'),
      'function' => 'user_roles',
    ),
    'user_current' => array(
      'title' => 'Current user',
      'short_description' => t('Enable a color for the current user'),
      'long_description' => t('A color for the current user. If enabled, you may set one color for items the current user has authored.'),
      'function' => '_user_current',
    ),
    'users' => array(
      'title' => 'Users',
      'short_description' => t('Enable colors for each user'),
      'long_description' => t('Colors for users. If enabled, you may set colors for each user below.'),
      'function' => '_colors_users',
    ),
  );
}

/**
 * Implements hook_colors_classes().
 *
 * Provide colors per user role.
 */
function user_colors_classes($entity) {
  $class_names = array();
  if (variable_get('colors_user_role_enabled', FALSE)) {
    if ($entity->entity_type == 'user' && !empty($entity->roles)) {
      foreach ($entity->roles as $role_id => $role) {
        $class_names[] = 'colors-user-role-' . $role_id;
      }
    }
  }
  if (variable_get('colors_user_current_enabled', FALSE)) {
    global $user;
    if (!empty($entity->uid) && $user->uid == $entity->uid) {
      $class_names[] = 'colors-user-current-0';
    }
  }
  if (variable_get('colors_users_enabled', FALSE)) {
    if ($entity->entity_type == 'user' || $entity->entity_type == 'node') {
      $class_names[] = 'colors-users-' . $entity->uid;
    }
  }
  return $class_names;
}

function _user_current() {
  return array('Current user');
}

function _colors_users() {
  $users = entity_load('user');

  $result = array();
  foreach ($users as $user) {
    if (!empty($user->name)) {
      $result[$user->uid] =  $user->name;
    }
  }

  return $result;
}
