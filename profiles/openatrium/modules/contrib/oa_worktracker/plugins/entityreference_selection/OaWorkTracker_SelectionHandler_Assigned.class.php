<?php
/**
 * @file
 * Contains the OaWorkTracker_SelectionHandler_Assigned class.
 */

/**
 * An EntityReference selection plugin for Work Tracker assigned users.
 *
 * It show the appropriate list of users based on the Work Tracker settings
 * for assigned users for the current Space.
 */
class OaWorkTracker_SelectionHandler_Assigned implements EntityReference_SelectionHandler {
  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    if ($field['settings']['target_type'] !== 'user') {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }

    return new OaWorkTracker_SelectionHandler_Assigned();
  }

  protected function __construct() {
    // We don't need to construct anything!
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    return array();
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $gid = oa_core_get_space_context();
    $space = node_load($gid);

    $type = variable_get_value('oa_worktracker_assigned_to_users');
    if ($type === OA_WORKTRACKER_ASSIGN_TO_INHERITED_USERS && !module_exists('oa_subspaces')) {
      $type = OA_WORKTRACKER_ASSIGN_TO_ONLY_LOCAL_USERS;
    }

    $uids = array();
    switch ($type) {
      case OA_WORKTRACKER_ASSIGN_TO_INHERITED_USERS:
        $uids = og_subgroups_get_users_group('node', $space);
        $uids = $uids['user'];
        $inherited = _og_subgroups_get_inherited_users('node', $gid);
        foreach ($inherited as $inherited_uid => $data) {
          $uids[] = $inherited_uid;
        }
        break;

      case OA_WORKTRACKER_ASSIGN_TO_ONLY_LOCAL_USERS:
        $query = new EntityFieldQuery();
        $query
          ->entityCondition('entity_type', 'og_membership')
          ->propertyCondition('group_type', 'node', '=')
          ->propertyCondition('gid', $gid, '=')
          ->propertyCondition('entity_type', 'user', '=')
          ->propertyCondition('state', OG_STATE_ACTIVE, '=');
        $result = $query->execute();
        if (!empty($result['og_membership'])) {
          $og_memberships = og_membership_load_multiple(array_keys($result['og_membership']));
          foreach ($og_memberships as $og_membership) {
            $uids[] = $og_membership->etid;
          }
        }
        break;

      case OA_WORKTRACKER_ASSIGN_TO_ANY_USERS:
        $query = db_select('users', 'u')
          ->fields('u', array('uid'))
          ->condition('status', 1);
        $uids = $query->execute()->fetchCol();
        break;
    }

    $options = array('user' => array());
    if (!empty($uids)) {
      // Get the user label and make sure that the user can access the space.
      $users = user_load_multiple($uids);
      foreach ($users as $uid => $account) {
        if (node_access('view', $space, $account)) {
          $options['user'][$uid] = check_plain($this->getLabel($account));
        }
      }
      asort($options['user']);
    }
    return $options;
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  public function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {
    $options = $this->getReferencableEntities();
    return count($options['user']);
  }

  /**
   * Implements EntityReferenceHandler::validateReferencableEntities().
   */
  public function validateReferencableEntities(array $ids) {
    /*
    $validated = array();
    if ($ids) {
      // Make sure these are valid values and filter out those that aren't.
      $options = $this->getReferencableEntities();
      foreach ($ids as $id) {
        if (isset($options['user'][$id])) {
          $validated[] = $id;
        }
      }
    }
    */

    // TODO: The above should work, but for some reason we're getting
    // the wrong Space context sometimes. For now, assume anything that
    // the form allowed to submit is valid.
    $validated = $ids;
    return $validated;
  }

  /**
   * Implements EntityReferenceHandler::validateAutocompleteInput().
   *
   * Copied from EntityReference_SelectionHandler_Generic::validateAutocompleteInput().
   */
  public function validateAutocompleteInput($input, &$element, &$form_state, $form) {
    $entities = $this->getReferencableEntities($input, '=', 6);
    if (empty($entities)) {
      // Error if there are no entities available for a required field.
      form_error($element, t('There are no entities matching "%value"', array('%value' => $input)));
    }
    elseif (count($entities) > 5) {
      // Error if there are more than 5 matching entities.
      form_error($element, t('Many entities are called %value. Specify the one you want by appending the id in parentheses, like "@value (@id)"', array(
        '%value' => $input,
        '@value' => $input,
        '@id' => key($entities),
      )));
    }
    elseif (count($entities) > 1) {
      // More helpful error if there are only a few matching entities.
      $multiples = array();
      foreach ($entities as $id => $name) {
        $multiples[] = $name . ' (' . $id . ')';
      }
      form_error($element, t('Multiple entities match this reference; "%multiple"', array('%multiple' => implode('", "', $multiples))));
    }
    else {
      // Take the one and only matching entity.
      return key($entities);
    }
  }

  /**
   * Implements EntityReferenceHandler::entityFieldQueryAlter().
   */
  public function entityFieldQueryAlter(SelectQueryInterface $query) {
  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    return entity_access('view', 'user', $entity) ? entity_label('user', $entity) : t('- Restricted access -');
  }

}
