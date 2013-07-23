<?php

/**
 * @file
 * Declares our ical plugins to Views.
 */

/**
 * Implements hook_views_plugins().
 */
function date_ical_views_plugins() {
  $includes_path = drupal_get_path('module', 'date_ical') . '/includes';

  $data = array(
    // This just tells our themes are elsewhere.
    'module' => 'date_ical',
    'style' => array(
      'date_ical' => array(
        'title' => t('iCal Feed'),
        'help' => t('Generates an iCal VCALENDAR feed from a view.'),
        'handler' => 'date_ical_plugin_style_ical_feed',
        'path' => $includes_path,
        'uses fields' => FALSE,
        'uses grouping' => FALSE,
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'type' => 'feed',
        'even empty' => TRUE,
      ),
    ),
    'row' => array(
      'date_ical' => array(
        'title' => t('iCal Entity'),
        'help' => t('Render each entity as an iCal VEVENT item.'),
        'handler' => 'date_ical_plugin_row_ical_entity',
        'path' => $includes_path,
        'uses options' => TRUE,
        'uses fields' => FALSE,
        'type' => 'feed',
      ),
      'date_ical_fields' => array(
        'title' => t('iCal Fields'),
        'help' => t('Display fields for an iCal VEVENT item.'),
        'handler' => 'date_ical_plugin_row_ical_fields',
        'path' => $includes_path,
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'type' => 'feed',
      ),
    ),
  );

  return $data;
}
