<?php
/**
 * @file
 * Definition of the bootstrap well pane style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Open Atrium Pane'),
  'description' => t('Renders the pane for Open Atrium'),
  'render pane' => 'oa_styles_oa_pane_style_render_pane',
  'render region' => 'oa_styles_oa_pane_style_render_region',
  'pane settings form' => 'oa_styles_oa_pane_style_settings_form',
  'hook theme' => array(
    'oa_styles_oa_pane_box' => array(
      'variables' => array('content' => NULL, 'settings' => NULL),
      'path' => drupal_get_path('module', 'oa_styles') . '/plugins/styles/oa_pane',
      'template' => 'oa-styles-oa-pane-box',
    ),
  ),
);


/**
 * Render callback for a single region.
 */
function theme_oa_styles_oa_pane_style_render_region($vars) {
  $sep = '<div class="panel-separator"></div>';
  // add separator to end also because panels ipe js removes the last one
  $output = implode($sep, $vars['panes']) . $sep;

  // Then wrap it in a well
  return theme('oa_styles_oa_pane_box', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Render callback for a single pane.
 */
function theme_oa_styles_oa_pane_style_render_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  if (empty($content->content)) {
    return;
  }

  // Render the pane as normal
  $output = theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));

  $vars['settings']['extra_class'] = 'inner-pane';
  // Then wrap it in a well
  return theme('oa_styles_oa_pane_box', array('content' => $output, 'settings' => $vars['settings']));
}

/**
 * Settings form callback.
 */
function oa_styles_oa_pane_style_settings_form($style_settings) {
  return $form;
}
