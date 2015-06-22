/**
 * @file
 * Javascript for the OA sitemap services.
 *
 * This seperate the business logic of communicating from the server with the
 * the presentation logic.
 *
 * Many of this functions return a promise object, as they are ajax requests.
 * To use the promise object:
 *   var promise = service.function();
 *   if (promise) promise.then(function() {});
 *
 * The then function is ran after the ajax is successful. See documentation for
 * $q for more information.
 */

(function ($) {
  angular.module('oaService', [])

  /**
   * Services that can be used for any node object.
   */
  .service('nodeService', function($q) {
    var self = this;
    /**
     * Saves the title of the node.
     */
    this.saveTitle = function (node, old_title) {
      var deferred = $q.defer();
      var promise = deferred.promise;
      $.post(
        // Callback URL.
        Drupal.settings.basePath + 'api/oa/sitemap-update/' + node.nid,
        {'node': node, 'save' : ['title'], token: node.token},
        function(result) {
          if ((result.length > 0) && result[1] && (result[1].command == 'alert')) {
            // undo local change and report error
            node.title = old_title;
            $scope.$apply();
            alert(result[1].text);
            deferred.reject('Unable to save title.');
          }
          else {
            deferred.resolve('Title Saved');
          }
        }
      );
      return promise;
    };
  })

  /**
   * Services that can be used for any space objects.
   */
  .service('SpacesService', function($q) {
    var self = this;
    self.spaces = [];
    self.spaces_loaded = {};
    /**
     * Fethes list of spaces to popular allSpaces
     */
    this.fetch = function (parent_id) {
      // If self.spaces is a promise object still, q.when will wait for it to resolve.
      if (parent_id in self.spaces_loaded) {
        return $q.when(self.spaces);
      }
      var deferred = $q.defer();
      $.get(
        // Callback URL.
        Drupal.settings.basePath + 'api/oa/sitemap/' + parent_id,
        {nids: self.spaces_loaded},
        function(result) {
          if ((result.length > 0) && result[1] && result[1].command  && (result[1].command == 'alert')) {
            alert(result[1].text);
            deferred.reject('Unable to fetch spaces.');
          }
          else {
            for (var nid in result) {
              // Don't override space entry with fetched spaces with new data.
              if (self.spaces[nid] == undefined || !self.spaces[nid].children_fetched) {
                self.spaces[nid] = result[nid];
              }
              if (result[nid].children_fetched) {
                self.spaces_loaded[nid] = nid;
              }
            }
            deferred.resolve(self.spaces);
          }
          self.spaces_loaded[parent_id] = parent_id;
        }
      );
      // Return the promise object for now which will be resolved when ajax done.
      return deferred.promise;
    };
    /**
     * Deletes a space.
     */
    this.delete = function (space) {
      var nid = space.nid;
      if ((space.sections.length > 0) || (space.subspaces.length > 0)) {
        alert(Drupal.t('Can only delete empty spaces.'));
        return false;
      }
      if (confirm(Drupal.t('Are you sure you wish to delete "@name" ?', {'@name': space.title}))) {
        var deferred = $q.defer();
        var promise = deferred.promise;
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/sitemap-delete/' + nid,
          {token: space.token},
          function( result ) {
            if ((result.length > 0) && result[1] && (result[1].command == 'alert')) {
              alert(result[1].text);
              deferred.reject('Unable to delete space.');
            }
            else {
              delete self.spaces[nid];
              deferred.resolve('deleted space.');
            }
        });
        return promise;
      }
    };
    /**
     * Updates the parent of a space.
     */
    this.updateParent = function (space, newParentNid) {
      if (space.nid != newParentNid && newParentNid != undefined) {
        var deferred = $q.defer();
        var promise = deferred.promise;
        // Dropping a space or section on a space.
        var oldParentNid = space.parent_id;
        space.parent_id = newParentNid;
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/sitemap-update/' + space.nid,
          {
            'node': space,
            'save' : ['oa_parent_space'],
            'token': space.token
          },
          function(result) {
            // Sometimes command is to redirect to new item.
            if ((result.length > 0) && result[0] && (result[0].command == 'redirect')) {
              window.location.href = result[0].url;
            }
            else if ((result.length > 0) && result[1] && (result[1].command == 'alert')) {
              // failed, so undo
              space.parent_id = oldParentNid;
              alert(result[1].text);
              deferred.reject('Unable to move space.');
            }
            else {
              if (oldParentNid > -1) {
                delete self.spaces[oldParentNid].subspaces[space.nid];
              }
              if (newParentNid) {
                self.spaces[newParentNid].subspaces[space.nid] = space.nid;
              }
              deferred.resolve('Moved space.');
            }
          }
        );
        return promise;
      }
    };
  })

  /**
   * Services that can be used for any section objects.
   */
  .service('SectionsService', function($q) {
    /**
     * Deletes a section.
     */
    this.delete = function (space, section) {
      if (confirm(Drupal.t('Are you sure you wish to delete "@name" ?', {'@name': section.title}))) {
        var deferred = $q.defer();
        var promise = deferred.promise;
        //TODO: drupal ajax callback to delete a node
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/sitemap-delete/' + section.nid,
          {token: section.token},
          function(result) {
            if ((result.length > 0) && result[1] && (result[1].command == 'alert')) {
              alert(result[1].text);
              deferred.reject('Unable to delete section.');
            }
            else {
              var index = space.sections.indexOf(section);
              if (index > -1) {
                space.sections.splice(index, 1);
              }
              deferred.resolve('Deleted section.');
            }
          }
        );
        return promise;
      }
    };

    /**
     * Updates the parent of a section.
     */
    this.updateParent = function (section, newParentNid, spaces) {
      if (section.nid != newParentNid) {
        var deferred = $q.defer();
        var promise = deferred.promise;
        // Dropping a section or section on a section.
        var oldParentNid = section.parent_id;
        section.parent_id = newParentNid;
        $.post(
          // Callback URL.
          Drupal.settings.basePath + 'api/oa/sitemap-update/' + section.nid,
          {
            'node': section,
            'save' : ['og_group_ref'],
            'token': section.token
          },
          function(result) {
            // Sometimes command is to redirect to new item.
            if ((result.length > 0) && (result[0].command == 'redirect')) {
              window.location.href = result[0].url;
            }
            else if ((result.length > 0) && (result[1].command == 'alert')) {
              // failed, so undo
              section.parent_id = oldParentNid;
              alert(result[1].text);
              deferred.reject('Unable to move section.');
            }
            else {
              var oldIndex = spaces[oldParentNid].sections.indexOf(section);
              spaces[oldParentNid].sections.splice(oldIndex, 1);
              spaces[newParentNid].sections.push(section);
              deferred.resolve('Updated parent.');
            }
          }
        );
        return promise;
      }
    };

  })

}(jQuery));
