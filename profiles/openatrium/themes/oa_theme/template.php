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
 * Implements template_preprocess_page().
 */
function oa_theme_preprocess_page(&$variables) {
  // Add copyright to theme.
  if ($copyright = theme_get_setting('copyright')) {
    $variables['copyright'] = check_markup($copyright['value'], $copyright['format']);
  }
}

/**
 * Implements template_preprocess_html().
 */
function oa_theme_preprocess_html(&$variables) {
  global $base_url;
  // Add the needed fonts from google
  $base = parse_url($base_url);
  drupal_add_css($base['scheme'] . '://fonts.googleapis.com/css?family=Open+Sans:400,700,300', array('type' => 'external'));

  // determine if page title is being displayed
  if (isset($variables['page']['#handler']->conf['display']->content)) {
    $found = FALSE;
    foreach ($variables['page']['#handler']->conf['display']->content as $pane) {
      if ($pane->type == 'pane_oa_title') {
        $found = TRUE;
        break;
      }
    }
    if (!$found) {
      $variables['classes_array'][] = 'oa-no-page-title';
    }
  }
}
