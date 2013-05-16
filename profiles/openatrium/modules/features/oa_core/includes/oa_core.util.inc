<?php
/**
 * @file
 * Code for Utility functions for OpenAtrium spaces
 */

/**
 * Returns the current space id context
 * @param  boolean $from_session only use the context stored in $SESSION
 * @return int Space ID
 */
function oa_core_get_space_context($from_session = FALSE) {
  if ($from_session && isset($_SESSION[OG_SESSION_CONTEXT_ID])) {
    return $_SESSION[OG_SESSION_CONTEXT_ID];
  }
  $context = og_context('node');
  return isset($context['gid']) ? $context['gid'] : 0;
}

/**
 * Returns the current section id context
 * @return int Section ID
 */
function oa_core_get_section_context() {
  return isset($_SESSION[OA_SESSION_SECTION])
    ? $_SESSION[OA_SESSION_SECTION]
    : 0;
}

/**
 * Determine if a user is a member of a team
 * @param  int $team_id
 * @param  int $user_id
 * @return boolean TRUE if user is in team
 */
function oa_core_member_of_team($team_id, $user_id) {
  $cache = &drupal_static(__FUNCTION__);

  if (!isset($cache[$team_id][$user_id])) {
    $result = db_select('field_data_field_oa_team_users', 'f')
      ->fields('f', array('field_oa_team_users_target_id'))
      ->condition('field_oa_team_users_target_id', $user_id)
      ->condition('entity_type', 'node')
      ->condition('entity_id', $team_id)
      ->condition('deleted', 0)
      ->execute();
    if ($result->rowCount() > 0) {
      $access = TRUE;
    }
    else {
      // not explicitly in team, but check ownership of team node
      // do NOT use node_load as this is called from hook_node_grants()
      $result = db_select('node', 'n')
        ->fields('n', array('uid'))
        ->condition('nid', $team_id)
        ->execute()
        ->fetchAssoc();
      $access = ($result['uid'] == $user_id) ? TRUE : FALSE;
    }
    $cache[$team_id][$user_id] = $access;
  }

  return $cache[$team_id][$user_id];
}

/**
 * Returns TRUE if the section $node has open access to public
 */
function oa_core_section_is_public($node) {
  return (
       empty($node->field_oa_group_ref[LANGUAGE_NONE])
    && empty($node->field_oa_team_ref[LANGUAGE_NONE])
    && empty($node->field_oa_user_ref[LANGUAGE_NONE])
    );
}

/**
 * Returns a list of group-content types throughout the system. List
 *   leaves out content types excluded by other modules/apps.
 *
 * @return array of strings denoting content types marked for omission
 */
function oa_core_list_content_types($space_content = FALSE) {
  $nodes = node_type_get_types();
  if ($space_content) {
    // remove types that are not space content
    foreach ($nodes as $key => $node) {
      if (!og_is_group_content_type('node', $node->type)) {
        unset($nodes[$key]);
      }
    }
  }

  // Queries hook_oa_omit_content_types to determine what content types
  //   modules wants to hide.
  $deny = module_invoke_all('oa_omit_content_types');
  if (!empty($deny)) {
    foreach ($deny as $remove) {
      unset($nodes[$remove]);
    }
  }

  return $nodes;
}

/**
 * Create a new content node within a space/section
 * @param  string $bundle  name of node bundle to create
 * @param  object $context an optional code to copy space/section from
 *   if not specified, current Session space/section context is used
 * @return object $wrapper entity metadata wrapper around node
 *
 * NOTE: The created node is NOT SAVED.  You need to use:
 *   $wrapper = oa_core_create_node(...);
 *   $wrapper->save();
 * to actually save the created node.  This allows you to set other
 * wrapper fields before saving
 */
function oa_core_create_node($bundle, $title = '', $context = NULL) {
  global $user;

  $values = array(
    'type' => $bundle,
    'uid' => $user->uid,
    'status' => 1,
    'comment' => 0,
    'promote' => 0,
  );
  $entity = entity_create('node', $values);
  $wrapper = entity_metadata_wrapper('node', $entity);

  $wrapper->title = $title;

  $space_id = $_SESSION['og_context']['gid'];
  $section_id = $_SESSION[OA_SESSION_SECTION];
  if (isset($context)) {
    // copy space and section fields from context node
    $context_wrapper = entity_metadata_wrapper('node', $context);
    if (isset($context_wrapper->{OA_SPACE_FIELD})) {
      $space_id = $context_wrapper->{OA_SPACE_FIELD}->value();
      if (is_array($space_id)) {
        // if multi-value space field, just use first space for message
        $space_id = array_shift($space_id);
      }
    }
    if (isset($context_wrapper->{OA_SECTION_FIELD})) {
      $section_id = $context_wrapper->{OA_SECTION_FIELD}->value();
    }
  }
  if (isset($wrapper->{OA_SPACE_FIELD})) {
    $wrapper->{OA_SPACE_FIELD} = $space_id;
  }
  if (isset($wrapper->{OA_SECTION_FIELD})) {
    $wrapper->{OA_SECTION_FIELD} = $section_id;
  }

  return $wrapper;
}

/**
 * Helper function to retrieve an array of node titles and links given
 * a list of node ids
 * @param  array  $ids array of node ids to fetch
 * @param  string $type optional node type to filter
 * @return array      associative array:
 *   'titles' is a list of node titles (clean)
 *   'links' is a list of node links
 *   'ids' is a list of the node ids
 */
function oa_core_get_titles($ids = array(), $type = '', $sort_field = NULL) {
  $items = array('titles' => array(), 'links' => array(), 'ids' => array());
  if (!empty($ids)) {
    $query = db_select('node', 'n');
    if (!empty($sort_field)) {
      $query->leftJoin('field_data_' . $sort_field, 's',
        "n.nid = s.entity_id AND s.entity_type = 'node'");
    }
    $query
      ->fields('n', array('nid', 'title'))
      ->condition('n.nid', $ids, 'IN');
    if (!empty($sort_field)) {
      $query->orderBy('s.' . $sort_field . '_value');
    }
    if (!empty($type)) {
      $query->condition('n.type', $type);
    }
    $result = $query->execute();
    while ($row = $result->fetchAssoc()) {
      $items['ids'][]    = $row['nid'];
      $items['titles'][] = check_plain($row['title']);
      $items['links'][]  = l($row['title'], 'node/' . $row['nid']);
    }
  }
  return $items;
}

/**
 * truncate a list to a given number of items with optional More link
 * @param  array $list      array to be truncated
 * @param  int $count     number of items desired
 * @param  string $more_link optional "More" link added to end of array
 * @param  boolean $always_link TRUE to always display more link
 * @return array            new list of items
 */
function oa_core_truncate_list($list, $count, $more_link = '', $always_link = FALSE) {
  $new_list = array_slice($list, 0, $count);
  if (!empty($more_link) && ($always_link ||(count($list) != count($new_list)))) {
    $new_list[] = $more_link;
  }
  return $new_list;
}

/**
 * Return a list of public spaces
 * since og_get_entity_groups doesn't return anything for anonymous users
 *
 * @return array
 * An array of public gids
 */
function oa_core_get_public_spaces() {
  $public_spaces = &drupal_static(__FUNCTION__);
  if (!isset($public_spaces)) {
    $query = db_select('field_data_group_access', 'g')
      ->fields('g', array('entity_id'))
      ->condition('bundle', OA_SPACE_TYPE)
      ->condition('entity_type', 'node')
      ->condition('group_access_value', 0);
    $public_spaces = $query->execute()->fetchCol(0);
  }
  return $public_spaces;
}

/**
 * Return a list of sections within a space
 * Uses access control, so only sections with access are returned
 * @param  int $gid space ID
 * @return keyed array of section data: $array[$nid] = $title
 */
function oa_core_space_sections($gid) {
  $query = db_select('node', 'n');
  $query->rightJoin('og_membership', 'og', 'n.nid = og.etid');
  $query->leftJoin('field_data_field_oa_section_weight', 'w',
        "n.nid = w.entity_id AND w.entity_type = 'node'");
  $query
    ->fields('n', array('nid', 'title'))
    ->condition('n.type', OA_SECTION_TYPE)
    ->condition('og.entity_type', 'node')
    ->condition('og.field_name', OA_SPACE_FIELD)
    ->condition('og.gid', $gid)
    ->orderBy('w.field_oa_section_weight_value')
    ->addTag('node_access');
  $result = $query->execute();
  return $result->fetchAllKeyed(0, 1);
}

/**
 * Return a list of all Groups
 *
 * @return
 *    An array of Groups, keyed by the group nid.
 */
function oa_core_get_all_groups() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'))
      ->condition('n.type', OA_GROUP_TYPE)
      ->addTag('node_access');
  return $query->execute()->fetchAllAssoc('nid');
}

/**
 * Returns the users that are in a space.
 */
function oa_core_get_users_for_space($space_id) {
  $query = db_select('users', 'u');
  $query->innerJoin('og_membership', 'og', 'u.uid = og.etid');
  $query->fields('u', array('uid'))
    ->condition('og.entity_type', 'user')
    ->condition('og.gid', $space_id);
    //->condition('og.group_type', 'node');

  $results = $query->execute()->fetchAllAssoc('uid');
  return user_load_multiple(array_keys($results));
}

/**
 * Return the users that are the intersection of Group and Space membership.
 *
 * @param int $space_id
 *    The Space ID of the Open Atrium site
 * @param $group_id
 *    The Group ID
 * @return
 *    An array of Users keyed by uid
 */
function oa_core_get_group_users_for_space($space_id, $group_id) {
  $query = db_select('users', 'u');
  $query->innerJoin('og_membership', 'og1', 'u.uid = og1.etid');
  $query->innerJoin('og_membership', 'og2', 'u.uid = og2.etid');
  $query->fields('u', array('uid'))
      ->condition('og1.entity_type', 'user')
      ->condition('og1.gid', $space_id)
      ->condition('og1.group_type', 'node')
      ->condition('og2.entity_type', 'user')
      ->condition('og2.gid', $group_id)
      ->condition('og1.group_type', 'node');

  $results = $query->execute()->fetchAllAssoc('uid');
  return user_load_multiple(array_keys($results));
}

/**
 * Return a list of space ids that a user belongs to.
 */
function oa_core_get_user_spaces($uid) {
  $query = db_select('og_membership', 'og')
    ->fields('og')
    ->condition('entity_type', 'user')
    ->condition('etid', $uid);

  $results = $query->execute()->fetchAllAssoc('gid');
  return array_keys($results);
}

/**
 * Returns the space ID that a node belongs to.
 */
function oa_core_get_node_space($nid) {
  $query = db_select('og_membership', 'og')
    ->fields('og')
    ->condition('entity_type', 'node')
    ->condition('etid', $nid);

  $result = $query->execute()->fetchAssoc();
  return empty($result) ? 0 : $result['gid'];
}
