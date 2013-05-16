<?php

/**
 * @file
 *  Classes implementing Date iCal's iCalcreator-based parser functionality.
 */

class DateIcalIcalcreatorParser extends DateIcalFeedsParser {
  
  /**
   * Output sources this parser offers.
   *
   * Includes additional field for the handler for output.
   *
   * @see DateIcalFeedsParser::getMappingSources().
   * @see DateIcalFeedsParser::getSourceElement().
   */
  static protected $sources = array(
    'summary' => array(
      'name' => 'Summary',
      'description' => 'A short summary or title for the calendar component.',
      'date_ical_parse_handler' => 'formatText',
    ),
    'description' => array(
      'name' => 'Description',
      'description' => 'A more complete description of the calendar component than that provided by the "summary" property.',
      'date_ical_parse_handler' => 'formatText',
    ),
    'dtstart' => array(
      'name' => 'Date start',
      'description' => 'Start time for the feed item.
        If also using the "Date end" source, this MUST come before it in the mapping, due to the way iCal feeds are formatted.',
      'date_ical_parse_handler' => 'formatDateTime',
    ),
    'dtend' => array(
      'name' => 'Date end',
      'description' => 'End time for the feed item.',
      'date_ical_parse_handler' => 'formatDateTime',
    ),
    'rrule' => array(
      'name' => 'Repeat rule',
      'description' => 'Describes when and how often this calendar component should repeat.
        The date field for the target node must be configrred to support repeating dates, using the Date Repeat Field module (a submodule of Date).
        When using this source field, it MUST come after Date start (and Date end, if used) in the mapping.',
      'date_ical_parse_handler' => 'formatRrule',
    ),
    'uid' => array(
      'name' => 'UID',
      'description' => 'UID of feed item',
      'date_ical_parse_handler' => 'formatText',
    ),
    'url' => array(
      'name' => 'URL',
      'description' => 'URL for the feed item.',
      'date_ical_parse_handler' => 'formatText',
    ),
    'location' => array(
      'name' => 'Location text',
      'description' => 'Text of the location property of the feed item.',
      'date_ical_parse_handler' => 'formatText',
    ),
    'location:altrep' => array(
      'name' => 'Location alternate representation',
      'description' => 'Additional location information, usually a URL to a page with more info.',
      'date_ical_parse_handler' => 'formatParamText',
    ),
    'categories' => array(
      'name' => 'Categories',
      'description' => 'Catagories of the feed item.',
      'date_ical_parse_handler' => 'formatCategories',
    ),
  );
  
  /**
   * Load and run parser implementation of FeedsParser::parse().
   *
   * @params - change these to generic required paramters.
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    self::loadLibrary();
    
    // Get the path to the temporary file created by the feed download.
    $filename = $fetcher_result->getFilePath();
    $config = $source->getConfig();
    
    //
    // Create the calendar object and parse the file.
    //
    $config = array(
      'unique_id' => '', // do we need one for incoming parsing?
      'filename' => $config['FeedsHTTPFetcher']['source'],
    );
    $calendar = new vcalendar($config);
    if (!$calendar->parse($fetcher_result->getRaw())) {
      throw new DateIcalParseException(t('Error parsing iCal file: %file', array('%file' => $filename)));
    }
    
    // Allow modules to alter the vcalendar object before we interpret its properties.
    $context = array(
      'source' => $source,
      'fetcher_result' => $fetcher_result,
    );
    drupal_alter('date_ical_icalcreator_calendar', $calendar, $context);
    
    //
    // Set a result object.
    //
    $result = new DateIcalParserResult();
    
    // FeedsResult properties
    $xcalname = $calendar->getProperty('X-WR-CALNAME');
    $result->title = !empty($xcalname) ? $xcalname[1] : '';
    $xcaldesc = $calendar->getProperty('X-WR-CALDESC');
    $result->description = !empty($xcaldesc) ? $xcaldesc[1] : '';
    $result->link = NULL;
    
    // Additional DateIcalParserResult properties
    $xtimezone = $calendar->getProperty('X-WR-TIMEZONE');
    if (!empty($xtimezone)) {
      try {
        $tz = new DateTimeZone($xtimezone[1]);
        $result->timezone = $tz;
      }
      catch (Exception $e) {
        $source->log('parse', 'Invalid X-WR-TIMEZONE: %error', array('%error' => $e->getMessage()), WATCHDOG_NOTICE);
      }
    }
    
    $components = array();
    while ($component = $calendar->getComponent('TIMEZONE')) {
      $components[$component->getProperty('tzid')] = new DateIcalIcalcreatorComponent($component);
    }
    $result->timezones = $components;
    
    // Separate the individual feed items into DateIcalIcalcreatorComponent objects, to be treated as
    // separate parsed elements.
    $components = array();
    $component_types = array('vevent', 'vtodo', 'vjournal', 'vfreebusy', 'valarm'); // @todo: admin per feed configurable; check each makes sense.
    foreach ($component_types as $component_type) {
      while ($component = $calendar->getComponent($component_type)) {
        $component = new DateIcalIcalcreatorComponent($component);
        
        // Allow modules to alter the DateIcalIcalcreatorComponent before we parse it into Feeds-readable data.
        $context = array(
          'calendar' => $calendar,
          'source' => $source,
          'fetcher_result' => $fetcher_result,
          'parser_result' => $result,
        );
        drupal_alter('date_ical_icalcreator_component', $component, $context);
        
        $components[] = $component;
      }
    }
    $result->items = $components;
    
    return $result;
  }
  
  /******
   * Source output formatters.
   *
   * Could be in a class of their own?
   **/
  
  /**
   * Format text fields.
   *
   * @todo is \n \N handling correct?
   */
  public function formatText($property_key, $property, DateIcalIcalcreatorComponent $item, FeedsParserResult $result, FeedsSource $source) {
    $context = get_defined_vars();
    $text = $property['value'];
    $text = str_replace(array("\\n", "\\N"), "\n", $text);
    
    // Allow modules to alter the text before it's mapped to the target.
    drupal_alter('date_ical_feeds_object', $text, $context);
    
    return $text;
  }
  
  /**
   * Format Text Parameter
   *
   * @return string.
   */
  public function formatParamText($property_key, $property, DateIcalIcalcreatorComponent $item, DateIcalParserResult $result, FeedsSource $source) {
    $context = get_defined_vars();
    $position = strpos($property_key, ':');
    $key = substr($property_key, 0, $position);
    $attribute = strtoupper(substr($property_key, ++$position));
    $text = $property['params'][$attribute];
    
    // Allow modules to alter the param text before it's mapped to the target.
    drupal_alter('date_ical_feeds_object', $text, $context);
    
    return $text;
  }
  
  /**
   * Format date fields.
   *
   * @return FeedsDateTime
   */
  public function formatDateTime($property_key, $property, DateIcalIcalcreatorComponent $item, DateIcalParserResult $result, FeedsSource $source) {
    $context = get_defined_vars();
    $date_array = $property['value'];
    
    // It's frustrating that iCalcreator gives us date data in a different format than it expects to receive date data.
    if (isset($property['params']['TZID'])) {
      $date_array['tz'] = $property['params']['TZID'];
    }
    
    if (isset($property['params']['VALUE']) && $property['params']['VALUE'] == 'DATE') {
      /**
       * DATE values are All Day events, with no time-of-day.
       * They can span over multiple days.
       * FeedsDateTime sets the granularity correctly.
       * However the granularity is not used yet.
       * All Day events handling is not finalized at the time of writing.
       * http://drupal.org/node/874322 To Date & All Day Date Handling
       */
      if ($property_key == 'dtend') {
        $start_prop = $item->getProperty('dtstart');
        $start_array = $start_prop['value'];
        if (isset($start_prop['params']['TZID'])) {
          $start_array['tz'] =  $start_prop['params']['TZID'];
        }
        
        // On single-day All Day events (the start date + 1 = the end date), just ignore the DTEND
        // if the Date All Day module is installed. Otherwise it'll be displayed strangely.
        if ($start_array['year']       == $date_array['year']
            && $start_array['month']   == $date_array['month']
            && $start_array['day'] + 1 == $date_array['day']
            && module_exists('date_all_day')) {
          return;
        }
        elseif (module_exists('date_all_day')) {
          // When we add the time of 00:00:00 to our date explicitly
          // the date that gets parsed for DTEND is 1 day ahead.
          // so taking a day away before that (if date_all_day is found)
          $date_array['day'] -= 1;
        }
      }
      // The order in which the source -> target mapping is set up matters here: dtstart has to come before dtend.
      // This has been noted in the description for this source field.
      if ($property_key == 'dtstart') {
        if ($duration = $item->getProperty('duration')) {
          $end_array = iCalUtilityFunctions::_duration2date($date_array, $duration['value']);
          $item->setProperty('dtend', $end_array);
        }
        elseif (!$item->getProperty('dtend')) {
          // For cases where a VEVENT component specifies a DTSTART property with a DATE value type
          // but no DTEND nor DURATION property, the event's duration is taken to be one day.
          $end_array = $date_array;
          $end_array['day'] += 1;
          $item->setProperty('dtend', $end_array);
        }
      }
      // FeedsDateTime's implementation of setTimezone() assumes that dates with no time element should just ignore
      // timezone changes, so I had to add the 00:00:00 explicitly, even though it shouldn't be necessary.
      $date_string = sprintf('%d-%d-%d 00:00:00', $date_array['year'], $date_array['month'], $date_array['day']);
      // Set the timezone for All Day events to the server's timezone, rather than letting them default to UTC,
      // so that they don't get improperly offset when saved to the DB.
      $parsed_datetime = new FeedsDateTime($date_string, new DateTimeZone(date_default_timezone_get()));
    }
    else {
      // Date with time.
      $date_string = iCalUtilityFunctions::_format_date_time($date_array);
      
      $tz = NULL;
      if (isset($date_array['tz'])) {
        // 'Z' == 'Zulu' == 'UTC'. DateTimeZone won't acept Z, so change it to UTC.
        if (strtoupper($date_array['tz']) == 'Z') {
          $date_array['tz'] = 'UTC';
        }
        $tz = new DateTimeZone($date_array['tz']);
      }
      else {
        // If there was no timezone in the date array itself, add one if we have one.
        if (!empty($property['params']['TZID'])) {
          // Use the timezone from this DATE-TIME component
          try {
            $tz = new DateTimeZone($property['params']['TZID']);
            // note: these should relate to the DateIcalParserResult::$timezones but see comment on property.
          }
          catch (Exception $e) {
            $source->log('parse', 'DATE-TIME TZID "%tzid" not recognized by PHP: %error',
              array('%tzid' => $property['params']['TZID'], '%error' => $e->getMessage()), WATCHDOG_NOTICE);
          }
        }
        elseif (!empty($result->timezone)) {
          // Use the timezone that was detected for the entire iCal feed.
          $tz = $result->timezone;
        }
      }
      
      // If this iCal object has no DTEND, but it does have a DURATION, emulate DTEND as DTSTART + DURATION.
      // Again, this mechanism requires that dtstart be parsed before dtend in the source->target mapping.
      if ($property_key == 'dtstart' && !$item->getProperty('dtend') && ($duration = $item->getProperty('duration'))) {
        $end_array = iCalUtilityFunctions::_duration2date($date_array, $duration['value']);
        $item->setProperty('dtend', $end_array);
      }
      
      $parsed_datetime = new FeedsDateTime($date_string, $tz);
    }
    
    // Allow modules to alter the FeedsDateTime object before it's mapped to the target.
    drupal_alter('date_ical_feeds_object', $parsed_datetime, $context);
    
    return $parsed_datetime;
  }
  
  /**
   * Format Categories
   *
   * @return array of free tags strings.
   */
  public function formatCategories($property_key, $property, DateIcalIcalcreatorComponent $item, DateIcalParserResult $result, FeedsSource $source) {
    $context = get_defined_vars();
    // Allow modules to alter the categories before they're mapped to the target.
    drupal_alter('date_ical_feeds_object', $property['value'], $context);
    
    if (!empty($property['value'])) {
      return is_array($property['value']) ? $property['value'] : array($property['value']);
    }
  }
  
  /**
   * Format RRULEs, which specify when and how often the event is repeated.
   *
   * @return An RRULE string, with any EXDATE and RDATE values appended, separated by \n.
   *   This is to make the RRULE compatible with date_repeat_split_rrule().
   */
  public function formatRrule($property_key, $property, DateIcalIcalcreatorComponent $item, DateIcalParserResult $result, FeedsSource $source) {
    $context = get_defined_vars();
    // Allow modules to alter the RRULE before it's mapped to the target.
    drupal_alter('date_ical_feeds_object', $property, $context);
    $item->setRrule($property);
    /*
    // I'm not really sure it makes sense to let users alter these, and since you can have more than one of each,
    // it's probbaly not worth the effort to program it correctly. But here's my attempts so far, if anyone wants
    // to finish it.
    $rdate = $item->getProperty('rdate');
    if (!empty($rdate)) {
      $context['property_key'] = 'rdate';
      drupal_alter('date_ical_feeds_object', $rdate, $context);
      $item->setRdate($rdate);
    }
    $exdate = $item->getProperty('exdate');
    if (!empty($rdate)) {
      $context['property_key'] = 'exdate';
      drupal_alter('date_ical_feeds_object', $exdate, $context);
      $item->setExdate($exdate);
    }
    */
    
    $rrule = $item->getRrule();
    $exdate = $item->getExdate();
    $rdate = $item->getRdate();
    return trim("$rrule\n$exdate\n$rdate");
  }
  
  /**
   * Load the iCalcreator library.
   */
  static public function loadLibrary() {
    $creator_path = libraries_get_path('iCalcreator');
    require_once($creator_path . '/iCalcreator.class.php');
  }
}

/**
 * A wrapper on iCalcreator component class.
 */
class DateIcalIcalcreatorComponent implements DateIcalComponentInterface {
  public $component;
  private $_serialized_component;
  
  /**
   * Constructor.
   *
   * @param
   *   vcalendar component configured, but not yet parsed into Feeds-readable data.
   */
  public function __construct(calendarComponent $component) {
    $this->component = $component;
  }
  
  /**
   * Serialization helper.
   */
  public function __sleep() {
    $this->_serialized_component = serialize($this->component);
    return array('_serialized_component');
  }
  
  /**
   * Unserialization helper.
   */
  public function __wakeup() {
    DateIcalIcalcreatorParser::loadLibrary();
    $this->component = unserialize($this->_serialized_component);
  }
  
  public function getComponentType() {
    return $this->component->objName;
  }
  
  public function getProperty($name) {
    return $this->component->getProperty($name, FALSE, TRUE);
  }
  
  // $args should be an array of arguments to be sent to the set$Name()
  // function of calendarComponent. If $args is not an array, it'll be
  // wrapped as one. This is necessary because the iCalcreator API has different
  // parameter lists for the set$Name() functions of different properties.
  public function setProperty($name, $args) {
    if (!is_array($args)) {
      $args = array($args);
    }
    // Call the setProperty() method on $this->component with the arguments: $name + $args.
    call_user_func_array(array($this->component, "setProperty"), array($name) + $args);
  }
  
  // Special set functions, because using component->setRrule() and similar always add an *additional*
  // RRULE/RDATE/EXDATE, rather than changing the existing one. This may be a bug in iCalcreator, or
  // I may just be calling the functions wrong.
  public function setRrule($rrule) {
    return $this->component->rrule[0] = $rrule;
  }
  
  public function getRrule() {
    return trim($this->component->createRrule());
  }
  
  public function setRdate($rdate) {
    return $this->component->rdate[0] = $rdate;
  }
  
  public function getRdate() {
    return trim($this->component->createRdate());
  }
  
  public function setExdate($exdate) {
    return $this->component->exdate[0] = $exdate;
  }
  
  public function getExdate() {
    return trim($this->component->createExdate());
  }
}
