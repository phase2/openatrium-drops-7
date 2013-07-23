<?php

/**
 * @file
 * Hooks provided by the Colors module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Gets the color configuration mapping.
 *
 * @return
 *   Mapping between the colorable features and the CSS input.
 */
function hook_colors_get_color_mapping() {
  return array(
    'background' => 'background-color',
    'text' =>  'color',
    'border' => 'border-color',
  );
}

/**
 * Builds a selector string.
 *
 * @param $class
 *   Class name used for the new selector string.
 *
 * @return
 *   The built selector.
 */
function hook_colors_build_selector($class) {
  $selector = '.' . $class . ',';
  $selector .= '.' . $class . 'a';
  return $selector;
}

/**
 * Declare if the CSS file should be automatically rebuilt.
 *
 * @return bool
 *   TRUE if the file should be rebuilt automatically, FALSE if it should be
 *   rebuilt at runtime.
 */
function hook_colors_rebuild() {
  return TRUE;
}

/**
 * Declare a colors plugin.
 *
 * @return array
 *   An associative array containing one or more coloring types, keyed by the
 *   type name, containing an associative array with the following keys:
 *   - title: The untranslated display name of this type.
 *   - short_description: The text to display for the checkbox.
 *   - long_description: The text to describe the fieldset.
 *   - function: The callback for gathering the type options.
 *   - multiple_function: (optional) If the type contains sub-types, this will
 *     be used as the top-level callback.
 *   - validate: (optional) A boolean, if TRUE an additional form validation
 *   - handler, colors_admin_TYPE_settings_validate(), will be used.
 *   - submit: (optional) A boolean, if TRUE an additional form submission
 *     handler, colors_admin_TYPE_settings_submit(), will be used.
 */
function hook_colors_info() {
  return array(
    'node_type' => array(
      'title' => 'Node type',
      'short_description' => t('Enable colors for node types'),
      'long_description' => t('Colors for node types. If enabled, you may set colors for each node type below.'),
      'function' => 'node_type_get_names',
    ),
  );
}

/**
 * Provide a way for modules to add the classes used to their markup.
 *
 * @param object $entity
 *   The entity object.
 */
function hook_colors_classes($entity) {
  $class_names = array();
  if (variable_get('colors_node_type_enabled', FALSE)) {
    if ($entity->entity_type == 'node') {
      $class_names[] = 'colors-node-type-' . $entity->type;
    }
  }
  return $class_names;
}

/**
 * @} End of "addtogroup hooks".
 */
