<?php
/**
 * @file
 * oa_toolbar.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function oa_toolbar_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'oa_admin_minipanel';
  $mini->category = 'OA Admin';
  $mini->admin_title = 'Open Atrium Admin panel';
  $mini->admin_description = 'Minipanel in left tray for admin and navigation';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a63cf87c-604f-4803-8f00-11e13546f5a8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e0d7ad95-d664-4c8d-b498-019d4e4e1c95';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_drupal_admin';
  $pane->subtype = 'oa_drupal_admin';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'caption' => '',
    'icon' => 'fa fa-drupal fa-2x',
    'show_caret' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'btn_class' => 'btn btn-circle',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e0d7ad95-d664-4c8d-b498-019d4e4e1c95';
  $display->content['new-e0d7ad95-d664-4c8d-b498-019d4e4e1c95'] = $pane;
  $display->panels['contentmain'][0] = 'new-e0d7ad95-d664-4c8d-b498-019d4e4e1c95';
  $pane = new stdClass();
  $pane->pid = 'new-cebe51d3-fd8b-4c81-a335-ec2e72f2bbac';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_space_config';
  $pane->subtype = 'oa_space_config';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'btn_class' => 'btn btn-circle',
    'icon_class' => 'icon-cog',
    'direction' => '',
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
  $pane->uuid = 'cebe51d3-fd8b-4c81-a335-ec2e72f2bbac';
  $display->content['new-cebe51d3-fd8b-4c81-a335-ec2e72f2bbac'] = $pane;
  $display->panels['contentmain'][1] = 'new-cebe51d3-fd8b-4c81-a335-ec2e72f2bbac';
  $pane = new stdClass();
  $pane->pid = 'new-6035c863-cefe-4f77-8ac9-1d3af549a096';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_space_structure';
  $pane->subtype = 'oa_space_structure';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'icon' => 'fa fa-sitemap',
    'icon_title' => 'Space Structure',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'btn_class' => 'btn btn-circle',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6035c863-cefe-4f77-8ac9-1d3af549a096';
  $display->content['new-6035c863-cefe-4f77-8ac9-1d3af549a096'] = $pane;
  $display->panels['contentmain'][2] = 'new-6035c863-cefe-4f77-8ac9-1d3af549a096';
  $pane = new stdClass();
  $pane->pid = 'new-aef93573-7245-41cb-8c23-35c43a7945b1';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_members_toolbar';
  $pane->subtype = 'oa_members_toolbar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'show_members' => 1,
    'btn_class' => 'btn btn-circle',
    'icon_class' => 'icon-user',
    'direction' => '',
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'form_build_id' => 'form-SydtPNXjbJgg-ATBlRnB0SaoufkRA2iwJD4iNPfx9LQ',
    'form_token' => 'opuK1ifkvnk3kKrwgtv_7FY8-2bBDDtTcAzyR0aokRY',
    'form_id' => 'oa_users_oa_members_toolbar_form',
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
  $pane->uuid = 'aef93573-7245-41cb-8c23-35c43a7945b1';
  $display->content['new-aef93573-7245-41cb-8c23-35c43a7945b1'] = $pane;
  $display->panels['contentmain'][3] = 'new-aef93573-7245-41cb-8c23-35c43a7945b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['oa_admin_minipanel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'oa_edit_minipanel';
  $mini->category = 'OA Admin';
  $mini->admin_title = 'Open Atrium Edit bar';
  $mini->admin_description = 'Bar shown at bottom of screen for content editors';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_burr';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '14b4a793-83db-4e94-8fa1-9ad66bffb743';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-0e3e4b49-591d-4e60-bfcc-70027ae2a021';
  $pane->panel = 'contentmain';
  $pane->type = 'contextual_tabs';
  $pane->subtype = 'contextual_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'icon_class' => 'fa fa-file-o',
    'form_build_id' => 'form-Xeo8irqXzB1aM4ClDxsJyVDCKv5xLhhriyEBWpPyB5E',
    'form_token' => 'YvoiBpX9duwm5SVde-1FJoaWH6dMp5P9cICl2qvvp70',
    'form_id' => 'contextual_tabs_settings_edit_form',
    'op' => 'Finish',
    'hide_captions' => 1,
    'direction' => 'up',
    'alignment' => 'right',
    'menu_caption' => 'Configure',
    'btn_class' => 'btn-circle',
    'prevent_alter' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-right dropup align-right no-caption',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0e3e4b49-591d-4e60-bfcc-70027ae2a021';
  $display->content['new-0e3e4b49-591d-4e60-bfcc-70027ae2a021'] = $pane;
  $display->panels['contentmain'][0] = 'new-0e3e4b49-591d-4e60-bfcc-70027ae2a021';
  $pane = new stdClass();
  $pane->pid = 'new-442fe0d6-1919-4ce6-828e-1ce78159d468';
  $pane->panel = 'contentmain';
  $pane->type = 'add_space_content';
  $pane->subtype = 'add_space_content';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'node/*/edit*
node/add/*
user/*
admin/*
sitemap*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'caption' => 'Create',
    'icon' => 'fa fa-plus',
    'caret' => 0,
    'form_build_id' => 'form-7yrHd3gWnr5BhmnNR38lJTuo4qyQgXg19Aq9v1VgcaQ',
    'form_token' => 'Pmu1LdSf7E-bpiHOpn8CdjYSECsHVj7D_YBjsgTOXT0',
    'form_id' => 'oa_buttons_add_space_content_settings_form',
    'op' => 'Finish',
    'btn_class' => 'btn btn-circle',
    'direction' => 'dropup',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-right',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '442fe0d6-1919-4ce6-828e-1ce78159d468';
  $display->content['new-442fe0d6-1919-4ce6-828e-1ce78159d468'] = $pane;
  $display->panels['contentmain'][1] = 'new-442fe0d6-1919-4ce6-828e-1ce78159d468';
  $pane = new stdClass();
  $pane->pid = 'new-cd09985e-70e8-4fcc-be64-8e3b0ab9341b';
  $pane->panel = 'contentmain';
  $pane->type = 'pane_oa_form_actions';
  $pane->subtype = 'pane_oa_form_actions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'btn_class' => 'btn-inverse',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'hide_captions' => 1,
    'omit_buttons' => 'edit-delete,edit-preview-changes',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-right',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cd09985e-70e8-4fcc-be64-8e3b0ab9341b';
  $display->content['new-cd09985e-70e8-4fcc-be64-8e3b0ab9341b'] = $pane;
  $display->panels['contentmain'][2] = 'new-cd09985e-70e8-4fcc-be64-8e3b0ab9341b';
  $pane = new stdClass();
  $pane->pid = 'new-05108f43-a24f-4ac2-bad5-eea44d107ff9';
  $pane->panel = 'sidebar';
  $pane->type = 'oa_widgets_content_visibility';
  $pane->subtype = 'oa_widgets_content_visibility';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mode' => 'btn',
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'context' => 'empty',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'form_build_id' => 'form-Ycwv0Fd3xmyf51v2wUG6ljB6RbxnRaIzOcUrxkm53X0',
    'form_token' => 'qe5M1j2a4rIkq81ytjyuwhorhUCicuakqRWJQujVd64',
    'form_id' => 'oa_widgets_content_visibility_edit_form',
    'op' => 'Finish',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-left',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '05108f43-a24f-4ac2-bad5-eea44d107ff9';
  $display->content['new-05108f43-a24f-4ac2-bad5-eea44d107ff9'] = $pane;
  $display->panels['sidebar'][0] = 'new-05108f43-a24f-4ac2-bad5-eea44d107ff9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0e3e4b49-591d-4e60-bfcc-70027ae2a021';
  $mini->display = $display;
  $export['oa_edit_minipanel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'oa_toolbar_modern_panel';
  $mini->category = 'OA Admin';
  $mini->admin_title = 'Open Atrium Modern Toolbar';
  $mini->admin_description = 'The toolbar used in the OA Modern site layout.';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'middle' => NULL,
      'secondcolumn1' => NULL,
      'secondcolumn2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '42cc7a4a-0bc0-4e2b-beca-b38e963ea867';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2bb895d3-61b4-465d-a9d5-c8d3fe57e839';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_responsive_regions_toggle';
  $pane->subtype = 'oa_responsive_regions_toggle';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'position' => 'left',
    'icon' => 'fa fa-angle-double-right fa-2x',
    'icon2' => 'fa fa-angle-double-left fa-2x',
    'btn_class' => 'btn-circle',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-left',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2bb895d3-61b4-465d-a9d5-c8d3fe57e839';
  $display->content['new-2bb895d3-61b4-465d-a9d5-c8d3fe57e839'] = $pane;
  $display->panels['contentmain'][0] = 'new-2bb895d3-61b4-465d-a9d5-c8d3fe57e839';
  $pane = new stdClass();
  $pane->pid = 'new-b0071828-d303-4b30-b93b-dc3da07a6c15';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_responsive_regions_mobile';
  $pane->subtype = 'oa_responsive_regions_mobile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menuid' => 'menu',
    'breakpoints' => 'sm',
    'icon' => 'fa fa-bars',
    'btn_class' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-left',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b0071828-d303-4b30-b93b-dc3da07a6c15';
  $display->content['new-b0071828-d303-4b30-b93b-dc3da07a6c15'] = $pane;
  $display->panels['contentmain'][1] = 'new-b0071828-d303-4b30-b93b-dc3da07a6c15';
  $pane = new stdClass();
  $pane->pid = 'new-5e4445d5-5af3-4e97-9fb7-fa2d03f4c72c';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_recent';
  $pane->subtype = 'oa_recent';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'icon' => 'fa fa-bars fa-2x',
    'icon_title' => 'Recent Spaces',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-left menu-mobile-menu oa-mobile-expand',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5e4445d5-5af3-4e97-9fb7-fa2d03f4c72c';
  $display->content['new-5e4445d5-5af3-4e97-9fb7-fa2d03f4c72c'] = $pane;
  $display->panels['contentmain'][2] = 'new-5e4445d5-5af3-4e97-9fb7-fa2d03f4c72c';
  $pane = new stdClass();
  $pane->pid = 'new-86bc5dc1-c1f8-4b43-a40c-7e7a36198b24';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_navigation';
  $pane->subtype = 'oa_navigation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'return' => 'Save',
    'cancel' => 'Cancel',
    'preview' => 'Update Preview',
    'override_title' => 0,
    'override_title_text' => '',
    'menu_name' => 'main-menu',
    'form_build_id' => 'form-EF6I4nvJ3PuMvArFhpFJ5Kp2OcDwMvG8gl4B3NlDRx0',
    'form_token' => 'BZ3KmS-psxrtVGe71oapeoJx9emdlcwu-NeoYSCB2XA',
    'form_id' => 'oa_toolbar_oa_navigation_content_type_edit_form',
    'op' => 'Save',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-left menu-mobile-menu',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '86bc5dc1-c1f8-4b43-a40c-7e7a36198b24';
  $display->content['new-86bc5dc1-c1f8-4b43-a40c-7e7a36198b24'] = $pane;
  $display->panels['contentmain'][3] = 'new-86bc5dc1-c1f8-4b43-a40c-7e7a36198b24';
  $pane = new stdClass();
  $pane->pid = 'new-bf654f39-83ea-40ee-b3f2-10e08adf8244';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_space_nav';
  $pane->subtype = 'oa_space_nav';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-left',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'bf654f39-83ea-40ee-b3f2-10e08adf8244';
  $display->content['new-bf654f39-83ea-40ee-b3f2-10e08adf8244'] = $pane;
  $display->panels['contentmain'][4] = 'new-bf654f39-83ea-40ee-b3f2-10e08adf8244';
  $pane = new stdClass();
  $pane->pid = 'new-8392382b-5711-4749-96e6-48ae5a7dda23';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_tour_custom_pane';
  $pane->subtype = 'oa_tour_custom_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'direction' => '',
    'alignment' => 'right',
    'icon_class' => 'icon-question-sign',
    'btn_class' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'search-mobile-menu pull-right',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '8392382b-5711-4749-96e6-48ae5a7dda23';
  $display->content['new-8392382b-5711-4749-96e6-48ae5a7dda23'] = $pane;
  $display->panels['contentmain'][5] = 'new-8392382b-5711-4749-96e6-48ae5a7dda23';
  $pane = new stdClass();
  $pane->pid = 'new-bf0e9047-1f82-4bcf-bf9b-f97fe6748f41';
  $pane->panel = 'contentmain';
  $pane->type = 'block';
  $pane->subtype = 'oa_toolbar-oa_user_badge';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-right',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'bf0e9047-1f82-4bcf-bf9b-f97fe6748f41';
  $display->content['new-bf0e9047-1f82-4bcf-bf9b-f97fe6748f41'] = $pane;
  $display->panels['contentmain'][6] = 'new-bf0e9047-1f82-4bcf-bf9b-f97fe6748f41';
  $pane = new stdClass();
  $pane->pid = 'new-818fa3a5-376e-4e7f-8f98-77ed1a6c3252';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_toolbar_search';
  $pane->subtype = 'oa_toolbar_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'search-mobile-menu pull-right',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '818fa3a5-376e-4e7f-8f98-77ed1a6c3252';
  $display->content['new-818fa3a5-376e-4e7f-8f98-77ed1a6c3252'] = $pane;
  $display->panels['contentmain'][7] = 'new-818fa3a5-376e-4e7f-8f98-77ed1a6c3252';
  $pane = new stdClass();
  $pane->pid = 'new-2058791f-ebf2-4a1e-9a78-3bb712fbc5bd';
  $pane->panel = 'contentmain';
  $pane->type = 'oa_responsive_regions_mobile';
  $pane->subtype = 'oa_responsive_regions_mobile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menuid' => 'search',
    'breakpoints' => 'sm',
    'icon' => 'fa fa-search',
    'btn_class' => '',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pull-right',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '2058791f-ebf2-4a1e-9a78-3bb712fbc5bd';
  $display->content['new-2058791f-ebf2-4a1e-9a78-3bb712fbc5bd'] = $pane;
  $display->panels['contentmain'][8] = 'new-2058791f-ebf2-4a1e-9a78-3bb712fbc5bd';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['oa_toolbar_modern_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'oa_toolbar_panel';
  $mini->category = 'OA Admin';
  $mini->admin_title = 'Open Atrium Toolbar';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'radix_moscone_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'middle' => NULL,
      'secondcolumn1' => NULL,
      'secondcolumn2' => NULL,
      'footer' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '42cc7a4a-0bc0-4e2b-beca-b38e963ea867';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-44a20294-d288-4dba-ad6a-824b7e3ec27c';
  $pane->panel = 'footer';
  $pane->type = 'oa_drupal_admin';
  $pane->subtype = 'oa_drupal_admin';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'caption' => '',
    'icon' => 'fa fa-drupal',
    'show_caret' => 0,
    'form_build_id' => 'form-iwd6UEeVPVJBWRhcVmjKnUEx0Qcsam7EWuIvbawkkbs',
    'form_token' => 'FIknbG0azQOE2TXs9epUWxcbtzI5OG5G6EIyNxpTjtk',
    'form_id' => 'oa_toolbar_oa_drupal_admin_form',
    'op' => 'Finish',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'admin-mobile-menu pull-left',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '44a20294-d288-4dba-ad6a-824b7e3ec27c';
  $display->content['new-44a20294-d288-4dba-ad6a-824b7e3ec27c'] = $pane;
  $display->panels['footer'][0] = 'new-44a20294-d288-4dba-ad6a-824b7e3ec27c';
  $pane = new stdClass();
  $pane->pid = 'new-2b828bf5-01a6-4805-a95d-6c64c67317ef';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'oa_toolbar-oa_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'spaces-mobile-menu pull-left',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2b828bf5-01a6-4805-a95d-6c64c67317ef';
  $display->content['new-2b828bf5-01a6-4805-a95d-6c64c67317ef'] = $pane;
  $display->panels['footer'][1] = 'new-2b828bf5-01a6-4805-a95d-6c64c67317ef';
  $pane = new stdClass();
  $pane->pid = 'new-bf0e9047-1f82-4bcf-bf9b-f97fe6748f41';
  $pane->panel = 'footer';
  $pane->type = 'block';
  $pane->subtype = 'oa_toolbar-oa_user_badge';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'user-mobile-menu pull-right',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'bf0e9047-1f82-4bcf-bf9b-f97fe6748f41';
  $display->content['new-bf0e9047-1f82-4bcf-bf9b-f97fe6748f41'] = $pane;
  $display->panels['footer'][2] = 'new-bf0e9047-1f82-4bcf-bf9b-f97fe6748f41';
  $pane = new stdClass();
  $pane->pid = 'new-818fa3a5-376e-4e7f-8f98-77ed1a6c3252';
  $pane->panel = 'footer';
  $pane->type = 'oa_toolbar_search';
  $pane->subtype = 'oa_toolbar_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'search-mobile-menu pull-right',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '818fa3a5-376e-4e7f-8f98-77ed1a6c3252';
  $display->content['new-818fa3a5-376e-4e7f-8f98-77ed1a6c3252'] = $pane;
  $display->panels['footer'][3] = 'new-818fa3a5-376e-4e7f-8f98-77ed1a6c3252';
  $pane = new stdClass();
  $pane->pid = 'new-738df920-1380-4622-ba4c-21f486060818';
  $pane->panel = 'footer';
  $pane->type = 'oa_favorites_favorites_button';
  $pane->subtype = 'oa_favorites_favorites_button';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'search-mobile-menu pull-right',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '738df920-1380-4622-ba4c-21f486060818';
  $display->content['new-738df920-1380-4622-ba4c-21f486060818'] = $pane;
  $display->panels['footer'][4] = 'new-738df920-1380-4622-ba4c-21f486060818';
  $pane = new stdClass();
  $pane->pid = 'new-8392382b-5711-4749-96e6-48ae5a7dda23';
  $pane->panel = 'footer';
  $pane->type = 'oa_tour_custom_pane';
  $pane->subtype = 'oa_tour_custom_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'search-mobile-menu pull-right',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '8392382b-5711-4749-96e6-48ae5a7dda23';
  $display->content['new-8392382b-5711-4749-96e6-48ae5a7dda23'] = $pane;
  $display->panels['footer'][5] = 'new-8392382b-5711-4749-96e6-48ae5a7dda23';
  $pane = new stdClass();
  $pane->pid = 'new-70813a7e-2551-49da-bd7c-4acaff4cae42';
  $pane->panel = 'footer';
  $pane->type = 'add_space_content';
  $pane->subtype = 'add_space_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'return' => 'Finish',
    'cancel' => 'Cancel',
    'override_title_heading' => 'h2',
    'caption' => '',
    'icon' => 'fa fa-plus',
    'form_build_id' => 'form-j0i0TgrT1OI4R8AfvQnELo6aYt-rKmHWbWhETs1bZYw',
    'form_token' => 'vvA_w42MkE6IIBaQYnxndGEAiybLlDALPjegdIiSlfc',
    'form_id' => 'oa_buttons_add_space_content_settings_form',
    'op' => 'Finish',
    'caret' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'search-mobile-menu pull-right',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '70813a7e-2551-49da-bd7c-4acaff4cae42';
  $display->content['new-70813a7e-2551-49da-bd7c-4acaff4cae42'] = $pane;
  $display->panels['footer'][6] = 'new-70813a7e-2551-49da-bd7c-4acaff4cae42';
  $pane = new stdClass();
  $pane->pid = 'new-d02119ab-43a7-4f5b-98a8-24506b23a2d2';
  $pane->panel = 'header';
  $pane->type = 'oa_space_banner';
  $pane->subtype = 'oa_space_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'banner_position' => '1',
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
  $pane->uuid = 'd02119ab-43a7-4f5b-98a8-24506b23a2d2';
  $display->content['new-d02119ab-43a7-4f5b-98a8-24506b23a2d2'] = $pane;
  $display->panels['header'][0] = 'new-d02119ab-43a7-4f5b-98a8-24506b23a2d2';
  $pane = new stdClass();
  $pane->pid = 'new-86bc5dc1-c1f8-4b43-a40c-7e7a36198b24';
  $pane->panel = 'header';
  $pane->type = 'oa_navigation';
  $pane->subtype = 'oa_navigation';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'return' => 'Save',
    'cancel' => 'Cancel',
    'preview' => 'Update Preview',
    'override_title' => 0,
    'override_title_text' => '',
    'menu_name' => 'main-menu',
    'form_build_id' => 'form-EF6I4nvJ3PuMvArFhpFJ5Kp2OcDwMvG8gl4B3NlDRx0',
    'form_token' => 'BZ3KmS-psxrtVGe71oapeoJx9emdlcwu-NeoYSCB2XA',
    'form_id' => 'oa_toolbar_oa_navigation_content_type_edit_form',
    'op' => 'Save',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'clearfix',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '86bc5dc1-c1f8-4b43-a40c-7e7a36198b24';
  $display->content['new-86bc5dc1-c1f8-4b43-a40c-7e7a36198b24'] = $pane;
  $display->panels['header'][1] = 'new-86bc5dc1-c1f8-4b43-a40c-7e7a36198b24';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['oa_toolbar_panel'] = $mini;

  return $export;
}
