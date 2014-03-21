<?php
/**
 * @file
 * oa_events.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_events_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_event:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_event';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
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
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7be5cd4d-6c69-4861-8488-519259cdc3e3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9035b3e7-28dc-478f-a595-e89dca69718a';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_event_detail-event_details';
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
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9035b3e7-28dc-478f-a595-e89dca69718a';
    $display->content['new-9035b3e7-28dc-478f-a595-e89dca69718a'] = $pane;
    $display->panels['contentmain'][0] = 'new-9035b3e7-28dc-478f-a595-e89dca69718a';
    $pane = new stdClass();
    $pane->pid = 'new-231244a5-ffbc-4013-a01e-cc85b4feeff0';
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
    $pane->uuid = '231244a5-ffbc-4013-a01e-cc85b4feeff0';
    $display->content['new-231244a5-ffbc-4013-a01e-cc85b4feeff0'] = $pane;
    $display->panels['sidebar'][0] = 'new-231244a5-ffbc-4013-a01e-cc85b4feeff0';
    $pane = new stdClass();
    $pane->pid = 'new-e0f02a5b-dd4e-4ab9-8479-06a195d86fd0';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_oa_geo_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'geofield_map_map',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'geofield_map_width' => '100%',
        'geofield_map_height' => '300px',
        'geofield_map_zoom' => '12',
        'geofield_map_controltype' => 'default',
        'geofield_map_mtc' => 'standard',
        'geofield_map_pancontrol' => 1,
        'geofield_map_maptype' => 'map',
        'geofield_map_baselayers_map' => 1,
        'geofield_map_baselayers_satellite' => 1,
        'geofield_map_baselayers_hybrid' => 1,
        'geofield_map_baselayers_physical' => 0,
        'geofield_map_scale' => 0,
        'geofield_map_overview' => 0,
        'geofield_map_overview_opened' => 0,
        'geofield_map_scrollwheel' => 1,
        'geofield_map_draggable' => 1,
        'geofield_map_streetview_show' => 0,
      ),
      'context' => array(),
      'override_title' => 0,
      'override_title_text' => '',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e0f02a5b-dd4e-4ab9-8479-06a195d86fd0';
    $display->content['new-e0f02a5b-dd4e-4ab9-8479-06a195d86fd0'] = $pane;
    $display->panels['sidebar'][1] = 'new-e0f02a5b-dd4e-4ab9-8479-06a195d86fd0';
    $pane = new stdClass();
    $pane->pid = 'new-cf81af22-ac8b-4147-8462-a5fce1b76471';
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
    $pane->uuid = 'cf81af22-ac8b-4147-8462-a5fce1b76471';
    $display->content['new-cf81af22-ac8b-4147-8462-a5fce1b76471'] = $pane;
    $display->panels['sidebar'][2] = 'new-cf81af22-ac8b-4147-8462-a5fce1b76471';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_event:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_section:calendar_section';
  $panelizer->title = 'Calendar Section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_section';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe_node_access';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
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
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '938471aa-f986-43b8-b6a6-9084c6c7fbf1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-39b87a40-e27c-45b0-8bdf-6a9c3f117695';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_fullcalendar-oa_calendar_month';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'og_group_ref_target_id' => '',
        'og_group_ref_target_id_mine' => 0,
        'og_subspaces_view_all' => '1',
        'oa_section_ref_target_id' => '',
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
    $pane->uuid = '39b87a40-e27c-45b0-8bdf-6a9c3f117695';
    $display->content['new-39b87a40-e27c-45b0-8bdf-6a9c3f117695'] = $pane;
    $display->panels['contentmain'][0] = 'new-39b87a40-e27c-45b0-8bdf-6a9c3f117695';
    $pane = new stdClass();
    $pane->pid = 'new-81942150-4ee9-4396-8371-b94f72b18f6a';
    $pane->panel = 'sidebar';
    $pane->type = 'fullcalendar_legend';
    $pane->subtype = 'fullcalendar_legend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'oa_fullcalendar-oa_calendar_month',
      'legend_type' => 'taxonomy',
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
    $pane->uuid = '81942150-4ee9-4396-8371-b94f72b18f6a';
    $display->content['new-81942150-4ee9-4396-8371-b94f72b18f6a'] = $pane;
    $display->panels['sidebar'][0] = 'new-81942150-4ee9-4396-8371-b94f72b18f6a';
    $pane = new stdClass();
    $pane->pid = 'new-5241f5c7-9e10-4e79-a1ce-84f68ad200f3';
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
      'form_build_id' => 'form-6Fnl37ZeEeU2hCxrypXlZVcvAy9Rb5CbH610FgT3qGc',
      'form_token' => 'oe5c2G_GZIK6IUkWVwc6PoyfBt5SVSqWK7_R7R7wf1c',
      'form_id' => 'oa_widgets_content_visibility_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5241f5c7-9e10-4e79-a1ce-84f68ad200f3';
    $display->content['new-5241f5c7-9e10-4e79-a1ce-84f68ad200f3'] = $pane;
    $display->panels['sidebar'][1] = 'new-5241f5c7-9e10-4e79-a1ce-84f68ad200f3';
    $pane = new stdClass();
    $pane->pid = 'new-f7576cce-3df6-4498-89b5-77da59c5f99c';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_event_list-oa_events_upcoming_small';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
      'exposed' => array(
        'og_group_ref_target_id' => '',
        'og_group_ref_target_id_mine' => 0,
        'og_subspaces_view_all' => FALSE,
        'oa_section_ref_target_id' => '',
      ),
      'items_per_page' => '10',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f7576cce-3df6-4498-89b5-77da59c5f99c';
    $display->content['new-f7576cce-3df6-4498-89b5-77da59c5f99c'] = $pane;
    $display->panels['sidebar'][2] = 'new-f7576cce-3df6-4498-89b5-77da59c5f99c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_section:calendar_section'] = $panelizer;

  return $export;
}
