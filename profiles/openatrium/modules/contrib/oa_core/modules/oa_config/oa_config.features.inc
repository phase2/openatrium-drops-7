<?php
/**
 * @file
 * oa_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_filter_default_formats_alter().
 */
function oa_config_filter_default_formats_alter(&$data) {
  if (isset($data['panopoly_wysiwyg_text'])) {
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_border-1']['border'] = 'border'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_border-2']['border-color'] = 'border-color'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_border-2']['border-style'] = 'border-style'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_color']['background-color'] = 'background-color'; /* WAS: 0 */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['valid_elements'] = 'a[!href|target<_blank|title|style|class],
            div[style|class|align<center?justify?left?right],
            br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,
            span[style],p[style|class],
            h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
            img[!src|title|alt|style|width|height|class|hspace|vspace],
            @[style|class],
            table[style|class],th[style|class],tr[style|class],td[style|class],tbody[style|class]'; /* WAS: 'a[!href|target<_blank|title|style|class],
    div[style|class|align<center?justify?left?right],
    br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,
    span[style],p[style|class],
    h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
    img[!src|title|alt|style|width|height|class|hspace|vspace],
    @[style|class]' */
  }
}

/**
 * Implements hook_wysiwyg_default_profiles_alter().
 */
function oa_config_wysiwyg_default_profiles_alter(&$data) {
  if (isset($data['panopoly_wysiwyg_text'])) {
    $data['panopoly_wysiwyg_text']['settings']['buttons']['table'] = array(
      'tablecontrols' => 1,
    ); /* WAS: '' */
  }
}
