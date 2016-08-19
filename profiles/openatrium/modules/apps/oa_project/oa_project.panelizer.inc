<?php
/**
 * @file
 * oa_project.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_project_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Project';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_space';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:oa_space:space_project';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_selby_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
      'header' => NULL,
      'middle' => NULL,
      'secondcolumn1' => NULL,
      'secondcolumn2' => NULL,
      'footer' => NULL,
      'contentheader' => NULL,
      'contentcolumn1' => NULL,
      'contentcolumn2' => NULL,
      'contentfooter' => NULL,
    ),
    'sidebar' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '0e3fa956-fb7b-4e52-82aa-b79a16b2e38c';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:oa_space:space_project';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7a5494e0-8193-4be3-9f00-6c180f2e0e02';
  $pane->panel = 'contentfooter';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7a5494e0-8193-4be3-9f00-6c180f2e0e02';
  $display->content['new-7a5494e0-8193-4be3-9f00-6c180f2e0e02'] = $pane;
  $display->panels['contentfooter'][0] = 'new-7a5494e0-8193-4be3-9f00-6c180f2e0e02';
  $pane = new stdClass();
  $pane->pid = 'new-8a1e4648-8f30-4c4d-a46e-17db70a5452c';
  $pane->panel = 'contentheader';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_fullcalendar-oa_calendar_week';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'exposed' => array(
      'og_group_ref_target_id' => 'CURRENT',
      'og_group_ref_target_id_mine' => 0,
      'og_subspaces_view_all' => 1,
      'og_subspaces_view_parent' => 0,
      'oa_section_ref_target_id' => 'All',
      'flagged' => '0',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8a1e4648-8f30-4c4d-a46e-17db70a5452c';
  $display->content['new-8a1e4648-8f30-4c4d-a46e-17db70a5452c'] = $pane;
  $display->panels['contentheader'][0] = 'new-8a1e4648-8f30-4c4d-a46e-17db70a5452c';
  $pane = new stdClass();
  $pane->pid = 'new-0f31d7ec-a646-4479-989b-70773905e940';
  $pane->panel = 'contentheader';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_comment_topics-comment_topics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
    'exposed' => array(
      'type' => 'oa_discussion_post',
      'flagged' => '0',
      'og_group_ref_target_id' => 'CURRENT',
      'og_group_ref_target_id_mine' => 0,
      'og_subspaces_view_all' => 1,
      'og_subspaces_view_parent' => 0,
      'oa_section_ref_target_id' => 'All',
    ),
    'show_exposed_form' => 0,
    'use_pager' => 1,
    'pager_id' => '1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'oa_styles_oa_pane',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0f31d7ec-a646-4479-989b-70773905e940';
  $display->content['new-0f31d7ec-a646-4479-989b-70773905e940'] = $pane;
  $display->panels['contentheader'][1] = 'new-0f31d7ec-a646-4479-989b-70773905e940';
  $pane = new stdClass();
  $pane->pid = 'new-269cdae1-1806-477a-ac1d-5376fba27e73';
  $pane->panel = 'contentheader';
  $pane->type = 'oa_files_treeview';
  $pane->subtype = 'oa_files_treeview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'oa_files_treeview_mode' => '1',
    'oa_files_menu_mode' => '0',
    'oa_files_fields' => array(
      'size' => 'size',
      'modified' => 'modified',
      'date' => 0,
      'filename' => 0,
      'body' => 0,
    ),
    'oa_files_showcount' => 0,
    'oa_files_showfilter' => 0,
    'oa_files_actions' => array(),
    'oa_files_sort' => 'changed',
    'oa_files_dir' => 'ASC',
    'oa_files_all' => 1,
    'oa_files_space' => 'CURRENT',
    'oa_files_section' => array(
      0 => '-1',
    ),
    'oa_files_only_attached' => 0,
    'oa_files_hide_empty' => 1,
    'oa_files_subspaces' => 1,
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'override_title' => 1,
    'override_title_text' => 'Recently Updated Files',
    'override_title_heading' => 'h2',
    'og_menu_single_depth' => '0',
    'og_menu_single_parent' => '0',
    'oa_files_vocabulary' => '',
    'oa_files_action_title_download' => 'Download',
    'oa_files_action_download' => '2',
    'oa_files_action_title_view' => 'View metadata',
    'oa_files_action_view' => '1',
    'oa_files_action_title_edit' => 'Edit metadata',
    'oa_files_action_edit' => '1',
    'oa_files_action_title_folder' => 'New folder',
    'oa_files_action_folder' => '1',
    'oa_files_action_title_addfile' => 'Add file',
    'oa_files_action_addfile' => '1',
    'form_build_id' => 'form-vox8krQH_KSFKesj8ti65vbCzgyPusmHUrNMF2GI62c',
    'form_token' => '0lfR4xLee4FMCk0XSbjjexJ9pCtpXiH5bXVN0_chD4Q',
    'form_id' => 'oa_files_treeview_settings_form',
    'op' => 'Finish',
    'context' => 'panelizer',
    'oa_files_auto' => 0,
    'oa_files_action_title_adddocument' => 'Add document',
    'oa_files_action_adddocument' => '1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'oa_styles_oa_pane',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '269cdae1-1806-477a-ac1d-5376fba27e73';
  $display->content['new-269cdae1-1806-477a-ac1d-5376fba27e73'] = $pane;
  $display->panels['contentheader'][2] = 'new-269cdae1-1806-477a-ac1d-5376fba27e73';
  $pane = new stdClass();
  $pane->pid = 'new-a813fc41-b2b1-4c9a-a533-fdbf58d8d707';
  $pane->panel = 'contentheader';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_worktracker-task_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'exposed' => array(
      'og_group_ref_target_id' => 'CURRENT',
      'og_group_ref_target_id_mine' => 0,
      'og_subspaces_view_all' => 1,
      'og_subspaces_view_parent' => 0,
      'oa_section_ref_target_id' => 'All',
      'keys' => '',
      'realname_1' => '',
      'realname' => '',
      'field_oa_worktracker_task_status_value' => array(),
      'field_oa_worktracker_priority_value' => array(),
      'field_oa_worktracker_task_type_value' => array(),
      'flagged' => '0',
    ),
    'show_exposed_form' => 1,
    'items_per_page' => '10',
    'fields_override' => array(
      'title' => 1,
      'timestamp' => 0,
      'field_oa_worktracker_duedate' => 1,
      'realname_1' => 0,
      'realname' => 1,
      'title_1' => 0,
      'field_oa_worktracker_priority' => 1,
      'field_oa_worktracker_task_type' => 1,
      'field_oa_worktracker_task_status' => 1,
      'comment_count' => 1,
      'last_updated' => 1,
    ),
    'override_title' => '',
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'view_settings' => 'table',
    'header_type' => 'titles',
    'view_mode' => 'teaser',
    'widget_title' => 'Tasks',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'oa_styles_oa_pane',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a813fc41-b2b1-4c9a-a533-fdbf58d8d707';
  $display->content['new-a813fc41-b2b1-4c9a-a533-fdbf58d8d707'] = $pane;
  $display->panels['contentheader'][3] = 'new-a813fc41-b2b1-4c9a-a533-fdbf58d8d707';
  $pane = new stdClass();
  $pane->pid = 'new-2ef72fbd-6a52-407d-9f90-eff0b2c09771';
  $pane->panel = 'sidebar';
  $pane->type = 'oa_core_summary';
  $pane->subtype = 'oa_core_summary';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'image_size' => 'quarter',
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => 'Description',
    'show_description' => 1,
    'show_favorite' => 0,
    'show_links' => 0,
    'override_title_heading' => 'h2',
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
  $pane->uuid = '2ef72fbd-6a52-407d-9f90-eff0b2c09771';
  $display->content['new-2ef72fbd-6a52-407d-9f90-eff0b2c09771'] = $pane;
  $display->panels['sidebar'][0] = 'new-2ef72fbd-6a52-407d-9f90-eff0b2c09771';
  $pane = new stdClass();
  $pane->pid = 'new-4deb0975-41f1-4090-902e-d49214ff257c';
  $pane->panel = 'sidebar';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_team_list-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'exposed' => array(
      'og_group_ref_target_id' => 'CURRENT',
      'og_group_ref_target_id_mine' => 0,
      'og_subspaces_view_all' => 0,
      'og_subspaces_view_parent' => 0,
    ),
    'show_exposed_form' => 0,
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '50',
    'fields_override' => array(
      'picture' => 1,
      'name' => 1,
      'title' => 0,
    ),
    'override_title' => '',
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'full',
    'widget_title' => 'Teams & Members',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'oa_styles_oa_pane',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4deb0975-41f1-4090-902e-d49214ff257c';
  $display->content['new-4deb0975-41f1-4090-902e-d49214ff257c'] = $pane;
  $display->panels['sidebar'][1] = 'new-4deb0975-41f1-4090-902e-d49214ff257c';
  $pane = new stdClass();
  $pane->pid = 'new-9995e8b8-d8cb-4339-a7ad-1f0ea569d2de';
  $pane->panel = 'sidebar';
  $pane->type = 'views_panes';
  $pane->subtype = 'oa_recent_activity-section_activity';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'panelizer',
    ),
    'view_mode' => 'full',
    'widget_title' => NULL,
    'items_per_page' => '20',
    'exposed' => array(
      'type' => array(),
      'realname' => '',
      'og_group_ref_target_id' => '',
      'og_group_ref_target_id_mine' => 0,
      'og_subspaces_view_all' => 1,
      'og_subspaces_view_parent' => 0,
      'oa_section_ref_target_id' => 'All',
    ),
    'use_pager' => NULL,
    'pager_id' => NULL,
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
    'view_settings' => 'fields',
    'header_type' => 'none',
    'show_exposed_form' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'oa_styles_oa_pane',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9995e8b8-d8cb-4339-a7ad-1f0ea569d2de';
  $display->content['new-9995e8b8-d8cb-4339-a7ad-1f0ea569d2de'] = $pane;
  $display->panels['sidebar'][2] = 'new-9995e8b8-d8cb-4339-a7ad-1f0ea569d2de';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_space:space_project'] = $panelizer;

  return $export;
}
