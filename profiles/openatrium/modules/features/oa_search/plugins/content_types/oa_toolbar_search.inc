<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Toolbar Search'),
  'description' => t('Provides a search bar for the toolbar that provides OA-specific options.'),
  'single' => TRUE,
  'category' => array(t('Search'), -9),
  'edit form' => 'oa_toolbar_search_settings_form',
  'render callback' => 'oa_toolbar_search_pane_render',
);


/**
 * Provides the form for the widget.
 */
function oa_toolbar_search_settings_form($form, &$form_state) {
  return $form;
}


/**
 * Renders the widget.
 */
function oa_toolbar_search_pane_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'oa_toolbar_search',
    '#options' => array(
      'all_spaces' => t('All spaces'),
      'this_space' => t('This space'),
      'users' => t('Users'),
    ),
  );

  return $block;
}
