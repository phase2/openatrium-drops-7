<?php
// Plugin definition
$plugin = array(
  'title' => t('Atrium Site Layout'),
  'icon' => 'oa-site-layout.png',
  'category' => t('Atrium'),
  'theme' => 'oa_site_layout',
  'regions' => array(
    'traytop' => t('Top Tray'),
    'header' => t('Site Header'),
    'sidebar1' => t('Left Tray'),
    'contentheader' => t('Content Header'),
    'content' => t('Page Content'),
    'contentfooter' => t('Content Footer'),
    'sidebar2' => t('Right Tray'),
    'footer' => t('Site Footer'),
    'traybottom' => t('Bottom Tray'),
  ),
);
