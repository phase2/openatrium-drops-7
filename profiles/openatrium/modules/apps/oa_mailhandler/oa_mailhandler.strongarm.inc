<?php
/**
 * @file
 * oa_mailhandler.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_mailhandler_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailcomment_import_filter_mode';
  $strongarm->value = '2';
  $export['mailcomment_import_filter_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailcomment_insert_reply_text';
  $strongarm->value = 1;
  $export['mailcomment_insert_reply_text'] = $strongarm;

  return $export;
}
