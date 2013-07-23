<?php

/**
 * @file
 * Provides a panels pane that shows user information.
 */

$plugin = array(
  'title' => t('OpenAtrium Favorites'),
  'description' => t('A single button that contains a dropdown menu exposing a user\'s favorite spaces.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_favorites_favorites_button_edit_form',
  'render callback' => 'oa_favorites_favorites_button_render',
);

/**
 * Render callback for the panel.
 */
function oa_favorites_favorites_button_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  $block = new stdClass();
  $block->title = '';
  $node = NULL;
  $space_id = oa_core_get_space_context();
  if (!empty($space_id)) {
    $node = node_load($space_id);
  }

  if ($user->uid) {
    $items = oa_favorites_get_spaces($user);
    $classes = '';
    // favorites flag link
    if (isset($node->nid)) {
      $items['links'][] = flag_create_link(FAVORITE_SPACE, $node->nid);
      if (oa_favorites_is_favorite_space($user->uid, $node->nid)) {
        $classes .= 'oa-is-favorite';
      }
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
      $vars['oa_toolbar_btn_class'] = $classes;
      $vars['oa_toolbar_btn_class'] .= variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';
      $block->content = theme('oa_favorites_favorites_button', $vars);
    }
  }
  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_favorites_favorites_button_edit_form($form, &$form_state) {
  return $form;
}
