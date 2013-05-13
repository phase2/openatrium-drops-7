<?php
/**
 * @file reference_option_limit.views.inc
 * Contains implementations of Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function reference_option_limit_views_data_alter(&$data) {
  // Get the names of fields that have instances which are option limited.
  $option_limited_fields = reference_option_get_entity_option_limited_fields();

  foreach ($option_limited_fields as $field_name) {
    $table_key = 'field_data_' . $field_name;
    //dsm($data[$table_key], "views data for $field_name");

    $field = field_info_field($field_name);
    $handler = NULL;
    switch ($field['type']) {
      /*
      // These are not supported yet: @todo.
      case 'entityreference':
        $field_key = $field_name . '_target_id';
        $handler = 'todo!';
        break;
      */
      case 'taxonomy_term_reference':
        $field_key = $field_name . '_tid';
        $handler = 'reference_option_limit_handler_filter_limited_options_term_reference';
        break;
    }
    // Skip this field if we've not found a handler.
    if (is_null($handler)) {
      continue;
    }

    $filter = $data[$table_key][$field_key]['filter'];

    $title_short = $data[$table_key][$field_key]['title short'];
    $title_short .= ' ' . t('(option limit)');
    $data_option_limit = array(
      'group' => $data[$table_key][$field_key]['group'],
      'title' => $title_short . ' (' . $filter['field_name'] . ')',
      'title short' => $title_short,
      'help' => $data[$table_key][$field_key]['help'] . ' ' . t('Includes additional options to limit filter values.'),
    );
    $data_option_limit['filter'] = $filter;
    $data_option_limit['filter']['real field'] = $filter['field'];
    $data_option_limit['filter']['handler'] = $handler;

    // Now add our new aliased field to the data for the table.
    $data[$table_key][$field_key . '_option_limit'] = $data_option_limit;
    //dsm($data[$table_key]);
  }
}

/**
 * Helper to get the options for a Views filter handler's matching fields.
 *
 * Returns a list of filter and argument handlers on the view that can be used
 * for matching against the handler's field.
 *
 * This helper allows to re-use the same code across different subclasses of
 * filter handler for different field types.
 *
 * @param $filter_handler
 *  The filter handler to make options for. Pretend this is $this ;)
 *  No assumptions should be made about the class of this handler more specific
 *  than it being a filter; it's here to allow access to its definition and the
 *  view object.
 * @param $referred_entity_type
 *  The entity type that this filter's field refers to.
 * @param $referred_bundles
 *  The bundles that this filter's field can refer to.
 *
 * @return
 *  An array of options for the extra_options_form checkboxes form element.
 */
function reference_option_limit_views_handler_filter_get_matched_field_options($filter_handler, $referred_entity_type, $referred_bundles) {
  $referred_entity_instances = field_info_instances($referred_entity_type);

  // Get the entity type.
  $table_data = views_fetch_data($filter_handler->view->base_table);
  $base_entity_type = $table_data['table']['entity type'];

  // Get the name of the field this handler represents.
  $field_name = $filter_handler->definition['field_name'];

  // Get the settings for this field's instances on this entity type.
  // We can't be any more specific as our view may be showing any or all
  // bundles.
  $option_limited_instances = reference_option_get_entity_option_limited_instances($base_entity_type, $field_name);
  //dsm($option_limited_instances, '$option_limited_instances');

  // Build an array of the fields that are used for matching by any of
  // the instances we have.
  $field_matched_fields = array();
  foreach ($option_limited_instances as $bundle => $instance) {
    $field_matched_fields += $instance['options_limit_fields'];
  }
  //dsm($field_matched_fields, '$field_matched_fields');

  // Get the potential field representations: filter or argument handlers
  // that have their field name set.
  $filters    = $filter_handler->view->display_handler->get_handlers('filter');
  $arguments  = $filter_handler->view->display_handler->get_handlers('argument');
  $candidates = array();
  foreach ($filters as $key => $handler) {
    if (isset($handler->definition['field_name'])) {
      $candidates['filter:' . $key] = $handler;
    }
  }
  foreach ($arguments as $key => $handler) {
    if (isset($handler->definition['field_name'])) {
      $candidates['argument:' . $key] = $handler;
    }
  }

  // Pick out the candidates that are fields that are also present on the
  // referred entity bundles our filter is interested in.
  $options = array();
  $views_object_types = views_object_types();
  foreach ($candidates as $key => $handler) {
    $handler_field_name = $handler->definition['field_name'];

    if (isset($field_matched_fields[$handler_field_name])) {
      $handler_type_label = $views_object_types[$handler->handler_type]['stitle'];
      $options[$key] = $handler_type_label . ': ' . $handler->ui_name();
    }
  }
  return $options;
}

/**
 * Helper to get the options for a Views filter handler.
 *
 * This allows to re-use the same code across different subclasses of filter
 * handler for different field types.
 *
 * @param $filter_handler
 *  The filter handler object that is calling this function; i.e. $this.
 * @param $referred_entity_type
 *  The type of entity that may be referered to by the field the calling handler
 *  represents.
 * @param $referred_bundles
 *  An array of bundle names that may be referred to by the field the calling
 *  handler represents.
 *
 * @return
 *  An array of FormAPI options.
 */
function reference_option_limit_views_handler_filter_get_value_options($filter_handler, $referred_entity_type, $referred_bundles) {
  $referred_entity_instances = field_info_instances($referred_entity_type);

  $limit_fields = array_filter($filter_handler->options['options_limit_fields']);
  //dsm($limit_fields);

  $match_columns = array();
  $match_values = array();
  foreach ($limit_fields as $key) {
    // Split the checkbox key back into handler type and handler id.
    list($handler_type, $handler_id) = explode(':', $key);
    // Retrieve the handler.
    $handler = $filter_handler->view->display_handler->get_handler($handler_type, $handler_id);
    $field_name_matching = $handler->definition['field_name'];
    // Build up a nice array for later.
    $fields_match[$field_name_matching] = $handler;
    // Buid up an array of values to match on, initialized as empty.
    $match_values[$field_name_matching] = '';
    //dsm($handler);

    // Here we probably need to switch out depending on whether we are:
    // a filter or an argument.

    // Case: filter.
    // This is the only one in my use case at the moment; if you want more
    // post a patch ;)
    if ($handler_type == 'filter') {
      if ($handler->options['exposed']) {
        // Exposed filter.
        // accept_exposed_input() has not yet been run on the handler at this
        // stage, so we need to get it from the view. Furthermore, we can't
        // call accept_exposed_input() ourselves as various other things it
        // expects haven't happened yet.
        $exposed_input = $handler->view->get_exposed_input();
        // This ends up as a nested array if the filter takes multiple values
        // but nothing further one seems to be bothered by it!
        if (isset($exposed_input[$handler->options['expose']['identifier']])) {
          $match_values[$field_name_matching] = array($exposed_input[$handler->options['expose']['identifier']]);
        }
      }
      else {
        // Non-exposed filter: grab the value from $handler->value.
        $match_values[$field_name_matching] = $handler->value;
      }
    }

    $field_info_matching = field_info_field($field_name_matching);
    // Get the list of columns we should be extracting from the form and
    // then matching on.
    $match_columns[$field_name_matching] = reference_option_limit_get_match_columns($field_info_matching);
  }

  // Build an EFQ.
  // @todo would be nice if we could share code with the main module here.

  // Get our entities to refer to.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $referred_entity_type);
  // Limit for all the referrable bundles.
  foreach ($referred_bundles as $bundle_name) {
    $query->entityCondition('bundle', $bundle_name);
  }
  // Limit for the matching field values.
  foreach ($fields_match as $field_name_matching => $handler) {
    // @todo: handle more than one column to match on.
    $column = $match_columns[$field_name_matching][0];
    $value = $match_values[$field_name_matching];
    if (!empty($value)) {
      $query->fieldCondition($field_name_matching, $column, $value, 'IN');
    }
  }
  // @todo: add some sort of ordering?
  // $query->fieldOrderBy('name', 'value', 'ASC') @todo! add some sort of ordering.
  $result = $query->execute();
  //dsm($result);

  // Load the resulting entities.
  if (!empty($result[$referred_entity_type])) {
    $entities = entity_load($referred_entity_type, array_keys($result[$referred_entity_type]));
  }
  else {
    $entities = array();
  }
  //dsm($entities);

  // Build an array of options.
  $options_limited = array();
  foreach ($entities as $entity) {
     list($id, $vid, $bundle) = entity_extract_ids($referred_entity_type, $entity);
     $options_limited[$id] = entity_label($referred_entity_type, $entity);
  }
  return $options_limited;
}
