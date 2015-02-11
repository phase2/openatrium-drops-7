<?php
/**
 * @file
 * oa_files.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_files_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_section:oa_section_files';
  $panelizer->title = 'Files Section';
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
  $display->title = '%node:title';
  $display->uuid = '4da17148-a7a9-4da8-a9bf-ef168121174a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b';
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
    $pane->uuid = '2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b';
    $display->content['new-2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b'] = $pane;
    $display->panels['contentmain'][0] = 'new-2010ab8d-8b3a-4f76-8bcd-a9b92ba1417b';
    $pane = new stdClass();
    $pane->pid = 'new-a1345e0e-4ffb-4445-b615-b8922b7dba10';
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
    $pane->uuid = 'a1345e0e-4ffb-4445-b615-b8922b7dba10';
    $display->content['new-a1345e0e-4ffb-4445-b615-b8922b7dba10'] = $pane;
    $display->panels['contentmain'][1] = 'new-a1345e0e-4ffb-4445-b615-b8922b7dba10';
    $pane = new stdClass();
    $pane->pid = 'new-e4ca5fe8-64da-4c85-9392-b94f617f37ed';
    $pane->panel = 'contentmain';
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
      'oa_files_showcount' => 1,
      'oa_files_showfilter' => 0,
      'oa_files_actions' => array(),
      'oa_files_sort' => 'title',
      'oa_files_dir' => 'ASC',
      'oa_files_all' => 1,
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'override_title' => 1,
      'override_title_text' => '',
      'og_menu_single_depth' => '0',
      'og_menu_single_parent' => 'auto',
      'oa_files_vocabulary' => '1',
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
      'form_build_id' => 'form-ojw3hkhm6QrNJ7STXU3cjVxg4i3hCtXNrpmnDE7pQXM',
      'form_token' => 'Hhb4L_eltcDAVfwX68CIIs19rzTMAaLBQE3bfO27ltM',
      'form_id' => 'oa_files_treeview_settings_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e4ca5fe8-64da-4c85-9392-b94f617f37ed';
    $display->content['new-e4ca5fe8-64da-4c85-9392-b94f617f37ed'] = $pane;
    $display->panels['contentmain'][2] = 'new-e4ca5fe8-64da-4c85-9392-b94f617f37ed';
    $pane = new stdClass();
    $pane->pid = 'new-e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc';
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
      'form_build_id' => 'form-AHJUfpYPcZ4fsSHUHIFy0Adu0CXy4e79Kcslz2yLodI',
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
    $pane->uuid = 'e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc';
    $display->content['new-e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc'] = $pane;
    $display->panels['sidebar'][0] = 'new-e7915e9b-dd20-424f-b4e9-4bc4d9a81cbc';
    $pane = new stdClass();
    $pane->pid = 'new-b0dae58c-8654-4b83-b7a5-c1c1006ac3ec';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'open_atrium_content-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'type' => array(
          'oa_wiki_page' => 'oa_wiki_page',
        ),
        'og_group_ref_target_id' => '',
        'og_group_ref_target_id_mine' => 0,
        'og_subspaces_view_all' => 0,
        'og_subspaces_view_parent' => 0,
        'oa_section_ref_target_id' => '',
        'uid' => '',
        'oa_core_default_to_current_user' => 0,
        'flagged' => '0',
      ),
      'show_exposed_form' => 0,
      'more_link' => 0,
      'use_pager' => 1,
      'pager_id' => '0',
      'items_per_page' => '20',
      'path' => 'content',
      'fields_override' => array(
        'title' => 1,
        'timestamp' => 0,
        'changed' => 0,
        'body' => 0,
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
      'widget_title' => 'Recent Documents',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b0dae58c-8654-4b83-b7a5-c1c1006ac3ec';
    $display->content['new-b0dae58c-8654-4b83-b7a5-c1c1006ac3ec'] = $pane;
    $display->panels['sidebar'][1] = 'new-b0dae58c-8654-4b83-b7a5-c1c1006ac3ec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_section:oa_section_files'] = $panelizer;

  return $export;
}
