<?php

/**
 * @file
 * Install profile for Open Atrium.
 */

include_once 'install_from_db/install_from_db.profile';

/**
 * Implements hook_appstore_stores_info().
 */
function openatrium_apps_servers_info() {
 $info =  drupal_parse_info_file(dirname(__file__) . '/openatrium.info');
 return array(
   'openatrium' => array(
     'title' => 'OpenAtrium',
     'description' => "Apps for the OpenAtrium distribution",
     // @CHANGE this to -stable for stable releases.
     'manifest' => 'http://appserver.openatrium.com/app/query/openatrium-development',
     'profile' => 'openatrium',
     'profile_version' => isset($info['version']) ? $info['version'] : '7.x-2.x-dev',
     'server_name' => !empty($_SERVER['SERVER_NAME']) ? $_SERVER['SERVER_NAME'] : '',
     'server_ip' => !empty($_SERVER['SERVER_ADDR']) ? $_SERVER['SERVER_ADDR'] : '',
   ),
 );
}

/**
 * Implements hook_form_FORM_ID_alter() for panopoly_theme_selection_form.
 */
function openatrium_form_panopoly_theme_selection_form_alter(&$form, &$form_state, $form_id) {
  // Change the default theme in the selection form.
  unset($form['theme_wrapper']['theme']['#options']['radix']);
  unset($form['theme_wrapper']['theme']['#options']['radix_starter']);
  $form['theme_wrapper']['theme']['#default_value'] = 'oa_radix';
}
