<?php

/**
 * @file
 * Views style plugin for the Date iCal module.
 */

/**
 * Default style plugin to render an iCal feed.
 */
class date_ical_plugin_style_ical_feed extends views_plugin_style {
  
  function _get_option($option_name) {
    return isset($this->options[$option_name]) ? $this->options[$option_name] : '';
  }
  
  // Sets up the iCal feed icon on calendar pages.
  function attach_to($display_id, $path, $title) {
    $display = $this->view->display[$display_id]->handler;
    $url_options = array();
    $input = $this->view->get_exposed_input();
    if ($input) {
      $url_options['query'] = $input;
    }
    $url_options['absolute'] = TRUE;
    
    $url = url($this->view->get_url(NULL, $path), $url_options);
    // If the user didn't disable the option, change the scheme to webcal:// so
    // that calendar clients can automatically subscribe via the iCal link.
    if (!$this->_get_option('disable_webcal')) {
      $url = str_replace(array('http://', 'https://'), 'webcal://', $url);
    }
    
    // Render the feed icon and header tag (except during a View Preview).
    if (empty($this->view->live_preview)) {
      $tooltip = t('Add to My Calendar');
      $this->view->feed_icon .= theme('date_ical_icon', array('url' => check_url($url), 'tooltip' => $tooltip, 'view' => $this->view));
      drupal_add_html_head_link(array(
        'rel' => 'alternate',
        'type' => 'text/calendar',
        'title' => $tooltip,
        'href' => $url
      ));
    }
  }
  
  function option_definition() {
    $options = parent::option_definition();
    $options['cal_name'] = array('default' => array());
    $options['no_calname'] = array('default' => array());
    $options['disable_webcal'] = array('default' => array());
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    // Allow users to override the default Calendar name (X-WR-CALNAME).
    $form['cal_name'] = array(
      '#type' => 'textfield',
      '#title' => t('iCal Calendar Name'),
      '#default_value' => $this->_get_option('cal_name'),
      '#description' => t('This will appear as the title of the iCal feed. If ' .
        'left blank, the View Title will be used. If that is also blank, the site ' .
        'name will be inserted as the iCal feed title.'),
    );
    $form['no_calname'] = array(
      '#type' => 'checkbox',
      '#title' => t('Exclude Calendar Name'),
      '#default_value' => $this->_get_option('no_calname'),
      '#description' => t("Excluding the X-WR-CALNAME value from the iCal Feed causes
        some calendar clients to add the events in the feed to an existing calendar, rather
        than creating a whole new calendar for them."),
    );
    $form['disable_webcal'] = array(
      '#type' => 'checkbox',
      '#title' => t('Disable webcal://'),
      '#default_value' => $this->_get_option('disable_webcal'),
      '#description' => t("By default, the feed URL will use the webcal:// scheme, which allows calendar
        clients to easily subscribe to the feed. If you want your users to instead download this iCal
        feed as a file, activate this option."),
    );
  }
  
  function render() {
    if (empty($this->row_plugin) || !in_array($this->row_plugin->plugin_name, array('date_ical','date_ical_fields'))) {
      debug('views_plugin_style_ical_feed: This style plugin supports only iCal Entity row and iCal Fields plugins.', NULL, TRUE);
      return t('To enable iCal output, this view\'s Format must be configured to Show: iCal Entity or iCal Fields.');
    }
    if ($this->row_plugin->plugin_name == 'date_ical_fields' && (empty($this->row_plugin->options['date_field'])
        || empty($this->row_plugin->options['title_field']) || empty($this->row_plugin->options['description_field']))) {
      // Because these settings are marked as required in the form, this error state will rarely occur. But I ran across it during
      // testing, and the error that resulted was totally non-sensical, so I'm adding this in case it does ever happen.
      return t("When using the iCal Fields row plugin, the Date, Title, and Description fields are all required.
        Please set them up using the Settings link under 'Format -> Show: iCal Fields'.");
    }
    $events = array();
    foreach ($this->view->result as $row_index => $row) {
      $this->view->row_index = $row_index;
      try {
        $events[] = $this->row_plugin->render($row, $row_index);
      }
      catch (Exception $e) {
        debug($e->getMessage(), NULL, TRUE);
        return $e->getMessage();
      }
    }
    unset($this->view->row_index);
    
    // Try to load the iCalcreator library, and check if that worked.
    $library = libraries_load('iCalcreator');
    if (!empty($library['loaded'])) {
      // Create a vcalendar object using the iCalcreator library.
      $config = array('unique_id' => 'Drupal: Date iCal');
      $vcalendar = new vcalendar($config);
      $vcalendar->setMethod('PUBLISH');
      
      // If the iCal Calendar Name has been set in the Feed Style options, it's used as the
      // title in the iCal feed. If not, the View Title is used. If that is also blank, then
      // the Site Name is used.
      $cal_name = $this->_get_option('cal_name');
      if (empty($cal_name)) {
        $view_title = $this->view->get_title();
        if (!empty($view_title)) {
          $cal_name = $view_title;
        }
        else {
          $cal_name = variable_get('site_name', 'Drupal');
        }
      }
      // Only include the X-WR-CALNAME property if the user didn't check "Exclude Calendar Name".
      if (!$this->_get_option('no_calname')) {
        $vcalendar->setProperty('x-wr-calname', $cal_name, array('VALUE' => 'TEXT'));
      }
      
      // Now add the VEVENTs.
      $timezones = array();
      foreach ($events as $event) {
        if (empty($event)) {
          // The row plugin returned NULL for this row, which can happen due to
          // various error conditions. The only thing we can do is skip it.
          continue;
        }
        
        $vevent = $vcalendar->newComponent('vevent');
        // Get the start date as an array.
        $start = $event['start']->toArray();
        $timezone = $event['start']->getTimezone()->getName();
        $timezones[$timezone] = $timezone;
        
        if ($event['all_day']) {
          // All day events need to be specified as DATE, rather than DATE-TIME, or they get interpretted wrong.
          $vevent->setDtstart($start['year'], $start['month'], $start['day'],
            FALSE, FALSE, FALSE, FALSE, array('VALUE' => 'DATE'));
        }
        else {
          $vevent->setDtstart(
            $start['year'],
            $start['month'],
            $start['day'],
            $start['hour'],
            $start['minute'],
            $start['second'],
            $timezone);
        }
        
        // Add the Timezone info to the start date, for use later.
        $start['tz'] = $event['start']->getTimezone();
        
        // Only add the end date if there is one.
        if (!empty($event['end'])) {
          $end = $event['end']->toArray();
          $timezone = $event['start']->getTimezone()->getName();
          $timezones[$timezone] = $timezone;
          
          if ($event['all_day']) {
            $vevent->setDtend($end['year'], $end['month'], $end['day'],
              FALSE, FALSE, FALSE, FALSE, array('VALUE' => 'DATE'));
          }
          else {
            $vevent->setDtend(
              $end['year'],
              $end['month'],
              $end['day'],
              $end['hour'],
              $end['minute'],
              $end['second'],
              $timezone);
          }
          // Keep a copy of the end date, as it's useful later.
          $end['tz'] = $event['end']->getTimezone();
        }
        $vevent->setProperty('uid', $event['uid']);
        $vevent->setProperty('summary', $event['summary']);
        
        // Handle repeating dates from the date_repeat module.
        if (!empty($event['rrule']) && module_exists('date_repeat')) {
          // Split the rrule into the actual rule, exceptions and additions.
          list($rrule, $exceptions, $additions) = date_repeat_split_rrule($event['rrule']);
          // Add the rrule itself. We need to massage the data a bit, since iCalcreator expects RRULEs to be
          // in a different format than the Date API gives them to us.
          $rrule = self::convert_rrule_for_icalcreator($rrule);
          $vevent->setRrule($rrule);
          // Process exceptions if there are any.
          if (!empty($exceptions)) {
            $exdates = array();
            foreach ($exceptions as $exception) {
              $except = date_ical_date($exception, 'UTC');
              date_timezone_set($except, $start['tz']);
              $exception_array = $except->toArray();
              $exdates[] = array(
                'year' =>  $exception_array['year'],
                'month' => $exception_array['month'],
                'day' =>   $exception_array['day'],
                // Use the time information from the start date.
                'hour' =>   $start['hour'],
                'min' =>    $start['minute'],
                'second' => $start['second'],
                'tz' =>     $start['tz']->getName(),
              );
            }
            // Add those exclusions as 'EXDATE's.
            $vevent->setExdate($exdates);
          }
          // Process additions if there are any.
          if (!empty($additions)) {
            $add_dates = array();
            foreach ($additions as $addition) {
              $add = date_ical_date($addition, 'UTC');
              date_timezone_set($add, $start['tz']);
              $addition_array = $add->toArray();
              
              $add_date = array(
                'year' =>  $addition_array['year'],
                'month' => $addition_array['month'],
                'day' =>   $addition_array['day'],
                // Use the time information from the start date.
                'hour' =>   $start['hour'],
                'min' =>    $start['minute'],
                'second' => $start['second'],
                'tz' =>     $start['tz']->getName(),
              );
              // If there was an end date specified, use that too.
              if (!empty($event['end'])) {
                $add_date = array($add_date);
                $add_date[] = array(
                  'year' =>  $addition_array['year'],
                  'month' => $addition_array['month'],
                  'day' =>   $addition_array['day'],
                  // Use the time information from the end date.
                  'hour' =>   $end['hour'],
                  'min' =>    $end['minute'],
                  'second' => $end['second'],
                  'tz' =>     $end['tz']->getName(),
                );
              }
              
              $add_dates[] = $add_date;
            }
            // Add the additions as 'RDATE's.
            $vevent->setRdate($add_dates);
          }
        }
        if (!empty($event['url'])) {
          $vevent->setUrl($event['url'], array('type' => 'URI'));
        }
        if (!empty($event['location'])) {
          $vevent->setProperty('location', $event['location']);
        }
        if (!empty($event['description'])) {
          $vevent->setProperty('description', $event['description']);
        }
        if (!empty($event['last-modified'])) {
          $lm = $event['last-modified']->toArray();
          $vevent->setLastModified(
            $lm['year'],
            $lm['month'],
            $lm['day'],
            $lm['hour'],
            $lm['minute'],
            $lm['second'],
            $lm['timezone']
          );
        }
        
        // Allow other modules to alter the VEVENT object.
        drupal_alter('date_ical_feed_ical_vevent_render', $vevent, $this->view, $event);
      }
      
      // Now add all the timezones we just used to the calendar.
      foreach ($timezones as $timezone) {
        iCalUtilityFunctions::createTimezone($vcalendar, $timezone);
      }
      
      // Allow other modules to alter the calendar as a whole.
      drupal_alter('date_ical_feed_ical_vcalendar_render', $vcalendar, $this->view);
      
      $output = $vcalendar->createCalendar();
    }
    else {
      // The iCalcreator library isn't available, so we can't output anything.
      $output = 'Please install the iCalcreator library to enable iCal output.';
    }
    
    // These steps shouldn't be run when doing a Preview on the View config page.
    if (empty($this->view->live_preview)) {
      // Prevent devel module from appending queries to ical export.
      $GLOBALS['devel_shutdown'] = FALSE;
      
      drupal_add_http_header('Content-Type', 'text/calendar; charset=utf-8');
      
      // For sites with Clean URLs disabled, the "path" value in the view Display
      // doesn't actually get applied to the URL of the calendar feed. So, we
      // need to manually instruct browsers to download a .ics file.
      if (!variable_get('clean_url', FALSE)) {
        $path_array = explode('/', $this->display->display_options['path']);
        $filename = array_pop($path_array);
        drupal_add_http_header('Content-Disposition', "attachment; filename=\"$filename\"");
      }
    }
    
    return $output;
  }
  
  /**
   * This function converts an rrule array to the iCalcreator format.
   *
   * iCalcreator expects the BYDAY element to be an array like this:
   * (array) ( [([plus] ordwk / minus ordwk)], "DAY" => weekday )
   *
   * But the way that the Date API gives it to us is like this:
   * (array) ( [([plus] ordwk / minus ordwk)]weekday )
   */
  public static function convert_rrule_for_icalcreator($rrule) {
    $new_rrule = array();
    foreach ($rrule as $key => $value) {
      if (strtoupper($key) == 'DATA') {
        // iCalcreator doesn't expect the 'DATA' key that the Date API gives us.
        continue;
      }
      if (strtoupper($key) == 'UNTIL') {
        // iCalcreator expects the 'timestamp' to be array key for UNTIL
        $value['timestamp'] = strtotime($value['datetime']);
      }
      if (strtoupper($key) == 'BYDAY') {
        $new_byday = array();
        foreach ($value as $day) {
          // Fortunately, the weekday values are always 2 characters, so it's easy to
          // split off the ordwk part, even though it could be 1 or 2 characters.
          $weekday = substr($day, -2);
          $ordwk = substr($day, 0, -2);
          $new_byday[] = array($ordwk, 'DAY' => $weekday);
        }
        $value = $new_byday;
      }
      $new_rrule[$key] = $value;
    }
    return $new_rrule;
  }
}
