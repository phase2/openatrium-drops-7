<?php
/**
 * @file
 * oa_export.module.export.inc
 *
 * Provides a way to export a blueprint via a new or existing module.
 */

require_once 'oa_export.module.install.inc';
require_once 'oa_export.module.info.inc';
require_once 'oa_export.module.module.inc';

/**
 * Form used to export a blueprint to a module.
 *
 * @param array $form
 *   Empty form array.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 * @param object $blueprint
 *   The fully loaded blueprint entity.
 *
 * @return array $form
 *   The fully built form used to collect data to generate a module.
 */
function oa_export_generate_module_form($form, &$form_state, $blueprint) {

  $form['#blueprint'] = $blueprint->tid;

  $form['module']['help'] = array(
    '#markup' => t('Creates a module that will import the blueprint when installed or adds the export to an existing module.'),
  );
  $form['module']['choose'] = array(
    '#title' => t('Choose an option.'),
    '#type' => 'select',
    '#options' => array('new' => t('Create a new module'), 'existing' => t('Add to an existing module')),
    '#default_value' => isset($form_state['input']['choose']) ? $form_state['input']['choose'] : 'new',
  );

  oa_export_generate_new_module_form($form, $form_state);
  oa_export_generate_existing_module_form($form, $form_state);

  return $form;
}

/**
 * Generates the form for creating a new module to add the export to.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function oa_export_generate_new_module_form(&$form, &$form_state) {
  $form['generate_module_form'] = array(
    '#title' => '',
    '#prefix' => '<div id="generate-module-form">',
    '#suffix' => '</div>',
    '#type' => 'fieldset',
    '#states' => array(
      'visible' => array(
        ':input[name="choose"]' => array('value' => 'new'),
      ),
    ),
  );

  $form['generate_module_form']['name'] = array(
    '#title' => t('Name'),
    '#description' => t('Example: Project Blueprint') . ' (' . t('Do not begin name with numbers.') . ')',
    '#type' => 'textfield',
    '#default_value' => isset($form_state['input']['name']) ? $form_state['input']['name'] : '',
  );
  $form['generate_module_form']['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine-readable name'),
    '#description' => t('Example: project_blueprint' .
      '<br/>' .
      t('May only contain lowercase letters, numbers and underscores. <strong>Try to avoid conflicts with the names of existing Drupal projects.</strong>')
    ),
    '#default_value' => isset($form_state['input']['machine_name']) ? $form_state['input']['machine_name'] : '',
    '#required' => FALSE,
    '#machine_name' => array(
      'exists' => 'oa_export_module_machine_name_validate',
      'source' => array('generate_module_form', 'name'),
    ),
  );
  $form['generate_module_form']['description'] = array(
    '#title' => t('Description'),
    '#description' => t('Provide a short description of what users should expect when they enable your module.'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['input']['description']) ? $form_state['input']['description'] : '',
  );
  $form['generate_module_form']['version'] = array(
    '#title' => t('Version'),
    '#description' => t('Examples: @examples', array('@examples' => DRUPAL_CORE_COMPATIBILITY . '-1.0, ' . DRUPAL_CORE_COMPATIBILITY . '-1.0-beta1')),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['input']['version']) ? $form_state['input']['version'] : '',
    '#element_validate' => array('oa_export_module_version_validate'),
  );
  $form['generate_module_form']['package'] = array(
    '#title' => t('Package'),
    '#description' => t('The group it will be displayed under in the module list.'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['input']['package']) ? $form_state['input']['package'] : '',
  );
  $form['generate_module_form']['generate_path'] = array(
    '#title' => t('Path to generate module'),
    '#description' => t('The relative path where the module will be created.') .
      t('Leave blank for <strong>@path</strong>.', array('@path' => OA_EXPORT_DEFAULT_MODULE_PATH)),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['input']['generate_path']) ? $form_state['input']['generate_path'] : '',
  );

  $form['generate_module_form']['process'] = array(
    '#type' => 'submit',
    '#value' => t('Generate Module'),
  );

}

/**
 * Handles validation on the 'machine_name' form element. Confirms the module name is unique.
 *
 * @param $element
 *   The form element being validated.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 * @param $form
 *   An associative array containing the structure of the form.
 */
function oa_export_module_machine_name_validate($element, &$form_state, $form) {
  if ($form_state['values']['choose'] != 'new') {
    return;
  }

  $modules = system_rebuild_module_data();
  foreach ($modules as $name => $module) {
    if ($element === $name) {
      form_error($element, t(
        'The machine name @name is already being used by another module. Please choose another.', array(
          '@name' => $name,
        )
      ));
    }
  }
}

/**
 * Handles validation on the 'version' form element.
 *
 * Similar to @see features_export_form_validate_field().
 *
 * @param $element
 *   The form element being validated.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 * @param $form
 *   An associative array containing the structure of the form.
 */
function oa_export_module_version_validate($element, &$form_state, $form) {
  preg_match('/^(?P<core>\d+\.x)-(?P<major>\d+)\.(?P<patch>\d+)-?(?P<extra>\w+)?$/', $element['#value'], $matches);
  if (!empty($element['#value']) && !isset($matches['core'], $matches['major'])) {
    $example = DRUPAL_CORE_COMPATIBILITY . '-1.0';
    form_error($element, t('Please enter a valid version with core and major version number. Example: @example', array('@example' => $example)));
  }
}

/**
 * Generates the form for adding the export to an existing module. This one is much simpler. We just need
 * the name of the module we will be adding the export to.
 *
 * @param $form_state
 *   A keyed array containing the current state of the form.
 * @param $form
 *   An associative array containing the structure of the form.
 */
function oa_export_generate_existing_module_form(&$form, &$form_state) {
  $form['generate_existing_module_form'] = array(
    '#title' => '',
    '#prefix' => '<div id="generate-existing-module-form">',
    '#suffix' => '</div>',
    '#type' => 'fieldset',
    '#states' => array(
      'visible' => array(
        ':input[name="choose"]' => array('value' => 'existing'),
      ),
    ),
  );

  $form['generate_existing_module_form']['existing_module'] = array(
    '#title' => t('Name of module'),
    '#description' => t('This should be the <strong>machine_name</strong> of an existing module in your system'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['input']['existing_module']) ? $form_state['input']['existing_module'] : '',
    '#element_validate' => array('oa_export_existing_module_name_validate'),
  );

  $form['generate_existing_module_form']['process'] = array(
    '#type' => 'submit',
    '#value' => t('Add export to module'),
  );

}

/**
 * Handles validation on the 'existing_module' form element when it is used while exporting to an existing module.
 *
 * @param $element
 *   The form element being validated.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 * @param $form
 *   An associative array containing the structure of the form.
 */
function oa_export_existing_module_name_validate($element, &$form_state, $form) {
  if ($form_state['values']['choose'] != 'existing') {
    return;
  }

  if (empty($element['#value'])) {
    form_error($element, t('You must enter the machine_name of an existing module.'));
  }
  else {
    // We build the absolute path. The module may be a work in progress and may not be enabled yet so this is the best
    // way to find it.
    $module_path = DRUPAL_ROOT . '/' . drupal_get_path('module', $element['#value']);
    if (!file_exists($module_path)) {
      form_error($element, t(
        'The @name module could not be found!.', array(
          '@name' => $element['#value'],
        )
      ));
    }
  }
}

/**
 * Handles validation on the 'generate_module' form.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function oa_export_generate_module_form_validate(&$form, &$form_state) {
  if ($form_state['values']['choose'] == 'new') {
    // New module
    $module_name = $form_state['values']['machine_name'];
    $module_path = !empty($form_state['values']['generate_path']) ? $form_state['values']['generate_path'] : OA_EXPORT_DEFAULT_MODULE_PATH;
    $module_path = DRUPAL_ROOT . '/' . $module_path . '/' . $module_name;
  }
  else {
    // Existing module
    $module_name = $form_state['values']['existing_module'];
    // The path to the existing module.
    $module_path = DRUPAL_ROOT . '/' . drupal_get_path('module', $module_name);
    if (empty($module_path)) {
      form_set_error(NULL, t("Couldn't find that the @module module at @module_path. Does it exist?.", array(
          '@module' => $module_name,
          '@module_path' => $module_path,
        )
      ));
    }

    if (file_exists($module_path . '/' . OA_EXPORT_DIR)) {
      // module already has an export, so rename it temporarily until we are done
      if (file_exists($module_path . '/' . OA_EXPORT_TEMP_DIR)) {
        file_unmanaged_delete_recursive($module_path . '/' . OA_EXPORT_TEMP_DIR);
      }
      rename($module_path . '/' . OA_EXPORT_DIR, $module_path . '/' . OA_EXPORT_TEMP_DIR);
    }
  }

  $form['#module_name'] = $module_name;
  $form['#module_path'] = $module_path;

  // Try to create the oa_export directory.
  $export_dir = oa_export_create_directories($module_path . '/' . OA_EXPORT_DIR);
  // Set an error if we are unsuccessful.
  if (!$export_dir) {
    form_set_error(NULL, t("Couldn't create the @dir directory in @module_name at the path @module_path. Please check your permissions.", array(
        '@dir' => OA_EXPORT_DIR,
        '@module_name' => $module_name,
        '@module_path' => $module_path,
      )
    ));
  }
  else {
    // Try to create the files directory.
    $files_dir = oa_export_create_directories($export_dir . '/' . OA_EXPORT_FILES);
    if (!$files_dir) {
      form_set_error(NULL, t("Couldn't create a files directory in @dir for the module @module_name. Please check your permissions.", array(
          '@module_name' => $module_name,
          '@dir' => $_SESSION['oa_export']['files_directory'],
        )
      ));
    }
    else {
      // File types for a module that we need to update.
      $file_types = array('module', 'info', 'install');
      foreach ($file_types as $extension) {
        $filename = $module_path . '/' . $module_name . '.' . $extension;
        $form['#module_file'] = $filename;
        if (file_exists($filename)) {
          $success = oa_export_update_module_file($form, $form_state, $extension);
          if (!$success) {
            form_set_error(NULL, t("Couldn't update the contents of the @module_name.@extension file at the path @module_path. Please check your permissions.", array(
                '@extension' => $extension,
                '@module_name' => $_SESSION['oa_export']['module'],
                '@module_path' => $module_path,
              )
            ));
          }
        }
        else {
          $success = oa_export_create_module_file($form, $form_state, $extension);
          if (!$success) {
            // Set a form error.
            form_set_error(NULL, t("Couldn't create the @module_name.@extension file at the path @module_path. Please check your permissions.", array(
                '@extension' => $extension,
                '@module_name' => $module_name,
                '@module_path' => $module_path,
              )
            ));
          }
        }
      }
    }
  }
}

/**
 * The submit handler for the module generation form. This is what kicks off the batch process for the export.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function oa_export_generate_module_form_submit($form, &$form_state) {

  if (form_get_errors()) {
    $form_state['rebuild'] = TRUE;
    return $form;
  }

  // NOTE: Directories were created in the validation step.
  // See oa_export_generate_module_form_validate()
  $module_path = $form['#module_path'];
  $module_name = $form['#module_name'];

  // Success, so set session variables for batch usage in export
  $_SESSION['oa_export'] = array();
  // Store the name of the module so we have access after the batch runs.
  $_SESSION['oa_export']['module'] = $module_name;
  // Lets us know we are adding the export to an existing module.
  $_SESSION['oa_export']['type'] = $form_state['values']['choose'];
  // This is where files will be stored.
  $_SESSION['oa_export']['files_directory'] = $module_path . '/' . OA_EXPORT_DIR . '/' . OA_EXPORT_FILES;

  if (!form_get_errors()) {
    // Load the full blueprint.
    $blueprint = taxonomy_term_load($form['#blueprint']);

    // Export the blueprint via batch.
    oa_export_batch_export($blueprint, 'module');

    // Redirect the user to the current path.
    batch_process(current_path());
  }
}

/**
 * Helper function to create a new file for a module.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 * @param $extension
 *   The extension of the file being created, e.g. module, info, install.
 *
 * @return bool
 *   Whether the file was successfully created or not.
 */
function oa_export_create_module_file($form, $form_state, $extension) {
  $function = 'oa_export_create_new_' . $extension . '_file';
  return $function($form, $form_state);
}

/**
 * Helper function to update existing file for a module.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 * @param $extension
 *   The extension of the file being created, e.g. module, info, install.
 *
 * @return bool
 *   Whether the file was successfully created or not.
 */
function oa_export_update_module_file($form, $form_state, $extension) {
  $function = 'oa_export_update_existing_' . $extension . '_file';
  return $function($form, $form_state);
}

/**
 * Helper function to search a file for a pattern.
 *
 * @param string $file
 *   The absolute path to the file.
 * @param string $pattern
 *   Regular expression.
 * @param int $delta
 *   Allows choosing the match that will be returned.
 *
 * @return array|bool
 *   Returns the match if one is found, otherwise FALSE.
 */
function oa_export_search_file($file, $pattern, $delta = 0) {
  try {
    if (!file_exists($file)) {
      throw new Exception(t('The file @file could not be found!', array('@file' => $file)));
    }
    $h = fopen($file, 'r');
    if (!$h) {
      throw new Exception(t('The file @file could not be opened!', array('@file' => $file)));
    }
    else {
      // Iterate
      while (($line = fgets($h)) !== false) {
        preg_match($pattern, $line, $matches);
        if ($matches) {
          $results[] = $matches[$delta];
        }
        else {
          continue;
        }
      }
      fclose($h);
      if (!empty($results)) {
        return $results;
      }
      else {
        return FALSE;
      }
    }
  }
  catch (Exception $e) {
    $message = $e->getMessage();
    drupal_set_message(t($message), 'error');
  }
}
