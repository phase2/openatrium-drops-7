<?php

/**
 * @file
 * Administration page callbacks for the Media module.
 */

/**
 * Displays the media administration page.
 */
function media_admin_config_browser($form, &$form_state) {
  $theme_options = array();
  $theme_options[NULL] = t('Default administration theme');

  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      $theme_options[$key] = $theme->info['name'];
    }
  }

  $form['media_dialog_theme'] = array(
    '#type' => 'select',
    '#title' => t('Media browser theme'),
    '#options' => $theme_options,
    '#description' => t("This theme will be used for all media related dialogs. It can be different from your site's theme because many site themes do not work well in the small windows which media uses."),
    '#default_value' => variable_get('media_dialog_theme', ''),
  );

  $form['array_filter'] = array(
    '#type' => 'value',
    '#value' => TRUE,
  );

  $form['#submit'][] = 'media_admin_config_browser_pre_submit';

  return system_settings_form($form);
}

/**
 * Form submission handler for media_admin_config_browser().
 */
function media_admin_config_browser_pre_submit(&$form, &$form_state) {
  if (!$form_state['values']['media_dialog_theme']) {
    variable_del('media_dialog_theme');
    unset($form_state['values']['media_dialog_theme']);
  }
}
