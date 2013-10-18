<?php

/**
 * @file
 * An installation file for OpenAtrium Core
 */

/**
 * Task handler to load our install profile and enhance the dependency information
 */
function oa_core_install_load_profile(&$install_state) {
  $private_path = variable_get('file_private_path', FALSE);
  if (!$private_path) {
    $private_path = variable_get('file_public_path', conf_path() . '/files') . '/private';
    // can't set variables here yet, but this will be set in oa_config later in install
    // variable_set('file_private_path', $private_path);
  }
  if (!empty($private_path) && !is_dir($private_path)) {
    mkdir($private_path, 0775, TRUE);
  }

  // Include any dependencies that we might have missed...
  require_once(drupal_get_path('module', 'panopoly_core') . '/panopoly_core.profile.inc');
  panopoly_core_install_load_profile($install_state);
}
