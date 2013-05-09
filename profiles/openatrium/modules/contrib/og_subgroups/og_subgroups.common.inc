<?php

/**
 * @file
 * Common functions used in og_subgroups.
 */

/**
 * Get parent groups.
 *
 * This functions works by traversing the tree from the current
 * group up to the a root group, which has no parents.
 * Since we want every path, even if branches are interconnected,
 * we use forks to take note of the point in the current traversal
 * where a group had more than one parent. When we are at the top
 * (for this traversal) we reset the $parent array only from the fork
 * to the root, and we continue.
 * We also check for recursive loops.
 *
 * @param $entity_type
 *   The entity type. Defaults to 'node'.
 * @param $entity
 *   The entity object or entity ID.
 * @param $paths
 *   An array used for tracking forked paths.
 * @param $reverse
 *   A boolean that determines whether or not to reverse returned array.
 * @param $parents
 *   An array used for tracking all parents.
 */
function og_subgroups_get_parents($entity_type = 'node', $entity, &$paths = array(), $reverse = FALSE, &$parents = array()) {
  static $forks;
  $groups = og_get_entity_groups($entity_type, $entity);
  if (!empty($groups)) {
    // We still have parents to record.
    if (_og_subgroups_count_groups($groups) > 1) {
      // There's a fork.
      $forks[] = count($parents);
    }
    foreach ($groups as $group_type => $data) {
      foreach ($data as $membership_id => $group_id) {
        if (_og_subgroups_parent_search($group_type, $group_id, $parents)) {
          // We found a parent we already found: this is a loop, which is a problem.
          // We skip this parent, and we log this error.
          // This should never happen, as we validate the parent group against loops.
          watchdog('og_subgroups', "Loop detected in group tree: entity type: %type, id %id already present in tree: %parents ", array('%type' => $group_type, '%id' => $group_id, '%parents' => serialize($parents)), WATCHDOG_CRITICAL);
        }
        else {
          // We can safely add this parent to the list.
          $parents[] = array(
            'type' => $group_type,
            'id' => $group_id,
          );
          og_subgroups_get_parents($group_type, $group_id, $paths, $reverse, $parents);
        }
      }
    }
  }
  else {
    $paths[] = $reverse ? array_reverse($parents) : $parents;
    if ($forks) {
      $length = array_pop($forks);
    }
    else {
      $length = 0;
    }
    $parents = array_slice($parents, 0, $length);
  }
}

/**
 * Helper function to count the number of groups in an array of results
 *
 * @param $groups
 *   An array of groups as returned by og_get_entity_groups().
 *
 * @return
 *   The number of groups in a groups array.
 *
 * @see: og_subgroups_get_parents().
 */
function _og_subgroups_count_groups($groups) {
  $count = 0;
  if ($groups) {
    foreach ($groups as $type => $data) {
      $count += count($data);
    }
  }
  return $count;
}

/**
 * Search for an entity among parents (used to detect and avoid loops).
 *
 * @param $entity_type
 *   The entity type. Defaults to 'node'.
 * @param $entity
 *   The entity object or entity ID.
 * @param $parents
 *   An array of parents as returned by og_get_entity_groups().
 *
 * @return
 *   The number of groups in a groups array.
 *
 * @see: og_subgroups_get_parents().
 */
function _og_subgroups_parent_search($entity_type, $entity, $parents) {
  $result = FALSE;
  foreach ($parents as $parent) {
    if ($parent['type'] == $entity_type && $parent['id'] == $entity) {
      $result = TRUE;
      break;
    }
  }
  return $result;
}

/**
 * Add the loaded entity to all the entities in all the paths.
 *
 * @param $paths
 *   An array used for tracking forked paths.
 *
 * @see: og_subgroups_get_parents().
 */
function og_subgroups_populate_paths(&$paths) {
  $entities = array();
  // Store all the entities divided in types.
  foreach ($paths as $path) {
    foreach ($path as $entity) {
      $entities[$entity['type']][$entity['id']] = TRUE;
    }
  }
  // We use entity_load() with multiple ids for performance.
  foreach ($entities as $type => $ids) {
    $loaded_entities[$type] = entity_load($type, array_keys($ids));
  }
  // Save the loaded entities into the paths.
  foreach ($paths as $path_delta => $path) {
    foreach ($path as $entity_delta => $entity) {
      $paths[$path_delta][$entity_delta]['entity'] = $loaded_entities[$entity['type']][$entity['id']];
    }
  }
}

/**
 * Get users that are associated with a group.
 *
 * @param $entity_type
 *   The entity type. Defaults to 'node'.
 * @param $entity
 *   Optional; The entity object or entity ID.
 * @param $states
 *   Optional; Array with the state to return. Defaults to active.
 *
 * @return
 *  An array with the entities' entity type as the key, and array - keyed by
 *  the OG membership ID and the Entity ID as the value. If nothing found,
 *  then an empty array.
 */
function og_subgroups_get_users_group($entity_type = 'node', $entity = NULL, $states = array(OG_STATE_ACTIVE)) {
  $cache = &drupal_static(__FUNCTION__, array());
  if (is_object($entity)) {
    // Get the entity ID.
    list($id) = entity_extract_ids($entity_type, $entity);
  }
  else {
    $id = $entity;
  }
  // Get a string identifier of the states, so we can retrieve it from cache.
  if ($states) {
    sort($states);
    $state_identifier = implode(':', $states);
  }
  else {
    $state_identifier = 0;
  }
  if (isset($cache[$entity_type][$id][$state_identifier])) {
    // Return cached values.
    return $cache[$entity_type][$id][$state_identifier];
  }
  $cache[$entity_type][$id][$state_identifier] = array();
  $query = new EntityFieldQuery();
  $query
  ->entityCondition('entity_type', 'og_membership', '=')
  ->propertyCondition('entity_type', 'user', '=')
  ->propertyCondition('group_type', $entity_type, '=')
  ->propertyCondition('gid', $id, '=');

  if ($states) {
    $query->propertyCondition('state', $states, 'IN');
  }
  $result = $query->execute();
  if (!empty($result['og_membership'])) {
    // Get the group ID from the group membership.
    $og_memberships = og_membership_load_multiple(array_keys($result['og_membership']));
    foreach ($og_memberships as $og_membership) {
      $cache[$entity_type][$id][$state_identifier]['user'][$og_membership->id] = $og_membership->etid;
    }
  }
  return $cache[$entity_type][$id][$state_identifier];
}

/**
 * Get non-users entities that are associated with a group.
 *
 * @param $entity_type
 *   The entity type.
 * @param $entity
 *   The entity object or entity ID.
 *
 * @return
 *  An array with the entities' entity type as the key, and array - keyed by
 *  the OG membership ID and the Entity ID as the value. If nothing found,
 *  then an empty array.
 */
function og_subgroups_get_associated_entities($entity_type, $entity) {
  $cache = &drupal_static(__FUNCTION__, array());
  if (is_object($entity)) {
    // Get the entity ID.
    list($id) = entity_extract_ids($entity_type, $entity);
  }
  else {
    $id = $entity;
  }
  if (isset($cache[$entity_type][$id])) {
    // Return cached values.
    return $cache[$entity_type][$id];
  }
  $cache[$entity_type][$id] = array();
  $query = new EntityFieldQuery();
  $query
  ->entityCondition('entity_type', 'og_membership', '=')
  ->propertyCondition('entity_type', 'user', '!=')
  ->propertyCondition('group_type', $entity_type, '=')
  ->propertyCondition('gid', $id, '=');
  $result = $query->execute();
  if (!empty($result['og_membership'])) {
    // Get the group ID from the group membership.
    $og_memberships = og_membership_load_multiple(array_keys($result['og_membership']));
    foreach ($og_memberships as $og_membership) {
      $cache[$entity_type][$id][$og_membership->entity_type][$og_membership->id] = $og_membership->etid;
    }
  }
  return $cache[$entity_type][$id];
}

/**
 * Return an array of inherited users from the parent groups that
 * allow for user inheritance.
 *
 * @param $entity_type
 *   The entity type. Defaults to 'node'.
 * @param $entity
 *   Optional; The entity object or entity ID.
 * @param $states
 *   Optional; Array with the state to return. Defaults to active.
 *
 * @return
 *  An array with the entities' entity type as the key, and array - keyed by
 *  the OG membership ID and the Entity ID as the value. If nothing found,
 *  then an empty array.
 *
 * @see: og_subgroups_views_pre_render().
 */
function _og_subgroups_get_inherited_users($group_type, $group_id, $states = array(OG_STATE_ACTIVE)) {
  $inherited_users = array();
  $parents = _og_subgroups_get_unique_parents($group_type, $group_id);
  foreach ($parents as $parent) {
    $users = og_subgroups_get_users_group($parent['type'], $parent['id'], $states);
    foreach ($users['user'] as $membership_id => $uid) {
      $roles = og_get_user_roles($parent['type'], $parent['id'], $uid);
      $membership_ids[] = $membership_id;
      $user_ids[] = $uid;
      $inherited_from[$parent['type']][] = $parent['id'];
      $inherited_users[$uid][] = array(
        'uid' => $uid,
        'membership_id' => $membership_id,
        'roles' => $roles,
        'inherited_from' => array(
          'type' => $parent['type'],
          'id' => $parent['id'],
        )
      );
    }
  }
  // Populate the array with *_multiple() functions (performance).
  if (!empty($membership_ids)) {
    $memberships = og_membership_load_multiple($membership_ids);
    $accounts = user_load_multiple($user_ids);
    foreach ($inherited_from as $type => $ids) {
      $inherited_from_entities[$type] = entity_load($type, $ids);
    }
    foreach ($inherited_users as $uid => $inheritance) {
      foreach ($inheritance as $delta => $data) {
        $inherited_users[$uid][$delta]['user'] = $accounts[$uid];
        $inherited_users[$uid][$delta]['membership'] = $memberships[$data['membership_id']];
        $inherited_users[$uid][$delta]['inherited_from']['entity'] = $inherited_from_entities[$data['inherited_from']['type']][$data['inherited_from']['id']];
      }
    }
  }
  return $inherited_users;
}

/**
 * Return an array of all the parent groups, optionally filtered
 * including only the groups that allow for inheritance.
 *
 * @param $group_type
 *   The group type.
 * @param $group_id
 *   The group ID.
 * @param $filter
 *   Boolean value for whether to return only groups that allow for inheritance.
 *
 * @return
 *  An array with the entities' entity type and entity id as the key, and array
 *  containing the entity type, entity id, and entity object as values.
 *  If nothing is found, returns an empty array.
 */
function _og_subgroups_get_unique_parents($group_type, $group_id, $filter = TRUE) {
  $groups = array();
  og_subgroups_get_parents($group_type, $group_id, $paths);
  og_subgroups_populate_paths($paths);
  foreach ($paths as $path) {
    foreach ($path as $group) {
      $entity = $group['entity'];
      if (!$filter || (!empty($entity->{OG_USER_INHERITANCE_FIELD}) && $entity->{OG_USER_INHERITANCE_FIELD}[LANGUAGE_NONE][0]['value'] == 1)) {
        $groups[$group['type'] . '-' . $group['id']] = $group;
      }
    }
  }
  return $groups;
}

/**
 * Return all the groups a user belongs to because of inheritance.
 *
 * @param $account
 *   A user object.
 *
 * @return
 *   An array of inherited groups a user is a member of.
 *
 * @see: og_subgroups_node_grants().
 *
 * @todo: add static cache.
 */
function _og_subgroup_get_user_inherited_groups($account) {
  $children_groups = array();
  $groups = og_get_entity_groups('user', $account);
  if (!empty($groups)) {
    foreach ($groups as $group_type => $gids) {
      foreach ($gids as $gid => $group_id) {
        $group_entity = current(entity_load($group_type, array($group_id)));
        if (isset($group_entity->{OG_USER_INHERITANCE_FIELD}[LANGUAGE_NONE][0]['value']) && $group_entity->{OG_USER_INHERITANCE_FIELD}[LANGUAGE_NONE][0]['value']) {
          _og_subgroups_get_children_groups($group_type, $group_id, $children_groups);
        }
      }
    }
  }
  return $children_groups;
}

/**
 * Helper function for _og_subgroup_get_user_inherited_groups().
 *
 * @param $group_type
 *   The group type.
 * @param $group_id
 *   The group ID.
 * @param $children_groups
 *   An array of children groups.
 *
 * @see: _og_subgroup_get_user_inherited_groups().
 */
function _og_subgroups_get_children_groups($group_type, $group_id, &$children_groups) {
  $children = og_subgroups_get_associated_entities($group_type, $group_id);
  foreach ($children as $children_type => $children_ids) {
    $children_entities = entity_load($children_type, $children_ids);
    foreach ($children_entities as $child_id => $child_entity) {
      if (og_is_group($children_type, $child_entity)) {
        $children_groups[$children_type][$child_id] = $child_entity;
        if (isset($child_entity->{OG_USER_INHERITANCE_FIELD}[LANGUAGE_NONE][0]['value']) && $child_entity->{OG_USER_INHERITANCE_FIELD}[LANGUAGE_NONE][0]['value']) {
          _og_subgroups_get_children_groups($children_type, $child_id, $children_groups);
        }
      }
    }
  }
}
