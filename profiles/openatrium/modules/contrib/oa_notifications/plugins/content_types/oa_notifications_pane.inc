<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Notifications'),
  'description' => t('Displays the list of Groups, Teams and Users that will be notified of a change to an Entity.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_notifications_settings_form',
  'render callback' => 'oa_notifications_pane_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the pane.
 *
 * @see ctools_plugin_examples for more advanced info
 */
function oa_notifications_pane_render($subtype, $conf, $args, $context) {
  if (!isset($context->data)) {
    return;
  }
  $node = $context->data;

  $has_edit = node_access('update', $node);
  $output = $has_edit
      ? drupal_get_form('oa_notifications_edit_form', $node)
      : oa_notifications_render_view($node);

  $block = new stdClass();
  $block->title = t('Notifications');
  $block->content = $output;
  return $block;
}

/**
 * Render the read only version of the notifications listing.
 *
 * @param object $node
 *    The node being viewed/edited
 *
 * @return
 *    A render array of the notification configuration
 */
function oa_notifications_render_view($node) {
  $render = array(
    '#theme' => "oa_notifications_view",
    '#node' => $node,
  );
  $notifications = oa_notifications_load_multiple($node);

  if (array_key_exists('group', $notifications)) {
    $groups = node_load_multiple(array_keys($notifications['group']));
    foreach ($groups as $group) {
      $render['#group'][$group->nid] = $group->title;
    }
  }

  if (array_key_exists('team', $notifications)) {
    $teams = node_load_multiple(array_keys($notifications['team']));
    foreach ($teams as $team) {
      $render['#team'][$team->nid] = $team->title;
    }
  }

  if (array_key_exists('user', $notifications)) {
    $users = user_load_multiple(array_keys($notifications['user']));
    foreach ($users as $user) {
      $render['#user'][] = array(
        'uid' => $user->uid,
        'name' => oa_core_realname($user),
        'access' => node_access('view', $node, $user),
      );
    }
  }

  $render['#subscribe'] = oa_notifications_subscribe_button($node);
  $render['#show_details'] = oa_notifications_show_details_button($node);

  // Attach the bootstrap tooltip in case there is an access denied user.
  drupal_add_js('jQuery(document).ready(function () {
    jQuery("span.label-important").tooltip();
  });', 'inline');

  return $render;
}


/**
 * Empty config form
 */
function oa_notifications_settings_form($form, &$form_state) {
  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_notifications_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render the edit form for Notifications
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $node
 *    The node being viewed/edited
 * @return
 *    The form
 */
function oa_notifications_edit_form($form, &$form_state, $node) {
  // Since this form functions via AJAX we need to tell the form handlers to include it when processing the form
  ctools_form_include_file($form_state, drupal_get_path('module', 'oa_notifications') . '/plugins/content_types/oa_notifications_pane.inc');

  oa_notifications_form_fields($form, $form_state, $node);
  $form['source_entity'] = array(
    '#type' => 'value',
    '#value' => $node,
  );

  // Add things for direct pane updates
  $form['notifications']['group']['#ajax'] = array(
    'callback' => 'oa_notifications_ajax_callback',
    'wrapper' => 'group-div',
    'method' => 'replace',
  );
  $form['notifications']['group']['#prefix'] = '<div id="group-div">';
  $form['notifications']['group']['#suffix'] = '</div>';

  $form['notifications']['team']['#ajax'] = array(
    'callback' => 'oa_notifications_ajax_callback',
    'wrapper' => 'team-div',
    'method' => 'replace',
  );
  $form['notifications']['team']['#prefix'] = '<div id="team-div">';
  $form['notifications']['team']['#suffix'] = '</div>';

  $form['notifications']['user']['#ajax'] = array(
    'callback' => 'oa_notifications_ajax_callback',
    'wrapper' => 'user-div',
    'method' => 'replace',
  );
  $form['notifications']['user']['#prefix'] = '<div id="user-div">';
  $form['notifications']['user']['#suffix'] = '</div>';

  $form['notifications']['skip_notify']['#ajax'] = array(
    'callback' => 'oa_notifications_skip_ajax_callback',
    'wrapper' => 'skip-notify-div',
    'method' => 'replace',
  );
  $form['notifications']['skip_notify']['#prefix'] = '<div id="skip-notify-div">';
  $form['notifications']['skip_notify']['#suffix'] = '</div>';

  $form['subscribe'] = oa_notifications_subscribe_button($node);
  $form['details'] = oa_notifications_show_details_button($node);

  return $form;
}

/**
 * Builds a Flags powered subscribe button. Only if user isn't on notifications.
 */
function oa_notifications_subscribe_button($node) {
  return array(
    '#type' => 'markup',
    '#markup' => flag_create_link('subscribe_section_content', $node->nid),
  );
}

/**
 * Builds the show details button.
 */
function oa_notifications_show_details_button($node) {
  $details = l(t('Show Details'), 'js/oa_notifications/details/' . $node->nid, array(
    'attributes' => array(
      'class' => array('btn'),
      'data-toggle' => 'modal',
      'data-target' => '#oa-notifications-details',
    )
  ));
  $details .= theme('oa_styles_modal', array('modal_id' => 'oa-notifications-details', 'title' => t('Notification Details')));

  return array(
    '#type' => 'markup',
    '#markup' => $details,
  );
}

/**
 * Submit handler for the Notifications Pane
 */
function oa_notifications_edit_form_submit($form, &$form_state) {
  oa_notifications_save_notifications($form_state['values']);
}
