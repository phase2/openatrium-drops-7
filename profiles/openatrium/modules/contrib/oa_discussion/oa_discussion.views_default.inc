<?php
/**
 * @file
 * oa_discussion.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oa_discussion_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'open_atrium_discussions';
  $view->description = '';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium Discussions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Replies';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'counter' => 'counter',
    'field_oa_media' => 'field_oa_media',
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '#[counter]';
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['counter']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['link_class'] = 'oa-pullout-left';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['oa_date'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['body_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body_1']['element_type'] = '0';
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body_1']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['body_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'remove';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_type'] = 'span';
  $handler->display->display_options['fields']['timestamp']['element_class'] = 'new-marker';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['element_type'] = 'span';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media']['id'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['label'] = '';
  $handler->display->display_options['fields']['field_oa_media']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_oa_media']['delta_offset'] = '0';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Open Atrium: Parent ID (Content) */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'field_data_oa_parent';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['entity_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'oa_discussion_post' => 'oa_discussion_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Discussion Replies */
  $handler = $view->new_display('panel_pane', 'Discussion Replies', 'replies');
  $handler->display->display_options['display_description'] = 'Replies to a post';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div id="toggle-reply-visibility" class="btn"></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'entity_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Open Atrium: Parent ID (Content)',
    ),
  );

  /* Display: Discussion Parent */
  $handler = $view->new_display('panel_pane', 'Discussion Parent', 'original_post');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Original Post';
  $handler->display->display_options['display_description'] = 'Parent of a discussion';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['oa_date'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'remove';
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media']['id'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['label'] = '';
  $handler->display->display_options['fields']['field_oa_media']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media']['type'] = 'file_table';
  $handler->display->display_options['fields']['field_oa_media']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['element_type'] = '0';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'entity_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Open Atrium: Parent ID (Content)',
    ),
  );

  /* Display: Discussion Attachments */
  $handler = $view->new_display('panel_pane', 'Discussion Attachments', 'attachments');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Documents/Media';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No files have been attached to this discussion';
  $handler->display->display_options['empty']['area']['format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '#[counter]';
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['counter']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_type'] = '0';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '0';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => 'content',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'g:ia D M j';
  $handler->display->display_options['fields']['created']['oa_date'] = '0';
  /* Field: Content: Attachments */
  $handler->display->display_options['fields']['field_oa_media']['id'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['table'] = 'field_data_field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['field'] = 'field_oa_media';
  $handler->display->display_options['fields']['field_oa_media']['label'] = '';
  $handler->display->display_options['fields']['field_oa_media']['element_type'] = '0';
  $handler->display->display_options['fields']['field_oa_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_oa_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_oa_media']['type'] = 'media_colorbox';
  $handler->display->display_options['fields']['field_oa_media']['settings'] = array(
    'file_view_mode' => 'preview',
    'colorbox_view_mode' => 'colorbox',
    'fixed_width' => '800',
    'fixed_height' => '600',
    'colorbox_gallery' => 'field_page',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'none',
    'audio_playlist' => 0,
  );
  $handler->display->display_options['fields']['field_oa_media']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_oa_media']['multi_type'] = 'ul';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'oa_discussion_post' => 'oa_discussion_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'entity_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Open Atrium: Parent ID (Content)',
    ),
  );

  /* Display: Discussion Topics */
  $handler = $view->new_display('panel_pane', 'Discussion Topics', 'discussion_topics');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Topics';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'last_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'group-content';
  $handler->display->display_options['style_options']['wrapper_class'] = 'group-header';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'counter' => 'counter',
    'field_oa_media' => 'field_oa_media',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_parent_target_id']['id'] = 'oa_parent_target_id';
  $handler->display->display_options['relationships']['oa_parent_target_id']['table'] = 'field_data_oa_parent';
  $handler->display->display_options['relationships']['oa_parent_target_id']['field'] = 'oa_parent_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['id'] = 'reverse_oa_parent_node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['field'] = 'reverse_oa_parent_node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['label'] = 'Replies';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: New Post */
  $handler->display->display_options['fields']['timestamp_new_1']['id'] = 'timestamp_new_1';
  $handler->display->display_options['fields']['timestamp_new_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_new_1']['field'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_new_1']['element_label_colon'] = FALSE;
  /* Field: Reply Count */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['nid_2']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid_2']['ui_name'] = 'Reply Count';
  $handler->display->display_options['fields']['nid_2']['label'] = '';
  $handler->display->display_options['fields']['nid_2']['element_type'] = '0';
  $handler->display->display_options['fields']['nid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_2']['element_default_classes'] = FALSE;
  /* Field: Content: New Post */
  $handler->display->display_options['fields']['timestamp_new']['id'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_new']['field'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['timestamp_new']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_new']['label'] = '';
  $handler->display->display_options['fields']['timestamp_new']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_new']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_new']['element_default_classes'] = FALSE;
  /* Field: Content: Updated Post */
  $handler->display->display_options['fields']['timestamp_updated']['id'] = 'timestamp_updated';
  $handler->display->display_options['fields']['timestamp_updated']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_updated']['field'] = 'timestamp_updated';
  $handler->display->display_options['fields']['timestamp_updated']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['timestamp_updated']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_updated']['label'] = '';
  $handler->display->display_options['fields']['timestamp_updated']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_updated']['element_default_classes'] = FALSE;
  /* Field: Last Reply */
  $handler->display->display_options['fields']['nid_3']['id'] = 'nid_3';
  $handler->display->display_options['fields']['nid_3']['table'] = 'node';
  $handler->display->display_options['fields']['nid_3']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_3']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['nid_3']['group_type'] = 'max';
  $handler->display->display_options['fields']['nid_3']['ui_name'] = 'Last Reply';
  $handler->display->display_options['fields']['nid_3']['label'] = '';
  $handler->display->display_options['fields']['nid_3']['element_type'] = '0';
  $handler->display->display_options['fields']['nid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_3']['element_default_classes'] = FALSE;
  /* Field: Content: Last updated date (child/parent) */
  $handler->display->display_options['fields']['last_date']['id'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['table'] = 'node';
  $handler->display->display_options['fields']['last_date']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['last_date']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date']['label'] = '';
  $handler->display->display_options['fields']['last_date']['element_type'] = '0';
  $handler->display->display_options['fields']['last_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['last_date']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date']['oa_date'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_user_picture']['group_column'] = 'entity_id';
  /* Field: Content: Last updated date (child/parent) */
  $handler->display->display_options['fields']['last_date_1']['id'] = 'last_date_1';
  $handler->display->display_options['fields']['last_date_1']['table'] = 'node';
  $handler->display->display_options['fields']['last_date_1']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date_1']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['last_date_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date_1']['label'] = '';
  $handler->display->display_options['fields']['last_date_1']['element_type'] = '0';
  $handler->display->display_options['fields']['last_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['last_date_1']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date_1']['oa_date'] = 'oa_date';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['group_type'] = 'max';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Open Atrium Section (oa_section_ref) */
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['oa_section_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Parent (oa_parent) */
  $handler->display->display_options['filters']['oa_parent_target_id']['id'] = 'oa_parent_target_id';
  $handler->display->display_options['filters']['oa_parent_target_id']['table'] = 'field_data_oa_parent';
  $handler->display->display_options['filters']['oa_parent_target_id']['field'] = 'oa_parent_target_id';
  $handler->display->display_options['filters']['oa_parent_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['oa_parent_target_id']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'oa_discussion_post' => 'oa_discussion_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 'offset';
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'type' => '',
  );
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'none',
      'context' => 'entity:fieldable_panels_pane.field-map-address',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
    'oa_section_ref_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Open Atrium Section (oa_section_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: User Topics */
  $handler = $view->new_display('panel_pane', 'User Topics', 'discussion_user');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Your Topics';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'last_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'group-content';
  $handler->display->display_options['style_options']['wrapper_class'] = 'group-header';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'counter' => 'counter',
    'field_oa_media' => 'field_oa_media',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_parent_target_id']['id'] = 'oa_parent_target_id';
  $handler->display->display_options['relationships']['oa_parent_target_id']['table'] = 'field_data_oa_parent';
  $handler->display->display_options['relationships']['oa_parent_target_id']['field'] = 'oa_parent_target_id';
  $handler->display->display_options['relationships']['oa_parent_target_id']['label'] = 'Parent';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['id'] = 'reverse_oa_parent_node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['field'] = 'reverse_oa_parent_node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['label'] = 'Replies';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: New Post */
  $handler->display->display_options['fields']['timestamp_new_1']['id'] = 'timestamp_new_1';
  $handler->display->display_options['fields']['timestamp_new_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_new_1']['field'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_new_1']['element_label_colon'] = FALSE;
  /* Field: Reply Count */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['nid_2']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid_2']['ui_name'] = 'Reply Count';
  $handler->display->display_options['fields']['nid_2']['label'] = '';
  $handler->display->display_options['fields']['nid_2']['element_type'] = '0';
  $handler->display->display_options['fields']['nid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_2']['element_default_classes'] = FALSE;
  /* Field: Content: New Post */
  $handler->display->display_options['fields']['timestamp_new']['id'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_new']['field'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['timestamp_new']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_new']['label'] = '';
  $handler->display->display_options['fields']['timestamp_new']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_new']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_new']['element_default_classes'] = FALSE;
  /* Field: Content: Updated Post */
  $handler->display->display_options['fields']['timestamp_updated']['id'] = 'timestamp_updated';
  $handler->display->display_options['fields']['timestamp_updated']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_updated']['field'] = 'timestamp_updated';
  $handler->display->display_options['fields']['timestamp_updated']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['timestamp_updated']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_updated']['label'] = '';
  $handler->display->display_options['fields']['timestamp_updated']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_updated']['element_default_classes'] = FALSE;
  /* Field: Last Reply */
  $handler->display->display_options['fields']['nid_3']['id'] = 'nid_3';
  $handler->display->display_options['fields']['nid_3']['table'] = 'node';
  $handler->display->display_options['fields']['nid_3']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_3']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['nid_3']['group_type'] = 'max';
  $handler->display->display_options['fields']['nid_3']['ui_name'] = 'Last Reply';
  $handler->display->display_options['fields']['nid_3']['label'] = '';
  $handler->display->display_options['fields']['nid_3']['element_type'] = '0';
  $handler->display->display_options['fields']['nid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_3']['element_default_classes'] = FALSE;
  /* Field: Content: Last updated date (child/parent) */
  $handler->display->display_options['fields']['last_date']['id'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['table'] = 'node';
  $handler->display->display_options['fields']['last_date']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['last_date']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date']['label'] = '';
  $handler->display->display_options['fields']['last_date']['element_type'] = '0';
  $handler->display->display_options['fields']['last_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['last_date']['date_format'] = 'oa_date';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_user_picture']['group_column'] = 'entity_id';
  /* Field: Content: Last updated date (child/parent) */
  $handler->display->display_options['fields']['last_date_1']['id'] = 'last_date_1';
  $handler->display->display_options['fields']['last_date_1']['table'] = 'node';
  $handler->display->display_options['fields']['last_date_1']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date_1']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['last_date_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date_1']['label'] = '';
  $handler->display->display_options['fields']['last_date_1']['element_type'] = '0';
  $handler->display->display_options['fields']['last_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['last_date_1']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date_1']['oa_date'] = 'oa_date';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'label';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'oa_section_ref_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = '';
  $handler->display->display_options['fields']['title_2']['element_type'] = 'span';
  $handler->display->display_options['fields']['title_2']['element_class'] = 'label';
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last updated date (child/parent) */
  $handler->display->display_options['sorts']['last_date']['id'] = 'last_date';
  $handler->display->display_options['sorts']['last_date']['table'] = 'node';
  $handler->display->display_options['sorts']['last_date']['field'] = 'last_date';
  $handler->display->display_options['sorts']['last_date']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['sorts']['last_date']['group_type'] = 'max';
  $handler->display->display_options['sorts']['last_date']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = TRUE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['filters']['nid_1']['table'] = 'node';
  $handler->display->display_options['filters']['nid_1']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_1']['relationship'] = 'oa_parent_target_id';
  $handler->display->display_options['filters']['nid_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['nid_1']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'oa_discussion_post' => 'oa_discussion_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Author uid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: User Reply Topics */
  $handler = $view->new_display('panel_pane', 'User Reply Topics', 'discussion_user_reply');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Your Reply Topics';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'last_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'group-content';
  $handler->display->display_options['style_options']['wrapper_class'] = 'group-header';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'counter' => 'counter',
    'field_oa_media' => 'field_oa_media',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_parent_target_id']['id'] = 'oa_parent_target_id';
  $handler->display->display_options['relationships']['oa_parent_target_id']['table'] = 'field_data_oa_parent';
  $handler->display->display_options['relationships']['oa_parent_target_id']['field'] = 'oa_parent_target_id';
  $handler->display->display_options['relationships']['oa_parent_target_id']['label'] = 'Parent';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['id'] = 'reverse_oa_parent_node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['field'] = 'reverse_oa_parent_node';
  $handler->display->display_options['relationships']['reverse_oa_parent_node']['label'] = 'Replies';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['id'] = 'oa_section_ref_target_id';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['table'] = 'field_data_oa_section_ref';
  $handler->display->display_options['relationships']['oa_section_ref_target_id']['field'] = 'oa_section_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: New Post */
  $handler->display->display_options['fields']['timestamp_new_1']['id'] = 'timestamp_new_1';
  $handler->display->display_options['fields']['timestamp_new_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_new_1']['field'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_new_1']['element_label_colon'] = FALSE;
  /* Field: Reply Count */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['nid_2']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid_2']['ui_name'] = 'Reply Count';
  $handler->display->display_options['fields']['nid_2']['label'] = '';
  $handler->display->display_options['fields']['nid_2']['element_type'] = '0';
  $handler->display->display_options['fields']['nid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_2']['element_default_classes'] = FALSE;
  /* Field: Content: New Post */
  $handler->display->display_options['fields']['timestamp_new']['id'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_new']['field'] = 'timestamp_new';
  $handler->display->display_options['fields']['timestamp_new']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['timestamp_new']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_new']['label'] = '';
  $handler->display->display_options['fields']['timestamp_new']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_new']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_new']['element_default_classes'] = FALSE;
  /* Field: Content: Updated Post */
  $handler->display->display_options['fields']['timestamp_updated']['id'] = 'timestamp_updated';
  $handler->display->display_options['fields']['timestamp_updated']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_updated']['field'] = 'timestamp_updated';
  $handler->display->display_options['fields']['timestamp_updated']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['timestamp_updated']['group_type'] = 'sum';
  $handler->display->display_options['fields']['timestamp_updated']['label'] = '';
  $handler->display->display_options['fields']['timestamp_updated']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp_updated']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_updated']['element_default_classes'] = FALSE;
  /* Field: Last Reply */
  $handler->display->display_options['fields']['nid_3']['id'] = 'nid_3';
  $handler->display->display_options['fields']['nid_3']['table'] = 'node';
  $handler->display->display_options['fields']['nid_3']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_3']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['nid_3']['group_type'] = 'max';
  $handler->display->display_options['fields']['nid_3']['ui_name'] = 'Last Reply';
  $handler->display->display_options['fields']['nid_3']['label'] = '';
  $handler->display->display_options['fields']['nid_3']['element_type'] = '0';
  $handler->display->display_options['fields']['nid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid_3']['element_default_classes'] = FALSE;
  /* Field: Content: Last updated date (child/parent) */
  $handler->display->display_options['fields']['last_date']['id'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['table'] = 'node';
  $handler->display->display_options['fields']['last_date']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['last_date']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date']['label'] = '';
  $handler->display->display_options['fields']['last_date']['element_type'] = '0';
  $handler->display->display_options['fields']['last_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['last_date']['date_format'] = 'oa_date';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'oa_small_thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_user_picture']['group_column'] = 'entity_id';
  /* Field: Content: Last updated date (child/parent) */
  $handler->display->display_options['fields']['last_date_1']['id'] = 'last_date_1';
  $handler->display->display_options['fields']['last_date_1']['table'] = 'node';
  $handler->display->display_options['fields']['last_date_1']['field'] = 'last_date';
  $handler->display->display_options['fields']['last_date_1']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['fields']['last_date_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['last_date_1']['label'] = '';
  $handler->display->display_options['fields']['last_date_1']['element_type'] = '0';
  $handler->display->display_options['fields']['last_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['last_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['last_date_1']['date_format'] = 'oa_date';
  $handler->display->display_options['fields']['last_date_1']['oa_date'] = 'oa_date';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_type'] = 'span';
  $handler->display->display_options['fields']['title_1']['element_class'] = 'label';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'oa_section_ref_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = '';
  $handler->display->display_options['fields']['title_2']['element_type'] = 'span';
  $handler->display->display_options['fields']['title_2']['element_class'] = 'label';
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Last updated date (child/parent) */
  $handler->display->display_options['sorts']['last_date']['id'] = 'last_date';
  $handler->display->display_options['sorts']['last_date']['table'] = 'node';
  $handler->display->display_options['sorts']['last_date']['field'] = 'last_date';
  $handler->display->display_options['sorts']['last_date']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['sorts']['last_date']['group_type'] = 'max';
  $handler->display->display_options['sorts']['last_date']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_oa_parent_node';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = TRUE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['filters']['nid_1']['table'] = 'node';
  $handler->display->display_options['filters']['nid_1']['field'] = 'nid';
  $handler->display->display_options['filters']['nid_1']['relationship'] = 'oa_parent_target_id';
  $handler->display->display_options['filters']['nid_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['nid_1']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'oa_discussion_post' => 'oa_discussion_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Open Atrium';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['exposed_form_configure'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['exposed_form_overrides'] = array(
    'filters' => array(
      'type' => '',
    ),
  );
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Author uid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['open_atrium_discussions'] = $view;

  return $export;
}
