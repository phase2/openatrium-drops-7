<?php
/**
 * @file
 * oa_events_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function oa_events_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'ical_importer';
  $feeds_importer->config = array(
    'name' => 'iCal importer',
    'description' => 'Imports iCal events into an Open Atrium group',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'DateiCalFeedsParser',
      'config' => array(
        'indefinite_count' => '52',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '2592000',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'SUMMARY',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'DTSTART',
            'target' => 'field_oa_date:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'DTEND',
            'target' => 'field_oa_date:end',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'DESCRIPTION',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'RRULE',
            'target' => 'field_oa_date:rrule',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'UID',
            'target' => 'guid',
            'unique' => TRUE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'oa_event',
      ),
    ),
    'content_type' => 'oa_ical_importer',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 1,
  );
  $export['ical_importer'] = $feeds_importer;

  return $export;
}
