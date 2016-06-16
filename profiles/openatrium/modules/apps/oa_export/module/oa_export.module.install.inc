<?php
/**
 * @file
 * oa_export.module.install.inc
 *
 * Supports writing a new or updating an existing MODULE.install file.
 */

/**
 * Builds a schema version for an update hook written to a new MODULE.install file.
 *
 * @param int $version
 *   An existing schema version if one exists.
 *
 * @return string
 *   The schema version for an update hook in a new MODULE.install file.
 */
function oa_export_get_new_schema_version($version = 0) {
  if ($version > 0) {
    return $version + 1;
  }
  list($core) = explode('.', DRUPAL_CORE_COMPATIBILITY);
  // The schema version to use for hook_update_N().
  return $core . '000';
}

/**
 * Creates a new install file for a module.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 * @param bool $reset
 *   This allows us to completely overwrite the existing file and create a new one. This only happens after the file has
 *   been searched and we didn't find hook_install() or an implementation of hook_update_N(). The file could contain
 *   other functions but they would be useless without at least one of the former.
 *
 * @return bool
 *   Whether the file was successfully created or not.
 */
function oa_export_create_new_install_file($form, $form_state, $reset = FALSE) {
  $module_name = $form['#module_name'];
  $filename = $form['#module_file'];
  // The schema version to use for hook_update_N().
  $version = oa_export_get_new_schema_version();
  // Write an implementation of hook_install().
  if ($success = oa_export_write_hook_install($filename, $module_name, $version, $reset)) {
    // Write an implementation of hook_update_N().
    $success = oa_export_write_update_hook($filename, $module_name, $version);
  }
  return $success;
}

/**
 * Reads through an existing install file so we better know how to write our changes to it.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 *
 * @return bool
 *    Whether or not the file was successfully written to.
 *
 * @see oa_export_update_module_file().
 */
function oa_export_update_existing_install_file($form, $form_state) {
  $module_name = $form['#module_name'];
  $filename = $form['#module_file'];
  $success = FALSE;

  // Check first to see if the module has an install file. It may not exist or just be an empty file.
  if (!file_exists($filename) || filesize($filename) == 0) {
    // We didn't find a file or it's empty so just create a new one.
    return oa_export_create_new_install_file($form, $form_state);
  }
  // The file exists and isn't empty.
  else {
    // Pattern used to find hook_install().
    $pattern = "/function " . $module_name . "_install\(\) {/";
    // Search the install file for an implementation of hook_install().
    if ($result = oa_export_search_file($filename, $pattern)) {
      // We found an existing install hook but still need to check for update hooks.
      $latest_schema = oa_export_find_latest_update_hook_schema($module_name, $filename);
      if ($latest_schema === 0) {
        // No update hooks so we can just add ours.
        $new_version = oa_export_get_new_schema_version();
        $success = oa_export_write_update_hook($filename, $module_name, $new_version);
      }
      else {
        // Get a new schema version for the new update hook.
        $new_version = oa_export_get_new_schema_version($latest_schema);
        $success = oa_export_write_update_hook($filename, $module_name, $new_version);
      }
    }
    else {
      // No install hook so let's see if there are any existing update hooks.
      $latest_schema = oa_export_find_latest_update_hook_schema($module_name, $filename);
      if ($latest_schema === 0) {
        // Didn't find any existing update hooks so we can safely create a new install file.
        $success = oa_export_create_new_install_file($form, $form_state, TRUE);
      }
      else {
        // We found at least one update hook so we want to make sure we are incrementing the schema version.
        // Get the new version.
        $new_version = oa_export_get_new_schema_version($latest_schema);
        $success = oa_export_write_update_hook($filename, $module_name, $new_version);
      }
    }
  }

  return $success;
}

function oa_export_find_latest_update_hook_schema($module_name, $filename) {
  $pattern = "/function " . $module_name . "_update_([0-9]{4})\(\) {/";
  // Search the install file for implementations of hook_update_N().
  if ($results = oa_export_search_file($filename, $pattern, 1)) {
    // Get the latest version returned from the file.
    return end($results);
  }
  else {
    return 0;
  }
}

/**
 * Helper function to create the actual MODULE.install file.
 *
 * @param string $filename
 *   The absolute path and file name for the file.
 * @param array $module_name
 *   The machine_name of the module.
 * @param int $version
 * @param bool $reset
 *   Allows overwriting the install file.
 *
 * @return bool
 *   Whether the file contents were successfully written or not.
 */
function oa_export_write_hook_install($filename, $module_name, $version, $reset = FALSE) {
  $output = '';
  $output .= "<?php\n/**\n * @file\n * Install, update and uninstall functions.\n */\n";
  $output .= "\n";
  $output .= "/**\n * Implements hook_install().\n */\n";
  $output .= "function {$module_name}_install() {\n";
  $output .= "  // Call our update hook.\n";
  $output .= "  {$module_name}_update_{$version}();\n";
  $output .= "}\n";

  if ($reset) {
    $result = file_put_contents($filename, $output);
  }
  else {
    $result = file_put_contents($filename, $output, FILE_APPEND);
  }

  if ($result === FALSE) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}

/**
 * Writes an update hook for the MODULE.install file.
 *
 * @param string $filename
 *   The absolute path and file name for the file.
 * @param array $module_name
 *   The machine_name of the module.
 * @param int $version
 *   The schema version for the update hook.
 *
 * @return bool
 *   Whether the file contents were successfully written or not.
 */
function oa_export_write_update_hook($filename, $module_name, $version) {
  $output = "";
  $output .= "\n/**\n * Implements hook_update_N().\n *\n * Imports a blueprint.\n */\n";
  $output .= "function {$module_name}_update_{$version}() {\n";
  $output .= "  // Check for the export file.\n";
  $output .= "  \$module = '" . $module_name . "';\n";
  $output .= "  \$path = drupal_get_path('module', \$module) . '/' . OA_EXPORT_DIR;\n";
  $output .= "  if (file_exists(\$path . '/' . OA_EXPORT_JSON_FILE . '.json')) {\n";
  $output .= "    // Start the import.\n";
  $output .= "    oa_export_batch_import(\$path, 'module');\n";
  $output .= "  }\n";
  $output .= "}\n";

  if (file_put_contents($filename, $output, FILE_APPEND) === FALSE) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}
