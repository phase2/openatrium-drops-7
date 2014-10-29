<?php

/**
 * @file
 * Plugin to provide access control based on solr status
 */

$plugin = array(
  'title' => t('Search User Index'),
  'description' => t('Is the Search User index enabled?'),
  'callback' => 'oa_search_search_user_index_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'oa_search_search_user_index_ctools_access_settings',
  'summary' => 'oa_search_search_user_index_ctools_access_summary',
);

/**
 * Settings form for the "Search API User Index Enabled" settings form
 */
function oa_search_search_user_index_ctools_access_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  return $form;
}

/**
 * Check to see if the Search API server and index are enabled
 */
function oa_search_search_user_index_ctools_access_check($conf, $context) {
  $solr_index= search_api_index_load('solr_user_index');
  return $solr_index->enabled;
}

/**
 * Provide a summary description based upon the checked terms.
 */
function oa_search_search_user_index_ctools_access_summary($conf, $context) {
  return t('Open Atrium Search User index is Enabled');
}
