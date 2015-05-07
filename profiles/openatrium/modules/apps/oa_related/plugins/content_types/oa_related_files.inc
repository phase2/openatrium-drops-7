<?php
/**
 * @file oa_related_files.inc
 */

$plugin = array(
  'title' => t('Attached Files'),
  'description' => t('Displays all files related to a node.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'render callback' => 'oa_related_files_render',
  'edit form' => 'oa_related_files_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
  ),
);

/**
 * Run-time rendering of the body of the pane.
 *
 * @see ctools_plugin_examples for more advanced info
 */
function oa_related_files_render($subtype, $conf, $args, $context) {
  if (!isset($context->data)) {
    return;
  }
  $node = $context->data;
  $nid = $node->nid;

  $query = db_select('file_managed', 'f');
  $query->leftJoin('field_data_field_oa_media', 'm', 'm.field_oa_media_fid = f.fid');
  $query->leftJoin('field_data_field_oa_related', 'r', "r.field_oa_related_value = m.entity_id AND m.entity_type = 'paragraphs_item'");
  $query->fields('f', array('fid'))
    ->orderBy('f.fid');

  $or = db_or();
  $or->condition(db_and()
     ->condition('m.entity_id', $nid)
     ->condition('m.entity_type', 'node'));
  $or->condition(db_and()
    ->condition('r.entity_id', $nid)
    ->condition('r.entity_type', 'node'));

  $query->condition($or);
  $fids = $query->execute()->fetchCol(0);
  $full_files = file_load_multiple($fids);
  $file_render = file_view_multiple($full_files, 'colorbox');

  $files = array();
  foreach ($full_files as $key => $file) {
    $title = $file->filename;
    if (!empty($file->field_file_title[LANGUAGE_NONE][0]['safe_value'])) {
      $title = $file->field_file_title[LANGUAGE_NONE][0]['safe_value'];
    }
    elseif (!empty($file->field_file_image_title_text[LANGUAGE_NONE][0]['safe_value'])) {
      $title = $file->field_file_image_title_text[LANGUAGE_NONE][0]['safe_value'];
    }
    elseif (!empty($file->field_file_image_alt_text[LANGUAGE_NONE][0]['safe_value'])) {
      $title = $file->field_file_image_alt_text[LANGUAGE_NONE][0]['safe_value'];
    }
    $render = drupal_render($file_render['files'][$file->fid]);
    $icon = file_icon_url($file);
    $uri = file_entity_download_uri($file);
    $url = file_create_url($file->uri);
    if ($file->type == 'document') {
      $render = l(theme('image', array('path' => $icon)), $url, array('html' => TRUE));
    }

    $files[] = array(
      'raw_title' => $title,
      'title' => l($title, $url),
      'filename' => $file->filename,
      'fid' => $file->fid,
      'size' => format_size($file->filesize),
      'icon' => $icon,
      'url' => $url,
      'downloadurl' => url($uri['path'], $uri['options']),
      'date' => format_date($file->timestamp, 'short'),
      'render' => $render,
    );
  }

  $block = new stdClass();
  $block->title = 'Attachments';
  $block->content = theme('oa_related_files', array('files' => $files));

  return $block;
}

/**
 * Empty config form
 */
function oa_related_files_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_related_files_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
