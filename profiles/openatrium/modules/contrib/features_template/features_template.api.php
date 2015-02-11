<?php
/**
 * @file
 * API info for features template module
 */

/**
 * RETURN an array of datum array that tell features template how 
 * and what items to make. they each have the following properties
 *   plugin: what features template template plugin to use
 *   template: where is the template that should be used to 
 *   construct components
 *   deleted: if marked true then features template will insure that 
 *   the component is removed.
 *   PLUGIN Variables:  Other items that are used by the plugin( 
 *   e.g. the field_instance plugin uses entity_type, buindle_type an field)
 */
function hook_features_template_info() {
  $content_types = variable_get('mymodule_content_types_to_index', array());
  $data = array();
  foreach ($content_types as $content_type => $present) {
    $data[] = array(
      'plugin' => 'field_instance',
      'template' => 'mymodule_search_field_author_default_field_instances_template'
      'deleted' => !empty($present),
      'entity_type' => 'node',
      'bundle_type' => $content_type,
      'field' => 'field_author',
    );
  }
  return $data;
}

/**
 * Example of template callback.
 *
 * Return the field instance defination like would recieve from exporting
 * via features, including being keyed. Suggestion is to create a field then
 * export the field base and field instance to a feature. Remove the field
 * instance into .module and rename it to your 'template' function.
 */
function mymodule_search_field_author_default_field_instances_template() {
  return array(
    'field_author' => array(
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 5,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_author',
      'label' => 'Author',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'node_reference',
        'settings' => array(
          'autocomplete_match' => 'contains',
          'autocomplete_path' => 'node_reference/autocomplete',
          'references_dialog_add' => 1,
          'references_dialog_edit' => 1,
          'references_dialog_search' => 1,
          'references_dialog_search_view' => '',
          'size' => 60,
        ),
        'type' => 'node_reference_autocomplete',
        'weight' => 2,
      ),
    ),
  );
}

/**
 * Example of configuration form to configure a field and rebuild
 * on save.
 */

/**
 * Configure the author field.
 */
function openpublic_field_author_apps_configure_form() {
  $form = array();

  $form['openpublic_field_author_author_field_content_types'] = array(
    '#title' => t('Content types'),
    '#default_value' => variable_get('openpublic_field_author_author_field_content_types', array()),
    '#type' => 'checkboxes',
    '#options' => node_type_get_names(),
  );

  $form['#submit'][] = 'openpublic_field_author_apps_configure_form_submit';
  return system_settings_form($form);
}

/**
 * Rebuild the field.
 */
function openpublic_field_author_apps_configure_form_submit($form, &$form_state) {
  // Revert features template.
  features_template_revert();
}
