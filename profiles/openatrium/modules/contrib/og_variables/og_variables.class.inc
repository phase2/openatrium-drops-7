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

class VariableStoreRealmStoreDefaultGlobal extends VariableStoreRealmStore {
  /**
   * Default to global to get around form fields default to hard default.
   */
  public function variable_get($name, $default = NULL) {
    $this->variable_init();
    return isset($this->variables[$name]) ? $this->variables[$name] : variable_get($name, $default);
  }
}

