<?php

/**
 * @file
 * Plugin to handle the page action_links.
 */

$plugin = array(
  'title' => t('Form action buttons'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A pane to show the action buttons from a form (like node edit).'),
  'category' => t('Page elements'),
  'render last' => TRUE,
  'edit form' => 'oa_site_layout_pane_oa_form_actions_form',
  'defaults' => array(
    'hide_captions' => FALSE,
    'show_dups' => FALSE,
    'omit_buttons' => 'edit-delete',
    'btn_class' => '',
  ),
);

/**
 * Output function for the 'pane_form_actions' content type.
 *
 * Outputs the action links of the current page.
 */
function oa_site_layout_pane_oa_form_actions_content_type_render($subtype, $conf, $panel_messagesrgs) {
  $buttons = array();
  $button_ids = array();
  $omit = !empty($conf['omit_buttons']) ? $conf['omit_buttons'] : 'edit-delete';
  $omit = explode(',', $omit);
  $btn_classes = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn-small btn-sm btn-default';
  $show_dups = !empty($conf['show_dups']) ? $conf['show_dups'] : FALSE;

  // Current form actions are saved in oa_site_layout after_build callback
  $actions = isset($GLOBALS['oa_site_layout_actions']) ? $GLOBALS['oa_site_layout_actions'] : array();
  if (!empty($actions)) {
    foreach ($actions as $key => $action) {
      if (!empty($action['#type']) && ($action['#type'] == 'submit') && !empty($action['#id']) &&
        !in_array($action['#id'], $omit)
      ) {
        if (!isset($action['#access']) || $action['#access']) {
          $btn = array(
            'title' => $action['#value'],
            'link' => $action['#id'],
            'class' => $btn_classes,
          );
          if ($key == 'submit') {
            $btn['class'] .= ' btn-primary';
          }
          $buttons[] = $btn;
          if (!$show_dups) {
            $button_ids[] = 'form .pane-node-form-buttons #' . $action['#id'];
          }
        }
      }
    }
  }

  if (empty($buttons)) {
    return FALSE;
  }

  $block = new stdClass();
  $vars = array(
    'buttons' => $buttons,
    'show_captions' => !empty($conf['hide_captions']) ? FALSE : TRUE,
    'btn_class' => $btn_classes,
  );

  $block->content = theme('pane_oa_form_actions', $vars);

  $options = array(
    'action_buttons' => implode(',', $button_ids),
  );
  drupal_add_js(drupal_get_path('module', 'oa_site_layout') . '/oa_site_layout.js');
  drupal_add_js(array('oa_site_layout' => $options), 'setting');

  return $block;
}

function oa_site_layout_pane_oa_form_actions_content_type_admin_info($subtype, $conf) {
  $block = new stdClass;
  $block->title = t('Form action buttons');
  $block->content = t('A pane to show the action buttons from a form (like node edit).');
  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_site_layout_pane_oa_form_actions_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['hide_captions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide button captions'),
    '#default_value' => (isset($conf['hide_captions'])) ? $conf['hide_captions'] : FALSE,
  );
  $form['show_dups'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show duplicate buttons in normal form'),
    '#default_value' => (isset($conf['show_dups'])) ? $conf['show_dups'] : FALSE,
  );
  $form['omit_buttons'] = array(
    '#type' => 'textfield',
    '#title' => t('Buttons to omit'),
    '#description' => t('List of button ids to omit, separated by commas.'),
    '#default_value' => !empty($conf['omit_buttons']) ? $conf['omit_buttons'] : 'edit-delete',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default small buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : '',
  );

  return $form;
}

function oa_site_layout_pane_oa_form_actions_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
