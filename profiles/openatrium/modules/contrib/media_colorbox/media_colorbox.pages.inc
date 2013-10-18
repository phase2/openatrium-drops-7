<?php
/**
 * @file
 * Media Colorbox pages callbacks.
 */

/**
 * Menu callback; Displays a given file inside a colorbox.
 */
function media_colorbox_callback($file, $view_mode, $langcode) {
  // access already handled in file_entity_access
  $fview = file_view($file, $view_mode, $langcode);
  $text = drupal_render($fview);
  print $text;
}
