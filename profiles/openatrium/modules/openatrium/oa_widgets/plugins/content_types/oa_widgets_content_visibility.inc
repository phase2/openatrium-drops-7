<?php

/**
 * @file
 * Provides a panels pane that shows the content's visibility.
 */

$plugin = array(
  'title' => t('Content Visibility'),
  'description' => t('Show content visibility.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_widgets_content_visibility_edit_form',
  'render callback' => 'oa_widgets_content_visibility_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_widgets_content_visibility_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }
  $vars = array();
  $block = new stdClass();
  $block->title = 'Content Visibility';

  $node = $context->data;
  if ($node->type == OA_SPACE_TYPE || $node->type == OA_GROUP_TYPE) {
    $visibility = field_get_items('node', $node, 'group_access');
    $vars['public'] = empty($visibility[0]['value']);
  }
  else {

    if ($node->type == OA_SECTION_TYPE) {
      $section_node = $node;
    }
    else {
      $section_reference_field = field_get_items('node', $node, OA_SECTION_FIELD);
      $section_node = node_load($section_reference_field[0]['target_id']);
    }
    $vars['public'] = oa_core_section_is_public($section_node);

    if (!$vars['public']) {
      $space_reference_field = field_get_items('node', $section_node, OA_SPACE_FIELD);
      $space_node = node_load($space_reference_field[0]['target_id']);

      $vars['accessors']['group'] = array(
        'links' => oa_widgets_build_visibility_links('node', $section_node, OA_GROUP_FIELD),
        'label' => t('Groups'),
      );
      $vars['accessors']['teams'] = array(
        'links' => oa_widgets_build_visibility_links('node', $section_node, OA_TEAM_FIELD),
        'label' => t('Teams'),
      );
      $vars['accessors']['users'] = array(
        'links' => oa_widgets_build_visibility_links('user', $section_node, OA_USER_FIELD),
        'label' => t('Additional Users'),
      );
    }
  }

  $block->content = theme('oa_widgets_content_visibility', $vars);
  return $block;
}


/**
 * Helper function, builds links for the various visibility fields on content.
 */
function oa_widgets_build_visibility_links($type, $node, $field) {
  $links = array();
  $values = field_get_items('node', $node, $field);
  if (!empty($values)) {
    $links = array();
    foreach ($values as $value) {
      if ($type == 'node') {
        $value_node = node_load($value['target_id']);
        $links[] = l($value_node->title, "node/" . $value_node->nid);
      }
      elseif ($type == 'user') {
        $user = user_load($value['target_id']);
        $links[] = l($user->name, "user/" . $user->uid);
      }
    }
  }
  return $links;
}


/**
 * Custom edit form to allow users to enable/disable selectable content types
 */
function oa_widgets_content_visibility_edit_form($form, &$form_state) {
  return $form;
}


/**
 * Saves changes to the widget.
 */
function oa_widgets_content_visibility_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

