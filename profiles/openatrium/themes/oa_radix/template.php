<?php

/**
 * @file
 * Theme functions
 */


/**
 * Implements template_preprocess_page().
 */
function oa_radix_preprocess_page(&$vars) {

// grab the Bootstrap JS since we can't currently add Bootstrap to our
// make file because Drupal is GPLv2 instead of GPLv3
  drupal_add_js('http://netdna.bootstrapcdn.com/twitter-bootstrap/2.3.1/js/bootstrap.min.js', 'external');

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
}
