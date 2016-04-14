<?php

/**
 * @file
 * Defines the Space config menu widget.
 */

$plugin = array(
  'title' => t('Space config menu'),
  'description' => t('Display a menu of space config actions.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'edit form' => 'oa_contextual_tabs_oa_space_config_form',
  'render callback' => 'oa_contextual_tabs_oa_space_config_render',
  'defaults' => array(
    'btn_class' => 'btn',
    'icon_class' => 'icon-cog',
    'direction' => '',
  ),
);


/**
 * Render callback for the pane.
 */
function oa_contextual_tabs_oa_space_config_render($subtype, $conf, $args, $context = NULL) {
  $block = FALSE;
  $space_id = oa_core_get_space_context();

  $vars = array();
  $config_links = array();
  $admin_links = array();
  $vars['space_url'] = '';
  $vars['config_url'] = '';
  $vars['space_title'] = '';

  if (isset($space_id) && ($space = node_load($space_id)) && node_access('view', $space)) {
    $vars['space_url'] = url('node/' . $space_id);
    $vars['config_url'] = url('node/' . $space_id . '/group');
    $vars['space_title'] = $space->title;

    // First, gather og group menu items
    $entity_type = 'node';
    if (module_exists('og_ui')) {
      $config_links = og_ui_get_group_admin($entity_type, $space_id);

      foreach ($config_links as $key => &$item) {
        // Re-format the URL.
        $item['href'] = "group/$entity_type/$space_id/" . $item['href'];
        // Imitate the menu_get_item() content, so we can pass it to
        // theme_admin_block_content(), so we add the localized_options key.
        $item['localized_options'] = array();
      }
    }
    unset($item);
  }
  else {
    $space_id = 0;
  }

  // Gather any task links
  $task_links = oa_contextual_tabs_task_links();
  if (!empty($task_links)) {
    foreach ($task_links as $key => $link) {
      if (drupal_match_path($link['path'], 'node/%/group')) {
        // Remove config link from contextual_links
        unset($task_links[$key]);
      }
    }
  }

  // Non-space-config local task links will go on top
  $filter = variable_get('oa_contextual_restrict', 1);
  if ($filter != 0) {
    if ($space_id) {
      // Remove space config tasks.
      oa_contextual_tabs_filter_links($task_links, 'oa_space_config_pages');
    }
    oa_contextual_tabs_filter_links($task_links, 'oa_user_config_pages');
    $contextual_links = oa_contextual_tabs_filter_links($task_links, 'oa_tasks_contextual', ($filter != 2));
    if ($filter == 1) {
      // In auto mode, remove tasks we put into space_config or top links
      oa_contextual_tabs_task_links($contextual_links);
    }
  }

  if ($space_id) {
    // Build list of space-config tasks for the current space
    $admin_links = array();
    $config_pages = explode("\n", variable_get('oa_space_config_pages', ''));
    foreach ($config_pages as $path) {
      if (strpos(trim($path), 'node/*/') === 0) {
        $new_path = str_replace('node/*/', 'node/' . $space_id . '/', trim($path));
        if (drupal_valid_path($new_path)) {
          $router = menu_get_item(trim($new_path));
          $link = array(
            'title' => $router['title'],
            'href' => $new_path,
          );
          $admin_links[] = $link;
        }
      }
    }
  }

  $vars['btn_class'] = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn';
  $vars['btn_class'] .= variable_get('oa_toolbar_style', 0) ? '' : ' btn-inverse';
  $vars['direction'] = !empty($conf['direction']) ? check_plain($conf['direction']) : '';
  $vars['icon'] = !empty($conf['icon_class']) ? check_plain($conf['icon_class']) : 'icon-cog';
  $vars['title'] = theme('head_title');

  $vars['top_links'] = theme('links', array(
    'links' => $task_links,
  ));
  $vars['admin_links'] = theme('links', array(
    'links' => $admin_links,
  ));
  $vars['config_links'] = theme('links', array(
    'links' => $config_links,
  ));

  if (!empty($task_links) || !empty($config_links) || !empty($admin_links)) {
    $block = new stdClass();
    $block->title = '';
    $block->content = theme('oa_space_config', $vars);
  }

  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_contextual_tabs_oa_space_config_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['direction'] = array(
    '#type' => 'select',
    '#title' => t('Direction'),
    '#options' => array(
      '' => t('Drop down'),
      'dropup' => t('Drop up'),
    ),
    '#default_value' => (isset($conf['direction'])) ? $conf['direction'] : '',
    '#description' => t('Controls whether menu expands downwards or upwards.  Default is drop down.'),
  );
  $form['icon_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class'),
    '#description' => t('CSS class name for icon.  Default is icon-cog.'),
    '#default_value' => !empty($conf['icon_class']) ? $conf['icon_class'] : 'icon-cog',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : '',
  );

  return $form;
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_contextual_tabs_oa_space_config_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

