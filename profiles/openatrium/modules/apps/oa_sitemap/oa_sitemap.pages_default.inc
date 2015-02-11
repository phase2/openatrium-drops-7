<?php
/**
 * @file
 * oa_sitemap.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function oa_sitemap_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'oa_sitemap';
  $page->task = 'page';
  $page->admin_title = 'Site Map';
  $page->admin_description = '';
  $page->path = 'sitemap/!node';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_oa_sitemap_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'oa_sitemap';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
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
  $display->uuid = 'bee020f6-add9-400b-839e-c5fa1ec85a03';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_sitemap_app';
    $pane->subtype = 'oa_sitemap_app';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'oa_sitemap_parent' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'form_build_id' => 'form-K-kNfXhLu_CkyB1h9QmmnmtRTJzLi0CyX7_OgnbkOfg',
      'form_token' => 'QirTMBeGJboHuNQ-QgckipOfF033GsybkNZsJRt6kB4',
      'form_id' => 'oa_sitemap_app_settings_form',
      'op' => 'Finish',
      'oa_sitemap_help' => 1,
      'oa_sitemap_space_help' => array(
        'value' => '<p>Open Atrium sites are divided into <strong>Spaces</strong>. A Space can be a department, project, region, office, brand, working group, etc. Once a space is created, you can select it to move into that space and create more content. Select the "<strong>New Space</strong>" button to create a new space.</p>',
        'format' => 'panopoly_wysiwyg_text',
      ),
      'oa_sitemap_section_help' => array(
        'value' => '<p>Spaces contain content within "<strong>Sections</strong>". A Section can be a Calendar, Discussion Forum, Document Library, Task list, Folder, etc. Select the "<strong>New Section</strong>" button to create a new section. Spaces can also be subdivided further into <strong>Sub-spaces</strong>. &nbsp;Select the "<strong>New Subspace</strong>" button to create a new sub-space.</p>',
        'format' => 'panopoly_wysiwyg_text',
      ),
      'oa_sitemap_fullpage' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
    $display->content['new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e'] = $pane;
    $display->panels['contentmain'][0] = 'new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['oa_sitemap'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'sitemap_old';
  $page->task = 'page';
  $page->admin_title = 'SItemap (old)';
  $page->admin_description = '';
  $page->path = 'sitemap_old/!node';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_sitemap_old_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'sitemap_old';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
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
  $display->uuid = '0d552761-2392-407c-9918-cb953342a696';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e0a2cb14-ca89-48ac-9bdd-73b4b6fe6222';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_sitemap';
    $pane->subtype = 'oa_sitemap';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-xh8zo_G4hHry7wKPdaYcfyE7s_CgJzCsV2YuH0qc1FI',
      'form_token' => 'O7ZA79McLp02oU-WMIO5r6irrHNcxJV2aeuW1tsQHrk',
      'form_id' => 'oa_sitemap_settings_form',
      'op' => 'Finish',
      'oa_sitemap_parent' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e0a2cb14-ca89-48ac-9bdd-73b4b6fe6222';
    $display->content['new-e0a2cb14-ca89-48ac-9bdd-73b4b6fe6222'] = $pane;
    $display->panels['contentmain'][0] = 'new-e0a2cb14-ca89-48ac-9bdd-73b4b6fe6222';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e0a2cb14-ca89-48ac-9bdd-73b4b6fe6222';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['sitemap_old'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'space_sitemap';
  $page->task = 'page';
  $page->admin_title = 'Space Sitemap';
  $page->admin_description = 'Sitemap of a space';
  $page->path = 'node/%node/map';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'oa_space' => 'oa_space',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'view',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Map',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_space_sitemap_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'space_sitemap';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
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
  $display->uuid = 'e21142c5-1147-4b9b-a6c1-a810a78621c0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bc169ec1-4d41-43ae-a6a0-96c481dc31ee';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_sitemap_app';
    $pane->subtype = 'oa_sitemap_app';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'oa_sitemap_parent' => 0,
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-N_o0dJgl-fJyiPPY5zIjGBOi3Gq466QSaDjx_xn4Ja4',
      'form_token' => '7ZGQbzajLEp3UTNs2YrxCZbxcWvSJerx8vK2wVcYNwc',
      'form_id' => 'oa_sitemap_app_settings_form',
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
    $pane->uuid = 'bc169ec1-4d41-43ae-a6a0-96c481dc31ee';
    $display->content['new-bc169ec1-4d41-43ae-a6a0-96c481dc31ee'] = $pane;
    $display->panels['contentmain'][0] = 'new-bc169ec1-4d41-43ae-a6a0-96c481dc31ee';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['space_sitemap'] = $page;

  return $pages;

}
