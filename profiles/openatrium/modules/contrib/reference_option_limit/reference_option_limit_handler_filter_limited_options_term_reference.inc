<?php
/**
 * Filter handler for taxonomy term reference fields with option limiting.
 *
 * Provides broadly the same functionality as in the entity form, with some
 * differences and limitations due to being in a multi-entity situation here.
 *
 * In the admin options for this handler we look at the FieldAPI option limited
 * field this handler is a filter for, find all instances of it on the entity
 * this view has as its base, and from that get a list of matching fields. We
 * then examine this view's filter and argument handlers to see if any of them
 * represent any of the matching fields. Those that do are presented as options
 * to select from: these are thus matching handlers.
 *
 * When the filter's exposed form is rendered, values are taken from the
 * matching handlers and used to build the Entity Field Query to get the
 * options for the exposed form.
 */
class reference_option_limit_handler_filter_limited_options_term_reference extends views_handler_filter_term_node_tid {
  function option_definition() {
    $options = parent::option_definition();

    // Override the default value for 'type': we don't support autocomplete.
    $options['type'] = array('default' => 'select');

    $options['options_limit_fields'] = array('default' => array());

    return $options;
  }

  /**
   * Extend and doctor the options form.
   */
  function extra_options_form(&$form, &$form_state) {
    parent::extra_options_form($form, $form_state);

    // Lock the selection type.
    $form['type']['#disabled'] = TRUE;
    $form['type']['#description'] = t('This filter must be a dropdown.');

    // Get values specific to taxonomy term ref fields.
    $referred_entity_type = 'taxonomy_term';
    $referred_bundles = array($this->options['vocabulary']);

    // Get the filter and argument handlers we can match on from our helper.
    $options = reference_option_limit_views_handler_filter_get_matched_field_options($this, $referred_entity_type, $referred_bundles);

    $form['options_limit_fields'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Matching fields'),
      '#options' => $options,
      // Add to docs: Because we can't know which entity type(s) are being shown
      // we may show irrelevant fields here.
      '#description' => t('Select the filters whose values should limit the available values of this filter. Note that some combinations of options will not work eg selecting the same field representation as both a filter and a contextual filter.'),
      '#default_value' => $this->options['options_limit_fields'],
    );
  }

  /**
   * Provide our own limited options in the value form.
   */
  function value_form(&$form, &$form_state) {
    // Get values specific to taxonomy term ref fields.
    $vocabulary = taxonomy_vocabulary_machine_name_load($this->options['vocabulary']);
    $referred_entity_type = 'taxonomy_term';
    $referred_bundles = array($this->options['vocabulary']);

    // Get the options for the value form.
    $options = reference_option_limit_views_handler_filter_get_value_options($this, $referred_entity_type, $referred_bundles);

    // Gacked from parent class.
    $default_value = (array) $this->value;
    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];

      if (!empty($this->options['expose']['reduce'])) {
        $options = $this->reduce_value_options($options);

        if (!empty($this->options['expose']['multiple']) && empty($this->options['expose']['required'])) {
          $default_value = array();
        }
      }

      if (empty($this->options['expose']['multiple'])) {
        if (empty($this->options['expose']['required']) && (empty($default_value) || !empty($this->options['expose']['reduce']))) {
          $default_value = 'All';
        }
        elseif (empty($default_value)) {
          $keys = array_keys($options);
          $default_value = array_shift($keys);
        }
        else {
          $copy = $default_value;
          $default_value = array_shift($copy);
        }
      }
    }

    $form['value'] = array(
      '#type' => 'select',
      '#title' => $this->options['limit'] ? t('Select terms from vocabulary @voc', array('@voc' => $vocabulary->name)) : t('Select terms'),
      '#multiple' => TRUE,
      '#options' => $options,
      '#size' => min(9, count($options)),
      '#default_value' => $default_value,
    );
  }
}
