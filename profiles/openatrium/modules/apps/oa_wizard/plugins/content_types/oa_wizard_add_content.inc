<?php

/**
 * @file
 * Defines the Add Member panels pane.
 */

$plugin = array(
  'title' => t('Add Content Wizard'),
  'description' => t('Add content via a wizard popup.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'edit form' => 'oa_wizard_add_content_edit_form',
  'render callback' => 'oa_wizard_add_content_render',
  'defaults' => array(
    'wizards' => '',
    'button_class' => '',
    'title_prefix' => '',
  ),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_wizard_add_content_render($subtype, $conf, $args, $context = NULL) {
  ctools_include('modal');
  ctools_modal_add_js();

  $wizards = isset($conf['wizards']) ? $conf['wizards'] : (isset($conf['content_types']) ? $conf['content_types'] : array());

  $links = array();
  $class = !empty($conf['button_class']) ? $conf['button_class'] : '';
  if (strpos($class, 'btn') !== FALSE) {
    if (strpos($class, 'btn-') === FALSE) {
      // handle default buttons in bootstrap 3
      $class .= ' btn-default';
    }
  }

  $custom_style = array(
    'oa-wizard' => array(
      'modalSize' => array(
        'type' => 'scale',
        'width' => 0.7,
        'height' => 0.5,
      ),
      'animation' => 'fadeIn',
    ),
  );

  ctools_include('ajax');

  drupal_add_js($custom_style, 'setting');

  $prefix = !empty($conf['title_prefix']) ? $conf['title_prefix'] : '';
  foreach ($wizards as $wizard_name) {
    $wizard = oa_wizard_machine_name_load($wizard_name);
    $content_type_info = !empty($wizard->field_wizard_type[LANGUAGE_NONE][0]['value']) ? node_type_load($wizard->field_wizard_type[LANGUAGE_NONE][0]['value']) : NULL;
    if (is_object($content_type_info) && node_access('create', $content_type_info->type)) {
      $links[] = '<li>' .
        ctools_modal_text_button($prefix . $content_type_info->name, 'api/oa_wizard/' . str_replace('_', '-', $wizard_name),
          $prefix . $content_type_info->name, $class . ' ctools-modal-oa-wizard')
        . '</li>';
    }
  }
  $output = '<ul>' . implode($links) . '</ul>';

  $block = new stdClass();
  $block->title = t('Create content');
  $block->content = $output;

  if (!empty($links)) {
    return $block;
  }
  return FALSE;
}

/**
 * Edit form for the panel.
 */
function oa_wizard_add_content_edit_form($form, &$form_state) {
  $conf = &$form_state['conf'];

  if ($options = oa_wizard_wizard_options()) {
    if (isset($conf['content_types']) && !isset($conf['wizards'])) {
      $conf['wizards'] = $conf['content_types'];
      unset($conf['content_types']);
    }
    $form['wizards'] = array(
      '#title' => t('Wizards'),
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => isset($conf['wizards']) ? $conf['wizards'] : array_values($options),
      '#description' => t('Select which content types you wish to display Add buttons for.'),
    );
    $form['button_class'] = array(
      '#title' => t('CSS class for links'),
      '#type' => 'textfield',
      '#default_value' => $conf['button_class'],
      '#description' => 'Enter CSS class for links, such as btn.'
    );
    $form['title_prefix'] = array(
      '#title' => t('Title Prefix'),
      '#type' => 'textfield',
      '#default_value' => $conf['title_prefix'],
      '#description' => 'Enter prefix text for link titles.'
    );
  }
  else {
    $form['not_configured']['#markup'] = t('Wizard it not properly configured.');
    if (user_access('administer site configuration')) {
      $form['not_configured']['#markup'] .= ' ' . l(t('Add a wizard?'), 'admin/structure/wizards/manage/wizard/add');
    }
  }

  return $form;
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_wizard_add_content_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

