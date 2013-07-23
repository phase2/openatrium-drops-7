<?php

/**
 * @file
 * Color page callbacks for the Colors module.
 */

/**
 * Form constructor for the Colors admin form.
 */
function colors_admin_settings() {
  $form = colors_load_colorpicker();
  $default_colors = colors_get_colors('colors_default');

  $form['default_color'] = array(
    '#type' => 'item',
    '#title' => t('Default color'),
    '#tree' => TRUE,
    'input' => array(
      '#title' => t('default color'),
      '#type' => 'textfield',
      '#attributes' => array('class' => array('colorpicker-input')),
      '#default_value' => $default_colors['background'],
      '#size' => 7,
      '#maxlength' => 7,
      '#title_display' => 'invisible',
    ),
  );

  $form['process_order'] = array(
    '#tree' => TRUE,
    'info' => array(
      '#type' => 'item',
      '#title' => t('Process order'),
    ),
    'enabled' => array(
      '#type' => 'checkbox',
      '#title' => t('Change the CSS processing order.'),
      '#default_value' => variable_get('colors_process_order_enabled', FALSE),
      '#description' => t('Color order is cascading, CSS from modules at the bottom will override the top.'),
    ),
  );

  colors_include_api();
  $form['modules'] = array(
    '#tree' => TRUE,
  );
  $delta = 0;
  foreach (module_invoke_all('colors_info') as $module => $info) {
    if (!variable_get("colors_$module" . '_enabled', FALSE)) {
      continue;
    }
    $weight = variable_get('colors_weight_' . $module, $delta);
    $form['modules'][$module]['#name'] = $info['title'];
    $form['modules'][$module]['#weight'] = $weight;
    $form['modules'][$module]['weight'] = array(
      '#type' => 'textfield',
      '#title' => t('Weight for @title', array('@title' => $info['title'])),
      '#title_display' => 'invisible',
      '#size' => 4,
      '#default_value' => $weight,
      '#attributes' => array('class' => array('colors-weight')),
    );
    $delta++;
  }
  uasort($form['modules'], 'element_sort');

  $form['order_settings'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        'input[name="process_order[enabled]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save settings'),
      '#submit' => array('colors_admin_settings_submit'),
    ),
  );

  return $form;
}

/**
 * Form submission handler for colors_admin_settings().
 */
function colors_admin_settings_submit($form, &$form_state) {
  _colors_set_colors('colors_default', 'colors', $form_state['values']['default_color']['input']);
  variable_set('colors_process_order_enabled', $form_state['values']['process_order']['enabled']);

  foreach ($form_state['values']['modules'] as $module => $weight) {
    variable_set('colors_weight_' . $module, $weight['weight']);
  }

  colors_css_clear();
}

/**
 * Returns HTML for the settings form.
 *
 * @param array $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 */
function theme_colors_admin_settings($variables) {
  $form = $variables['form'];

  $rows = array();
  foreach (element_children($form['modules']) as $module) {
    $row = array();
    $row[] = $form['modules'][$module]['#name'];
    $row[] = drupal_render($form['modules'][$module]['weight']);

    $rows[] = array('data' => $row, 'class' => array('draggable'));
  }

  $form['order_settings']['table'] = array(
    '#theme' => 'table',
    '#header' => array(
      t('Module'),
      t('Weight'),
    ),
    '#rows' => $rows,
    '#attributes' => array('id' => 'colors-settings'),
  );
  drupal_add_tabledrag('colors-settings', 'order', 'sibling', 'colors-weight');

  return drupal_render_children($form);
}

/**
 * Generate an admin form for each Colors plugin.
 *
 * @param array $form
 *   An empty array for the form, this is always overridden.
 * @param array $form_state
 *   The form's state.
 * @param string $type
 *   The machine name of the plugin type.
 *
 * @return array
 *   The built form.
 */
function colors_generate_settings_form($form, $form_state, $type) {
  colors_include_api();
  $info = module_invoke_all('colors_info');
  if (empty($info[$type])) {
    return;
  }

  $info = $info[$type];

  $form = colors_load_colorpicker();
  $form['#attached']['css'][] = ctools_attach_css('colors.admin', 'colors');
  $form['#colors_type'] = $type;
  $form['#colors_info'] = $info;


  $form[$type . '_colors'] = array(
    '#type' => 'item',
    '#title' => t('!title colors', array('!title' => $info['title'])),
    '#description' => $info['long_description'],
  );

  $multiple = !empty($info['multiple_function']);
  $repeat = !empty($multiple) ? $info['multiple_function']() : array(NULL => NULL);

  foreach ($repeat as $id => $repeat_value) {
    $enabled_type = !empty($multiple) ? $type . '_' . $id : $type;
    $enabled_string = 'colors_' . $enabled_type . '_enabled';
    $enabled = variable_get($enabled_string, FALSE);

    $element = array(
      '#type' => 'fieldset',
      '#title' => !empty($multiple) ? $repeat_value->name : t('!title colors', array('!title' => $info['title'])),
      '#collapsible' => TRUE,
      '#collapsed' => !$enabled,
    );
    $element[$enabled_string] = array(
      '#type' => 'checkbox',
      '#title' => $info['short_description'],
      '#default_value' => $enabled,
    );
    foreach ($info['function']($id) as $key => $value) {
      $class = 'colors_' . $type . '_' . $key;
      $colors = colors_get_colors($class, 'colors');

      $element[$class] = array(
        '#title' => t($value),
        '#type' => 'textfield',
        '#attributes' => array('class' => array('colorpicker-input')),
        '#default_value' => $colors['background'],
        '#size' => 7,
        '#maxlength' => 7,
        '#states' => array(
          'visible' => array(
            ':input[name="' . $enabled_string . '"]' => array('checked' => TRUE),
          ),
        ),
      );
    }
    if (!empty($multiple)) {
      $form[$id] = $element;
    }
    else {
      $form['fieldset'] = $element;
    }
  }

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  $form['#submit'][] = 'colors_admin_type_settings_submit';

  // Add the additional submission handler, if necessary.
  if (!empty($info['submit'])) {
    $form['#submit'][] = 'colors_admin_' . $type . '_settings_submit';
  }

  // Add the additional validation handler, if necessary.
  if (!empty($info['validate'])) {
    $form['#validate'][] = 'colors_admin_' . $type . '_settings_validate';
  }

  return $form;
}

/**
 * Form submission handler for colors_generate_settings_form().
 */
function colors_admin_type_settings_submit($form, &$form_state) {
  if (empty($form['#colors_type']) || empty($form['#colors_info'])) {
    return;
  }

  $type = $form['#colors_type'];
  $info = $form['#colors_info'];

  $multiple = !empty($info['multiple_function']);
  $repeat = !empty($multiple) ? $info['multiple_function']() : array(NULL => NULL);

  $multiple_enabled = FALSE;
  foreach ($repeat as $id => $repeat_value) {
    $enabled_type = !empty($multiple) ? $type . '_' . $id : $type;
    $enabled_string = 'colors_' . $enabled_type . '_enabled';

    variable_set($enabled_string, (bool) $form_state['values'][$enabled_string]);
    if (!empty($form_state['values'][$enabled_string])) {
      $multiple_enabled = TRUE;
    }

    foreach ($info['function']($id) as $key => $value) {
      $class = 'colors_' . $type . '_' . $key;
      _colors_set_colors($class, $type, $form_state['values'][$class]);
    }
  }

  if ($multiple && $multiple_enabled) {
    variable_set('colors_' . $type . '_enabled', TRUE);
  }

  colors_css_clear();

  drupal_set_message(t('The configuration options have been saved.'));
}
