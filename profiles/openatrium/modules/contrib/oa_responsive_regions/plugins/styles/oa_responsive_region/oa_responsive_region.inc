<?php
/**
 * @file
 * Definition of a responsive region style.
 */

// Plugin path.
$plugin_path = panels_get_path('plugins/styles/oa_responsive_region', FALSE, 'oa_responsive_regions');

// Plugin definition.
$plugin = array(
  'title' => t('Responsive Tray'),
  'description' => t('Display a region that collapses into a tray on the edge of the screen.'),
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

  $output = theme('oa_responsive_region', array('panes' => $panes, 'settings' => $settings));
  if ($settings['fixed'] && $settings['expand_always']) {
    // When using a fixed top toolbar, duplicate the toolbar with a hidden version to handle the body offset
    // See http://codepen.io/parkerbennett/pen/hbzJm for Fixed Header Design Pattern
    $settings['hidden'] = TRUE;
    $output .= theme('oa_responsive_region', array('panes' => $panes, 'settings' => $settings));
  }
  return $output;
}

/**
 * Implements HOOK_preprocess_THEME().
 * @param $vars
 */
function template_preprocess_oa_responsive_region(&$vars) {
  $settings = $vars['settings'];
  if (!empty($settings['hidden'])) {
    // remove oa-responsive-region class from hidden div
    unset($vars['classes_array'][0]);
    $vars['classes_array'][] = drupal_html_class('oa-hidden');
  }
  else {
    $class = ($settings['mobile_only']) ? 'oa-responsive-mobile' : 'oa-responsive-desktop';
    $vars['classes_array'][] = drupal_html_class($class);
    $class = in_array($settings['position'], array('center', 'fluid')) ? 'oa-responsive-primary' : 'oa-responsive-region-' . $vars['settings']['position'];
    $vars['classes_array'][] = drupal_html_class($class);
    if ($settings['position'] == 'fluid') {
      $vars['classes_array'][] = drupal_html_class('oa-responsive-fluid');
    }
    if ($settings['fixed']) {
      $vars['classes_array'][] = drupal_html_class('oa-responsive-fixed');
    }
    if ($settings['expand_always']) {
      $vars['classes_array'][] = drupal_html_class('oa-responsive-expand');
    }
  }
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
    '#default_value' => isset($style_settings['position']) ? $style_settings['position'] : '',
  );

  $form['fixed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fixed'),
    '#description' => t('Enable this to fix toolbar to top/bottom of page'),
    '#default_value' => isset($style_settings['fixed']) ? $style_settings['fixed'] : FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="position"]' => array(
          array('value' => 'top'),
          array('value' => 'bottom'),
        ),
      ),
    ),
  );

  $form['mobile_only'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mobile only'),
    '#description' => t('Enable if tray is only hidden on small screens, otherwise tray is always hidden.'),
    '#default_value' => isset($style_settings['mobile_only']) ? $style_settings['mobile_only'] : FALSE,
  );

  $form['expand_always'] = array(
    '#type' => 'checkbox',
    '#title' => t('Expand always'),
    '#description' => t('Always show the tray as expanded.'),
    '#default_value' => isset($style_settings['expand_always']) ? $style_settings['expand_always'] : FALSE,
  );

  $form['css_classes'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS class'),
    '#description' => t('CSS class to apply to this pane. This may be blank.'),
    '#default_value' => isset($style_settings['css_classes']) ? $style_settings['css_classes'] : '',
  );

  return $form;
}


