<?php

/**
 * @file
 * Defines the space members panels pane.
 */

$plugin = array(
  'title' => t('Space Members'),
  'description' => t("Show the owners, teams, and members of a Space"),
  'single' => TRUE,
  'category' => t('Open Atrium'),
  'edit form' => 'oa_core_members_widget_edit_form',
  'render callback' => 'oa_core_members_widget_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'hide_owner' => FALSE,
    'hide_teams' => FALSE,
    'hide_members' => FALSE,
    'hide_inherited' => FALSE,
    'show_number' => 10,
    'show_as_tabs' => FALSE,
  ),
);


/**
 * Main render function for oa_core_members_widget.
 */
function oa_core_members_widget_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  if (!isset($context->data->nid) || !($space = oa_core_get_group_from_node($context->data->nid)) || !node_access('view', $space)) {
    return;
  }

  $is_admin = og_user_access('node', $space->nid, 'manage members');

  $block = new stdClass();
  $block->title = t('Members');

  $teams = array();
  if (empty($conf['hide_teams']) && module_exists('oa_teams') && ($teams = oa_teams_get_teams_for_space($space->nid))) {
    $teams = node_load_multiple(array_keys($teams));
  }

  $pending = array();
  if ($is_admin && empty($conf['hide_members']) && empty($conf['hide_owner'])) {
    $pending = oa_core_get_users_for_space($space->nid, OG_STATE_PENDING);
  }

  $blocked = array();
  if ($is_admin && empty($conf['hide_members']) && empty($conf['hide_owner'])) {
    $blocked = oa_core_get_users_for_space($space->nid, OG_STATE_BLOCKED);
  }

  $members = empty($conf['hide_owner']) || empty($conf['hide_members']) ? oa_core_get_users_for_space($space->nid) : array();
  uasort($members, 'oa_core_sort_users_by_name');
  $owners = array();
  if (empty($conf['hide_owner'])) {
    foreach ($members as $member) {
      $roles = og_get_user_roles('node', $space->nid, $member->uid);
      if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $space->uid) {
        $owners[$member->uid] = $member;
      }
    }
  }
  if (!empty($conf['hide_members'])) {
    $members = array();
  }

  $parents = array();
  if (empty($conf['hide_inherited']) && $is_admin && ($parent_field = field_get_items('node', $space, 'oa_parent_space'))) {
    foreach ($parent_field as $parent) {
      if (!empty($parent['target_id'])) {
        $parents[$parent['target_id']] = $parent['target_id'];
      }
    }
    $parents = node_load_multiple(array_keys($parents));
  }

  $vars = array();

  $show_number = isset($conf['show_number']) ? $conf['show_number'] : 10;
  if ($show_number > 0) {
    $vars['see_all_link'] = l(t('See all members'), 'node/' . $space->nid . '/members');
    $members = array_slice($members, 0, $show_number-1);
  }
  else {
    $vars['see_all_link'] = '';
  }
  $vars['show_as_tabs'] = isset($conf['show_as_tabs']) ? $conf['show_as_tabs'] : FALSE;
  // set the order the tabs/categories show on page
  $vars['categories'] = $vars['show_as_tabs']
    ? array('members', 'pending', 'blocked', 'owners', 'parents', 'teams')
    : array('owners', 'parents', 'teams', 'pending', 'members', 'blocked');

  $space_type = node_type_get_name($space->type);

  $tabs = array();
  if (count($members) > 0) {
    $tabs['members'] = array(
      'caption' => t('Members'),
      'title' => '',
      'items' => $members,
      'links' => array('dashboard', 'remove', 'remove-child', 'add-admin', 'block'),
    );
  }
  if (count($pending) > 0) {
    $tabs['pending'] = array(
      'caption' => t('Pending') . ' <span class="oa_pending_count">' . count($pending) . '</span>',
      'title' => t('Pending members'),
      'items' => $pending,
      'links' => array('dashboard', 'add', 'remove'),
    );
  }
  if (count($blocked) > 0) {
    $tabs['blocked'] = array(
      'caption' => t('Blocked'),
      'title' => t('Blocked users'),
      'items' => $blocked,
      'links' => array('dashboard', 'add', 'remove'),
    );
  }
  if (count($owners) > 0) {
    $tabs['owners'] = array(
      'caption' => t('Administrators'),
      'title' => t('@type administrators', array('@type' => $space_type)),
      'items' => $owners,
      'links' => array('dashboard', 'remove-admin'),
    );
  }
  if (count($parents) > 0) {
    $tabs['parents'] = array(
      'caption' => t('Inherited'),
      'title' => t('Inheriting members from'),
      'items' => $parents,
      'links' => array(),
    );
  }
  if (count($teams) > 0) {
    $tabs['teams'] = array(
      'caption' => t('Teams'),
      'title' => t('Teams'),
      'items' => $teams,
      'links' => array(),
    );
  }

  foreach ($tabs as $category => $tab) {
    $tabs[$category]['items'] = array();
    if ($tab['items']) {
      foreach ($tab['items'] as $id => $entity) {
        $tabs[$category]['items'][$id] = oa_core_entity_build_display($entity, $id, $space);
        if ($entity->uid == $space->uid) {
          // don't show links for main space owner
          $tabs[$category]['items'][$id]['uid'] = 0;
        }
      }
    }
    else {
      unset($tabs[$category]);
    }
  }
  // don't show extra title if only one type of user being shown in a block
  if (count($tabs) == 1) {
    unset($tabs[key($tabs)]['title']);
  }

  $ajax = (variable_get('oa_use_ajax', FALSE)) ? '/nojs' : '';
  $links = array(
    'dashboard' => array(
      'title' => t('Dashboard'),
      'url' => 'user/%uid',
    ),
    'remove' => array(
      'title' => t('Remove from @label', array('@label' => $space_type)),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/remove/single/%uid' . $ajax : '',
    ),
    'add' => array(
      'title' => t('Approve/Add to @label', array('@label' => $space_type)),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/add-member/%uid/' . OA_SPACE_FIELD . $ajax : '',
    ),
    'block' => array(
      'title' => t('Block user'),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/block/%uid' . $ajax : '',
    ),
    'add-admin' => array(
      'title' => t('Add as Admin'),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/add-admin/%uid' . $ajax : '',
    ),
    'remove-admin' => array(
      'title' => t('Remove as Admin'),
      'url' => $is_admin ? 'group/node/' . $space->nid . '/remove-admin/%uid' . $ajax : '',
    ),
    'remove-child' => array(
      'title' => t('Remove from @label and any children spaces', array('@label' => $space_type)),
      'url' => (og_user_access('node', $space->nid, 'administer group') && module_exists('oa_subspaces') && og_subgroups_children_load('node', $space->nid, FALSE))
        ? 'group/node/' . $space->nid . '/remove/all/%uid' . $ajax
        : '',
    ),
  );

  $vars['tabs'] = $tabs;
  $vars['links'] = $links;
  $vars['active'] = 'members';

  $block->content = theme('oa_core_members_widget', $vars);
  return $block;
}

/**
 * Edit form for the widget.
 */
function oa_core_members_widget_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['show_as_tabs'] = array(
    '#title' => t('Show as Tabs'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_as_tabs'],
  );
  $form['hide_owner'] = array(
    '#title' => t('Hide administrators'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_owner'],
  );
  $form['hide_teams'] = array(
    '#title' => t('Hide teams'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_teams'],
  );
  $form['hide_members'] = array(
    '#title' => t('Hide members'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_members'],
  );
  $form['hide_inherited'] = array(
    '#title' => t('Hide inherited'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_inherited'],
  );
  $form['show_number'] = array(
    '#title' => t('Number of members to show'),
    '#type' => 'textfield',
    '#default_value' => $conf['show_number'],
    '#description' => 'Enter zero to show all members.'
  );

  return $form;
}

function oa_core_members_widget_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

