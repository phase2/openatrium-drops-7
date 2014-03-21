<?php
/**
 * @file
 * panels_customerror.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function panels_customerror_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panels_customerror_403';
  $page->task = 'page';
  $page->admin_title = 'Panels Custom Error Access Denied';
  $page->admin_description = '';
  $page->path = 'access-denied';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panels_customerror_403_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panels_customerror_403';
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
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Access Denied';
  $display->uuid = '7e0e26d2-b517-443a-9d53-95a60f476fa6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1ce0c00a-b09b-478b-abbf-84adde639905';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'panels_customerror-403';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1ce0c00a-b09b-478b-abbf-84adde639905';
    $display->content['new-1ce0c00a-b09b-478b-abbf-84adde639905'] = $pane;
    $display->panels['left'][0] = 'new-1ce0c00a-b09b-478b-abbf-84adde639905';
    $pane = new stdClass();
    $pane->pid = 'new-b19d6807-c315-4527-8585-91ef94b57833';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b19d6807-c315-4527-8585-91ef94b57833';
    $display->content['new-b19d6807-c315-4527-8585-91ef94b57833'] = $pane;
    $display->panels['right'][0] = 'new-b19d6807-c315-4527-8585-91ef94b57833';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panels_customerror_403'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panels_customerror_404';
  $page->task = 'page';
  $page->admin_title = 'Panels Custom Error Page Not Found';
  $page->admin_description = '';
  $page->path = 'page-not-found';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panels_customerror_404_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panels_customerror_404';
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
  $display->title = 'Page not found';
  $display->uuid = '17b277ea-d05c-4565-93c9-95bde15960eb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c2b62bd5-89d0-45c6-85f7-9560a772726c';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'panels_customerror-404';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c2b62bd5-89d0-45c6-85f7-9560a772726c';
    $display->content['new-c2b62bd5-89d0-45c6-85f7-9560a772726c'] = $pane;
    $display->panels['middle'][0] = 'new-c2b62bd5-89d0-45c6-85f7-9560a772726c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panels_customerror_404'] = $page;

  return $pages;

}
