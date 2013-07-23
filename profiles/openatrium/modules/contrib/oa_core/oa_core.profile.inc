<?php

/**
 * @file
 * An installation file for OpenAtrium Core
 */

/**
 * Task handler to load our install profile and enhance the dependency information
 */
function oa_core_install_load_profile(&$install_state) {
  // ensure the private file path exists
  $path = 'sites/default/files/private';  // set in oa_config feature
  if (!empty($path) && !is_dir($path)) {
    mkdir($path, 0775, TRUE);
  }

  // Include any dependencies that we might have missed...
  require_once(drupal_get_path('module', 'panopoly_core') . '/panopoly_core.profile.inc');
  panopoly_core_install_load_profile($install_state);
}
