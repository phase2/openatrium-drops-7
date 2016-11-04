<?php
/**
 * @file
 * oa_notifications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_notifications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function oa_notifications_flag_default_flags() {
  $flags = array();
  // Exported flag: "Section Content Subscribe".
  $flags['subscribe_section_content'] = array(
    'entity_type' => 'node',
    'title' => 'Section Content Subscribe',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Follow',
    'flag_long' => 'Follow to receive messages related to this content',
    'flag_message' => 'Following',
    'unflag_short' => 'UnFollow',
    'unflag_long' => 'UnFollow to stop receiving messages about this content',
    'unflag_message' => 'UnFollowed',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'oa_notifications',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
