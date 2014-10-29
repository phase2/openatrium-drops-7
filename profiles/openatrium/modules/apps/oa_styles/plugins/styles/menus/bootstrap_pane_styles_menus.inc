<?php
/**
 * @file
 * Definition of the bootstrap well pane style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap Menu Styles'),
  'description' => t('Renders a menu pane using bootstrap components.'),
  'render pane' => 'bootstrap_pane_styles_menus_style_render_pane',
  'pane settings form' => 'bootstrap_pane_styles_menus_style_settings_form',
  'hook theme' => array(
    'bootstrap_pane_styles_menu_tree' => array(
      'render element' => 'tree',
      'path' => drupal_get_path('module', 'bootstrap_pane_styles') . '/plugins/styles/menus',
    ),
    'bootstrap_pane_styles_btn_toolbar' => array(
      'render element' => 'tree',
      'path' => drupal_get_path('module', 'bootstrap_pane_styles') . '/plugins/styles/menus',
    ),
    'bootstrap_pane_styles_btn_group' => array(
      'render element' => 'tree',
      'path' => drupal_get_path('module', 'bootstrap_pane_styles') . '/plugins/styles/menus',
    ),
    'bootstrap_pane_styles_btn_link' => array(
      'render element' => 'element',
      'path' => drupal_get_path('module', 'bootstrap_pane_styles') . '/plugins/styles/menus',
    ),
    'bootstrap_pane_styles_btn_link_dropdown' => array(
      'render element' => 'element',
      'path' => drupal_get_path('module', 'bootstrap_pane_styles') . '/plugins/styles/menus',
    ),
    'bootstrap_pane_styles_menu_dropdown' => array(
      'render element' => 'tree',
      'path' => drupal_get_path('module', 'bootstrap_pane_styles') . '/plugins/styles/menus',
    ),
  ),
);

/**
 * Render callback for menu_tree
 */
function theme_bootstrap_pane_styles_menu_tree($vars) {
  $vars['tree']['#attributes']['class'] .= ' nav';
  return '<ul ' . drupal_attributes($vars['tree']['#attributes']) . '> ' . $vars['tree']['#children'] . '</ul>';
}

/**
 * Render callback for btn group
 */
function theme_bootstrap_pane_styles_btn_group($vars) {
  $vars['tree']['#attributes']['class'] .= ' btn-group';
  $group = '<div ' . drupal_attributes($vars['tree']['#attributes']) . '>' . $vars['tree']['#children'] . '</div>';
  if (!empty($vars['tree']['#bootstrap_stacked'])) {
    $group = '<div>' . $group . '</div>';
  }
  return $group;
}

/**
 * Render callback for btn group
 */
function theme_bootstrap_pane_styles_btn_toolbar($vars) {
  return '<div class="btn-toolbar">' . $vars['tree']['#children'] . '</div>';
}


/**
 * Render callback for btn link
 */
function theme_bootstrap_pane_styles_btn_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $element['#localized_options']['attributes']['class'][] = 'btn';
  if (!empty($element['#bootstrap_inverse'])) {
    $element['#localized_options']['attributes']['class'][] = 'btn-inverse';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return $output . $sub_menu;
}

/**
 * Render callback for btn link
 */
function theme_bootstrap_pane_styles_btn_link_dropdown($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = '<a class="dropdown-toggle btn ' . (!empty($element['#bootstrap_inverse']) ? 'btn-inverse' : '') . '" data-toggle="dropdown" href="#"><b class="caret"></b></a>';
    $sub_menu .= drupal_render($element['#below']);
  }
  $element['#localized_options']['attributes']['class'][] = 'btn';
  if (!empty($element['#bootstrap_inverse'])) {
    $element['#localized_options']['attributes']['class'][] = 'btn-inverse';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return $output . $sub_menu;
}

/**
 * Render callback for menu_tree
 */
function theme_bootstrap_pane_styles_menu_dropdown($vars) {
  return '<ul class="dropdown-menu">' . $vars['tree']['#children'] . '</ul>';
}
/**
 * Render callback for a single pane.
 */
function theme_bootstrap_pane_styles_menus_style_render_pane($vars) {
  $style = !empty($vars['settings']['nav_style']) ? $vars['settings']['nav_style'] :  'nav-tabs';
  $ul_classes = 'nav ' . check_plain($style) . ' ' . (!empty($vars['settings']['stacked']) ? 'nav-stacked' : '');
  $inverse = !empty($vars['settings']['inverse']);
  $content = &$vars['content']->content;
  $is_button_style = strpos($style, 'button') === 0;
  $wrapper_theme = '';
  if (!empty($vars['settings']['wrapper'])) {
      module_load_include('inc', 'panels', 'includes/plugins');
    $styles = panels_get_styles();
    $wrapper_theme = !empty($styles[$vars['settings']['wrapper']]['render pane']) ? $styles[$vars['settings']['wrapper']]['render pane'] : FALSE;
  }
  if (empty($content) || is_string($content)) {
    // This is hacky, but likely better than parsing it xml and moving it around.
    // Views etc. renders it's output still.
    if ($content && is_string($content)) {
      if (preg_match('/<ul\b[^><]*/', $content)) {
        $content = preg_replace_callback('/<ul\b[^><]*/', function ($match) use ($ul_classes, $style, $vars, $is_button_style) {
          if ($is_button_style) {
            return '<div class="btn-toolbar"';
          }
          else {
            return $match[0] . ' class="' . $ul_classes . '" ';
          }
        },
        $content, 1);
        if ($is_button_style) {
          if (empty($vars['settings']['stacked'])) {
            $content = preg_replace('/<li\b[^><]*/', '<div class="btn-group"', $content);
            $content = str_replace('</li', '</div', $content);
          }
          else {
            $content = preg_replace('/<li\b[^><]*/', '<div><div class="btn-group"', $content);
            $content = str_replace('</li', '</div></div', $content);
          }
          $content = str_replace('<a', '<a class="btn ' . (!empty($vars['settings']['inverse']) ? ' btn-inverse' : '') . '"', $content);
          $content =  str_replace('</ul', '</div', $content);
        }
      }
    }
    return $content && $wrapper_theme ? theme($wrapper_theme, $vars) : $content;
  }
  if (!empty($content['#content']) && is_array($content['#content'])) {
    $content = $content['#content'];
  }

  foreach (element_children($content) as $child_key) {
    $is_menu_link = FALSE;
    if (!empty($content[$child_key]['#theme'])) {
      if (is_array($content[$child_key]['#theme']) && in_array('menu_link', $content[$child_key]['#theme'])) {
        $is_menu_link = TRUE;
      }
      elseif (is_string($content[$child_key]['#theme']) && strpos($content[$child_key]['#theme'], 'menu_link') === 0) {
        $is_menu_link = TRUE;
      }
    }
    // Skip if this is something unknown.
    if (!$is_menu_link) {
      continue;
    }
    // Change child elements to drop downs.
    $content[$child_key]['#bootstrap_inverse'] = $inverse;
    $content[$child_key]['#bootstrap_stacked'] = !empty($vars['settings']['stacked']);
    if (!empty($content[$child_key]['#below'])) {
      $menu_link = $content[$child_key];
      $menu_link['#below'] = array();
      // Make parent link into title (dropdown style provides own toggle).
      if ($style != 'button_dropdown') {
        $content[$child_key]['#attributes']['class'][] = 'dropdown';
        $content[$child_key]['#localized_options']['attributes']['data-toggle'] = 'dropdown';
        $content[$child_key]['#localized_options']['attributes']['data-target'] = '#';
        $content[$child_key]['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
        $content[$child_key]['#below'] = array($child_key => $menu_link) + $content[$child_key]['#below'];
      }
      $content[$child_key]['#below']['#theme_wrappers'] = array('bootstrap_pane_styles_menu_dropdown');
    }
    // Determine if this element
    // Replace menu links with button link.
    if ($style == 'button') {
      $content[$child_key]['#theme'] = 'bootstrap_pane_styles_btn_link';
    }
    elseif ($style == 'button_dropdown') {
      $content[$child_key]['#theme'] = 'bootstrap_pane_styles_btn_link_dropdown';
    }
    // Wrap each button in button group for now. @todo add setting to determine this?
    if (strpos($style, 'button') === 0) {
      $content[$child_key]['#theme_wrappers'] = array('bootstrap_pane_styles_btn_group');
    }
  }
  $attributes = array('class' => '');
  if (!empty($vars['content']->css_id)) {
    $attributes['id'] = $vars['content']->css_id;
  }
  if (!empty($vars['content']->css_class)) {
    $attributes['class'] = $vars['content']->css_class;
  }
  if ($is_button_style) {
    $content['#theme_wrappers'] = array('bootstrap_pane_styles_btn_toolbar');
  }
  else {
    $content['#theme_wrappers'] = array('bootstrap_pane_styles_menu_tree');
    $attributes['class'] .= $ul_classes;
  }
  $content['#attributes'] = $attributes;
  // Render the pane as normal
  $content = drupal_render($content);
  return $content && $wrapper_theme ? theme($wrapper_theme, $vars) : $content;
}

/**
 * Settings form callback.
 */
function bootstrap_pane_styles_menus_style_settings_form($style_settings) {
  $form['nav_style'] = array(
    '#type' => 'select',
    '#title' => t('Style'),
    '#options' => array(
      'nav-tabs' => t('Tabs'),
      'nav-pills' => t('Pills'),
      'button' => t('Buttons'),
      'button_dropdown' => t('Split Button Dropdowns'),
    ),
    '#default_value' => (isset($style_settings['nav_style'])) ? $style_settings['nav_style'] : '',
    '#description' => t('Controls the padding and rounded corners on the Well inset'),
  );

  $form['stacked'] = array(
    '#type' => 'checkbox',
    '#title' => t('Stacked'),
    '#default_value' => (isset($style_settings['stacked'])) ? $style_settings['stacked'] : FALSE,
    '#description' => t('Appear horizontally (not stacked) or vertically (stacked)'),
  );

  $form['inverse'] = array(
    '#type' => 'checkbox',
    '#title' => t('Inversed'),
    '#default_value' => (isset($style_settings['inverse'])) ? $style_settings['inverse'] : FALSE,
    '#description' => t('Use inverse styles if avialable'),
  );

  module_load_include('inc', 'panels', 'includes/plugins');
  $styles = panels_get_styles();
  $options = array();
  $options[0] = t('<None>');

  uasort($styles, 'ctools_plugin_sort');

  foreach ($styles as $id => $info) {
    if (empty($info['hidden']) && !empty($info['render pane']) && $id != 'bootstrap_pane_styles_menus' && $id != 'naked') {
      $options[$id] = check_plain($info['title']);
    }
  }

  $form['wrapper'] = array(
    '#type' => 'select',
    '#title' => t('Wrapper style'),
    '#description' => t('Title will not displayed if a wrapper style is not picked.'),
    '#options' => $options,
    '#default_value' => isset($style_settings['wrapper']) ? $style_settings['wrapper'] : 0,
  );

  return $form;
}
