<?php
/**
 * @file
 * Code for Theme functions of the OpenAtrium Discussion feature.
 */

/**
 * Implements hook_theme()
 */
function oa_discussion_theme() {
  $displays = array('replies', 'original_post', 'attachments', 'discussion_topics',
    'discussion_user', 'discussion_user_reply');
  $theme = array();
  foreach ($displays as $display) {
    $key = 'views_view_fields__open_atrium_discussions__' . $display;
    $filename = str_replace('_', '-', $key);
    $theme[$key] = array(
      'template'  => $filename,
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
        'oa_core_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => drupal_get_path('module', 'oa_discussion') . '/templates',
    );
  }
  return $theme;
}

