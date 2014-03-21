<?php
/**
 * @file
 * oa_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function oa_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'oa_spaces';
  $page->task = 'page';
  $page->admin_title = 'Spaces';
  $page->admin_description = 'Show all spaces on the site';
  $page->path = 'spaces';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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
  $handler->name = 'page_oa_spaces_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'oa_spaces';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
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
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '8a973113-ff6f-4da3-bdb1-60efe2cf82cd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b2d697bd-94b9-4b1f-9bde-250d3b4e060a';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_core_user_spaces';
    $pane->subtype = 'oa_core_user_spaces';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'featured_spaces' => '1',
      'context' => 'context_user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'image_size' => 'quarter',
      'show_sections' => 1,
      'show_description' => 1,
      'tabs' => array(
        'Favorite' => 'Favorite',
        'Subscribed' => 'Subscribed',
        'All' => 'All',
      ),
      'link_class' => 'btn',
      'show_links' => 1,
      'num_per_page' => '15',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b2d697bd-94b9-4b1f-9bde-250d3b4e060a';
    $display->content['new-b2d697bd-94b9-4b1f-9bde-250d3b4e060a'] = $pane;
    $display->panels['contentmain'][0] = 'new-b2d697bd-94b9-4b1f-9bde-250d3b4e060a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['oa_spaces'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_oa_groups';
  $page->task = 'page';
  $page->admin_title = 'Groups';
  $page->admin_description = 'Show all spaces on the site';
  $page->path = 'groups';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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
  $handler->name = 'page_page_oa_groups_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'page_oa_groups';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
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
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1006a1c7-d722-4f92-bff9-390113450fbb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-315b52ff-90a0-4f38-a81f-5d2cd5404fc9';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_core_user_spaces';
    $pane->subtype = 'oa_core_user_spaces';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'featured_spaces' => '1',
      'context' => 'context_user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'image_size' => 'quarter',
      'show_sections' => 1,
      'show_description' => 1,
      'tabs' => array(
        'Favorite' => 'Favorite',
        'Subscribed' => 'Subscribed',
        'All' => 'All',
      ),
      'link_class' => 'btn',
      'show_links' => 1,
      'num_per_page' => '15',
      'types' => array(
        'oa_group' => 'oa_group',
        'oa_space' => 0,
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '315b52ff-90a0-4f38-a81f-5d2cd5404fc9';
    $display->content['new-315b52ff-90a0-4f38-a81f-5d2cd5404fc9'] = $pane;
    $display->panels['contentmain'][0] = 'new-315b52ff-90a0-4f38-a81f-5d2cd5404fc9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_oa_groups'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_user_groups';
  $page->task = 'page';
  $page->admin_title = 'User groups';
  $page->admin_description = '';
  $page->path = 'user/%user/groups';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access user profiles',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Groups',
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
  $handler->name = 'page_page_user_groups_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'page_user_groups';
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
  $display->layout = 'bryant_flipped_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%user:name\'s groups';
  $display->uuid = 'ad61eaf6-e7c0-4ad3-b798-57381adafa7a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-068bdfd0-f993-43b0-923b-00980676a874';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_core_user_spaces';
    $pane->subtype = 'oa_core_user_spaces';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'tabs' => array(
        'Favorite' => 'Favorite',
        'Subscribed' => 'Subscribed',
        'All' => 'All',
      ),
      'image_size' => 'square',
      'show_description' => 1,
      'show_sections' => 1,
      'show_links' => 1,
      'link_class' => 'btn',
      'num_per_page' => '15',
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
      'types' => array(
        'oa_group' => 'oa_group',
        'oa_space' => 0,
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '068bdfd0-f993-43b0-923b-00980676a874';
    $display->content['new-068bdfd0-f993-43b0-923b-00980676a874'] = $pane;
    $display->panels['contentmain'][0] = 'new-068bdfd0-f993-43b0-923b-00980676a874';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_user_groups'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'space_members';
  $page->task = 'page';
  $page->admin_title = 'Space Members';
  $page->admin_description = '';
  $page->path = 'node/%node/members';
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
        'name' => 'node_access',
        'settings' => array(
          'type' => 'view',
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
    'type' => 'tab',
    'title' => 'Members',
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
  $handler->name = 'page_space_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'space_members';
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
  $display->uuid = '090a6a08-a000-45f2-bdd7-fcfa519189e0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-087a56d7-7043-4581-9d3c-fc480f87d8f7';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_core_members_widget';
    $pane->subtype = 'oa_core_members_widget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'hide_owner' => 0,
      'hide_teams' => 0,
      'show_number' => '0',
      'hide_members' => 0,
      'hide_inherited' => 0,
      'show_as_tabs' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '087a56d7-7043-4581-9d3c-fc480f87d8f7';
    $display->content['new-087a56d7-7043-4581-9d3c-fc480f87d8f7'] = $pane;
    $display->panels['contentmain'][0] = 'new-087a56d7-7043-4581-9d3c-fc480f87d8f7';
    $pane = new stdClass();
    $pane->pid = 'new-197a4919-a200-4f4a-82c8-661d73cd48d5';
    $pane->panel = 'sidebar';
    $pane->type = 'oa_core_add_member';
    $pane->subtype = 'oa_core_add_member';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '197a4919-a200-4f4a-82c8-661d73cd48d5';
    $display->content['new-197a4919-a200-4f4a-82c8-661d73cd48d5'] = $pane;
    $display->panels['sidebar'][0] = 'new-197a4919-a200-4f4a-82c8-661d73cd48d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['space_members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_spaces';
  $page->task = 'page';
  $page->admin_title = 'User spaces';
  $page->admin_description = '';
  $page->path = 'user/%user/spaces';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access user profiles',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Spaces',
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
  $handler->name = 'page_user_spaces_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_spaces';
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
  $display->layout = 'bryant_flipped_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%user:name\'s spaces';
  $display->uuid = '8795b9d1-f621-4590-a690-db1dbc80afd2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bb82f9f8-a3de-476e-b5be-6b60b67ab040';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_core_user_spaces';
    $pane->subtype = 'oa_core_user_spaces';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'tabs' => array(
        'Favorite' => 'Favorite',
        'Subscribed' => 'Subscribed',
        'All' => 'All',
      ),
      'image_size' => 'square',
      'show_description' => 1,
      'show_sections' => 1,
      'show_links' => 1,
      'link_class' => 'btn',
      'num_per_page' => '15',
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = 'bb82f9f8-a3de-476e-b5be-6b60b67ab040';
    $display->content['new-bb82f9f8-a3de-476e-b5be-6b60b67ab040'] = $pane;
    $display->panels['contentmain'][0] = 'new-bb82f9f8-a3de-476e-b5be-6b60b67ab040';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_spaces'] = $page;

  return $pages;

}
