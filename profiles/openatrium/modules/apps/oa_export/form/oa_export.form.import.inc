<?php
/**
 * @file oa_export.form.import.inc
 *
 * The form used for importing a blueprint.
 */

//require_once 'oa_export.batch.import.inc';
//require_once 'formats/json.inc';

/**
 * The blueprint import form.
 *
 * @param array $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 * @return array $form
 *   The form used for importing a blueprint.
 */
function oa_export_blueprint_import_form($form, &$form_state) {

  $form = array();
  $form['#attributes'] = array(
    'enctype' => "multipart/form-data",
  );
  $form['#prefix'] = "<p>";
  $form['#prefix'] .= t('Import your blueprint by uploading the file you exported.') . " ";
  $form['#prefix'] .= "</p>";

  $form['upload'] = array(
    '#type' => 'fieldset',
    '#title' => t('Upload file'),
    '#collapsible' => FALSE,
  );
  $form['upload']['file'] = array(
    '#type' => 'file',
    '#description' => t('To clear this field, <a href="!reset">reset the form</a>.', array('!reset' => url($_GET['q'])))
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

/**
 * Validation function for the blueprint import form.
 *
 * @param array $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 */
function oa_export_blueprint_import_form_validate($form, &$form_state) {
  if (!$_FILES['files']['name']['file']) {
    drupal_set_message(t('Please upload a file to run a blueprint import.'), 'error');
    form_set_error('', NULL);
  }
}

/**
 * Submit function for the blueprint import form.
 *
 * @param array $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 * @throws Exception
 */
function oa_export_blueprint_import_form_submit($form, &$form_state) {

  $original = $_FILES['files']['name']['file'];
  // Save the uploaded file.
  $file = file_save_upload('file', array('file_validate_extensions' => array()), FALSE, FILE_EXISTS_REPLACE);
  if (!$file) {
    drupal_set_message(t('Error: Node export could not save file.'), 'error');
  }
  else {
    $file->original = $original;
    // Set the form value for the file.
    form_set_value($form['upload']['file'], serialize($file), $form_state);
  }
  // Make sure we have a value for the file.
  if ($form_state['values']['file'] && isset($file)) {

    // Build the batch to import the blueprint.
    oa_export_batch_import($file);
    // Start the batch process and redirect when it's finished.
    batch_process();
  }
  else {
    drupal_set_message(t("There was an error importing the file, try exporting and re-importing."));
  }

  // We need to send this user somewhere, and we know they have permission
  // for this page:
  drupal_goto('blueprint/import');
}
