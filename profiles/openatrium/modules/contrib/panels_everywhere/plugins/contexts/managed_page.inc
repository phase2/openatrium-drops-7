<?php

/**
 * @file
 *
 * Plugin to provide a managed_page context
 */

$plugin = array(
  'title' => t('Managed page'),
  'description' => t('A page manager page.'),
  'context' => 'panels_everywhere_context_create_managed_page',
  'keyword' => 'managed_page',
  'no ui' => TRUE,
  'context name' => 'managed_page',
);

/**
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function panels_everywhere_context_create_managed_page($empty, $data = NULL, $conf = FALSE) {
  // The input is expected to be an object containing 'title' and 'content'.

  $context = new ctools_context('managed_page');
  $context->plugin = 'managed_page';

  if ($empty) {
    return $context;
  }

  if ($data !== FALSE ) {
    $context->data = $data;
    $context->title = t('Managed page');
    return $context;
  }
}
