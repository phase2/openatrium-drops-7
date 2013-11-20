<?php

/**
 * @file
 * Provides forms and pages for administering oa_messages.
 */

/**
 * Implements hook_oa_user_settings_form_alter().
 */
function oa_messages_oa_user_settings_form_alter(&$form, $form_state, $user) {
  $form['oa_messages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $defaults = isset($user->data['oa_messages']) ? $user->data['oa_messages'] : array();

  $form['oa_messages']['message_notifications'] = oa_messages_build_message_notifications_table($user, $defaults);

  $form['oa_messages']['email_type'] = array(
    '#type' => 'radios',
    '#title' => t('Email type'),
    '#description' => t('Select how you would like your emails sent.'),
    '#options' => array(
      EMAIL_TYPE_PLAIN => 'Plain text',
      EMAIL_TYPE_HTML => 'HTML',
    ),
    '#default_value' => isset($defaults['email_type']) ? $defaults['email_type'] : EMAIL_TYPE_HTML,
  );

  $form['#attached']['js'][] = drupal_get_path('module', 'oa_messages') . '/js/oa-messages-settings.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'oa_messages') . '/css/oa-messages-settings.css';
}

/**
 * Build a table of notification types per space, much like
 * the permissions table.
 */
function oa_messages_build_message_notifications_table($user, $defaults = array()) {
  $spaces = node_load_multiple(oa_core_get_user_spaces($user->uid));
  $message_types = message_type_load();

  // Split them out in to tabs per module.
  $message_types_modules = array();
  foreach ($message_types as $type) {
    $module = $type->module ? $type->module : 'Custom';
    $message_types_modules[$module][] = $type;
  }

  $form = array(
    'tabs' => array(
      '#prefix' => '<ul id="messages-tabs" class="nav nav-tabs">',
      '#suffix' => '</ul>',
    ),
    'tables' => array(
      '#prefix' => '<div class="tab-content">',
      '#suffix' => '</div>',
    ),
  );

  foreach ($message_types_modules as $module => $message_types) {
    $module_info = system_get_info('module', $module);
    $module_name = $module_info ? $module_info['name'] : $module;
    $form['tabs'][$module] = array(
      '#prefix' => '<li><a href="#message-settings-' . $module . '" data-toggle="tab">',
      '#markup' => $module_name,
      '#suffix' => '</a></li>',
    );

    $table = array(
      '#prefix' => '<div id="message-settings-' . $module . '" class="tab-pane"><table class="table table-bordered table-striped table-hover checkbox-table">',
      '#suffix' => '</table></div>',
    );
    $table['header'] = array(
      '#prefix' => '<thead><tr>',
      'group' => array(
        '#prefix' => '<th>',
        '#markup' => t('Group'),
        '#suffix' => '</th>',
      ),
      '#suffix' => '</tr></thead>',
    );
    foreach ($message_types as $message_type) {
      $table['header'][$message_type->name] = array(
        '#prefix' => '<th class="center">',
        '#markup' => $message_type->description,
        '#suffix' => '</th>',
      );
    }

    foreach ($spaces as $space) {
      $table[$space->nid] = array(
        '#prefix' => '<tr>',
        'group' => array(
          '#prefix' => '<td class="space-label">',
          '#markup' => $space->title,
          '#suffix' => '</td>',
        ),
        '#suffix' => '</tr>',
      );

      $notifiers = oa_message_notifiers();
      foreach ($message_types as $message_type) {
        $table[$space->nid][$message_type->name] = array(
          '#prefix' => '<td class="center">',
          '#suffix' => '</td>',
        );
        foreach ($notifiers as $notifier) {
          $value = isset($defaults['message_notifications'][$space->nid][$message_type->name][$notifier['id']]) ?
            $defaults['message_notifications'][$space->nid][$message_type->name][$notifier['id']] :
            $notifier['default'];

          $table[$space->nid][$message_type->name][$notifier['id']] = array(
            '#type' => 'checkbox',
            '#default_value' => $value,
            '#field_prefix' => '<span class="label">' . $notifier['title'] . '</span>',
          );
        }
      }
    }

    $form['tables'][$module] = $table;
  }

  return $form;
}

/**
 * Implements hook_oa_user_settings_form_submit().
 */
function oa_messages_oa_user_settings_form_submit($form_state, $user) {
  // Flatten out message notification settings as they're keyed by the module
  // that provided the message type for organizational purposes only.
  $message_notifications = array();
  foreach ($form_state['values']['oa_messages']['message_notifications']['tables'] as $spaces) {
    foreach ($spaces as $space_id => $settings) {
      $settings = isset($message_notifications[$space_id]) ?
        array_merge($message_notifications[$space_id], $settings) :
        $settings;
      $message_notifications[$space_id] = $settings;
    }
  }


  return array('oa_messages' => array(
    'message_notifications' => $message_notifications,
    'email_type' => $form_state['values']['oa_messages']['email_type'],
  ));
}

/**
 * Add plugin-specific configuration to main Open Atrium settings form
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function oa_messages_form_oa_core_configure_form_alter(&$form, &$form_state, $form_id) {
  $form['oa_messages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Notifications'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['oa_messages']['oa_messages_notifications'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable notifications',
    '#description' => 'If off, no notifications will be sent.  If on, notifications are controlled by individual user settings.',
    '#default_value' => variable_get('oa_messages_notifications', TRUE),
  );
}

