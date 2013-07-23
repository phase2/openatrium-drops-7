<?php

/**
 * @file
 * Code for the OpenAtrium Core views alterations.
 */


/**
 * Implements hook_views_data_alter
 */
function oa_core_views_data_alter(&$data) {
  if (isset($data['og_membership']['og_group_ref_target_id']['filter']['handler'])) {
    $data['og_membership']['og_group_ref_target_id']['filter']['handler'] = 'oa_core_og_group_ref_views_handler_filter_in_operator';
  }
  if (isset($data['og_membership']['oa_parent_space_target_id']['filter']['handler'])) {
    $data['og_membership']['oa_parent_space_target_id']['filter']['handler'] = 'oa_core_og_group_ref_views_handler_filter_in_operator';
  }
  if (isset($data['field_data_oa_section_ref']['oa_section_ref_target_id']['filter']['handler'])) {
    $data['field_data_oa_section_ref']['oa_section_ref_target_id']['filter']['handler'] = 'oa_core_oa_section_ref_views_handler_filter_in_operator';
  }
}

/**
 * Implements hook_views_plugins().
 */
function oa_core_views_plugins() {
  return array(
    'exposed_form' => array(
      'oa_form' => array(
        'title' => t('Open Atrium'),
        'help' => t('Open Atrium exposed filter form adds some options that integrate with Bootstrap.'),
        'handler' => 'oa_views_plugin_exposed_form',
        'uses options' => TRUE,
      ),
    ),
  );
}
