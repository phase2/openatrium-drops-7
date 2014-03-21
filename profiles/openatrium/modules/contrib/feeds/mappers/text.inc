<?php

/**
 * @file
 * On behalf implementation of Feeds mapping API for text.module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsProcessor::getMappingTargets()
 */
function text_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  $text_types = array(
    'list_text',
    'text',
    'text_long',
    'text_with_summary',
  );
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);

    if (in_array($info['type'], $text_types)) {
      $targets[$name] = array(
        'name' => check_plain($instance['label']),
        'callback' => 'text_feeds_set_target',
        'description' => t('The @label field of the entity.', array('@label' => $instance['label'])),
      );
    }
  }
}

/**
 * Callback for mapping text fields.
 */
function text_feeds_set_target($source, $entity, $target, array $values) {
  if (isset($source->importer->processor->config['input_format'])) {
    $format = $source->importer->processor->config['input_format'];
  }

  $field = isset($entity->$target) ? $entity->$target : array('und' => array());

  // Iterate over all values.
  foreach ($values as $value) {

    if (is_object($value) && ($value instanceof FeedsElement)) {
      $value = $value->getValue();
    }

    if (is_scalar($value) && strlen($value)) {
      $value = array('value' => (string) $value);
      if (isset($format)) {
        $value['format'] = $format;
      }

      $field['und'][] = $value;
    }
  }

  $entity->$target = $field;
}
