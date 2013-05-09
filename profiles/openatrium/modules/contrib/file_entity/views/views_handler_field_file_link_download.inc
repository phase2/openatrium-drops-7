<?php

/**
 * @file
 * Definition of views_handler_field_file_link_download.
 */

/**
 * Field handler to present a link to download a file.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_file_link_download extends views_handler_field_file_link {

  /**
   * Renders the link.
   */
  function render_link($file, $values) {
    // Ensure user has access to download this file.
    if (!file_entity_access('download', $file)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "file/$file->fid/download";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Download');
    return $text;
  }
}
