<?php
/**
 * @file
 * Provides a panels pane that displays the space structure menu.
 */

$plugin = array(
  'title' => t('Space structure'),
  'description' => t('Manage the structure of a space.'),
  'category' => array(t('OA Admin'), -9),
  'render callback' => 'oa_toolbar_oa_space_structure_render',
  'edit form' => 'oa_toolbar_oa_space_structure_form',
  'defaults' => array(
    'icon' => 'fa fa-bars',
    'icon_title' => '',
    'btn_class' => 'btn',
  ),
);

/**
 * Helper function to strip item-list div
 */
function _oa_toolbar_strip_list($text) {
  return preg_replace('/<div class="item-list">(.*)<\/div>/s', '$1', $text);
}

/**
 * Render callback.
 */
function oa_toolbar_oa_space_structure_render($subtype, $conf, $panel_args) {
  global $user;

  $vars['oa_toolbar_btn_class'] = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn';
  $vars['oa_toolbar_btn_class'] .= variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';
  $vars['icon'] = !empty($conf['icon']) ? $conf['icon'] : 'fa fa-bars';
  $vars['icon_title'] = !empty($conf['icon_title']) ? $conf['icon_title'] : '';

  // Spaces
  $space = NULL;
  $space_id = oa_core_get_space_context();
  if (isset($space_id) && ($space = node_load($space_id)) && node_access('view', $space)) {
    $space_type = $space->type;
    $menu_title = $space->title;
    $space_url = url('node/' . $space_id);

    $parent_list = oa_toolbar_get_parent_list($space_id, $space_type);
    $subspace_list = oa_toolbar_get_subspace_list($space_id, $space_type);

    $parent_list = theme('item_list', array(
      'items' => !empty($parent_list['links']) ? $parent_list['links'] : array(),
      'title' => '',
      'type' => 'ul',
      'attributes' => array('class' => array('dropdown-menu')),
    ));
    $parent_list = _oa_toolbar_strip_list($parent_list);

    $subspace_list = theme('item_list', array(
      'items' => !empty($subspace_list['links']) ? $subspace_list['links'] : array(),
      'title' => '',
      'type' => 'ul',
      'attributes' => array('class' => array('dropdown-menu')),
    ));
    $subspace_list = _oa_toolbar_strip_list($subspace_list);

    if ($space->type == OA_SPACE_TYPE) {
      $section_list = oa_toolbar_get_section_list($space_id);
      $section_list = theme('item_list', array(
        'items' => !empty($section_list['links']) ? $section_list['links'] : array(),
        'title' => '',
        'type' => 'ul',
        'attributes' => array('class' => array('dropdown-menu')),
      ));
      $section_list = _oa_toolbar_strip_list($section_list);
    }

    $vars['sitemap_url'] = url('node/' . $space_id . '/map');

    $list = array();

    if (module_exists('oa_sitemap')) {
      $list[] = array(
        'data' => l(t('Site map'), 'sitemap'),
        'class' => array(),
      );
    }

    if (!empty($parent_list)) {
      $list[] = array(
        'data' => l(t('Parents'), $space_url) . $parent_list,
        'class' => !empty($parent_list) ? array('dropdown-submenu') : array(),
      );
    }
    if (!empty($section_list)) {
      $list[] = array(
        'data' => l(t('Sections'), $space_url) . $section_list,
        'class' => !empty($section_list) ? array('dropdown-submenu') : array(),
      );
    }
    if (!empty($subspace_list)) {
      $title = ($space_type == OA_SPACE_TYPE) ? t('Subspaces') : t('Subgroups');
      $list[] = array(
        'data' => l($title, $space_url) . $subspace_list,
        'class' => !empty($subspace_list) ? array('dropdown-submenu', 'oa-border-bottom') : array(),
      );
    }

    $list[] = l(t('All Spaces...'), 'spaces');
    $list[] = l(t('All Groups...'), 'groups');

    if (user_access('create ' . OA_SPACE_TYPE . ' content', $user)) {
      $jump_links = oa_toolbar_get_jump_links('space');
      $list[] = array(
        'data' => l(t('Create top-level space'), 'node/add/' . str_replace('_', '-', OA_SPACE_TYPE)) . $jump_links,
        'class' => !empty($jump_links) ? array('dropdown-submenu') : array(),
      );
    }
    if (user_access('create ' . OA_GROUP_TYPE . ' content', $user)) {
      $jump_links = oa_toolbar_get_jump_links('group');
      $list[] = array(
        'data' => l(t('Create top-level group'), 'node/add/' . str_replace('_', '-', OA_GROUP_TYPE)) . $jump_links,
        'class' => !empty($jump_links) ? array('dropdown-submenu') : array(),
      );
    }
    if (!empty($space_id) && module_exists('oa_subspaces') && og_user_access('node', $space_id, 'create ' . OA_SPACE_TYPE . ' content', $user)) {
      $jump_links = oa_toolbar_get_jump_links('space', array(OA_PARENT_SPACE => $space_id));
      $list[] = array(
        'data' => l(t('Create new subspace'), 'node/add/' . str_replace('_', '-', OA_SPACE_TYPE),
            array(
              'query' => array(OA_PARENT_SPACE => $space_id),
            )) . $jump_links,
        'class' => !empty($jump_links) ? array('dropdown-submenu') : array(),
      );
    }
    if (og_user_access('node', $space_id, "create " . OA_SECTION_TYPE . " content", $user)) {
      $jump_links = oa_toolbar_get_jump_links('section');
      $list[] = array(
        'data' => l(t('Create new section'), 'node/add/' . str_replace('_', '-', OA_SECTION_TYPE)) . $jump_links,
        'class' => !empty($jump_links) ? array('dropdown-submenu') : array(),
      );
    }
    if (!empty($list)) {
      $vars['links'] = theme('item_list', array(
        'items' => $list,
        'title' => l($menu_title, 'node/' . $space_id),
        'type' => 'ul',
      ));
    }
  }

  if (!$space) {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = theme('oa_space_structure', $vars);
  return $block;
}

/**
 * Edit form callback.
 */
function oa_toolbar_oa_space_structure_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['icon_title'] = array(
    '#title' => t('Button title'),
    '#type' => 'textfield',
    '#default_value' => (!empty($conf['icon_title'])) ? $conf['icon_title'] : '',
  );
  $form['icon'] = array(
    '#title' => t('Icon class'),
    '#type' => 'textfield',
    '#default_value' => (!empty($conf['icon'])) ? $conf['icon'] : 'fa fa-bars',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : 'btn',
  );

  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function oa_toolbar_oa_space_structure_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
