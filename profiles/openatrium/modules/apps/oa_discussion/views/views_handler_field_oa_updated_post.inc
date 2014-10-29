<?php

/**
 * @file
 * Definition of views_handler_argument_numeric.
 */

/**
 * Basic filter for Open Atrium section access
 */
class views_handler_field_oa_updated_post extends views_handler_field_numeric {

  function query() {
    $limit = REQUEST_TIME - NODE_NEW_LIMIT;

    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";
    $node = $this->query->ensure_table('node', $this->relationship);

    $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
    $this->field_alias = $this->query->add_field(NULL, "CASE WHEN $field < $node.changed THEN 1 ELSE 0 END", $this->table . '_' . $this->field, $params);
  }
}
