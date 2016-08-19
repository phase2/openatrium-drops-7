<?php
/**
 * @file
 * oa_discussion.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_discussion_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_5';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Discussion Edit Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'node-edit',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'oa_discussion_post' => 'oa_discussion_post',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
    'sidebar' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'edb2450e-22df-4403-95d3-d6a0c5b2ee79';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context_5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-355a826a-db1e-4c05-84b7-d3471392f9e2';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
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
  $pane->uuid = '355a826a-db1e-4c05-84b7-d3471392f9e2';
  $display->content['new-355a826a-db1e-4c05-84b7-d3471392f9e2'] = $pane;
  $display->panels['contentmain'][0] = 'new-355a826a-db1e-4c05-84b7-d3471392f9e2';
  $pane = new stdClass();
  $pane->pid = 'new-a68da5e7-4b10-4e58-b015-1c9022cdcaca';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_path';
  $pane->subtype = 'node_form_path';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
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
  $pane->uuid = 'a68da5e7-4b10-4e58-b015-1c9022cdcaca';
  $display->content['new-a68da5e7-4b10-4e58-b015-1c9022cdcaca'] = $pane;
  $display->panels['contentmain'][1] = 'new-a68da5e7-4b10-4e58-b015-1c9022cdcaca';
  $pane = new stdClass();
  $pane->pid = 'new-44bd2b12-bb50-4faa-9824-0e11e8fca29f';
  $pane->panel = 'contentmain';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = '44bd2b12-bb50-4faa-9824-0e11e8fca29f';
  $display->content['new-44bd2b12-bb50-4faa-9824-0e11e8fca29f'] = $pane;
  $display->panels['contentmain'][2] = 'new-44bd2b12-bb50-4faa-9824-0e11e8fca29f';
  $pane = new stdClass();
  $pane->pid = 'new-b6b3cae1-d737-43fe-b478-0ebc7253017b';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:group_access';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = 'b6b3cae1-d737-43fe-b478-0ebc7253017b';
  $display->content['new-b6b3cae1-d737-43fe-b478-0ebc7253017b'] = $pane;
  $display->panels['sidebar'][0] = 'new-b6b3cae1-d737-43fe-b478-0ebc7253017b';
  $pane = new stdClass();
  $pane->pid = 'new-72487532-55e0-42d6-8695-62408e7376cd';
  $pane->panel = 'sidebar';
  $pane->type = 'panelizer_form_default';
  $pane->subtype = 'panelizer_form_default';
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
  $pane->uuid = '72487532-55e0-42d6-8695-62408e7376cd';
  $display->content['new-72487532-55e0-42d6-8695-62408e7376cd'] = $pane;
  $display->panels['sidebar'][1] = 'new-72487532-55e0-42d6-8695-62408e7376cd';
  $pane = new stdClass();
  $pane->pid = 'new-6fc9f47a-0eb1-4538-b494-e1aed519d268';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Featured image',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6fc9f47a-0eb1-4538-b494-e1aed519d268';
  $display->content['new-6fc9f47a-0eb1-4538-b494-e1aed519d268'] = $pane;
  $display->panels['sidebar'][2] = 'new-6fc9f47a-0eb1-4538-b494-e1aed519d268';
  $pane = new stdClass();
  $pane->pid = 'new-f14b4454-0050-4181-8185-5dfb34996c97';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_oa_notifications';
  $pane->subtype = 'node_form_oa_notifications';
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
  $pane->uuid = 'f14b4454-0050-4181-8185-5dfb34996c97';
  $display->content['new-f14b4454-0050-4181-8185-5dfb34996c97'] = $pane;
  $display->panels['sidebar'][3] = 'new-f14b4454-0050-4181-8185-5dfb34996c97';
  $pane = new stdClass();
  $pane->pid = 'new-84c1a05c-0e6c-458a-a079-020a341174ad';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_menu';
  $pane->subtype = 'node_form_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = '84c1a05c-0e6c-458a-a079-020a341174ad';
  $display->content['new-84c1a05c-0e6c-458a-a079-020a341174ad'] = $pane;
  $display->panels['sidebar'][4] = 'new-84c1a05c-0e6c-458a-a079-020a341174ad';
  $pane = new stdClass();
  $pane->pid = 'new-ca3774cd-f5f3-4315-a50f-e66afd7fbe1d';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->uuid = 'ca3774cd-f5f3-4315-a50f-e66afd7fbe1d';
  $display->content['new-ca3774cd-f5f3-4315-a50f-e66afd7fbe1d'] = $pane;
  $display->panels['sidebar'][5] = 'new-ca3774cd-f5f3-4315-a50f-e66afd7fbe1d';
  $pane = new stdClass();
  $pane->pid = 'new-7fa0c92c-6e60-47e3-8ac5-7f1c14205a81';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_author';
  $pane->subtype = 'node_form_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '7fa0c92c-6e60-47e3-8ac5-7f1c14205a81';
  $display->content['new-7fa0c92c-6e60-47e3-8ac5-7f1c14205a81'] = $pane;
  $display->panels['sidebar'][6] = 'new-7fa0c92c-6e60-47e3-8ac5-7f1c14205a81';
  $pane = new stdClass();
  $pane->pid = 'new-be9e23fd-09e8-467e-8666-62e4fd6ed666';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_comment';
  $pane->subtype = 'node_form_comment';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'be9e23fd-09e8-467e-8666-62e4fd6ed666';
  $display->content['new-be9e23fd-09e8-467e-8666-62e4fd6ed666'] = $pane;
  $display->panels['sidebar'][7] = 'new-be9e23fd-09e8-467e-8666-62e4fd6ed666';
  $pane = new stdClass();
  $pane->pid = 'new-a9870e37-b52d-405f-b64a-89ee004ad968';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'a9870e37-b52d-405f-b64a-89ee004ad968';
  $display->content['new-a9870e37-b52d-405f-b64a-89ee004ad968'] = $pane;
  $display->panels['sidebar'][8] = 'new-a9870e37-b52d-405f-b64a-89ee004ad968';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_5'] = $handler;

  return $export;
}
