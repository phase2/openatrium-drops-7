<?php
/**
 * @file
 * Provide views handlers for Open Atrium Buttons
 */

/**
 * Field handler to present a link node edit.
 */
class command_buttons_handler_field_edit_entity extends command_buttons_handler_field_view_entity {
  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    if (command_buttons_access('update', $entity)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "admin/structure/command-buttons/view/$entity->bid/edit";
      $this->options['alter']['query'] = drupal_get_destination();

      $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
      return $text;
    }
    else {
      $this->options['alter']['path'] = '';
    }
  }
}
