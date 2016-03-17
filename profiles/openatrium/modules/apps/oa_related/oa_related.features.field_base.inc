<?php
/**
 * @file
 * oa_related.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oa_related_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_image_alignment'
  $field_bases['field_image_alignment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image_alignment',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'left' => 'Align Left',
        'right' => 'Align Right',
        'center' => 'Center',
        'full' => 'Full width',
        'grid2' => '2 columns',
        'grid3' => '3 columns',
        'grid4' => '4 columns',
        'grid5' => '5 columns',
        'preview' => 'Preview listing',
        'table' => 'Media file table',
      ),
      'allowed_values_function' => 'oa_related_paragraphs_field_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_oa_content_layout'
  $field_bases['field_oa_content_layout'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_content_layout',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'table' => 'Table of files',
        'preview' => 'Preview listing',
        'full' => 'Full content',
        'list' => 'Simple listing',
      ),
      'allowed_values_function' => 'oa_related_paragraphs_field_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_oa_related'
  $field_bases['field_oa_related'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_related',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  // Exported field_base: 'field_oa_related_content'
  $field_bases['field_oa_related_content'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_related_content',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-autocomplete' => array(
            'status' => 0,
          ),
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'lock_revision' => 0,
        'reference_revisions' => 0,
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'oa_discussion_post' => 'oa_discussion_post',
          'oa_event' => 'oa_event',
          'oa_section' => 'oa_section',
          'oa_space' => 'oa_space',
          'oa_wiki_page' => 'oa_wiki_page',
          'oa_worktracker_task' => 'oa_worktracker_task',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_paragraph_layout'
  $field_bases['field_paragraph_layout'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_paragraph_layout',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        2 => '2 column',
        3 => '3 column',
        4 => '4 column',
        'full' => 'Callout',
        'left' => 'Callout Left',
        'right' => 'Callout Right',
      ),
      'allowed_values_function' => 'oa_related_paragraphs_field_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_paragraph_lock_revision'
  $field_bases['field_paragraph_lock_revision'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_paragraph_lock_revision',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_paragraph_text'
  $field_bases['field_paragraph_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_paragraph_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_snippet_content'
  $field_bases['field_snippet_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_snippet_content',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'lock_revision' => 0,
        'reference_revisions' => 1,
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_snippet_showtitle'
  $field_bases['field_snippet_showtitle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_snippet_showtitle',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_snippet_title_override'
  $field_bases['field_snippet_title_override'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_snippet_title_override',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_snippet_viewmode'
  $field_bases['field_snippet_viewmode'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_snippet_viewmode',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'summary' => 'Summary',
        'normal' => 'Just body',
        'full' => 'Body and paragraphs',
      ),
      'allowed_values_function' => 'oa_related_paragraphs_field_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
