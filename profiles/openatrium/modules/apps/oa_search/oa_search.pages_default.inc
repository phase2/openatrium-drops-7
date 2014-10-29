<?php
/**
 * @file
 * oa_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_search_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_node_panel_context';
  $handler->task = 'search';
  $handler->subtask = 'node';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Database Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'brenham_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_styles_well',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1e657d93-af29-4838-a78c-56ca34c925ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-549bb361-0279-4218-a3bd-7544852fa57c';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'panopoly_database_search-search_database_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '25',
      'fields_override' => array(
        'field_featured_image' => 1,
        'title' => 1,
        'body' => 1,
      ),
      'exposed' => array(
        'widget_title' => '',
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'context' => array(
        0 => 'argument_string_1',
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_mode' => 'teaser',
      'widget_title' => '',
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '549bb361-0279-4218-a3bd-7544852fa57c';
    $display->content['new-549bb361-0279-4218-a3bd-7544852fa57c'] = $pane;
    $display->panels['contentmain'][0] = 'new-549bb361-0279-4218-a3bd-7544852fa57c';
    $pane = new stdClass();
    $pane->pid = 'new-a71e209a-0b36-49a2-bce7-dfae611d8803';
    $pane->panel = 'header';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'node',
      'form' => 'simple',
      'path_type' => 'default',
      'path' => '',
      'override_prompt' => 0,
      'prompt' => '',
      'context' => 'argument_string_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a71e209a-0b36-49a2-bce7-dfae611d8803';
    $display->content['new-a71e209a-0b36-49a2-bce7-dfae611d8803'] = $pane;
    $display->panels['header'][0] = 'new-a71e209a-0b36-49a2-bce7-dfae611d8803';
    $pane = new stdClass();
    $pane->pid = 'new-6a158ed7-518f-4d8b-aac8-2cedd5e3286a';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => '1Cpx6naJU4Y3YvKVc0vcLK7Yo0ahaN0l',
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6a158ed7-518f-4d8b-aac8-2cedd5e3286a';
    $display->content['new-6a158ed7-518f-4d8b-aac8-2cedd5e3286a'] = $pane;
    $display->panels['sidebar'][0] = 'new-6a158ed7-518f-4d8b-aac8-2cedd5e3286a';
    $pane = new stdClass();
    $pane->pid = 'new-41d934b6-f767-4675-bd00-e9524f3c0477';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => 'fA1pg0Ubd1zgx1mvzHkFUGaNoMb4Gs0s',
      'context' => array(),
      'override_title' => 1,
      'override_title_text' => 'Post date',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '41d934b6-f767-4675-bd00-e9524f3c0477';
    $display->content['new-41d934b6-f767-4675-bd00-e9524f3c0477'] = $pane;
    $display->panels['sidebar'][1] = 'new-41d934b6-f767-4675-bd00-e9524f3c0477';
    $pane = new stdClass();
    $pane->pid = 'new-0e10d916-e69d-4114-9399-21b2b636cf36';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => 'gJEl0bHjuvEHlQ0UZTb6Gq6xb11CtHQk',
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Section',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0e10d916-e69d-4114-9399-21b2b636cf36';
    $display->content['new-0e10d916-e69d-4114-9399-21b2b636cf36'] = $pane;
    $display->panels['sidebar'][2] = 'new-0e10d916-e69d-4114-9399-21b2b636cf36';
    $pane = new stdClass();
    $pane->pid = 'new-8ca1fb1d-7d4a-4bfe-a7ff-88ae59027a0d';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => 'NYglB4K37RuIXVUKIKv5nNMcs6y1S4o6',
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Space',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8ca1fb1d-7d4a-4bfe-a7ff-88ae59027a0d';
    $display->content['new-8ca1fb1d-7d4a-4bfe-a7ff-88ae59027a0d'] = $pane;
    $display->panels['sidebar'][3] = 'new-8ca1fb1d-7d4a-4bfe-a7ff-88ae59027a0d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_node_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_node_panel_context_2';
  $handler->task = 'search';
  $handler->subtask = 'node';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Solr Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'solr',
          'settings' => NULL,
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'search_api_index',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'brenham_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_styles_well',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e7c77d5a-7ace-402b-87dd-fee34c3ec06c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3e971e78-e7f7-4dd3-8528-4c6f21ef043b';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'panopoly_search-search_solr_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '25',
      'fields_override' => array(
        'field_featured_image' => 1,
        'title' => 1,
        'body' => 1,
        'field_featured_image_1' => 1,
      ),
      'exposed' => array(
        'widget_title' => '',
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'context' => array(
        0 => 'argument_string_1',
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_mode' => 'teaser',
      'widget_title' => '',
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3e971e78-e7f7-4dd3-8528-4c6f21ef043b';
    $display->content['new-3e971e78-e7f7-4dd3-8528-4c6f21ef043b'] = $pane;
    $display->panels['contentmain'][0] = 'new-3e971e78-e7f7-4dd3-8528-4c6f21ef043b';
    $pane = new stdClass();
    $pane->pid = 'new-df115ba8-c939-4206-9572-794382ed769c';
    $pane->panel = 'header';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'node',
      'form' => 'simple',
      'path_type' => 'default',
      'path' => '',
      'override_prompt' => 0,
      'prompt' => '',
      'context' => 'argument_string_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'df115ba8-c939-4206-9572-794382ed769c';
    $display->content['new-df115ba8-c939-4206-9572-794382ed769c'] = $pane;
    $display->panels['header'][0] = 'new-df115ba8-c939-4206-9572-794382ed769c';
    $pane = new stdClass();
    $pane->pid = 'new-ab625399-2707-4272-9f69-84793e6873d5';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => 'Shb0Q1vWgCArrHrjHszTyhl2jaEhIjzW',
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ab625399-2707-4272-9f69-84793e6873d5';
    $display->content['new-ab625399-2707-4272-9f69-84793e6873d5'] = $pane;
    $display->panels['sidebar'][0] = 'new-ab625399-2707-4272-9f69-84793e6873d5';
    $pane = new stdClass();
    $pane->pid = 'new-20a80760-3730-4c46-8d76-ffafd5429291';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => '6NILbvqD1zpW1Fd6w9agY0q6ZLORxAcU',
      'context' => array(),
      'override_title' => 1,
      'override_title_text' => 'Post date',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '20a80760-3730-4c46-8d76-ffafd5429291';
    $display->content['new-20a80760-3730-4c46-8d76-ffafd5429291'] = $pane;
    $display->panels['sidebar'][1] = 'new-20a80760-3730-4c46-8d76-ffafd5429291';
    $pane = new stdClass();
    $pane->pid = 'new-e7f2934f-d278-4714-998f-5ca058392ab0';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => 'HSqINVsF9ZdDxgE7V8uur7mG8V9mDwoM',
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Section',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e7f2934f-d278-4714-998f-5ca058392ab0';
    $display->content['new-e7f2934f-d278-4714-998f-5ca058392ab0'] = $pane;
    $display->panels['sidebar'][2] = 'new-e7f2934f-d278-4714-998f-5ca058392ab0';
    $pane = new stdClass();
    $pane->pid = 'new-da0a3db8-2661-4a38-966d-413036c49b46';
    $pane->panel = 'sidebar';
    $pane->type = 'facet';
    $pane->subtype = 'facet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'delta' => 'HvLOPCkVDNau3ZAk5LBJYek3buGzJekf',
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Space',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'da0a3db8-2661-4a38-966d-413036c49b46';
    $display->content['new-da0a3db8-2661-4a38-966d-413036c49b46'] = $pane;
    $display->panels['sidebar'][3] = 'new-da0a3db8-2661-4a38-966d-413036c49b46';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_node_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_user_panel_context';
  $handler->task = 'search';
  $handler->subtask = 'user';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Database Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'brenham_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0a93236a-de4b-495f-95bb-9af04e45be86';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ed2eed1d-4081-4d72-942e-954388b0a8c3';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_user_search-search_user_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '20',
      'fields_override' => array(
        'uid' => 0,
        'field_user_display_name' => 1,
        'mail' => 1,
        'field_user_picture' => 1,
        'field_user_about' => 1,
      ),
      'exposed' => array(
        'widget_title' => '',
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'context' => array(
        0 => 'argument_string_1',
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_mode' => 'teaser',
      'widget_title' => '',
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ed2eed1d-4081-4d72-942e-954388b0a8c3';
    $display->content['new-ed2eed1d-4081-4d72-942e-954388b0a8c3'] = $pane;
    $display->panels['contentmain'][0] = 'new-ed2eed1d-4081-4d72-942e-954388b0a8c3';
    $pane = new stdClass();
    $pane->pid = 'new-deab1fb8-90b7-478f-a1a8-3473030357c1';
    $pane->panel = 'header';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'user',
      'form' => 'simple',
      'path_type' => 'default',
      'path' => 'search/user',
      'override_prompt' => 0,
      'prompt' => '',
      'context' => 'argument_string_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'deab1fb8-90b7-478f-a1a8-3473030357c1';
    $display->content['new-deab1fb8-90b7-478f-a1a8-3473030357c1'] = $pane;
    $display->panels['header'][0] = 'new-deab1fb8-90b7-478f-a1a8-3473030357c1';
    $pane = new stdClass();
    $pane->pid = 'new-20dd4f46-2c99-4f98-a3b8-ccafbc46f541';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-l0aef2Lyf50iLShW3gCJg8JWaun2956f';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Spaces',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(),
      'style' => 'oa_styles_oa_pane',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '20dd4f46-2c99-4f98-a3b8-ccafbc46f541';
    $display->content['new-20dd4f46-2c99-4f98-a3b8-ccafbc46f541'] = $pane;
    $display->panels['sidebar'][0] = 'new-20dd4f46-2c99-4f98-a3b8-ccafbc46f541';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_user_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_user_panel_context_2';
  $handler->task = 'search';
  $handler->subtask = 'user';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Solr Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'solr',
          'settings' => NULL,
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'oa_search_user_index',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'brenham_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dc88113a-4843-4e74-a42a-8ec21e0e402f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-090ab049-4c76-4941-8353-8eed24fdb748';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_user_solr_search-search_user_solr_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '20',
      'fields_override' => array(
        'uid' => 1,
        'field_user_display_name' => 1,
        'mail' => 1,
        'field_user_picture' => 1,
        'field_user_about' => 1,
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
      'widget_title' => '',
      'context' => array(
        0 => 'argument_string_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '090ab049-4c76-4941-8353-8eed24fdb748';
    $display->content['new-090ab049-4c76-4941-8353-8eed24fdb748'] = $pane;
    $display->panels['contentmain'][0] = 'new-090ab049-4c76-4941-8353-8eed24fdb748';
    $pane = new stdClass();
    $pane->pid = 'new-6c016fd5-af9b-4384-821c-594a9c99cce1';
    $pane->panel = 'header';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'user',
      'form' => 'simple',
      'path_type' => 'default',
      'path' => 'search/user',
      'override_prompt' => 0,
      'prompt' => '',
      'context' => 'argument_string_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6c016fd5-af9b-4384-821c-594a9c99cce1';
    $display->content['new-6c016fd5-af9b-4384-821c-594a9c99cce1'] = $pane;
    $display->panels['header'][0] = 'new-6c016fd5-af9b-4384-821c-594a9c99cce1';
    $pane = new stdClass();
    $pane->pid = 'new-33bbfee9-a540-462a-8dd3-5fc7ec57bca8';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-157RtPgyeaCVFXrUW2NuaIpHMzYTWc6k';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Spaces',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(),
      'style' => 'oa_styles_oa_pane',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '33bbfee9-a540-462a-8dd3-5fc7ec57bca8';
    $display->content['new-33bbfee9-a540-462a-8dd3-5fc7ec57bca8'] = $pane;
    $display->panels['sidebar'][0] = 'new-33bbfee9-a540-462a-8dd3-5fc7ec57bca8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_user_panel_context_2'] = $handler;

  return $export;
}
