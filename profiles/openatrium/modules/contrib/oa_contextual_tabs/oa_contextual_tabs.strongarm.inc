<?php
/**
 * @file
 * oa_contextual_tabs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_contextual_tabs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'contextual_tabs_extract';
  $strongarm->value = 'user*:Edit|Edit profile,icon-pencil
node/*/clone/confirm:View|Cancel,icon-remove
node/*/edit:View|Cancel,icon-remove
View
Edit,icon-pencil
Members,icon-user';
  $export['contextual_tabs_extract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'contextual_tabs_pages';
  $strongarm->value = 'admin*';
  $export['contextual_tabs_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'contextual_tabs_visilibity';
  $strongarm->value = 1;
  $export['contextual_tabs_visilibity'] = $strongarm;

  return $export;
}
