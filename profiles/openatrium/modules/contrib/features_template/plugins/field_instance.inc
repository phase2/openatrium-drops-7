<?php
/**
 * @File
 *
 * This plugin is used for field_instance templates.
 * The following are items that can be changed:
 *   entity_type: The name of the entity
 *   bundle_type: The name of the bundle
 *   field: the name of the field to update (must match the item in the template.
 *
 * This i san example of the data for a field_instance template in hook_features_template_info
    $data[] = array(
      'plugin' => 'field_instance',
      'template' => 'opensanmateo_search_field_default_field_instances_template'
      'deleted' => !$present,
      'entity_type' => 'node',
      'bundle_type' => $content_type,
      'field' => 'field_do_not_index',
    );
 *
 */

$plugin = array(
  'component' => 'field_instance',
  'implement callback' => 'features_template_field_instance',
  'features info callback' => 'features_template_field_instance_info',
  'deleted callback' => 'features_template_field_instance_delete',
);

/**
 * Callback that adds an entry into system info for thefield instance.
 */
function features_template_field_instance_info(&$info, $datum) {
  $key = features_template_field_instance_key($datum);
  if (!isset($info['features']['field_instance']) || !in_array($key, $info['features']['field_instance'])) {
    $info['features']['field_instance'][] = $key;
  }
}

/**
 * Customizes the field instance template for this data.
 */
function features_template_field_instance($template, $datum) {
  $key = features_template_field_instance_key($datum);
  $fields[$key] = reset($template);
  $fields[$key]['bundle'] = $datum['bundle_type'];
  $fields[$key]['entity_type'] = $datum['entity_type'];
  return $fields;
}

function features_template_field_instance_delete($datum) {
  $key = features_template_field_instance_key($datum);
  $instance = field_info_instance($datum['entity_type'], $datum['field'], $datum['bundle_type']);
  field_delete_instance($instance, FALSE);
}

/**
 * Creates the key for the array of field instances.
 */
function features_template_field_instance_key($datum) {
  return implode('-', array($datum['entity_type'], $datum['bundle_type'], $datum['field']));

}
