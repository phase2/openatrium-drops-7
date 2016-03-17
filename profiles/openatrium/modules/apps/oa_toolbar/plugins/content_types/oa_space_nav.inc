<?php
/**
 * @file
 * Provides a panels pane that displays the Space navigation.
 */

$plugin = array(
  'title' => t('Space navigation'),
  'description' => t('Toolbar widget for showing current space and navigation.'),
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_toolbar_oa_space_nav_form',
  'render callback' => 'oa_toolbar_oa_space_nav_render',
  'defaults' => array(
  ),);

/**
 * Render callback.
 */
function oa_toolbar_oa_space_nav_render($subtype, $conf, $panel_args) {
  global $user;

  $vars['oa_toolbar_btn_class'] = variable_get('oa_toolbar_style', 0) ? '' : 'btn-inverse';

  // Separators
  $vars['oa_toolbar_separator'] = t('&gt;');
  $vars['home_url'] = url('<front>', array('absolute' => TRUE));

  // Spaces
  $space = NULL;
  $space_id = oa_core_get_space_context();
  $node = menu_get_object();
  oa_core_add_node_class($node);
  $front_panel = drupal_is_front_page() && !(isset($node) && ($node->type == OA_SPACE_TYPE));

  if ($front_panel) {
    $space_id = 0;  // reset breadcrumbs on home page
  }

  $vars['space_label'] = '';
  $vars['section_label'] = '';
  $vars['sections_list'] = '';
  $vars['parent_label'] = '';
  $vars['parent_url'] = '';
  $vars['parent_list'] = '';
  $vars['subspace_list'] = '';
  $vars['sections_list'] = '';

  if (isset($space_id) && ($space = node_load($space_id)) && node_access('view', $space)) {
    $title = $space->title;
    $space_type = $space->type;
    oa_core_add_node_class($space);
    $vars['space_label'] = check_plain($title);
    $vars['space_url'] = url('node/' . $space_id);

    $parent_list = oa_toolbar_get_parent_list($space_id, $space_type);
    $subspace_list = oa_toolbar_get_subspace_list($space_id, $space_type);

    $current_space = array(l($title, 'node/' . $space_id, array(
      'attributes' => array('class' => array('active')))));

    $vars['current_space'] = theme('item_list', array(
      'items' => $current_space,
      'title' => '',
      'type' => 'ul',
    ));

    $vars['parent_list'] = theme('item_list', array(
      'items' => !empty($parent_list['links']) ? $parent_list['links'] : array(),
      'title' => l('Home', '<front>'),
      'type' => 'ul',
    ));

    $vars['subspace_list'] = theme('item_list', array(
      'items' => !empty($subspace_list['links']) ? $subspace_list['links'] : array(),
      'title' => ($space_type == OA_SPACE_TYPE) ? t('Subspaces') : t('Subgroups'),
      'type' => 'ul',
    ));
  }
  else {
    $space = NULL;
  }

  if (!empty($space) && ($space->type == OA_SPACE_TYPE)) {
    $section_list = oa_toolbar_get_section_list($space_id);
    $section_id = oa_core_get_section_context($node);
    if (($section = node_load($section_id)) && node_access('view', $section)) {
      if (isset($section->field_oa_section[LANGUAGE_NONE][0]['tid'])) {
        oa_core_add_taxonomy_class($section->field_oa_section[LANGUAGE_NONE][0]['tid']);
      }
      // Mark link as active
      $section_list['links'][$section_id] = l($section->title, 'node/' . $section_id, array(
        'attributes' => array('class' => array('active')),
      ));
      $vars['section_label'] = $section->title;
      $vars['section_url'] = url('node/' . $section_id);
    }

    $vars['sections_list'] = theme('item_list', array(
      'items' => !empty($section_list['links']) ? $section_list['links'] : array(),
      'title' => t('Sections'),
      'type' => 'ul',
    ));
  }

  if (empty($vars['space_label'])) {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = theme('oa_space_nav', $vars);
  return $block;
}

/**
 * Edit form callback.
 */
function oa_toolbar_oa_space_nav_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function oa_toolbar_oa_space_nav_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
