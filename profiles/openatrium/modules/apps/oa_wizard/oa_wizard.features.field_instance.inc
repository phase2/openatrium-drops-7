<?php
/**
 * @file
 * oa_wizard.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oa_wizard_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'oa_wizard-wizard-field_wizard_steps'
  $field_instances['oa_wizard-wizard-field_wizard_steps'] = array(
    'bundle' => 'wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Steps for the wizard.<br/>
Each step should be on a new line and be in format of Title: [title] | fields:[[field_name],[field_name2]]</br>
<code>
    title: Title | fields: [title]<br/>
    title: Space Type | fields: [field_oa_space_type,oa_parent_space]<br/>
    title: Space Access | fields: [group_access]<br/>
</code>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'oa_wizard',
    'field_name' => 'field_wizard_steps',
    'label' => 'Wizard Steps',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'oa_wizard-wizard-field_wizard_type'
  $field_instances['oa_wizard-wizard-field_wizard_type'] = array(
    'bundle' => 'wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'oa_wizard',
    'field_name' => 'field_wizard_type',
    'label' => 'Content Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content Type');
  t('Steps for the wizard.<br/>
Each step should be on a new line and be in format of Title: [title] | fields:[[field_name],[field_name2]]</br>
<code>
    title: Title | fields: [title]<br/>
    title: Space Type | fields: [field_oa_space_type,oa_parent_space]<br/>
    title: Space Access | fields: [group_access]<br/>
</code>');
  t('Wizard Steps');

  return $field_instances;
}
