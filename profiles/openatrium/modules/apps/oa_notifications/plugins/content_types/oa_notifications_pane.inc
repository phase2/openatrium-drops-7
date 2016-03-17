<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Notifications'),
  'description' => t('Displays the list of Groups, Teams and Users that will be notified of a change to an Entity.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'render callback' => 'oa_notifications_pane_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the pane.
 *
 * @see ctools_plugin_examples for more advanced info
 */
function oa_notifications_pane_render($subtype, $conf, $args, $context) {
  global $user;
  if (!isset($context->data) || !variable_get('oa_messages_notifications', TRUE)) {
    return FALSE;
  }

  $node = $context->data;
  if (empty($user->uid) || !node_access('view', $node)) {
    return FALSE;
  }

  $form = drupal_get_form('oa_notifications_edit_form', $node);

  if (!isset($form[OA_NOTIFY_FORM]['source_id']) && !isset($form[OA_NOTIFY_FORM]['notify_list'])) {
    return FALSE;
  }
  $block = new stdClass();
  $block->title = t('Notifications');
  $block->content = $form;
  return $block;
}

/**
 * Render the edit form for Notifications
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $node
 *    The node being viewed/edited
 * @return
 *    The form
 */
function oa_notifications_edit_form($form, &$form_state, $node) {
  // Since this form functions via AJAX we need to tell the form handlers to include it when processing the form
  ctools_form_include_file($form_state, drupal_get_path('module', 'oa_notifications') . '/plugins/content_types/oa_notifications_pane.inc');

  $form['#node'] = $node;
  $form[OA_NOTIFY_FORM] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );
  oa_notifications_form_fields($form[OA_NOTIFY_FORM], $form_state, $node);

  return $form;
}
