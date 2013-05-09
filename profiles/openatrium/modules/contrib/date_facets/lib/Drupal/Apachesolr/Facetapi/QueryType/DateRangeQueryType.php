<?php

/**
 * @file
 * Contains Drupal_Apachesolr_Facetapi_QueryType_DateRangeQueryType.
 */

/**
 * Date range query type plugin for the Apache Solr Search Integration adapter.
 */
class Drupal_Apachesolr_Facetapi_QueryType_DateRangeQueryType extends FacetapiQueryType implements FacetapiQueryTypeInterface {

  /**
   * Implements FacetapiQueryTypeInterface::getType().
   */
  static public function getType() {
    return 'date_range';
  }

  /**
   * Implements FacetapiQueryTypeInterface::execute().
   *
   * @see http://searchhub.org/dev/2012/02/23/date-math-now-and-filter-queries/
   */
  public function execute($query) {
    $active = $this->getActiveItems();
    $field = $this->facet['field'];

    if (!empty($active)) {

      // Check the first value since only one is allowed.
      switch (key($active)) {
        case 'past_hour':
          $lower = "NOW/HOUR-1HOUR";
          break;

        case 'past_24_hours':
          $lower = "NOW/DAY-1DAY";
          break;

        case 'past_week':
          $lower = "NOW/DAY-7DAYS";
          break;

        case 'past_month':
          $lower = "NOW/MONTH-1MONTH";
          break;

        case 'past_year':
          $lower = "NOW/MONTH-1YEAR";
          break;

        default:
          return;
      }

      $query->addParam('fq', $this->facet['field'] . ":[$lower TO NOW/DAY+1DAY]");
    }
  }

  /**
   * Implements FacetapiQueryTypeInterface::build().
   *
   * Unlike normal facets, we provide a static list of options.
   */
  public function build() {
    return date_facets_get_ranges();
  }
}
