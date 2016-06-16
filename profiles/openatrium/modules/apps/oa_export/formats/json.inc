<?php

/**
 * @file
 * The OA export JSON format handler.
 *
 * Adds JSON format to OA export.
 */

/**
 * Converts a PHP variable into its JavaScript equivalent.
 *
 * We use HTML-safe strings, with several characters escaped.
 *
 * COPIED FROM drupal_json_encode() in common.inc but added JSON_PRETTY_PRINT option
 *
 * @see drupal_json_decode()
 * @see drupal_json_encode_helper()
 * @ingroup php_wrappers
 */
function drupal_json_pretty_print($var) {
  // The PHP version cannot change within a request.
  static $php530;
  static $php540;

  if (!isset($php530)) {
    $php530 = version_compare(PHP_VERSION, '5.3.0', '>=');
  }

  if (!isset($php540)) {
    $php540 = version_compare(PHP_VERSION, '5.4.0', '>=');
  }

  if ($php530) {
    // Encode <, >, ', &, and " using the json_encode() options parameter.
    $options = JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT;
    if ($php540) {
      $options = $options | JSON_PRETTY_PRINT;
    }
    return json_encode($var, $options);
  }

  // json_encode() escapes <, >, ', &, and " using its options parameter, but
  // does not support this parameter prior to PHP 5.3.0.  Use a helper instead.
  include_once DRUPAL_ROOT . '/includes/json-encode.inc';
  return drupal_json_encode_helper($var);
}



/**
 * Export callback.
 *
 * @param array $export
 *   An array of multiple entities and their dependencies.
 *
 * @return string
 *   A json object.
 */
function oa_export_json_export($export) {
  return drupal_json_pretty_print(oa_export_json_encode_objects($export));
}

/**
 * Mark objects as being objects.
 */
function oa_export_json_encode_objects($var) {
  if (is_object($var)) {
    $var = (array) $var;
    $var['#oa_export_object'] = '1';
  }
  if (is_array($var)) {
    foreach ($var as $key => $value) {
      $var[$key] = oa_export_json_encode_objects($value);
    }
  }
  return $var;
}

/**
 * Import callback.
 */
function oa_export_json_import($code_string) {
  return oa_export_json_decode_objects(drupal_json_decode($code_string));
}

/**
 * Recursively convert arrays back to objects.
 *
 * @param array $array
 *   An array that contains arrays which may contain a special key we set in the export.
 *
 * @return array
 *   An array with all objects, that were converted to arrays in the export, converted back to objects.
 */
function oa_export_json_decode_objects($array) {
  if (is_array($array)) {
    foreach ($array as $k => $v) {
      if (is_array($v)) {
        $array[$k] = oa_export_json_decode_objects($v);
      }
    }
    if (isset($array['#oa_export_object'])) {
      unset($array['#oa_export_object']);
      $array = (object) $array;
    }
    return $array;
  }
}
