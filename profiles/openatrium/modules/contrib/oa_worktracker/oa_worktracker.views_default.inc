<?php
/**
 * @file
 * oa_worktracker.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oa_worktracker_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'oa_worktracker';
  $view->description = 'Widgets for displaying information from the Open Atrium Work Tracker.';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium Work Tracker';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'oa_form';
  $handler->display->display_options['exposed_form']['options']['collapsed_filter'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
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
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No tasks.';
  $handler->display->display_options['empty']['area']['format'] = 'panopoly_wysiwyg_text';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['id'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['table'] = 'field_data_field_oa_worktracker_assigned_to';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['field'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['label'] = 'Assigned to';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['fields']['realname']['label'] = 'Assigned to';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['fields']['realname_1']['table'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['field'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname_1']['label'] = 'Created by';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Task list */
  $handler = $view->new_display('panel_pane', 'Task list', 'task_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tasks';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'timestamp' => 'title',
    'realname_1' => 'realname_1',
    'realname' => 'realname',
    'title_1' => 'title_1',
    'field_oa_worktracker_priority' => 'field_oa_worktracker_priority',
    'field_oa_worktracker_task_type' => 'field_oa_worktracker_task_type',
    'field_oa_worktracker_task_status' => 'field_oa_worktracker_task_status',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
  );
  $handler->display->display_options['style_options']['default'] = 'last_updated';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_oa_worktracker_priority' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_oa_worktracker_task_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_oa_worktracker_task_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['id'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['table'] = 'field_data_field_oa_worktracker_assigned_to';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['field'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['label'] = 'Assigned to';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['label'] = 'Section';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['required'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [timestamp]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['fields']['realname_1']['table'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['field'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname_1']['label'] = 'Created by';
  $handler->display->display_options['fields']['realname_1']['exclude'] = TRUE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['fields']['realname']['label'] = 'Assigned to';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'oa_section_ref_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Section';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_oa_worktracker_priority']['id'] = 'field_oa_worktracker_priority';
  $handler->display->display_options['fields']['field_oa_worktracker_priority']['table'] = 'field_data_field_oa_worktracker_priority';
  $handler->display->display_options['fields']['field_oa_worktracker_priority']['field'] = 'field_oa_worktracker_priority';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_oa_worktracker_task_type']['id'] = 'field_oa_worktracker_task_type';
  $handler->display->display_options['fields']['field_oa_worktracker_task_type']['table'] = 'field_data_field_oa_worktracker_task_type';
  $handler->display->display_options['fields']['field_oa_worktracker_task_type']['field'] = 'field_oa_worktracker_task_type';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_oa_worktracker_task_status']['id'] = 'field_oa_worktracker_task_status';
  $handler->display->display_options['fields']['field_oa_worktracker_task_status']['table'] = 'field_data_field_oa_worktracker_task_status';
  $handler->display->display_options['fields']['field_oa_worktracker_task_status']['field'] = 'field_oa_worktracker_task_status';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  $handler->display->display_options['fields']['comment_count']['alter']['path'] = 'node/';
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Updated';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'oa_worktracker_task' => 'oa_worktracker_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Groups audience (og_group_ref) */
  $handler->display->display_options['filters']['og_group_ref_target_id']['id'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['og_group_ref_target_id']['field'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['og_group_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator_id'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['label'] = 'Space';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['operator'] = 'og_group_ref_target_id_op';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['identifier'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['og_group_ref_target_id']['group_info']['label'] = 'Groups audience (og_group_ref)';
  $handler->display->display_options['filters']['og_group_ref_target_id']['group_info']['identifier'] = 'og_group_ref_target_id';
  $handler->display->display_options['filters']['og_group_ref_target_id']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['og_group_ref_target_id']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Open Atrium Section (oa_section_ref) */
  $handler->display->display_options['filters']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['oa_section_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['operator_id'] = 'oa_section_ref_target_id_op';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['operator'] = 'oa_section_ref_target_id_op';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['identifier'] = 'oa_section_ref_target_id';
  $handler->display->display_options['filters']['oa_section_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['filters']['realname_1']['table'] = 'realname';
  $handler->display->display_options['filters']['realname_1']['field'] = 'realname';
  $handler->display->display_options['filters']['realname_1']['relationship'] = 'uid';
  $handler->display->display_options['filters']['realname_1']['operator'] = 'word';
  $handler->display->display_options['filters']['realname_1']['group'] = 1;
  $handler->display->display_options['filters']['realname_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname_1']['expose']['operator_id'] = 'realname_1_op';
  $handler->display->display_options['filters']['realname_1']['expose']['label'] = 'Created by';
  $handler->display->display_options['filters']['realname_1']['expose']['operator'] = 'realname_1_op';
  $handler->display->display_options['filters']['realname_1']['expose']['identifier'] = 'realname_1';
  $handler->display->display_options['filters']['realname_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['realname_1']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['realname_1']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname_1']['expose']['autocomplete_field'] = 'realname_1';
  $handler->display->display_options['filters']['realname_1']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname_1']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname_1']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['filters']['realname']['operator'] = 'word';
  $handler->display->display_options['filters']['realname']['group'] = 1;
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Assigned to';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_field'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Status (field_oa_worktracker_task_status) */
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['id'] = 'field_oa_worktracker_task_status_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['table'] = 'field_data_field_oa_worktracker_task_status';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['field'] = 'field_oa_worktracker_task_status_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['operator_id'] = 'field_oa_worktracker_task_status_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['operator'] = 'field_oa_worktracker_task_status_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['identifier'] = 'field_oa_worktracker_task_status_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Priority (field_oa_worktracker_priority) */
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['id'] = 'field_oa_worktracker_priority_value';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['table'] = 'field_data_field_oa_worktracker_priority';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['field'] = 'field_oa_worktracker_priority_value';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['operator_id'] = 'field_oa_worktracker_priority_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['operator'] = 'field_oa_worktracker_priority_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['identifier'] = 'field_oa_worktracker_priority_value';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type (field_oa_worktracker_task_type) */
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['id'] = 'field_oa_worktracker_task_type_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['table'] = 'field_data_field_oa_worktracker_task_type';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['field'] = 'field_oa_worktracker_task_type_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['operator_id'] = 'field_oa_worktracker_task_type_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['operator'] = 'field_oa_worktracker_task_type_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['identifier'] = 'field_oa_worktracker_task_type_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_title'] = 'Task list';
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 'exposed_form_configure';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'og_group_ref_target_id' => '',
      'oa_section_ref_target_id' => '',
      'keys' => 'pane_and_exposed',
      'realname_1' => 'pane_and_exposed',
      'realname' => 'pane_and_exposed',
      'field_oa_worktracker_task_status_value' => 'pane_and_exposed',
      'field_oa_worktracker_priority_value' => 'pane_and_exposed',
      'field_oa_worktracker_task_type_value' => 'pane_and_exposed',
    ),
  );
  $handler->display->display_options['argument_input'] = array(
    'oa_section_ref_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Section',
    ),
  );

  /* Display: Section information */
  $handler = $view->new_display('panel_pane', 'Section information', 'section_info');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Section information';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['label'] = 'Section';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'oa_section_ref_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'oa_section_ref_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Section information';
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content',
    ),
  );

  /* Display: Attachments */
  $handler = $view->new_display('panel_pane', 'Attachments', 'attachments');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Attachments (field_oa_media:fid) */
  $handler->display->display_options['relationships']['field_oa_media_fid']['id'] = 'field_oa_media_fid';
  $handler->display->display_options['relationships']['field_oa_media_fid']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['relationships']['field_oa_media_fid']['field'] = 'field_oa_media_fid';
  $handler->display->display_options['relationships']['field_oa_media_fid']['label'] = 'File';
  $handler->display->display_options['relationships']['field_oa_media_fid']['required'] = TRUE;
  /* Relationship: File: User who uploaded */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'field_oa_media_fid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => '',
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'field_oa_media_fid';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'g:ia D M j';
  $handler->display->display_options['fields']['timestamp']['oa_date'] = '0';
  /* Field: File: Download link */
  $handler->display->display_options['fields']['download']['id'] = 'download';
  $handler->display->display_options['fields']['download']['table'] = 'file_managed';
  $handler->display->display_options['fields']['download']['field'] = 'download';
  $handler->display->display_options['fields']['download']['relationship'] = 'field_oa_media_fid';
  $handler->display->display_options['fields']['download']['label'] = '';
  $handler->display->display_options['fields']['download']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: User tasks */
  $handler = $view->new_display('panel_pane', 'User tasks', 'user_tasks');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Your Tasks';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'timestamp' => 'title',
    'realname_1' => 'realname_1',
    'realname' => 'realname',
    'title_1' => 'title_1',
    'field_oa_worktracker_priority' => 'field_oa_worktracker_priority',
    'field_oa_worktracker_task_type' => 'field_oa_worktracker_task_type',
    'field_oa_worktracker_task_status' => 'field_oa_worktracker_task_status',
    'comment_count' => 'comment_count',
    'last_updated' => 'last_updated',
  );
  $handler->display->display_options['style_options']['default'] = 'last_updated';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_oa_worktracker_priority' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_oa_worktracker_task_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_oa_worktracker_task_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['id'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['table'] = 'field_data_field_oa_worktracker_assigned_to';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['field'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['relationships']['field_oa_worktracker_assigned_to_target_id']['label'] = 'Assigned to';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['label'] = 'Section';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['required'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Author';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] [timestamp]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname_1']['id'] = 'realname_1';
  $handler->display->display_options['fields']['realname_1']['table'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['field'] = 'realname';
  $handler->display->display_options['fields']['realname_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname_1']['label'] = 'Created by';
  $handler->display->display_options['fields']['realname_1']['exclude'] = TRUE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['fields']['realname']['label'] = 'Assigned to';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'oa_section_ref_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Section';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_oa_worktracker_priority']['id'] = 'field_oa_worktracker_priority';
  $handler->display->display_options['fields']['field_oa_worktracker_priority']['table'] = 'field_data_field_oa_worktracker_priority';
  $handler->display->display_options['fields']['field_oa_worktracker_priority']['field'] = 'field_oa_worktracker_priority';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_oa_worktracker_task_type']['id'] = 'field_oa_worktracker_task_type';
  $handler->display->display_options['fields']['field_oa_worktracker_task_type']['table'] = 'field_data_field_oa_worktracker_task_type';
  $handler->display->display_options['fields']['field_oa_worktracker_task_type']['field'] = 'field_oa_worktracker_task_type';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_oa_worktracker_task_status']['id'] = 'field_oa_worktracker_task_status';
  $handler->display->display_options['fields']['field_oa_worktracker_task_status']['table'] = 'field_data_field_oa_worktracker_task_status';
  $handler->display->display_options['fields']['field_oa_worktracker_task_status']['field'] = 'field_oa_worktracker_task_status';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  $handler->display->display_options['fields']['comment_count']['alter']['path'] = 'node/';
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Updated';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'time ago';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_oa_worktracker_assigned_to_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'oa_worktracker_task' => 'oa_worktracker_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_oa_worktracker_task_status) */
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['id'] = 'field_oa_worktracker_task_status_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['table'] = 'field_data_field_oa_worktracker_task_status';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['field'] = 'field_oa_worktracker_task_status_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['operator_id'] = 'field_oa_worktracker_task_status_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['operator'] = 'field_oa_worktracker_task_status_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['identifier'] = 'field_oa_worktracker_task_status_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Priority (field_oa_worktracker_priority) */
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['id'] = 'field_oa_worktracker_priority_value';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['table'] = 'field_data_field_oa_worktracker_priority';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['field'] = 'field_oa_worktracker_priority_value';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['operator_id'] = 'field_oa_worktracker_priority_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['operator'] = 'field_oa_worktracker_priority_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['identifier'] = 'field_oa_worktracker_priority_value';
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_priority_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type (field_oa_worktracker_task_type) */
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['id'] = 'field_oa_worktracker_task_type_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['table'] = 'field_data_field_oa_worktracker_task_type';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['field'] = 'field_oa_worktracker_task_type_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['operator_id'] = 'field_oa_worktracker_task_type_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['operator'] = 'field_oa_worktracker_task_type_value_op';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['identifier'] = 'field_oa_worktracker_task_type_value';
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_oa_worktracker_task_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_title'] = 'User Tasks';
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 'exposed_form_configure';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'keys' => 'pane_and_exposed',
      'realname_1' => 'pane_and_exposed',
      'realname' => 'pane_and_exposed',
      'field_oa_worktracker_priority_value' => 'pane_and_exposed',
      'field_oa_worktracker_task_status_value' => 'pane_and_exposed',
      'field_oa_worktracker_task_type_value' => 'pane_and_exposed',
    ),
  );
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User',
    ),
  );
  $export['oa_worktracker'] = $view;

  return $export;
}
