<?php

/**
 * @file
 *
 * Plugin to provide a page_content context
 */

$plugin = array(
  'title' => t('Page content'),
  'description' => t('The page content.'),
  'context' => 'panels_everywhere_context_create_page_content',
  'keyword' => 'page_content',
  'no ui' => TRUE,
  'context name' => 'page_content',
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function panels_everywhere_context_create_page_content($empty, $data = NULL, $conf = FALSE) {
  // The input is expected to be an object containing 'title' and 'content'.

  $context = new ctools_context('page_content');
  $context->plugin = 'page_content';

  if ($empty) {
    return $context;
  }

  if ($data !== FALSE ) {
    $context->data = $data;
    $context->title = t('Page content');
    return $context;
  }
}
