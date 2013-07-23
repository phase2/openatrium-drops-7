<?php


/**
 * OG variables edit variable form.
 */
function og_menu_single_menu_edit_form($form, &$form_state, $entity_type, $entity_id) {
  module_load_include('admin.inc', 'menu');
  $form['#theme'] = 'menu_overview_form';
  if ($entity_type != 'node') {
    return array(
      '#empty_text' => t('Entity type currently not supported'),
    );
  }
  elseif (!($plid = og_menu_single_get_link_mlid_or_create($entity_type, $entity_id))) {
    return array(
      '#empty_text' => t('Unable to create menu for group. Please contact site administrator.'),
    );

  }
  global $menu_admin;
  $form['#attached']['css'] = array(drupal_get_path('module', 'menu') . '/menu.css');
  $tree = og_menu_single_children_items($plid);
  $node_links = array();
  menu_tree_collect_node_links($tree, $node_links);

  $form = array_merge($form, _menu_overview_tree_form($tree));
  $form['#menu'] = OG_MENU_SINGLE_MENU_NAME;

  $replace_path = 'group/' . $entity_type . '/' . $entity_id . '/admin/menu';
  if (element_children($form)) {
    foreach (element_children($form) as $mlid) {
      $form[$mlid]['#item']['depth'] = $form[$mlid]['#item']['depth'] - 1;
      if (!empty($form[$mlid]['operations'])) {
        foreach (array_keys($form[$mlid]['operations']) as $op_type) {
          if (!empty($form[$mlid]['operations'][$op_type]['#href'])) {
            $form[$mlid]['operations'][$op_type]['#href'] = str_replace('admin/structure/menu', $replace_path, $form[$mlid]['operations'][$op_type]['#href']);
          }
        }
      }
    }
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    );
    $form['#submit'][] = 'menu_overview_form_submit';
  }
  else {
    $form['#empty_text'] = t('There are no menu links yet. <a href="@link">Add link</a>.', array('@link' => url($replace_path . '/add')));
  }
  return $form;
}
