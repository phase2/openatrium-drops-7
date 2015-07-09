<?php
/**
 * @file
 * Variable Realm controller.
 */

/**
 * Controller for Language realms.
 */
class OgVariableRealm extends VariableRealmDefaultController {
  protected $entity_type = 'node';

  protected function makeRequestKey($entity_type, $gid) {
    return $entity_type . '_' . $gid;
  }

  /**
   * Implementation of VariableRealmControllerInterface::getRequestKey().
   */
  public function getRequestKey() {
    if ($context = og_context($this->entity_type)) {
      return $this->makeRequestKey($context['group_type'], $context['gid']);
    }
  }

  /**
   * Implementation of VariableRealmControllerInterface::getAllKeys().
   */
  public function getAllKeys() {
    $realms = array();
    foreach (og_get_all_group($this->entity_type) as $entity_id) {
      $entity = current(entity_load($this->entity_type, array($entity_id)));
      if (entity_access('update', $this->entity_type, $entity)) {
        $label = entity_label($this->entity_type, $entity);
        $realms[$this->makeRequestKey($this->entity_type, $entity_id)] = $label;
      }
    }
    return $realms;
  }

  /**
   * Get single variable.
   *
   * @param $name
   *   Variable name
   * @param $default
   *   Default value
   */
  public function variable_get($name, $default = NULL) {
    $this->variable_init();
    return isset($this->variables[$name]) ? $this->variables[$name] : $default;
  }
}

/**
 * @file
 * Variable realm controller
 */

class OgVariableStoreRealmStore extends VariableStoreRealmStore {
  private $parent_variables = array();
  private $deleted = array();

  /**
   * Default to global to get around form fields default to hard default.
   */
  public function variable_get($name, $default = NULL) {
    $this->variable_init();
    // This gets around the hiccup that $conf has the old value right after
    // delete os variable_realm_refresh resets it to that old value.
    $was_deleted = FALSE;
    if (!empty($this->deleted[$name])) {
      $was_deleted = TRUE;
      unset($this->deleted[$name]);
    }
    return isset($this->variables[$name]) ? $this->variables[$name] :
      (isset($this->parent_variables[$name]) ? $this->parent_variables[$name] :
        // If variable deleted, don't want to use $conf as has old value.
        ($was_deleted ? $default : variable_get($name, $default)));
  }

  /**
   * Delete single variable.
   *
   * @param $name
   *   Variable name
   */
  public function variable_del($name) {
    if (isset($this->variables[$name])) {
      $this->deleted[$name] = $name;
      // Since $variables is a reference we just need to delete the store value.
      variable_store_del($this->realm, $this->key, $name);
    }
  }

  /**
   * Initialize realm.
   */
  public function variable_init() {
    if (!isset($this->variables)) {
      // We need to traverse the key to get parent ones also.
      $keys = $this->getAllKeys();
      // We need to keep this by reference so changes are reflected.
      $this->variables = &variable_store($this->realm, array_shift($keys));
      $this->parent_variables = array();
      foreach ($keys as $key) {
        // variable_store is cached so likely fetching cached info.
        $this->parent_variables += variable_store($this->realm, $key);
      }
    }
  }

  /**
   * List all current variable values.
   */
  public function variable_list() {
    $this->variable_init();
    return $this->variables + $this->parent_variables;
  }

  /**
   * Get all the keys that should fetch for set key.
   */
  private function getAllKeys() {
    $keys =  array($this->key);
    if (module_exists('og_subgroups')) {
      list(, $nid) = explode('_', $this->key);
      // We fetch one level at time to perserve hierarchy.
      $parents = og_subgroups_parents_load('node', $nid, TRUE, FALSE);
      while (!empty($parents['node'])) {
        $parent = reset($parents['node']);
        $keys[] = 'node_' . $parent;
        // og_subgroups_parents_load is cached well.
        $parents = og_subgroups_parents_load('node', $parent, TRUE, FALSE);
      }
    }
    return $keys;
  }
}
