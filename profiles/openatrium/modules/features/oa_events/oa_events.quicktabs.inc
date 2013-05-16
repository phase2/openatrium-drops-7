<?php
/**
 * @file
 * oa_events.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function oa_events_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'oa_calendar';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Calendar';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'oa_events',
      'display' => 'oa_calendar_day',
      'args' => '',
      'title' => 'Day',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'oa_events',
      'display' => 'oa_calendar_week',
      'args' => '',
      'title' => 'Week',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'oa_events',
      'display' => 'oa_calendar_month',
      'args' => '',
      'title' => 'Month',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Calendar');
  t('Day');
  t('Month');
  t('Week');

  $export['oa_calendar'] = $quicktabs;

  return $export;
}
