<?php

$plugin = array(
  'title' => t('Daily Message Digest'),
  'description' => t('Send Message via daily digest.'),
  'class' => 'MessageDigestDay',
  'view_modes' => array(
    'message_notify_daily_digest' => array('label' => t('Notify - Daily digest')),
  ),
);
