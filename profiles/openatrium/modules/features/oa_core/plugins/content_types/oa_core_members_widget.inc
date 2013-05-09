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
    'show_number' => 10,
  ),
);


/**
 * Main render function for oa_core_members_widget.
 */
function oa_core_members_widget_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  if (!isset($context->data)) {
    return;
  }

  $block = new stdClass();
  $block->title = 'Members';

  $space = $context->data;
  $teams = oa_teams_get_teams_for_space($space->nid);
  $teams = node_load_multiple(array_keys($teams));
  $members = oa_core_get_users_for_space($space->nid);
  uasort($members, '_oa_core_sort_user_by_name');
  $owners = array();

  $is_admin = ($user->uid == 1) ? TRUE : FALSE;
  foreach ($members as $member) {
    $roles = og_get_user_roles('node', $space->nid, $member->uid);
    if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $space->uid) {
      $owners[$member->uid] = $member;
      if ($member->uid == $user->uid) {
        $is_admin = TRUE;
      }
    }
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

  $space_title = ($space->type == OA_SPACE_TYPE) ? t('Space') : t('Group');
  $vars['space_title'] = $space_title;
  $vars['owner_title'] = $space_title . ' ' . t('owners');
  $items = array(
    'teams' => $teams,
    'members' => $members,
    'owners' => $owners,
  );
  foreach ($items as $key => $entities) {
    $vars[$key] = array();
    foreach ($entities as $id => $entity) {
      $vars[$key][$id] = oa_core_entity_build_display($entity, $id);
      if ($entity->uid == $space->uid) {
        // don't show links for main space owner
        $vars[$key][$id]['uid'] = 0;
      }
    }
  }

  $vars['links']['dashboard'] = 'user/';
  if ($is_admin) {
    $vars['links']['remove'] = 'group/node/' . $space->nid . '/remove/';
    $vars['links']['add-admin'] = 'group/node/' . $space->nid . '/add-admin/';
    $vars['links']['remove-admin'] = 'group/node/' . $space->nid . '/remove-admin/';
  }
  else {
    $vars['links']['remove'] = '';
    $vars['links']['add-admin'] = '';
    $vars['links']['remove-admin'] = '';
  }
  if (!empty($conf['hide_owner'])) {
    unset($vars['owners']);
  }
  if (!empty($conf['hide_teams'])) {
    unset($vars['teams']);
  }
  $block->content = theme('oa_core_members_widget', $vars);
  return $block;
}

/**
 * Sort function to sort users by name.
 */
function _oa_core_sort_user_by_name($u1, $u2) {
  // Get last name for sorting.
  $name1 = $u1->realname ? array_pop(explode(' ', $u1->realname)) : $u1->name;
  $name2 = $u2->realname ? array_pop(explode(' ', $u2->realname)) : $u2->name;
  return strcasecmp($name1, $name2);
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_core_entity_build_display($entity, $id) {
  $type = isset($entity->nid) ? 'node' : 'user';
  $title = ($type == 'user') ?
    (empty($entity->realname) ? $entity->name : $entity->realname) :
    $entity->title;
  $nid = ($type == 'user') ? $entity->uid : $entity->nid;
  $display['title'] = l($title, $type . '/' . $nid);
  $display['uid'] = $entity->uid;

  if ($type == 'user') {
    $display['picture'] = oa_dashboard_render_user_picture($entity);
  }
  else {
    $display['picture'] = '';
  }

  return $display;
}

/**
 * Edit form for the widget.
 */
function oa_core_members_widget_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['hide_owner'] = array(
    '#title' => t('Hide space owner'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_owner'],
  );
  $form['hide_teams'] = array(
    '#title' => t('Hide teams'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_teams'],
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

