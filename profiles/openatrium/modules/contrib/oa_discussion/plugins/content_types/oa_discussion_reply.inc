<?php

/**
 * @file
 * Provides the reply form pane.
 */

$plugin = array(
  'title' => t('Reply form'),
  'description' => t('Reply to current content.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_discussion_reply_settings_form',
  'render callback' => 'oa_discussion_reply_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_discussion_reply_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }
  $node = $context->data;
  // Only show reply form if user is allowed to create a reply.
  $gid = $node->{OG_AUDIENCE_FIELD}[LANGUAGE_NONE][0]['target_id'];
  if (!og_user_access('node', $gid, 'write' . ' ' . $subtype . ' ' . 'to discussion post')) {
    return;
  }
  $output = drupal_get_form('oa_discussion_reply_form', $node);

  $block = new stdClass();
  $block->title = t('New Reply');
  $block->content = $output;
  return $block;
}

/**
 * Empty config form
 */
function oa_discussion_reply_settings_form($form, &$form_state) {
  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_discussion_reply_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render the edit form for Replies
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
function oa_discussion_reply_form($form, &$form_state, $node) {
  $parent = field_get_items('node', $node, 'oa_parent');
  $parent_id = !empty($parent[0]['target_id']) ? $parent[0]['target_id'] : $node->nid;

  $form['#node'] = $node;
  $form['#parent_id'] = $parent_id;

/*
  $form['oa_reply']['subject'] = array(
    '#type' => 'textfield',
    '#default_value' => '',
    '#attributes' => array(
      'placeholder' => t('Optional Subject'),
    ),
  );
  */

  $form['oa_reply']['body'] = array(
    '#type' => 'text_format',
    '#default_value' => '',
    '#format' => 'panopoly_wysiwyg_text',
  );

  // field_default_form requires #parents be set.
  $form['#parents'] = empty($form['#parents']) ? array() : $form['#parents'];

  // Only show attachment form if the user is allowed to add attachments.
  $gid = $node->{OG_AUDIENCE_FIELD}[LANGUAGE_NONE][0]['target_id'];
  if (og_user_access('node', $gid, 'add attachment to' . ' ' . $node->type)) {
    // mimic how the attachment field is rendered in normal node/add forms
    $field_name = 'field_oa_media';
    $field = field_info_field($field_name);
    $instance = field_info_instance('node', $field_name, 'oa_discussion_post');
    $form_field = field_default_form('node', NULL, $field, $instance, $node->language, NULL, $form, $form_state);
    if (!empty($form_field[$field_name])) {
      // need to preserve the array keys for other modules that hook into media
      // such as media_multiselect
      $form[$field_name] = $form_field[$field_name];
      form_load_include($form_state, 'inc', 'oa_discussion', 'plugins/content_types/oa_discussion_reply'); // For AJAX add more
    }
  }

  $form['oa_reply']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Reply'),
  );
  return $form;
}

/**
 * Submit handler for the Notifications Pane
 */
function oa_discussion_reply_form_submit($form, &$form_state) {
  $node = $form['#node'];
  $parent_id = $form['#parent_id'];
  $body = $form_state['values']['body'];
  $media = isset($form_state['values']['field_oa_media']) ? $form_state['values']['field_oa_media'][LANGUAGE_NONE] : array();
  if (!empty($parent_id) && (!empty($body['value']) || !empty($media))) {
    // determine a title for the reply
    if (!empty($form_state['values']['subject'])) {
      $title = $form_state['values']['subject'];
    }
    // Supply title from body
    elseif (!empty($body['value'])) {
      $alter = array(
        'max_length' => 80,
        'word_boundary' => TRUE,
        'ellipsis' => TRUE,
        'html' => TRUE,
      );
      $title = strip_tags( views_trim_text($alter, $body['value']));
    }
    // Supply title from media
    elseif (!empty($media)) {
      $files = array();
      foreach ($media as $delta => $file) {
        if (is_numeric($delta)) {
          $file = file_load($file['fid']);
          $files[] = $file->filename;
        }
      }
      $title = 'Attached ' . implode(', ', $files);
    }

    // create a new reply node
    $wrapper = oa_core_create_node('oa_discussion_post', $title, $node);
    $wrapper->oa_parent = $parent_id;
    $wrapper->body->set(array('value' => $body['value'], 'format' => $body['format']));
    foreach ($media as $delta => $file) {
      if (!empty($file['fid'])) {
        if (is_numeric($delta)) {
          $wrapper->field_oa_media[$delta]->set(array('fid' => $file['fid'], 'display' => $file['display']));
        }
      }
    }
    $wrapper->save();
  }
}

