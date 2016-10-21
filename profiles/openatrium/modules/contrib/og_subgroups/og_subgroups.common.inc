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
 * @param $groups_only
 *   If only group entities should be returned. Huge performance gain
 *   and used internally by this module, but is FALSE by default for legacy
 *   reasons.
 *
 * @return
 *  An array with the entities' entity type as the key, and array - keyed by
 *  the OG membership ID and the Entity ID as the value. If nothing found,
 *  then an empty array.
 */
function og_subgroups_get_associated_entities($entity_type, $entity, $fields = array(), $groups_only = FALSE) {
  $cache = &drupal_static(__FUNCTION__, array());
  $groups_only_key = $groups_only ? 'groups' : 'all';
  if (is_object($entity)) {
    // Get the entity ID.
    list($id) = entity_extract_ids($entity_type, $entity);
  }
  else {
    $id = is_numeric($entity) ? $entity : 0;
  }
  if (isset($cache[$entity_type][$id][$groups_only_key])) {
    // Return cached values.
    return $cache[$entity_type][$id][$groups_only_key];
  }
  $cache[$entity_type][$id][$groups_only_key] = array();

  // Create base query for all content and groups only.
  $query = db_select('og_membership')
  ->condition('entity_type', 'user', '!=')
  ->condition('group_type', $entity_type, '=')
  ->condition('gid', $id, '=');
  if ($fields || ($fields !== FALSE && $fields = variable_get('og_subgroups_default_fields_' . $entity_type, array()))) {
    $query->condition('field_name', $fields, 'IN');
  }

  // Groups only query.
  if ($groups_only) {
    // Get all group bundles of this entity type in an array.
    $group_all_bundles = og_get_all_group_bundle();
    $group_bundles = isset($group_all_bundles[$entity_type]) ? array_keys($group_all_bundles[$entity_type]) : array();
    // Return early if there are no group bundles in this entity type.
    if (empty($group_bundles)) {
      return $cache[$entity_type][$id][$groups_only_key];
    }

    // Gather scheme information from the entity to be used in the query.
    $entity_info = entity_get_info($entity_type);
    $entity_table = $entity_info['base table'];
    $entity_key_id = $entity_info['entity keys']['id'];
    $entity_key_bundle = $entity_info['entity keys']['bundle'];

    // Add entity bundle condition using known group bundles.
    $query->join($entity_table, 'entity', "etid = entity.{$entity_key_id}");
    $query->condition("entity.{$entity_key_bundle}", $group_bundles, 'IN');
  }

  // Add fields and execute. Store results to cache.
  $query->fields('og_membership', array('entity_type', 'id', 'etid'));
  $result = $query->execute();
  if ($result) {
    // Get the group ID from the group membership.
    foreach ($result as $og_membership) {
      $cache[$entity_type][$id][$groups_only_key][$og_membership->entity_type][$og_membership->id] = $og_membership->etid;
    }
  }
  return $cache[$entity_type][$id][$groups_only_key];
}

/**
 * Get all parents that could exist.
 */
function og_subgroups_get_potentional_parents($entity_type, $fields = array()) {
  $cache = &drupal_static(__FUNCTION__, array());
  if (!isset($cache[$entity_type])) {
    if ($cache = cache_get(__FUNCTION__ . '::' . $entity_type)) {
      $cache[$entity_type] = $cache->data;
    }
    else {
      $query = db_select('og_membership')
        ->distinct()
        ->condition('entity_type', 'user', '!=')
        ->condition('group_type', $entity_type, '=');
      if ($fields || ($fields !== FALSE && $fields = variable_get('og_subgroups_default_fields_' . $entity_type, array()))) {
        $query->condition('field_name', $fields, 'IN');
      }
      $query->fields('og_membership', array('gid'));
      $cache[$entity_type] = $query->execute()->fetchCol();
    }
  }
  return $cache[$entity_type];
}

/**
 * Return an array of inherited users from the parent groups that
 * allow for user inheritance.
 *
 * @param $group_type
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
  $parents = og_subgroups_parents_load($group_type, $group_id);
  foreach ($parents as $parent_type => $parent_ids) {
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

/**
 * Same as og_subgroups_parents_load() but takes in an array of groups.
 */
function og_subgroups_parents_load_multiple($groups, $filter = TRUE, $fetch_all = TRUE, $include_current = TRUE, $reset = FALSE) {
  $group_cache = &drupal_static(__FUNCTION__, array());
  $return = array();

  foreach ($groups as $group_type => $group_ids) {
    // Reprocess all if resetting.
    if ($reset) {
      $process = $group_ids;
    }
    else {
      // Only find group_ids we haven't looked up yet.
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
      foreach ($process as $group_id) {
        $key = array_search($group_id, $process);
        unset($process[$key]);

        $cid = _og_subgroups_load_multiple_cid('parents', $group_type, $group_id, $filter);
        $group_cache[$cid] = array();
        if ($parent_groups = og_get_entity_groups($group_type, $group_id)) {
          foreach ($parent_groups as $parent_group_type => $parent_group_ids) {
            // If not filtering, than all ids are valid.
            if (!$filter) {
              $group_cache[$cid][$parent_group_type] = drupal_map_assoc($parent_group_ids);
            }
            // If filtering, need to check the inhertence field.
            else {
              foreach (_og_subgroups_get_field_matching($parent_group_type, $parent_group_ids, OG_USER_INHERITANCE_FIELD, 1) as $parent_group_id) {
                $group_cache[$cid][$parent_group_type][$parent_group_id] = $parent_group_id;
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
        $group_cache[$cid][$group_type] = array();
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

/**
 * Get groups with a a specific value for a field.
 *
 * @param $group_type
 *  The type of entity.
 * @param $group_id
 *  The id of the entity.
 * @param $field
 *  The name of the field to test
 * @param $value
 *  The value of the field to test.
 * @param $key
 *  The specific key for the field.
 */
function _og_subgroups_get_field_matching($group_type, $gids, $field, $value, $key = 'value') {
  $field_info = field_info_field($field);
  if (empty($field_info)) {
    return array();
  }
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $group_type)
    ->entityCondition('entity_id', $gids)
    ->fieldCondition($field, $key, $value)
    ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
  $result = $query->execute();
  return !empty($result[$group_type]) ? array_keys($result[$group_type]) : array();
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
 * @param $filter
 *   Boolean value for whether to return only groups that allow for inheritance.
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
function og_subgroups_children_load_multiple($groups, $filter = TRUE, $fetch_all = TRUE, $include_current = TRUE, $reset = FALSE, $main_level = TRUE) {
  $group_cache = &drupal_static(__FUNCTION__, array());
  $return = array();
  // Deep trees make the regular caching less then effective, so allow
  // performance improvements for sites that have deep trees that may
  // not be best for flatter sites.
  $deep_tree_performance = variable_get('og_subgroups_deep_tree_performance', FALSE);
  $group_cache_all = &drupal_static(__FUNCTION__ . '_all', array());
  // Recursion protection protects both from infinite recursion and from
  // reprocessing the same children if a parent is the child of two groups.
  if ($main_level && $deep_tree_performance) {
    $all_cid = print_r($groups, 1) . ':' . ($filter ? 1 : 0) . ':' . ($fetch_all ? 1 : 0) . ':' . ($include_current ? 1 : 0);
    if ($deep_tree_performance && isset($group_cache_all[$all_cid])) {
      return $group_cache_all[$all_cid];
    }
  }

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
      $inheritated_groups = _og_subgroups_get_field_matching($group_type, $process, OG_USER_INHERITANCE_FIELD, 1);
      foreach ($process as $group_id) {
        $key = array_search($group_id, $process);
        unset($process[$key]);

        $cid = _og_subgroups_load_multiple_cid('children', $group_type, $group_id, $filter);
        // If group does not inherient then no child groups.
        if ($filter && !in_array($group_id, $inheritated_groups)) {
          $group_cache[$cid] = array();
        }
        else {
          $group_cache[$cid] = array();

          foreach (og_subgroups_get_associated_entities($group_type, $group_id, array(), TRUE) as $entity_type => $entity_ids) {
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
        $group_cache[$cid][$group_type] = array();
        cache_set($cid, $group_cache[$cid]);
      }
    }

    // Add them to return array.
    foreach ($group_ids as $group_id) {
      $cid = _og_subgroups_load_multiple_cid('children', $group_type, $group_id, $filter);
      $current_return = $return;
      $return = og_subgroups_merge_groups($return, $group_cache[$cid]);
      // If current group has not been processed, process it's children.
      if ($fetch_all && !isset($return[$group_type][$group_id]) && !empty($group_cache[$cid])) {
        // We want to find children that we haven't processed yet and that could be parents.
        $process_children = array();
        foreach ($group_cache[$cid] as $new_group_type => $children) {
          // If it's in return before current children added, it's already been processed.
          $not_processed = !empty($current_return[$group_type]) ? array_diff($children, $current_return[$group_type]) : $children;
          unset($children[$group_type][$group_id]);
          // If performing for big trees, remove any ones that don't have any children.
          if ($deep_tree_performance && ($potentional_parents = og_subgroups_get_potentional_parents($group_type))) {
            $process_children[$new_group_type] = array_intersect($not_processed, $potentional_parents);
          }
          else {
            $process_children[$new_group_type] = $not_processed;
          }
        }
        // If we're optomizing for large tree, remove any children that aren't parents of anything.
        if (array_filter($process_children)) {
          $return = og_subgroups_merge_groups($return, og_subgroups_children_load_multiple($process_children, $filter, $fetch_all, TRUE, $reset, FALSE));
        }
      }
      // Include current will generally be set for all but the originall caller.
      // which should prevent recurssion.
      if ($include_current) {
        $return[$group_type][$group_id] = $group_id;
      }
    }
  }
  if (isset($all_cid) && $deep_tree_performance) {
    $group_cache_all[$all_cid] = $return;
  }

  return $return;
}
