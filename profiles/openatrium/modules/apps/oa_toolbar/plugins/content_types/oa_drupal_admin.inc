<?php
/**
 * @file
 * Provides a panels pane that displays the Drupal Admin menu.
 */

$plugin = array(
  'title' => t('Drupal admin menu button'),
  'description' => t('Drupal admin menu button.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_toolbar_oa_drupal_admin_form',
  'render callback' => 'oa_toolbar_oa_drupal_admin_render',
  'defaults' => array(
    'caption' => t('Admin'),
    'icon' => '',
    'btn_class' => 'btn',
    'show_caret' => FALSE,
  ),);

/**
 * Render callback.
 */
function oa_toolbar_oa_drupal_admin_render($subtype, $conf, $panel_args) {
  $block = FALSE;

  if (module_exists('navbar')) {
    $tree = navbar_get_menu_tree();
    if (!empty($tree)) {
      drupal_add_js(drupal_get_path('module', 'oa_toolbar') . '/js/toolbar-menu-toggle.js');

      $block = new stdClass();

      $vars = array();
      $vars['caption'] = isset($conf['caption']) ? check_plain($conf['caption']) : t('Admin');
      $vars['icon'] = isset($conf['icon']) ? check_plain($conf['icon']) : '';
      $vars['show_caret'] = isset($conf['show_caret']) ? $conf['show_caret'] : FALSE;
      $vars['oa_toolbar_btn_class'] = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn';
      $vars['oa_toolbar_btn_class'] .= variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';

      $block->content = theme('oa_toolbar_menu_button', $vars);
      $block->module = 'oa_toolbar';
    }
  }
  return $block;
}

/**
 * Edit form callback.
 */
function oa_toolbar_oa_drupal_admin_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['caption'] = array(
    '#title' => t('Button caption'),
    '#type' => 'textfield',
    '#default_value' => (isset($conf['caption'])) ? $conf['caption'] : t('Admin'),
  );
  $form['icon'] = array(
    '#title' => t('Icon class'),
    '#type' => 'textfield',
    '#default_value' => (!empty($conf['icon'])) ? $conf['icon'] : '',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : 'btn',
  );
  $form['show_caret'] = array(
    '#title' => t('Show caret'),
    '#type' => 'checkbox',
    '#default_value' => (isset($conf['show_caret'])) ? $conf['show_caret'] : FALSE,
  );

  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function oa_toolbar_oa_drupal_admin_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
