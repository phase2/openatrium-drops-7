<?php

/**
 * @file
 * Definition of views_handler_argument_numeric.
 */

/**
 * Contextural filter for Open Atrium Parent ID
 */
class views_handler_argument_oa_parent_id extends views_handler_argument_numeric {
  var $no_operator = TRUE;

  function query($group_by = FALSE) {
    $this->ensure_my_table();

    // determine parent of the node argument if any
    $node = node_load($this->argument);  // drupal has this cached
    $parent = field_get_items('node', $node, 'oa_parent');
    $parent_id = (!empty($parent[0]['target_id'])) ? $parent[0]['target_id'] : $this->argument;
    $this->query->add_where_expression(0, "field_data_oa_parent.oa_parent_target_id = $parent_id OR node.nid = $parent_id");
  }

}
