<?php
/**
 * @file
 * Definition of a responsive region style.
 */

// Plugin path.
$plugin_path = panels_get_path('plugins/styles/oa_responsive_region', FALSE, 'oa_responsive_regions');

// Plugin definition.
$plugin = array(
  'title' => t('OA Responsive Region'),
  'description' => t('Display a region that is responsive.'),
  'render region' => 'oa_responsive_regions_render_region',
  'settings form' => 'oa_responsive_regions_region_settings_form',
  'hook theme' => array(
    'oa_responsive_region' => array(
      'variables' => array('panes' => NULL, 'settings' => NULL),
      'path' => $plugin_path,
      'template' => 'oa-responsive-region',
    ),
  ),
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_oa_responsive_regions_render_region($variables) {
  $panes = $variables['panes'];
  $settings = $variables['settings'];

  return theme('oa_responsive_region', array(
    'panes' => $panes,
    'settings' => $settings,
  ));
}

/**
 * Settings form callback.
 */
function oa_responsive_regions_region_settings_form($style_settings) {
  $positions = _oa_responsive_regions_get_positions();

  $form['position'] = array(
    '#type' => 'select',
    '#title' => t('Position'),
    '#options' => $positions,
    '#default_value' => (isset($style_settings['position'])) ? $style_settings['position'] : '',
  );

  $form['css_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#description' => t('CSS class to apply to this pane. This may be blank.'),
  );

  return $form;
}