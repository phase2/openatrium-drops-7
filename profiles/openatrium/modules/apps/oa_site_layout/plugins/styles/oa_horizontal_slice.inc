<?php
/**
 * @file
 * Definition of the toolbar pane style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Horizontal slice'),
  'description' => t('Renders a region as a horizontal slice, such as a toolbar'),
  'render pane' => 'oa_horizontal_slice_render_pane',
  'render region' => 'oa_horizontal_slice_render_region',
  'pane settings form' => 'oa_horizontal_slice_settings_form',
  'hook theme' => array(
    'oa_horizontal_slice' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'oa_site_layout') . '/plugins/styles',
      'template' => 'oa-horizontal-slice',
    ),
  ),
);

/**
 * Helper function to set variables based on config settings.
 * @param $vars
 */
function _oa_horizontal_slice_configure(&$vars, $hidden = FALSE) {
  $vars['settings']['attr'] = '';
  $vars['settings']['classes'] = 'oa-horizontal-slice style-region';
  $vars['settings']['classes'] .= !empty($vars['settings']['toolbar']) ? ' oa-toolbar-style navbar navbar-inverse' : '';
  $vars['settings']['classes'] .= !empty($vars['settings']['position']) && !$hidden ? ' navbar-fixed-top' : '';
  $vars['settings']['classes'] .= isset($vars['settings']['margins']) ? ' ' . check_plain($vars['settings']['margins']) : '';
  $vars['settings']['classes'] .= $hidden ? ' oa-hidden' : '';
}

/**
 * Helper function to actually theme/render the slice
 * @param $content
 * @param $vars
 * @return string
 */
function _oa_horizontal_slice_render($content, $vars) {
  drupal_add_css(drupal_get_path('module', 'oa_site_layout') . '/oa_site_layout.css');

  _oa_horizontal_slice_configure($vars);
  $output = theme('oa_horizontal_slice', array('content' => $content, 'settings' => $vars['settings']));

  if (!empty($vars['settings']['position'])) {
    // When using a fixed top toolbar, duplicate the toolbar with a hidden version to handle the body offset
    // See http://codepen.io/parkerbennett/pen/hbzJm for Fixed Header Design Pattern
    _oa_horizontal_slice_configure($vars, TRUE);
    $output .= theme('oa_horizontal_slice', array('content' => $content, 'settings' => $vars['settings']));
  }
  return $output;
}

/**
 * Render callback for a single region.
 */
function theme_oa_horizontal_slice_render_region($vars) {
  $output = implode($vars['panes']);
  return _oa_horizontal_slice_render($output, $vars);
}

/**
 * Render callback for a single pane.
 */
function theme_oa_horizontal_slice_render_pane($vars) {
  $content = $vars['content'];
  if (empty($content->content)) {
    return;
  }

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $vars['pane'], 'display' => $vars['display']));
  return _oa_horizontal_slice_render($output, $vars);
}

/**
 * Settings form callback.
 */
function oa_horizontal_slice_settings_form($style_settings) {
  $form['position'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fixed to top of page'),
    '#default_value' => (isset($style_settings['position'])) ? $style_settings['position'] : 0,
  );
  $form['toolbar'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use toolbar colors'),
    '#default_value' => (isset($style_settings['toolbar'])) ? $style_settings['toolbar'] : 0,
  );
  $form['margins'] = array(
    '#type' => 'select',
    '#title' => t('Margins'),
    '#options' => array(
      'oa-fullwidth' => t('None (full width)'),
      '' => t('Normal'),
      'oa-fluid' => t('Fluid'),
    ),
    '#default_value' => (isset($style_settings['margins'])) ? $style_settings['margins'] : '',
    '#description' => t('Controls the left/right margins around the panel pane.'),
  );

  return $form;
}
