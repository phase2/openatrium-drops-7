<?php
/**
 * @file
 * Theme and preprocess functions for related paragraph forms.
 */

/**
 * Implements hook_preprocess_paragraphs_field_multiple_value_form().
 */
function oa_related_preprocess_paragraphs_field_multiple_value_form(&$vars) {

  // Set the title.
  $vars['element']['#title'] = '';

  $children = !empty($vars['element']['add_more']) ? element_children($vars['element']['add_more']) : array();
  if (!empty($children)) {
    foreach ($children as $bundle) {
      $machine_name = str_replace(PARAGRAPH_ADD_MORE_BUNDLE, '', $bundle);
      // Allow modules the ability to define their own icons and titles for
      // paragraph add-more submit buttons. If a title is not defined we are
      // just using the #value that comes from the default input button.
      // $info should be an array containing 'icon' and 'title'. The 'title' is
      // optional.
      $info = module_invoke_all('oa_related_icons', $machine_name);
      if (!empty($info)) {
        // Changes the #value to an icon and sets the 'title' to the old #value.
        // We are using unicode since this is an <input>.
        $vars['element']['add_more'][$bundle]['#attributes']['title'][] = isset($info['title']) ? $info['title'] : $vars['element']['add_more'][$bundle]['#value'];
        if (isset($info['icon'])) {
          $vars['element']['add_more'][$bundle]['#value'] = $info['icon'];
          $vars['element']['add_more'][$bundle]['#attributes']['class'][] = 'paragraphs-add-mode-button';
        }
        $vars['element']['#title'] = isset($info['element_title']) ? $info['element_title'] : '';
      }
    }
  }
}

/**
 * Implements hook_preprocess_oa_related_paragraphs_paragraph_content_form().
 */
function oa_related_preprocess_oa_related_paragraphs_paragraph_content_form(&$vars) {
  $element = $vars['element'];
  $vars['title'] = drupal_render($element['paragraph_bundle_title']);
  $vars['related_content'] = drupal_render($element['field_oa_related_content']);
  $vars['layout'] = drupal_render($element['field_oa_content_layout']);
  oa_related_remove_paragraph_icon($element);
  $vars['action_links'] = drupal_render($element['actions']);
}

/**
 * Implements hook_preprocess_oa_related_paragraphs_paragraph_media_form().
 */
function oa_related_preprocess_oa_related_paragraphs_paragraph_media_form(&$vars) {
  $element = $vars['element'];
  $vars['title'] = drupal_render($element['paragraph_bundle_title']);
  $vars['layout'] = drupal_render($element['field_image_alignment']);
  oa_related_remove_paragraph_icon($element);
  $vars['action_links'] = drupal_render($element['actions']);
  $vars['media_widget'] = drupal_render($element['field_oa_media']);
}

/**
 * Implements hook_preprocess_oa_related_paragraphs_paragraph_snippet_form().
 */
function oa_related_preprocess_oa_related_paragraphs_paragraph_snippet_form(&$vars) {
  $element = $vars['element'];
  $vars['title'] = drupal_render($element['paragraph_bundle_title']);
  $vars['content'] = drupal_render($element['field_snippet_content']);
  $vars['view_mode'] = drupal_render($element['field_snippet_viewmode']);
  $vars['layout'] = drupal_render($element['field_paragraph_layout']);
  $vars['lock_revision'] = drupal_render($element['field_paragraph_lock_revision']);
  $vars['show_title'] = drupal_render($element['field_snippet_showtitle']);
  $vars['title_override'] = drupal_render($element['field_snippet_title_override']);
  oa_related_remove_paragraph_icon($element);
  $vars['action_links'] = drupal_render($element['actions']);
}

/**
 * Implements hook_preprocess_oa_related_paragraphs_paragraph_text_form().
 */
function oa_related_preprocess_oa_related_paragraphs_paragraph_text_form(&$vars) {
  $element = $vars['element'];
  $vars['title'] = drupal_render($element['paragraph_bundle_title']);
  $vars['text'] = drupal_render($element['field_paragraph_text']);
  $vars['layout'] = drupal_render($element['field_paragraph_layout']);
  oa_related_remove_paragraph_icon($element);
  $vars['action_links'] = drupal_render($element['actions']);
}

/**
 * Change the remove paragraph button to an icon.
 *
 * @param array $element
 *   The current element that contains the actions.
 */
function oa_related_remove_paragraph_icon(&$element) {
  $element['actions']['remove_button']['#attributes']['class'][] = 'oa-related-trash';
  $element['actions']['remove_button']['#attributes']['title'][] = $element['actions']['remove_button']['#value'];
  $element['actions']['remove_button']['#value'] = decode_entities('&#xf014;');
}
