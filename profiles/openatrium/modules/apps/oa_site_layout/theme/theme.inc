<?php

/**
 * Default preprocess functions.
 */

/**
 * Implements hook_preprocess_PANE().
 */
function template_preprocess_pane_oa_tabs(&$vars) {
  $tabs = menu_local_tabs();
  if (!empty($vars['hide_primary'])) {
    unset($tabs['#primary']);
  }
  if (!empty($vars['hide_secondary'])) {
    unset($tabs['#secondary']);
  }
  $vars['tabs'] = $tabs;
}

/**
 * Implements hook_preprocess_PANE().
 */
function template_preprocess_pane_oa_action_links(&$variables) {
  $links = menu_local_actions();

  // Theme action links as buttons.
  if (!empty($links)) {
    foreach (element_children($links) as $key) {
      $links[$key]['#link']['localized_options']['attributes'] = array(
        'class' => array('btn', 'btn-primary', 'btn-sm'),
      );
    }
  }

  $variables['action_links'] = '';
  if (!empty($links)) {
    $variables['action_links'] = '<ul class="action-links">' . render($links) . '</ul>';
  }
}

/**
 * Implements hook_preprocess_PANE().
 */
function template_preprocess_pane_oa_help(&$vars) {
  $vars['help'] = menu_get_active_help();
}

/**
 * Implements hook_preprocess_PANE().
 */
function template_process_pane_oa_title(&$vars) {
  $vars['title'] = theme('head_title');
}

/**
 * Implements hook_process_PANE().
 */
function template_process_pane_oa_breadcrumb(&$vars) {
  $vars['breadcrumb'] = theme('breadcrumb', array('breadcrumb' => drupal_get_breadcrumb()));
}

/**
 * Implements hook_process_PANE().
 */
function template_process_pane_oa_messages(&$vars) {
  $vars['messages'] = theme('status_messages');
}
