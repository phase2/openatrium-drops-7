<?php
/**
 * @file
 * oa_search.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_search_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: search_api_server
  $overrides["search_api_server.database_server.options|indexes|database_node_index|field_oa_related"] = array(
    'table' => 'search_api_db_database_node_index_field_oa_related',
    'type' => 'list<integer>',
    'boost' => '1.0',
  );
  $overrides["search_api_server.database_server.options|indexes|database_node_index|field_oa_related:field_paragraph_text:value"] = array(
    'table' => 'search_api_db_database_node_index_text',
    'type' => 'list<text>',
    'boost' => '1.0',
  );
  $overrides["search_api_server.database_server.options|indexes|database_node_index|field_oa_related:snippet_body"] = array(
    'table' => 'search_api_db_database_node_index_text',
    'type' => 'list<text>',
    'boost' => '1.0',
  );
  $overrides["search_api_server.database_server.options|indexes|database_node_index|oa_section_ref:title"] = array(
    'table' => 'search_api_db_database_node_index_oa_section_ref_title',
    'type' => 'string',
    'boost' => '1.0',
  );
  $overrides["search_api_server.database_server.options|indexes|database_node_index|og_group_ref:title"] = array(
    'table' => 'search_api_db_database_node_index_og_group_ref_title',
    'type' => 'string',
    'boost' => '1.0',
  );
  $overrides["search_api_server.database_server.options|indexes|user_index"] = array(
    'name' => array(
      'table' => 'search_api_db_user_index_name',
      'type' => 'text',
      'boost' => '1.0',
    ),
    'mail' => array(
      'table' => 'search_api_db_user_index_name',
      'type' => 'text',
      'boost' => '1.0',
    ),
    'og_user_node' => array(
      'table' => 'search_api_db_user_index_og_user_node',
      'type' => 'list<integer>',
      'boost' => '1.0',
    ),
    'field_user_display_name' => array(
      'table' => 'search_api_db_user_index_name',
      'type' => 'text',
      'boost' => '5.0',
    ),
    'search_api_language' => array(
      'table' => 'search_api_db_user_index_search_api_language',
      'type' => 'string',
      'boost' => '1.0',
    ),
    'search_api_url' => array(
      'table' => 'search_api_db_user_index_search_api_url',
      'type' => 'uri',
      'boost' => '1.0',
    ),
  );

  // Exported overrides for: variable
  $overrides["variable.search_active_modules.value|file_entity"] = 0;
  $overrides["variable.search_active_modules.value|user"] = 'user';

 return $overrides;
}
