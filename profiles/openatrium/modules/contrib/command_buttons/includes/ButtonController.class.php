<?php
/**
 * @file
 *
 * Contains the controller class for the OA Button entity.
 */

/**
 * Entity controller class.
 */
class ButtonController extends EntityAPIControllerExportable {
  public $entity;

  /**
   * Overrides DrupalDefaultEntityController::resetCache().
   */
  public function resetCache(array $ids = NULL) {
    if (module_exists('entitycache')) {
      EntityCacheControllerHelper::resetEntityCache($this, $ids);
    }
    parent::resetCache($ids);
  }

  /**
   * Overrides DrupalDefaultEntityController::load().
   */
  public function load($ids = array(), $conditions = array()) {
    if (module_exists('entitycache')) {
      return EntityCacheControllerHelper::entityCacheLoad($this, $ids, $conditions);
    }
    else {
      return parent::load($ids, $conditions);
    }
  }

  public function access($op, $entity = NULL, $account = NULL) {
    if ($op !== 'create' && !$entity) {
      return FALSE;
    }

    // The administer permission is a blanket override.
    if (user_access('administer command buttons')) {
      return TRUE;
    }

    switch ($op) {
      case 'create':
        return user_access('create button ' . $entity);

      case 'view':
        return TRUE;

      case 'update':
        ctools_include('context');
        return user_access('edit button ' . $entity->bundle);

      case 'delete':
        ctools_include('context');
        return user_access('delete button ' . $entity->bundle);

    }

    return FALSE;
  }

  public function save($entity) {
    $entity = (object) $entity;

    // Determine if we will be inserting a new entity.
    $entity->is_new = !(isset($entity->bid) && is_numeric($entity->bid));

    $transaction = db_transaction();

    // Set the timestamp fields.
    if (empty($entity->created)) {
      $entity->created = REQUEST_TIME;
    }

    $entity->changed = REQUEST_TIME;

    field_attach_presave('command_button', $entity);
    module_invoke_all('entity_presave', $entity, 'command_button');

    try {
      if (!$entity->is_new) {
        drupal_write_record('command_buttons', $entity, 'bid');
        field_attach_update('command_button', $entity);
        module_invoke_all('entity_update', $entity, 'command_button');
      }
      else {
        drupal_write_record('command_buttons', $entity);
        field_attach_insert('command_button', $entity);
        module_invoke_all('entity_insert', $entity, 'command_button');
      }

      return $entity;
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception('command_button', $e);
    }

    return FALSE;
  }

  public function view($entities, $view_mode = 'full', $langcode = NULL, $page = NULL) {
    if (!isset($langcode)) {
      $langcode = $GLOBALS['language_content']->language;
    }

    // Ensure entities is an array.
    if (!is_array($entities)) {
      $entities = array($entities);
    }

    $build = array();

    foreach ($entities as $entity) {
      // Populate $entity->content with a render() array.
      $this->buildContent($entity, $view_mode, $langcode);
      // Allow modules to modify the structured button.
      $type = 'command_button';
      drupal_alter(array('command_buttons_view', 'entity_view'), $entity->content, $type);
      $build[] = $entity->content;

      // We don't need duplicate rendering info in $entity->content.
      unset($entity->content);
    }


    return $build;
  }

  /**
   * Builds a structured array representing the button content.
   *
   * @param object $entity
   *   A button entity.
   * @param string $view_mode
   *   View mode, e.g. 'full', 'teaser'...
   * @param string $langcode
   *   (optional) A language code to use for rendering. Defaults to the global
   *   content language of the current request.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL) {
    if (!isset($langcode)) {
      $langcode = $GLOBALS['language_content']->language;
    }

    // Remove previously built content, if exists.
    $entity->content = array();

    // Allow modules to change the view mode.
    $context = array(
      'entity_type' => 'command_button',
      'entity' => $entity,
      'langcode' => $langcode,
    );
    drupal_alter('entity_view_mode', $view_mode, $context);

    // Build fields content.
    field_attach_prepare_view('command_button', array($entity->bid => $entity), $view_mode, $langcode);
    entity_prepare_view('command_button', array($entity->bid => $entity), $langcode);
    $entity->content += field_attach_view('command_button', $entity, $view_mode, $langcode);

    // Allow modules to make their own additions to the entity.
    module_invoke_all('command_button_view', $entity, $view_mode, $langcode);
    module_invoke_all('entity_view', $entity, 'command_button', $view_mode, $langcode);

    // Make sure the current view mode is stored if no module has already
    // populated the related key.
    $entity->content += array('#view_mode' => $view_mode);
  }

  public function delete($bids) {
    $transaction = db_transaction();
    if (!empty($bids)) {
      $entities = command_buttons_load_multiple($bids, array());

      try {
        foreach ($entities as $bid => $entity) {
          // Call the entity-specific callback (if any):
          module_invoke_all('entity_delete', $entity, 'command_button');
          field_attach_delete('command_button', $entity);
        }

        // Delete after calling hooks so that they can query entity tables as needed.
        db_delete('command_buttons')
          ->condition('bid', $bids, 'IN')
          ->execute();

      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('command_button', $e);
        throw $e;
      }

      // Clear the page and block and entity_load_multiple caches.
      entity_get_controller('command_button')->resetCache();
    }
  }

  public function create(array $values = array()) {
    $entity = (object) array(
      'bundle' => $values['bundle'],
      'language' => LANGUAGE_NONE,
      'is_new' => TRUE,
    );

    // Ensure basic fields are defined.
    $values += array(
      'bundle' => 'button',
      'title' => '',
      'name' => '',
      'module' => 'command_buttons',
      'status' => 1,
    );

    // Apply the given values.
    foreach ($values as $key => $value) {
      $entity->$key = $value;
    }

    return $entity;
  }
}
