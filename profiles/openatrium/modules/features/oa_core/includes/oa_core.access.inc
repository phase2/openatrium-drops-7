<?php
/**
 * @file
 * Code for Access Control functions for OpenAtrium spaces
 */

/**
 * Determine access to a Open Atrium Section
 * do NOT use node_load here as it gets called from hook_node_grants()
 */
function oa_core_section_access($row, $spaces, $account) {

  $gid = $row['field_oa_group_ref_target_id'];
  $team_id = $row['field_oa_team_ref_target_id'];
  $user_id = $row['field_oa_user_ref_target_id'];

  // check if no access fields are set
  if (is_null($gid) && is_null($team_id) && is_null($user_id)) {
    return NODE_ACCESS_ALLOW;
  }

  // Test Group membership
  if (!is_null($gid) && !empty($spaces['node'])) {
    if (in_array($gid, $spaces['node'])) {
      return NODE_ACCESS_ALLOW;
    }
  }

  // Test Team membership
  if (!is_null($team_id)) {
    if (oa_core_member_of_team($team_id, $account->uid)) {
      return NODE_ACCESS_ALLOW;
    }
  }

  // Test User membership
  if (!is_null($user_id)) {
    if ($user_id == $account->uid) {
      return NODE_ACCESS_ALLOW;
    }
  }

  // none of the groups, teams, or users allowed access, so deny access
  return NODE_ACCESS_DENY;
}

/**
 * Implements hook_node_grants().
 * Define node access grant realm for Open Atrium sections
 */
function oa_core_node_grants($account, $op) {
  static $cache = array();

  if ($op != 'view') {
    return;
  }

  if (isset($cache[$account->uid])) {
    return $cache[$account->uid];
  }
  $member_spaces = og_get_entity_groups('user', $account);
  // add the list of public spaces that user might not be explicitly
  // a member of, but can access content within
  $spaces = array_merge($member_spaces, oa_core_get_public_spaces());
  if (!empty($spaces['node'])) {
    // get the list of all section nodes assigned to the list of spaces
    $query = db_select('node', 'n');
    $query->join('og_membership', 'og', 'n.nid = og.etid');
    $query
      ->fields('n', array('nid'))
      ->condition('n.type', OA_SECTION_TYPE)
      ->condition('og.entity_type', 'node')
      ->condition('og.field_name', OA_SPACE_FIELD)
      ->condition('og.gid', $spaces['node'], 'IN');
    $result = $query->execute();
    // get a list of sections that don't have any access fields
    // loop through each result to determine access to section
    $sections = $result->fetchCol(0);

    if (!empty($sections)) {
      // do a big complex query to grab all section access fields
      // might be a way to merge this with the previous query
      // but it makes my brain hurt
      $query = db_select('node', 'n');
      // we join with the Groups, Teams, Users fields
      $query->leftJoin('field_data_field_oa_group_ref', 'o', "n.nid = o.entity_id AND o.entity_type = 'node'");
      $query->leftJoin('field_data_field_oa_team_ref', 't', "n.nid = t.entity_id AND t.entity_type = 'node'");
      $query->leftJoin('field_data_field_oa_user_ref', 'u', "n.nid = u.entity_id AND u.entity_type = 'node'");
      $query
        ->fields('n', array('nid'))
        ->fields('o', array('field_oa_group_ref_target_id'))
        ->fields('t', array('field_oa_team_ref_target_id'))
        ->fields('u', array('field_oa_user_ref_target_id'))
        ->condition('n.type', OA_SECTION_TYPE)
        ->condition('n.nid', $sections, 'IN');
      $result = $query->execute();

      while ($row = $result->fetchAssoc()) {
        $sid = $row['nid'];
        // only check detailed access for non-public sections
        $access = oa_core_section_access($row, $member_spaces, $account);
        if (($access == NODE_ACCESS_ALLOW) || ($access == NODE_ACCESS_IGNORE)) {
          $grants[OA_ACCESS_REALM][] = $sid;
        }
      }
    }
  }

  $cache[$account->uid] = !empty($grants) ? $grants : array();
  return $cache[$account->uid];
}

/**
 * Implements hook_node_access_records().
 */
function oa_core_node_access_records($node) {
  $sids = array();
  if ($node->status == 0) {
    // don't change access for unpublished nodes
    // keep normal Drupal access (should be set for only Own access)
  }
  elseif ($node->type == OA_SECTION_TYPE) {
    if (!oa_core_section_is_public($node)) {
      $sids[] = $node->nid;
    }
  }
  // Look for the default section reference
  elseif (!empty($node->{OA_SECTION_FIELD})) {
    foreach ($node->{OA_SECTION_FIELD}[LANGUAGE_NONE] as $entity_ref) {
      $section = node_load($entity_ref['target_id']);
      if (!oa_core_section_is_public($section)) {
        $sids[] = $entity_ref['target_id'];
      }
    }
  }
  if (empty($sids)) {
    return array();
  }

  foreach ($sids as $sid) {
    $grants[] = array(
      'realm' => OA_ACCESS_REALM,
      'gid' => $sid,
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
      'priority' => 0,
    );
  }

  return !empty($grants) ? $grants : array();
}

/**
 * Update the node_access_records of the given nodes
 * @param  array $nodes array of nids
 */
function oa_core_update_access_records($nodes) {
  foreach ($nodes as $nid) {
    $node = node_load($nid);
    node_access_acquire_grants($node);
  }
}

/**
 * Implements hook_node_update
 * if saving a section or space node, update access locks on related content
 */
function oa_core_node_update($node) {
  if ($node->type == OA_SPACE_TYPE) {
    // check if group access changed and update space content grants
    if (isset($node->group_access[LANGUAGE_NONE][0]['value']) &&
      isset($node->original->group_access[LANGUAGE_NONE][0]['value']) &&
      ($node->group_access[LANGUAGE_NONE][0]['value'] !=
       $node->original->group_access[LANGUAGE_NONE][0]['value'])) {
      // rebuild space content nodes
      $nodes = db_select('og_membership', 'og')
        ->fields('og', array('etid'))
        ->condition('og.entity_type', 'node')
        ->condition('og.gid', $node->nid)  // all content nodes of this space
        ->execute()
        ->fetchCol(0);
      // clear the static node cache for the space node so correct access
      // values are tested in hook_node_access_records
      entity_get_controller('node')->resetCache(array($node->nid));
      oa_core_update_access_records($nodes);
    }
  }
  elseif ($node->type == OA_SECTION_TYPE) {
    // if section node changed from public to private, update content grants
    $was_public = oa_core_section_is_public($node->original);
    $is_public  = oa_core_section_is_public($node);
    if ($was_public != $is_public) {
      // rebuild section content nodes
      $nodes = db_select('field_data_' . OA_SECTION_FIELD, 'n')
        ->fields('n', array('entity_id'))
        ->condition('n.entity_type', 'node')
        ->condition('n.oa_section_ref_target_id', $node->nid)
        ->execute()
        ->fetchCol(0);
      // clear the static node cache for the space node so correct access
      // values are tested in hook_node_access_records
      entity_get_controller('node')->resetCache(array($node->nid));
      oa_core_update_access_records($nodes);
    }
  }
}

/**
 * Implements hook_file_entity_access
 * Check permissions of private files based upon the node they are attached to
 */
function oa_core_file_entity_access($op, $file, $account) {
  if (is_object($file) && in_array($op, array('view', 'download'))) {
    $scheme = file_uri_scheme($file->uri);
    $wrapper = file_entity_get_stream_wrapper($scheme);
    if (!empty($wrapper['private'])) {
      $query = db_select('node', 'n');
      $query->join('field_data_field_oa_media', 'f', "n.nid = f.entity_id AND f.entity_type = 'node'");
      $nodes = $query
        ->fields('n', array('nid'))
        ->condition('f.field_oa_media_fid', $file->fid)
        ->addTag('node_access')
        ->execute()
        ->fetchCol(0);
      if (!empty($nodes)) {
        return FILE_ENTITY_ACCESS_ALLOW;
      }
      else {
        // if no nodes have access, check to see if ANY nodes reference image
        $query = db_select('node', 'n');
        $query->join('field_data_field_oa_media', 'f', "n.nid = f.entity_id AND f.entity_type = 'node'");
        $nodes = $query
          ->fields('n', array('nid'))
          ->condition('f.field_oa_media_fid', $file->fid)
          ->execute()
          ->fetchCol(0);
        if (empty($nodes)) {
          // image is not referenced by any node, so allow it
          return FILE_ENTITY_ACCESS_ALLOW;
        }
      }
    }
  }
  return FILE_ENTITY_ACCESS_IGNORE;
}
