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
  'defaults' => array(
    'direction' => '',
    'alignment' => '',
    'icon_class' => 'icon-question-sign',
    'btn_class' => '',
  ),
);

/**
 * Renders the widget.
 */
function oa_tour_pane_render($subtype, $conf, $args, $context = NULL) {
  $block = NULL;
  $tours = bootstrap_tour_load_all();
  if (!empty($tours)) {
    drupal_add_css(drupal_get_path('module', 'oa_tour') . '/oa_tour.css');
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

    $vars['oa_toolbar_btn_class'] .= !empty($conf['btn_class']) ? ' ' . check_plain($conf['btn_class']) : '';
    $vars['alignment'] = !empty($conf['alignment']) ? 'align-right' : '';
    $vars['direction'] = !empty($conf['direction']) ? 'dropup' : '';
    $vars['icon_class'] = !empty($conf['icon_class']) ? check_plain($conf['icon_class']) : 'icon-question-sign';

    $vars['tours'] = theme('item_list', array('items' => $items));
    $block = new stdClass();
    $block->title = '';
    $block->content = theme('oa_tour_dropdown', $vars);
  }
  return $block;
}

/**
 * Provides the form for the widget.
 */
function oa_tour_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
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
  $form['icon_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class'),
    '#description' => t('CSS class name for icon.  Default is icon-cog.'),
    '#default_value' => !empty($conf['icon_class']) ? $conf['icon_class'] : 'icon-question-sign',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default small buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : '',
  );

  return $form;
}

function oa_tour_pane_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
