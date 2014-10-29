<?php
/**
 * @file
 * oa_domains.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oa_domains_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-oa_space-field_oa_space_domain'
  $field_instances['node-oa_space-field_oa_space_domain'] = array(
    'bundle' => 'oa_space',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom domain name for this space, e.g. myspace.example.com.  Do not include the http://',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oa_space_domain',
    'label' => 'Domain',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 38,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom domain name for this space, e.g. myspace.example.com.  Do not include the http://');
  t('Domain');

  return $field_instances;
}
