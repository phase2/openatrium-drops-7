<?php

/**
 * @file
 * The OA export formats file.
 */

/**
 * Returns an array of format handlers for file export.
 */
function oa_export_format_handlers() {
  return array(
    'json' => array(
      '#title' => t('JSON'),
      '#module' => 'oa_export',
      '#file' => drupal_get_path('module', 'oa_export') . '/formats/json.inc',
      '#description' => t(
        '<a href="!json">JavaScript Object Notation</a> code.',
        array(
          '!json' => 'http://en.wikipedia.org/wiki/JSON'
        )
      ),
      '#mime' => 'application/json',
      '#export_callback' => 'oa_export_json_export',
      '#import_callback' => 'oa_export_json_import',
    ),
  );
}
