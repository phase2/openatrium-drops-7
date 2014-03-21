<?php
/**
 * @file
 * oa_layouts.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function oa_layouts_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'default_section_sidebar';
  $mini->category = 'Open Atrium';
  $mini->admin_title = 'Open Atrium Sidebar Bottom';
  $mini->admin_description = 'Provides bottom default section sidebar content';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->title = '';
  $display->uuid = '3d1931ce-af4b-436d-b1f7-3101b7d40c2a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e88f722e-09b5-451c-b694-f6b79c2d8554';
    $pane->panel = 'middle';
    $pane->type = 'oa_notifications_pane';
    $pane->subtype = 'oa_notifications_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-cqM7WI7hjRznriZxDFBrm8G4I9_mm6Yzvz7wALJklco',
      'form_token' => 'hj-U86RUhHElqbcZxCaB5y1kMBIyQjRYApEWJ5pwg1M',
      'form_id' => 'oa_notifications_settings_form',
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
    $pane->uuid = 'e88f722e-09b5-451c-b694-f6b79c2d8554';
    $display->content['new-e88f722e-09b5-451c-b694-f6b79c2d8554'] = $pane;
    $display->panels['middle'][0] = 'new-e88f722e-09b5-451c-b694-f6b79c2d8554';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['default_section_sidebar'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'oa_footer_panel';
  $mini->category = 'Page Elements';
  $mini->admin_title = 'Open Atrium Footer';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'geary';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c94dbbdc-f52c-491e-bde7-a61c98b5cbd3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-39727060-3c1c-4478-ac3f-fa1a0800ad6f';
    $pane->panel = 'column1';
    $pane->type = 'menu_tree';
    $pane->subtype = 'menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'menu_name' => 'menu-footer',
      'parent_mlid' => 'menu-footer:menu-footer:menu-footer:0',
      'title_link' => 0,
      'admin_title' => '',
      'level' => '1',
      'follow' => 0,
      'depth' => 0,
      'expanded' => 1,
      'sort' => 0,
      'override_title' => 1,
      'override_title_text' => '',
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
    $pane->uuid = '39727060-3c1c-4478-ac3f-fa1a0800ad6f';
    $display->content['new-39727060-3c1c-4478-ac3f-fa1a0800ad6f'] = $pane;
    $display->panels['column1'][0] = 'new-39727060-3c1c-4478-ac3f-fa1a0800ad6f';
    $pane = new stdClass();
    $pane->pid = 'new-acef9208-6753-4fee-8b2b-834b2ed0909a';
    $pane->panel = 'column3';
    $pane->type = 'oa_widgets_powered_by';
    $pane->subtype = 'oa_widgets_powered_by';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'acef9208-6753-4fee-8b2b-834b2ed0909a';
    $display->content['new-acef9208-6753-4fee-8b2b-834b2ed0909a'] = $pane;
    $display->panels['column3'][0] = 'new-acef9208-6753-4fee-8b2b-834b2ed0909a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['oa_footer_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'oa_toolbar_panel';
  $mini->category = 'Page Elements';
  $mini->admin_title = 'Open Atrium Toolbar';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'moscone_flipped';
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
    $pane->pid = 'new-3bd6fb98-8bec-48c8-9777-cf8850617d9f';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'oa_dashboard-oa_toolbar_menu_button';
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
      'css_class' => 'pull-left',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3bd6fb98-8bec-48c8-9777-cf8850617d9f';
    $display->content['new-3bd6fb98-8bec-48c8-9777-cf8850617d9f'] = $pane;
    $display->panels['footer'][0] = 'new-3bd6fb98-8bec-48c8-9777-cf8850617d9f';
    $pane = new stdClass();
    $pane->pid = 'new-2b828bf5-01a6-4805-a95d-6c64c67317ef';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'oa_dashboard-oa_breadcrumb';
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
      'css_class' => 'pull-left',
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
    $pane->subtype = 'oa_dashboard-oa_user_badge';
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
      'css_class' => 'pull-right',
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
      'css_class' => 'pull-right',
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
      'css_class' => 'pull-right',
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
      'form_id' => 'oa_dashboard_oa_navigation_content_type_edit_form',
      'op' => 'Save',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
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

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'section_sidebar_top';
  $mini->category = 'Open Atrium';
  $mini->admin_title = 'Open Atrium Sidebar Top';
  $mini->admin_description = 'Provides the top default section sidebar content';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->title = '';
  $display->uuid = '9f0c0534-ba65-4249-bb78-180cd3e7aa44';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9ed591f8-ab5b-4f63-b168-5acab75ccfb7';
    $pane->panel = 'middle';
    $pane->type = 'oa_widgets_content_visibility';
    $pane->subtype = 'oa_widgets_content_visibility';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-uRTcRQO6bSpNFP0fFiN_Py_Fq4JgR6M0fwB0DjBfo00',
      'form_token' => 'ftELGes9cSP07D0rKXmZzilWqzY8HXgZvejPQwIpx0w',
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
    $pane->uuid = '9ed591f8-ab5b-4f63-b168-5acab75ccfb7';
    $display->content['new-9ed591f8-ab5b-4f63-b168-5acab75ccfb7'] = $pane;
    $display->panels['middle'][0] = 'new-9ed591f8-ab5b-4f63-b168-5acab75ccfb7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['section_sidebar_top'] = $mini;

  return $export;
}
