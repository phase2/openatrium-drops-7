<?php

/**
 * @file
 * Defines the Add Member panels pane.
 */

$plugin = array(
  'title' => t('Add Space Member'),
  'description' => t('Allows members to be added to the space.'),
  'single' => TRUE,
  'category' => t('Open Atrium'),
  'render callback' => 'oa_core_add_member_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_core_add_member_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }

  global $user;
  $space = $context->data;

  $is_admin = ($user->uid == 1) ? TRUE : FALSE;
  $members = oa_core_get_users_for_space($space->nid);
  foreach ($members as $member) {
    $roles = og_get_user_roles('node', $space->nid, $member->uid);
    if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $space->uid) {
      if ($member->uid == $user->uid) {
        $is_admin = TRUE;
      }
    }
  }

  if ($is_admin) {
    $output = drupal_get_form('oa_core_add_member_form', $space);

    $block = new stdClass();
    $block->title = t('Add Existing User');
    $block->content = $output;
    return $block;
  }
  return;
}

/**
 * Render the form for Add Member
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $space
 *    The space being viewed
 * @return
 *    The form
 */
function oa_core_add_member_form($form, &$form_state, $space) {
  // Since this form functions via AJAX we need to tell the form handlers to include it when processing the form
  ctools_form_include_file($form_state, drupal_get_path('module', 'oa_core') . '/plugins/content_types/oa_core_add_member.inc');

  $form['#space'] = $space;
  $name = ($space->type == OA_SPACE_TYPE) ? t('space') : t('group');

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('User name'),
    '#autocomplete_path' => 'user/autocomplete',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add to') . ' ' . $name,
  );

  return $form;
}

/**
 * Validate handler; Add users to group.
 */
function oa_core_add_member_form_validate($form, &$form_state) {
  $account = user_load_by_name($form_state['values']['name']);
  $space = $form['#space'];
  if (!$account) {
    form_set_error('name', t('You have entered an invalid user name.'));
    return;
  }
  elseif (og_get_membership('node', $space->nid, 'user', $account->uid)) {
    form_set_error('name', t('User %name is already subscribed to group.', array('%name' => format_username($account))));
  }
}

/**
 * Submit handler for adding member
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function oa_core_add_member_form_submit($form, &$form_state) {
  $space = $form['#space'];
  $account = user_load_by_name($form_state['values']['name']);
  oa_core_add_member('node', $space->nid, $account->uid, FALSE);
}


