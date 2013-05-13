<?php
/**
 * @file
 * OaMailParser feeds plugin definition.
 */

$plugin = array(
  'name' => 'Open Atrium IMAP stream parser',
  'description' => 'Parses an IMAP stream, adds a few OA-specific fields.',
  'handler' => array(
    'parent' => 'MailhandlerParser',
    'class' => 'OaMailParser',
  ),
);
