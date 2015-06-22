<?php

/**
 * @file
 * Hook implementations for the Variable module.
 */

/**
 * Implements hook_variable_info().
 */
function oa_layouts_variable_info($options) {
  $variable = array();
  $variable['oa_layouts_minipanel_header'] = array(
    'type' => 'string',
    'title' => t('Minipanel for Header'),
    'default' => 'oa_toolbar_panel',
    'description' => t("The machine name used for the page header mini panel."),
    'group' => 'oa_layouts',
  );
  $variable['oa_layouts_minipanel_footer'] = array(
    'type' => 'string',
    'title' => t('Minipanel for Footer'),
    'default' => 'oa_footer_panel',
    'description' => t("The machine name used for the page footer mini panel."),
    'group' => 'oa_layouts',
  );
  return $variable;
}

/**
 * Implements hook_variable_group_info().
 */
function oa_layouts_variable_group_info() {
  $groups = array();
  $groups['oa_layouts'] = array(
    'title' => t('Layout settings'),
    'description' => t('Settings for Open Atrium Layouts'),
    'access' => 'administer mini panels',
  );
  return $groups;
}
