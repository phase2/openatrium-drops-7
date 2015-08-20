/**
 * @file
 * Angular Javascript for the OA files treeview.
 */

(function ($) {

  var app = angular.module("oaFilesTreeview", ['ngSanitize', 'treeControl', 'ngCookies']);

  app.controller("oaFilesTreeviewController", function($scope, $cookieStore, $timeout, $location) {

    $scope.init = function(instance) {

      var maxId = 0;
      var settings = Drupal.settings['oa_files_instance_' + instance];
      var files = settings.files;
      var mode = settings.mode;
      var space = settings.space;
      var section = settings.section;
      var fields = settings.fields;
      var allownew = settings.allownew;
      var allowfiles = settings.allowfiles;
      var showcount = settings.showcount;
      var parentfield = settings.parentfield;
      var showfilter = settings.showfilter;
      var currentid = settings.currentid;
      var hideempty = settings.hideempty;
      var linkvocab = settings.linkvocab;
      var nodetype = settings.nodetype;
      var topid = (settings.topid) ? settings.topid : 0;

      var expandedList = $cookieStore.get(cookieKey('expanded'));
      if (expandedList == undefined) {
        expandedList = [];
      }

      function searchId(myArray, id) {
        for(var i = 0, len = myArray.length; i < len; i++) {
          if (myArray[i].id === id) return i;
        }
        return -1;
      }

      // build tree data hierarchy from flat files list
      function buildTree(files, parent) {
        var seenIds = [];
        return _buildTree(files, parent, seenIds);
      }
      function _buildTree(files, parent, seenIds) {
        var result = [];
        for (var id in files) {
          var item = files[id];
          // match both string and int values for parent
          // if parent is the top, also match parent values of zero
          if ((item.parent.indexOf(parent) > -1) || (item.parent.indexOf(parent.toString()) > -1)
            || ((parent == topid) &&
              ((item.parent.indexOf(0) > -1) || (item.parent.indexOf('0') > -1)))
            ) {
            // In case of files, need to clone the item so we get unique row objects
            // within each parent otherwise things like the popup menu will appear
            //  for all instancesof the same node
            // fortunately we have a simple object structure
            var clone;
            if (seenIds.indexOf(item.id) > -1) {
              clone = {};
              for (var key in item) {
                clone[key] = item[key];
              }
            }
            else {
              clone = item;
              seenIds.push(item.id);
            }
            clone.weight = clone.weight ? parseInt(clone.weight) : 0;
            if (clone.isfolder) {
              clone.children = buildTree(files, id);
            }
            else {
              clone.children = [];
            }
            if ((hideempty != 1) || !clone.isfolder || (clone.children.length > 0)) {
              result.push(clone);
              maxId++;
            }
          }
        }
        return result;
      }

      function cookieKey(name) {
        return 'oa_files_' + name + '_' + space + '_' + section + '_' + instance;
      }

      function addExpandCookie(id, expanded) {
        // update cookie that saves the toggle status.
        var key = cookieKey('expanded');
        expandedList = $cookieStore.get(key);
        if (expandedList == undefined) {
          expandedList = [];
        }

        if (expanded) {
          var index = expandedList.indexOf(id);
          if (index == -1) {
            expandedList.push(id);
          }
        }
        else {
          var index = expandedList.indexOf(id);
          if (index > -1) {
            expandedList.splice(index, 1);
          }
        }
        $cookieStore.put(key, expandedList);
      }

      function setExpandCookie(all) {
        var key = cookieKey('expanded');
        expandedList = [];
        if (all) {
          for (var index in $scope.expandedNodes) {
            var node = $scope.expandedNodes[index];
            expandedList.push(node.id);
          }
        }
        $cookieStore.put(key, expandedList);
      }

      // ensure node is expanded
      function doExpand(node) {
        if (node != undefined) {
          var index = searchId($scope.expandedNodes, node.id);
          if (index < 0) {
            $scope.expandedNodes.push(node);
            addExpandCookie(node.id, true);
          }
        }
      }

      // expand nodes saved in session cookie.
      function preExpand(root) {
        for (var key in root) {
          var node = root[key];
          var index = expandedList.indexOf(node.id);
          var index2 = searchId($scope.expandedNodes, node.id);
          if ((index > -1) && (index2 < 0)) {
            $scope.expandedNodes.push(node);
          }
          preExpand(node.children);
        }
      }

      // expand the current node in the tree.
      function expandCurrent(id) {
        var currentnode = files[id];
        if (currentnode) {
          for (var pid in currentnode.parent) {
            var node = files[currentnode.parent[pid]];
            if (node != undefined) {
              $scope.expandedNodes.push(files[currentnode.parent[pid]]);
              expandCurrent(currentnode.parent[pid]);
            }
          }
        }
      }

      var previousNode = null;

      $scope.options = {
        nodeChildren: "children",
        dirSelectable: false,
        injectClasses: {
          iLeafItem: "oa-files-leaf",
          iFolderItem: "oa-files-folder"
        },
        isLeaf: function (node) {
          $scope.options.injectClasses.iLeafItem = (node.id == currentid) ? "oa-files-selected oa-files-leaf" : "oa-files-leaf";
          return !(node.isfolder) && (node.children.length == 0);
        }
      };

      $scope.actions = settings.actions;
      angular.extend($scope.actions['download'], {
        url: function (node) {
          return node.downloadurl;
        },
        show: function (node) {
          return node.downloadurl;
        },
        click: function (e, node) {
          return true;
        }
      });
      angular.extend($scope.actions['view'], {
        url: function (node) {
          return Drupal.settings.basePath + node.url + '/view';
        },
        show: function (node) {
          return (node != $scope.root);
        },
        click: function (e, node) {
          return true;
        }
      });
      angular.extend($scope.actions['edit'], {
        url: function (node) {
          return Drupal.settings.basePath + node.url + '/edit?destination=' + settings.currentpath;
        },
        show: function (node) {
          return node.editor;
        },
        click: function (e, node) {
          return true;
        }
      });
      angular.extend($scope.actions['folder'], {
        url: function (node) {
          return '#';
        },
        show: function (node) {
          return $scope.allownew && $scope.isFolder(node);
        },
        click: function (e, node) {
          $scope.stopPropagate(e);
          $scope.promptFolder(node);
          return false;
        }
      });
      angular.extend($scope.actions['addfile'], {
        url: function (node) {
          var id = 0;
          if (parentfield == 'menu_parent') {
            id = node.nid || topid;
          }
          else {
            id = node.tid || topid;
          }
          return Drupal.settings.basePath + 'oa-files/upload/ajax?' + parentfield + '=' + id;
        },
        show: function (node) {
          return $scope.allowfiles && node.isfolder;
        },
        click: function (e, node) {
          $scope.stopPropagate(e);
          $scope.closeMenu(node);
          return true;
        }
      });
      angular.extend($scope.actions['adddocument'], {
        url: function (node) {
          var id = 0;
          if (parentfield == 'menu_parent') {
            id = node.nid || topid;
          }
          else {
            id = node.tid || topid;
          }
          return Drupal.settings.basePath + 'node/add/' + nodetype + '?' + parentfield + '=' + id + '&type=' + nodetype + '&destination=' + settings.currentpath;
        },
        show: function (node) {
          return $scope.allowfiles && node.isfolder;
        },
        click: function (e, node) {
          $scope.showToggle(node, true);
          if (e.stopPropagation) e.stopPropagation();
          return true;
        }
      });

      $scope.exposedCount = 0;
      for (var key in $scope.actions) {
        if ($scope.actions[key].exposed) {
          $scope.exposedCount++;
        }
      }
      // clear the Loading... message
      setTimeout(
        function () {
          $('.oa-ng-loading').hide();
      }, 10);

      $scope.foldername = "";
      $scope.creatingFolder = false;
      $scope.parentFolder = null;

      $scope.expandedNodes = [];
      $scope.rearrange = settings.rearrange;
      $scope.allownew = allownew;
      $scope.allowfiles = allowfiles;
      $scope.showcount = showcount;
      $scope.showfilter = showfilter;
      $scope.selected = null;
      $scope.treeData = buildTree(files, topid);
      preExpand($scope.treeData);
      expandCurrent(currentid);

      $scope.root = {
        id: 0,
        name: '<root>',
        children: [],
        editor: false,
        isfolder: true
      };
      // add root node for split panel mode.
      if (mode == 'split') {
        $scope.root.children = $scope.treeData;
        $scope.treeData = [$scope.root];
        doExpand($scope.root);
      }

      $scope.doRefresh = function () {
        $timeout(function () {
          $location.hash('');
          $scope.$broadcast('oaFilesRefresh');
        }, 10);
      };

      $scope.doRefresh();

      $scope.$on('oaFilesRefresh', function (event) {
        // need to reset ctools since it caches the previous href values on modal links
        $('a.ctools-use-modal').each(function () {
          // get link url without any query string
          var newurl = $(this).attr('href');
          var newquery = newurl.split('?');
          if (newquery.length > 1) {
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
        if (mode != 'sidebar') {
          // ensure there is space for the exposed action icons
          $('.oa-files-wide [treecontrol] li .tree-label').css('padding-right', ($scope.exposedCount * 20 + 60) + 'px');
        }
        // ok, now reattach new ctools ajax to modals
        Drupal.attachBehaviors($('.oa-files-treeview'));
      });

      $scope.stopPropagate = function ($event) {
        if ($event.stopPropagation) $event.stopPropagation();
        if ($event.preventDefault) $event.preventDefault();
        $event.cancelBubble = true;
        $event.returnValue = false;
        return false;
      };

      $scope.showMenu = function (e, node) {
        if (previousNode != null && previousNode != node) {
          previousNode.menu = false;
        }
        node.menu = !node.menu;
        previousNode = node;
        e.stopPropagation();
        return false;
      };

      $scope.closeMenu = function (node) {
        if (previousNode != null && previousNode != node) {
          previousNode.menu = false;
        }
        if (node != null) {
          node.menu = false;
        }
      };

      $scope.showFilter = function (value) {
        $scope.showfilter = value;
        $scope.closeMenu($scope.root);
      };

      $scope.showSelected = function (node) {
        if (node != undefined) {
          $scope.selected = node;
          if ($scope.options.isLeaf(node) || linkvocab) {
            window.location.href = Drupal.settings.basePath + node.url;
          }
        }
      };

      $scope.showToggle = function (node, expanded) {
        $scope.selected = node;
        $scope.closeMenu(node);
        addExpandCookie(node.id, expanded);
        $scope.doRefresh();
      };

      $scope.expandAll = function (value) {
        var allNodes = [];
        function addTree(root) {
          for (var index in root) {
            var n = root[index];
            allNodes.push(n);
            addTree(n.children);
          }
        }
        $scope.closeMenu($scope.root);
        if (value) {
          addTree($scope.treeData);
          $scope.expandedNodes = allNodes;
        }
        else {
          $scope.expandedNodes = [];
        }
        setExpandCookie(value);
      };

      // determine if the cog menu needs to be shown
      $scope.enabledMenu = function (node) {
        for (var key in $scope.actions) {
          if ($scope.actions[key].enabled && !$scope.actions[key].exposed && $scope.actions[key].show(node)) {
            return true;
          }
        }
        return false;
      };

      $scope.isFolder = function (node) {
        return !$scope.options.isLeaf(node);
      };

      $scope.promptFolder = function (node) {
        $scope.parentFolder = node;
        $scope.creatingFolder = true;
        $scope.closeMenu(node);
      };

      $scope.addFolder = function (parentNode, folderName) {
        $scope.creatingFolder = false;
        if (parentNode == null) {
          parentNode = $scope.root;
        }
        if ((folderName != '') && (parentNode != null)) {
          var token;
          var parent = 0;
          var parentId = parentNode.id;
          if (parentfield == 'menu_parent') {
            if (parentNode && parentNode.nid) {
              parent = parentNode.nid;
              $url = 'api/oa/files-addmenu/' + parent;
            }
            else {
              $url = 'api/oa/files-addmenu';
            }
            token = Drupal.settings.oa_files.node_token[(parentNode && parentNode.nid ? 'node:' + parentNode.nid : 'undefined')];
          }
          else {
            parent = parentNode.tid;
            $url = 'api/oa/files-addterm/' + parent + '/' + settings.vid;
            token = Drupal.settings.oa_files.vocab_token['vid:' + settings.vid];
          }
          var treeNode = {
            name: folderName,
            id: maxId + 1,
            parent: [parent],
            isfolder: true,
            editor: parentNode.editor,
            children: [],
          };
          $.post(
            // Callback URL.
            Drupal.settings.basePath + $url,
            {
              'node': treeNode,
              'type': nodetype,
              'token': token
            },
            function (result) {
              if ((result.length > 0) && (result[1].command == 'alert')) {
                // report error
                alert(result[1].text);
              }
              else if (result.id) {
                if (result.oa_files) {
                  // Merge in settings.
                  for (var type_key in result.oa_files) {
                    if (Drupal.settings.oa_files[type_key] == undefined) {
                      Drupal.settings.oa_files[type_key] = {};
                    }
                    for (var folder_id in result.oa_files[type_key]) {
                      Drupal.settings.oa_files[type_key][folder_id] = result.oa_files[type_key][folder_id];
                    }
                  }
                }
                // Merge in additional data.
                if (result.additions) {
                  for (var addition_key in result.additions) {
                    treeNode[addition_key] = result.additions[addition_key];
                  }
                }
                maxId++;
                treeNode.id = result.id;
                treeNode.parent = [parentId];
                if (parentfield == 'menu_parent') {
                  treeNode.nid = result.id;
                  treeNode.url = 'node/' + result.id;
                }
                else {
                  treeNode.tid = result.tid;
                  treeNode.url = 'taxonomy/term/' + result.tid;
                }
                files[treeNode.id] = treeNode;
                $scope.treeData = buildTree(files, topid);
                addExpandCookie(parentId, true);
                preExpand($scope.treeData);
                $scope.$apply();
                $scope.doRefresh();
              }
            });
        }
      };

      $scope.filterFolder = function(node, _index) {
        if (node == null) {
          // passed node=null to determine if there is a valid filter defined
          return ($scope.filterexp !== undefined) && angular.isString($scope.filterexp) && ($scope.filterexp.length > 0);
        }
        if (($scope.filterexp == undefined) || !angular.isString($scope.filterexp) || ($scope.filterexp.length == 0)) {
          return true;
        }
        var matched = (node.name.toLowerCase().indexOf($scope.filterexp.toLowerCase()) !== -1);
        if (matched) {
          return true;
        }
        else if (node.children.length > 0) {
          for (var index in node.children) {
            if ($scope.filterFolder(node.children[index], _index)) {
              return true;
            }
          }
          return false;
        }
        else {
          return false;
        }
      };

      $scope.themeClass = function() {
        return 'oa-files-' + mode;
      };

      $scope.nodeIcon = function(node) {
        return '<img class="file-icon" alt="" title="' + node.mimetype + '" src="' + node.icon + '" />';
      };

      $scope.showField = function(index) {
        return ((fields === Object(fields)) && (index in fields) && (fields[index] != 0));
      };

      $scope.clearFilter = function() {
        $scope.filterexp = '';
      };

      $scope.$on('oaFilesExpand', function (event, node) {
        $scope.selectedNode = node;
      });

      $(document).on('oaFilesAdded', function (event, new_files) {
        // respond to event message from adding a new file
        parents = [];
        for (var fid in new_files) {
          var file = new_files[fid];
          file.children = [];
          files[fid] = file;
          for (var pid in file.parent) {
            parents.push(file.parent[pid]);
          }
          // need to rebuild because it could have effected any parents
          $scope.treeData = buildTree(files, topid);
          // now add parents to expanded list
          for (var pid in parents) {
            addExpandCookie(parents[pid], true)
          }
          preExpand($scope.treeData);
          $scope.$apply();
          $scope.doRefresh();
        }
      });

    }

  });

  // add a filter to support sorting objects
  // from http://justinklemm.com/angularjs-filter-ordering-objects-ngrepeat/
  app.filter('orderObjectBy', function() {
    return function(items, field, reverse) {
      var filtered = [];
      angular.forEach(items, function(item) {
        filtered.push(item);
      });
      filtered.sort(function (a, b) {
        return (a[field] > b[field] ? 1 : -1);
      });
      if(reverse) filtered.reverse();
      return filtered;
    };
  });

  app.directive('stopEvent', function () {
    return {
      restrict: 'A',
      link: function (scope, element, attr) {
        element.bind(attr.stopEvent, function (e) {
          e.stopPropagation();
        });
      }
    };
  });

  // directive for the Bootstrap modal for creating a new folder
  app.directive('oaFilesNewfolder', function () {
    return {
      restrict: 'EA',
      replace: true,
      template: '<div>' +
      '  <div class="modal fade" id="oa-files-newfolder-{{instance}}" tabindex="-1" + role = "dialog" aria-labelledby = "modal-dialog-title" aria-hidden = "true" > ' +
      '    <div class = "modal-dialog" > ' +
      '      <form name = "form"> ' +
      '        <div class = "modal-content" > ' +
      '          <div class = "modal-header" > ' +
      '            <button type="button" class = "close" data-dismiss="modal" aria-hidden="true" ng-click="cancel()" ><i class="icon-remove"></i></button>' +
      '              <h3 id="modal-dialog-title">New Folder</h3 > ' +
      '          </div>' +
      '          <div class="modal-body">' +
      '            <p>Enter the name of the new folder:</p>' +
      '            <input type="text" class="oa-files-foldername" ng-model="foldername" name="foldername"></input >' +
      '            <input type="submit" class="btn btn-primary" id="submit" ng-click="submit()" value="Create Folder"></input >' +
      '            <input type="button" class="btn btn-default" id="cancel" ng-click="cancel()" value="Cancel"></input >' +
      '          </div>' +
      '        </div > ' +
      '      </form>' +
      '    </div > ' +
      '  </div>' +
      '</div > ',
      controller: function ($scope) {

        $scope.init = function(instance) {
          $scope.instance = instance;
        };

        $scope.submit = function() {
          $scope.addFolder($scope.parentFolder, $scope.foldername);
          $scope.parentFolder = null;
          $("#oa-files-newfolder-" + $scope.instance).modal('hide');
        };

        $scope.cancel = function() {
          $scope.creatingFolder = false;
          $("#oa-files-newfolder-" + $scope.instance).modal('hide');
        };

        $scope.$watch('creatingFolder', function() {
          if ($scope.creatingFolder) {
            $("#oa-files-newfolder-" + $scope.instance).on("shown.bs.modal", function() {
              $("#oa-files-newfolder-" + $scope.instance + " input").first().focus();
            });
            $("#oa-files-newfolder-" + $scope.instance).modal('show');
          }
        });
      }
    };
  });

  Drupal.ajax.prototype.commands.oaFilesAdded = function(ajax, response, status) {
    // called when the ajax for adding file has completed
    // trigger an event to notify anybody who might need the files data
    $(document).trigger('oaFilesAdded', response.files);
  };

  Drupal.behaviors.oaFilesTreeview = {
    attach: function(context, settings) {
    }
  }

}(jQuery));
