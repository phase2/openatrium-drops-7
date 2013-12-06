<?php

/**
 * @file
 * Common functions used in og_subgroups.
 */

/**
 * Computes the intersection (shared) between two group arrays.
 */
function og_subgroups_intersect_groups($groups, $groups2) {
  $return = array();
  foreach ($groups as $group_type => $ids) {
    if (!empty($groups2[$group_type]) && ($gids = array_intersect($ids, $groups2[$group_type]))) {
      $return[$group_type] = $gids;
    }
  }
  return $return;
}

/**
 * Computes the gids that are in $groups but not in $groups2.
 */
function og_subgroups_diff_groups($groups, $groups2) {
  $return = array();
  foreach ($groups as $group_type => $ids) {
    if (!empty($groups2[$group_type]) && ($gids = array_diff($ids, $groups2[$group_type]))) {
      $return[$group_type] = $gids;
    }
    elseif (empty($groups2[$group_type])) {
      $return[$group_type] = $ids;
    }
  }
  return $return;
}

/**
 * Merges the two group arrays.
 *
 * array_merge_recursive messes up the keys.
 */
function og_subgroups_merge_groups($groups, $groups2) {
  foreach ($groups as $group_type => $ids) {
    if (!empty($groups2[$group_type])) {
      $groups[$group_type] += $groups2[$group_type];
    }
  }

  return $groups + $groups2;
}

/**
 * Return all the groups a user belongs to.
 */
function og_subgroup_user_groups_load($account = NULL, $inheriented_only = TRUE) {
  if (!$account) {
    global $user;
    $account = $user;
  }
  $children_groups = array();
  $groups = og_get_entity_groups('user', $account);
  $new_groups = $groups ? og_subgroups_children_load_multiple($groups, TRUE, TRUE, !$inheriented_only) : array();
  return $new_groups && $inheriented_only ? og_subgroups_diff_groups($new_groups, $groups) : $new_groups;
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
    $id = is_numeric($entity) ? $entity : 0;
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
function og_subgroups_get_associated_entities($entity_type, $entity, $fields = array()) {
  $cache = &drupal_static(__FUNCTION__, array());
  if (is_object($entity)) {
    // Get the entity ID.
    list($id) = entity_extract_ids($entity_type, $entity);
  }
  else {
    $id = is_numeric($entity) ? $entity : 0;
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
  if ($fields || ($fields !== FALSE && $fields = variable_get('og_subgroups_default_fields_' . $entity_type, array()))) {
    $query->propertyCondition('field_name', $fields, 'IN');
  }
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
  foreach (og_subgroups_parents_load($group_type, $group_id) as $parent_type => $parent_ids) {
    foreach ($parent_ids as $parent_id) {
      $users = og_subgroups_get_users_group($parent_type, $parent_id, $states);
      foreach ($users['user'] as $membership_id => $uid) {
        $roles = og_get_user_roles($parent_type, $parent_id, $uid);
        $membership_ids[] = $membership_id;
        $user_ids[] = $uid;
        $inherited_from[$parent_type][] = $parent_id;
        $inherited_users[$uid][] = array(
          'uid' => $uid,
          'membership_id' => $membership_id,
          'roles' => $roles,
          'inherited_from' => array(
            'type' => $parent_type,
            'id' => $parent_id,
          )
        );
      }
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
 * @param $fetch_all
 *   Fetch all ancestors. Set to false for only direct parents.
 * @param $include_current
 *   Include the group given in params.
 * @param $rest
 *   Reset the cache for this group type/id.
 *
 * @return
 *  An array with in the form group type to entity ids.
 */
function og_subgroups_parents_load($group_type, $group_id, $filter = TRUE, $fetch_all = TRUE, $include_current = FALSE, $reset = FALSE) {
  $groups_all = &drupal_static(__FUNCTION__, array());
  $cid = $group_type . '__' . $group_id . '__' . ($filter ? '1' : '0')  . '__' . ($fetch_all ? '1' : '0')  . '__' . ($include_current ? '1' : '0');
  if (!isset($groups_all[$cid]) || $reset) {
    $groups_all[$cid] = og_subgroups_parents_load_multiple(array($group_type => array($group_id)), $filter, $fetch_all, $include_current, $reset);
  }
  return $groups_all[$cid];
}

function og_subgroups_parents_load_multiple($groups, $filter = TRUE, $fetch_all = TRUE, $include_current = TRUE, $reset = FALSE) {
  $group_cache = &drupal_static(__FUNCTION__, array());
  $return = array();

  foreach ($groups as $group_type => $group_ids) {
    // Reprocess all if resetting.
    if ($reset) {
      $process = $group_ids;
    }
    else {
      $process = array();
      foreach ($group_ids as $group_id) {
        $cid = _og_subgroups_load_multiple_cid('parents', $group_type, $group_id, $filter);
        // Fetch from cache if possible.
        if (!isset($group_cache[$cid])) {
          if ($cache = cache_get($cid)) {
            $group_cache[$cid] = $cache->data;
          }
          else {
            $process[] = $group_id;
          }
        }
      }
    }
    if ($process) {
      foreach (entity_load($group_type, $process) as $group_id => $entity) {
        $key = array_search($group_id, $process);
        unset($process[$key]);

        $cid = _og_subgroups_load_multiple_cid('parents', $group_type, $group_id, $filter);
        $group_cache[$cid] = array();
        if ($parent_groups = og_get_entity_groups($group_type, $entity)) {
          foreach ($parent_groups as $parent_group_type => $parent_group_ids) {
            // If not filtering, than all ids are valid.
            if (!$filter) {
              $group_cache[$cid][$parent_group_type] = drupal_map_assoc($parent_group_ids);
            }
            // If filtering, need to check the inhertence field.
            else {
              foreach (entity_load($parent_group_type, $parent_group_ids) as $parent_group_id => $parent_entity) {
                $wrapper = entity_metadata_wrapper($parent_group_type, $parent_group_id);
                if (empty($wrapper->{OG_USER_INHERITANCE_FIELD}) || $wrapper->{OG_USER_INHERITANCE_FIELD}->value()) {
                  $group_cache[$cid][$parent_group_type][$parent_group_id] = $parent_group_id;
                }
              }
            }
          }
        }
        cache_set($cid, $group_cache[$cid]);
      }

      // Any leftovers are from a failed entity_load, so just set blank arrays
      // for them.
      foreach ($process as $group_id) {
        $cid = _og_subgroups_load_multiple_cid('parents', $group_type, $group_id, $filter);
        $group_cache[$cid][$entity_type] = array();
        cache_set($cid, $group_cache[$cid]);
      }

    }
    // Add them to return array.
    foreach ($group_ids as $group_id) {
      $cid = _og_subgroups_load_multiple_cid('parents', $group_type, $group_id, $filter);
      $return = og_subgroups_merge_groups($return, $group_cache[$cid]);
      // If current group has not been processed, process it's children.
      if ($fetch_all && !isset($return[$group_type][$group_id]) && !empty($group_cache[$cid])) {
        $return = og_subgroups_merge_groups($return, og_subgroups_parents_load_multiple($group_cache[$cid], $filter, $fetch_all, TRUE, $reset));
      }
      // Include current will be set for all child calls, which should generally prevent recurssion.
      if ($include_current) {
        $return[$group_type][$group_id] = $group_id;
      }
    }
  }

  return $return;
}

function _og_subgroups_load_multiple_cid($type, $group_type, $group_id, $filter) {
  return 'og_subgroups_' . $type . '_load_multiple__' . $group_type . '__' . $group_id . '__' . ($filter ? 'filtered' : 'all');
}

/**
 * Gets the children of the given group including current group.
 *
 * @param $group_type
 *  The type of entity.
 * @param $group_id
 *  The id of the entity.
 * @param $fetch_all
 *   Fetch all including grandchildren and below.
 * @param $include_current
 *  Include the group that was given as paramaters.
 * @param $reset
 *   Reset the cache for this entity.
 */
function og_subgroups_children_load($group_type, $group_id, $filter = TRUE, $fetch_all = TRUE, $include_current = FALSE, $reset = FALSE) {
  $groups_all = &drupal_static(__FUNCTION__, array());
  $cid = $group_type . '__' . $group_id . '__' . ($filter ? '1' : '0')  . '__' . ($fetch_all ? '1' : '0')  . '__' . ($include_current ? '1' : '0');
  if (!isset($groups_all[$cid]) || $reset) {
    $groups_all[$cid] = og_subgroups_children_load_multiple(array($group_type => array($group_id)), $filter, $fetch_all, $include_current, $reset);
  }
  return $groups_all[$cid];
}

/**
 * Get the inheriented groups + current group.
 */
function og_subgroups_children_load_multiple($groups, $filter = TRUE, $fetch_all = TRUE, $include_current = TRUE, $reset = FALSE) {
  $group_cache = &drupal_static(__FUNCTION__, array());
  $return = array();

  foreach ($groups as $group_type => $group_ids) {
    // Reprocess all if resetting.
    if ($reset) {
      $process = $group_ids;
    }
    else {
      $process = array();
      foreach ($group_ids as $group_id) {
        $cid = _og_subgroups_load_multiple_cid('children', $group_type, $group_id, $filter);
        // Fetch from cache if possible.
        if (!isset($group_cache[$cid])) {
          if ($cache = cache_get($cid)) {
            $group_cache[$cid] = $cache->data;
          }
          else {
            $process[] = $group_id;
          }
        }
      }
    }
    if ($process) {
      foreach (entity_load($group_type, $process) as $group_id => $entity) {
        $key = array_search($group_id, $process);
        unset($process[$key]);

        $cid = _og_subgroups_load_multiple_cid('children', $group_type, $group_id, $filter);
        // If group does not inherient then no child groups.
        $wrapper = entity_metadata_wrapper($group_type, $group_id);
        if ($filter && (empty($wrapper->{OG_USER_INHERITANCE_FIELD}) || !$wrapper->{OG_USER_INHERITANCE_FIELD}->value())) {
          $group_cache[$cid] = array();
        }
        else {
          $group_cache[$cid] = array();

          foreach (og_subgroups_get_associated_entities($group_type, $group_id) as $entity_type => $entity_ids) {
            $group_cache[$cid][$entity_type] = drupal_map_assoc($entity_ids);
          }
          cache_set($cid, $group_cache[$cid]);
        }
      }

      // Any leftovers are from a failed entity_load, so just set blank arrays
      // for them.
      foreach ($process as $key => $group_id) {
        unset ($process[$key]);
        $cid = _og_subgroups_load_multiple_cid('children', $group_type, $group_id, $filter);
        $group_cache[$cid][$entity_type] = array();
        cache_set($cid, $group_cache[$cid]);
      }
    }
    // Add them to return array.
    foreach ($group_ids as $group_id) {
      $cid = _og_subgroups_load_multiple_cid('children', $group_type, $group_id, $filter);
      $return = og_subgroups_merge_groups($return, $group_cache[$cid]);
      // If current group has not been processed, process it's children.
      if ($fetch_all && !isset($return[$group_type][$group_id]) && !empty($group_cache[$cid])) {
        $return = og_subgroups_merge_groups($return, og_subgroups_children_load_multiple($group_cache[$cid], $filter, $fetch_all, TRUE, $reset));
      }
      // Include current will generally be set for all but the originall caller.
      // which should prevent recurssion.
      if ($include_current) {
        $return[$group_type][$group_id] = $group_id;
      }
    }
  }

  return $return;
}
