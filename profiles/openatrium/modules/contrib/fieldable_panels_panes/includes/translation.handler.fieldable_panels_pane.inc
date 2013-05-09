<?php

/**
 * @file
 * Fieldable panels pane translation handler for the translation module.
 */


/**
 * Fieldable panels pane translation handler.
 */
class EntityTranslationFieldablePanelsPaneHandler extends EntityTranslationDefaultHandler {

  public function __construct($entity_type, $entity_info, $entity) {
    parent::__construct('fieldable_panels_pane', $entity_info, $entity);
  }

  /**
   * @see EntityTranslationDefaultHandler::isRevision()
   */
  public function isRevision() {
    return !empty($this->entity->revision);
  }

  /**
   * @see EntityTranslationDefaultHandler::getAccess()
   */
  public function getAccess($op) {
    return fieldable_panels_panes_access($op, $this->entity);
  }
}
