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
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_discussion_post';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:oa_discussion_post:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
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
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
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
  $display->title = '';
  $display->uuid = 'f2483186-0bec-4855-a087-1b170ce6c469';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_discussion_post:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a1d93472-6b82-406d-b6b6-22aace42217a';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_users_submitted';
  $pane->subtype = 'oa_users_submitted';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'align' => '0',
    'label' => 1,
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'form_build_id' => 'form-qKg4KcSf7VuHM5ffY6pV_5tXwVlSs3-NfI1MTAAjctw',
    'form_token' => '7mY1E1RH_d8YoFnu99LjqKZa1oqJB_tFj9lmvnHmIuo',
    'form_id' => 'oa_user_submitted_form',
    'op' => 'Finish',
    'date' => '0',
    'node_title' => 1,
    'picture' => 0,
    'image_style' => 'oa_medium_thumbnail',
    'hide_author' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a1d93472-6b82-406d-b6b6-22aace42217a';
  $display->content['new-a1d93472-6b82-406d-b6b6-22aace42217a'] = $pane;
  $display->panels['contentmain'][0] = 'new-a1d93472-6b82-406d-b6b6-22aace42217a';
  $pane = new stdClass();
  $pane->pid = 'new-bd0d0809-6830-46ab-8f33-272115d12b49';
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
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'bd0d0809-6830-46ab-8f33-272115d12b49';
  $display->content['new-bd0d0809-6830-46ab-8f33-272115d12b49'] = $pane;
  $display->panels['contentmain'][1] = 'new-bd0d0809-6830-46ab-8f33-272115d12b49';
  $pane = new stdClass();
  $pane->pid = 'new-779395e1-2a93-4b60-b511-a461e30ac9df';
  $pane->panel = 'contentmain';
  $pane->type = 'node_terms';
  $pane->subtype = 'node_terms';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'vid' => '0',
    'term_format' => 'term-links',
    'link' => 1,
    'term_delimiter' => ', ',
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '779395e1-2a93-4b60-b511-a461e30ac9df';
  $display->content['new-779395e1-2a93-4b60-b511-a461e30ac9df'] = $pane;
  $display->panels['contentmain'][2] = 'new-779395e1-2a93-4b60-b511-a461e30ac9df';
  $pane = new stdClass();
  $pane->pid = 'new-c0403a30-33da-45c4-b123-96ec401fbd96';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'build_mode' => 'full',
    'identifier' => '',
    'link' => 1,
    'context' => 'panelizer',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c0403a30-33da-45c4-b123-96ec401fbd96';
  $display->content['new-c0403a30-33da-45c4-b123-96ec401fbd96'] = $pane;
  $display->panels['contentmain'][3] = 'new-c0403a30-33da-45c4-b123-96ec401fbd96';
  $pane = new stdClass();
  $pane->pid = 'new-a95c7986-ab4b-4cfc-8bb8-7174a505396a';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_oa_related';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'paragraphs_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'full',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a95c7986-ab4b-4cfc-8bb8-7174a505396a';
  $display->content['new-a95c7986-ab4b-4cfc-8bb8-7174a505396a'] = $pane;
  $display->panels['contentmain'][4] = 'new-a95c7986-ab4b-4cfc-8bb8-7174a505396a';
  $pane = new stdClass();
  $pane->pid = 'new-cc5113ed-3c85-45e7-b49c-a5c93ad6e757';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_oa_media';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_table',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'cc5113ed-3c85-45e7-b49c-a5c93ad6e757';
  $display->content['new-cc5113ed-3c85-45e7-b49c-a5c93ad6e757'] = $pane;
  $display->panels['contentmain'][5] = 'new-cc5113ed-3c85-45e7-b49c-a5c93ad6e757';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '08eeb46c-9c1b-4811-9652-2f546cfd67d9';
  $display->content['new-08eeb46c-9c1b-4811-9652-2f546cfd67d9'] = $pane;
  $display->panels['contentmain'][6] = 'new-08eeb46c-9c1b-4811-9652-2f546cfd67d9';
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
    'override_title' => 1,
    'override_title_text' => 'New Reply',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '0af56eac-2101-473d-8c5c-782928eea43b';
  $display->content['new-0af56eac-2101-473d-8c5c-782928eea43b'] = $pane;
  $display->panels['contentmain'][7] = 'new-0af56eac-2101-473d-8c5c-782928eea43b';
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
  $pane->pid = 'new-b116ce80-5c90-425a-aece-b73ce7992fe3';
  $pane->panel = 'sidebar';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_comment_media-commentnode_attachments';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'panelizer',
    ),
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b116ce80-5c90-425a-aece-b73ce7992fe3';
  $display->content['new-b116ce80-5c90-425a-aece-b73ce7992fe3'] = $pane;
  $display->panels['sidebar'][1] = 'new-b116ce80-5c90-425a-aece-b73ce7992fe3';
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_discussion_post:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_discussion_post';
  $panelizer->access = array();
  $panelizer->view_mode = 'featured';
  $panelizer->name = 'node:oa_discussion_post:default:featured';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '62e61500-65e2-4fd0-a240-8b4ddfe527c5';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_discussion_post:default:featured';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8cd46244-72e5-425c-aac0-60b6f5ad2f3c';
  $pane->panel = 'middle';
  $pane->type = 'oa_users_submitted';
  $pane->subtype = 'oa_users_submitted';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'align' => '1',
    'label' => 1,
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'date' => '0',
    'form_build_id' => 'form-PIClH40X085sARAQ5utMXnGAUs781iDn_tYiBmo8xq0',
    'form_token' => '8YTbwsFFJjryaxS8biQyqmDKZMu52T9ZxBM5xrUmltw',
    'form_id' => 'oa_user_submitted_form',
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
  $pane->uuid = '8cd46244-72e5-425c-aac0-60b6f5ad2f3c';
  $display->content['new-8cd46244-72e5-425c-aac0-60b6f5ad2f3c'] = $pane;
  $display->panels['middle'][0] = 'new-8cd46244-72e5-425c-aac0-60b6f5ad2f3c';
  $pane = new stdClass();
  $pane->pid = 'new-44de22ec-3352-4151-9c92-b86785d0b67d';
  $pane->panel = 'middle';
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
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '44de22ec-3352-4151-9c92-b86785d0b67d';
  $display->content['new-44de22ec-3352-4151-9c92-b86785d0b67d'] = $pane;
  $display->panels['middle'][1] = 'new-44de22ec-3352-4151-9c92-b86785d0b67d';
  $pane = new stdClass();
  $pane->pid = 'new-6c23b0e8-376e-44f9-b776-313f013ec98d';
  $pane->panel = 'middle';
  $pane->type = 'node_comment_wrapper';
  $pane->subtype = 'node_comment_wrapper';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mode' => '1',
    'comments_per_page' => '50',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6c23b0e8-376e-44f9-b776-313f013ec98d';
  $display->content['new-6c23b0e8-376e-44f9-b776-313f013ec98d'] = $pane;
  $display->panels['middle'][2] = 'new-6c23b0e8-376e-44f9-b776-313f013ec98d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_discussion_post:default:featured'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Discussion Section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_section';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:oa_section:oa_section_discussion';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
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
  $display = new panels_display();
  $display->layout = 'radix_bryant_flipped';
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
  $display->title = '';
  $display->uuid = '82894af0-3dae-495b-a609-56786f6327f7';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_section:oa_section_discussion';
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
  $pane->pid = 'new-53a7e967-2673-47b3-86fa-bf985765f6ca';
  $pane->panel = 'contentmain';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_comment_topics-comment_topics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
    'exposed' => array(
      'type' => array(),
      'flagged' => '0',
      'og_group_ref_target_id' => 'CURRENT',
      'og_group_ref_target_id_mine' => 0,
      'og_subspaces_view_all' => 0,
      'og_subspaces_view_parent' => 0,
      'oa_section_ref_target_id' => '',
    ),
    'show_exposed_form' => 0,
    'use_pager' => 1,
    'pager_id' => '1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '53a7e967-2673-47b3-86fa-bf985765f6ca';
  $display->content['new-53a7e967-2673-47b3-86fa-bf985765f6ca'] = $pane;
  $display->panels['contentmain'][2] = 'new-53a7e967-2673-47b3-86fa-bf985765f6ca';
  $pane = new stdClass();
  $pane->pid = 'new-a3f6416e-1faf-4899-ae8d-c398767509dd';
  $pane->panel = 'contentmain';
  $pane->type = 'node_comment_wrapper';
  $pane->subtype = 'node_comment_wrapper';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mode' => '1',
    'comments_per_page' => '50',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a3f6416e-1faf-4899-ae8d-c398767509dd';
  $display->content['new-a3f6416e-1faf-4899-ae8d-c398767509dd'] = $pane;
  $display->panels['contentmain'][3] = 'new-a3f6416e-1faf-4899-ae8d-c398767509dd';
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
