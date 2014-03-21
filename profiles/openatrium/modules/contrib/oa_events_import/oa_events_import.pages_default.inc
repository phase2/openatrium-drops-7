<?php
/**
 * @file
 * oa_events_import.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function oa_events_import_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'oa_ical_feeds';
  $page->task = 'page';
  $page->admin_title = 'iCal Feeds';
  $page->admin_description = '';
  $page->path = 'group/node/%node/admin/ical';
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
        'name' => 'og_perm',
        'settings' => array(
          'perm' => 'administer group',
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
    'type' => 'none',
    'title' => 'iCal Feeds',
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
  $handler->name = 'page_oa_ical_feeds_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'oa_ical_feeds';
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
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
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
  $display->uuid = '629687bb-6710-47d4-bfed-192fdf2805d3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1fbcc5ee-cfac-4e6c-9e8e-04c2e3b5aeea';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'open_atrium_ical_importers-oa_ical_feeds';
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
    $pane->uuid = '1fbcc5ee-cfac-4e6c-9e8e-04c2e3b5aeea';
    $display->content['new-1fbcc5ee-cfac-4e6c-9e8e-04c2e3b5aeea'] = $pane;
    $display->panels['contentmain'][0] = 'new-1fbcc5ee-cfac-4e6c-9e8e-04c2e3b5aeea';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['oa_ical_feeds'] = $page;

  return $pages;

}
