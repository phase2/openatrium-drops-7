<?php

/**
 * @file
 * Defines the Drawer panel toggle button widget.
 */

$plugin = array(
  'title' => t('Mobile menu button'),
  'description' => t('Display a button containing a mobile menu.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'edit form' => 'oa_responsive_regions_mobile_edit_form',
  'render callback' => 'oa_responsive_regions_mobile_render',
  'defaults' => array(
    'menuid' => '',
    'breakpoints' => 'sm',
    'icon' => 'fa fa-bars',
    'btn_class' => '',
  ),
);

/**
 * Render callback for the pane.
 */
function oa_responsive_regions_mobile_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  $vars['menuid'] = isset($conf['menuid']) ? check_plain($conf['menuid']) : '';
  $vars['breakpoints'] = isset($conf['breakpoints']) ? check_plain($conf['breakpoints']) : 'sm';
  $vars['icon'] = isset($conf['icon']) ? check_plain($conf['icon']) : 'fa fa-bars';
  $vars['btn_class'] = isset($conf['btn_class']) ? check_plain($conf['btn_class']) : '';

  $block = new stdClass();
  $block->title = '';
  $block->content = theme('oa_responsive_regions_mobile', $vars);

  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_responsive_regions_mobile_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['menuid'] = array(
    '#type' => 'textfield',
    '#title' => t('Unique menu name'),
    '#description' => t('Should match the css *-mobile-menu class added to the widgets to be placed within mobile menu.'),
    '#default_value' => isset($conf['menuid']) ? $conf['menuid'] : '',
  );
  $form['breakpoints'] = array(
    '#type' => 'textfield',
    '#title' => t('Breakpoint classes'),
    '#description' => t('Breakpoints to show button.'),
    '#default_value' => isset($conf['breakpoints']) ? $conf['breakpoints'] : 'sm',
  );
  $form['icon'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class name for button'),
    '#default_value' => isset($conf['icon']) ? $conf['icon'] : 'fa fa-bars',
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
function oa_responsive_regions_mobile_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

