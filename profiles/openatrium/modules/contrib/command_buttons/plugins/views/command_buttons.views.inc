<?php

/**
 * @file
 * Provides views integration for Open Atrium Buttons.
 */

/**
 * Implements hook_views_data().
 */
function command_buttons_views_data() {
  $data = array();

  // ------------------------------------------------------------------------
  // Buttons table
  $data['command_buttons'] = array(
    'table' => array(
      'base' => array(
        'field' => 'bid',
        'title' => t('Button entities'),
        'help' => t('A button entity.'),
      ),
      'group' => t('Command Buttons'),
      'entity type' => 'command_button',
    ),
    'bid' => array(
      'title' => t('Button ID ID'),
      'help' => t('The internal ID of the button.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'bundle' => array(
      'title' => t('Bundle'),
      'help' => t('The bundle (type) of the entity.'),
      'field' => array(
        'handler' => 'command_buttons_handler_field_bundle',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'command_buttons_handler_filter_bundle',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'command_buttons_handler_argument_bundle',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'title' => array(
      'title' => t('Title'),
      'help' => t('The content title of the entity.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'view_entity' => array(
      'field' => array(
        'title' => t('Administrative link'),
        'help' => t('Provide a simple link for administrators to view the content.'),
        'handler' => 'command_buttons_handler_field_view_entity',
      ),
    ),
    'edit_entity' => array(
      'field' => array(
        'title' => t('Administrative edit link'),
        'help' => t('Provide a simple link for administrators to edit the content.'),
        'handler' => 'command_buttons_handler_field_edit_entity',
      ),
    ),
    'delete_entity' => array(
      'field' => array(
        'title' => t('Administrative delete link'),
        'help' => t('Provide a simple link for administrators to delete the content.'),
        'handler' => 'command_buttons_handler_field_delete_entity',
      ),
    ),
  );

  return $data;
}
