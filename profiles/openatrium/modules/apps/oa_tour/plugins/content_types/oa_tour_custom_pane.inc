<?php
/**
 * @file oa_tour_custom_pane.inc
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Open Atrium Tour Dropdown'),
  'description' => t('A dropdown menu that lets users manually start site tours.'),
  'category' => t('OA Admin'),
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
  drupal_add_css(drupal_get_path('module', 'oa_tour') . '/oa_tour.css');
  $block = new stdClass();
  $block->title = '';
  $tours = bootstrap_tour_load_all();
  if (!empty($tours)) {
    $vars['title'] = t('Site Tours');
    $vars['oa_toolbar_btn_class'] = variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';
    $items = array();
    foreach ($tours as $tour) {
      if (!bootstrap_tour_access($tour)) {
        continue;
      }
      if (!empty($tour->spaces)) {
        $tour_spaces = explode(',', $tour->spaces);
        $space_context = oa_core_get_space_context();
        if (!in_array($space_context, $tour_spaces)) {
          continue;
        }
      }
      drupal_alter('bootstrap_tour', $tour);
      if (($first_path = $tour->start_path)
        || (!empty($tour->steps[0]->path) && ($first_path = $tour->steps[0]->path))) {
        $url = drupal_parse_url($first_path);
        if (empty($url['query']['tour'])) {
          $url['query']['tour'] = $tour->name;
        }
        if (empty($_GET['tour']) || $_GET['tour'] != $tour->name) {
          $items[] = l($tour->title, $url['path'], array('query' => $url['query']));
        }
        else {
          $items[] = l($tour->title, $url['path'], array('query' => $url['query'], 'attributes' => array('class' => array('active-trail'))));
        }
      }
    }
    $vars['tours'] = theme('item_list', array('items' => $items));
    $block->content = theme('oa_tour_dropdown', $vars);
  }
  return $block;
}
