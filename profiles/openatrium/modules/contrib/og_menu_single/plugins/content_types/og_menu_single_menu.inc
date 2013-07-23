<?php
/**
 * @file
 * Custom menu pane for OG menu single.
 */


$plugin = array(
  'title' => t('Group Menu'),
  'description' => t('Display the menu for the group.'),
  'single' => TRUE,
  'category' => array(t('Menus'), -9),
  'edit form' => 'og_menu_single_pane_edit_form',
  'render callback' => 'og_menu_single_pane_render',
  'defaults' => array(
    'parent' => 0,
  ),
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function og_menu_single_pane_render($subtype, $conf, $args, $context = NULL) {
  $plid = og_menu_single_get_active_plid();
  if (!empty($conf['og_menu_single_parent'])) {
    $plid = $conf['og_menu_single_parent'];
    if ($plid === 'auto') {
      $result = module_invoke_all('og_menu_single_menu_parent', $conf);
      $plid = reset($result);
    }
  }

  if ($plid) {
    $tree = og_menu_single_children_items($plid, !empty($conf['og_menu_single_depth']) ? $conf['og_menu_single_depth'] : MENU_MAX_DEPTH);
    if ($tree && ($output = menu_tree_output($tree))) {
      $block = new stdClass();
      $block->title = '';
      $block->content =  $output;
      // Don't want to do menu_link_load if overriding title.
      if (empty($conf['override_title'])) {
        $item = og_menu_single_menu_link_load($plid);
        $block->title = l($item['link_title'], $item['link_path'], $item['options']);
      }
      return $block;
    }
  }
  return FALSE;
}

/**
 * Custom edit form to allow users to enable/disable selectable content types
 */
function og_menu_single_pane_edit_form($form, &$form_state) {
  if ($plid = og_menu_single_get_active_plid()) {
    $conf = $form_state['conf'];
    $form['settings']['og_menu_single_depth'] = array(
      '#title' => t('Depth'),
      '#type' => 'select',
      '#options' => array(0 => t('All'), 1 => 1, 2 => 2, 3 => 3, 4 => 4, 5 => 5, 6 => 6, 7 => 7),
      '#default_value' => isset($conf['og_menu_single_depth']) ? $conf['og_menu_single_depth'] : 0,
      '#description' => t('Select how deep/how many levels of the menu to display.'),
    );
    if ($tree = og_menu_single_children_items($plid)) {
      $options = array();
      $options[OG_MENU_SINGLE_MENU_NAME . ':' . 0] = '<' . t('Full Menu') . '>';
      if (module_implements('og_menu_single_menu_parent')) {
        $options[OG_MENU_SINGLE_MENU_NAME . ':auto'] = '<' . t('Automatically Detect') . '>';
      }
      _menu_parents_recurse($tree, OG_MENU_SINGLE_MENU_NAME, '--', $options, 0, 8);
      $form['settings']['og_menu_single_parent'] = array(
        '#title' => t('Parent'),
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => OG_MENU_SINGLE_MENU_NAME . ':' . (isset($conf['og_menu_single_parent']) ?  $conf['og_menu_single_parent'] : 0),
        '#description' => t('Select.which parent item to display items below.'),
      );
    }
  }
  else {
    drupal_set_message(t('Unable to fetch an active group.'), 'error');
  }

  return $form;
}


/**
 * Saves changes to the widget.
 */
function og_menu_single_pane_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      if ($key == 'og_menu_single_parent') {
        $form_state['values'][$key] = substr($form_state['values'][$key], strpos($form_state['values'][$key], ':') + 1);
      }
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

