<?php

/**
 * @file
 * Plugin to handle the 'contextual_tabs' pane
 */

$plugin = array(
  'title' => t('Contextual tab buttons'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('Displays the contextual tab buttons within a panel pane.'),
  'category' => t('Page elements'),
  'edit form' => 'contextual_tabs_settings_edit_form',
  'render last' => TRUE,
  'defaults' => array(
    'hide_captions' => FALSE,
    'direction' => '',
    'alignment' => '',
    'menu_caption' => t('Configure'),
    'icon_class' => 'icon-cog',
    'btn_class' => '',
    'prevent_alter' => FALSE,
  ),
);

/**
 * Output function for the 'contextual_tabs' content type.
 */
function contextual_tabs_contextual_tabs_content_type_render($subtype, $conf, $panel_messagesrgs) {
  $block = new stdClass();
  $conf['btn_class'] = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn-small btn-sm btn-default';
  $block->content = contextual_tabs_render($conf);
  return $block;
}

function contextual_tabs_contextual_tabs_content_type_admin_info($subtype, $conf) {
  $block = new stdClass;
  $block->title = t('Contextual tab buttons');
  $block->content = t('Displays the contextual tab buttons within a panel pane.');
  return $block;
}

/**
 * Edit form for the panel.
 */
function contextual_tabs_settings_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['hide_captions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide button captions'),
    '#default_value' => (isset($conf['hide_captions'])) ? $conf['hide_captions'] : FALSE,
  );
  $form['direction'] = array(
    '#type' => 'select',
    '#title' => t('Direction'),
    '#options' => array(
      '' => t('Drop down'),
      'up' => t('Drop up'),
    ),
    '#default_value' => (isset($conf['direction'])) ? $conf['direction'] : '',
    '#description' => t('Controls whether menu expands downwards or upwards.  Default is drop down.'),
  );
  $form['alignment'] = array(
    '#type' => 'select',
    '#title' => t('Alignment'),
    '#options' => array(
      '' => t('Left'),
      'right' => t('Right'),
    ),
    '#default_value' => (isset($conf['alignment'])) ? $conf['alignment'] : '',
    '#description' => t('Controls the text alignment of the items in the dropdown menu.'),
  );
  $form['menu_caption'] = array(
    '#type' => 'textfield',
    '#title' => t('Menu caption'),
    '#description' => t('Title/Caption of dropdown menu.  Default is "Configure"'),
    '#default_value' => !empty($conf['menu_caption']) ? $conf['menu_caption'] : t('Configure'),
  );
  $form['icon_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class'),
    '#description' => t('CSS class name for icon.  Default is icon-cog.'),
    '#default_value' => !empty($conf['icon_class']) ? $conf['icon_class'] : 'icon-cog',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default small buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : '',
  );
  $form['prevent_alter'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent buttons added from other modules'),
    '#default_value' => (isset($conf['prevent_alter'])) ? $conf['prevent_alter'] : FALSE,
  );

  return $form;
}

function contextual_tabs_settings_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
