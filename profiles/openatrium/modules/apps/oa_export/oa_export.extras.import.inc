<?php

/**
 * Import menu links for this entity.
 *
 * @param array $link
 *   The link we are importing.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 *
 * @return bool/int
 *   The new mlid if we create a new menu item.
 */
function oa_export_oa_import_extra_menu($link, $key, $imports, &$map) {

  $new_mlid = FALSE;
  return FALSE;

  if (!empty($link)) {
    // The old menu link id and nid it belongs to.
    list(,$mlid) = explode(':', $key);

    // The nid of the node the link points to.
    list(,$nid) = explode('/', $link['link_path']);

    // Look for the node this link belongs to.
    $new_path = 'node/' . $imports['node:' . $nid]->nid;

    // Look for an existing menu item with the same name, path and title.
    $result = db_select('menu_links', 'ml')
      ->fields('ml', array('mlid'))
      ->condition('menu_name', $link['menu_name'])
      ->condition('link_path', $new_path)
      ->condition('link_title', $link['link_title'])
      ->execute();

    foreach ($result as $record) {
      // Load the link if we find one.
      $existing_link = menu_link_load($record->mlid);
      $new_mlid = $record->mlid;
    }

    // Set the key without the nid.
    $key = 'link:' . $mlid;


//    // This will insert a new link.
//    $link['mlid'] = NULL;
//
//    // Save the link. We get the new mlid in return.
//    $new_mlid = menu_link_save($link);
  }

  return $new_mlid;
}

/**
 * Import group roles for this entity.
 *
 * @param array $role
 *   The role we are importing.
 * @param string $bundle
 * @param string $entity_id
 *   The id of the entity for this permission.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 */
function oa_export_oa_import_extra_role($role, $key, $imports, &$map) {

  $new_id = FALSE;
  return FALSE;

  if (!empty($role)) {
    list($type, $bundle, $entity_id) = explode(':', $key);

    foreach ($role as $name) {
      // Make sure the role doesn't already exist.
      module_load_include('inc', 'og', 'includes/og_features_role.features');
      if (!_og_features_role_exists($name, 'node', $bundle)) {
        // Create the role.
        $role = og_role_create($role, 'node', $entity_id, $bundle);
        $new_id = $role->rid;
      }
    }
  }
  return $new_id;

//  list($entity_id,,$bundle) = entity_extract_ids($entity_type, $entity);
//
//  // Export OG roles.
//  $role_map = array();
//  $roles = og_roles('node', $bundle, $entity_id);
//  $custom_roles = array();
//  foreach ($roles as $rid => $role_name) {
//    $original_role_map[$role_name] = $rid;
//
//  }
//
//  // Custom roles won't have a rid so we will just push them into the roles
//  // array.
//  foreach ($custom_roles as $custom_role) {
//    array_push($custom_role, $roles);
//  }
//  $results['roles'] = $roles;

  // Clone OG permissions. @todo: this will need to be done on import.
//  $permissions = og_role_permissions($original_roles);
//  $roles = og_roles('node', $space->type, $space->nid);
//  foreach ($roles as $rid => $name) {
//    og_role_change_permissions($rid, $permissions[$original_role_map[$name]]);
//  }
//  // If this is a custom role, then we have to create it.
//  if (!in_array($role_name, array(OG_ANONYMOUS_ROLE, OG_AUTHENTICATED_ROLE, OG_ADMINISTRATOR_ROLE))) {
//    $role = og_role_create($role_name, 'node', $entity_id, $bundle);
//    $custom_roles[$role->rid] = $role;
//  }
}

/**
 * Import group permissions for this entity.
 *
 * @param array $permission
 *   The permission we are importing.
 * @param string $bundle
 * @param string $entity_id
 *   The id of the entity for this permission.
 * @param string $key
 *   Entities are keyed by [ENTITY_TYPE:ENTITY_ID].
 * @param array $imports
 *   Contains all entities that will be imported.
 * @param array $map
 *   Contains a record of imported entities and their ids.
 *   -  [ENTITY_TYPE:OLD_ENTITY_ID] = [NEW_ENTITY_ID];
 */
function oa_export_oa_import_extra_permission($permission, $key, $imports, &$map) {

  return FALSE;

  if (!empty($permission)) {
    list($type, $bundle, $entity_id) = explode(':', $key);

    foreach ($permission as $rid => $permissions) {
      $existing = og_role_permissions(array($rid => $permissions));
      $new = array_diff($permission[$rid], $existing[$rid]);
      if (!empty($new)) {
        $well = 'new';
      }
    }
    // user_role_grant_permissions();
  }
}
