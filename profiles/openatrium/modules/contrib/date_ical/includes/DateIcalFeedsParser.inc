<?php

/**
 * @file
 * Basic classes.
 */

/**
 * Parent class for Feeds integration.
 */
abstract class DateIcalFeedsParser extends FeedsParser {
  /**
   * The output sources the parser offers.
   *
   * array(
   *  'feeds_output_key' => array(
   *    'name' => 'Human readable name of output source.',
   *    'description' => 'Longer description of source.',
   *    'date_ical_parse_handler' => 'Method callback for parsing source before handing to feeds.',
   *  ),
   * );
   */
  static protected $sources;
  
  /**
   * Implementation of FeedsParser::getMappingSources().
   */
  public function getMappingSources() {
    // Quirky work around.
    // Want to have the sources as a property of the class,
    // but can't declare them with t().
    $sources = $this::$sources;
    foreach ($sources as &$source) {
      foreach ($source as $key => &$value) {
        if ($key == 'name' || $key == 'description') {
          $value = t($value);
        }
      }
    }
    // Call parent::getMappingSources() to trigger additional target creation.
    return $sources + parent::getMappingSources();
  }
  
  /**
   * Override FeedsParser::getSourceElement().
   */
  public function getSourceElement(FeedsSource $source, FeedsParserResult $result, $property_key) {
    // Allow parent method to handle any mappings based on the parent node.
    if (substr($property_key, 0, 7) == 'parent:') {
      return parent::getSourceElement($source, $result, $property_key);
    }
    
    // Otherwise retrieve the current DateIcalComponent from the DateIcalParserResult.
    if ($item = $result->currentItem()) {
      if ($position = strpos($property_key, ':')) {
        $key = substr($property_key, 0, $position);
        $attribute = substr($property_key, ++$position);
      }
      else {
        $key = $property_key;
      }
      // and use listed handler to get source output
      $handler = $this::$sources[$property_key]['date_ical_parse_handler'];
      $property = $item->getProperty($key);
      if (empty($property)) {
        // $property will be empty if the mapping is set up to parse optional source
        // components (e.g. RRULE), and this particular VEVENT doesn't have one.
        return '';
      }
      else {
        return $this->$handler($property_key, $property, $item, $result, $source);
      }
    }
  }
}

interface DateIcalComponentInterface {
  public function getComponentType();
  public function setProperty($name, $args);
  public function getProperty($name);
}

class DateIcalParserResult extends FeedsParserResult {
  // Feed extension timezone (X-WR-TIMEZONE)
  public $timezone;
  
  // Feed RFC 5545 timezones; we can't use these at
  // present, only PHP timezonedb tz will be actually recognized.
  // So this is more here as reminder/explanation.
  public $timezones;
}

/**
 * Generic DateIcalFeedsParser exceptions.
 */
class DateIcalException extends Exception {}

/**
 * DateIcalFeedsParser failed to parse some part of iCal.
 */
class DateIcalParseException extends DateIcalException {}
