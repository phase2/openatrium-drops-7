<?php

/**
 * Implements hook_form()
 *
 * This form builds a guided tour.
 * @param array $form
 * @param array $form_state
 * @return array
 */
function bootstrap_tour_configure_form($form, &$form_state) {
  $tour = null;
  if (is_numeric(arg(5)))
    $tour = _bootstrap_tour_get_data(arg(5));
  $options = _bootstrap_tour_generate_entity_selector();

  if (!isset($form_state['storage']['guided tours']['steps'])) {
    if (is_object($tour))
      $form_state['storage']['guided tours']['steps'] = count($tour->configuration['steps']);
    else
      $form_state['storage']['guided tours']['steps'] = 1;
  }

  if (!isset($form_state['storage']['guided tours']['tooltips'])) {
    if (is_object($tour)) {
      foreach ($tour->configuration['steps'] as $i => $step) {
        $form_state['storage']['guided tours']['tooltips'][$i] = count($step['tooltips']);
      }
    } else {
      $form_state['storage']['guided tours']['tooltips'][0] = 1;
    }
  }

  if (!isset($form_state['storage']['guided tours']['modified step']))
    $form_state['storage']['guided tours']['modified step'] = -1;

  if (!isset($form_state['storage']['guided tours']['modified tooltip']))
    $form_state['storage']['guided tours']['modified tooltip'] = -1;

  // Build steps and tooltips
  $steps = array();
  for ($i = 0; $i < $form_state['storage']['guided tours']['steps']; $i++) {
    $tooltips = array();

    // Determine wether this step has to be collapsed or not
    $step_collapsed = true;
    if ($i == $form_state['storage']['guided tours']['modified step'])
      $step_collapsed = false;

    // Build tooltips for specific step
    for ($o = 0; $o < $form_state['storage']['guided tours']['tooltips'][$i]; $o++) {

      // Determine wether or not this tooltip has to be collapsed or not
      $tooltip_collapsed = true;
      if ($i == $form_state['storage']['guided tours']['modified step'] && $o == $form_state['storage']['guided tours']['modified tooltip'])
        $tooltip_collapsed = true;

      // Build tooltip
      $tooltips[$o] = array(
        '#type' => 'fieldset',
        '#collapsible' => true,
        '#collapsed' => $tooltip_collapsed,
        '#title' => t('Tooltip #!number', array('!number' => $o + 1)),
        'content' => array(
          '#type' => 'textarea',
          '#title' => t('Content'),
          '#description' => t('The content of the tooltip. Can contain HTML.'),
          '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['content'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['content'] : '',
        ),
        'selector' => array(
          '#type' => 'textfield',
          '#title' => t('Selector for target element'),
          '#description' => t('The selector for the target element as used in jQuery().'),
          '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['selector'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['selector'] : '',
        ),
        'position_on_tooltip' => array(
          '#type' => 'textfield',
          '#title' => t('Position of arrow on tooltip'),
          '#description' => t('See <a href="@url">qTip2 documentation</a> for possible values!', array('@url' => url('http://craigsworks.com/projects/qtip2/docs/position/#my'))),
          '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['position_on_tooltip'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['position_on_tooltip'] : 'top center',
        ),
        'position_on_target' => array(
          '#type' => 'textfield',
          '#title' => t('Position of arrow on target element'),
          '#description' => t('See <a href="@url">qTip2 documentation</a> for possible values!', array('@url' => url('http://craigsworks.com/projects/qtip2/docs/position/#at'))),
          '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['position_on_target'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['position_on_target'] : 'bottom center',
        ),
        'fixed' => array(
          '#type' => 'radios',
          '#title' => t('Tooltip has property "fixed"'),
          '#description' => t('Wether or not the tooltip is "fixed" on the page. If it is not fixed, it moves with the content.'),
          '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['fixed'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['fixed'] : 0,
          '#options' => array(
            1 => t('Yes'),
            0 => t('No'),
          ),
        ),
        'hide_on_click' => array(
          '#type' => 'radios',
          '#title' => t('Tooltip hides on click'),
          '#description' => t('Wether or not the tooltip hides if clicked.'),
          '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['hide_on_click'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['hide_on_click'] : 0,
          '#options' => array(
            1 => t('Yes'),
            0 => t('No'),
          ),
        ),
        'dynamic' => array(
          '#type' => 'fieldset',
          '#title' => t('Dynamic behaviour'),
          '#collapsible' => true,
          '#collapsed' => true,
          'enabled' => array(
            '#type' => 'radios',
            '#title' => t('Enable dynamic behaviour?'),
            '#description' => t('Be aware that the position of the arrow on the tooltip can not be changed due to limitations in qTip.'),
            '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['enabled'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['enabled'] : 0,
            '#options' => array(
              1 => t('Yes'),
              0 => t('No'),
            ),
          ),
          'event' => array(
            '#type' => 'textfield',
            '#title' => t('Event'),
            '#description' => t('Event on the original element on which the tooltip should move to another element.'),
            '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['event'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['event'] : '',
          ),
          'content' => array(
            '#type' => 'textarea',
            '#title' => t('Content after event'),
            '#description' => t('The content of the tooltip after the event. Can contain HTML.'),
            '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['content'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['content'] : '',
          ),
          'selector' => array(
            '#type' => 'textfield',
            '#title' => t('Selector for target of new element'),
            '#description' => t('The selector for the new target element after the event as used in jQuery().'),
            '#default_value' => (isset($tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['selector'])) ? $tour->configuration['steps'][$i]['tooltips'][$o]['dynamic']['selector'] : '',
          ),
        )
      );
    }

    // Build step
    if ($i == 0) {
      $steps[$i]['location'] = array(
        '#type' => 'fieldset',
        '#collapsible' => true,
        '#title' => t('Location of that step'),
        'disclaimer' => array(
          '#type' => 'item',
          '#markup' => t('The location of the first step is always the homepage of drupal.'),
        ),
      );
    } else {
      $steps[$i]['location'] = array(
        '#type' => 'fieldset',
        '#collapsible' => true,
        '#title' => t('Location of that step'),
        '#description' => t('Set on which location this step shall occurr. Either you can choose the entity type (and appropriate bundle) or you can provide a regular expression that matches the locations address.'),
        'switch' => array(
          '#type' => 'radios',
          '#options' => array(
            'entity' => t('Entity type (and bundle)'),
            'address' => t('Address')
          ),
          '#default_value' => (isset($tour->configuration['steps'][$i]['location']['switch'])) ? $tour->configuration['steps'][$i]['location']['switch'] : 'address',
          '#description' => t('Select which method you want to use!'),
          '#title' => t('Location switch'),
        ),
        'entity' => array(
          '#type' => 'select',
          '#title' => t('Entity type (and bundle)'),
          '#description' => t('You can either just choose an entity type or you can be more specific by selecting a specific bundle of an entity type.'),
          '#options' => $options,
          '#default_value' => (isset($tour->configuration['steps'][$i]['location']['entity'])) ? $tour->configuration['steps'][$i]['location']['entity'] : 'ignore',
        ),
        'address' => array(
          '#type' => 'textfield',
          '#title' => t('Address'),
          '#description' => t('A regular expression that matches the address on which this step shall occurr. See <a href="@url">PHP documentation</a> for syntax!', array('@url' => url('http://de3.php.net/manual/en/function.preg-match.php'))),
          '#default_value' => (isset($tour->configuration['steps'][$i]['location']['address'])) ? $tour->configuration['steps'][$i]['location']['address'] : '',
        ),
      );
    }

    $steps[$i] += array(
      '#type' => 'fieldset',
      '#collapsible' => true,
      '#collapsed' => $step_collapsed,
      '#title' => t('Step #!number', array('!number' => $i + 1)),
      '#required' => true,
      'tooltips' => $tooltips,
      'add-tooltip-' . $i => array(
        '#type' => 'submit',
        '#value' => t('Add tooltip to step #!amount', array('!amount' => $i + 1)),
        '#submit' => array('bootstrap_tour_configure_add_tooltip_submit'),
        '#ajax' => array(
          'callback' => '_bootstrap_tour_configure_rebuild_configuration',
          'effect' => 'fade',
          'method' => 'replace',
          'progress' => array(
            'type' => 'throbber',
          ),
          'wrapper' => 'guided-tours-step-rapper',
        ),
        '#attributes' => array('style' => 'background: #0a0; color: #fff;'),
      ),
    );

    // Add "remove tooltip" button if needed
    if (count(element_children($steps[$i]['tooltips'])) > 1)
      $steps[$i]['remove-tooltip-' . $i] = array(
        '#type' => 'submit',
        '#value' => t('Remove last tooltip from step #!amount', array('!amount' => $i + 1)),
        '#submit' => array('bootstrap_tour_configure_remove_tooltip_submit'),
        '#ajax' => array(
          'callback' => '_bootstrap_tour_configure_rebuild_configuration',
          'effect' => 'fade',
          'method' => 'replace',
          'progress' => array(
            'type' => 'throbber',
          ),
          'wrapper' => 'guided-tours-step-rapper',
        ),
        '#attributes' => array('style' => 'background: #a00; color: #fff;'),
      );
  }

  // Build form
  $form = array(
    'title' => array(
      '#type' => 'textfield',
      '#title' => t('Title of guided tour'),
      '#required' => true,
    ),
    'visible' => array(
      '#type' => 'radios',
      '#title' => t('Visibility of guided tour'),
      '#options' => array(1 => t('Visible'), 0 => t('Invisible')),
      '#description' => t('Wether the tour is visible or not.'),
      '#default_value' => 0,
      '#required' => true,
    ),
    'description' => array(
      '#type' => 'textarea',
      '#title' => t('Description of guided tour'),
    ),
    'configuration' => array(
      '#type' => 'fieldset',
      '#collapsible' => true,
      '#title' => t('Configuration'),
      '#prefix' => '<div class="clearfix" id="guided-tours-step-rapper">',
      '#suffix' => '</div>',
      '#required' => true,
      '#tree' => true,
      'steps' => $steps,
      'add_step' => array(
        '#type' => 'submit',
        '#value' => t('Add step'),
        '#submit' => array('bootstrap_tour_configure_add_step_submit'),
        '#ajax' => array(
          'callback' => '_bootstrap_tour_configure_rebuild_configuration',
          'effect' => 'fade',
          'method' => 'replace',
          'progress' => array(
            'type' => 'throbber',
          ),
          'wrapper' => 'guided-tours-step-rapper',
        ),
        '#attributes' => array('style' => 'background: #0a0; color: #fff;'),
      ),
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save'),
    ),
  );

  // Add "remove step" button if needed
  if (count(element_children($form['configuration']['steps'])) > 1)
    $form['configuration']['remove_step'] = array(
      '#type' => 'submit',
      '#value' => t('Remove step'),
      '#submit' => array('bootstrap_tour_configure_remove_step_submit'),
      '#ajax' => array(
        'callback' => '_bootstrap_tour_configure_rebuild_configuration',
        'effect' => 'fade',
        'method' => 'replace',
        'progress' => array(
          'type' => 'throbber',
        ),
        'wrapper' => 'guided-tours-step-rapper',
      ),
      '#attributes' => array('style' => 'background: #a00; color: #fff;'),
    );

  if (isset($tour) && is_object($tour)) {
    $form['title']['#default_value'] = $tour->title;
    $form['description']['#default_value'] = $tour->description;
    $form['visible']['#default_value'] = $tour->visible;
  }

  return $form;
}

/**
 * Adds a tooltip to the configuration form
 * @param array $form
 * @param array $form_state
 */
function bootstrap_tour_configure_add_tooltip_submit($form, &$form_state) {
  // Determine correct step
  $values = explode('-', end($form_state['clicked_button']['#array_parents']));
  $step = $values[2];

  // Increase the amount of tooltips
  $form_state['storage']['guided tours']['tooltips'][$step]++;

  // Signalize Drupal to rebuild the form
  $form_state['rebuild'] = true;

  $form_state['storage']['guided tours']['modified step'] = $step;
  $form_state['storage']['guided tours']['modified tooltip'] = $form_state['storage']['guided tours']['tooltips'][$step] - 1;
}

/**
 * Remove a tooltip from the configuration form
 * @param array $form
 * @param array $form_state
 */
function bootstrap_tour_configure_remove_tooltip_submit($form, &$form_state) {
  // Determine correct step
  $values = explode('-', end($form_state['clicked_button']['#array_parents']));
  $step = $values[2];

  // Decrease the amount of tooltips
  if ($form_state['storage']['guided tours']['tooltips'][$step] > 1)
    $form_state['storage']['guided tours']['tooltips'][$step]--;

  // Signalize Drupal to rebuild the form
  $form_state['rebuild'] = true;

  $form_state['storage']['guided tours']['modified step'] = $step;
  $form_state['storage']['guided tours']['modified tooltip'] = $form_state['storage']['guided tours']['tooltips'][$step] - 1;
}

/**
 * Add a step to the configuration form
 * @param array $form
 * @param array $form_state
 */
function bootstrap_tour_configure_add_step_submit($form, &$form_state) {
  // Increase the amount of steps
  $form_state['storage']['guided tours']['tooltips'][$form_state['storage']['guided tours']['steps']] = 1;
  $form_state['storage']['guided tours']['steps']++;

  // Signalize Drupal to rebuild the form
  $form_state['rebuild'] = true;

  $form_state['storage']['guided tours']['modified step'] = $form_state['storage']['guided tours']['steps'] - 1;
}

/**
 * Remove a step from the configuration form
 * @param array $form
 * @param array $form_state
 */
function bootstrap_tour_configure_remove_step_submit($form, &$form_state) {
  // Decrease the amount of steps
  if ($form_state['storage']['guided tours']['steps'] > 1)
    $form_state['storage']['guided tours']['steps']--;
  unset($form_state['storage']['guided tours']['tooltips'][$form_state['storage']['guided tours']['steps']]);

  // Signalize Drupal to rebuild the form
  $form_state['rebuild'] = true;

  $form_state['storage']['guided tours']['modified step'] = $form_state['storage']['guided tours']['steps'] - 1;
}

/**
 * Return the new build configuration part of the form
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _bootstrap_tour_configure_rebuild_configuration(&$form, &$form_state) {
  return $form['configuration'];
}

/**
 * Save the contents of the configuration form
 * @param array $form
 * @param array $form_state
 */
function bootstrap_tour_configure_form_submit($form, &$form_state) {
  $tour_record = array(
    'title' => $form_state['values']['title'],
    'description' => $form_state['values']['description'],
    'visible' => $form_state['values']['visible'],
    'configuration' => $form_state['values']['configuration'],
  );

  if (is_object(_bootstrap_tour_get_data(arg(5)))) {
    // Update the data of the tour
    $tour_record['tour_id'] = arg(5);

    drupal_write_record('bootstrap_tour', $tour_record, array('tour_id'));
    drupal_set_message('Tour data was updated successfully!');
  } else {
    // Create a new tour
    drupal_write_record('bootstrap_tour', $tour_record);
    drupal_set_message('Tour has been created!');
  }

  drupal_goto('admin/config/content/bootstrap_tour/configure_tour/' . $tour_record['tour_id']);
}

/**
 * Generates a structured array of entity types (and bundles) for use in the form api as a selector
 * @return array
 */
function _bootstrap_tour_generate_entity_selector() {
  $entities = array();
  $_options = array();

  foreach (entity_get_info() as $entity_id => $entity_info) {
    $entities[$entity_id] = $entity_info['label'];

    if (count($entity_info['bundles']) > 1) {
      foreach ($entity_info['bundles'] as $bundle_id => $bundle_info) {
        $_options[$entity_info['label']][$entity_id . ':' . $bundle_id] = $bundle_info['label'];
      }
      asort($_options[$entity_info['label']]);
    }
  }

  ksort($_options);
  asort($entities);

  $options = array(
    'ignore' => '<ignore>',
    t('Entities') => $entities,
    ) + $_options;

  return $options;
}

/**
 * Administrative list of guided tours with statistics
 * @return string
 */
function _bootstrap_tour_list_tours() {
  $tours = _bootstrap_tour_get_data();

  // Check if we have guided tours in the database
  if (count($tours) > 0) {
    $rows = array();

    // Add the tours' data as rows to the table
    foreach ($tours as $tour) {
      $rows[] = array(
        l($tour->title, 'admin/config/content/bootstrap_tour/configure_tour/' . $tour->tour_id) . '<br />' . $tour->description,
        $tour->visible ? t('Yes') : t('No'),
        $tour->start_count,
        $tour->finish_count,
        (($tour->start_count > 0) ? round($tour->finish_count / $tour->start_count * 100, 2) : 0) . '%',
      );
    }

    $return = theme_table(array(
      'header' => array(t('Title/Description'), t('Visible'), t('Started'), t('Finished'), t('Ratio')),
      'rows' => $rows,
      'attributes' => array(),
      'caption' => '',
      'colgroups' => array(),
      'sticky' => true,
      'empty' => '',
    ));
  } else {
    $return = '<h2>' . t('No tours in the database!') . '</h2>';
  }

  return $return;
}

/**
 * Allows to administer the basic settings for guided tours
 * @return type
 */
function bootstrap_tour_settings_form() {
  $options = array(
    0 => t('None')
  );

  $tours = _bootstrap_tour_get_data();

  if (count($tours) > 0) {
    foreach ($tours as $tour) {
      $options[$tour->tour_id] = $tour->title;
    }
  }

  return array(
    'behaviour' => array(
      '#type' => 'fieldset',
      '#title' => t('Behaviour on user login'),
      '#collapsible' => true,
      '#collapsed' => true,
      'obligatory' => array(
        '#type' => 'select',
        '#title' => t('Obligatory guided tour'),
        '#options' => $options,
        '#default_value' => (int) variable_get('bootstrap_tour obligatory_tour', 0),
        '#description' => t('Please choose the tour that shall be obligatory for all users that log in and haven\'t seen that tour so far!'),
      ),
      'description' => array(
        '#type' => 'textarea',
        '#title' => t('Description'),
        '#default_value' => variable_get('bootstrap_tour obligatory_tour description', ''),
        '#description' => t('Short text that explains the user why this specific tour has been started automatically for him.')
      ),
      'intrusive' => array(
        '#type' => 'radios',
        '#title' => t('Kind of behaviour?'),
        '#description' => t('Wether or not the guided tour shall be intrusively obgligatory or simply informatively.'),
        '#default_value' => (int) variable_get('bootstrap_tour obligatory_tour intrusive', false),
        '#options' => array(
          1 => t('Intrusive'),
          0 => t('Informative'),
        ),
      ),
    ),
    'additional classes' => array(
      '#type' => 'fieldset',
      '#title' => t('Additional classes'),
      '#collapsible' => true,
      '#collapsed' => true,
      'tour_additional_classes' => array(
        '#type' => 'textarea',
        '#title' => t('Additional classes for tour tooltips'),
        '#default_value' => variable_get('bootstrap_tour tour_additional_classes', ''),
        '#description' => t('A list of additional classes that shall be applied to tooltips of guided tours.')
      ),
      'dialog_additional_classes' => array(
        '#type' => 'textarea',
        '#title' => t('Additional classes for dialogs'),
        '#default_value' => variable_get('bootstrap_tour dialog_additional_classes', ''),
        '#description' => t('A list of additional classes that shall be applied to dialogs.')
      ),
      'button_additional_classes' => array(
        '#type' => 'textarea',
        '#title' => t('Additional classes for buttons in dialogs'),
        '#default_value' => variable_get('bootstrap_tour button_additional_classes', ''),
        '#description' => t('A list of additional classes that shall be applied to buttons in dialogs.')
      ),
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('save'),
    ),
  );
}

/**
 * Submit handler for settings form
 * @param stdClass $form
 * @param stdClass $form_state
 */
function bootstrap_tour_settings_form_submit($form, &$form_state) {
  $form_state = $form_state;

  variable_set('bootstrap_tour obligatory_tour', (int) $form_state['values']['obligatory']);
  variable_set('bootstrap_tour obligatory_tour description', (string) $form_state['values']['description']);
  variable_set('bootstrap_tour obligatory_tour intrusive', (bool) $form_state['values']['intrusive']);
  variable_set('bootstrap_tour tour_additional_classes', (string) $form_state['values']['tour_additional_classes']);
  variable_set('bootstrap_tour dialog_additional_classes', (string) $form_state['values']['dialog_additional_classes']);
  variable_set('bootstrap_tour button_additional_classes', (string) $form_state['values']['button_additional_classes']);
  drupal_set_message('Settings saved!');
}