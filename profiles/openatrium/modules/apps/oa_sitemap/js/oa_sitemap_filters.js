/**
 * @file
 * Javascript for the OA sitemap folters.
 *
 * Filters can be used to transform text.
 */

(function ($) {

  angular.module('oaSitemapFilters', []).filter('drupalt', function() {
    return function(input) {
      return Drupal.t(input);
    };
  });

}(jQuery));
