<?php
/**
 * @file
 * panopoly_widgets.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function panopoly_widgets_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'video__link__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['video__link__file_field_file_default'] = $file_display;

  return $export;
}
