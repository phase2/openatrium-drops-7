<?php
/**
 * @file
 * Provide views handlers for Open Atrium Buttons
 */

/**
 * Filter by node type
 */
class command_buttons_handler_filter_bundle extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Bundles');
      $this->value_options = command_buttons_get_bundle_labels();
    }
  }
}
