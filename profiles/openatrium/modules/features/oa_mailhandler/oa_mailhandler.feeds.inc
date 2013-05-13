<?php

/**
 * @file
 * Contains all feeds related code for oa_mailhandler.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see FeedsNodeProcessor::getMappingTargets().
 */
function oa_mailhandler_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  // Entity references uses a function to assign values from feeds to entity
  // reference fields that goes through a lot of validation that we don't want.
  // It checks against a GUID assigned to the feed to ensure that the referenced
  // entities had been imported previously, but we don't care, since we're
  // importing something generated from an existing entity.
  foreach (oa_mailhandler_entity_reference_fields() as $field) {
    $targets[$field]['callback'] = 'oa_mailhandler_entity_reference_feeds_value';
  }
}

/**
 * Callback for assigning entity reference value to an entity from a feed.
 *
 * @see oa_mailhandler_feeds_processor_targets_alter().
 */
function oa_mailhandler_entity_reference_feeds_value($source, $entity, $target, $values, $mapping, $input_format = FALSE) {
  if (!$values) {
    return;
  }

  if (!is_array($values)) {
    $values = array($values);
  }

  $lang = isset($mapping['language']) ? $mapping['language'] : LANGUAGE_NONE;

  $i = 0;
  foreach ($values as $value) {
    $entity->{$target}[$lang][$i]['target_id'] = $value;
  }
}

/**
 * List of entity reference fields that get imported from feeds.
 */
function oa_mailhandler_entity_reference_fields() {
  return array(
    'oa_parent',
    'oa_section_ref',
    'og_group_ref',
  );
}
