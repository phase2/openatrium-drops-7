<?php
/**
 * @file
 * Examples and documentation.
 */

/**
 * Implements hook_oa_import_panelizer_CONTENT_TYPE().
 *
 * In this example: We have added a pane that references a node by its nid.
 * When that node is imported into a new site its nid will more than likely
 * be different. To keep from having to use uuids, this hook will allow you to
 * handle mapping the new node id to the references in the panelizer config.
 */
function hook_oa_import_panelizer_NODE_TYPE(&$content, $key, $imports, &$map) {
  $node_key = 'node:' . $content->configuration['nid'];
  if (isset($map[$node_key])) {
    $nid = $map[$node_key];
  }
  else {
    // The node hasn't been imported yet so we don't know what the new nid will
    // be. Import the node now.
    $nid = oa_export_entity_import('node', $imports[$node_key], $node_key, $imports, $map);
  }
  if (!empty($nid)) {
    $node = node_load($nid);
    // 'cta_nid' => 'CTA: Take Action [id: 16]',
    $content->configuration['nid'] = $nid;
    $content->configuration['custom_autocomplete_field'] = $node->title . ' ' . '[id: ' . $nid . ']';
  }
}
