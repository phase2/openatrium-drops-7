<?php
/**
 * @file
 * Provide views handlers for Open Atrium Wizards
 */

/**
 * Field handler to present a link node edit.
 */
class oa_wizard_handler_field_edit_entity extends oa_wizard_handler_field_view_entity {
  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    if (oa_wizard_access('update', $entity)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "admin/structure/wizards/view/$entity->wizard_id/edit";
      $this->options['alter']['query'] = drupal_get_destination();

      $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
      return $text;
    }
    else {
      $this->options['alter']['path'] = '';
    }
  }
}
