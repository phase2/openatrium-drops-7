<?php

/**
 * @file
 * Contains Drupal_Apachesolr_Facetapi_QueryType_DateRangeQueryType
 */

/**
 * Date range widget that displays ranges similar to major search engines.
 *
 * There is a hack in place that only allows one item to be active at a time
 * since if would make sense to have multiple active values.
 */
class Drupal_Apachesolr_Facetapi_Widget_DateRangeWidget extends FacetapiWidgetLinks {

  /**
   * Implements FacetapiWidget::execute().
   *
   * We have to hack our way around things to ensure that only one item is
   * active at a time. The downside of this hack is that it might not work with
   * alternate URL processors such as Facet API Pretty Paths. Of course, there
   * is a feature request which I have ignored for some time, so shame on me.
   *
   * @see http://drupal.org/node/1393928
   */
  public function execute() {
    $element = &$this->build[$this->facet['field alias']];

    // Get all variables we will need to hack the query string in order to
    // ensure that only one item is active at a time.
    $filter_key = $this->facet->getAdapter()->getUrlProcessor()->getFilterKey();
    $facet = $this->facet->getFacet();
    $field_alias = rawurlencode($facet['field alias']);
    $value_start_pos = strlen($field_alias) + 1;

    // Re-build query string for all date range facets.
    foreach ($element as &$item) {

      // Filters out all other values from the query string excluding the value
      // of the current item.
      if (!$item['#active']) {
        foreach ($item['#query'][$filter_key] as $pos => $filter) {
          if (0 === strpos($filter, $field_alias . ':')) {
            $value = substr($filter, $value_start_pos);
            if ($value !== $item['#indexed_value']) {
              unset($item['#query'][$filter_key][$pos]);
            }
          }
        }
      }
    }

    // Render the links.
    parent::execute();
  }

  /**
   * Overrides FacetapiWidget::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {
    parent::settingsForm($form, $form_state);
    unset($form['widget']['widget_settings']['links'][$this->id]['soft_limit']);
    unset($form['widget']['widget_settings']['links'][$this->id]['show_expanded']);
  }

  /**
   * Overrides FacetapiWidget::getDefaultSettings().
   */
  function getDefaultSettings() {
    return array(
      'nofollow' => 1,
    );
  }
}
