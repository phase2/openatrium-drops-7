<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Add Space Content'),
  'description' => t('Provides a dropdown menu for adding content within a space'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_buttons_add_space_content_settings_form',
  'render callback' => 'oa_buttons_add_space_content_render',
);


/**
 * Provides the form for the widget.
 */
function oa_buttons_add_space_content_settings_form($form, &$form_state) {
  return $form;
}


/**
 * Renders the widget.
 */
function oa_buttons_add_space_content_render($subtype, $conf, $args, $context) {
  global $user;
  $block = new stdClass();
  $context = og_context();
  $section = oa_core_get_section_context();
  $content = '';
  if (isset($context['gid'])) {
    $node = node_load($context['gid']);
  }
  else {
    return;
  }
  $cache_key = 'oa_section_buttons:' . $context['gid'] . ':' . $section . ':' . $user->uid;
  // Lets cache this, since it can be expensive.
  if ($cache = cache_get($cache_key, 'cache_oa_section_buttons')) {
    $content = $cache->data;
  }
  else {
    $node_types = oa_buttons_get_command_buttons($node);
    if (count($node_types)) {
      drupal_alter('oa_space_buttons', $node_types);
      $buttons = command_buttons_machine_name_load(array_keys($node_types));
      $item_list = array();
      $classes = array(
        'use_dropdowns' => TRUE,
        'dropdown_label' => t('Create Content'),
        'item_class' => array(
          'oa-button',
         ),
        'wrapper_class' => array(
          'oa-buttons',
          'btn',
          'btn-inverse',
        ),
      );

      $content = command_buttons_render_buttons($buttons, $classes, $node_types);

      // Cache for 1 hour.
      cache_set($cache_key, $content, 'cache_oa_section_buttons', time() + 6000);
    }
  }

  $block->content = $content;

  return $block;
}


