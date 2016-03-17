<?php
/**
 * @file
 * Used to define information for specific fields on paragraph entities. For now these fields are of the 'Widget type'
 * => 'Select list'.
 *
 * You can implement hook_oa_related_field_info() in your module to add values to fields on paragraph items.
 * You can also modify it by calling hook_oa_related_field_info_alter(). This is helpful if you would like to
 * alter one of the elements in the array such as the 'render callback'.
 *
 * @code
 *   function hook_oa_related_field_info() {
 *     return array(
 *       array(
 *         'key' => The key of the allowed value,
 *         'value' => The value of the allowed value,
 *         'bundle' => The paragraph bundle this field is used on,
 *         'field name' => (optional) Use if the paragraph bundle has more than one field that needs pre-processing,
 *         'render callback' => The function used to preprocess variables for the template,
 *       ),
 *     );
 *   }
 * @endcode
 *
 * or
 *
 * @code
 *   function hook_oa_related_field_info_alter(&$info, $bundle) {
 *     if($bundle == 'paragraph_media') {
 *       foreach($info as $data) {
 *         if ($info['key'] == 'center') {
 *           $info['value'] = 'Center Image';
 *           $info['render callback'] = 'my_function_to_center_the_image';
 *         }
 *       }
 *     }
 *   }
 * @endcode
 *
 * @see oa_related_paragraphs_field_allowed_values().
 */

function oa_related_oa_related_field_info() {
    $info = array(
      'field_image_alignment' => array(
        'paragraph_media' => array(
          'render callback' => 'oa_related_oa_paragraph_media_render',
          'allowed values' => array(
            'left' => 'Align Left',
            'right' => 'Align Right',
            'center' => 'Center',
            'full' => 'Full Width',
            'grid2' => '2 Columns',
            'grid3' => '3 Columns',
            'grid4' => '4 Columns',
            'grid5' => '5 Columns',
            'preview' => 'Preview Listing',
            'table' => 'Media File Table',
          ),
        ),
      ),
      'field_oa_content_layout' => array(
        'paragraph_content' => array(
          'render callback' => 'oa_related_oa_paragraph_content_render',
          'allowed values' => array(
            'table' => 'Table of Files',
            'preview' => 'Preview Listing',
            'full' => 'Full Content',
            'list' => 'Simple Listing',
          ),
        ),
      ),
      'field_paragraph_layout' => array(
        'paragraph_text' => array(
          'render callback' => 'oa_related_oa_paragraph_text_render',
          'allowed values' => array(
            '2' => '2 Columns',
            '3' => '3 Columns',
            '4' => '4 Columns',
            'full' => 'Callout',
            'left' => 'Callout Left',
            'right' => 'Callout Right',
          ),
        ),
        'paragraph_snippet' => array(
          'render callback' => 'oa_related_oa_paragraph_snippet_render',
          'allowed values' => array(
            '2' => '2 Columns',
            '3' => '3 Columns',
            '4' => '4 Columns',
            'full' => 'Callout',
            'left' => 'Callout Left',
            'right' => 'Callout Right',
          ),
        ),
      ),
      'field_snippet_viewmode' => array(
        'paragraph_snippet' => array(
          'allowed values' => array(
            'summary' => 'Summary',
            'normal' => 'Just Body',
            'full' => 'Body and Paragraphs',
          ),
        ),
      ),
  );

  return $info;
}
