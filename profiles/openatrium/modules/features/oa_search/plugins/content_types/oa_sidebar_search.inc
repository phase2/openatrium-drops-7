<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Sidebar Search'),
  'description' => t('Provides a search bar for the sidebar, with the ability to preview results.'),
  'single' => TRUE,
  'category' => array(t('Search'), -9),
  'edit form' => 'oa_sidebar_search_settings_form',
  'render callback' => 'oa_sidebar_search_pane_render',
);


/**
 * Provides the form for the widget.
 */
function oa_sidebar_search_settings_form($form, &$form_state) {
  return $form;
}


/**
 * Renders the widget.
 */
function oa_sidebar_search_pane_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Search');
  $block->content = array(
    '#theme' => 'oa_sidebar_search',
    '#options' => array(
      'all_spaces' => t('All spaces'),
      'this_space' => t('This space'),
      'users' => t('Users'),
    ),
  );

  return $block;
}
