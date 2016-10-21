<?php


/**
 * @file
 * OG example selection handler.
 */

class OgSubgroupsSelectionHandler extends OgSelectionHandler {

  /**
   * Overrides OgSelectionHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new OgSubgroupsSelectionHandler($field, $instance, $entity_type, $entity);
  }

  /**
   * Override EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);
    return $form;
  }

  /**
   * Overrides OgSelectionHandler::buildEntityFieldQuery().
   */
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    global $user;
    $group_type = $this->field['settings']['target_type'];

    if (empty($this->instance['field_mode']) || $group_type != 'node') {
      return parent::buildEntityFieldQuery($match, $match_operator);
    }

    $handler = EntityReference_SelectionHandler_Generic::getInstance($this->field, $this->instance, $this->entity_type, $this->entity);
    $query = $handler->buildEntityFieldQuery($match, $match_operator);

    // FIXME: http://drupal.org/node/1325628
    unset($query->tags['node_access']);

    // FIXME: drupal.org/node/1413108
    unset($query->tags['entityreference']);

    $query->addTag('entity_field_access');
    $query->addTag('og');

    $group_type = $this->field['settings']['target_type'];
    $entity_info = entity_get_info($group_type);

    if (!field_info_field(OG_GROUP_FIELD)) {
      // There are no groups, so falsify query.
      $query->propertyCondition($entity_info['entity keys']['id'], -1, '=');
      return $query;
    }

    // Show only the entities that are active groups.
    $query->fieldCondition(OG_GROUP_FIELD, 'value', 1, '=');

    if (empty($this->instance['field_mode'])) {
      return $query;
    }

    $field_mode = $this->instance['field_mode'];
    $user_groups = og_subgroup_user_groups_load(NULL, FALSE);
    $user_groups = isset($user_groups['node']) ? $user_groups['node'] : array();
    $user_groups = array_merge($user_groups, $this->getGidsForCreate());

    // Show the user only the groups they belong to.
    if ($field_mode == 'default') {
      if ($user_groups && !empty($this->instance) && $this->instance['entity_type'] == 'node') {
        // Determine which groups should be selectable.
        $node = $this->entity;
        $node_type = $this->instance['bundle'];
        $ids = array();
        foreach ($user_groups as $gid) {
          // Check if user has "create" permissions on those groups.
          // If the user doesn't have create permission, check if perhaps the
          // content already exists and the user has edit permission.
          if (og_user_access($group_type, $gid, "create $node_type content")) {
            $ids[] = $gid;
          }
          elseif (!empty($node->nid) && (og_user_access($group_type, $gid, "update any $node_type content") || ($user->uid == $node->uid && og_user_access($group_type, $gid, "update own $node_type content")))) {
            $node_groups = isset($node_groups) ? $node_groups : og_get_entity_groups('node', $node->nid);
            if (in_array($gid, $node_groups['node'])) {
              $ids[] = $gid;
            }
          }
        }
      }
      else {
        $ids = $user_groups;
      }

      if ($ids) {
        $query->propertyCondition($entity_info['entity keys']['id'], $ids, 'IN');
      }
      else {
        // User doesn't have permission to select any group so falsify this
        // query.
        $query->propertyCondition($entity_info['entity keys']['id'], -1, '=');
      }
    }
    elseif ($field_mode == 'admin' && $user_groups) {
      // Show only groups the user doesn't belong to.
      if (!empty($this->instance) && $this->instance['entity_type'] == 'node') {
        // Don't include the groups, the user doesn't have create
        // permission.
        $node_type = $this->instance['bundle'];
        foreach ($user_groups as $delta => $gid) {
          if (!og_user_access($group_type, $gid, "create $node_type content")) {
            unset($user_groups[$delta]);
          }
        }
      }
      if ($user_groups) {
        $query->propertyCondition($entity_info['entity keys']['id'], $user_groups, 'NOT IN');
      }
    }

    return $query;
  }

  /**
   * Override EntityReferenceHandler::getGidsForCreate().
   */
  private function getGidsForCreate() {
    if ($this->instance['entity_type'] != 'node') {
      return array();
    }

    if (!empty($this->entity->nid)) {
      // Existing node.
      return array();
    }

    if (!module_exists('entityreference_prepopulate') || empty($this->instance['settings']['behaviors']['prepopulate'])) {
      return array();
    }

    // Don't try to validate the IDs.
    if (!$ids = entityreference_prepopulate_get_values($this->field, $this->instance, FALSE)) {
      return array();
    }
    $node_type = $this->instance['bundle'];
    foreach ($ids as $delta => $id) {
      if (!is_numeric($id) || !$id || !og_user_access($this->field['settings']['target_type'], $id, "create $node_type content")) {
        unset($ids[$delta]);
      }
    }
    return $ids;
  }
}
