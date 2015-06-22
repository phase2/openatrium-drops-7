<?php

/**
 * @file
 * Hook implementations for the Variable module.
 */

/**
 * Implements hook_variable_info().
 */
function oa_wiki_variable_info($options) {
  $variable = array();
  $options = oa_wiki_get_vocab_options();
  $options[0] = t('-None-');
  $variable['oa_wiki_vocab'] = array(
    'type' => 'select',
    'title' => t('Document Vocabulary'),
    'options' => $options,
    'default' => 0,
    'description' => t("The vocabulary used for Document sections.  Leave empty for menu-based documents."),
    'group' => 'oa_taxonomy',
  );
  return $variable;
}

/**
 * Helper function to determine which vocabularies are allowed on this content type
 */
function oa_wiki_get_vocab_options($type = 'oa_wiki_page') {
  $vids = array();
  $vocab_names = array();

  // first grab any taxonomy reference fields on the content type
  $field_info = field_info_fields();
  $fields = field_info_instances('node', $type);
  foreach ($fields as $key => $field) {
    $info = $field_info[$key];
    if ($info['module'] == 'taxonomy') {
      foreach ($info['settings']['allowed_values'] as $index => $item) {
        $vocab_names[] = $item['vocabulary'];
      }
    }
  }

  // if using og_vocab, grab the valid vocab ids.
  if (module_exists('og_vocab')) {
    $vids = og_vocab_get_accessible_vocabs('node', $type, OG_VOCAB_FIELD);
    $vids = !empty($vids) ? $vids : array();
  }

  $result = array();
  foreach (taxonomy_get_vocabularies() as $vid => $vocab) {
    if (in_array($vid, $vids) || (in_array($vocab->machine_name, $vocab_names))) {
      $result[$vid] = $vocab->name;
    }
  }
  return $result;
}

/**
 * Implements hook_variable_group_info().
 */
function oa_wiki_variable_group_info() {
  $groups = array();
  $groups['oa_taxonomy'] = array(
    'title' => t('Taxonomy'),
    'description' => t('Settings for Open Atrium Taxonomies'),
    'access' => 'administer taxonomy',
  );
  return $groups;
}
