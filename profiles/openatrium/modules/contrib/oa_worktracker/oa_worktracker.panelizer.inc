<?php
/**
 * @file
 * oa_worktracker.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_worktracker_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_section:oa_section_worktracker';
  $panelizer->title = 'Tasks Section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_section';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
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
  $display->uuid = 'affb0a00-4608-4cef-94ca-b3147c959f46';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d9d3303b-f59f-4e65-bcd7-67a42b55cdda';
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
    $pane->uuid = 'd9d3303b-f59f-4e65-bcd7-67a42b55cdda';
    $display->content['new-d9d3303b-f59f-4e65-bcd7-67a42b55cdda'] = $pane;
    $display->panels['contentmain'][0] = 'new-d9d3303b-f59f-4e65-bcd7-67a42b55cdda';
    $pane = new stdClass();
    $pane->pid = 'new-da9053d3-c4a2-4bb4-a0d0-9e66b49efabc';
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
    $pane->uuid = 'da9053d3-c4a2-4bb4-a0d0-9e66b49efabc';
    $display->content['new-da9053d3-c4a2-4bb4-a0d0-9e66b49efabc'] = $pane;
    $display->panels['contentmain'][1] = 'new-da9053d3-c4a2-4bb4-a0d0-9e66b49efabc';
    $pane = new stdClass();
    $pane->pid = 'new-083432ea-5fb3-4e40-8c9d-09ed848deab7';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_worktracker-task_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '10',
      'fields_override' => array(
        'title' => 1,
        'timestamp' => 1,
        'realname_1' => 0,
        'realname' => 1,
        'title_1' => 0,
        'field_oa_worktracker_priority' => 1,
        'field_oa_worktracker_task_type' => 1,
        'field_oa_worktracker_task_status' => 1,
        'comment_count' => 1,
        'last_updated' => 1,
      ),
      'exposed' => array(
        'og_group_ref_target_id' => '',
        'og_group_ref_target_id_mine' => 0,
        'og_subspaces_view_all' => 0,
        'oa_section_ref_target_id' => '',
        'keys' => '',
        'realname_1' => '',
        'realname' => '',
        'field_oa_worktracker_task_status_value' => array(),
        'field_oa_worktracker_priority_value' => array(),
        'field_oa_worktracker_task_type_value' => array(),
      ),
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_mode' => 'teaser',
      'widget_title' => 'Tasks',
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
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '083432ea-5fb3-4e40-8c9d-09ed848deab7';
    $display->content['new-083432ea-5fb3-4e40-8c9d-09ed848deab7'] = $pane;
    $display->panels['contentmain'][2] = 'new-083432ea-5fb3-4e40-8c9d-09ed848deab7';
    $pane = new stdClass();
    $pane->pid = 'new-bb4d24a8-400f-4710-8ed8-4617dcb6a89d';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_recent_activity-section_activity';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'type' => array(),
        'realname' => '',
        'og_group_ref_target_id' => '',
        'og_group_ref_target_id_mine' => 0,
        'og_subspaces_view_all' => 0,
        'oa_section_ref_target_id' => '',
        'use_pager' => 1,
        'pager_id' => '1',
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'show_exposed_form' => 0,
      'items_per_page' => '20',
      'view_mode' => 'teaser',
      'widget_title' => NULL,
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bb4d24a8-400f-4710-8ed8-4617dcb6a89d';
    $display->content['new-bb4d24a8-400f-4710-8ed8-4617dcb6a89d'] = $pane;
    $display->panels['contentmain'][3] = 'new-bb4d24a8-400f-4710-8ed8-4617dcb6a89d';
    $pane = new stdClass();
    $pane->pid = 'new-f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f';
    $pane->panel = 'sidebar';
    $pane->type = 'oa_widgets_content_visibility';
    $pane->subtype = 'oa_widgets_content_visibility';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
      'form_build_id' => 'form-V0GNaOe_jcI4GeEbCDAJvWABqI8dLL3oQc2wt_JoNqk',
      'form_token' => 'njVkGwxcnRn82ge96ivsc_xCRz5OGZPGwWJyd994lQM',
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
    $pane->uuid = 'f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f';
    $display->content['new-f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f'] = $pane;
    $display->panels['sidebar'][0] = 'new-f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_section:oa_section_worktracker'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_worktracker_task:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_worktracker_task';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
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
  $display->uuid = '9ca515a2-1ad3-434c-b55d-062f412162fe';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-af899e0d-b082-4756-a5b0-7b81f93352f6';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'af899e0d-b082-4756-a5b0-7b81f93352f6';
    $display->content['new-af899e0d-b082-4756-a5b0-7b81f93352f6'] = $pane;
    $display->panels['contentmain'][0] = 'new-af899e0d-b082-4756-a5b0-7b81f93352f6';
    $pane = new stdClass();
    $pane->pid = 'new-4d950f23-b75f-4181-b4bd-bcaee2827726';
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
    $pane->uuid = '4d950f23-b75f-4181-b4bd-bcaee2827726';
    $display->content['new-4d950f23-b75f-4181-b4bd-bcaee2827726'] = $pane;
    $display->panels['sidebar'][0] = 'new-4d950f23-b75f-4181-b4bd-bcaee2827726';
    $pane = new stdClass();
    $pane->pid = 'new-36e8d7f2-31db-441b-903b-f6932d38e136';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_worktracker-section_info';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '10',
      'fields_override' => array(
        'title' => 1,
        'body' => 1,
      ),
      'exposed' => array(
        'widget_title' => 'Section information',
        'use_pager' => 0,
        'pager_id' => '',
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_mode' => 'teaser',
      'widget_title' => 'Section information',
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
    $pane->uuid = '36e8d7f2-31db-441b-903b-f6932d38e136';
    $display->content['new-36e8d7f2-31db-441b-903b-f6932d38e136'] = $pane;
    $display->panels['sidebar'][1] = 'new-36e8d7f2-31db-441b-903b-f6932d38e136';
    $pane = new stdClass();
    $pane->pid = 'new-fe734968-2437-401a-a83e-2a48ffc565d3';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_oa_media';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'file_view_mode' => 'default',
        'colorbox_view_mode' => 'colorbox',
        'fixed_width' => '800',
        'fixed_height' => '600',
        'colorbox_gallery' => 'field_page',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => 'none',
        'audio_playlist' => 0,
        'text' => '[file:name]',
      ),
      'context' => array(),
      'override_title' => 1,
      'override_title_text' => 'Documents/Media',
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
    $pane->uuid = 'fe734968-2437-401a-a83e-2a48ffc565d3';
    $display->content['new-fe734968-2437-401a-a83e-2a48ffc565d3'] = $pane;
    $display->panels['sidebar'][2] = 'new-fe734968-2437-401a-a83e-2a48ffc565d3';
    $pane = new stdClass();
    $pane->pid = 'new-fe5afb3a-1258-40e5-9d8a-50ea4cb283b5';
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
    $pane->uuid = 'fe5afb3a-1258-40e5-9d8a-50ea4cb283b5';
    $display->content['new-fe5afb3a-1258-40e5-9d8a-50ea4cb283b5'] = $pane;
    $display->panels['sidebar'][3] = 'new-fe5afb3a-1258-40e5-9d8a-50ea4cb283b5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_worktracker_task:default'] = $panelizer;

  return $export;
}
