<?php
/**
 * @file
 * oa_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_media_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function oa_media_views_default_views_alter(&$data) {
  if (isset($data['media_default'])) {
    $data['media_default']->display['default']->display_options['filters']['og_group_ref_target_id'] = array(
      'id' => 'og_group_ref_target_id',
      'table' => 'og_membership',
      'field' => 'og_group_ref_target_id',
      'relationship' => 'reverse_field_oa_media_node',
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'og_group_ref_target_id_op',
        'label' => 'Space',
        'operator' => 'og_group_ref_target_id_op',
        'identifier' => 'og_group_ref_target_id',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
    ); /* WAS: '' */
    $data['media_default']->display['default']->display_options['filters']['oa_section_ref_target_id'] = array(
      'id' => 'oa_section_ref_target_id',
      'table' => 'field_data_oa_section_ref',
      'field' => 'oa_section_ref_target_id',
      'relationship' => 'reverse_field_oa_media_node',
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'oa_section_ref_target_id_op',
        'label' => 'Section',
        'operator' => 'oa_section_ref_target_id_op',
        'identifier' => 'oa_section_ref_target_id',
      ),
    ); /* WAS: '' */
    $data['media_default']->display['default']->display_options['relationships'] = array(
      'reverse_field_oa_media_node' => array(
        'id' => 'reverse_field_oa_media_node',
        'table' => 'file_managed',
        'field' => 'reverse_field_oa_media_node',
      ),
    ); /* WAS: '' */
    $data['media_default']->display['media_browser_my_files']->display_options['filters']['og_group_ref_target_id'] = array(
      'id' => 'og_group_ref_target_id',
      'table' => 'og_membership',
      'field' => 'og_group_ref_target_id',
      'relationship' => 'reverse_field_oa_media_node',
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'og_group_ref_target_id_op',
        'label' => 'Space',
        'operator' => 'og_group_ref_target_id_op',
        'identifier' => 'og_group_ref_target_id',
        'remember_roles' => array(
          2 => 2,
          1 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
    ); /* WAS: '' */
    $data['media_default']->display['media_browser_my_files']->display_options['filters']['oa_section_ref_target_id'] = array(
      'id' => 'oa_section_ref_target_id',
      'table' => 'field_data_oa_section_ref',
      'field' => 'oa_section_ref_target_id',
      'relationship' => 'reverse_field_oa_media_node',
      'exposed' => TRUE,
      'expose' => array(
        'operator_id' => 'oa_section_ref_target_id_op',
        'label' => 'Section',
        'operator' => 'oa_section_ref_target_id_op',
        'identifier' => 'oa_section_ref_target_id',
      ),
    ); /* WAS: '' */
    $data['media_default']->display['media_browser_my_files']->display_options['relationships']['reverse_field_oa_media_node'] = array(
      'id' => 'reverse_field_oa_media_node',
      'table' => 'file_managed',
      'field' => 'reverse_field_oa_media_node',
      'label' => 'field_oa_media_1',
    ); /* WAS: '' */
  }
}
