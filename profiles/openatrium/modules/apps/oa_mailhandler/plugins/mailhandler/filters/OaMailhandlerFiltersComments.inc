<?php
/**
 * @file
 * OaMailhandlerFiltersComments class.
 */

$plugin = array(
  'name' => 'Drupal comments only (not OA Discussion Posts)',
  'handler' => array(
    'class' => 'OaMailhandlerFiltersComments',
    'parent' => 'MailhandlerFilters',
  ),
  'file' => 'OaMailhandlerFiltersComments.class.php',
);
