<?php

/**
 * @file
 * OG-vocab admin settings
 */

/**
 * Admin form settings.
 */
function og_vocab_admin_settings($form_state) {
  $form['og_vocab_term_page_access'] = array(
    '#type' => 'checkbox',
    '#title' => t('Term page access'),
    '#description' => t('When enabled, access to taxonomy/term/[tid] will be controlled by OG-vocab'),
    '#default_value' => variable_get('og_vocab_term_page_access', FALSE),
  );
  $form['og_vocab_allow_shared_vocabularies'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow groups to share vocabularies'),
    '#description' => t('When using the %og_vocab module this settings allow groups to share the same vocabularies. Note: Only enable this setting if you have a trusted permission setup. In certain setups shared vocabularies can be edited/deleted by all group administrator.', array('%og_vocab' => 'OG Vocabulary')),
    '#default_value' => variable_get('og_vocab_allow_shared_vocabularies', FALSE),
  );
  return system_settings_form($form);
}


/**
 * Submit handler; Re-build the menu tree.
 *
 * @see og_vocab_menu_alter().
 */
function og_vocab_admin_settings_submit($form, &$form_state) {
  if (variable_get('og_vocab_term_page_access', FALSE) != $form_state['values']['og_vocab_term_page_access']) {
    // Rebuild the menu tree.
    variable_set('menu_rebuild_needed', TRUE);
  }
}
