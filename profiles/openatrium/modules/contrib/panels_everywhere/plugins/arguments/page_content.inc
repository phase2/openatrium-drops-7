<?php

/**
 * @file
 *
 * Plugin to provide an argument handler for a raw page_content
 */

$plugin = array(
  'title' => t("Page content"),
  // keyword to use for %substitution
  'keyword' => 'page_content',
  'description' => t('A hidden argument that can be used to get the page content as a context.'),
  'context' => 'panels_everywhere_page_content_context',
  'placeholder form' => array(
    '#type' => 'fieldset',
    'title' => array(
      '#title' => t('Page title'),
      '#type' => 'textfield',
      '#default_value' => t('Dummy page title'),
    ),
    'content' => array(
      '#title' => t('Page content'),
      '#type' => 'textarea',
      '#default_value' => '<p>' . t('Dummy page content') . '</p>',
    ),
  ),
  'no ui' => TRUE,
);

/**
 * Discover if this argument gives us the term we crave.
 */
function panels_everywhere_page_content_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('page_content');
  }

  if (is_array($arg)) {
    $arg = (object) $arg;
  }

  $context = ctools_context_create('page_content', $arg);
  $context->original_argument = $arg;

  return $context;
}
