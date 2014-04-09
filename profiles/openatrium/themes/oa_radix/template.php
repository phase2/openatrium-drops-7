<?php

/**
 * @file
 * Theme functions
 */

require_once dirname(__FILE__) . '/includes/structure.inc';
require_once dirname(__FILE__) . '/includes/form.inc';
require_once dirname(__FILE__) . '/includes/menu.inc';
require_once dirname(__FILE__) . '/includes/comment.inc';
require_once dirname(__FILE__) . '/includes/node.inc';

/**
 * Implements hook_css_alter().
 * Changes the jQuery UI theme to a Bootstrap-like theme
 * from http://addyosmani.github.io/jquery-ui-bootstrap/
 */
function oa_radix_css_alter(&$css) {
  $radix_path = drupal_get_path('theme', 'radix');

  // Radix now includes compiled stylesheets for demo purposes.
  // We remove these from our subtheme since they are already included
  // in compass_radix.
  unset($css[$radix_path . '/assets/stylesheets/radix-style.css']);
  unset($css[$radix_path . '/assets/stylesheets/radix-print.css']);

  // Add a custom jQuery UI theme.
  if (isset($css['misc/ui/jquery.ui.theme.css'])) {
    $css['misc/ui/jquery.ui.theme.css']['data'] =
      drupal_get_path('theme', 'oa_radix') . '/assets/vendor/jqueryui/jquery-ui-1.10.0.custom.css';
  }
}

/**
 * Implements hook_module_implements_alter().
 * Remove panopoly_core which uses this alter to set it's own jquery_ui theme
 * Should be done in a theme layer, not in panopoly_core
 */
function oa_radix_module_implements_alter(&$implementations, $hook) {
  if ($hook == 'element_info_alter') {
    unset($implementations['panopoly_core']);
  }
}

/**
 * Implements template_preprocess_page().
 */
function oa_radix_preprocess_page(&$vars) {
  // Rework search_form to our liking.
  $vars['search_form'] = '';
  if (module_exists('search') && user_access('search content')) {
    $search_box_form = drupal_get_form('search_form');
    $search_box_form['basic']['keys']['#title'] = '';
    $search_box_form['basic']['keys']['#attributes'] = array('placeholder' => 'Search');
    $search_box_form['basic']['keys']['#attributes']['class'][] = 'search-query';
    $search_box_form['basic']['submit']['#value'] = t('Search');
    $search_box_form['#attributes']['class'][] = 'navbar-form';
    $search_box_form['#attributes']['class'][] = 'pull-right';
    $search_box = drupal_render($search_box_form);
    $vars['search_form'] = (user_access('search content')) ? $search_box : NULL;
  }

  // Add user_badge to header.
  $vars['user_badge'] = '';
  if (module_exists('oa_dashboard')) {
    $user_badge = module_invoke('oa_dashboard', 'block_view', 'oa_user_badge');
    $vars['user_badge'] = $user_badge['content'];
  }
  $toolbar = panels_mini_block_view('oa_toolbar_panel');
  $vars['oa_toolbar_panel'] = isset($toolbar) ? $toolbar['content'] : '';
  $footer = panels_mini_block_view('oa_footer_panel');
  $vars['oa_footer_panel'] = isset($footer) ? $footer['content'] : '';

  ctools_include('content');
  $banner = ctools_content_render('oa_space_banner', '', array(
    'banner_position' => 2
  ));
  if (!empty($banner->content)) {
    $vars['oa_banner'] = $banner->content;
  }
  $vars['oa_space_menu'] = '';
  $space_id = oa_core_get_space_context();
  if (variable_get('oa_space_menu_' . $space_id, TRUE)) {
    $space_menu = ctools_content_render('oa_space_menu', '', array(), array());
    if (!empty($space_menu->content)) {
      $vars['oa_space_menu'] = $space_menu->content;
    }
  }
}

