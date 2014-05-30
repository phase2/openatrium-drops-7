<?php
/**
 * @file
 * Code for Utility functions for OpenAtrium spaces
 */

/**
 * Get the group IDs of all the groups a user is an approved member of.
 * REPLACES og_get_groups_by_user() in OG and returns a list of groups
 * including subspaces
 *
 * @param $account
 *   (optional) The user object to fetch group memberships for. Defaults to the
 *   acting user.
 * @param $group_type
 *   (optional) The entity type of the groups to fetch. By default all group
 *   types will be fetched.
 *
 * @return
 *   An array with the group IDs or an empty array, or returns NULL if there was an error
 */
function oa_core_get_groups_by_user($account = NULL, $group_type = NULL) {
  $user_groups = og_get_groups_by_user($account, $group_type);
  if (!empty($group_type) && !empty($user_groups)) {
    $user_groups = array($group_type => $user_groups);
  }
  if (module_exists('og_subgroups') && !empty($user_groups)) {
    $user_groups = og_subgroups_children_load_multiple($user_groups);
  }

  if (!empty($group_type)) {
    $user_groups = (!empty($user_groups[$group_type])) ? $user_groups[$group_type] : array();
  }
  return $user_groups;
}

/**
 * Returns the current space id context
 * @param  boolean $from_session only use the context stored in $SESSION
 * @return int Space ID
 */
function oa_core_get_space_context($from_session = FALSE) {
  if (variable_get('install_task') !== 'done') {
    // don't run this during the installer
    return 0;
  }
  if ($from_session && defined('OG_SESSION_CONTEXT_ID') && isset($_SESSION[OG_SESSION_CONTEXT_ID])) {
    return $_SESSION[OG_SESSION_CONTEXT_ID];
  }
  $context = og_context('node');
  if (!empty($context['gid'])) {
    return $context['gid'];
  }
  else {
    return og_session_context_get_context();
  }
}

/**
 * Returns the current space id context
 * Returns zero if on the site home page
 * @param  boolean $from_session only use the context stored in $SESSION
 * @return int Space ID
 */
function oa_core_get_space_home_context() {
  if (variable_get('install_task') !== 'done') {
    // don't run this during the installer
    return 0;
  }
  $space_id = oa_core_get_space_context();
  $node = menu_get_object();
  if (drupal_is_front_page() && !(isset($node) && ($node->type == OA_SPACE_TYPE))) {
    return 0;  // front page, not a space page
  }
  return $space_id;
}

/**
 * Returns the current section id context
 * @return int Section ID
 */
function oa_core_get_section_context() {
  if (defined('OA_SESSION_SECTION') && isset($_SESSION[OA_SESSION_SECTION])) {
    return $_SESSION[OA_SESSION_SECTION];
  }
  else {
    return oa_section_get_section_context();
  }
}

/**
 * Return an array of parent nids
 * @param  int $nid    nid of space/group to check
 * @param  string $bundle node type
 * @return array of parent nids
 */
function oa_core_get_parents($nid, $bundle = OA_SPACE_TYPE, $status = NULL) {
  $cache = &drupal_static(__FUNCTION__);

  if (!isset($cache[$nid][$bundle])) {
    $query = db_select('node', 'n');
    $query->leftJoin('og_membership', 'f', "n.nid = f.gid");
    if (isset($status)) {
      $query->condition('n.status', $status);
    }
    $result = $query
      ->fields('n', array('nid'))
      ->condition('f.etid', $nid)
      ->condition('f.entity_type', 'node')
      ->condition('n.type', $bundle)
      ->orderBy('n.title')
      ->addTag('node_access')
      ->execute()
      ->fetchCol(0);
    $cache[$nid][$bundle] = $result;
  }
  return $cache[$nid][$bundle];
}

/**
 * Return an array of children groups
 * @param  int $nid    nid of space/group to check
 * @param  string $bundle node type
 * @return array of children nids
 */
function oa_core_get_groups_by_parent($nid, $bundle = OA_SPACE_TYPE, $status = NULL) {
  $cache = &drupal_static(__FUNCTION__);

  if (!isset($cache[$nid][$bundle])) {

    if ($nid == 0) {
      $query = db_select('node', 'n');
      $query->leftJoin('og_membership', 'f', "n.nid = f.etid");
      if (isset($bundle)) {
        $query->condition('n.type', $bundle);
      }
      if (isset($status)) {
        $query->condition('n.status', $status);
      }
      $result = $query
        ->fields('n', array('nid'))
        ->isNull('f.gid')
        ->orderBy('n.title')
        ->addTag('node_access')
        ->execute()
        ->fetchCol(0);
    }
    else {
      $query = db_select('node', 'n');
      $query->leftJoin('og_membership', 'f', "n.nid = f.etid");
      if (isset($bundle)) {
        $query->condition('n.type', $bundle);
      }
      if (isset($status)) {
        $query->condition('n.status', $status);
      }
      $result = $query
        ->fields('n', array('nid'))
        ->condition('f.gid', $nid)
        ->condition('f.entity_type', 'node')
        ->orderBy('n.title')
        ->addTag('node_access')
        ->execute()
        ->fetchCol(0);
      }
    $cache[$nid][$bundle] = $result;
  }
  return $cache[$nid][$bundle];
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

  $space_id = oa_core_get_space_context();
  $section_id = oa_core_get_section_context();
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
function oa_core_get_titles($ids = array(), $type = '', $sort_field = 'title') {
  $items = array('titles' => array(), 'links' => array(), 'ids' => array());
  if (!empty($ids)) {
    $query = db_select('node', 'n');
    if (!empty($sort_field) && ($sort_field != 'title')) {
      $query->leftJoin('field_data_' . $sort_field, 's',
        "n.nid = s.entity_id AND s.entity_type = 'node'");
    }
    $query
      ->fields('n', array('nid', 'title'))
      ->condition('n.nid', $ids, 'IN');
    if ($sort_field == 'title') {
      $query->orderBy('title');
    }
    elseif (!empty($sort_field)) {
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
function oa_core_get_public_spaces($group_types = array(OA_SPACE_TYPE => OA_SPACE_TYPE), $status = NULL) {
  $public_spaces = &drupal_static(__FUNCTION__);
  if (!isset($public_spaces)) {
    $query = db_select('node', 'n');
    $query->rightJoin('field_data_group_access', 'g', "n.nid = g.entity_id AND g.entity_type = 'node'");
    $query
      ->fields('n', array('nid'))
      ->condition('n.type', $group_types, 'IN')
      ->condition('g.group_access_value', 0);
    if (isset($status)) {
      $query->condition('n.status', $status);
    }
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
function oa_core_space_sections($gid, $status = NULL, $bypass_access_check = FALSE) {
  $query = db_select('node', 'n');
  $query->rightJoin('og_membership', 'og', 'n.nid = og.etid');
  $query->leftJoin('field_data_field_oa_section_weight', 'w',
        "n.nid = w.entity_id AND w.entity_type = 'node'");
  if (isset($status)) {
    $query->condition('n.status', $status);
  }
  $query
    ->fields('n', array('nid', 'title'))
    ->condition('n.type', OA_SECTION_TYPE)
    ->condition('og.entity_type', 'node')
    ->condition('og.field_name', OA_SPACE_FIELD)
    ->condition('og.gid', $gid)
    ->orderBy('w.field_oa_section_weight_value');
  if (!$bypass_access_check) {
    $query->addTag('node_access');
  }
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
function oa_core_get_users_for_space($space_id, $state = OG_STATE_ACTIVE) {
  $space = node_load($space_id);
  $wrapper = entity_metadata_wrapper('node', $space);
  $members = isset($wrapper->{'members__' . $state}) ? $wrapper->{'members__' . $state}->value() : array();
  return (!empty($members)) ? $members : array();
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
  if ($groups = og_get_entity_groups('user', $uid)) {
    return !empty($groups['node']) ? $groups['node'] : array();
  }
  return array();
}

/**
 * Helper function to return the id of the space/group that contains the nid node
 * This function is called a lot, so it needs to be fast
 * Do not use node_load here!
 */
function oa_core_get_group_from_node($nid, $allowed_types = array(OA_SPACE_TYPE, OA_GROUP_TYPE)) {
  $cache = &drupal_static('oa_core_groups', array());
  if (isset($cache[$nid])) {
    return $cache[$nid];
  }

  $query = db_select('og_membership', 'f');
  $query->leftJoin('node', 'n', "n.nid = f.gid");
  $result = $query
    ->fields('f', array('gid'))
    ->condition('f.etid', $nid)
    ->condition('f.group_type', 'node')
    ->condition('f.field_name', OA_SPACE_FIELD)
    ->condition('n.type', $allowed_types, 'IN')
    ->execute()
    ->fetchAssoc();

  if (!empty($result)) {
    $cache[$nid] = $result['gid'];
  }
  else {
    $cache[$nid] = $nid;
  }
  return $cache[$nid];
}

/**
 * Sort function to sort users by name.
 */
function oa_core_sort_users_by_name($u1, $u2) {
  // Get last name for sorting.
  $name1 = !empty($u1->realname) ? oa_core_get_last_word($u1->realname) : $u1->name;
  $name2 = !empty($u2->realname) ? oa_core_get_last_word($u2->realname) : $u2->name;
  return strcasecmp($name1, $name2);
}

function oa_core_get_last_word($string) {
  return ($pos =  strrpos($string, ' ')) ?  substr($string, $pos + 1) : $string;
}

/**
 * Return the name of a user
 */
function oa_core_realname($user) {
  return !empty($user->realname) ? $user->realname : $user->name;
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_core_entity_build_display($entity, $id, $space) {
  if (!empty($entity->nid)) {
    if (node_access('view', $entity)) {
      $display['title'] = l($entity->title, 'node/' . $entity->nid);
    }
    else {
      $display['title'] = t('A @type', array('@type' => array('@type' => node_type_get_name($entity->type))));
    }
    $display['picture'] = '';
    $display['uid'] = 0;
    $display['options'] = array();
  }
  else {
    $display['title'] = l(format_username($entity), 'user/' . $entity->uid);
    $display['uid'] = $entity->uid;
    $display['picture'] = oa_users_picture($entity);
    $display['options'] = array(
      'attributes' => array(
        'class' => array('use-ajax'),
      ),
      'query' => drupal_get_destination() + array(
        'token' => drupal_get_token('node_' . $space->nid . '_' . $entity->uid),
      ),
    );
  }

  return $display;
}

/**
 * Return vocabularies assigned to a specific content type
 */
function oa_core_get_entity_vocabs($entity_type, $bundle) {
  $vocabs = array();
  $fields = field_info_instances($entity_type, $bundle);
  foreach ($fields as $field_name => $field) {
    $info = field_info_field($field_name);
    // handle normal taxonomy_term_reference fields
    if ($info['type'] == 'taxonomy_term_reference') {
      foreach ($info['settings']['allowed_values'] as $value) {
        if (!empty($value['vocabulary'])) {
          $vocabs[$value['vocabulary']] = $value['vocabulary'];
        }
      }
    }
    // also handle entityreference fields pointing to taxonomy
    elseif (($info['type'] == 'entityreference') && ($info['settings']['target_type'] == 'taxonomy_term')) {
      if (!empty($info['settings']['handler_settings']['target_bundles'])) {
        foreach ($info['settings']['handler_settings']['target_bundles'] as $value) {
          $vocabs[$value] = $value;
        }
      }
    }
  }
  return $vocabs;
}

/**
 * Returns the named vocabulary
 * Cannot use core taxonomy_vocabulary_machine_name_load because og_vocab
 * alters the query to only return vocabs associated with the current space
 * see issue https://drupal.org/node/2270529
 */
function oa_core_taxonomy_vocabulary($machine_name) {
  // EntityFieldQuery is not subject to the
  // og_vocab_query_taxonomy_vocabulary_load_multiple_alter() function
  $efq = new EntityFieldQuery();
  $result = $efq->entityCondition('entity_type', 'taxonomy_vocabulary')
    ->propertyCondition('machine_name', $machine_name)
    ->execute();
  return !empty($result['taxonomy_vocabulary']) ? current($result['taxonomy_vocabulary']) : NULL;
}

/**
 * Return terms for a list of vocabularies
 */
function oa_core_get_vocab_terms($vocabs) {
  $options = array();
  foreach ($vocabs as $vocab) {
    if ($vocabulary = oa_core_taxonomy_vocabulary($vocab)) {
      if ($terms = taxonomy_get_tree($vocabulary->vid)) {
        foreach ($terms as $term) {
          $options[$term->tid] = str_repeat('-', $term->depth) . $term->name;
        }
      }
    }
  }
  return $options;
}
