<?php
/**
 * @file
 * oa_site_layout_defaults.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_site_layout_defaults_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__atrium-modern';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Modern layout',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'atrium-modern',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'theme',
          'settings' => array(
            'theme' => 'oa_theme',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'theme',
          'settings' => array(
            'theme' => 'oa_basetheme',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $display = new panels_display();
  $display->layout = 'oa_site_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => array(
        'position' => 'right',
        'css_classes' => '',
      ),
      'contentmain' => NULL,
      'secondarycolumn2' => array(
        'position' => 'center',
        'css_classes' => '',
      ),
      'column1' => NULL,
      'column2' => array(
        'position' => 'top',
        'css_classes' => '',
      ),
      'column3' => NULL,
      'secondarycolumn1' => array(
        'position' => 'left',
        'fixed' => 0,
        'mobile_only' => 1,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'secondarycolumn3' => array(
        'position' => 'right',
        'fixed' => 0,
        'mobile_only' => 0,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'sidebar1' => array(
        'position' => 'left',
        'fixed' => 1,
        'mobile_only' => 0,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'sidebar2' => array(
        'position' => 'right',
        'fixed' => 0,
        'mobile_only' => 0,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'contentfooter' => NULL,
      'content' => NULL,
      'traytop' => array(
        'position' => 'top',
        'fixed' => 1,
        'mobile_only' => 0,
        'expand_always' => 1,
        'css_classes' => '',
      ),
      'traybottom' => array(
        'position' => 'bottom',
        'fixed' => 1,
        'mobile_only' => 0,
        'expand_always' => 1,
        'css_classes' => '',
      ),
      'footer' => NULL,
      'contentheader' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_responsive_region',
    ),
    'contentmain' => array(
      'style' => '0',
    ),
    'column1' => array(
      'style' => '0',
    ),
    'column3' => array(
      'style' => '0',
    ),
    'secondarycolumn1' => array(
      'style' => 'oa_responsive_region',
    ),
    'secondarycolumn3' => array(
      'style' => 'oa_responsive_region',
    ),
    'column2' => array(
      'style' => 'oa_responsive_region',
    ),
    'header' => array(
      'style' => '0',
    ),
    'secondarycolumn2' => array(
      'style' => 'oa_responsive_region',
    ),
    'footer' => array(
      'style' => '0',
    ),
    'sidebar1' => array(
      'style' => 'oa_responsive_region',
    ),
    'sidebar2' => array(
      'style' => 'oa_responsive_region',
    ),
    'contentheader' => array(
      'style' => '0',
    ),
    'content' => array(
      'style' => '0',
    ),
    'traytop' => array(
      'style' => 'oa_responsive_region',
    ),
    'traybottom' => array(
      'style' => 'oa_responsive_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '092d1ae4-83ab-471f-8c35-a169a16bdb6a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fcc6b1ff-541b-4fe3-82d2-ea79c4e53895';
  $pane->panel = 'content';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fcc6b1ff-541b-4fe3-82d2-ea79c4e53895';
  $display->content['new-fcc6b1ff-541b-4fe3-82d2-ea79c4e53895'] = $pane;
  $display->panels['content'][0] = 'new-fcc6b1ff-541b-4fe3-82d2-ea79c4e53895';
  $pane = new stdClass();
  $pane->pid = 'new-8363a9b5-ce0c-4a21-bedf-2795687c70a7';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_breadcrumb';
  $pane->subtype = 'pane_oa_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'admin*',
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8363a9b5-ce0c-4a21-bedf-2795687c70a7';
  $display->content['new-8363a9b5-ce0c-4a21-bedf-2795687c70a7'] = $pane;
  $display->panels['contentheader'][0] = 'new-8363a9b5-ce0c-4a21-bedf-2795687c70a7';
  $pane = new stdClass();
  $pane->pid = 'new-9646cb4d-e5f4-4b57-8f59-2bfe90fdffad';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_messages';
  $pane->subtype = 'pane_oa_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9646cb4d-e5f4-4b57-8f59-2bfe90fdffad';
  $display->content['new-9646cb4d-e5f4-4b57-8f59-2bfe90fdffad'] = $pane;
  $display->panels['contentheader'][1] = 'new-9646cb4d-e5f4-4b57-8f59-2bfe90fdffad';
  $pane = new stdClass();
  $pane->pid = 'new-6e8115bd-403c-4664-95d0-102148dea15d';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_title';
  $pane->subtype = 'pane_oa_title';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6e8115bd-403c-4664-95d0-102148dea15d';
  $display->content['new-6e8115bd-403c-4664-95d0-102148dea15d'] = $pane;
  $display->panels['contentheader'][2] = 'new-6e8115bd-403c-4664-95d0-102148dea15d';
  $pane = new stdClass();
  $pane->pid = 'new-f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_tabs';
  $pane->subtype = 'pane_oa_tabs';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'admin*',
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'hide_primary' => 0,
    'hide_secondary' => 1,
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
  $pane->uuid = 'f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6';
  $display->content['new-f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6'] = $pane;
  $display->panels['contentheader'][3] = 'new-f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6';
  $pane = new stdClass();
  $pane->pid = 'new-dabcead7-95a1-4e66-96ac-dd6bd8de7e48';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_tabs';
  $pane->subtype = 'pane_oa_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'hide_primary' => 1,
    'hide_secondary' => 0,
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
  $pane->uuid = 'dabcead7-95a1-4e66-96ac-dd6bd8de7e48';
  $display->content['new-dabcead7-95a1-4e66-96ac-dd6bd8de7e48'] = $pane;
  $display->panels['contentheader'][4] = 'new-dabcead7-95a1-4e66-96ac-dd6bd8de7e48';
  $pane = new stdClass();
  $pane->pid = 'new-41d0f75f-ba8b-495d-9e83-057b6fc026c1';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_help';
  $pane->subtype = 'pane_oa_help';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '41d0f75f-ba8b-495d-9e83-057b6fc026c1';
  $display->content['new-41d0f75f-ba8b-495d-9e83-057b6fc026c1'] = $pane;
  $display->panels['contentheader'][5] = 'new-41d0f75f-ba8b-495d-9e83-057b6fc026c1';
  $pane = new stdClass();
  $pane->pid = 'new-8a55619b-021c-457a-b0e2-99d1dc5c4eb6';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_action_links';
  $pane->subtype = 'pane_oa_action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '8a55619b-021c-457a-b0e2-99d1dc5c4eb6';
  $display->content['new-8a55619b-021c-457a-b0e2-99d1dc5c4eb6'] = $pane;
  $display->panels['contentheader'][6] = 'new-8a55619b-021c-457a-b0e2-99d1dc5c4eb6';
  $pane = new stdClass();
  $pane->pid = 'new-45d40ae9-3122-4b39-afba-5547f5915f56';
  $pane->panel = 'footer';
  $pane->type = 'panels_mini';
  $pane->subtype = 'oa_footer_panel';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'oa_horizontal_slice',
    'settings' => array(
      'position' => 0,
      'toolbar' => 0,
      'margins' => 'oa-fullwidth',
    ),
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'oa-navbar',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '45d40ae9-3122-4b39-afba-5547f5915f56';
  $display->content['new-45d40ae9-3122-4b39-afba-5547f5915f56'] = $pane;
  $display->panels['footer'][0] = 'new-45d40ae9-3122-4b39-afba-5547f5915f56';
  $pane = new stdClass();
  $pane->pid = 'new-891e3f7e-5973-49bf-9306-838bbcd931dc';
  $pane->panel = 'header';
  $pane->type = 'oa_space_banner';
  $pane->subtype = 'oa_space_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'banner_position' => '1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'position' => 0,
      'toolbar' => 0,
      'margins' => 'oa-fullwidth',
    ),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '891e3f7e-5973-49bf-9306-838bbcd931dc';
  $display->content['new-891e3f7e-5973-49bf-9306-838bbcd931dc'] = $pane;
  $display->panels['header'][0] = 'new-891e3f7e-5973-49bf-9306-838bbcd931dc';
  $pane = new stdClass();
  $pane->pid = 'new-414ced3f-0377-429d-a127-7c91480756ba';
  $pane->panel = 'header';
  $pane->type = 'panels_mini';
  $pane->subtype = 'oa_toolbar_modern_panel';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'position' => 0,
      'toolbar' => 1,
      'margins' => 'oa-fullwidth',
    ),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'oa-navbar',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '414ced3f-0377-429d-a127-7c91480756ba';
  $display->content['new-414ced3f-0377-429d-a127-7c91480756ba'] = $pane;
  $display->panels['header'][1] = 'new-414ced3f-0377-429d-a127-7c91480756ba';
  $pane = new stdClass();
  $pane->pid = 'new-29f92506-351a-4b10-9a44-227fb1afe2d9';
  $pane->panel = 'header';
  $pane->type = 'oa_space_banner';
  $pane->subtype = 'oa_space_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'banner_position' => '2',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'position' => 0,
      'toolbar' => 0,
      'margins' => 'oa-fullwidth',
    ),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '29f92506-351a-4b10-9a44-227fb1afe2d9';
  $display->content['new-29f92506-351a-4b10-9a44-227fb1afe2d9'] = $pane;
  $display->panels['header'][2] = 'new-29f92506-351a-4b10-9a44-227fb1afe2d9';
  $pane = new stdClass();
  $pane->pid = 'new-84c9284a-2356-4395-ab70-1d7d876f02a6';
  $pane->panel = 'header';
  $pane->type = 'oa_space_menu';
  $pane->subtype = 'oa_space_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'position' => 0,
      'toolbar' => 0,
      'margins' => 'oa-fullwidth',
    ),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '84c9284a-2356-4395-ab70-1d7d876f02a6';
  $display->content['new-84c9284a-2356-4395-ab70-1d7d876f02a6'] = $pane;
  $display->panels['header'][3] = 'new-84c9284a-2356-4395-ab70-1d7d876f02a6';
  $pane = new stdClass();
  $pane->pid = 'new-42b721ec-e52d-49f1-91ca-7cdc7a5cd68b';
  $pane->panel = 'sidebar1';
  $pane->type = 'panels_mini';
  $pane->subtype = 'oa_admin_minipanel';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->uuid = '42b721ec-e52d-49f1-91ca-7cdc7a5cd68b';
  $display->content['new-42b721ec-e52d-49f1-91ca-7cdc7a5cd68b'] = $pane;
  $display->panels['sidebar1'][0] = 'new-42b721ec-e52d-49f1-91ca-7cdc7a5cd68b';
  $pane = new stdClass();
  $pane->pid = 'new-48b4d796-bbf9-425f-bc9a-4bd870a2c237';
  $pane->panel = 'traybottom';
  $pane->type = 'panels_mini';
  $pane->subtype = 'oa_edit_minipanel';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '48b4d796-bbf9-425f-bc9a-4bd870a2c237';
  $display->content['new-48b4d796-bbf9-425f-bc9a-4bd870a2c237'] = $pane;
  $display->panels['traybottom'][0] = 'new-48b4d796-bbf9-425f-bc9a-4bd870a2c237';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__atrium-modern'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_a4d57c32-e3d0-4611-96eb-3777dd5d594e';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'oa_site_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => array(
        'position' => 'right',
        'css_classes' => '',
      ),
      'contentmain' => NULL,
      'secondarycolumn2' => array(
        'position' => 'center',
        'css_classes' => '',
      ),
      'column1' => NULL,
      'column2' => array(
        'position' => 'top',
        'css_classes' => '',
      ),
      'column3' => NULL,
      'secondarycolumn1' => array(
        'position' => 'left',
        'fixed' => 0,
        'mobile_only' => 1,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'secondarycolumn3' => array(
        'position' => 'right',
        'fixed' => 0,
        'mobile_only' => 0,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'sidebar1' => array(
        'position' => 'left',
        'fixed' => 0,
        'mobile_only' => 0,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'sidebar2' => array(
        'position' => 'right',
        'fixed' => 0,
        'mobile_only' => 0,
        'expand_always' => 0,
        'css_classes' => '',
      ),
      'contentfooter' => NULL,
      'content' => NULL,
      'traytop' => array(
        'position' => 'top',
        'fixed' => 1,
        'mobile_only' => 0,
        'expand_always' => 1,
        'css_classes' => '',
      ),
      'traybottom' => array(
        'position' => 'bottom',
        'fixed' => 1,
        'mobile_only' => 0,
        'expand_always' => 1,
        'css_classes' => '',
      ),
      'footer' => NULL,
      'contentheader' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_responsive_region',
    ),
    'contentmain' => array(
      'style' => '0',
    ),
    'column1' => array(
      'style' => '0',
    ),
    'column3' => array(
      'style' => '0',
    ),
    'secondarycolumn1' => array(
      'style' => 'oa_responsive_region',
    ),
    'secondarycolumn3' => array(
      'style' => 'oa_responsive_region',
    ),
    'column2' => array(
      'style' => 'oa_responsive_region',
    ),
    'header' => array(
      'style' => '0',
    ),
    'secondarycolumn2' => array(
      'style' => 'oa_responsive_region',
    ),
    'footer' => array(
      'style' => '0',
    ),
    'sidebar1' => array(
      'style' => 'oa_responsive_region',
    ),
    'sidebar2' => array(
      'style' => 'oa_responsive_region',
    ),
    'contentheader' => array(
      'style' => '0',
    ),
    'content' => array(
      'style' => '0',
    ),
    'traytop' => array(
      'style' => 'oa_responsive_region',
    ),
    'traybottom' => array(
      'style' => 'oa_responsive_region',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '092d1ae4-83ab-471f-8c35-a169a16bdb6a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-06387b2b-0035-49aa-beb1-9b16e7048e18';
  $pane->panel = 'content';
  $pane->type = 'contextual_tabs';
  $pane->subtype = 'contextual_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '06387b2b-0035-49aa-beb1-9b16e7048e18';
  $display->content['new-06387b2b-0035-49aa-beb1-9b16e7048e18'] = $pane;
  $display->panels['content'][0] = 'new-06387b2b-0035-49aa-beb1-9b16e7048e18';
  $pane = new stdClass();
  $pane->pid = 'new-6e8115bd-403c-4664-95d0-102148dea15d';
  $pane->panel = 'content';
  $pane->type = 'pane_oa_title';
  $pane->subtype = 'pane_oa_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6e8115bd-403c-4664-95d0-102148dea15d';
  $display->content['new-6e8115bd-403c-4664-95d0-102148dea15d'] = $pane;
  $display->panels['content'][1] = 'new-6e8115bd-403c-4664-95d0-102148dea15d';
  $pane = new stdClass();
  $pane->pid = 'new-f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6';
  $pane->panel = 'content';
  $pane->type = 'pane_oa_tabs';
  $pane->subtype = 'pane_oa_tabs';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'admin*',
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6';
  $display->content['new-f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6'] = $pane;
  $display->panels['content'][2] = 'new-f49de3e1-27ab-40b9-b8b5-379ba8a1a1b6';
  $pane = new stdClass();
  $pane->pid = 'new-41d0f75f-ba8b-495d-9e83-057b6fc026c1';
  $pane->panel = 'content';
  $pane->type = 'pane_oa_help';
  $pane->subtype = 'pane_oa_help';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '41d0f75f-ba8b-495d-9e83-057b6fc026c1';
  $display->content['new-41d0f75f-ba8b-495d-9e83-057b6fc026c1'] = $pane;
  $display->panels['content'][3] = 'new-41d0f75f-ba8b-495d-9e83-057b6fc026c1';
  $pane = new stdClass();
  $pane->pid = 'new-8a55619b-021c-457a-b0e2-99d1dc5c4eb6';
  $pane->panel = 'content';
  $pane->type = 'pane_oa_action_links';
  $pane->subtype = 'pane_oa_action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '8a55619b-021c-457a-b0e2-99d1dc5c4eb6';
  $display->content['new-8a55619b-021c-457a-b0e2-99d1dc5c4eb6'] = $pane;
  $display->panels['content'][4] = 'new-8a55619b-021c-457a-b0e2-99d1dc5c4eb6';
  $pane = new stdClass();
  $pane->pid = 'new-fcc6b1ff-541b-4fe3-82d2-ea79c4e53895';
  $pane->panel = 'content';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'fcc6b1ff-541b-4fe3-82d2-ea79c4e53895';
  $display->content['new-fcc6b1ff-541b-4fe3-82d2-ea79c4e53895'] = $pane;
  $display->panels['content'][5] = 'new-fcc6b1ff-541b-4fe3-82d2-ea79c4e53895';
  $pane = new stdClass();
  $pane->pid = 'new-8363a9b5-ce0c-4a21-bedf-2795687c70a7';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_breadcrumb';
  $pane->subtype = 'pane_oa_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'admin*',
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8363a9b5-ce0c-4a21-bedf-2795687c70a7';
  $display->content['new-8363a9b5-ce0c-4a21-bedf-2795687c70a7'] = $pane;
  $display->panels['contentheader'][0] = 'new-8363a9b5-ce0c-4a21-bedf-2795687c70a7';
  $pane = new stdClass();
  $pane->pid = 'new-9646cb4d-e5f4-4b57-8f59-2bfe90fdffad';
  $pane->panel = 'contentheader';
  $pane->type = 'pane_oa_messages';
  $pane->subtype = 'pane_oa_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9646cb4d-e5f4-4b57-8f59-2bfe90fdffad';
  $display->content['new-9646cb4d-e5f4-4b57-8f59-2bfe90fdffad'] = $pane;
  $display->panels['contentheader'][1] = 'new-9646cb4d-e5f4-4b57-8f59-2bfe90fdffad';
  $pane = new stdClass();
  $pane->pid = 'new-45d40ae9-3122-4b39-afba-5547f5915f56';
  $pane->panel = 'footer';
  $pane->type = 'panels_mini';
  $pane->subtype = 'oa_footer_panel';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'oa_horizontal_slice',
    'settings' => array(
      'position' => 0,
      'toolbar' => 0,
      'margins' => 'oa-fullwidth',
    ),
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'oa-navbar',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '45d40ae9-3122-4b39-afba-5547f5915f56';
  $display->content['new-45d40ae9-3122-4b39-afba-5547f5915f56'] = $pane;
  $display->panels['footer'][0] = 'new-45d40ae9-3122-4b39-afba-5547f5915f56';
  $pane = new stdClass();
  $pane->pid = 'new-e1c95efc-282c-468f-8763-dbf09477df3a';
  $pane->panel = 'header';
  $pane->type = 'panels_mini';
  $pane->subtype = 'oa_toolbar_panel';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'position' => 1,
      'toolbar' => 1,
      'margins' => 'oa-fullwidth',
    ),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'oa-navbar',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e1c95efc-282c-468f-8763-dbf09477df3a';
  $display->content['new-e1c95efc-282c-468f-8763-dbf09477df3a'] = $pane;
  $display->panels['header'][0] = 'new-e1c95efc-282c-468f-8763-dbf09477df3a';
  $pane = new stdClass();
  $pane->pid = 'new-29f92506-351a-4b10-9a44-227fb1afe2d9';
  $pane->panel = 'header';
  $pane->type = 'oa_space_banner';
  $pane->subtype = 'oa_space_banner';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'banner_position' => '2',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'position' => 0,
      'toolbar' => 0,
      'margins' => 'oa-fullwidth',
    ),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '29f92506-351a-4b10-9a44-227fb1afe2d9';
  $display->content['new-29f92506-351a-4b10-9a44-227fb1afe2d9'] = $pane;
  $display->panels['header'][1] = 'new-29f92506-351a-4b10-9a44-227fb1afe2d9';
  $pane = new stdClass();
  $pane->pid = 'new-84c9284a-2356-4395-ab70-1d7d876f02a6';
  $pane->panel = 'header';
  $pane->type = 'oa_space_menu';
  $pane->subtype = 'oa_space_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'position' => 0,
      'toolbar' => 0,
      'margins' => 'oa-fullwidth',
    ),
    'style' => 'oa_horizontal_slice',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '84c9284a-2356-4395-ab70-1d7d876f02a6';
  $display->content['new-84c9284a-2356-4395-ab70-1d7d876f02a6'] = $pane;
  $display->panels['header'][2] = 'new-84c9284a-2356-4395-ab70-1d7d876f02a6';
  $pane = new stdClass();
  $pane->pid = 'new-581d6ad7-a4d4-41ae-a054-21420db40952';
  $pane->panel = 'sidebar1';
  $pane->type = 'fieldable_panels_pane';
  $pane->subtype = 'fpid:33';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'fieldable_panels_pane' => (object) array(
      'bundle' => 'text',
      'language' => 'und',
      'is_new' => TRUE,
      'title' => 'Left Tray',
      'link' => 0,
      'path' => '',
      'reusable' => 0,
      'admin_title' => '',
      'admin_description' => '',
      'category' => 'Reusable Content',
      'vid' => '52',
      'current_vid' => '',
      'revision' => 1,
      'fpid' => '33',
      'field_basic_text_text' => array(
        'und' => array(
          0 => array(
            'value' => '<p>Testing</p>',
            'format' => 'panopoly_wysiwyg_text',
          ),
        ),
      ),
      'log' => '',
      'created' => 1452629583,
      'timestamp' => 1452629583,
      'changed' => 1452629583,
      'uuid' => '',
      'uid' => '1',
      'vuuid' => '',
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
  $pane->uuid = '581d6ad7-a4d4-41ae-a054-21420db40952';
  $display->content['new-581d6ad7-a4d4-41ae-a054-21420db40952'] = $pane;
  $display->panels['sidebar1'][0] = 'new-581d6ad7-a4d4-41ae-a054-21420db40952';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_a4d57c32-e3d0-4611-96eb-3777dd5d594e'] = $handler;

  return $export;
}
