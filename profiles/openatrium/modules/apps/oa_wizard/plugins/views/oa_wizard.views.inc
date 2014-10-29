<?php

/**
 * @file
 * Provides views integration for Open Atrium Wizards.
 */

/**
 * Implements hook_views_data().
 */
function oa_wizard_views_data() {
  $data = array();

  // ------------------------------------------------------------------------
  // Buttons table
  $data['oa_wizard'] = array(
    'table' => array(
      'base' => array(
        'field' => 'wizard_id',
        'title' => t('Wizard entities'),
        'help' => t('A wizard entity.'),
      ),
      'group' => t('Wizards'),
      'entity type' => 'oa_wizard',
    ),
    'wizard_id' => array(
      'title' => t('Wizard ID'),
      'help' => t('The internal ID of the wizard.'),
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
    'title' => array(
      'title' => t('Title'),
      'help' => t('The content title of the wizard.'),
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
        'handler' => 'oa_wizard_handler_field_view_entity',
      ),
    ),
    'edit_entity' => array(
      'field' => array(
        'title' => t('Administrative edit link'),
        'help' => t('Provide a simple link for administrators to edit the content.'),
        'handler' => 'oa_wizard_handler_field_edit_entity',
      ),
    ),
    'delete_entity' => array(
      'field' => array(
        'title' => t('Administrative delete link'),
        'help' => t('Provide a simple link for administrators to delete the content.'),
        'handler' => 'oa_wizard_handler_field_delete_entity',
      ),
    ),
  );

  return $data;
}
