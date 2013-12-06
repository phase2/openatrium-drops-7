<?php

/**
 * @file
 * Definition of views_handler_relationship_oa_parent_id.
 */

/**
 * Relationship for Open Atrium parent
 */
class views_handler_relationship_oa_parent_id extends views_handler_relationship {

  function query() {
    // Figure out what base table this relationship brings to the party.
    $table_data = views_fetch_data($this->definition['base']);
    $base_field = empty($this->definition['base field']) ? $table_data['table']['base']['field'] : $this->definition['base field'];

    $this->ensure_my_table();

    $def = $this->definition;
    $def['table'] = $this->definition['base'];
    $def['field'] = $base_field;
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = $this->real_field;
    if (!empty($this->options['required'])) {
      $def['type'] = 'INNER';
    }

    // use a short alias for this:
    $alias = $def['table'] . '_' . $this->table;
    $field = $def['table'] . '.' . $def['field'];
    $left_field = $def['left_table'] . '.' . $def['left_field'];

    $def['left_table'] = '';
    $def['left_field'] = 'COALESCE(' . $left_field . ', ' . $field . ')';

    $join = new views_join();

    $join->definition = $def;
    $join->options = $this->options;
    $join->construct();
    $join->adjusted = TRUE;

    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);

    // Add access tags if the base table provide it.
    if (empty($this->query->options['disable_sql_rewrite']) && isset($table_data['table']['base']['access query tag'])) {
      $access_tag = $table_data['table']['base']['access query tag'];
      $this->query->add_tag($access_tag);
    }
  }
}
