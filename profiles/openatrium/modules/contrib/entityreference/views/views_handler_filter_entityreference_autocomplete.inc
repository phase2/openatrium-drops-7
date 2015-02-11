<?php

/**
 * Filter by entity id with an autocomplete widget.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_entityreference_autocomplete extends views_handler_filter_many_to_one {
  // Stores the exposed input for this filter.
  var $validated_exposed_input = NULL;

  function init(&$view, &$options) {
    parent::init($view, $options);
    // Find field info
    $field = field_info_field($this->definition['field_name']);
    $this->field = $this->definition['field_name'];
    $this->target_type = $field['settings']['target_type'];
  }

  function value_form(&$form, &$form_state) {
    $default = '';
    if ($this->value) {
      $entities = entity_load($this->target_type, $this->value);
      foreach ($entities as $entity) {
        if ($default) {
          $default .= ', ';
        }
        $default .= entity_label($this->target_type, $entity) . ' (' . entity_id($this->target_type, $entity) . ')';
      }
    }

    // Sniff out the entity and bundle this appears on - there's probably a
    // nicer way of doing this but for now we'll take the first instance we
    // find of the field and use that. This should be ok, because allowed
    // bundles are usually set as field settings.
    $instances = field_read_instances(array('field_name' => $this->definition['field_name']));
    $instance = reset($instances);

    if($this->options['expose']['multiple'] == 1) {
      $autocomplete_path = 'entityreference/autocomplete/tags/';
    } else {
      $autocomplete_path = 'entityreference/autocomplete/single/';
    }
    $autocomplete_path .= $this->definition['field_name'] . '/' . $instance['entity_type'] . '/' . $instance['bundle'] . '/NULL';

    $form['value'] = array(
      '#title' => t('Select entities'),
      '#type' => 'textfield',
      '#default_value' => $default,
      '#autocomplete_path' => $autocomplete_path,
      '#element_validate' => array('_entityreference_autocomplete_tags_validate'),
    );

    if (empty($form_state['exposed'])) {
      // Retain
      $this->helper->options_form($form, $form_state);
    }
  }

  function value_validate($form, &$form_state) {
    foreach ($form_state['values']['options']['value'] as $array) {
      $values[] = $array['target_id'];
    }

    $form_state['values']['options']['value'] = $values;
  }

  function accept_exposed_input($input) {
    if (empty($this->options['exposed'])) {
      return TRUE;
    }

    // If view is an attachment and is inheriting exposed filters, then assume
    // exposed input has already been validated
    if (!empty($this->view->is_attachment) && $this->view->display_handler->uses_exposed()) {
      $this->validated_exposed_input = (array) $this->view->exposed_raw_input[$this->options['expose']['identifier']];
    }

    // If it's non-required and there's no value don't bother filtering.
    if (!$this->options['expose']['required'] && empty($this->validated_exposed_input)) {
      return FALSE;
    }

    $accepted = parent::accept_exposed_input($input);
    if ($accepted) {
      // If we have previously validated input, override.
      if (isset($this->validated_exposed_input)) {
        $this->value = $this->validated_exposed_input;
      }
    }

    return $accepted;
  }

  function exposed_validate(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }

    if (empty($this->options['expose']['identifier'])) {
      return;
    }

    $identifier = $this->options['expose']['identifier'];

    foreach ($form_state['values'][$identifier] as $array) {
      $values[] = $array['target_id'];
    }
    //$eids = $this->validate_entity_labels($form[$identifier], $form, $form_state, $values);
    if (!empty($values)) {
      $this->validated_exposed_input = $values;
    }
  }
}
