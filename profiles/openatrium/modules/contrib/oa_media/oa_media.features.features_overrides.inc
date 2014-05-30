<?php
/**
 * @file
 * oa_media.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_media_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.media_default.display|default|display_options|filters|og_group_ref_target_id"] = array(
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
  );
  $overrides["views_view.media_default.display|default|display_options|filters|oa_section_ref_target_id"] = array(
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
  );
  $overrides["views_view.media_default.display|default|display_options|relationships"] = array(
    'reverse_field_oa_media_node' => array(
      'id' => 'reverse_field_oa_media_node',
      'table' => 'file_managed',
      'field' => 'reverse_field_oa_media_node',
    ),
  );
  $overrides["views_view.media_default.display|media_browser_my_files|display_options|filters|og_group_ref_target_id"] = array(
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
  );
  $overrides["views_view.media_default.display|media_browser_my_files|display_options|filters|oa_section_ref_target_id"] = array(
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
  );
  $overrides["views_view.media_default.display|media_browser_my_files|display_options|relationships|reverse_field_oa_media_node"] = array(
    'id' => 'reverse_field_oa_media_node',
    'table' => 'file_managed',
    'field' => 'reverse_field_oa_media_node',
    'label' => 'field_oa_media_1',
  );

 return $overrides;
}
