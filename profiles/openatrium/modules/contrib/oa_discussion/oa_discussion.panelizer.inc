<?php
/**
 * @file
 * oa_discussion.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_discussion_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_discussion_post:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_discussion_post';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array(
    0 => array(
      'identifier' => 'Space',
      'keyword' => 'space',
      'name' => 'entity_from_field:og_group_ref-node-node',
      'delta' => 0,
      'context' => 'panelizer',
      'id' => 1,
    ),
    1 => array(
      'identifier' => 'Section',
      'keyword' => 'space',
      'name' => 'entity_from_field:oa_section_ref-node-node',
      'delta' => 0,
      'context' => 'panelizer',
      'id' => 1,
    ),
  );
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'sidebar' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f2483186-0bec-4855-a087-1b170ce6c469';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5f45707c-08ca-44dc-813e-1d8c33bd88c9';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'open_atrium_discussions-original_post';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'view_mode' => 'teaser',
      'widget_title' => '',
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
      'override_title' => '',
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
    $pane->uuid = '5f45707c-08ca-44dc-813e-1d8c33bd88c9';
    $display->content['new-5f45707c-08ca-44dc-813e-1d8c33bd88c9'] = $pane;
    $display->panels['contentmain'][0] = 'new-5f45707c-08ca-44dc-813e-1d8c33bd88c9';
    $pane = new stdClass();
    $pane->pid = 'new-64688a22-84b9-41b7-baaa-d939473b89c8';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'open_atrium_discussions-replies';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'view_mode' => 'teaser',
      'widget_title' => NULL,
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '64688a22-84b9-41b7-baaa-d939473b89c8';
    $display->content['new-64688a22-84b9-41b7-baaa-d939473b89c8'] = $pane;
    $display->panels['contentmain'][1] = 'new-64688a22-84b9-41b7-baaa-d939473b89c8';
    $pane = new stdClass();
    $pane->pid = 'new-c0403a30-33da-45c4-b123-96ec401fbd96';
    $pane->panel = 'contentmain';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c0403a30-33da-45c4-b123-96ec401fbd96';
    $display->content['new-c0403a30-33da-45c4-b123-96ec401fbd96'] = $pane;
    $display->panels['contentmain'][2] = 'new-c0403a30-33da-45c4-b123-96ec401fbd96';
    $pane = new stdClass();
    $pane->pid = 'new-ffc49e54-b3e0-4641-9354-d74e5ed2d732';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_discussion_reply';
    $pane->subtype = 'oa_discussion_reply';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-iVavqOC6bzBA_ErXsVB7zwrNYyoHM1BHhC1eMooaeqk',
      'form_token' => '4CdQgzPlDP9xxRzmRMKu1oy6AB4yaHSwnO7i8ygSNj0',
      'form_id' => 'oa_discussion_reply_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ffc49e54-b3e0-4641-9354-d74e5ed2d732';
    $display->content['new-ffc49e54-b3e0-4641-9354-d74e5ed2d732'] = $pane;
    $display->panels['contentmain'][3] = 'new-ffc49e54-b3e0-4641-9354-d74e5ed2d732';
    $pane = new stdClass();
    $pane->pid = 'new-08eeb46c-9c1b-4811-9652-2f546cfd67d9';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '08eeb46c-9c1b-4811-9652-2f546cfd67d9';
    $display->content['new-08eeb46c-9c1b-4811-9652-2f546cfd67d9'] = $pane;
    $display->panels['contentmain'][4] = 'new-08eeb46c-9c1b-4811-9652-2f546cfd67d9';
    $pane = new stdClass();
    $pane->pid = 'new-0af56eac-2101-473d-8c5c-782928eea43b';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '0af56eac-2101-473d-8c5c-782928eea43b';
    $display->content['new-0af56eac-2101-473d-8c5c-782928eea43b'] = $pane;
    $display->panels['contentmain'][5] = 'new-0af56eac-2101-473d-8c5c-782928eea43b';
    $pane = new stdClass();
    $pane->pid = 'new-b9d0d392-f615-4c92-9166-093a30cf05cd';
    $pane->panel = 'sidebar';
    $pane->type = 'panels_mini';
    $pane->subtype = 'section_sidebar_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
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
    $pane->uuid = 'b9d0d392-f615-4c92-9166-093a30cf05cd';
    $display->content['new-b9d0d392-f615-4c92-9166-093a30cf05cd'] = $pane;
    $display->panels['sidebar'][0] = 'new-b9d0d392-f615-4c92-9166-093a30cf05cd';
    $pane = new stdClass();
    $pane->pid = 'new-35d06055-8f3f-4790-b785-bb5d0d336ecb';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'open_atrium_discussions-attachments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
      'widget_title' => NULL,
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
      'context' => array(
        0 => 'panelizer',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '35d06055-8f3f-4790-b785-bb5d0d336ecb';
    $display->content['new-35d06055-8f3f-4790-b785-bb5d0d336ecb'] = $pane;
    $display->panels['sidebar'][1] = 'new-35d06055-8f3f-4790-b785-bb5d0d336ecb';
    $pane = new stdClass();
    $pane->pid = 'new-5391a87c-2b91-4ee7-a17d-07a99957758b';
    $pane->panel = 'sidebar';
    $pane->type = 'panels_mini';
    $pane->subtype = 'default_section_sidebar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5391a87c-2b91-4ee7-a17d-07a99957758b';
    $display->content['new-5391a87c-2b91-4ee7-a17d-07a99957758b'] = $pane;
    $display->panels['sidebar'][2] = 'new-5391a87c-2b91-4ee7-a17d-07a99957758b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_discussion_post:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_section:oa_section_discussion';
  $panelizer->title = 'Discussion Section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_section';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe_node_access';
  $panelizer->contexts = array();
  $panelizer->relationships = array(
    0 => array(
      'identifier' => 'Space',
      'keyword' => 'space',
      'name' => 'entity_from_field:og_group_ref-node-node',
      'delta' => 0,
      'context' => 'panelizer',
      'id' => 1,
    ),
  );
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'bryant_flipped_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_styles_oa_pane',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '82894af0-3dae-495b-a609-56786f6327f7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b5034a79-ddc6-4fb5-b939-e21cdcfcb6b6';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b5034a79-ddc6-4fb5-b939-e21cdcfcb6b6';
    $display->content['new-b5034a79-ddc6-4fb5-b939-e21cdcfcb6b6'] = $pane;
    $display->panels['contentmain'][0] = 'new-b5034a79-ddc6-4fb5-b939-e21cdcfcb6b6';
    $pane = new stdClass();
    $pane->pid = 'new-6e7b549b-c4e3-4462-b4d2-a02b9db9eff4';
    $pane->panel = 'contentmain';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6e7b549b-c4e3-4462-b4d2-a02b9db9eff4';
    $display->content['new-6e7b549b-c4e3-4462-b4d2-a02b9db9eff4'] = $pane;
    $display->panels['contentmain'][1] = 'new-6e7b549b-c4e3-4462-b4d2-a02b9db9eff4';
    $pane = new stdClass();
    $pane->pid = 'new-c7a43a77-fca5-4cc3-829c-220e2142ae5e';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'open_atrium_discussions-discussion_topics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'type' => 'oa_discussion_post',
      ),
      'context' => array(
        1 => 'panelizer',
      ),
      'view_mode' => 'teaser',
      'widget_title' => NULL,
      'items_per_page' => '20',
      'use_pager' => 1,
      'pager_id' => '',
      'offset' => '',
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'oa_styles_oa_pane',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c7a43a77-fca5-4cc3-829c-220e2142ae5e';
    $display->content['new-c7a43a77-fca5-4cc3-829c-220e2142ae5e'] = $pane;
    $display->panels['contentmain'][2] = 'new-c7a43a77-fca5-4cc3-829c-220e2142ae5e';
    $pane = new stdClass();
    $pane->pid = 'new-b485b8e9-9c6a-4242-8058-06de9082942a';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b485b8e9-9c6a-4242-8058-06de9082942a';
    $display->content['new-b485b8e9-9c6a-4242-8058-06de9082942a'] = $pane;
    $display->panels['contentmain'][3] = 'new-b485b8e9-9c6a-4242-8058-06de9082942a';
    $pane = new stdClass();
    $pane->pid = 'new-e9603b15-2c3a-4b58-8290-692183e7b687';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e9603b15-2c3a-4b58-8290-692183e7b687';
    $display->content['new-e9603b15-2c3a-4b58-8290-692183e7b687'] = $pane;
    $display->panels['contentmain'][4] = 'new-e9603b15-2c3a-4b58-8290-692183e7b687';
    $pane = new stdClass();
    $pane->pid = 'new-f40e5cbc-b456-4d18-986e-5d516011a7de';
    $pane->panel = 'sidebar';
    $pane->type = 'oa_widgets_content_visibility';
    $pane->subtype = 'oa_widgets_content_visibility';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-Mu6nO6nBWsEMQS3rgB1GQ44dcra2o5gifVUMggSJ_u4',
      'form_token' => 'BzH8uxEwTjsQGuqkcXBIlcjCxMTFGGufXWz-7ckhC2M',
      'form_id' => 'oa_widgets_content_visibility_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f40e5cbc-b456-4d18-986e-5d516011a7de';
    $display->content['new-f40e5cbc-b456-4d18-986e-5d516011a7de'] = $pane;
    $display->panels['sidebar'][0] = 'new-f40e5cbc-b456-4d18-986e-5d516011a7de';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_section:oa_section_discussion'] = $panelizer;

  return $export;
}
