<?php
/**
 * @file
 * oa_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_core_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags_alter().
 */
function oa_core_flag_default_flags_alter(&$data) {
  if (isset($data['trash'])) {
    $data['trash']['flag_confirmation'] = 'Are you sure you want to archive this item? You may be unable to access it after archiving.'; /* WAS: 'Are you sure you want to trash this item? You may be unable to access it after trashing.' */
    $data['trash']['flag_long'] = 'Move item to the site archive'; /* WAS: 'Move item to the site trash bin.' */
    $data['trash']['flag_message'] = 'Item has been archived'; /* WAS: 'Item has been trashed' */
    $data['trash']['flag_short'] = 'Archive This'; /* WAS: 'Move to Trash' */
    $data['trash']['show_on_page'] = 0; /* WAS: 1 */
    $data['trash']['title'] = 'Archive'; /* WAS: 'Trash' */
    $data['trash']['unflag_confirmation'] = 'Are you sure you want to remove this item from archive?'; /* WAS: 'Are you sure you want to remove this item from trash?' */
    $data['trash']['unflag_denied_text'] = 'Archived'; /* WAS: 'trashed' */
    $data['trash']['unflag_long'] = 'Unarchive item and restore previous access settings.'; /* WAS: 'Remove from trash item and restore previous access settings.' */
    $data['trash']['unflag_message'] = 'Item removed fromt archive'; /* WAS: 'Item removed from Trash' */
    $data['trash']['unflag_short'] = 'Remove from archive'; /* WAS: 'Remove from Trash' */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function oa_core_views_default_views_alter(&$data) {
  if (isset($data['trash_flag_bin'])) {
    $data['trash_flag_bin']->display['default']->display_options['title'] = 'Archive'; /* WAS: 'Trash Bin' */
    $data['trash_flag_bin']->display['page_1']->display_options['menu']['title'] = 'Archive'; /* WAS: 'Trash Bin' */
    $data['trash_flag_bin']->display['page_1']->display_options['path'] = 'node/%/archive'; /* WAS: 'node/%/trash-bin' */
    $data['trash_flag_bin']->display['page']->display_options['path'] = 'archive'; /* WAS: 'trash-bin' */
  }
}

/**
 * Implements hook_image_default_styles().
 */
function oa_core_image_default_styles() {
  $styles = array();

  // Exported image style: oa_medium_thumbnail.
  $styles['oa_medium_thumbnail'] = array(
    'name' => 'oa_medium_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: oa_small_thumbnail.
  $styles['oa_small_thumbnail'] = array(
    'name' => 'oa_small_thumbnail',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function oa_core_node_info() {
  $items = array(
    'oa_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('A collection of users that exists across all spaces.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_space' => array(
      'name' => t('Space'),
      'base' => 'node_content',
      'description' => t('A collection of content and users (members)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
