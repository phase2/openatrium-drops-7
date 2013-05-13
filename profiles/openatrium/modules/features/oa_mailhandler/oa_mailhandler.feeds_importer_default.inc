<?php
/**
 * @file
 * oa_mailhandler.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function oa_mailhandler_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'discussion_reply_email_importer';
  $feeds_importer->config = array(
    'name' => 'Discussion reply email importer',
    'description' => 'Imports email replies to discussion as discussion replies',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'MailhandlerFilters',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'OaMailParser',
      'config' => array(
        'available_commands' => 'status',
        'authenticate_plugin' => 'MailhandlerAuthenticateDefault',
        'extended_headers' => NULL,
        'require_contextual_nid' => TRUE,
        'filter_email' => TRUE,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'oa_discussion_post',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'authenticated_uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'body_text',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'attachments',
            'target' => 'field_oa_media',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'contextual_nid',
            'target' => 'oa_parent',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'contextual_space_id',
            'target' => 'og_group_ref',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'contextual_section_id',
            'target' => 'oa_section_ref',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['discussion_reply_email_importer'] = $feeds_importer;

  return $export;
}
