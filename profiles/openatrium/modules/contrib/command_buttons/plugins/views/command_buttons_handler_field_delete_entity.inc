<?php
/**
 * @file
 * Provide views handlers for fieldable panel panes
 */

/**
 * Field handler to present a link node delete.
 */
class command_buttons_handler_field_delete_entity extends command_buttons_handler_field_view_entity {
  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    if (command_buttons_access('delete', $entity)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "admin/structure/command-buttons/view/$entity->bid/delete";
      $this->options['alter']['query'] = drupal_get_destination();

      $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
      return $text;
    }
    else {
      $this->options['alter']['path'] = '';
    }
  }
}
