<?php
/**
 * @file oa_sitemap_app.inc
 */

$plugin = array(
  'title' => t('Site Map (App)'),
  'description' => t('Displays the site map of a space.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
  'edit form' => 'oa_sitemap_app_settings_form',
  'render callback' => 'oa_sitemap_app_render',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
  'defaults' => array(
    'oa_sitemap_parent' => FALSE,
    'oa_sitemap_help' => FALSE,
    'oa_sitemap_fullpage' => FALSE,
    'oa_sitemap_space_help' => '',
    'oa_sitemap_section_help' => '',
  ),
);

/**
 * Run-time rendering of the body of the pane.
 *
 * @see ctools_plugin_examples for more advanced info
 */
function oa_sitemap_app_render($subtype, $conf, $args, $context) {
  global $user;

  $logged_in = ($user->uid != 0);

  $node = NULL;
  if (isset($context->data)) {
    $node = $context->data;
  }
  $space_id = isset($node) ? $node->nid : 0;

  $title = (empty($node) || !empty($conf['oa_sitemap_parent'])) ? variable_get('site_name', '') : $node->title;
  // Don't sanitize title yet, it will get handled by drupal_set_title and by
  // {{}} sanitization in angular
  $page_title = !empty($title) ? t('Site Map for !space', array('!space' => $title)) : t('Site Map');

  $base = drupal_get_path('module', 'oa_sitemap');

  ctools_include('modal');
  ctools_modal_add_js();

  drupal_set_title($page_title);

  $terms = oa_sections_get_icons();
  $icons = array();
  $icons[0] = '<i class="icon-plus"></i>';
  foreach ($terms as $id => $term) {
    if (!empty($term->field_oa_icon_class_value)) {
      $icon = '<i class="' . check_plain($term->field_oa_icon_class_value) . '"></i>';
    }
    elseif (!empty($term->field_oa_icon_image_fid)) {
      $file = file_load($term->field_oa_icon_image_fid);
      $content = array(
        'file' => array(
          '#theme' => 'image_style',
          '#style_name' => 'oa_medium_thumbnail',
          '#path' => $file->uri,
        ),
      );
      $icon = drupal_render($content);
    }
    else {
      $icon = '<i class="icon-th-large"></i>';
    }
    $icons[$id] = $icon;
  }

  $top_id = empty($conf['oa_sitemap_parent']) ? $space_id : 0;
  $options = array();
  if ($top_id == 0) {
    $options[0] = $title;
  }
  $spaces = array();
  oa_sitemap_spaces($top_id, $spaces);

  $map_link = '';
  if (empty($conf['oa_sitemap_parent']) && ($space_id != 0)) {
    $map_link = l(t('Full sitemap'), 'sitemap/' . $space_id);
  }

  $header_vars = array(
    'link' => $map_link,
  );

  drupal_add_js(array(
    'oa_sitemap' => array(
      'topID' => $space_id,
      'icons' => $icons,
      'spaces' => $spaces,
      'showHelp' => !empty($conf['oa_sitemap_help']) ? $logged_in && $conf['oa_sitemap_help'] : FALSE,
      'options' => isset($_SESSION['oa_sitemap_option']) ? $_SESSION['oa_sitemap_option'] : 1,
      'fullPage' => !empty($conf['oa_sitemap_fullpage']) ? $logged_in && $conf['oa_sitemap_fullpage'] : FALSE,
      'spaceHelp' => !empty($conf['oa_sitemap_space_help']['value']) ? $conf['oa_sitemap_space_help']['value'] : '',
      'sectionHelp' => !empty($conf['oa_sitemap_section_help']['value']) ? $conf['oa_sitemap_section_help']['value'] : '',
      'basePath' => base_path() . $base,
      'title' => $page_title,
    ),
    'oa-sitemap-section' => array(
      'modalSize' => array(
        'type' => 'scale',
        'width' => 0.7,
        'height' => 0.9,
      ),
      'animation' => 'fadeIn',
    ),
    'oa-sitemap-space' => array(
      'modalSize' => array(
        'type' => 'scale',
        'width' => 0.7,
        'height' => 0.5,
      ),
      'animation' => 'fadeIn',
    ),
  ), 'setting');

  oa_angular_add(array('sanitize', 'ngDraggable'));

  drupal_add_js($base . '/js/oa_sitemap_app.js');
  drupal_add_css($base . '/css/oa_sitemap_app.css');

  $block = new stdClass();
  $block->title = '';
  $block->content = theme('oa_sitemap_app', $header_vars);
  return $block;
}

/**
 * Empty config form
 */
function oa_sitemap_app_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['oa_sitemap_parent'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show full parent tree'),
    '#default_value' => $conf['oa_sitemap_parent'],
  );
  $form['oa_sitemap_help'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show help text'),
    '#default_value' => $conf['oa_sitemap_help'],
  );
  $form['oa_sitemap_fullpage'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show fullpage theming'),
    '#default_value' => $conf['oa_sitemap_fullpage'],
  );
  $form['oa_sitemap_space_help'] = array(
    '#title' => t('Create Space help text'),
    '#description' => t('Enter the text to be displayed for the Create Space help box.'),
    '#type' => 'text_format',
    '#format' => isset($conf['oa_sitemap_space_help']['format']) ? $conf['oa_sitemap_space_help']['format'] : 'panopoly_wysiwyg_text',
    '#default_value' => isset($conf['oa_sitemap_space_help']['value']) ? $conf['oa_sitemap_space_help']['value'] : '',
  );
  $form['oa_sitemap_section_help'] = array(
    '#title' => t('Create Section help text'),
    '#description' => t('Enter the text to be displayed for the Create Section help box.'),
    '#type' => 'text_format',
    '#format' => isset($conf['oa_sitemap_section_help']['format']) ? $conf['oa_sitemap_section_help']['format'] : 'panopoly_wysiwyg_text',
    '#default_value' => isset($conf['oa_sitemap_section_help']['value']) ? $conf['oa_sitemap_section_help']['value'] : '',
  );

  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_sitemap_app_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
