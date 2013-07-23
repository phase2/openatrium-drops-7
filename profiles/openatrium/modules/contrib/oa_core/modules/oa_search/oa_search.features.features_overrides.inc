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

  // Exported overrides for: search_api_index
  $overrides["search_api_index.database_node_index.options|fields|created|type"] = 'date';
  $overrides["search_api_index.database_node_index.options|fields|oa_section_ref:title"] = array(
    'type' => 'string',
  );
  $overrides["search_api_index.database_node_index.options|fields|og_group_ref:title"] = array(
    'type' => 'string',
  );

  // Exported overrides for: search_api_server
  $overrides["search_api_server.database_server.options|indexes|database_node_index|created|type"] = 'date';
  $overrides["search_api_server.database_server.options|indexes|database_node_index|oa_section_ref:title"] = array(
    'table' => 'search_api_db_database_node_index_oa_section_ref_title',
    'type' => 'string',
    'boost' => 1,
  );
  $overrides["search_api_server.database_server.options|indexes|database_node_index|og_group_ref:title"] = array(
    'table' => 'search_api_db_database_node_index_og_group_ref_title',
    'type' => 'string',
    'boost' => 1,
  );

  // Exported overrides for: variable
  $overrides["variable.search_active_modules.value|file_entity"] = 0;
  $overrides["variable.search_active_modules.value|user"] = 'user';

 return $overrides;
}
