<?php
/**
 * @file
 * Definition of the bootstrap well pane style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap Well'),
  'description' => t('Renders the panes within a Bootstrap Well'),
  'render pane' => 'oa_styles_well_style_render_pane',
  'render region' => 'oa_styles_well_style_render_region',
  'pane settings form' => 'oa_styles_well_style_settings_form',
  'hook theme' => array(
    'oa_styles_well_box' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'oa_styles') . '/plugins/styles/well',
      'template' => 'oa-styles-well-box',
    ),
  ),
);


/**
 * Render callback for a single region.
 */
function theme_oa_styles_well_style_render_region($vars) {
  $sep = '<div class="panel-separator"></div>';
  // add separator to end also because panels ipe js removes the last one
  $output = implode($sep, $vars['panes']) . $sep;

  // Then wrap it in a well
  return theme('oa_styles_well_box', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Render callback for a single pane.
 */
function theme_oa_styles_well_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  if (empty($content->content)) {
    return;
  }

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));

  // Then wrap it in a well
  return theme('oa_styles_well_box', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Settings form callback.
 */
function oa_styles_well_style_settings_form($style_settings) {
  $form['well_modifier'] = array(
    '#type' => 'select',
    '#title' => t('Well modifier'),
    '#options' => array(
      'well-small' => t('Small'),
      '' => t('Normal'),
      'well-large' => t('Large'),
    ),
    '#default_value' => (isset($style_settings['well_modifier'])) ? $style_settings['well_modifier'] : '',
    '#description' => t('Controls the padding and rounded corners on the Well inset'),
  );

  return $form;
}
