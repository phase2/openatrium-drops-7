<?php

/**
 * Implements hook_install_tasks()
 */
function openatrium_install_tasks(&$install_state) {
  $tasks = array();

  // Add our custom CSS file for the installation process
  drupal_add_css(drupal_get_path('profile', 'openatrium') . '/openatrium.css');

  // Add the Panopoly app selection to the installation process
  require_once(drupal_get_path('module', 'apps') . '/apps.profile.inc');
  $tasks = $tasks + apps_profile_install_tasks($install_state, array('machine name' => 'openatrium', 'default apps' => array()));

  return $tasks;
}

/**
 * Implements hook_install_tasks_alter()
 */
function openatrium_install_tasks_alter(&$tasks, $install_state) {
  require_once(drupal_get_path('module', 'oa_core') . '/oa_core.profile.inc');
  $tasks['install_load_profile']['function'] = 'oa_core_install_load_profile';
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
