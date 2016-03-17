<?php

/**
 * @file
 * Plugin to handle the 'page' content type which allows the standard page
 * template variables to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Page messages'),
  'single' => TRUE,
  'icon' => 'icon_page.png',
  'description' => t('A general page messages block that includes tabs, messages and help. It is normally placed in the same region as your content. This can be easily modified by overriding pane-messages.tpl.php in your theme.'),
  'category' => t('Page elements'),
  'render last' => TRUE,
);

/**
 * Output function for the 'pane_tabs' content type.
 *
 * Outputs the tabs (local tasks) of the current page.
 */
function panels_everywhere_pane_messages_content_type_render($subtype, $conf, $panel_messagesrgs) {
  $block = new stdClass();
  $block->content = theme('pane_messages');
  return $block;
}

function panels_everywhere_pane_messages_content_type_admin_info($subtype, $conf) {
  $block = new stdClass;
  $block->title = t('Page messages, tabs and help');
  $block->content = t('A general page messages block that includes tabs, messages and help. It is normally placed in the same region as your content. This can be easily modified by overriding pane-messages.tpl.php in your theme.');
  return $block;
}
