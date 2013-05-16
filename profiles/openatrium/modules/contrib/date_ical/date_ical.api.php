<?php

/**
 * Alter the HTML of an event's Summary and Description, before it gets converted
 * to plaintext for output in an iCal feed.
 *
 * @param $data
 *   A reference to an associative array with the following keys and values:
 *   - 'description': The rendered HTML of the iCal view mode of the entity.
 *   - 'summary': The title of the entity.
 * @param $view
 *  The view object that is being executed to render the iCal feed.
 * @param $context
 *   An associative array of context, with the following keys and values:
 *   - 'entity_type': The type of entity being rendered, 'node', 'user' etc.
 *   - 'entity': The fully loaded entity being rendered.
 *   - 'language': The language code that indicates which translation of field
 *     data should be used.
 */
function hook_date_ical_html_alter(&$data, $view, &$context) {

}

/**
 * Modify a structured event before it is rendered to iCal format.
 *
 * This hook is invoked after the Date iCal module has generated its
 * representation of the event and allows you to modify or add to the
 * representation. Use this hook to set values of iCal fields that are supported
 * but have no values mapped into them by default.
 *
 * @param $event
 *   An associative array representation of the iCal event. This will be used by
 *   the Date iCal rendering system to create an entry in an iCal feed.
 * @param $view
 *   The view object that is being executed to render the iCal feed.
 * @param $context
 *   An associative array of context, with the following keys and values:
 *   - 'entity_type': The type of entity being rendered, 'node', 'user' etc.
 *   - 'entity': The fully loaded entity being rendered.
 *   - 'language': The language code that indicates which translation of field
 *     data should be used.
 */
function hook_date_ical_feed_event_render_alter(&$event, $view, &$context) {
  // Simple example adding the location to a rendered event from a simple
  // textfield called 'field_location'.
  $entity_type = $context['entity_type'];
  $entity = $context['entity'];
  $language = $context['language'];
  if ($locations = field_get_items($entity_type, $entity, 'field_location', $language)) {
    foreach ($locations as $location) {
      $event['location'] = check_plain($location['value']);
    }
  }
}

/**
 * Alter an iCal representation of an event.
 *
 * This hook allows you to modify the event that is being added to the
 * iCal calendar. If Date iCal doesn't support an iCal property that you
 * need to use, then you can add it to the event in the iCal feed here.
 *
 * @param $vevent
 *   The iCalcreator vevent object that is being added to the iCal feed. See the
 *   iCalcreator library for documentation on how to use this object correctly.
 * @param $view
 *  The view object that is being executed to render the iCal feed.
 * @param $event_array
 *   The array representation of the event that's been rendered to the $vevent.
 */
function hook_date_ical_feed_ical_vevent_render_alter($vevent, $view, $event_array) {

}

/**
 * Alter the iCalcreator vcalendar object that will be rendered into an iCal
 * feed View.
 *
 * This hook allows you to modify the iCal calendar that will be rendered into
 * an iCal feed. You can use this hook to add sections to the generated iCal
 * feeds that the Date iCal module doesn't support, etc.
 *
 * @param $vcalendar
 *   The iCalcreator vcalendar object that will be rendered to generate the iCal
 *   feed. See the iCalcreator library for documentation on how to use this
 *   object correctly.
 * @param $view
 *  The view object that is being executed to render the iCal feed.
 */
function hook_date_ical_feed_ical_vcalendar_render_alter(&$vcalendar, $view) {

}

/**
 * Alter the iCalcreator vcalendar object that was parsed from an imported
 * iCal feed.
 *
 * @param $calendar
 *   The iCalcreator vcalendar object that was created by parsing the iCal
 *   feed. See the iCalcreator library for documentation on this object.
 * @param $context
 *   An associative array of context, with the following keys and values:
 *   - 'source' FeedsSource object associated with this Feed.
 *   - 'fetcher_result': The FeedsFetcherResult object associated with this Feed.
 */
function hook_date_ical_icalcreator_calendar_alter(&$calendar, &$context) {
  
}

/**
 * Alter an individual DateIcalIcalcreatorComponent (vevent, valarm, vtodo, etc.)
 * that was parsed from an iCal feed.
 *
 * @param $component
 *   A DateIcalIcalcreatorComponent. See the definition of this class in
 *   includes/DateIcalIcalcreatorParser.inc for more information.
 * @param $context
 *   An associative array of context, with the following keys and values:
 *   - 'calendar': The iCalcreator vcalendar object from which this
 *     DateIcalIcalcreatorComponent originates.
 *   - 'parser_result': The DateIcalParserResult object which contains the parsed
 *     values from the vcalendar object.
 *   - 'source': FeedsSource object associated with this Feed.
 *   - 'fetcher_result': The FeedsFetcherResult object associated with this Feed.
 */
function hook_date_ical_icalcreator_component_alter(&$component, &$context) {
  // Example of what might be done with this alter hook
  if ($component->getComponentType() == 'vevent') {
    // Do something for vevents ...
  }
  if ($component->getComponentType() == 'vtimezone') {
    // Do something different for vtimezones ...
  }
}

/**
 * Alter the post-parse data for a single field from an iCal feed.
 *
 * @param $value
 *   A string or object representing one parsed property of an iCal component.
 * @param $context
 *   An associative array of context, with the following keys and values:
 *   - 'property_key': Inernal, parser-specific identifier for this property.
 *   - 'property': "RAW" value of this property.
 *   - 'item': The DateIcalComponentInterface object that holds the unparsed component.
 *   - 'parser_result': The parsed result of the whole Calendar.
 *   - 'feeds_source': Contains all the metadata about the configuration of this Feed.
 */
function hook_date_ical_feeds_object_alter(&$value, &$context) {
  // Example of what might be done with this alter hook
  if ($context['property_key'] == 'dtstart') {
    // Tweak the parsed FeedsDateTime object created from the start time.
    // ...
  }
}
