<?php
/**
 * @file
 * oa_panopoly_users.features.inc
 */

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function oa_panopoly_users_default_page_manager_handlers_alter(&$data) {
  if (isset($data['pm_existing_pages_user_login_panel_context'])) {
    $data['pm_existing_pages_user_login_panel_context']->conf['body_classes_to_add'] = 'oa-login'; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['body_classes_to_remove'] = ''; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->content['new-36405db8-54c5-495c-ba8a-0a5f7ade185a']->configuration['override_title_text'] = 'Log In'; /* WAS: '' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->hide_title = 1; /* WAS: 0 */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->layout = 'boxton'; /* WAS: 'burr_flipped' */
    $data['pm_existing_pages_user_login_panel_context']->conf['display']->panel_settings['contentmain'] = array(
      'style' => 'oa_styles_oa_pane',
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_panelizer_defaults_override_alter().
 */
function oa_panopoly_users_panelizer_defaults_override_alter(&$data) {
  if (isset($data['user:user:default'])) {
    $data['user:user:default']->display->content['new-80a6a21b-20e6-4acf-9772-eb089cc6082b'] = (object) array(
          'pid' => 'new-80a6a21b-20e6-4acf-9772-eb089cc6082b',
          'panel' => 'sidebar',
          'type' => 'oa_core_user_spaces',
          'subtype' => 'oa_core_user_spaces',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'featured_spaces' => 1,
            'context' => 'panelizer',
            'override_title' => 0,
            'override_title_text' => '',
            'image_size' => 'none',
            'show_description' => 0,
            'show_sections' => 0,
            'tabs' => array(
              'Favorite' => 'Favorite',
              'Subscribed' => 'Subscribed',
              'All' => 0,
            ),
            'link_class' => 'btn',
            'show_links' => 0,
            'num_per_page' => 15,
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
            'style' => 'oa_styles_oa_pane',
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
          'uuid' => '80a6a21b-20e6-4acf-9772-eb089cc6082b',
        ); /* WAS: '' */
    $data['user:user:default']->display->content['new-9def882d-91aa-4313-87b2-0ace29b4329c'] = (object) array(
          'pid' => 'new-9def882d-91aa-4313-87b2-0ace29b4329c',
          'panel' => 'sidebar',
          'type' => 'entity_field',
          'subtype' => 'user:field_user_picture',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'label' => 'hidden',
            'formatter' => 'image',
            'delta_limit' => 0,
            'delta_offset' => 0,
            'delta_reversed' => FALSE,
            'formatter_settings' => array(
              'image_style' => 'panopoly_image_full',
              'image_link' => '',
            ),
            'context' => 'panelizer',
            'override_title' => 1,
            'override_title_text' => '',
            'view_mode' => NULL,
            'widget_title' => NULL,
            'items_per_page' => NULL,
            'use_pager' => NULL,
            'pager_id' => NULL,
            'offset' => NULL,
            'link_to_view' => NULL,
            'more_link' => NULL,
            'path' => NULL,
          ),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
          'uuid' => '9def882d-91aa-4313-87b2-0ace29b4329c',
        ); /* WAS: '' */
    $data['user:user:default']->display->content['new-a617e554-6ad7-4d25-9d89-627d130d8be3'] = (object) array(
          'pid' => 'new-a617e554-6ad7-4d25-9d89-627d130d8be3',
          'panel' => 'contentheader',
          'type' => 'views_panes',
          'subtype' => 'open_atrium_discussions-discussion_user_reply',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(),
          'cache' => array(),
          'css' => array(),
          'extras' => array(),
          'position' => 2,
          'locks' => array(),
          'uuid' => 'a617e554-6ad7-4d25-9d89-627d130d8be3',
        ); /* WAS: '' */
    $data['user:user:default']->display->content['new-d3a2a9fb-f88a-4730-bfab-c36f4e0af395'] = (object) array(
          'pid' => 'new-d3a2a9fb-f88a-4730-bfab-c36f4e0af395',
          'panel' => 'contentheader',
          'type' => 'entity_field',
          'subtype' => 'user:field_user_about',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'label' => 'hidden',
            'formatter' => 'text_default',
            'delta_limit' => 0,
            'delta_offset' => 0,
            'delta_reversed' => FALSE,
            'formatter_settings' => array(),
            'context' => array(),
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
          'uuid' => 'd3a2a9fb-f88a-4730-bfab-c36f4e0af395',
        ); /* WAS: '' */
    $data['user:user:default']->display->content['new-faf0ad46-b575-4f96-874d-9a4548cc8da3'] = (object) array(
          'pid' => 'new-faf0ad46-b575-4f96-874d-9a4548cc8da3',
          'panel' => 'contentheader',
          'type' => 'views_panes',
          'subtype' => 'open_atrium_discussions-discussion_user',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'use_pager' => 1,
            'pager_id' => 0,
            'items_per_page' => 20,
            'exposed' => array(
              'type' => 'oa_discussion_post',
            ),
            'context' => array(
              0 => 'empty',
            ),
            'view_settings' => 'fields',
            'header_type' => 'none',
            'view_mode' => 'teaser',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => array(),
            'style' => 'oa_styles_oa_pane',
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
          'uuid' => 'faf0ad46-b575-4f96-874d-9a4548cc8da3',
        ); /* WAS: '' */
    $data['user:user:default']->display->layout = 'selby_flipped'; /* WAS: 'phelan' */
    $data['user:user:default']->display->panel_settings['style_settings']['contentcolumn1'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->panel_settings['style_settings']['contentcolumn2'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->panel_settings['style_settings']['contentfooter'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->panel_settings['style_settings']['contentheader'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->panels['contentheader'] = array(
      0 => 'new-d3a2a9fb-f88a-4730-bfab-c36f4e0af395',
      1 => 'new-faf0ad46-b575-4f96-874d-9a4548cc8da3',
      2 => 'new-a617e554-6ad7-4d25-9d89-627d130d8be3',
    ); /* WAS: '' */
    $data['user:user:default']->display->panels['sidebar'] = array(
      0 => 'new-9def882d-91aa-4313-87b2-0ace29b4329c',
      1 => 'new-80a6a21b-20e6-4acf-9772-eb089cc6082b',
    ); /* WAS: '' */
    unset($data['user:user:default']->display->content['new-23b1f4f1-cda8-42ca-880a-afc2ae92f3e9']);
    unset($data['user:user:default']->display->content['new-d76e85cd-4625-4a52-a17b-e5c65e1a0247']);
    unset($data['user:user:default']->display->panels['column1']);
    unset($data['user:user:default']->display->panels['column2']);
  }
}
