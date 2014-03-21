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
  $cache = &drupal_static(__FUNCTION__, array());

  if ($op != 'view' || !$account->uid) {
    return;
  }

  if (isset($cache[$account->uid])) {
    return $cache[$account->uid];
  }

  // Handle unpublished content permissions
  if (user_access('bypass node access') || user_access('view own unpublished content')) {
    // get a list of unpublished nodes owned by this user
    $query = db_select('node', 'n');
    $query->fields('n', array('nid'))
      ->condition('n.status', 0);
    if (!user_access('bypass node access')) {
      // user with bypass access can access all unpublished content
      $query->condition('n.uid', $account->uid);
    }
    $grants[OA_UNPUBLISHED_REALM] = $query->execute()->fetchCol(0);
  }

  // Combine the spaces the user is part of with public spaces.
  $member_spaces = oa_core_get_groups_by_user($account, 'node');
  $spaces = array_merge($member_spaces, oa_core_get_public_spaces());
  if (!empty($spaces)) {
    $query = db_select('node', 'n');

    // Join the og table to filter by spaces.
    $query->join('og_membership', 'og', "n.nid = og.etid AND og.entity_type = 'node' AND og.field_name = '" . OA_SPACE_FIELD . "'");
    $query->condition('og.gid', $spaces, 'IN');

    // we join with the Groups, Teams, Users fields
    $query->fields('n', array('nid'));
    $query->condition('n.type', OA_SECTION_TYPE);

    // Create an or condition that finds if section is allowed.
    $db_or = db_or();

    // Allow author of section.
    $db_or->condition('n.uid', $account->uid , '=');

    // If user is specified in user ref column.
    $query->leftJoin('field_data_field_oa_user_ref', 'u', "n.nid = u.entity_id AND u.entity_type = 'node'");
    $db_or->condition('u.field_oa_user_ref_target_id', $account->uid , '=');


    // If one of the groups are included.
    if ($member_spaces) {
      $query->leftJoin('field_data_field_oa_group_ref', 'o', "n.nid = o.entity_id AND o.entity_type = 'node'");
      $db_or->condition('o.field_oa_group_ref_target_id', $member_spaces , 'IN');
    }

    // If one of the teams are included.
    $query->leftJoin('field_data_field_oa_team_ref', 't', "n.nid = t.entity_id AND t.entity_type = 'node'");
    $query->leftJoin('node', 'tn', "tn.nid = t.field_oa_team_ref_target_id");
    // Add creater of team.
    $db_or->condition('tn.uid', $account->uid , '=');
    $query->leftJoin('field_data_field_oa_team_users', 'tu', "t.field_oa_team_ref_target_id = tu.entity_id AND tu.entity_type = 'node' AND tu.deleted=0");
    // If user is part of team.
    $db_or->condition('tu.field_oa_team_users_target_id', $account->uid , '=');

    // Add or to query.
    $query->condition($db_or);


    // Set grants to nids, which should be only valid ones.
    $grants[OA_ACCESS_REALM] = $query->execute()->fetchCol(0);
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
    // Drupal doesn't handle grants for unpublished nodes
    // Grants are needed for Views to work
    $grants[] = array(
      'realm' => OA_UNPUBLISHED_REALM,
      'gid' => $node->nid,
      'grant_view' => 1,
      'grant_update' => 0,
      'grant_delete' => 0,
      'priority' => 0,
    );
    return $grants;
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
      // Priority 1 means lesser grants for this node will be ignored.
      'priority' => 1,
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
 * Implements hook_node_access()
 * Add proper 'create' access checks that OG doesn't handle
 */
function oa_core_node_access($node, $op, $account) {
  $type = is_string($node) ? $node : (is_array($node) ? $node['type'] : $node->type);

  if ($op == 'create' && (($type == OA_SPACE_TYPE) || og_is_group_content_type('node', $type))) {
    // In og.module, og_node_access doesn't handle 'create' because
    // it doesn't have a Group context.
    // Well, in OA2 we *have* a Group context most of the time.
    // Can't call oa_core_get_space_context() however since
    // og_context_determine_context() will cause an infinite loop
    if (defined('OG_SESSION_CONTEXT_ID') && isset($_SESSION[OG_SESSION_CONTEXT_ID])) {
      $space_id = $_SESSION[OG_SESSION_CONTEXT_ID];
      // so let's use that to test 'create' access
      if ($space_id) {
        $return = og_user_access('node', $space_id, "$op $type content", $account);
        if ($return) {
          return NODE_ACCESS_ALLOW;
        }
      }
      if ($type != OA_SPACE_TYPE) {
        return NODE_ACCESS_DENY;
      }
    }
  }

  return NODE_ACCESS_IGNORE;
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
 * Implements hook_file_entity_access().
 *
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
        else {
          // image is referenced by node that we don't have access to, so deny
          return FILE_ENTITY_ACCESS_DENY;
        }
      }
    }
  }
  return FILE_ENTITY_ACCESS_IGNORE;
}

/**
 * Implements hook_query_media_browser_alter().
 * Add private file access support to media browser
 */
function oa_core_query_media_browser_alter(QueryAlterableInterface $query) {

  if (!user_access('administer nodes') && module_implements('node_grants')) {
    // first, remove the existing condition from media.media.inc that prevents private files
    $where =& $query->conditions();
    foreach ($where as $delta => $condition) {
      if (isset($condition['value']) && isset($condition['operator']) &&
        ($condition['value'] == 'private://%') && ($condition['operator'] == 'NOT LIKE')) {
        unset($where[$delta]);
        break;
      }
    }

    // next, add a proper node_access query restriction
    $or = db_or();
    // Ensure that the query is against the file_managed table.
    $tables = $query->getTables();
    if (empty($tables['file_managed'])) {
      throw new Exception(t('Media browser being queried without the file_managed table.'));
    }
    $alias = $tables['file_managed']['alias'];

    // get down to which node has the attachment
    $query->addJoin('LEFT', 'field_data_field_oa_media', 'media_field', "media_field.field_oa_media_fid = $alias.fid AND media_field.entity_type = 'node'");
    $query->addJoin('LEFT', 'node', 'node', "node.nid = media_field.entity_id");
    $query->addJoin('LEFT', 'node_access', 'node_access', "node.nid = node_access.nid");

    // this is from views_handler_filter_node_access.inc
    // cannot just use the addTag('node access') because base table of query is not node
    $table = 'node_access';
    $grants = db_or();
    foreach (node_access_grants('view') as $realm => $gids) {
      foreach ($gids as $gid) {
        $grants->condition(db_and()
          ->condition($table . '.gid', $gid)
          ->condition($table . '.realm', $realm)
        );
      }
    }
    $or->condition(db_and()
      ->condition($grants)
      ->condition($table . '.grant_view', 1, '>=')
    );

    // finally, put back the "private" condition as an OR state for public files
    $or->condition($alias . '.uri', db_like('private://') . '%', 'NOT LIKE');
    $query->condition($or);
  }
}

/**
 * Implements hook_og_membership_insert().
 */
function oa_core_og_membership_insert($og_membership) {
  drupal_static_reset('oa_core_node_grants');
}

function oa_core_visibility_data($node) {
  $data = array();
  $data['published'] = !empty($node->status);
  $data['archived'] = FALSE;
  if (module_exists('flag')) {
    $flag = flag_load('trash');
    $data['archived'] = $flag->is_flagged($node->nid);
  }
  if ($node->type == OA_SPACE_TYPE || $node->type == OA_GROUP_TYPE) {
    $visibility = field_get_items('node', $node, 'group_access');
    $data['public'] = empty($visibility[0]['value']);
    if (!$data['public']) {
      $data['accessors']['group'] = array(
        'links' => _oa_core_build_visibility_links('node', $node, 'oa_parent_space', OA_GROUP_TYPE),
        'label' => t('Groups'),
      );
      $data['accessors']['space'] = array(
        'links' => _oa_core_build_visibility_links('node', $node, 'oa_parent_space', OA_SPACE_TYPE),
        'label' => t('Spaces'),
      );
    }
  }
  else {

    if ($node->type == OA_SECTION_TYPE) {
      $section_node = $node;
    }
    else {
      $section_reference_field = field_get_items('node', $node, OA_SECTION_FIELD);
      $section_node = node_load($section_reference_field[0]['target_id']);
    }
    if (empty($section_node)) {
      $section_node = $node;
    }

    $space_reference_field = field_get_items('node', $section_node, OA_SPACE_FIELD);
    $space_node = node_load($space_reference_field[0]['target_id']);

    if (empty($space_node)) {
      $data['public'] = TRUE;
    }
    else {
      $visibility = field_get_items('node', $space_node, 'group_access');
      $data['public'] = (($section_node->type != OA_SECTION_TYPE) || oa_core_section_is_public($section_node))
        && empty($visibility[0]['value']);

      if (!$data['public']) {

        if (!empty($visibility[0]['value'])) {
          $data['accessors']['space'] = array(
            'links' => _oa_core_build_visibility_links('node', $section_node, OA_SPACE_FIELD, OA_SPACE_TYPE),
            'label' => t('Spaces'),
          );
        }
        $data['accessors']['group'] = array(
          'links' => _oa_core_build_visibility_links('node', $section_node, OA_GROUP_FIELD),
          'label' => t('Groups'),
        );
        $data['accessors']['teams'] = array(
          'links' => _oa_core_build_visibility_links('node', $section_node, OA_TEAM_FIELD),
          'label' => t('Teams'),
        );
        $data['accessors']['users'] = array(
          'links' => _oa_core_build_visibility_links('user', $section_node, OA_USER_FIELD),
          'label' => t('Additional Users'),
        );
      }
    }
  }
  $data['title'] = $data['public'] ? t('Public') : t('Private');
  return $data;
}

/**
 * Helper function, builds links for the various visibility fields on content.
 */
function _oa_core_build_visibility_links($type, $node, $field, $bundle = '') {
  $links = array();
  $values = field_get_items('node', $node, $field);
  if (!empty($values)) {
    $links = array();
    foreach ($values as $value) {
      if ($type == 'node') {
        $value_node = node_load($value['target_id']);
        if (empty($bundle) || ($bundle == $value_node->type)) {
          $links[] = l($value_node->title, "node/" . $value_node->nid);
        }
      }
      elseif ($type == 'user') {
        $user = user_load($value['target_id']);
        $links[] = l($user->name, "user/" . $user->uid);
      }
    }
  }
  return $links;
}

