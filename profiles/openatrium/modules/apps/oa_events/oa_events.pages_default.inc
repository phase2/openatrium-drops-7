<?php
/**
 * @file
 * oa_events.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_events_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_7';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Event Edit Page',
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
              'oa_event' => 'oa_event',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
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
  $display->uuid = '8605550b-4162-4696-a270-f21c10c146d1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d0c28a3e-a1e5-43c2-b8fd-5e91c3345e27';
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
    $pane->uuid = 'd0c28a3e-a1e5-43c2-b8fd-5e91c3345e27';
    $display->content['new-d0c28a3e-a1e5-43c2-b8fd-5e91c3345e27'] = $pane;
    $display->panels['contentmain'][0] = 'new-d0c28a3e-a1e5-43c2-b8fd-5e91c3345e27';
    $pane = new stdClass();
    $pane->pid = 'new-d5c83106-b1b5-4b32-8c58-a4a53eddb6f9';
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
    $pane->uuid = 'd5c83106-b1b5-4b32-8c58-a4a53eddb6f9';
    $display->content['new-d5c83106-b1b5-4b32-8c58-a4a53eddb6f9'] = $pane;
    $display->panels['contentmain'][1] = 'new-d5c83106-b1b5-4b32-8c58-a4a53eddb6f9';
    $pane = new stdClass();
    $pane->pid = 'new-bff98032-21e1-446d-8c79-fffd4a116418';
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
    $pane->uuid = 'bff98032-21e1-446d-8c79-fffd4a116418';
    $display->content['new-bff98032-21e1-446d-8c79-fffd4a116418'] = $pane;
    $display->panels['contentmain'][2] = 'new-bff98032-21e1-446d-8c79-fffd4a116418';
    $pane = new stdClass();
    $pane->pid = 'new-73af3f62-dd48-400c-bfff-26be3ede3b36';
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
    $pane->uuid = '73af3f62-dd48-400c-bfff-26be3ede3b36';
    $display->content['new-73af3f62-dd48-400c-bfff-26be3ede3b36'] = $pane;
    $display->panels['sidebar'][0] = 'new-73af3f62-dd48-400c-bfff-26be3ede3b36';
    $pane = new stdClass();
    $pane->pid = 'new-08f897a0-7ee5-4c24-856e-e5d6e0aa8bb3';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:field_oa_date';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '08f897a0-7ee5-4c24-856e-e5d6e0aa8bb3';
    $display->content['new-08f897a0-7ee5-4c24-856e-e5d6e0aa8bb3'] = $pane;
    $display->panels['sidebar'][1] = 'new-08f897a0-7ee5-4c24-856e-e5d6e0aa8bb3';
    $pane = new stdClass();
    $pane->pid = 'new-30f4398c-9f13-4195-b392-3f34ab0ddcee';
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
    $pane->uuid = '30f4398c-9f13-4195-b392-3f34ab0ddcee';
    $display->content['new-30f4398c-9f13-4195-b392-3f34ab0ddcee'] = $pane;
    $display->panels['sidebar'][2] = 'new-30f4398c-9f13-4195-b392-3f34ab0ddcee';
    $pane = new stdClass();
    $pane->pid = 'new-c1b47a87-02a0-4882-a02f-5dd40ec016bb';
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
    $pane->uuid = 'c1b47a87-02a0-4882-a02f-5dd40ec016bb';
    $display->content['new-c1b47a87-02a0-4882-a02f-5dd40ec016bb'] = $pane;
    $display->panels['sidebar'][3] = 'new-c1b47a87-02a0-4882-a02f-5dd40ec016bb';
    $pane = new stdClass();
    $pane->pid = 'new-84b3bfce-f79b-4397-8b67-d97d1b61347c';
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
    $pane->uuid = '84b3bfce-f79b-4397-8b67-d97d1b61347c';
    $display->content['new-84b3bfce-f79b-4397-8b67-d97d1b61347c'] = $pane;
    $display->panels['sidebar'][4] = 'new-84b3bfce-f79b-4397-8b67-d97d1b61347c';
    $pane = new stdClass();
    $pane->pid = 'new-020f676b-0f7d-4a37-93e2-44aa23df3980';
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
    $pane->uuid = '020f676b-0f7d-4a37-93e2-44aa23df3980';
    $display->content['new-020f676b-0f7d-4a37-93e2-44aa23df3980'] = $pane;
    $display->panels['sidebar'][5] = 'new-020f676b-0f7d-4a37-93e2-44aa23df3980';
    $pane = new stdClass();
    $pane->pid = 'new-0b869cc5-d419-48ed-bcd1-4e6ec0d15a34';
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
    $pane->uuid = '0b869cc5-d419-48ed-bcd1-4e6ec0d15a34';
    $display->content['new-0b869cc5-d419-48ed-bcd1-4e6ec0d15a34'] = $pane;
    $display->panels['sidebar'][6] = 'new-0b869cc5-d419-48ed-bcd1-4e6ec0d15a34';
    $pane = new stdClass();
    $pane->pid = 'new-68f32ccd-0cec-45db-9ecd-112683c079ae';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '68f32ccd-0cec-45db-9ecd-112683c079ae';
    $display->content['new-68f32ccd-0cec-45db-9ecd-112683c079ae'] = $pane;
    $display->panels['sidebar'][7] = 'new-68f32ccd-0cec-45db-9ecd-112683c079ae';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_7'] = $handler;

  return $export;
}
