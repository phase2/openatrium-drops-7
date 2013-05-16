<?php
/**
 * @file
 * Code for Theme functions of the OpenAtrium Event feature.
 */

/**
 * Implements hook_theme()
 */
function oa_events_theme() {

  $theme = array(
    'oa_event_date' => array(
      'template' => 'oa-event-date',
      'path' => drupal_get_path('module', 'oa_events') . '/templates',
      'variables' => array(
        'month' => NULL,
        'day' => NULL,
      ),
    ),
    'oa_event_next_date' => array(
      'template' => 'oa-event-next-date',
      'path' => drupal_get_path('module', 'oa_events') . '/templates',
      'variables' => array(
        'date' => NULL,
        'time' => NULL,
        'rrule' => NULL,
      ),
    ),
  );

  $displays = array('event_details', 'event_details_list');
  foreach ($displays as $display) {
    $key = 'views_view_fields__oa_event_detail__' . $display;
    $filename = str_replace('_', '-', $key);
    $theme[$key] = array(
      'template'  => $filename,
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => drupal_get_path('module', 'oa_events') . '/templates',
    );
  }

  return $theme;
}
