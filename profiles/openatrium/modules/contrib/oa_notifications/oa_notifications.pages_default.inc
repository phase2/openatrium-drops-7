<?php
/**
 * @file
 * oa_notifications.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function oa_notifications_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_subscribed_content';
  $page->task = 'page';
  $page->admin_title = 'User Subscribed Content';
  $page->admin_description = '';
  $page->path = 'user/%user/subscribed';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'argument_entity_id:user_1',
          1 => 'logged-in-user',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Subscribed Content',
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
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
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
  $handler->name = 'page_user_subscribed_content_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_subscribed_content';
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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'open_atrium_content-panel_pane_subscribed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'type' => array(),
        'og_group_ref_target_id' => 'All',
        'og_group_ref_target_id_mine' => 0,
        'oa_section_ref_target_id' => 'All',
        'uid' => '',
        'oa_core_default_to_current_user' => 0,
        'sort_order' => 'DESC',
        'sort_by' => 'changed',
      ),
      'use_pager' => 1,
      'pager_id' => '1',
      'items_per_page' => '20',
      'fields_override' => array(
        'title' => 1,
        'changed' => 1,
        'body' => 1,
        'ops' => 1,
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_settings' => 'table',
      'header_type' => 'titles',
      'view_mode' => 'teaser',
      'widget_title' => 'Subscribed Content',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_subscribed_content'] = $page;

  return $pages;

}
