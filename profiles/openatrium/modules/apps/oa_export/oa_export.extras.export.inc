<?php

/**
 * Helper function to export comments on entities.
 *
 * @param integer $entity_id
 * @param array $results
 */
function oa_export_entity_comments_export($entity_id, &$results) {
  foreach (oa_export_get_comments($entity_id) as $cid) {
    if ($comment = reset(entity_load('comment', array($cid)))) {
      oa_export_entity_export('comment', $comment, $results);
    }
    // Not sure this can happen but have had issues with missing entities.
    else {
      $results['messages'][] = t("The comment with cid: !cid, couldn't be exported. It no longer exists", array('!cid' => $cid));
    }
  }
}

/**
 * Export menu links for this entity.
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_entity_menu_export(&$entity, $entity_id, $entity_type, &$results) {

  // Look for a link on this node entity.
  if ($mlid = og_menu_single_get_link_mlid('node', $entity_id)) {
    // Load the link by the menu link id.
    $link = menu_link_load($mlid);
    // Can there be a tree?
    $tree = _menu_build_tree(OG_MENU_SINGLE_MENU_NAME, array('expanded' => array($mlid), 'min_depth' => $link['depth']+1));

    // Save the link keyed as: link:[MENU LINK ID]:[ENTITY ID]
    $results['export']['link:' . $link['mlid']] = $link;
    $results['export']['menu_trees:0'] = $tree;
  }
}

/**
 * Export group metadata for this entity.
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 * @throws EntityMalformedException
 */
function oa_export_entity_group_metadata_export(&$entity, $entity_type, &$results) {

  list($entity_id,,$bundle) = entity_extract_ids($entity_type, $entity);

  if ($roles = og_roles('node', $bundle, $entity_id)) {
    // Store the roles keyed by role:[BUNDLE]:[ENTITY_ID].
    $results['export']['role:' . $bundle . ':' . $entity_id] = $roles;
    if ($permissions = og_role_permissions($roles)) {
      $results['export']['permission:' . $entity_id] = $permissions;
    }
  }
}
