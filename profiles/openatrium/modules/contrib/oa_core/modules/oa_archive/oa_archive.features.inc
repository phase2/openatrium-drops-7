<?php
/**
 * @file
 * oa_archive.features.inc
 */

/**
 * Implements hook_flag_default_flags_alter().
 */
function oa_archive_flag_default_flags_alter(&$data) {
  if (isset($data['trash'])) {
    $data['trash']['flag_confirmation'] = 'Are you sure you want to archive this item? You may be unable to access it after archiving.'; /* WAS: 'Are you sure you want to trash this item? You may be unable to access it after trashing.' */
    $data['trash']['flag_long'] = 'Move item to the site archive'; /* WAS: 'Move item to the site trash bin.' */
    $data['trash']['flag_message'] = 'Item has been archived'; /* WAS: 'Item has been trashed' */
    $data['trash']['flag_short'] = 'Archive This'; /* WAS: 'Move to Trash' */
    $data['trash']['show_on_page'] = 0; /* WAS: 1 */
    $data['trash']['title'] = 'Archive'; /* WAS: 'Trash' */
    $data['trash']['unflag_confirmation'] = 'Are you sure you want to remove this item from archive?'; /* WAS: 'Are you sure you want to remove this item from trash?' */
    $data['trash']['unflag_denied_text'] = 'Archived'; /* WAS: 'trashed' */
    $data['trash']['unflag_long'] = 'Unarchive item and restore previous access settings.'; /* WAS: 'Remove from trash item and restore previous access settings.' */
    $data['trash']['unflag_message'] = 'Item removed fromt archive'; /* WAS: 'Item removed from Trash' */
    $data['trash']['unflag_short'] = 'Remove from archive'; /* WAS: 'Remove from Trash' */
  }
}

/**
 * Implements hook_views_default_views_alter().
 */
function oa_archive_views_default_views_alter(&$data) {
  if (isset($data['trash_flag_bin'])) {
    $data['trash_flag_bin']->display['default']->display_options['title'] = 'Show Archive'; /* WAS: 'Trash Bin' */
    $data['trash_flag_bin']->display['page_1']->display_options['menu']['title'] = 'Show Archive'; /* WAS: 'Trash Bin' */
    $data['trash_flag_bin']->display['page_1']->display_options['path'] = 'node/%/archive'; /* WAS: 'node/%/trash-bin' */
    $data['trash_flag_bin']->display['page']->display_options['path'] = 'archive'; /* WAS: 'trash-bin' */
  }
}

