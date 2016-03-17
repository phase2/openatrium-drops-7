<?php

/**
 * @file
 *
 * Plugin to provide an argument handler for a raw managed_page
 */

$plugin = array(
  'title' => t("Managed page"),
  // keyword to use for %substitution
  'keyword' => 'page',
  'description' => t('A hidden argument that can be used to get the page content as a context.'),
  'context' => 'panels_everywhere_managed_page_context',
  'no ui' => TRUE,
);

/**
 * Discover if this argument gives us the term we crave.
 */
function panels_everywhere_managed_page_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('managed_page');
  }

  $context = ctools_context_create('managed_page', $arg);
  $context->original_argument = $arg;

  return $context;
}
