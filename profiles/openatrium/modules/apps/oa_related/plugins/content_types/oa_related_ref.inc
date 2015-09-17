<?php
/**
 * @file oa_related_ref.inc
 */

$plugin = array(
  'title' => t('Referenced From'),
  'description' => t('Displays all nodes that references this node.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'render callback' => 'oa_related_ref_render',
  'edit form' => 'oa_related_ref_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
  ),
);

/**
 * Run-time rendering of the body of the pane.
 *
 * @see ctools_plugin_examples for more advanced info
 */
function oa_related_ref_render($subtype, $conf, $args, $context) {
  if (!isset($context->data)) {
    return;
  }
  $node = $context->data;
  $nid = $node->nid;

  // get list of fields being used for related content
  $fieldmap = field_info_field_map();
  $fields = array();
  foreach ($fieldmap as $fieldname => $field) {
    if (($field['type'] == 'entityreference') && (in_array('paragraphs_item', array_keys($field['bundles'])))) {
      $fields[] = $fieldname;
    }
  }

  $or = db_or();
  $query = db_select('node', 'n');
  $query->join('field_data_field_oa_related', 'r', "r.entity_id = n.nid AND r.entity_type = 'node'");
  foreach ($fields as $fieldname) {
    $query->leftJoin('field_data_' . $fieldname, $fieldname,
      $fieldname . ".entity_id = r.field_oa_related_value AND " . $fieldname . "." . $fieldname . "_target_id = $nid");
    $or->isNotNull($fieldname . '.entity_id');
  }
  $query->fields('n', array('nid', 'title', 'type'))
    ->condition($or)
    ->addTag('node_access');

  $nodes = $query->execute()->fetchAllAssoc('nid');
  $items = array();
  foreach ($nodes as $node) {
    $items[] = array(
      'raw_title' => check_plain($node->title),
      'nid' => $node->nid,
      'title' => l($node->title, 'node/' . $node->nid),
      'type' => node_type_get_name($node),
    );
  }

  if (!empty($items)) {
    $block = new stdClass();
    $block->title = 'Referenced from';
    $block->content = theme('oa_related_ref', array('items' => $items));

    return $block;
  }
  return FALSE;
}

/**
 * Empty config form
 */
function oa_related_ref_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_related_ref_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
