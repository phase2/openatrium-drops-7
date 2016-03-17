<?php
/**
 * @file
 * oa_export.module.info.inc
 *
 * Supports writing a new or updating an existing MODULE.info file.
 */

/**
 * Helper function to return the values for the MODULE.info file for a new module.
 *
 * @param $form_state
 *   A keyed array containing the current state of the form.
 *
 * @return array
 */
function oa_export_new_module_info($form_state) {
  return array(
    'name' => $form_state['values']['name'],
    'description' => $form_state['values']['description'],
    'core' => DRUPAL_CORE_COMPATIBILITY,
    'package' => $form_state['values']['package'],
    'version' => $form_state['values']['version'],
  );
}

/**
 * Helper function to create the actual MODULE.info file.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 *
 * @return bool
 *   Whether the file was successfully created or not.
 */
function oa_export_create_new_info_file($form, $form_state) {
  // Data the will be written to the info file.
  $info = oa_export_new_module_info($form_state);
  $filename = $form['#module_file'];
  $output = '';
  foreach ($info as $k => $v) {
    if (!empty($v)) {
      $output .= "$k = $v\n";
    }
  }
  // We only need a dependency on oa_export for now.
  $output .= "dependencies[] = oa_export";

  // Write the info file.
  if (file_put_contents($filename, $output, FILE_APPEND|FILE_TEXT) === FALSE) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}

/**
 * Updates an existing info file.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 *
 * @return bool
 */
function oa_export_update_existing_info_file($form, $form_state) {
  $file = $form['#module_file'];
  // Check first to see if the module has an info file. It may not exist or just be an empty file.
  if (!file_exists($file) || filesize($file) == 0) {
    oa_export_create_new_info_file($form, $form_state);
  }
  else {
    // Pattern to search for.
    $pattern = "/dependencies\[\] = oa_export/";
    // Check for "dependencies[] = oa_export" line in the info file
    if (!oa_export_search_file($file, $pattern)) {
      // We need to add a dependency on oa_export.
      $output = "\ndependencies[] = oa_export";
      // Add the line to the info file.
      if (file_put_contents($file, $output, FILE_APPEND|FILE_TEXT) === FALSE) {
        return FALSE;
      }
      else {
        return TRUE;
      }
    }
    else {
      // The module already has a dependency on oa_export.
      return TRUE;
    }
  }
}
