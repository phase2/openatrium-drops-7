<?php
/**
 * @file
 * oa_related.features.inc
 */

/**
 * Implements hook_views_api().
 */
function oa_related_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_paragraphs_info().
 */
function oa_related_paragraphs_info() {
  $items = array(
    'paragraph_content' => array(
      'name' => 'Related Content',
      'bundle' => 'paragraph_content',
      'locked' => '1',
    ),
    'paragraph_media' => array(
      'name' => 'Media Gallery',
      'bundle' => 'paragraph_media',
      'locked' => '1',
    ),
    'paragraph_snippet' => array(
      'name' => 'Snippet',
      'bundle' => 'paragraph_snippet',
      'locked' => '1',
    ),
    'paragraph_text' => array(
      'name' => 'Text',
      'bundle' => 'paragraph_text',
      'locked' => '1',
    ),
  );
  return $items;
}
