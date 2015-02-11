<?php

/**
 * @file
 * Definition of views_handler_filter_has_parent.
 */

/**
 * Basic filter for OpenAtrium Has Parent
 */
class views_handler_filter_is_parent extends views_handler_filter {

  function query() {
    $this->ensure_my_table();
//    $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", $this->value, $this->operator);
    $this->query->add_where_expression(0, "field_data_oa_parent.oa_parent_target_id IS NULL");
  }
}
