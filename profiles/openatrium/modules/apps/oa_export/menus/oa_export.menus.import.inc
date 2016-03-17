<?php
/**
 * @file
 * oa_export.menus.import.inc
 */

/**
 * Import menu links for this entity.
 *
 * Exported menus are stored in the $imports array as:
 *   - ['menu':ENTITY_ID]
 *
 * @param array $menu
 *   Menu being imported.
 * @param string $menu_entity_type
 *   The entity type of the entity the menu belongs to.
 * @param int $new_entity_id
 *   The id of the imported entity.
 * @param string $new_entity_bundle
 *   The bundle ($entity->type) of the new entity.
 * @param $menu_map
 *   Keeps track of the menus that have already been imported.
 *
 * @return int/bool
 *   The new menu link id if a new menu is created.
 */
function oa_export_menus_import($menu, $old_id, $new_id, $entity_type, &$map) {
  // This key gets stored in the $map when a menu item is successfully
  // imported so we can keep track.
  $map_key = $entity_type . ':' . $new_id . ':' . 'link';
  if (isset($map[$map_key])) {
    $mlid = $map[$map_key];
  }
  else {
    foreach ($menu as $key => $links) {
      if (!empty($links)) {
        list($type, $nid) = explode(':', $key);
        // Double check the type and id.
        if ($entity_type == $type && $old_id == $nid) {
          // This is the top-level menu item.
          $menu_name = $links[0]['menu_name'];
          // Check to make sure the menu item hasn't already been imported.
          // When Spaces are imported a {menu_item} entry gets created. We expect
          // to find an entry but make sure.
          if ($mlid = og_menu_single_get_link_mlid($entity_type, $new_id, TRUE)) {
            // We generate new links for all child links and use this mlid as the
            // plid for the links. This is the parent link.
            $existing_link = og_menu_single_menu_link_load($mlid);
            // Add it to our menu map.
            $map[$map_key] = $existing_link['mlid'];
            // The parent link id used to associate child links.
            $plid = isset($existing_link) ? $existing_link['mlid'] : NULL;
            oa_export_menus_import_create_links($plid, $links, $map);
          }
          // Didn't find an existing link so we need to create a group link.
          elseif ($mlid = og_menu_single_get_link_mlid_or_create($entity_type, $new_id)) {
            $existing_link = og_menu_single_menu_link_load($mlid);
            // Add it to our menu map.
            $map[$map_key] = $existing_link['mlid'];
            // The parent link id used to associate child links.
            $plid = isset($existing_link) ? $existing_link['mlid'] : NULL;
            oa_export_menus_import_create_links($plid, $links, $map);
          }
        }
      }
    }
  }
}

/**
 * maybe
 */
//    $menu_name = str_replace('-', '_', $menu['menu_name']);
//    foreach (module_implements('oa_import_menus__' . $entity_type . '__' . $menu_name) as $module) {
//      $function = $module . '_oa_import_menus__' . $entity_type . '__' . $menu_name;
//      if (function_exists($function)) {
//        $mlid = $function($menu, $old_entity_id, $new_entity_id, $entity_type, $entity_bundle);
//
//        if (($mlid !== FALSE) && !isset($map[$map_key])) {
//          $map[$map_key] = $mlid;
//        }
//      }
//    }

function oa_export_menus_import_create_links($plid, $links, &$map) {
  foreach ($links as $old_mlid => $link) {
    // Get the entity type and old id from the link.
    list($type, $id) = explode('/', $link['link_path']);
    // Get the new entity id from our map.
    $new_id = $map[$type . ':' . $id];
    // Key used to track imports.
    $map_key = $type . ':' . $new_id . ':' . 'link';

    if (!isset($map[$map_key]) && !og_menu_single_get_link_mlid($type, $new_id, TRUE)) {
      $mlid = NULL;
      // Build a basic link.
      $new_link = array(
        'menu_name' => $link['menu_name'],
        'mlid' => $mlid,
        'plid' => $plid,
        'link_path' => $type . '/' . $new_id,
        'link_title' => $link['link_title'],
        'options' => $link['options'],
      );

      // Save the new link.
      $mlid = menu_link_save($new_link);

      // If the save was successful add an entry to the menu map.
      if ($mlid !== FALSE && !isset($map[$map_key])) {
        $map[$map_key] = $mlid;
      }
    }
  }
}

/**
 * Import menus for nodes and menus with the 'og-menu-single' name.
 *
 * @param array $menu
 *   Menu being imported.
 *
 * @code
 *   $menu = array(
 *     ['menu':OLD_ENTITY_ID] => array(
 *       [ENTITY_TYPE:ENTITY_ID:MLID] => array(
 *         [PLID] = ALL CHILD ITEMS.
 *       ),
 *     ),
 *   );
 * @endcode
 *
 * @param string $entity_type
 *   The entity type of the entity the menu belongs to.
 * @param int $new_entity_id
 *   The id of the imported entity.
 * @param string $entity_bundle
 *   The bundle ($entity->type) of the new entity.
 *
 * @return int/bool
 *   The menu link id of the imported menu or FALSE.
 */
function oa_export_oa_import_menus__node__og_menu_single($menu, $old_entity_id, $new_entity_id, $entity_type, $entity_bundle) {

  // The $menu that is passed in is a parent with all children.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast = &drupal_static(__FUNCTION__);
  }
  $plid = &$drupal_static_fast;

  // Wrapper for the new entity that has already been imported that needs this
  // menu assigned to it.
  $entity = entity_metadata_wrapper($entity_type, $new_entity_id);

  foreach ($menu as $item => $key) {
    foreach ($key as $plid => $link) {
      if ($plid) {
        // Clone the imported menu and save it.
//        $clone = $menu;
//        oa_export_menu_import_prepare($clone, $entity, $plid);
//        $mlid = menu_link_save($clone);
      }
    }
  }

  // Wrapper for the new entity that has already been imported that needs this
  // menu assigned to it.
//  $entity = entity_metadata_wrapper($entity_type, $new_entity_id);
//  // Make sure we don't already have an og menu entry for this entity.
//  if ($mlid = og_menu_single_get_link_mlid($entity_type, $new_entity_id, TRUE)) {
//    // Found a menu entry in {menu_links}, load it.
//    $single_link = og_menu_single_menu_link_load($mlid);
//    // Let's us know that this is a top-level menu item.
//    if (isset($single_link['plid']) && empty($single_link['plid'])) {
//      $plid = $single_link['plid'];
//    }
//  }
//  if (!$mlid ) {
//    // Group content.
//    if (og_is_group_content_type($entity_type, $entity_bundle)) {
//
//      // Get existing options for menus that are enabled via the node type
//      // edit form. If the OG group option isn't set then we set it.
//      $menu_options = variable_get('menu_options_' . $entity_bundle, array());
//      if (!in_array(OG_MENU_SINGLE_MENU_NAME, $menu_options)) {
//        $menu_options[] = OG_MENU_SINGLE_MENU_NAME;
//        variable_set('menu_options_' . $entity_bundle, $menu_options);
//      }
//
//      if (!variable_get('og_menu_single_group_content__node__' . $entity_bundle, FALSE)) {
//        // This allows adding this menu to the <Group menu>.
//        variable_set('og_menu_single_group_content__node__' . $entity_bundle, (int) (bool) 1);
//      }
//
//      // Clone the imported menu and save it.
//      $clone = $menu;
//      oa_export_menu_import_prepare($clone, $entity, $plid);
//      $mlid = menu_link_save($clone);
//    }
//  }
//  else {
//    // This is the top-level Space plid we need.
//    if (!isset($plid)) {
//      $plid = $mlid;
//    }
//  }
//
//  // A group.
//  if (og_is_group($entity_type, $entity)) {
//    if (!og_menu_single_is_enabled_group('node', $entity_bundle)) {
//      variable_set('og_menu_single_group__node__' . $entity_bundle, (int) (bool) 1);
//      // Create the new og menu link.
//      $mlid = og_menu_single_get_link_mlid_or_create($entity_type, $new_entity_id);
//    }
//  }
//  return $mlid;
}

/**
 * Prepare a new menu item for import.
 *
 * @param array $clone
 *   The menu to clone.
 * @param object $entity
 *   Entity wrapper for the imported entity this menu belongs to.
 * @param int/bool $plid
 *   Set the parent menu link.
 */
function oa_export_menu_import_prepare(&$clone, $entity, $plid) {
  // This is what triggers the menu creation.
  unset($clone['mlid']);
  unset($clone['plid']);
  // Replace the old nid with the new nid on some items.
  $clone['link_path'] =
  $clone['href'] = 'node/' . $entity->getIdentifier();
  // This sets the parent link id.
  $clone['plid'] = isset($plid) ? $plid : 0;
}
