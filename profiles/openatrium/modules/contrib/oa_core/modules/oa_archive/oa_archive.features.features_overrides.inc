<?php
/**
 * @file
 * oa_archive.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_archive_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: flag
  $overrides["flag.trash.flag_confirmation"] = 'Are you sure you want to archive this item? You may be unable to access it after archiving.';
  $overrides["flag.trash.flag_long"] = 'Move item to the site archive';
  $overrides["flag.trash.flag_message"] = 'Item has been archived';
  $overrides["flag.trash.flag_short"] = 'Archive This';
  $overrides["flag.trash.show_on_page"] = 0;
  $overrides["flag.trash.title"] = 'Archive';
  $overrides["flag.trash.unflag_confirmation"] = 'Are you sure you want to remove this item from archive?';
  $overrides["flag.trash.unflag_denied_text"] = 'Archived';
  $overrides["flag.trash.unflag_long"] = 'Unarchive item and restore previous access settings.';
  $overrides["flag.trash.unflag_message"] = 'Item removed fromt archive';
  $overrides["flag.trash.unflag_short"] = 'Remove from archive';

  // Exported overrides for: views_view
  $overrides["views_view.trash_flag_bin.display|default|display_options|title"] = 'Show Archive';
  $overrides["views_view.trash_flag_bin.display|page_1|display_options|menu|title"] = 'Show Archive';
  $overrides["views_view.trash_flag_bin.display|page_1|display_options|path"] = 'node/%/archive';
  $overrides["views_view.trash_flag_bin.display|page|display_options|path"] = 'archive';

 return $overrides;
}
