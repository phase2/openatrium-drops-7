<?php
/**
 * @file oa_tour_custom_pane.inc
 */

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
  drupal_add_css(drupal_get_path('module', 'oa_tour') . '/oa_tour.css');
  $block = new stdClass();
  $block->title = '';
  $tours = bootstrap_tour_load_all();
  if (!empty($tours)) {
    $vars['title'] = t('Site Tours');
    $vars['oa_toolbar_btn_class'] = variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';
    $items = array();
    foreach ($tours as $tour) {
      if (!empty($tour->roles)) {
        global $user;
        $tour_roles = explode(',', $tour->roles);
        $user_roles = array_keys($user->roles);
        $compare = array_intersect($tour_roles, $user_roles);
        if (empty($compare)) {
          continue;
        }
      }
      if (!empty($tour->spaces)) {
        $tour_spaces = explode(',', $tour->spaces);
        $space_context = oa_core_get_space_context();
        if (!in_array($space_context, $tour_spaces)) {
          continue;
        }
      }
      if (!empty($tour->steps) && !is_array($tour->steps)) {
        $tour->steps = unserialize($tour->steps);
      }
      drupal_alter('bootstrap_tour', $tour);
      if (!empty($tour->steps[0]['path'])) {
        $first_path = $tour->steps[0]['path'];
        if (empty($_GET['tour']) || $_GET['tour'] != $tour->name) {
          $items[] = l($tour->title, $first_path, array('query' => array('tour' => $tour->name)));
        }
        else {
          $items[] = l($tour->title, $first_path, array('query' => array('tour' => $tour->name), 'attributes' => array('class' => array('active-trail'))));
        }
      }
    }
    $vars['tours'] = theme('item_list', array('items' => $items));
    $block->content = theme('oa_tour_dropdown', $vars);
  }
  return $block;
}
