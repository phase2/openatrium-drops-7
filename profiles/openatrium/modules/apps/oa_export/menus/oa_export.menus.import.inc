<?php
/**
 * @file
 * oa_export.menus.import.inc
 */

/**
 * Import menu links for this entity.
 *
 * @param array $menu
 *   Menu being imported.
 * @param int $old_id
 *   The old entity id of the entity the menu belongs to.
 * @param int $new_id
 *   The new entity id of the entity the menu belongs to.
 * @param string $entity_type
 *   The ($entity->type) of the new entity.
 * @param $map
 *   Keeps track of items that have already been imported.
 *
 * @return int/bool
 *   The new menu link id if a new menu is created.
 */
function oa_export_menus_import($menu, $old_id, $new_id, $entity_type, &$map) {
  foreach ($menu as $key => $links) {
    if (!empty($links)) {
      list($type, $nid) = explode(':', $key);
      // Double check the type and id.
      if ($entity_type == $type && $old_id == $nid) {
        // Check to make sure the menu item hasn't already been imported.
        // When Spaces are imported a {menu_item} entry gets created. We expect
        // to find an entry but make sure.
        if ($mlid = og_menu_single_get_link_mlid_or_create($entity_type, $new_id)) {
          // We generate new links for all child links and use this mlid as the
          // plid for the links. This is the parent link.
          $existing_link = og_menu_single_menu_link_load($mlid);
          // The parent link id used to associate child links.
          $plid = isset($existing_link) ? $existing_link['mlid'] : NULL;
          $map_key = $entity_type . ':' . $new_id . ':' . $plid;

          // Iterate over the exported links and import them.
          foreach ($links as $old_mlid => $link) {
            // We skip the actual Space link.
            // @todo: See if we can just remove this from the export.
            if ($old_mlid != 0) {
              // Get the entity type and old entity id from the link.
              list($type, $id) = explode('/', $link['link_path']);
              // Get the new entity id from our map.
              $new_link_nid = $map[$type . ':' . $id];
              // Build a basic link.
              $new_link = array(
                'menu_name' => $link['menu_name'],
                'mlid' => NULL,
                'plid' => $plid,
                'link_path' => $type . '/' . $new_link_nid,
                'link_title' => $link['link_title'],
                'options' => $link['options'],
                'weight' => $link['weight'],
              );

              // Save the new link.
              $mlid = menu_link_save($new_link);

              // If the save was successful add an entry to the menu map.
              if ($mlid !== FALSE && !isset($map[$map_key][$old_mlid])) {
                $map[$map_key][$old_mlid] = $mlid;
              }
            }
          }
        }
      }
    }
  }
}
