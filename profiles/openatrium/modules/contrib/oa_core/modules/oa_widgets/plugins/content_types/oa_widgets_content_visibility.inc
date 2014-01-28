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
  $block = new stdClass();
  $block->title = t('Content Visibility');

  $node = $context->data;
  $vars = oa_core_visibility_data($node);

  $block->content = theme('oa_widgets_content_visibility', $vars);
  return $block;
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

