<?php
/**
 * @file
 * oa_panopoly_users.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_panopoly_users_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|body_classes_to_add"] = 'oa-login';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|body_classes_to_remove"] = '';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|content|new-1|configuration|override_title_text"] = 'Log In';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|hide_title"] = 1;
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|layout"] = 'boxton';
  $overrides["page_manager_handlers.pm_existing_pages_user_login_panel_context.conf|display|panel_settings|contentmain"] = array(
    'style' => 'oa_styles_oa_pane',
  );

  // Exported overrides for: panelizer_defaults
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|delta_limit"] = 0;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|delta_offset"] = 0;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|delta_reversed"] = FALSE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|exposed"] = array(
    'sort_by' => NULL,
    'sort_order' => NULL,
  );
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|formatter"] = 'text_default';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|formatter_settings"] = array();
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|items_per_page"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|label"] = 'hidden';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|link_to_view"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|more_link"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|offset"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|override_title"] = 0;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|pager_id"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|path"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|use_pager"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|widget_title"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|panel"] = 'contentheader';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|subtype"] = 'user:field_user_about';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|type"] = 'entity_field';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|context|0"] = 'panelizer';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|delta_limit"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|delta_offset"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|delta_reversed"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|exposed|sort_by"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|exposed|sort_order"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|exposed|type"] = 'oa_discussion_post';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|formatter"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|formatter_settings"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|header_type"] = 'none';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|items_per_page"] = '';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|label"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|override_title"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|override_title_text"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|pager_id"] = '';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|use_pager"] = 0;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|view_mode"] = 'teaser';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|view_settings"] = 'fields';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|panel"] = 'contentheader';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|position"] = 1;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|subtype"] = 'open_atrium_discussions-discussion_user';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|type"] = 'views_panes';
  $overrides["panelizer_defaults.user:user:default.display|content|new-3"] = (object) array(
      'pid' => 'new-3',
      'panel' => 'contentheader',
      'type' => 'views_panes',
      'subtype' => 'open_atrium_discussions-discussion_user_reply',
      'shown' => TRUE,
      'access' => array(),
      'configuration' => array(
        'exposed' => array(
          'type' => 'oa_discussion_post',
          'sort_by' => NULL,
          'sort_order' => NULL,
        ),
        'view_mode' => 'teaser',
        'widget_title' => NULL,
        'items_per_page' => NULL,
        'use_pager' => NULL,
        'pager_id' => NULL,
        'offset' => NULL,
        'link_to_view' => NULL,
        'more_link' => NULL,
        'path' => NULL,
        'view_settings' => 'fields',
        'header_type' => 'none',
        'context' => array(
          0 => 'panelizer',
        ),
      ),
      'cache' => array(),
      'style' => array(
        'settings' => NULL,
      ),
      'css' => array(),
      'extras' => array(),
      'position' => 2,
      'locks' => array(),
    );
  $overrides["panelizer_defaults.user:user:default.display|content|new-4"] = (object) array(
      'pid' => 'new-4',
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
      ),
      'cache' => array(),
      'style' => array(
        'settings' => NULL,
      ),
      'css' => array(),
      'extras' => array(),
      'position' => 0,
      'locks' => array(),
    );
  $overrides["panelizer_defaults.user:user:default.display|content|new-5"] = (object) array(
      'pid' => 'new-5',
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
    );
  $overrides["panelizer_defaults.user:user:default.display|layout"] = 'selby_flipped';
  $overrides["panelizer_defaults.user:user:default.display|panel_settings|style_settings|contentcolumn1"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|panel_settings|style_settings|contentcolumn2"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|panel_settings|style_settings|contentfooter"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|panel_settings|style_settings|contentheader"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|panels|column1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|panels|column2"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|panels|contentheader"] = array(
    0 => 'new-1',
    1 => 'new-2',
    2 => 'new-3',
  );
  $overrides["panelizer_defaults.user:user:default.display|panels|sidebar"] = array(
    0 => 'new-4',
    1 => 'new-5',
  );

 return $overrides;
}
