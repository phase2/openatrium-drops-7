<?php
/**
 * @file
 * Provides a panels pane that displayes the OA Navigation.
 */

$plugin = array(
  'title' => t('Open Atrium Navigation'),
  'description' => t('The Open Atrium navigation.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
);

/**
 * Render callback.
 */
function oa_dashboard_oa_navigation_content_type_render($subtype, $conf, $panel_args) {
  global $base_url;
  $block = new stdClass();
  $block->module = 'oa_dashboard';

  $vars = array();
  $vars['menu_name'] = $conf['menu_name'];

  // first check for space banner next to main menu
  $show_space = FALSE;
  if (module_exists('oa_appearance')) {
    drupal_add_js(drupal_get_path('module', 'oa_appearance') . '/oa_appearance.js');
    $space_id = oa_core_get_space_home_context();
    if (($space = node_load(oa_core_get_group_from_node($space_id))) && node_access('view', $space)) {
      $field = field_get_items('node', $space, OA_SPACE_BANNER_POSITION);
    }
    $show_space = (!empty($field[0]['value']) && ($field[0]['value'] == OA_SPACE_BANNER_MAIN_MENU));
    if ($show_space) {
      $space_picture = field_get_items('node', $space, 'field_oa_banner');
      if (!empty($space_picture)) {
        $space_picture = array_shift($space_picture);
        $vars['height'] = $space_picture['height'];
        $vars['width'] = 0; // prevents stretching
        $vars['banner'] = theme('image_style', array(
          'style_name' => 'oa_banner',
          'path' => $space_picture['uri'],
          'width' => $space_picture['width'],
          'height' => $space_picture['height'],
          'alt' => $space_picture['alt'],
          'attributes' => array(
            'class' => array('oa-banner-img')
          ),
        ));
      }
      else {
        $show_space = FALSE;
      }
    }
  }
  // next check for site banner
  if (!$show_space && variable_get('oa_menu_banner', TRUE) && !variable_get('oa_banner_stretch', FALSE)) {
    $fid = variable_get('oa_site_banner', '');
    if ($fid && ($site_file = file_load($fid))) {
      // banner found
    }
    elseif (variable_get('oa_banner_default', TRUE)) {
      // use default banner image
      $site_file = new stdClass();
      $path = drupal_get_path('module', 'oa_widgets');
      $site_file->uri = $base_url . '/' . $path . '/openatrium-powered.png';
      $site_file->metadata['height'] = 43;
      $site_file->metadata['width'] = 161;
    }
    if (!empty($site_file)) {
      $vars['height'] = (!empty($site_file->metadata['height'])) ? $site_file->metadata['height'] : 0;
      $vars['width'] = (!empty($site_file->metadata['width'])) ? $site_file->metadata['width'] : 0;
      $vars['banner'] = l(theme('image', array(
        'path' => $site_file->uri,
        'width' => $vars['width'],
        'height' => $vars['height'],
        'alt' => t('Site banner'),
        'attributes' => array(
          'class' => array('oa-site-banner-img'),
        ),
      )), '<front>', array('html' => TRUE));
      $vars['width'] = 0;
    }
  }
  $vars['show_menu'] = variable_get('oa_mainmenu', TRUE);
  $block->content = theme('oa_navigation', $vars);

  return $block;
}

/**
 * Edit form callback.
 */
function oa_dashboard_oa_navigation_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $menus = menu_get_menus();

  $form['menu_name'] = array(
    '#title' => t('Menu'),
    '#type' => 'select',
    '#description' => t('Menu to use for the OA Navigation.'),
    '#options' => $menus,
    '#required' => TRUE,
    '#default_value' => $conf['menu_name'],
  );

  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function oa_dashboard_oa_navigation_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Returns the administrative title.
 */
function oa_dashboard_oa_navigation_content_type_admin_title($subtype, $conf, $context) {
  return t('Open Atrium Navigation');
}
