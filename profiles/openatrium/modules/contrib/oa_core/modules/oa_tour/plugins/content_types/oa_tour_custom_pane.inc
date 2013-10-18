<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Open Atrium Tour Dropdown'),
  'description' => t('A dropdown menu that lets users manually start site tours.'),
  'category' => t('Open Atrium'),
  'edit form' => 'oa_tour_pane_edit_form',
  'render callback' => 'oa_tour_pane_render',
  'all contexts' => TRUE,
);

/**
 * Provides the form for the widget.
 */
function oa_tour_pane_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Renders the widget.
 */
function oa_tour_pane_render($subtype, $conf, $args, $context = NULL) {
  $block = new stdClass();
  $block->title = '';
  $tours = bootstrap_tour_load_all();
  if (!empty($tours)) {
    $vars['title'] = t('Site Tours');
    $vars['oa_toolbar_btn_class'] = variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';
    $items = array();
    foreach ($tours as $tour) {
      $tour->steps = unserialize($tour->steps);
      if (!empty($tour->steps[0]['path'])) {
        $first_path = $tour->steps[0]['path'];
        $items[] = l($tour->title, $first_path, array('query' => array('tour' => $tour->name)));
      }
    }
    $vars['tours'] = theme('item_list', array('items' => $items));
    $block->content = theme('oa_tour_dropdown', $vars);
  }
  return $block;
}
