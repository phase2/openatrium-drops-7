<?php

/**
 * @file
 * Contains documentation about the Open Atrium Clone module's hooks.
 */

/**
 * @defgroup oa_clone Open Atrium Clone
 * @{
 * Hooks from the Open Atrium Clone module.
 */

/**
 * Clone metadata associated with a Space or Group.
 *
 * This hook is called when cloning Space or Group, after the new node has
 * been created but before any of it's content has been cloned. This is where
 * your module should clone any metadata that it keeps about the Space or Group.
 *
 * If you want to clone some peice of data BEFORE the Space or Group node is
 * saved (ie. so that your data is saved with it, rather than saving again) then
 * you should hook_clone_node_alter() instead.
 *
 * @param object $node
 *   Node object representing the Space or Group that we are going to configure.
 * @param int $original_nid
 *   The node ID of the original Space or Group we are cloning metadata from.
 *
 * @see hook_clone_node_alter()
 */
function hook_oa_clone_group_metadata($node, $original_nid) {
  // Clone some data you are keeping about the node 
  save_data_about_group($node->nid, load_data_about_group($original_nid));
}

/**
 * @}
 */
