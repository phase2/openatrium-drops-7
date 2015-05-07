<?php
/**
 * @file
 * oa_appearance.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_appearance_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function oa_appearance_image_default_styles() {
  $styles = array();

  // Exported image style: oa_banner.
  $styles['oa_banner'] = array(
    'label' => 'oa_banner',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => 200,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
