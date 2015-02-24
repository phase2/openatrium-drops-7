<?php
/**
 * @file
 * oa_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_server_alter().
 */
function oa_search_default_search_api_server_alter(&$data) {
  if (isset($data['database_server'])) {
    $data['database_server']->options['indexes']['database_node_index']['field_oa_related'] = array(
      'table' => 'search_api_db_database_node_index_field_oa_related',
      'type' => 'list<integer>',
      'boost' => '1.0',
    ); /* WAS: '' */
    $data['database_server']->options['indexes']['database_node_index']['field_oa_related:field_paragraph_text:value'] = array(
      'table' => 'search_api_db_database_node_index_text',
      'type' => 'list<text>',
      'boost' => '1.0',
    ); /* WAS: '' */
    $data['database_server']->options['indexes']['database_node_index']['field_oa_related:snippet_body'] = array(
      'table' => 'search_api_db_database_node_index_text',
      'type' => 'list<text>',
      'boost' => '1.0',
    ); /* WAS: '' */
    $data['database_server']->options['indexes']['database_node_index']['oa_section_ref:title'] = array(
      'table' => 'search_api_db_database_node_index_oa_section_ref_title',
      'type' => 'string',
      'boost' => '1.0',
    ); /* WAS: '' */
    $data['database_server']->options['indexes']['database_node_index']['og_group_ref:title'] = array(
      'table' => 'search_api_db_database_node_index_og_group_ref_title',
      'type' => 'string',
      'boost' => '1.0',
    ); /* WAS: '' */
    $data['database_server']->options['indexes']['user_index'] = array(
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
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function oa_search_strongarm_alter(&$data) {
  if (isset($data['search_active_modules'])) {
    $data['search_active_modules']->value['file_entity'] = 0; /* WAS: '' */
    $data['search_active_modules']->value['user'] = 'user'; /* WAS: 0 */
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function oa_search_default_search_api_index() {
  $items = array();
  $items['solr_user_index'] = entity_import('search_api_index', '{
    "name" : "Solr User Index",
    "machine_name" : "solr_user_index",
    "description" : null,
    "server" : "solr_server",
    "item_type" : "user",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_user_display_name" : { "type" : "text", "boost" : "5.0" },
        "mail" : { "type" : "text" },
        "name" : { "type" : "text" },
        "og_user_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_role_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "roles" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "0",
    "read_only" : "0"
  }');
  $items['user_index'] = entity_import('search_api_index', '{
    "name" : "User Index",
    "machine_name" : "user_index",
    "description" : null,
    "server" : "database_server",
    "item_type" : "user",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_user_display_name" : { "type" : "text", "boost" : "5.0" },
        "mail" : { "type" : "text" },
        "name" : { "type" : "text" },
        "og_user_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_role_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "roles" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "name" : true, "mail" : true, "field_user_display_name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
