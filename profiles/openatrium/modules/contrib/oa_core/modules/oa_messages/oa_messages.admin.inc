<?php

/**
 * @file
 * Provides forms and pages for administering oa_messages.
 */

/**
 * Implements hook_oa_user_settings_form_alter().
 */
function oa_messages_oa_user_settings_form_alter(&$form, &$form_state, $user) {
  drupal_set_title(t('Notification Settings'));
  $defaults = isset($user->data['oa_messages']) ? $user->data['oa_messages'] : array();

  $form['submit_top'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#attributes' => array(
      'class' => array('btn-primary'),
    ),
    '#weight' => -99,
  );

  $form['oa_messages'] = array(
    '#type' => 'fieldgroup',
    '#tree' => TRUE,
  );

  $form['oa_messages']['delivery'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('delivery-prefs'),
    ),
  );

  $form['oa_messages']['delivery']['email_type'] = array(
    '#type' => 'radios',
    '#title' => t('Select your email preference:'),
    '#prefix' => '<h4>' . t('Delivery Preferences') . '</h4>',
    '#options' => array(
      EMAIL_TYPE_PLAIN => 'Plain text',
      EMAIL_TYPE_HTML => 'HTML',
    ),
    '#default_value' => isset($defaults['email_type']) ? $defaults['email_type'] : EMAIL_TYPE_HTML,
  );

  $form['oa_messages']['message_notifications'] = oa_messages_build_message_notifications_table($form_state, $user, $defaults);

  $form['oa_messages']['message_notifications']['pager'] = array(
    '#theme' => 'pager',
  );

  $form['oa_messages']['subscribed_content'] = array(
    '#prefix' => '<div class="subscribed-content">',
    '#markup' => l(t('Subscribed Content') . html_entity_decode(' &#x25b6;'), 'user/' . $user->uid . '/subscribed', array('html' => TRUE)),
    '#suffix' => '</div>',
  );

  $form['#attached']['js'][] = drupal_get_path('module', 'oa_messages') . '/js/oa-messages-settings.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'oa_messages') . '/css/oa-messages-settings.css';
}

/**
 * Implements hook_oa_user_settings_form_submit().
 */
function oa_messages_oa_user_settings_form_submit($form_state, $user) {
  // Set email type.
  $return['oa_messages']['email_type'] = $form_state['values']['oa_messages']['delivery']['email_type'];

  if (isset($form_state['values']['oa_messages']['message_notifications'])) {
    $values = $form_state['values']['oa_messages']['message_notifications'];

    foreach ($values['all_spaces'] as $nid => $vals) {
      $return['oa_messages']['message_notifications'][$nid]['methods'] = (!empty($vals['methods'])) ? $vals['methods'] : array();
      $return['oa_messages']['message_notifications'][$nid]['messages'] = (!empty($vals['methods'])) ? $vals['message_container']['messages'] : array();
    }
  }

  return $return;
}

/**
 * Helper function to build the message notifications table.
 */
function oa_messages_build_message_notifications_table(&$form_state, $user, $defaults = array()) {
  $values = isset($form_state['values']) ? $form_state['values']['oa_messages']['message_notifications'] : NULL;
  if (isset($form_state['triggering_element']) && $form_state['triggering_element']['#value'] === 'Search') {
    $options = array(
      'space' => trim($form_state['values']['oa_messages']['message_notifications']['filter']['space_filter']),
    );
  }
  else {
    $options = array();
  }

  $page = NULL;
  if (isset($form_state['complete form'])) {
    if ($pos = strrpos($form_state['complete form']['#action'], '=')) {
      $page = substr($form_state['complete form']['#action'], $pos + 1);
    }
  }

  $spaces = oa_messages_get_entity_groups($user->uid, 'user', $options, $page);

  $form = array();

  if (!empty($spaces)) {
    $message_types = message_type_load();
    $notifiers = oa_message_notifiers();

    // Get notification method options.
    foreach ($notifiers as $notifier) {
      $method_options[$notifier['id']] = $notifier['title'];
      if ($notifier['default']) {
        $default_notifiers[] = $notifier['id'];
      }
    }
    $method_options['none'] = t('None');

    // Get messages options.
    foreach ($message_types as $type) {
      $message_options[$type->name] = $type->description;
      $message_defaults[$type->name] = $type->name;
    }

    $form['filter'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('filters'),
      ),
    );

    $form['filter']['space_filter'] = array(
      '#type' => 'textfield',
      '#attributes' => array(
        'placeholder' => t('Space'),
      ),
      '#prefix' => '<br /><h4>' . t('Space Preferences') . '</h4><label>' . t('Filter Spaces:') . '</label>',
    );

    $form['filter']['actions']['submit'] = array(
      '#type' => 'button',
      '#value' => t('Search'),
      '#prefix' => '<div class="filter-actions">',
      '#ajax' => array(
        'wrapper' => 'edit-oa-messages-all-spaces',
        'callback' => 'oa_messages_ajax_load_notification_methods',
      ),
    );

    $form['filter']['actions']['reset'] = array(
      '#type' => 'button',
      '#value' => t('Reset'),
      '#suffix' => '</div><br />',
      '#ajax' => array(
        'wrapper' => 'edit-oa-messages-all-spaces',
        'callback' => 'oa_messages_ajax_load_notification_methods',
      ),
    );

    $form['all_notifications'] = array(
      '#type' => 'select',
      '#prefix' => '<label>' . t('Set Spaces Preferences:') . '</label>',
      '#options' => $method_options,
      '#required' => FALSE,
      '#empty_option' => t('Choose a notification method'),
    );

    $form['all_notifications_submit'] = array(
      '#type' => 'button',
      '#value' => t('Apply'),
      '#ajax' => array(
        'wrapper' => 'edit-oa-messages-all-spaces',
        'callback' => 'oa_messages_ajax_load_notification_methods',
      ),
    );

    $form['header'] = array(
      '#type' => 'container',
      '#prefix' => '<div class="row-fluid header">',
      '#suffix' => '</div>',
    );

    $form['header']['select_all'] = array(
      '#type' => 'checkbox',
      '#title' => t('Spaces'),
      '#prefix' => '<div class="column1 span3">',
      '#suffix' => '</div>',
      '#attributes' => array(
        'class' => array('select-all'),
      ),
    );

    $form['header']['methods'] = array(
      '#markup' => t('Notification Method'),
      '#prefix' => '<div class="column2 span3">',
      '#suffix' => '</div>',
    );

    $form['header']['message'] = array(
      '#markup' => t('Messages'),
      '#prefix' => '<div class="column3 span6">',
      '#suffix' => '</div>',
    );

    $form['all_spaces'] = array(
      '#type' => 'container',
      '#id' => 'edit-oa-messages-all-spaces',
    );

    // Remove "None" option for method notifications.
    array_pop($method_options);

    // Build space options.
    foreach ($spaces as $key => $space) {

      // Set defaults.
      $method_values = NULL;
      $messages_values = NULL;
      if (isset($values) && $values['all_spaces'][$space->nid]['checkbox']) {
        if ($values['all_notifications'] === 'none') {
          $method_values = '';
          $messages_values = '';
        }
        else {
          $method_values = $values['all_notifications'];
          $messages_values = $message_defaults;
        }
      }
      elseif (isset($defaults['message_notifications'][$space->nid]['methods'])) {
        $default_methods = $defaults['message_notifications'][$space->nid]['methods'];
        if (isset($defaults['message_notifications'][$space->nid]['messages'])) {
          $default_messages = $defaults['message_notifications'][$space->nid]['messages'];
        }
      }
      else {
        $default_methods = $default_notifiers;
        $default_messages = $message_defaults;
      }

      $form['all_spaces'][$space->nid] = array(
        '#type' => 'fieldgroup',
        '#title' => $space->title,
        '#title_display' => 'invisible',
        '#collapsible' => FALSE,
        '#prefix' => '<div class="row-fluid">',
        '#suffix' => '</div>',
      );

      $form['all_spaces'][$space->nid]['checkbox'] = array(
        '#type' => 'checkbox',
        '#title' => $space->title,
        '#prefix' => '<div class="column1 span3">',
        '#suffix' => '</div>',
        '#attributes' => array(
          'class' => array('apply-to'),
        ),
      );

      $form['all_spaces'][$space->nid]['methods'] = array(
        '#type' => 'select',
        '#title' => t('Notification Method'),
        '#title_display' => 'invisible',
        '#multiple' => TRUE,
        '#options' => $method_options,
        '#default_value' => $default_methods,
        '#prefix' => '<div class="column2 span3">',
        '#suffix' => '</div>',
        '#id' => $space->nid,
      );

      $form['all_spaces'][$space->nid]['message_container'] = array(
        '#type' => 'fieldset',
        '#title' => t('Messages'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#prefix' => '<div class="column3 span6">',
        '#suffix' => '</div>',
        '#id' => 'message-container-' . $space->nid,
      );

      $form['all_spaces'][$space->nid]['message_container']['messages'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Messages'),
        '#title_display' => 'invisible',
        '#multiple' => TRUE,
        '#options' => $message_options,
        '#default_value' => $default_messages,
      );

      // Set values if given.
      if (isset($method_values) && isset($messages_values)) {
        $form['all_spaces'][$space->nid]['methods']['#value'] = $method_values;
        $form_state['input']['oa_messages']['message_notifications']['all_spaces'][$space->nid]['message_container']['messages'] = $messages_values;
      }
    }
  }

  return $form;
}

/**
 * AJAX callback to return search space values.
 */
function oa_messages_ajax_load_notification_methods($form, &$form_state) {
  return $form['oa_messages']['message_notifications']['all_spaces'];
}

/**
 * Add plugin-specific configuration to main Open Atrium settings form.
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

/**
 * Helper function to get user's spaces.
 */
function oa_messages_get_entity_groups($entity, $entity_type = 'user', $options = array(), $page = NULL) {
  $matches = array();

  if (isset($page) && !isset($_GET['page'])) {
    $_GET['page'] = $page;
  }

  $query = db_select('og_membership', 'ogm')->extend('PagerDefault');
  $query->join('node', 'n', 'n.nid = ogm.gid');
  $query->condition('ogm.entity_type', $entity_type)
  ->condition('ogm.etid', $entity)
  ->condition('n.type', 'oa_space')
  ->fields('n', array('nid', 'title'))
  ->orderBy('n.title', 'ASC')
  ->limit(20);

  if (!empty($options['space'])) {
    $query->condition('n.title', '%' . db_like($options['space']) . '%', 'LIKE');
  }

  $result = $query->execute();
  $matches = $result->fetchAll();

  return $matches;
}
