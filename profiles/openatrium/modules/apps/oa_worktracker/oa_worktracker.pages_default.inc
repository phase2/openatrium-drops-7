<?php
/**
 * @file
 * oa_worktracker.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_worktracker_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_task';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Task Edit Page',
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
              'oa_worktracker_task' => 'oa_worktracker_task',
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
  $display->layout = 'burr_flipped';
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
  $display->uuid = '25b12fdd-d883-4d28-8872-4cc1f30091c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-45a0185a-1dd8-4615-959e-7937b8b0c253';
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
    $pane->uuid = '45a0185a-1dd8-4615-959e-7937b8b0c253';
    $display->content['new-45a0185a-1dd8-4615-959e-7937b8b0c253'] = $pane;
    $display->panels['contentmain'][0] = 'new-45a0185a-1dd8-4615-959e-7937b8b0c253';
    $pane = new stdClass();
    $pane->pid = 'new-5f7884ec-750e-4012-92a3-6c77f36d7ea7';
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
    $pane->uuid = '5f7884ec-750e-4012-92a3-6c77f36d7ea7';
    $display->content['new-5f7884ec-750e-4012-92a3-6c77f36d7ea7'] = $pane;
    $display->panels['contentmain'][1] = 'new-5f7884ec-750e-4012-92a3-6c77f36d7ea7';
    $pane = new stdClass();
    $pane->pid = 'new-cbd3881a-ade0-490b-9658-cbc725e6761d';
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
    $pane->uuid = 'cbd3881a-ade0-490b-9658-cbc725e6761d';
    $display->content['new-cbd3881a-ade0-490b-9658-cbc725e6761d'] = $pane;
    $display->panels['contentmain'][2] = 'new-cbd3881a-ade0-490b-9658-cbc725e6761d';
    $pane = new stdClass();
    $pane->pid = 'new-f7f6ea84-a3ec-4394-bee0-7f5781448650';
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
    $pane->uuid = 'f7f6ea84-a3ec-4394-bee0-7f5781448650';
    $display->content['new-f7f6ea84-a3ec-4394-bee0-7f5781448650'] = $pane;
    $display->panels['sidebar'][0] = 'new-f7f6ea84-a3ec-4394-bee0-7f5781448650';
    $pane = new stdClass();
    $pane->pid = 'new-cbdbb52c-b284-49af-9dd0-1a7aa9c48ab1';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cbdbb52c-b284-49af-9dd0-1a7aa9c48ab1';
    $display->content['new-cbdbb52c-b284-49af-9dd0-1a7aa9c48ab1'] = $pane;
    $display->panels['sidebar'][1] = 'new-cbdbb52c-b284-49af-9dd0-1a7aa9c48ab1';
    $pane = new stdClass();
    $pane->pid = 'new-c66ea64b-ce0f-44b6-87d7-783f2435e85f';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c66ea64b-ce0f-44b6-87d7-783f2435e85f';
    $display->content['new-c66ea64b-ce0f-44b6-87d7-783f2435e85f'] = $pane;
    $display->panels['sidebar'][2] = 'new-c66ea64b-ce0f-44b6-87d7-783f2435e85f';
    $pane = new stdClass();
    $pane->pid = 'new-4309a1f8-510e-44cf-b626-bce50a46db13';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4309a1f8-510e-44cf-b626-bce50a46db13';
    $display->content['new-4309a1f8-510e-44cf-b626-bce50a46db13'] = $pane;
    $display->panels['sidebar'][3] = 'new-4309a1f8-510e-44cf-b626-bce50a46db13';
    $pane = new stdClass();
    $pane->pid = 'new-83c18373-a631-4bf2-b261-deb8a29f1def';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '83c18373-a631-4bf2-b261-deb8a29f1def';
    $display->content['new-83c18373-a631-4bf2-b261-deb8a29f1def'] = $pane;
    $display->panels['sidebar'][4] = 'new-83c18373-a631-4bf2-b261-deb8a29f1def';
    $pane = new stdClass();
    $pane->pid = 'new-c9471e75-f9a5-45f6-8c5d-a217023be39c';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c9471e75-f9a5-45f6-8c5d-a217023be39c';
    $display->content['new-c9471e75-f9a5-45f6-8c5d-a217023be39c'] = $pane;
    $display->panels['sidebar'][5] = 'new-c9471e75-f9a5-45f6-8c5d-a217023be39c';
    $pane = new stdClass();
    $pane->pid = 'new-8c7a4171-5435-463e-ae9d-a298789b3fd4';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '8c7a4171-5435-463e-ae9d-a298789b3fd4';
    $display->content['new-8c7a4171-5435-463e-ae9d-a298789b3fd4'] = $pane;
    $display->panels['sidebar'][6] = 'new-8c7a4171-5435-463e-ae9d-a298789b3fd4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_task'] = $handler;

  return $export;
}
