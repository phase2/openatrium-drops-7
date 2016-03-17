<?php

/**
 * @file
 * Plugin to handle the 'page_content' content type which allows the
 * mission statement of the site to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Page content'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('Page content that is available if the panel is being used to wrap content with the Panels Everywhere module.'),
  'category' => t('Page elements'),
  'required context' => new ctools_context_required(t('Page content'), 'page_content'),
);

/**
 * Output function for the 'page_content' content type.
 *
 * Outputs the mission statement for the site.
 */
function panels_everywhere_page_content_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  if (is_string($context->data)) {
    $block = new stdClass();
    $block->title = t('Dummy content');
    $block->content = $context->data;
    return $block;
  }

  return $context->data;
}

/**
 * Returns an edit form for custom type settings.
 */
function panels_everywhere_page_content_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}

function panels_everywhere_page_content_content_type_admin_info($subtype, $conf, $context) {
  $block = new StdClass;
  $block->title = t('Main page content');
  $block->content = t('This will contain the content of page being viewed. In order to get the page title to be used as a Panel title, it is recommended that you set the "Title type" to "From pane" and then check "Panel title" in the dropdown menu for this pane.');
  return $block;
}
