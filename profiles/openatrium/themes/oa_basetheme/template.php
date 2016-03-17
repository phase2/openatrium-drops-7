<?php

/**
 * @file
 * Theme functions
 */

// Include all files from the includes directory.
$includes_path = dirname(__FILE__) . '/includes/*.inc';
foreach (glob($includes_path) as $filename) {
  require_once dirname(__FILE__) . '/includes/' . basename($filename);
}

/**
 * Implements hook_css_alter().
 * Changes the jQuery UI theme to a Bootstrap-like theme
 * from http://addyosmani.github.io/jquery-ui-bootstrap/
 */
function oa_basetheme_css_alter(&$css) {
  // Unset some panopoly css.
  if (module_exists('panopoly_admin')) {
    $panopoly_admin_path = drupal_get_path('module', 'panopoly_admin');
    if (isset($css[$panopoly_admin_path . '/panopoly-admin.css'])) {
      unset($css[$panopoly_admin_path . '/panopoly-admin.css']);
    }
  }

  if (module_exists('panopoly_magic')) {
    $panopoly_magic_path = drupal_get_path('module', 'panopoly_magic');
    if (isset($css[$panopoly_magic_path . '/css/panopoly-modal.css'])) {
      unset($css[$panopoly_magic_path . '/css/panopoly-modal.css']);
    }
  }

  // Add a custom jQuery UI theme.
  if (isset($css['misc/ui/jquery.ui.theme.css'])) {
    $css['misc/ui/jquery.ui.theme.css']['data'] =
      drupal_get_path('theme', 'oa_basetheme') . '/assets/vendor/jqueryui/jquery-ui-1.10.0.custom.css';
  }

  // Unset some core css.
  unset($css['modules/system/system.menus.css']);
}

/**
 * Implements hook_js_alter().
 */
function oa_basetheme_js_alter(&$javascript) {
  // Add oa_basetheme-modal when required.
  if (module_exists('ctools')) {
    $ctools_modal = drupal_get_path('module', 'ctools') . '/js/modal.js';
    $oa_basetheme_modal = drupal_get_path('theme', 'oa_basetheme') . '/assets/js/oa_basetheme.modal.js';
    if (!empty($javascript[$ctools_modal]) && empty($javascript[$oa_basetheme_modal])) {
      $javascript[$oa_basetheme_modal] = array_merge(
        drupal_js_defaults(), array('group' => JS_THEME, 'data' => $oa_basetheme_modal));
    }
  }

  // Add oa_basetheme-field-slideshow when required.
  if (module_exists('field_slideshow')) {
    $field_slideshow = drupal_get_path('module', 'field_slideshow') . '/field_slideshow.js';
    $oa_basetheme_field_slideshow = drupal_get_path('theme', 'oa_basetheme') . '/assets/js/oa_basetheme.slideshow.js';
    if (!empty($javascript[$field_slideshow]) && empty($javascript[$oa_basetheme_field_slideshow])) {
      $javascript[$oa_basetheme_field_slideshow] = array_merge(
        drupal_js_defaults(), array('group' => JS_THEME, 'data' => $oa_basetheme_field_slideshow));
    }
  }

  // Add oa_basetheme-progress when required.
  $progress = 'misc/progress.js';
  $oa_basetheme_progress = drupal_get_path('theme', 'oa_basetheme') . '/assets/js/oa_basetheme.progress.js';
  if (!empty($javascript[$progress]) && empty($javascript[$oa_basetheme_progress])) {
    $javascript[$oa_basetheme_progress] = array_merge(
      drupal_js_defaults(), array('group' => JS_THEME, 'data' => $oa_basetheme_progress));
  }
}

/**
 * Implements hook_module_implements_alter().
 * Remove panopoly_core which uses this alter to set it's own jquery_ui theme
 * Should be done in a theme layer, not in panopoly_core
 */
function oa_basetheme_module_implements_alter(&$implementations, $hook) {
  if ($hook == 'element_info_alter') {
    unset($implementations['panopoly_core']);
  }
}

/**
 * Implements hook_ctools_plugin_post_alter().
 *
 * @param $plugin
 * @param $info
 */
function oa_basetheme_ctools_plugin_post_alter(&$plugin, &$info) {
  // Fix Panopoly bryant_flipped_flipped.inc filename
  if ($info['type'] == 'layouts' && $plugin['module'] == 'panopoly_theme') {
    if (strpos($plugin['theme'], 'bryant_flipped') !== FALSE) {
      if (strpos($plugin['file'], 'flipped_flipped') !== FALSE) {
        $plugin['file'] = str_replace('flipped_flipped', 'flipped', $plugin['file']);
      }
    }
  }
}

/**
 * Implements template_preprocess_html().
 */
function oa_basetheme_preprocess_html(&$variables) {
  global $base_url;

//  // Add Bootstrap JS from CDN if bootstrap library is not installed.
  if (!module_exists('bootstrap_library')) {
    $base = parse_url($base_url);
    $url = $base['scheme'] . '://netdna.bootstrapcdn.com/bootstrap/3.1.1/js/bootstrap.min.js';
    $jquery_ui_library = drupal_get_library('system', 'ui');
    $jquery_ui_js = reset($jquery_ui_library['js']);
    drupal_add_js($url, array(
      'type' => 'external',
      // We have to put Bootstrap after jQuery, but before jQuery UI.
      'group' => JS_LIBRARY,
      'weight' => $jquery_ui_js['weight'] - 1,
    ));
  }

  // Add meta for Bootstrap Responsive.
  // <meta name="viewport" content="width=device-width, initial-scale=1.0">
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1.0',
    ),
  );
  drupal_add_html_head($element, 'bootstrap_responsive');

  // Add some custom classes for panels pages.
  if (module_exists('page_manager') && count(page_manager_get_current_page())) {
    $variables['is_panel'] = TRUE;

    // Get the current panel display and add some classes to body.
    if ($display = panels_get_current_page_display()) {
      $variables['classes_array'][] = 'panel-layout-' . $display->layout;

      // Add a custom class for each region that has content.
      $regions = array_keys($display->panels);
      foreach ($regions as $region) {
        $variables['classes_array'][] = 'panel-region-' . $region;
      }
    }
  }
}

/**
 * Implements template_preprocess_page().
 */
function oa_basetheme_preprocess_page(&$variables) {
  // Determine if the page is rendered using panels.
  $variables['is_panel'] = FALSE;
  if (module_exists('page_manager') && count(page_manager_get_current_page())) {
    $variables['is_panel'] = TRUE;
  }

  // Make sure tabs is empty.
  if (empty($variables['tabs']['#primary']) && empty($variables['tabs']['#secondary'])) {
    $variables['tabs'] = '';
  }

  // Theme action links as buttons.
  if (!empty($variables['action_links'])) {
    foreach (element_children($variables['action_links']) as $key) {
      $variables['action_links'][$key]['#link']['localized_options']['attributes'] = array(
        'class' => array('btn', 'btn-primary', 'btn-sm'),
      );
    }
  }
  // Rework search_form to our liking.
  $variables['search_form'] = '';
  if (module_exists('search') && user_access('search content')) {
    $search_box_form = drupal_get_form('search_form');
    $search_box_form['basic']['keys']['#title'] = '';
    $search_box_form['basic']['keys']['#attributes'] = array('placeholder' => 'Search');
    $search_box_form['basic']['keys']['#attributes']['class'][] = 'search-query';
    $search_box_form['basic']['submit']['#value'] = t('Search');
    $search_box_form['#attributes']['class'][] = 'navbar-form';
    $search_box_form['#attributes']['class'][] = 'pull-right';
    $search_box = drupal_render($search_box_form);
    $variables['search_form'] = (user_access('search content')) ? $search_box : NULL;
  }

  $variables['user_badge'] = '';
  $variables['mobile_buttons'] = '';
  if (module_exists('oa_toolbar')) {
    // Add user_badge to header.
    $user_badge = module_invoke('oa_toolbar', 'block_view', 'oa_user_badge');
    $variables['user_badge'] = $user_badge['content'];
    $variables['mobile_buttons'] = theme('oa_toolbar_mobile');
  }
  $toolbar_name = variable_get_value('oa_layouts_minipanel_header', array('defaults' => 'oa_toolbar_panel'));
  $toolbar = panels_mini_block_view($toolbar_name);
  $variables['oa_toolbar_panel'] = isset($toolbar) ? $toolbar['content'] : '';
  $footer_name = variable_get_value('oa_layouts_minipanel_footer', array('defaults' => 'oa_footer_panel'));
  $footer = panels_mini_block_view($footer_name);
  $variables['oa_footer_panel'] = isset($footer) ? $footer['content'] : '';

  ctools_include('content');
  $banner = ctools_content_render('oa_space_banner', '', array(
    'banner_position' => 2
  ));
  if (!empty($banner->content)) {
    $variables['oa_banner'] = $banner->content;
  }
  $variables['oa_space_menu'] = '';
  $space_id = oa_core_get_space_context();
  if (variable_get('oa_space_menu_' . $space_id, TRUE)) {
    $space_menu = ctools_content_render('oa_space_menu', '', array(), array());
    if (!empty($space_menu->content)) {
      $variables['oa_space_menu'] = $space_menu->content;
    }
  }

  // Format and add main menu to theme.
  $variables['main_menu'] = _oa_basetheme_dropdown_menu_tree(variable_get('menu_main_links_source', 'main-menu'), array(
    'min_depth' => 1,
    'max_depth' => 2,
  ));

  // Add a copyright message.
  $variables['copyright'] = t('Drupal is a registered trademark of Dries Buytaert.');
}
