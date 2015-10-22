/**
 * @file
 * Javascript for the OA sitemap.
 */

(function ($) {

  var app = angular.module("oaSitemap", ['ngSanitize', 'ngDraggable', 'ngRoute', 'oaSitemapComponents', 'oaSitemapFilters', 'oaService']);
  var oa_map_redirected = false;

  app.config(function($routeProvider) {
    $routeProvider
      .when('/', {
        controller:'oaSitemapController',
        templateUrl: oaSitemapAngularTemplate('oa-sitemap'),
        resolve: {
          allSpaces: function (SpacesService) {
            return SpacesService.fetch(0);
          },
          "redirect_to_path": function($location){
            if (Drupal.settings.oa_sitemap.topID && !oa_map_redirected){
              oa_map_redirected = true;
              $location.path('/space/' + Drupal.settings.oa_sitemap.topID);
            }
            return true;
          },
        }
      })
      // Allows us to be lazy by catching nid is 0 condition.
      .when('/space/0', {
        redirectTo:'/'
      })
      .when('/space/:spaceID', {
        controller:'oaSitemapController',
        templateUrl: oaSitemapAngularTemplate('oa-sitemap'),
        resolve: {
          allSpaces: function ($route, SpacesService) {
            return SpacesService.fetch($route.current.params.spaceID);
          }
        }
      })
      .otherwise({
        redirectTo:'/'
      });
  });

  app.controller("oaSitemapController", function(allSpaces, $scope, $timeout, $location, $routeParams, SpacesService, nodeService, SectionsService) {

    var currentID = 0;
    var topID = 0;
    var breadcrumbs = [];
    /**
     * @todo Fix draggable so ng-click events aren't executed after drag.
     * Till then, this is a work around to stop relocation on drag.
     */
    $scope.$on('draggable:start', function() {
      $scope.dragging = true;
    });
    $scope.$on('draggable:end', function() {
      $timeout( function() {
        $scope.dragging = false;
      }, 10);
    });

    /**
     * Allows us to go to specific route, e.g. va ng-click attribute on button.
     */
    $scope.go = function ( path ) {
      $location.path( path );
    };

    /**
     * Allows us to go to a space route, e.g. va ng-click attribute on button.
     */
    $scope.goToSpace = function ( nid ) {
      if (!$scope.dragging) {
        $location.path('/space/' + nid );
      }
    };


    function loadSpace(id) {
      currentID = id;
      var parentId = allSpaces[id].parent_id;
      var currentSpaces = [];

      // if ID has a valid parent space
      var parentSpace = allSpaces[parentId];

      if (parentSpace) {
        for (var i in parentSpace.subspaces) {
          var childSpace = allSpaces[parentSpace.subspaces[i]];
          currentSpaces.push(childSpace);
        }
      }
      // if ID does not have a valid parent i.e. is top level space
      else {
        currentSpaces.push(allSpaces[id]);
      }
      allSpaces[id].editorEnabled = false;

      // need to call CTools to get it to re-attach the modal popup behavior
      // to links *after* our space has been updated
      $timeout( function() {
        $scope.$broadcast('oaSitemapRefresh', id);
      }, 10);
      return currentSpaces;
    }

    function loadBreadCrumbs(id) {
      var parentId = allSpaces[id].parent_id;

      if ((parentId != -1) && (parentId in allSpaces)) {
        breadcrumbs.push(allSpaces[parentId]);
        loadBreadCrumbs(parentId);
      }

      return breadcrumbs;
    }

    function returnSpacePosition(spaces, index) {
      for (var i in spaces) {
        if (spaces[i].nid == index) {
          return parseInt(i);
        }
      }
      return -1;
    }

    function returnDropDownSelects(active, top) {
      var dropDownSelects = [allSpaces[top]];

      function returnChildren(id, active, depth) {
        var subspaces = allSpaces[id].subspaces;
        for (var i in subspaces) {
          var spaceID = subspaces[i];
          allSpaces[spaceID].prefix = new Array(depth+1).join("- ");
          allSpaces[spaceID].classes = spaceID == active ? 'active' : '';
          dropDownSelects.push(allSpaces[spaceID]);
          if (allSpaces[spaceID] && allSpaces[spaceID].subspaces) {
            var child = returnChildren(spaceID, active, depth+1);
            if (child) {
              return child;
            }
          }
        }
        return false;
      }
      returnChildren(top, active, 1);
      return dropDownSelects;
    }

    function getOptions(helpValue, dragValue) {
      var value = 0;
      if (helpValue) {
        value = value + 1;
      }
      if (dragValue) {
        value = value + 2;
      }
      return value;
    }

    $scope.$on('oaSitemapRefresh', function(event, e) {
      $timeout(function () {
        // need to reset ctools since it caches the previous href values on modal links
        $('a.ctools-use-modal').each(function() {
          // get link url without any query string
          var newurl = $(this).attr('href');
          var newquery = newquery ? newurl.split('?') : [];
          if (newquery.length > 1) {
            var newlink = newquery[0];
            // now need to remove previous ajax assigned to the old url
            for (var base in Drupal.ajax) {
              if ($(this)[0] == Drupal.ajax[base].element) {
                //Drupal.ajax[base].url = newurl;
                //Drupal.ajax[base].element_settings.url = newurl;
                Drupal.ajax[base].options.url = newurl;
              }
            }
          }
        });
        // ok, now reattach new ctools ajax to modals
        var $sitemap = $('.oa-sitemap');
        if ($sitemap.length) {
          Drupal.attachBehaviors($sitemap);
          $('#edit-space').change(function() {
            var item_nid = $(this).val();
            if (item_nid == 'All') {
              $scope.go('/');
            }
            else if (item_nid == 'CURRENT') {
              $scope.goToSpace(Drupal.settings.oa_sitemap.current_space_context);
            }
            else if (jQuery.isNumeric(item_nid)) {
              $scope.goToSpace(item_nid);
            }
            $scope.$apply()
          });
        }
      }, 0, false);
    });

    topID = 0;
    if ($routeParams.spaceID) {
      topID = $routeParams.spaceID;
    }

    $scope.allSpaces = allSpaces;
    $scope.topID = topID;
    $scope.spaces = loadSpace(topID);
    $scope.topDropdown = (0 in allSpaces) ? 0 : Drupal.settings.oa_sitemap.topID;
    $scope.dropDownSelects = returnDropDownSelects(topID, $scope.topDropdown);
    $scope.oldTitles = {};
    $scope.space = allSpaces[topID];
    $scope.showHelp = Drupal.settings.oa_sitemap.showHelp;
    $scope.helpStatus = Drupal.settings.oa_sitemap.options & 0x01;
    $scope.dragDrop = Drupal.settings.oa_sitemap.options & 0x02;
    $scope.fullPage = Drupal.settings.oa_sitemap.fullPage;
    $scope.spaceHelp = Drupal.settings.oa_sitemap.spaceHelp;
    $scope.sectionHelp = Drupal.settings.oa_sitemap.sectionHelp;
    $scope.basePath = Drupal.settings.oa_sitemap.basePath;
    $scope.title = Drupal.settings.oa_sitemap.title;

    $scope.breadcrumbs = loadBreadCrumbs(topID);
    $scope.icons = Drupal.settings.oa_sitemap.icons;
    $scope.currentSlide = returnSpacePosition($scope.spaces, topID);
    $scope.currentSpace = $scope.spaces[$scope.currentSlide];
    $scope.prevSpace = $scope.currentSlide - 1 > -1 ? $scope.spaces[$scope.currentSlide - 1] : null;
    $scope.nextSpace = $scope.spaces[$scope.currentSlide + 1] != undefined ? $scope.spaces[$scope.currentSlide + 1] : null;

    $scope.slide = function(slide) {
      var diff = $scope.currentSlide - parseInt(slide);
      $scope.currentSlide = parseInt(slide);
      $scope.space = $scope.spaces[$scope.currentSlide];
      var offset = -1000;
      if (diff < 0) {
        offset = 1000;
      }
      $('#oa-sitemap-top').css('overflow', 'hidden');
      $('#oa-sitemap-top .oa-spaces').css({
        opacity: 1,
        left: offset
      });
      $('#oa-sitemap-top .oa-space-header').css({
        opacity: 1,
        left: offset
      });
      $('#oa-sitemap-top .oa-spaces').animate({
        opacity: 1,
        left: 0
      }, 300);
      $('#oa-sitemap-top .oa-space-header').animate({
        opacity: 1,
        left: 0
      }, 300,
      function () {
        $('#oa-sitemap-top').css('overflow', 'visible');
      });
    };

    $scope.toggleHelp = function(value) {
      $scope.helpStatus = value;
      var arg = getOptions(value, $scope.dragDrop);
      // ajax callback to set drupal user session value
      $.get(Drupal.settings.basePath + 'api/oa/sitemap-option/' + arg, {token: Drupal.settings.oa_sitemap.option_token});
    };

    $scope.toggleDrag = function(value) {
      $scope.dragDrop = value;
      var arg = getOptions($scope.helpStatus, value);
      // ajax callback to set drupal user session value
      $.get(Drupal.settings.basePath + 'api/oa/sitemap-option/' + arg, {token: Drupal.settings.oa_sitemap.option_token});
      Drupal.settings.oa_sitemap.options = arg;
    };

    $scope.newSpaceTitle = function(spaceID) {
      return (allSpaces[spaceID].parent_id >= 0) ? Drupal.t('New Subspace') : Drupal.t('New Space');
    };

    $scope.newSpaceClass = function(spaceID) {
      return 'oa-subspace-link ctools-use-modal ctools-modal-oa-sitemap-space';
    };

    $scope.newSpaceURL = function(spaceID) {
      var url = Drupal.settings.basePath + 'api/oa_wizard/space-wizard?sitemap=1';
      if (spaceID > 0) {
        url = url + '&oa_parent_space=' + spaceID;
      }
      return url;
    };

    $scope.newSectionTitle = function(spaceID) {
      return Drupal.t('New Section');
    };

    $scope.newSectionClass = function(spaceID) {
      return 'oa-section-link ctools-use-modal ctools-modal-oa-sitemap-section';
    };

    $scope.newSectionURL = function(spaceID) {
      var url = Drupal.settings.basePath + 'api/oa_wizard/section-wizard';
      if (spaceID > 0) {
        url = url + '?og_group_ref=' + spaceID;
      }
      return url;
    };

    /**
     * Calls delete space service then reacts as needed.
     */
    $scope.deleteSpace = function(space) {
      var promise = SpacesService.delete(space);
      if (promise) {
        promise.then(function (data) {
          // If we want to add any additional functionaly after delete, add here.
          // Scope is re-applied purely this being here but empty.
        });
      }
    };


    $scope.deleteSection = function(space, section) {
      var promise = SectionsService.delete(space, section);
      if (promise) {
        promise.then(function (data) {});
      }
    };

    /**
     * Make the title editor visible.
     *
     * The user is directly changing node.title object via ngModel (as that
     * is passed around already to components via node object)
     */
    $scope.enableEditor = function(node) {
      $scope.oldTitles[node.nid] = node.title;
      // This property determines visiblity of textarea via ng-show attribute..
      node.editorEnabled = true;
    };

    /**
     * If the user clicks cancel, return the old title to space object.
     */
    $scope.restoreTitle = function(node) {
      if ($scope.oldTitles[node.nid]) {
        node.title = $scope.oldTitles[node.nid];
      }
      node.editorEnabled = false;
    };

    $scope.disableEditor = function(node) {
      node.editorEnabled = false;
    };

    /**
     * Call the save title service to save title change to server.
     */
    $scope.saveTitle = function(node) {
      $scope.disableEditor(node);
      var promise = nodeService.saveTitle(node, $scope.oldTitles[node.nid]);
      if (promise) {
        promise.then(function (data) {});
      }
    };

    $scope.editUrl = function(node) {
      return node.url_edit + '?destination=' + document.URL;
    };

    $scope.onDropOnSpace = function(node, newParentID){
      if (node.nid == newParentID) return;
      var promise;
      if (node.type == 'oa_space') {
        promise = SpacesService.updateParent(node, newParentID);
      }
      else {
        promise = SectionsService.updateParent(node, newParentID, $scope.allSpaces);
      }
      if (promise) {
        promise.then(function (data) {});
      }
    };

    $scope.onDropOnSpaceList = function(data, index, spaceID, evt){
      if (data.nid != spaceID) {
        // don't drop over itself
        // reordering subspaces
      }
    };

    $scope.onDropOnSection = function(data, index, section, evt){
      if (!angular.equals(data,section)) {
        // don't drop over itself
        // reordering sections
      }
    };
    $(document).on('oaWizardNew', function(event, node) {
      // respond to event message from submitting oa_wizard form
      switch (node.type) {
        case 'oa_section':
          var parentID = node.og_group_ref.und[0].target_id;
          if (allSpaces[parentID]) {
            // only add section if it hasn't already been added.
            // since this event handler can get called multiple times.
            if (returnSpacePosition(allSpaces[parentID].sections, node.nid) == -1) {
              allSpaces[parentID].sections.push({
                'title': node.title,
                'nid': node.nid,
                'parent_id': parentID,
                'type': 'oa_section',
                'url': Drupal.settings.basePath + 'node/' + node.nid,
                'url_edit': Drupal.settings.basePath + 'node/' + node.nid + '/edit',
                'visibility': (!node.field_oa_group_ref || node.field_oa_group_ref.length == 0) &&
                (!node.field_oa_team_ref || node.field_oa_team_ref.length == 0) &&
                (!node.field_oa_user_ref || node.field_oa_user_ref.length == 0),
                'admin': allSpaces[parentID].admin,
                'icon_id': node.field_oa_section.und[0].tid,
                'token': node.node_token
              });
            }
            $scope.$apply()
          }
          break;
        case 'oa_space':
          var parentID = (node.oa_parent_space == undefined) ? 0 : node.oa_parent_space.und[Object.keys(node.oa_parent_space.und)[0]].target_id;
          allSpaces[node.nid] = {
            'nid': node.nid,
            'parent_id': parentID,
            'title': node.title,
            'type': 'oa_space',
            'status': node.status,
            'visibility': node.group_access.und[0].value,
            'admin': allSpaces[parentID].admin,
            'url': Drupal.settings.basePath + 'node/' + node.nid,
            'url_edit': Drupal.settings.basePath + 'node/' + node.nid + '/edit',
            'new_space': allSpaces[parentID].new_space,
            'new_section': (parentID == 0) ? allSpaces[parentID].new_space : allSpaces[parentID].new_section,
            'sections': [],
            'subspaces': {},
            'token': node.node_token
          };
          allSpaces[parentID].subspaces[node.nid] = node.nid;
          $scope.dropDownSelects = returnDropDownSelects($scope.topID, $scope.topDropdown);
          $scope.$apply();
          break;
      }
    });

  });

  var $space_selection_element;

  Drupal.behaviors.oaSitemap = {
    attach: function(context, settings) {
      if (settings.oa_sitemap.fullPage) {
        $('body').addClass('oa-sitemap-full');
      }
      // We need to save the select2 element before it's attached, as
      // the suggested select2(destroy) didn't work.
      if (!$space_selection_element) {
        $space_selection_element = $('.form-item-space');
        $space_selection_element.find('label').hide();
        $select2_element = $space_selection_element.find('.select2widget-processed');
        $space_selection_element.removeClass('form-item').addClass('pull-right');
        $space_selection_element.detach();
      }

      // We move the unprocessed select2 element into the header here
      // Attachbeviours is called again when sitemap is loaded.
      var $header = $('.oa-sitemap-header');
      if ($header.length && !$header.find('.form-item-space').length) {
        if ($space_selection_element.length) {
          $header.append($space_selection_element.clone(true));
        }
      }
    }
  };

  // This reorders drupal.behaviours so select2widget comes after us.
  if (Drupal.behaviors.select2widget) {
    var save_behaviour = Drupal.behaviors.select2widget;
    delete Drupal.behaviors.select2widget;
    Drupal.behaviors.select2widget = save_behaviour;
  }

}(jQuery));
