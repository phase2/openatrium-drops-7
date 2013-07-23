<?php
/**
 * @file
 * Defines the iCal Fields row style plugin, which lets users map view fields
 * to the components of the VEVENTs in the iCal feed.
 */

/**
 * Plugin which creates a view on the resulting object
 * and formats it as an iCal VEVENT.
 */
class date_ical_plugin_row_ical_fields extends views_plugin_row {

  function option_definition() {
    $options = parent::option_definition();
    $options['date_field'] = array('default' => '');
    $options['title_field'] = array('default' => '');
    $options['description_field'] = array('default' => '');
    $options['location_field'] = array('default' => '');
    $options['additional_settings']['skip_blank_dates'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $blank_label = array('' => t('- None -'));
    $all_field_labels = $this->display->handler->get_field_labels();
    $date_field_labels = $this->get_date_field_candidates($all_field_labels);
    $date_field_label_options = array_merge($blank_label, $date_field_labels);
    $text_field_label_options = array_merge($blank_label, $all_field_labels);
    
    $form['instructions'] = array(
      // The surrounding <div> is necessary to ensure that the settings dialog expands to show everything.
      '#prefix' => '<div style="font-size: 90%">',
      '#suffix' => '</div>',
      '#markup' => t("Before applying these settings, this view will need to be configured to load the fields you wish to map into the events in your iCal feed.
        If you have no fields to choose, you may want to click the X button in the upper-right to close this dialog."),
    );
    $form['date_field'] = array(
      '#type' => 'select',
      '#title' => t('Date field'),
      '#description' => t('The views field to use as the start (and possibly end) time for each event (DTSTART/DTEND).'),
      '#options' => $date_field_label_options,
      '#default_value' => $this->options['date_field'],
      '#required' => TRUE,
    );
    $form['title_field'] = array(
      '#type' => 'select',
      '#title' => t('Title field'),
      '#description' => t('The views field to use as the title for each event (SUMMARY).'),
      '#options' => $text_field_label_options,
      '#default_value' => $this->options['title_field'],
      '#required' => FALSE,
    );
    $form['description_field'] = array(
      '#type' => 'select',
      '#title' => t('Description field'),
      '#description' => t("The views field to use as the body text for each event (DESCRIPTION).<br>
          If you wish to include more than one entity field in the event body, you may want to use the 'Content: Rendered Node' views field,
          and set it to the 'iCal' view mode. Then configure the iCal view mode on your event nodes to include the text you want."),
      '#options' => $text_field_label_options,
      '#default_value' => $this->options['description_field'],
      '#required' => FALSE,
    );
    $form['location_field'] = array(
      '#type' => 'select',
      '#title' => t('Location field'),
      '#description' => t('(optional) The views field to use as the location for each event (LOCATION).'),
      '#options' => $text_field_label_options,
      '#default_value' => $this->options['location_field'],
      '#required' => FALSE,
    );
    $form['additional_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Additional settings'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    );
    $form['additional_settings']['skip_blank_dates'] = array(
      '#type' => 'checkbox',
      '#title' => t('Skip blank dates'),
      '#description' => t('Normally, if a view result has a blank date field, the feed will display an error,
        because it is impossible to create an iCal event with no date. This option makes Views silently skip those results, instead.'),
      '#default_value' => $this->options['additional_settings']['skip_blank_dates'],
    );
  }
  
  function pre_render($result) {
    // Get the language for this view.
    $this->language = $this->display->handler->get_option('field_language');
    $substitutions = views_views_query_substitutions($this->view);
    if (array_key_exists($this->language, $substitutions)) {
      $this->language = $substitutions[$this->language];
    }
  }
  
  /**
   * Returns an Event array based on the query result from the view whose index is
   * specified in the (hidden) second parameter of this function.
   */
  function render($row) {
    // Using func_get_args() instead of declaring $row_index in the arguments,
    // because this function must be compatible with views_plugin_row::render().
    $args = func_get_args();
    $row_index = $args[1];
    
    // Fetch the event's date information.
    try {
      $date = $this->get_row_date($row_index);
    }
    catch (BlankDateFieldException $e) {
      if ($this->options['additional_settings']['skip_blank_dates']) {
        return NULL;
      }
      else {
        throw $e;
      }
    }
    
    $event = array();
    // Add the LAST-MODIFIED and URL components based on the original entity.
    $entity = $row->_field_data[$this->view->base_field]['entity'];
    $entity_type = $row->_field_data[$this->view->base_field]['entity_type'];
    if (isset($entity->changed)) {
      $event['last-modified'] = new DateObject($entity->changed, new DateTimeZone('UTC'));
    }
    $uri = entity_uri($entity_type, $entity);
    $uri['options']['absolute'] = TRUE;
    $event['url'] = url($uri['path'], $uri['options']);

    // Generate a uid.
    $domain = check_plain($_SERVER['SERVER_NAME']);
    $event['uid'] = "calendar." . $row->{$this->view->base_field} . "." . $this->options['date_field'] . "@" . $domain;

    // Create the primary text fields.
    $text_fields['summary'] = $this->get_field($row_index, $this->options['title_field']);
    $text_fields['description'] = $this->get_field($row_index, $this->options['description_field']);
    $text_fields['location'] = $this->get_field($row_index, $this->options['location_field']);
    
    // Allow other modules to alter the rendered text fields before they get
    // sanitized for iCal-compliance. This is most useful for fields of type
    // "Content: Rendered Node", which are likely to have complex HTML.
    $context = array(
      'row' => $row,
      'row_index' => $row_index,
      'language' => $this->language,
    );
    drupal_alter('date_ical_fields_html', $text_fields, $this->view, $context);
    
    // Sanitize the text fields for iCal compliance, and add them to the event.
    // Also strip all HTML from the summary and location fields, since they
    // must be plaintext, and may have been set as links by the view.
    $event['summary'] = date_ical_sanitize_text(strip_tags($text_fields['summary']));
    $event['location'] = date_ical_sanitize_text(strip_tags($text_fields['location']));
    $event['description'] = date_ical_sanitize_text($text_fields['description']);
    
    // Add the date data.
    $event = array_merge($event, $date);
    
    // Allow other modules to alter the event object, before it gets passed to
    // the style plugin to be converted into an iCal VEVENT.
    $context = array(
      'entity' => $entity,
      'entity_type' => $entity_type,
      'language' => $this->language,
    );
    drupal_alter('date_ical_feed_event_render', $event, $this->view, $context);
    
    return $event;
  }

  /**
   * Returns an normalized array for the current row's datefield/timestamp.
   *
   * @param object $row
   *   The current row object.
   * @param int $row_index
   *   The current row index.
   *
   * @return array
   *   The normalized array.
  */
  function get_row_date($row_index) {
    // Fetch the date field value.
    $date_field_value = $this->view->style_plugin->get_field_value($row_index, $this->options['date_field']);

    $start = NULL;
    $end   = NULL;
    $rrule = NULL;
    $delta = 0;
    $is_date_field = FALSE;

    // Handle date fields.
    if (isset($date_field_value[$delta]) && is_array($date_field_value[$delta])) {
      $is_date_field = TRUE;
      $date_field = $date_field_value[$delta];

      $start = new DateObject($date_field['value'], $date_field['timezone_db']);
      if (array_key_exists('value2', $date_field)) {
        $end = new DateObject($date_field['value2'], $date_field['timezone_db']);
      }
      else {
        $end = clone $start;
      }
      
      if (isset($date_field['rrule'])) {
        $rrule = $date_field['rrule'];
      }
    }
    elseif (is_numeric($date_field_value)) {
      // Handle timestamps, which are always saved in UTC.
      $start = new DateObject($date_field_value, 'UTC');
      $end   = new DateObject($date_field_value, 'UTC');
    }
    else {
      // Handle rows with blank date values.
      $title = strip_tags($this->view->style_plugin->get_field($row_index, $this->options['title_field']));
      throw new BlankDateFieldException("The row '$title' has a blank date. An iCal entry cannot be created for it.");
    }

    // Set the display timezone to whichever tz is stored for this field.
    // If there isn't a stored TZ, use the site default.
    $timezone = isset($date_field['timezone']) ? $date_field['timezone'] : date_default_timezone(FALSE);
    $start->setTimezone(new DateTimeZone($timezone));
    $end->setTimezone(new DateTimeZone($timezone));

    $granularity = 'second';
    if ($is_date_field) {
      $granularity_settings = $this->view->field[$this->options['date_field']]->field_info['settings']['granularity'];
      $granularity = date_granularity_precision($granularity_settings);
    }

    // Check if the start and end dates indicate that this is an All Day event.
    $all_day = date_is_all_day(
      date_format($start, DATE_FORMAT_DATETIME),
      date_format($end, DATE_FORMAT_DATETIME),
      $granularity
    );

    if ($all_day) {
      // According to RFC 2445 (clarified in RFC 5545) the DTEND value is
      // non-inclusive. When dealing with All Day values, they are DATEs rather
      // than DATETIMEs, so we need to add a day to conform to RFC.
      $end->modify("+1 day");
    }

    $date = array(
      'start' => $start,
      'end' => $end,
      'all_day' => $all_day,
      'rrule' => $rrule,
    );

    return $date;
  }

  /**
   * Filter the list of views fields down to only those which are supported date-type fields.
   * At this time, the supported date-type fields are timestamps and the three Date fields.
   *
   * @param array $view_fields
   *   An key=>value array @see views_plugin_display::get_field_labels().
   *
   * @return array
   *   An key=>value array (alias => label) of date fields.
   */
  function get_date_field_candidates($view_fields) {
    $handlers = $this->display->handler->get_handlers('field');
    $field_candidates = array();
    foreach ($view_fields as $alias => $label) {
      $handler = $handlers[$alias];
      if (get_class($handler) == 'views_handler_field_date'
        || (get_class($handler) == 'views_handler_field_field' &&
          // These are Date, Date (ISO format), and Date (Unix timestamp).
          in_array($handler->field_info['type'], array('datetime', 'date', 'datestamp')))) {
        $field_candidates[$alias] = $label;
      }
    }
    return $field_candidates;
  }

  /**
   * Retrieves a field value from the style plugin.
   *
   * @param int $index
   *   The index count of the row @see views_plugin_style::get_field().
   * @param string $field_id
   *   The ID assigned to the required field in the display.
   */
  function get_field($index, $field_id) {
    if (empty($this->view->style_plugin) || !is_object($this->view->style_plugin) || empty($field_id)) {
      return '';
    }
    return $this->view->style_plugin->get_field($index, $field_id);
  }
}
