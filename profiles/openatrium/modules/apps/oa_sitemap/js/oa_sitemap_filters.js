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
  })
  .filter('orderSpacesBy', function() {
    return function(items, field, data, reverse) {
      var filtered = [];
      angular.forEach(items, function(item) {
        filtered.push(item);
      });
      filtered.sort(function (a, b) {
        return (data[a][field] > data[b][field] ? 1 : -1);
      });
      if (reverse) filtered.reverse();
      return filtered;
    };
  });

}(jQuery));
