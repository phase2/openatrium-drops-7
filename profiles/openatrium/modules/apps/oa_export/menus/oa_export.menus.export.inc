<?php
/**
 * @file
 * oa_export.menus.export.inc
 */

/**
 * Helper function to export comments on entities.
 *
 * @param integer $entity_id
 * @param array $results
 */
function oa_export_comments_export($entity_id, &$results) {
  foreach (oa_export_get_comments($entity_id) as $cid) {
    if ($comment = reset(entity_load('comment', array($cid)))) {
      oa_export_entity_export('comment', $comment, $results);
    }
    // Not sure this can happen but have had issues with missing entities.
    else {
      $results['messages'][] = t("The comment with cid: !cid, couldn't be exported. It no longer exists", array('!cid' => $cid));
    }
  }
}

/**
 * Export menu links for this entity.
 *
 * @param object $entity
 *   The fully loaded entity.
 * @param int $entity_id
 *   Id of the entity the menu belongs to.
 * @param string $entity_type
 *   The type of entity, e.g., 'node', 'taxonomy_term', etc.
 * @param array $results
 *   Data stored in $context['results'] during the batch process.
 */
function oa_export_menus_export($entity, $entity_id, $entity_type, &$results) {
  // Look for a link on this node entity.
  if ($mlid = og_menu_single_get_link_mlid($entity_type, $entity_id)) {
    // Load the link by the menu link id.
    $menu = menu_link_load($mlid);
    if (!empty($menu)) {
      list(,,$bundle) = entity_extract_ids($entity_type, $entity);
      // Allow exporting menus based on the menu name.
      $menu_name = str_replace('-', '_', $menu['menu_name']);
      foreach (module_implements('oa_export_menus__' . $entity_type . '__' . $menu_name) as $module) {
        $function = $module . '_oa_export_menus__' . $entity_type . '__' . $menu_name;
        if (function_exists($function)) {
          $function($menu, $entity_id, $entity_type, $bundle, $results);
        }
      }
    }
  }
}

/**
 * Implements hook_oa_export_menus__ENTITY_TYPE__MENU_NAME().
 */
function oa_export_oa_export_menus__node__og_menu_single($menu, $entity_id, $entity_type, $bundle, &$results) {
  $items = array();
  // See if we have already stored this menu.
  if (!isset($results['export']['menu' . ':' . $entity_type . ':' . $entity_id])) {
    // This could be a child link so look a little deeper to make sure.
    if (!oa_export_child_menu_exported($menu['plid'], $results)) {
      // This is a top-level menu as its 'plid' is 0.
      if (isset($menu['plid']) && empty($menu['plid'])) {
        // Add the top-level menu. This seems to always get created by default
        // but including it in case we need to create it.
        $items[$entity_type . ':' . $entity_id . ':' . $menu['mlid']][$menu['plid']] = $menu;
        // Check for children items.
        oa_export_find_menu_children($items, $menu['mlid'], $entity_id, $entity_type);
      }
      // This is a child.
      else {
        // Use this child to load the parent menu.
        $parent = og_menu_single_menu_link_load($menu['plid']);
        // Make sure we found the parent.
        if (isset($parent['plid']) && empty($parent['plid'])) {
          // Get the id of the parent to check our results.
          list($type ,$id) = explode('/', $parent['link_path']);
          // Check for a previous import.
          if (!isset($results['export'][$type . ':'. $id])) {
            // Add the top-level menu.
            $items[$entity_type . ':' . $entity_id . ':' . $parent['mlid']][$parent['plid']] = $parent;
            // Get the entity id of the parent to store in our results since the
            // entity id passed in was a child.
            list(,$entity_id) = explode('/', $parent['link_path']);
            // Check for children items.
            oa_export_find_menu_children($items, $parent['mlid'], $entity_id, $entity_type);
          }
        }
      }
      if (!empty($items)) {
        // Save the menu to a key: [menu:ENTITY_ID]
        $results['export']['menu' . ':' . $entity_type . ':' . $entity_id] = $items;
      }
    }
  }
}

function oa_export_find_menu_children(&$items, $mlid, $entity_id, $entity_type) {
  // Check for children items.
  $children = og_menu_single_children_items($mlid);
  foreach ($children as $description => $link) {
    // Collect all the child links.
    $items[$entity_type . ':' . $entity_id . ':' . $link['link']['plid']][$link['link']['mlid']] = $link['link'];
  }
}

function oa_export_child_menu_exported($plid, &$results) {
  if ($parent = og_menu_single_menu_link_load($plid)) {
    list(,$entity_id) = explode('/', $parent['link_path']);
    if (!isset($results['export']['menu' . ':' . $entity_id])) {
      return FALSE;
    }
    else {
      return TRUE;
    }
  }
}
