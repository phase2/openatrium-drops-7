<?php

/**
 * @file
 * Provides a panels pane that shows space banner
 */

$plugin = array(
  'title' => t('Space Banner'),
  'description' => t('A panel for the space banner image.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_space_banner_edit_form',
  'render callback' => 'oa_space_banner_render',
  'defaults' => array(
    'banner_position' => 2,
  ),
);


/**
 * Render callback for the panel.
 */
function oa_space_banner_render($subtype, $conf, $args, $context = NULL) {
  global $base_url;

  $space_id = oa_core_get_space_home_context();
  $position = isset($conf['banner_position']) ? $conf['banner_position'] : OA_SPACE_BANNER_BELOW;

  $site_banner_position = variable_get('oa_site_banner_position', 0);
  $show_site = ($site_banner_position == $conf['banner_position']);

  if (($space = node_load(oa_core_get_group_from_node($space_id))) && node_access('view', $space)) {
    $field = field_get_items('node', $space, OA_SPACE_BANNER_POSITION);
  }
  $show_space = (!empty($field[0]['value']) && ($field[0]['value'] == $conf['banner_position']));
  if ($show_space) {
    $space_picture = field_get_items('node', $space, 'field_oa_banner');
    if (!empty($space_picture)) {
      $space_picture = array_shift($space_picture);
    }
    else {
      $show_space = FALSE;
    }
  }
  if ($show_site) {
    $fid = variable_get('oa_site_banner', '');
    if ($fid && ($site_file = file_load($fid))) {
      // successful banner loaded
    }
    elseif (variable_get('oa_banner_default', TRUE)) {
      // use default banner image
      $site_file = new stdClass();
      $path = drupal_get_path('module', 'oa_widgets');
      $site_file->uri = $base_url . '/' . $path . '/openatrium-powered.png';
      $site_file->metadata['height'] = 43;
      $site_file->metadata['width'] = 161;
    }
    else {
      $show_site = FALSE;
    }
  }
  if (!$show_site && !$show_space) {
    return;
  }

  drupal_add_js(drupal_get_path('module', 'oa_appearance') . '/oa_appearance.js');

  $vars = array();

  $vars['banner'] = '';
  $vars['text'] = '';
  $vars['slogan'] = '';
  $vars['height'] = '';
  $vars['width'] = '';
  $vars['banner_text_class'] = 'oa-banner-overlay';
  $vars['banner_slogan_class'] = 'oa-banner-slogan-overlay';
  $vars['banner_class'] = ($conf['banner_position'] == 1) ? 'oa-banner-before' : 'oa-banner-after';

  if ($show_space) {
    $vars['height'] = $space_picture['height'];
    $vars['width'] = $space_picture['width'];
    $vars['banner'] = theme('image', array(
      'path' => $space_picture['uri'],
      'width' => $space_picture['width'],
      'height' => $space_picture['height'],
      'alt' => $space_picture['alt'],
      'attributes' => array(
        'class' => 'oa-banner-overlay-img'
      ),
    ));
    $field = field_view_field('node', $space, 'field_oa_banner_text', array('label' => 'hidden'));
    if (!empty($field)) {
      $vars['text'] = drupal_render($field);
    }
  }
  elseif ($show_site) {
    $vars['height'] = (!empty($site_file->metadata['height'])) ? $site_file->metadata['height'] : 0;
    $vars['width'] = (!empty($site_file->metadata['width'])) ? $site_file->metadata['width'] : 0;
    $stretch = variable_get('oa_banner_stretch', FALSE);
    $vars['banner'] = theme('image', array(
      'path' => $site_file->uri,
      'width' => $vars['width'],
      'height' => $vars['height'],
      'alt' => t('Site banner'),
      'attributes' => array(
        'class' => ($stretch) ? 'oa-banner-overlay-img' : 'oa-banner-img',
      ),
    ));
    $vars['width'] = ($stretch) ? $vars['width'] : 0;
    $use_sitename = variable_get('oa_banner_sitename', TRUE);
    if ($use_sitename) {
      $vars['text'] = variable_get('site_name', '');
    }
    $use_siteslogan = variable_get('oa_banner_siteslogan', FALSE);
    if ($use_siteslogan) {
      $vars['slogan'] = variable_get('site_slogan', '');
    }
    if (!$stretch) {
      $vars['banner_text_class'] = 'oa-banner-text';
      $vars['banner_slogan_class'] = 'oa-banner-slogan';
    }
  }
  $block = new stdClass();
  $block->title = '';
  $block->content = theme('oa_space_banner', $vars);
  return $block;
}


/**
 * Edit form for the panel.
 */
function oa_space_banner_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['banner_position'] = array(
    '#type' => 'select',
    '#options' => array(
      0 => 'Hidden',
      1 => 'Above toolbar',
      2 => 'Below toolbar',
    ),
    '#title' => 'Banner Position',
    '#empty_option' => '--Banner Position--',
    '#default_value' => $conf['banner_position'],
  );

  return $form;
}

function oa_space_banner_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
