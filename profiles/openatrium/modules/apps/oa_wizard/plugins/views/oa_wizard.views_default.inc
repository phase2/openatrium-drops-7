<?php
/**
 * @file
 * command_buttons.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oa_wizard_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'oa_wizard_entities';
  $view->description = '';
  $view->tag = 'OA';
  $view->base_table = 'oa_wizard';
  $view->human_name = 'Open Atrium Wizards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Wizards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'view_entity' => 'view_entity',
    'edit_entity' => 'edit_entity',
    'delete_entity' => 'delete_entity',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Command Buttons: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'oa_wizard';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Command Buttons: Administrative link */
  $handler->display->display_options['fields']['view_entity']['id'] = 'view_entity';
  $handler->display->display_options['fields']['view_entity']['table'] = 'oa_wizard';
  $handler->display->display_options['fields']['view_entity']['field'] = 'view_entity';
  $handler->display->display_options['fields']['view_entity']['label'] = 'View';
  /* Field: Command Buttons: Administrative edit link */
  $handler->display->display_options['fields']['edit_entity']['id'] = 'edit_entity';
  $handler->display->display_options['fields']['edit_entity']['table'] = 'oa_wizard';
  $handler->display->display_options['fields']['edit_entity']['field'] = 'edit_entity';
  $handler->display->display_options['fields']['edit_entity']['label'] = 'Edit';
  /* Field: Command Buttons: Administrative delete link */
  $handler->display->display_options['fields']['delete_entity']['id'] = 'delete_entity';
  $handler->display->display_options['fields']['delete_entity']['table'] = 'oa_wizard';
  $handler->display->display_options['fields']['delete_entity']['field'] = 'delete_entity';
  $handler->display->display_options['fields']['delete_entity']['label'] = 'Delete';
  $export['oa_wizard_entities'] = $view;

  return $export;
}
