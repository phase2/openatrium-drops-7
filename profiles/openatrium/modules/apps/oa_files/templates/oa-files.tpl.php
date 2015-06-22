<?php
/**
 * @file
 * Template for Open Atrium Files Menu.  This template is used for the full page view.
 */
?>
<div class="oa-ng-loading alert alert-warning"><?php print t('Loading widget...'); ?></div>
<div class="oa-files-treeview" ng-init="init(<?php print $instance?>)" ng-cloak ng-module="oaFilesTreeview" ng-controller="oaFilesTreeviewController" ng-class="themeClass()">

  <div class="oa-file oa-file-root oa-file-hidden pull-right">
    <a ng-click="showMenu($event,root)"><i class="icon-cog"></i></a>
    <ul ng-show="root.menu" class="dropdown-menu ng-dropdown-menu" role="menu">
      <li><a ng-repeat="action in actions | orderObjectBy:'weight'" ng-if="action.enabled && !action.exposed && action.show(root)" ng-href="{{action.url(root)}}" title="{{action.title}}" ng-click="action.click($event,root)" class="{{action.class}}">{{action.title}}</a></li>
      <li><a title="Rearrange" href="{{rearrange}}" ng-if="allownew" class="oa-file-action"><?php print t('Rearrange'); ?></a></li>
      <li><a title="Expand all" ng-click="expandAll(true)" class="oa-file-action" href=""><?php print t('Expand all'); ?></a></li>
      <li><a title="Collapse all" ng-click="expandAll(false)" class="oa-file-action" href=""><?php print t('Collapse all'); ?></a></li>
      <li><a title="Show filter" ng-click="showFilter(true)" ng-show="!showfilter" class="oa-file-action" href=""><?php print t('Show filter'); ?></a></li>
      <li><a title="Hide filter" ng-click="showFilter(false)" ng-show="showfilter" class="oa-file-action" href=""><?php print t('Hide filter'); ?></a></li>
    </ul>
  </div>
  <div class="oa-files-header">
    <div class="pull-right oa-files-rightalign">
      <div class="oa-files-topbuttons" ng-repeat="action in ['folder', 'adddocument', 'addfile']">
        <div ng-if="actions[action].enabled && actions[action].show(root)">
          <a ng-href="{{actions[action].url(root)}}" ng-click="actions[action].click($event,root)" class="btn btn-default {{actions[action].class}}"><i class="{{actions[action].icon}}"></i>&nbsp;{{actions[action].title}}</a>
        </div>
      </div>
    </div>
    <div ng-show="treeData.length != 0">
      <div class="oa-files-filter input-group" ng-show="showfilter">
        <input type="text" ng-model="filterexp" class="form-control" placeholder="<?php print t('Filter'); ?>" name="file_filter_text"></input >
        <span class="input-group-btn">
          <button class="btn btn-default" ng-click="clearFilter()" type="button"><?php print t('Clear'); ?></button>
        </span>
      </div>
    </div>
  </div>

  <div class="alert alert-warning" ng-if="treeData.length == 0">
    <span><?php print t('No files to show'); ?></span>
  </div>

  <div treecontrol class="tree-classic"
       tree-model="treeData"
       options="options"
       on-selection="showSelected(node)"
       expanded-nodes="expandedNodes"
       on-node-toggle="showToggle(node, expanded)"
       order-by="weight"
       filter-expression="filterFolder">
    <div ng-if="node.icon" class="oa-file-icon" ng-bind-html="nodeIcon(node)">
    </div>
    {{node.name}}
    <div ng-if="showcount && isFolder(node)" class="oa-file-count">
      ({{node.children.length}})
    </div>
    <div class="oa-file oa-file-hidden">
      <a ng-repeat="action in actions | orderObjectBy:'weight'" ng-if="action.enabled && action.exposed && action.show(node)" ng-href="{{action.url(node)}}" title="{{action.title}}" ng-click="action.click($event,node)" class="oa-file-action {{action.class}}"><i class="{{action.icon}}"></i></a>
      <a ng-click="showMenu($event,node)" ng-if="enabledMenu(node)"><i class="icon-cog"></i></a>
      <ul ng-show="node.menu" class="dropdown-menu ng-dropdown-menu" role="menu">
        <li><a ng-repeat="action in actions | orderObjectBy:'weight'" ng-if="action.enabled && !action.exposed && action.show(node)" ng-href="{{action.url(node)}}" title="{{action.title}}" ng-click="action.click($event,node)" class="{{action.class}}">{{action.title}}</a></li>
      </ul>
    </div>
    <div ng-if="showField('date') && node.date" class="oa-file-info oa-column-med pull-right">
      {{node.date}}
    </div>
    <div ng-if="showField('modified') && node.modified" class="oa-file-info oa-column-med pull-right">
      {{node.modified}}
    </div>
    <div ng-if="showField('size') && node.filesize" class="oa-file-info oa-column-sm pull-right">
      {{node.filesize}}
    </div>
    <div ng-if="showField('filename') && node.filename" class="oa-file-info oa-column-lg pull-left">
      {{node.filename}}
    </div>
    <div ng-if="showField('body') && node.body" class="oa-file-info oa-column-full" ng-bind-html="node.body">
    </div>
  </div>
  <div oa-files-newfolder ng-init="init(<?php print $instance?>)"></div>
</div>
