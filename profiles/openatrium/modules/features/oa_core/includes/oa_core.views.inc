<?php

/**
 * @file
 * Provides views plugins and integration for oa_core.
 */

/**
 * Implements hook_views_plugins().
 */
function oa_core_views_plugins() {
  return array(
    'exposed_form' => array(
      'oa_form' => array(
        'title' => t('Open Atrium'),
        'help' => t('Open Atrium exposed filter form adds some options that integrate with Bootstrap.'),
        'handler' => 'oa_views_plugin_exposed_form',
        'uses options' => TRUE,
      ),
    ),
  );
}


/**
 * Implements hook_preprocess_views_exposed_form().
 */
function oa_core_preprocess_views_exposed_form(&$vars) {
  // Add options from a filters to the variables for use in our template.
  $vars['collapsed_filter'] = empty($vars['form']['#collapsed_filter']) ? FALSE : TRUE;
}