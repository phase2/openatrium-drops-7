<?php
/**
 * @file
 * Provides a panels pane that displays the recent spaces menu.
 */

$plugin = array(
  'title' => t('Recent Spaces'),
  'description' => t('Menu of recent spaces.'),
  'category' => array(t('OA Admin'), -9),
  'render callback' => 'oa_toolbar_oa_recent_render',
  'edit form' => 'oa_toolbar_oa_recent_form',
  'defaults' => array(
    'icon' => 'fa fa-bars',
    'icon_title' => '',
    'show_favorites' => TRUE,
  ),
);

/**
 * Render callback.
 */
function oa_toolbar_oa_recent_render($subtype, $conf, $panel_args) {
  global $user;

  $vars['oa_toolbar_btn_class'] = variable_get('oa_toolbar_style', 0) ? '' : 'btn-inverse';
  $vars['home_url'] = url('<front>', array('absolute' => TRUE));
  $vars['icon'] = !empty($conf['icon']) ? $conf['icon'] : 'fa fa-bars';
  $vars['icon_title'] = !empty($conf['icon_title']) ? $conf['icon_title'] : '';

  // Spaces
  $space = NULL;
  $space_id = oa_core_get_space_context();

  // grab list of user's spaces and sections
  $parent_id = NULL;
  $space_type = OA_SPACE_TYPE;

  $space_type_names = ($space_type == OA_SPACE_TYPE) ? t('Spaces') : t('Groups');
  $all_spaces = ($space_type == OA_SPACE_TYPE) ? 'spaces' : 'groups';

  $show_all = TRUE;
  $spaces = NULL;
  $sort_field = 'title';
  if ($user->uid) {
    if (variable_get('oa_toolbar_recent', 1) == 1) {
      // First get recent history.  This cannot be cached, so limit to 10
      $limit = 10;
      $spaces = array_map(
        function($node) { return $node->nid; },
        oa_core_get_groups_by_user_access($user, FALSE, NULL, NULL, NULL, $space_type, 'history', $limit));
      if (count($spaces) < $limit) {
        // if not enough recent spaces, then add the rest based on reverse creation timestamp
        $more_spaces = array_map(
          function($node) { return $node->nid; },
          oa_core_get_groups_by_user_access($user, FALSE, NULL, NULL, NULL, $space_type, '-created', $limit));
        $more_spaces = array_diff($more_spaces, $spaces);
        $spaces = array_merge($spaces, $more_spaces);
      }
      $menu_title = ($space_type == OA_SPACE_TYPE) ? t('Recent Spaces') : t('Recent Groups');
      $sort_field = '';
    }
    else {
      // Otherwise get all subscribed spaces.  This is cached.
      // This only returns spaces with Direct membership.  No inherited subspaces
      $spaces = array_map(
        function($node) { return $node->nid; },
        oa_core_get_groups_by_user_access($user, FALSE, NULL, NULL, NULL, $space_type, NULL, 50));
      $menu_title = ($space_type == OA_SPACE_TYPE) ? t('Member Spaces') : t('Groups');
    }
  }
  if (empty($spaces)) {
    // og_get_entity_groups doesn't return anything for anonymous users
    // so return list of all public spaces
    $only_top = (variable_get('oa_toolbar_toplevel', 1) == 1);
    $spaces = oa_core_get_public_spaces(array(OA_SPACE_TYPE => OA_SPACE_TYPE), NODE_PUBLISHED, FALSE, TRUE, $only_top);
    $menu_title = t('Public Spaces');
  }
  if (empty($spaces)) {
    $list = array();
  }
  else {
    $items = oa_core_get_titles($spaces, $space_type, $sort_field);
    $list = oa_core_truncate_list($items['links'], 20,
      l(t('All ' . $space_type_names . '...'), $all_spaces,
        array('attributes' => array('class' => array('more-link')))),
      $show_all);
  }

  if (module_exists('oa_sitemap')) {
    $vars['sitemap_url'] = url('sitemap');
    $list[] = l(t('Site map'), 'sitemap', array('attributes' => array('class' => array('more-link'))));
  }
  if (!empty($list)) {
    $vars['home_spaces'] = theme('item_list', array(
      'items' => $list,
      'title' => $menu_title,
      'type' => 'ul',
    ));
  }

  $show_fav = (isset($conf['show_favorites'])) ? $conf['show_favorites'] : TRUE;
  if ($show_fav && module_exists('oa_favorites') && ($user->uid)) {
    $items = oa_favorites_get_spaces($user, $space_id);
    $classes = '';
    // favorites flag link
    if ($space_id) {
      $items['links'][] = flag_create_link(FAVORITE_SPACE, $space_id);
    }
    if (oa_favorites_is_favorite_space($user->uid, $space_id)) {
      $classes .= 'oa-is-favorite';
    }
    if (!empty($items['links'])) {
      // include css
      drupal_add_css(drupal_get_path('module', 'oa_favorites') . '/oa_favorites.css');
      $vars['spaces_favorite'] = theme('item_list', array(
        'items' => $items['links'],
        'title' => t('Favorite Spaces'),
        'type' => 'ul',
      ));
      $vars['title'] = t('Favorites');
      $vars['favorite_class'] = $classes;
      $vars['favorite_class'] .= variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';
    }
  }

  $block = new stdClass();
  $block->content = theme('oa_recent', $vars);
  return $block;
}

/**
 * Edit form callback.
 */
function oa_toolbar_oa_recent_form($form, &$form_state) {
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
  $form['show_favorites'] = array(
    '#title' => t('Show Favorites'),
    '#type' => 'checkbox',
    '#default_value' => (isset($conf['show_favorites'])) ? $conf['show_favorites'] : TRUE,
  );

  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function oa_toolbar_oa_recent_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
