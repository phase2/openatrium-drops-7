<?php
/**
 * @file
 * oa_search.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_search_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: variable
  $overrides["variable.search_active_modules.value|file_entity"] = 0;
  $overrides["variable.search_active_modules.value|user"] = 'user';

 return $overrides;
}
