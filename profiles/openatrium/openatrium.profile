<?php

/**
 * @file
 * Install profile for Open Atrium.
 */

include_once 'install_from_db/install_from_db.profile';

/**
 * Implements hook_install_tasks()
 */
function openatrium_install_tasks(&$install_state) {
  $tasks = array();

  // Add our custom CSS file for the installation process
  drupal_add_css(drupal_get_path('profile', 'openatrium') . '/openatrium.css');

  // Add the Panopoly app selection to the installation process

// Don't install Apps at this time until we have Open Atrium apps
//  require_once(drupal_get_path('module', 'apps') . '/apps.profile.inc');
//  $tasks = $tasks + apps_profile_install_tasks($install_state, array('machine name' => 'openatrium', 'default apps' => array()));

// Default theme set in openatrium.install
// Disable the theme selection screen
  // Add the Panopoly theme selection to the installation process
  //require_once(drupal_get_path('module', 'panopoly_theme') . '/panopoly_theme.profile.inc');
  //$tasks = $tasks + panopoly_theme_profile_theme_selection_install_task($install_state);

  $tasks['openatrium_features_revert_all'] = array(
    'type' => 'normal',
  );

// Need to rebuild search index tables since oa_search changes panopoly_search
  $tasks['openatrium_rebuild_search'] = array(
    'type' => 'normal',
  );

  return $tasks;
}

function openatrium_features_revert_all() {
  global $install_state;
  drupal_set_time_limit(0);
  // only revert features when not doing a quick install
  if (empty($install_state['parameters']['quickstart']) || ($install_state['parameters']['quickstart'] != 'quick')) {
    features_revert(array(
      'oa_core' => array('field_base'),
      'oa_sections' => array('field_base', 'field_instance'),
      'oa_users' => array('field_instance'),
    ));
    features_revert();
  }
}

function openatrium_rebuild_search() {
  global $install_state;
  // only rebuild search when not doing a quick install
  if (empty($install_state['parameters']['quickstart']) || ($install_state['parameters']['quickstart'] != 'quick')) {
    require_once(drupal_get_path('module', 'oa_search') . '/oa_search.install');
    oa_search_rebuild_index();
  }
}

/**
 * Implements hook_install_tasks_alter()
 */
function openatrium_install_tasks_alter(&$tasks, $install_state) {
  require_once(drupal_get_path('module', 'oa_core') . '/oa_core.profile.inc');
  $tasks['install_load_profile']['function'] = 'oa_core_install_load_profile';
  // add option for importing from db
  install_from_db_install_tasks_alter($tasks, $install_state);
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function openatrium_form_install_configure_form_alter(&$form, $form_state) {
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function openatrium_form_apps_profile_apps_select_form_alter(&$form, $form_state) {
  // panopoly_form_apps_profile_apps_select_form_alter($form, $form_state);
  ############## INCLUDE FROM PANOPOLY #####################
    // For some things there are no need
  $form['apps_message']['#access'] = FALSE;
  $form['apps_fieldset']['apps']['#title'] = NULL;

  // Improve style of apps selection form
  if (isset($form['apps_fieldset'])) {
    $manifest = apps_manifest(apps_servers('panopoly'));
    foreach ($manifest['apps'] as $name => $app) {
      if ($name != '#theme') {
        $form['apps_fieldset']['apps']['#options'][$name] = '<strong>' . $app['name'] . '</strong><p><div class="admin-options"><div class="form-item">' . theme('image', array('path' => $app['logo']['path'], 'height' => '32', 'width' => '32')) . '</div>' . $app['description'] . '</div></p>';
      }
    }
  }

  // Remove the demo content selection option since this is handled through the Panopoly demo module.
  $form['default_content_fieldset']['#access'] = FALSE;
  // ########### END PANOPOLY ################
}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function openatrium_form_panopoly_theme_selection_form_alter(&$form, &$form_state, $form_id) {
  // change the default theme in the selection form
  unset($form['theme_wrapper']['theme']['#options']['radix']);
  unset($form['theme_wrapper']['theme']['#options']['radix_starter']);
  $form['theme_wrapper']['theme']['#default_value'] = 'oa_radix';
}

