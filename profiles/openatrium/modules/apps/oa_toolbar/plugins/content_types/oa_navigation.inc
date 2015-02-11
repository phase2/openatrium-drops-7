<?php
/**
 * @file
 * Provides a panels pane that displayes the OA Navigation.
 */

$plugin = array(
  'title' => t('Open Atrium Navigation'),
  'description' => t('The Open Atrium main menu navigation.'),
  'single' => TRUE,
  'category' => array(t('OA Admin'), -9),
);

/**
 * Render callback.
 */
function oa_toolbar_oa_navigation_content_type_render($subtype, $conf, $panel_args) {
  global $base_url;
  $block = new stdClass();
  $block->module = 'oa_toolbar';

  $vars = array();
  $vars['menu_name'] = $conf['menu_name'];

  // first check for space banner next to main menu
  if (module_exists('oa_appearance')) {
    drupal_add_js(drupal_get_path('module', 'oa_appearance') . '/oa_appearance.js');
    $space_id = oa_core_get_space_home_context();
    $banner = oa_appearance_get_space_banner($space_id, OA_SPACE_BANNER_MAIN_MENU);
    if ($banner['image']) {
      $vars['height'] = $banner['image']['height'];
      $vars['width'] = 0; // prevents stretching
      $vars['banner'] = theme('image_style',
        $banner['image'] + array('style_name' => 'oa_banner'));
    }
  }
  // next check for site banner
  if (empty($banner['image']) && variable_get('oa_menu_banner', TRUE) && !variable_get('oa_banner_stretch', FALSE)) {
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
function oa_toolbar_oa_navigation_content_type_edit_form($form, &$form_state) {
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
function oa_toolbar_oa_navigation_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Returns the administrative title.
 */
function oa_toolbar_oa_navigation_content_type_admin_title($subtype, $conf, $context) {
  return t('Open Atrium Navigation');
}
