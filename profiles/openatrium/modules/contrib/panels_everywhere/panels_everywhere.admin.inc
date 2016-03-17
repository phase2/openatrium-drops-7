<?php

/**
 * @file
 * Contains administrative pages for the Panels Everywhere module.
 */

function panels_everywhere_settings_page() {
  ctools_include('dependent');

  $form = array();

  $form['panels_everywhere_site_template_enabled'] = array(
    '#title' => t('Enable Panels Everywhere site template'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('panels_everywhere_site_template_enabled', FALSE),
    '#description' => t('This will enable a page in the page manager pages list that allows you to "wrap" any page in a panels display. You may use variants on that page to check site data such as the URL and apply wrappers selectively.'),
  );

  $form['panels_everywhere_provide_sample'] = array(
    '#title' => t('Provide a sample variant for the site template'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('panels_everywhere_provide_sample', FALSE),
    '#description' => t('If checked, the site template in the page administration will come with a sample variant pre-created with the minimal options, to help get you started faster. It is recommended you use this on a new installation, and once you are comfortable with Panels Everywhere, you can turn this off again to get it out of the way.'),
    '#dependency' => array(
      'edit-panels-everywhere-site-template-enabled' => array(1),
    ),
  );

  $form['panels_everywhere_site_template_per_theme'] = array(
    '#title' => t('Enable Panels Everywhere site template on a per-theme basis'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('panels_everywhere_site_template_per_theme', FALSE),
    '#description' => t('This setting lets you choose which themes are overridden by Panels Everywhere.'),
    '#dependency' => array(
      'edit-panels-everywhere-site-template-enabled' => array(1),
    ),
  );

  $form['panels_everywhere_site_template_enabled_admin'] = array(
    '#title' => t('Enable Panels Everywhere site template for the admin theme'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('panels_everywhere_site_template_enabled_admin', FALSE),
    '#description' => t('This will also enable the site template for your admin theme. Note that if your admin theme is the same as your site theme, the site_template will be used regardless of this setting. If you do not wish to use the site_template with your admin theme, you must select a different admin theme at administer >> site configuration >> administration theme.'),
    '#dependency' => array(
      'edit-panels-everywhere-site-template-per-theme' => array(0),
      'edit-panels-everywhere-site-template-enabled' => array(1),
    ),
    '#dependency_count' => 2,
  );

  foreach (list_themes() as $theme) {
    if (empty($theme->info['hidden'])) {
      $form['panels_everywhere_override_theme_' . $theme->name] = array(
        '#type' => 'checkbox',
        '#title' => t($theme->info['name']),
        '#default_value' => variable_get('panels_everywhere_override_theme_' . $theme->name, FALSE),
        '#dependency' => array(
          'edit-panels-everywhere-site-template-enabled' => array(1),
          'edit-panels-everywhere-site-template-per-theme' => array(1),
        ),
        '#dependency_count' => 2,
      );
    }
  }

  $form['head_title'] = array(
    '#type' => 'fieldset',
    '#title' => t('Head title'),
    '#description' => t('The head title is the version of the page title that the browser places in the title bar.'),
    '#dependency' => array(
      'edit-panels-everywhere-site-template-enabled' => array(1),
    ),
  );

  $form['head_title']['panels_everywhere_head_title_include_name'] = array(
    '#title' => t('Include the site name'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('panels_everywhere_head_title_include_name', TRUE),
  );

  $form['head_title']['panels_everywhere_head_title_include_slogan'] = array(
    '#title' => t('Use site slogan if the page title is blank'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('panels_everywhere_head_title_include_slogan', TRUE),
  );

  $form['head_title']['panels_everywhere_head_title_separator'] = array(
    '#title' => t('Separator'),
    '#type' => 'textfield',
    '#default_value' => variable_get('panels_everywhere_head_title_separator', ' | '),
  );

  return system_settings_form($form);
}
