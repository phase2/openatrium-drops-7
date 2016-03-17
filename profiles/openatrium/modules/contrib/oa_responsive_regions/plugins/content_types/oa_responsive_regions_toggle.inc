<?php

/**
 * @file
 * Defines the Drawer panel toggle button widget.
 */

$plugin = array(
  'title' => t('Tray panel toggle'),
  'description' => t('Display a button to toggle a sidebar tray panel.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'edit form' => 'oa_responsive_regions_toggle_edit_form',
  'render callback' => 'oa_responsive_regions_toggle_render',
  'defaults' => array(
    'position' => 'left',
    'icon' => 'icon-chevron-right',
    'icon2' => 'icon-chevron-left',
    'btn_class' => '',
  ),
);

/**
 * Implements HOOK_preprocess_THEME().
 * @param $vars
 */
function template_preprocess_oa_responsive_regions_toggle(&$vars) {
  $class = ($vars['mobile_only']) ? 'oa-responsive-mobile' : 'oa-responsive-desktop';
  $vars['classes_array'][] = drupal_html_class($class);
  $class = 'oa-responsive-regions-toggle-' . $vars['position'];
  $vars['classes_array'][] = drupal_html_class($class);
}

/**
 * Render callback for the pane.
 */
function oa_responsive_regions_toggle_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  if ($user->uid) {
    // Ensure the cookie library is loaded for non-anonymous users
    drupal_add_library('system', 'jquery.cookie');
  }

  $regions = oa_responsive_regions_get_responsive_regions();
  $position = isset($conf['position']) ? check_plain($conf['position']) : 'left';
  if (!isset($regions[$position]) || !empty($regions[$position]['settings']['expand_always'])) {
    return FALSE;
  }

  $vars['mobile_only'] = $regions[$position]['settings']['mobile_only'];
  $vars['position'] = $position;
  $vars['icon'] = isset($conf['icon']) ? check_plain($conf['icon']) : 'icon-chevron-right';
  $vars['icon2'] = isset($conf['icon2']) ? check_plain($conf['icon2']) : 'icon-chevron-left';
  $vars['btn_class'] = isset($conf['btn_class']) ? check_plain($conf['btn_class']) : '';

  $block = new stdClass();
  $block->title = '';
  $block->content = theme('oa_responsive_regions_toggle', $vars);

  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_responsive_regions_toggle_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $positions = _oa_responsive_regions_get_positions();
  unset($positions['center']);

  $form['position'] = array(
    '#type' => 'select',
    '#title' => t('Position to Toggle'),
    '#options' => $positions,
    '#default_value' => isset($conf['position']) ? $conf['position'] : 'left',
  );
  $form['icon'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class name when tray is hidden'),
    '#default_value' => isset($conf['icon']) ? $conf['icon'] : 'icon-chevron-right',
  );
  $form['icon2'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class name when tray is visible'),
    '#default_value' => isset($conf['icon2']) ? $conf['icon2'] : 'icon-chevron-left',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#description' => t('Optional additional css classes, such as btn-default.'),
    '#default_value' => isset($conf['btn_class']) ? $conf['btn_class'] : '',
  );

  return $form;
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_responsive_regions_toggle_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

