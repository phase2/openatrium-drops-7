<?php
/**
 * @file
 * oa_wiki.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_wiki_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_wiki_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:oa_wiki_page:default';
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
      'identifier' => 'Wki Author',
      'keyword' => 'user',
      'name' => 'entity_from_schema:uid-node-user',
      'context' => 'panelizer',
      'id' => 1,
    ),
    1 => array(
      'identifier' => 'Space',
      'keyword' => 'space',
      'name' => 'entity_from_field:og_group_ref-node-node',
      'delta' => 0,
      'context' => 'panelizer',
      'id' => 1,
    ),
    2 => array(
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
  $display->uuid = 'bb6a940f-7670-401e-a236-7ab1c5798251';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_wiki_page:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-75a6ef87-6704-432f-90cf-62f15ce2ec6c';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_users_submitted';
  $pane->subtype = 'oa_users_submitted';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'align' => '0',
    'label' => 1,
    'date' => '0',
    'picture' => 0,
    'image_style' => 'oa_medium_thumbnail',
    'node_title' => 1,
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'form_build_id' => 'form-BkJBiLahmw2VSFnNLflf1vsCer3lkJwBs7Cru9zbp78',
    'form_token' => '3t8MqfSEvIfOMIPdnCefRjmo5eMffDkS7_ETQz2wH4Q',
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
  $pane->uuid = '75a6ef87-6704-432f-90cf-62f15ce2ec6c';
  $display->content['new-75a6ef87-6704-432f-90cf-62f15ce2ec6c'] = $pane;
  $display->panels['contentmain'][0] = 'new-75a6ef87-6704-432f-90cf-62f15ce2ec6c';
  $pane = new stdClass();
  $pane->pid = 'new-7746f122-1e4b-445f-8cf4-d15ef627d71f';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7746f122-1e4b-445f-8cf4-d15ef627d71f';
  $display->content['new-7746f122-1e4b-445f-8cf4-d15ef627d71f'] = $pane;
  $display->panels['contentmain'][1] = 'new-7746f122-1e4b-445f-8cf4-d15ef627d71f';
  $pane = new stdClass();
  $pane->pid = 'new-32c308fc-ae57-43df-a4fa-8667a747ea6f';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '32c308fc-ae57-43df-a4fa-8667a747ea6f';
  $display->content['new-32c308fc-ae57-43df-a4fa-8667a747ea6f'] = $pane;
  $display->panels['contentmain'][2] = 'new-32c308fc-ae57-43df-a4fa-8667a747ea6f';
  $pane = new stdClass();
  $pane->pid = 'new-a811ab4b-b391-4bac-aee2-f0b6bdb5a65d';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'full',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a811ab4b-b391-4bac-aee2-f0b6bdb5a65d';
  $display->content['new-a811ab4b-b391-4bac-aee2-f0b6bdb5a65d'] = $pane;
  $display->panels['contentmain'][3] = 'new-a811ab4b-b391-4bac-aee2-f0b6bdb5a65d';
  $pane = new stdClass();
  $pane->pid = 'new-fd50a4cf-8298-4584-8504-b21e0e215e78';
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
  $pane->uuid = 'fd50a4cf-8298-4584-8504-b21e0e215e78';
  $display->content['new-fd50a4cf-8298-4584-8504-b21e0e215e78'] = $pane;
  $display->panels['contentmain'][4] = 'new-fd50a4cf-8298-4584-8504-b21e0e215e78';
  $pane = new stdClass();
  $pane->pid = 'new-e46086d2-3bda-405b-b9b1-6d44d79ea78e';
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
  $pane->uuid = 'e46086d2-3bda-405b-b9b1-6d44d79ea78e';
  $display->content['new-e46086d2-3bda-405b-b9b1-6d44d79ea78e'] = $pane;
  $display->panels['contentmain'][5] = 'new-e46086d2-3bda-405b-b9b1-6d44d79ea78e';
  $pane = new stdClass();
  $pane->pid = 'new-7ddbd76b-3d46-436a-b91b-5078220845a8';
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
  $pane->uuid = '7ddbd76b-3d46-436a-b91b-5078220845a8';
  $display->content['new-7ddbd76b-3d46-436a-b91b-5078220845a8'] = $pane;
  $display->panels['sidebar'][0] = 'new-7ddbd76b-3d46-436a-b91b-5078220845a8';
  $pane = new stdClass();
  $pane->pid = 'new-05a2ca63-14bd-45a1-bab5-147952670034';
  $pane->panel = 'sidebar';
  $pane->type = 'oa_files_treeview';
  $pane->subtype = 'oa_files_treeview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'oa_files_treeview_mode' => '0',
    'oa_files_menu_mode' => '0',
    'oa_files_fields' => array(
      'size' => 0,
      'date' => 0,
      'modified' => 0,
      'filename' => 0,
      'body' => 0,
    ),
    'oa_files_showcount' => 0,
    'oa_files_showfilter' => 0,
    'oa_files_actions' => array(),
    'oa_files_sort' => 'title',
    'oa_files_dir' => 'ASC',
    'oa_files_all' => 0,
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'override_title' => 0,
    'override_title_text' => '',
    'og_menu_single_depth' => '0',
    'og_menu_single_parent' => 'auto',
    'oa_files_vocabulary' => '0',
    'oa_files_action_title_download' => 'Download',
    'oa_files_action_download' => '1',
    'oa_files_action_title_view' => 'View metadata',
    'oa_files_action_view' => '1',
    'oa_files_action_title_edit' => 'Edit metadata',
    'oa_files_action_edit' => '1',
    'oa_files_action_title_folder' => 'New folder',
    'oa_files_action_folder' => '1',
    'oa_files_action_title_addfile' => 'Add file',
    'oa_files_action_addfile' => '1',
    'form_build_id' => 'form-1Ov4KU5yfJbNT4AKmKEyTuJOVatmfCeGdeMNBgbkDaU',
    'form_token' => 'RbqUdq3pbUv-OlBVDaXHXiFcLdPijr1eoQ1zhKS00VA',
    'form_id' => 'oa_files_treeview_settings_form',
    'op' => 'Finish',
    'override_title_heading' => 'h2',
    'oa_files_auto' => 1,
    'oa_files_space' => 'CURRENT',
    'oa_files_subspaces' => 0,
    'oa_files_section' => array(
      0 => '-1',
    ),
    'oa_files_only_attached' => 0,
    'oa_files_hide_empty' => 0,
    'oa_files_action_title_adddocument' => 'Add document',
    'oa_files_action_adddocument' => '1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '05a2ca63-14bd-45a1-bab5-147952670034';
  $display->content['new-05a2ca63-14bd-45a1-bab5-147952670034'] = $pane;
  $display->panels['sidebar'][1] = 'new-05a2ca63-14bd-45a1-bab5-147952670034';
  $pane = new stdClass();
  $pane->pid = 'new-61664bae-1939-49e7-a25e-f958bf7a99f6';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_oa_media';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'media_colorbox',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'file_view_mode' => 'teaser',
      'colorbox_view_mode' => 'default',
      'fixed_width' => '',
      'fixed_height' => '',
      'colorbox_gallery' => 'page',
      'colorbox_gallery_custom' => '',
      'colorbox_caption' => 'title',
      'audio_playlist' => 0,
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'view_mode' => NULL,
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '61664bae-1939-49e7-a25e-f958bf7a99f6';
  $display->content['new-61664bae-1939-49e7-a25e-f958bf7a99f6'] = $pane;
  $display->panels['sidebar'][2] = 'new-61664bae-1939-49e7-a25e-f958bf7a99f6';
  $pane = new stdClass();
  $pane->pid = 'new-726f799f-b273-4c70-bb8e-8fa078660e60';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '726f799f-b273-4c70-bb8e-8fa078660e60';
  $display->content['new-726f799f-b273-4c70-bb8e-8fa078660e60'] = $pane;
  $display->panels['sidebar'][3] = 'new-726f799f-b273-4c70-bb8e-8fa078660e60';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_wiki_page:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_wiki_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'featured';
  $panelizer->name = 'node:oa_wiki_page:default:featured';
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
  $display->uuid = 'd5bdeeaa-12a0-40e6-9fa6-3860a3e653b3';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_wiki_page:default:featured';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c49eb239-66a4-4c8b-be93-3373a331e5d0';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c49eb239-66a4-4c8b-be93-3373a331e5d0';
  $display->content['new-c49eb239-66a4-4c8b-be93-3373a331e5d0'] = $pane;
  $display->panels['middle'][0] = 'new-c49eb239-66a4-4c8b-be93-3373a331e5d0';
  $pane = new stdClass();
  $pane->pid = 'new-be84fac6-1dd9-4fb1-9f83-75c9b0480762';
  $pane->panel = 'middle';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'be84fac6-1dd9-4fb1-9f83-75c9b0480762';
  $display->content['new-be84fac6-1dd9-4fb1-9f83-75c9b0480762'] = $pane;
  $display->panels['middle'][1] = 'new-be84fac6-1dd9-4fb1-9f83-75c9b0480762';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_wiki_page:default:featured'] = $panelizer;

  return $export;
}
