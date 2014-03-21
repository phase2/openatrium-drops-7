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
  'defaults' => array(
    'allowed_options' => array(),
    'taxonomy_terms' => array(),
    'select_title' => '',
  ),
);

/**
 * Renders the widget.
 */
function oa_sidebar_search_pane_render($subtype, $conf, $args, $context) {

  $all_options = array(
      'all_spaces' => t('All spaces'),
      'this_space' => t('This space'),
      'users' => t('Users'),
    );
  if (isset($conf['allowed_options']) && count(array_filter($conf['allowed_options'])) > 0) {
    $keys = array_keys(array_filter($conf['allowed_options']));
  }
  else {
    $keys = array_keys($all_options);
  }
  $options = array();
  foreach ($keys as $key) {
    $options[$key] = $all_options[$key];
  }

  $spaces = array();
  if (isset($conf['taxonomy_terms']) && count(array_filter($conf['taxonomy_terms'])) > 0) {
    $terms = $conf['taxonomy_terms'];
    $terms = array_filter($terms);
    // get a list of spaces with those terms
    $query = db_select('taxonomy_index', 't');
    $result = $query
      ->fields('t', array('nid'))
      ->condition('t.tid', $terms, 'IN')
      ->execute()
      ->fetchCol(0);
    $titles = oa_core_get_titles($result);
    $spaces[0] = 'Select a space';
    foreach ($titles['titles'] as $key => $name) {
      $spaces[$titles['ids'][$key]] = $name;
    }
    $element = array(
      '#name' => 'space_select',
      '#title' => (!empty($conf['select_title'])) ? $conf['select_title'] : '',
      '#type' => 'select',
      '#options' => $spaces,
      '#default_value' => array(),
      '#multiple' => FALSE,
      '#required' => FALSE,
    );
    $element = form_process_select($element);
    $spaces = drupal_render($element);
  }
  $extra_classes = '';
  $solr_server = search_api_server_load('solr_server');
  if (isset($solr_server) && $solr_server->enabled) {
    $extra_classes .= ' solr-search';
  }

  $block = new stdClass();
  $block->title = t('Search');
  $block->content = array(
    '#theme' => 'oa_sidebar_search',
    '#options' => $options,
    '#spaces' => $spaces,
    '#extra_classes' => $extra_classes,
  );

  return $block;
}

/**
 * Provides the form for the widget.
 */
function oa_sidebar_search_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $options = array(
    'all_spaces' => t('All spaces'),
    'this_space' => t('This space'),
    'users' => t('Users'),
  );
  $form['allowed_options'] = array(
    '#title' => t('Allowed options'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => (!empty($conf['allowed_options'])) ? $conf['allowed_options'] : $options,
    '#description' => t('Select which search options you would like to enable.'),
  );

  $form['select_title'] = array(
    '#title' => t('Label for Space Selection'),
    '#type' => 'textfield',
    '#default_value' => (!empty($conf['select_title'])) ? $conf['select_title'] : '',
  );

  $vocabs = oa_core_get_entity_vocabs('node', OA_SPACE_TYPE);
  $options = oa_core_get_vocab_terms($vocabs);
  $form['taxonomy_terms'] = array(
    '#title' => t('Select from Spaces'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => (!empty($conf['taxonomy_terms'])) ? $conf['taxonomy_terms'] : $options,
    '#description' => t('Select which taxonomy terms are used to provide a selection of spaces to search within.'),
  );

  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_sidebar_search_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
