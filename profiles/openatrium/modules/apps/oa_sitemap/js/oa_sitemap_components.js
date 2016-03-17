/**
 * @file
 * Javascript for the OA sitemap components.
 *
 * Components can be inserted into page via <component name>
 */

function oaSitemapAngularTemplate(name) {
  return Drupal.settings.oa_sitemap.basePath + '/js/templates/' + name + '.html';
}

(function ($) {

angular.module('oaSitemapComponents', ['oaSitemapFilters',])
    /**
     * This defines a reusable box that contains brief space controls.
     * It is inserted via <oa-space-box> with scope attributes.
     */
    .directive('oaSpaceBox', function() {
    return {
      transclude: true,
      scope: {
        // Passed in as exact attributes.
        space:'=',
        parentSpace: '=',
        dragDrop: '=',
        // Passed in parent functions.
        deleteSpace: '&',
        enableEditor: '&',
        saveTitle: '&',
        restoreTitle: '&',
        onDropOnSpace: '&',
        goToSpace: '&',
        editUrl: '&',
      },
      controller: function($scope, $element, $attrs) {
        $scope.spaceClass = function(space) {
          var className = '';
          if (space.status) {
            className = (space.visibility == 0) ? 'oa-icon-green' : 'oa-icon-red';
          }
          return className;
        };
      },
      templateUrl: oaSitemapAngularTemplate('oa-space-box'),
      replace: true
    };
    })
    /**
     * This defines a reusable box that contains brief section controls.
     * It is inserted via <oa-section-box> with scope attributes.
     */
    .directive('oaSectionBox', function() {
    return {
      transclude: true,
      scope: {
        // Passed in as exact attributes.
        space:'=',
        section:'=',
        dragDrop: '=',
        icons: '=',
        // Passed in parent functions.
        deleteSection: '&',
        enableEditor: '&',
        saveTitle: '&',
        restoreTitle: '&',
        editUrl: '&',
      },
      controller: function($scope, $element, $attrs) {
        $scope.sectionClass = function(section) {
          return (section.visibility) ? 'oa-icon-green' : 'oa-icon-red';
        };
      },
      templateUrl: oaSitemapAngularTemplate('oa-section-box'),
      replace: true
    };
    })
    /**
     * This defines a reusable add button.
     */
    .directive('oaSitemapAdd', ['$timeout', function($timeout) {
    return {
      transclude: true,
      scope: {
        // Passed as string
        addType: "@",
        dropId: "@",
        length1: "@",
        length2: "@",
        // Passed in as exact attributes.
        space: '=',
        // Passed in parent functions.
        onDrop: '&',
        newUrl: '&',
        newClass: '&',
        newTitle: '&',
      },
      templateUrl: oaSitemapAngularTemplate('oa-sitemap-add'),
      replace: true,
      link: function link($scope, element, attrs) {
        $timeout(function() {
          $scope.$emit('oaSitemapRefresh');
        }, 0);
      }
    };
    }])

}(jQuery));
