<?php
/**
 * @file
 * Template for Open Atrium sitemap App.
 * $link - link for full sitemap
 * $search - search dropdown list
 * $data - JSON data
 */
?>
<div class="oa-sitemap" ng-cloak ng-app="oaSitemap" ng-controller="oaSitemapController" ondragstart="return false;" ondrop="return false;">
  <div class="oa-sitemap-header clearfix">
    <div class="oa-sitemap-title pull-left">
      <h3>{{title}}</h3>
    </div>
    <div class="oa-sitemap-search pull-right btn-group">
      <button class="oa-sitemap-search-toggle btn btn-default dropdown-toggle" data-toggle="dropdown" href="#">{{spaces[currentSlide].title}} <span class="caret"></span></button>
      <ul class="dropdown-menu" role="menu">
        <li ng-repeat="dropDownSelect in dropDownSelects">
          <a ng-class="dropDownSelect.classes" class="oa-sitemap-search-link" ng-click="exploreSpace(dropDownSelect.nid, 1)">{{dropDownSelect.prefix}}{{dropDownSelect.title}}</a>
        </li>
      </ul>
    </div>
    <a class="btn-none pull-right" ng-if="showHelp && helpStatus" ng-click="toggleHelp(false)" href="#">
      <?php print t('Hide Help'); ?>
    </a>
    <a class="btn btn-default pull-right" ng-if="showHelp && !helpStatus" ng-click="toggleHelp(true)" href="#">
      <i class="icon-question-sign"></i> <?php print t('Help'); ?>
    </a>
    <div class="oa-sitemap-full pull-left">
      <?php print $link; ?>
    </div>
  </div>
  <div class="oa-sitemap-help" ng-if="showHelp && helpStatus && space.new_space">
    <img class="oa-sitemap-helpimage" ng-src="{{basePath}}/images/atrium-tree.png">
    <div class="oa-sitemap-spacehelp" ng-if="!space.new_section">
      <img class="pull-left oa-sitemap-helpicon" ng-src="{{basePath}}/images/space.png">
      <div ng-bind-html="spaceHelp"></div>
    </div>
    <div class="oa-sitemap-sectionhelp" ng-if="space.new_section">
      <img class="pull-left oa-sitemap-helpicon" ng-src="{{basePath}}/images/section.png">
      <div ng-bind-html="sectionHelp"></div>
    </div>
    <div class="oa-sitemap-caret">
      <img ng-src="{{basePath}}/images/triangle.png">
    </div>
  </div>
  <ul class="oa-sitemap-breadcrumbs">
    <li class="oa-sitemap-breadcrumb" ng-repeat="breadcrumb in breadcrumbs.slice().reverse()">
      <a class="btn btn-default" ng-click='exploreSpace(breadcrumb.nid, -1)' ng-drop="true" ng-drop-success="onDropOnSpace($data,breadcrumb.nid,$event)">{{breadcrumb.title}}</a>
    </li>
  </ul>
  <div id="oa-sitemap-top" class="oa-carousel-container">
    <div class="oa-space-header">
      <button class="prev" ng-show="spaces[currentSlide-1]" ng-click="slide(currentSlide-1)" ng-drop="true" ng-drop-success="onDropOnSpace($data,spaces[currentSlide-1].nid,$event)">{{spaces[currentSlide - 1].title}}</button>
      <div class="dropdown">
        <a class="oa-space-title" data-toggle="dropdown" href="#" ng-drop="true">{{spaces[currentSlide].title}}</a>
        <ul class="dropdown-menu" role="menu">
          <li ng-repeat="space in spaces">
            <a ng-click="slide($index)" ng-drop="true" ng-drop-success="onDropOnSpace($data,space.nid,$event)">{{space.title}}</a>
          </li>
        </ul>
        <a ng-href="{{spaces[currentSlide].url}}" title="<?php print t('Visit Space'); ?>">
          &nbsp;&nbsp;<i class="icon-eye-open"></i>
        </a>
      </div>
      <button class="next" ng-show="spaces[currentSlide+1]" ng-click="slide(currentSlide+1)" ng-drop="true" ng-drop-success="onDropOnSpace($data,spaces[currentSlide+1].nid,$event)">{{spaces[currentSlide + 1].title}}</button>
    </div>

    <div class="oa-spaces">

      <section class="oa-sections">
        <div class="oa-section" ng-repeat="section in space.sections" ng-drag="{{dragDrop}}" ng-drag-data="section" ng-drag-id="1">
          <h4 class="oa-section-title dropdown" ng-drop="true" ng-drop-id="[1]" ng-drop-success="onDropOnSection($data,$index,section,$event)">
            <div class="oa-section-icon {{sectionClass(section)}}" ng-bind-html="icons[section.icon_id]"></div>
            <a ng-hide="section.editorEnabled" class="oa-section-link {{section.class}}" data-toggle="dropdown" href="#">{{section.title}}</a>
            <ul class="dropdown-menu" role="menu">
              <li ng-show="section.admin"><a ng-href="{{editURL(section)}}"><?php print t('Edit'); ?></a></li>
              <li ng-show="section.admin"><a ng-click="deleteSection(space, section)"><?php print t('Delete'); ?></a></li>
              <li ng-show="section.admin"><a ng-click="enableEditor(section)"><?php print t('Rename'); ?></a></li>
              <li><a href="{{section.url}}"><?php print t('View'); ?></a></li>
            </ul>
            <div ng-show="section.editorEnabled">
              <textarea ng-model="editableTitle[section.nid]"></textarea>
              <div class="oa-rename-actions">
                <a href="#" ng-click="saveTitle(section)"><?php print t('Save'); ?></a>
                <?php print t('or'); ?>
                <a href="#" ng-click="disableEditor(section)"><?php print t('Cancel'); ?></a>.
              </div>
            </div>
          </h4>
        </div>
        <div ng-if="space.new_section" class="oa-section newsection">
          <h4 class="oa-section-title" ng-drop="true" ng-drop-id="[1]" ng-drop-success="onDropOnSection($data,space.sections.length,undefined,$event)">
            <a ng-href="{{newSectionURL(space.nid)}}" ng-class="newSectionClass(space.nid)" title="{{newSectionTitle(space.nid)}}">
              <div class="oa-section-icon"><i class="icon-plus"></i></div>
            {{newSectionTitle(space.nid)}}</a>
          </h4>
        </div>
      </section>

      <section class="oa-subspaces">
        <div class="oa-subspace" ng-repeat="index in space.subspaces" ng-drag="{{dragDrop}}" ng-drag-data="allSpaces[index]" ng-drag-id="2">
          <div class="oa-subspace-icons" ng-hide="allSpaces[index].editorEnabled">
            <div class="oa-subspace-icon-left">
              <a ng-href="{{allSpaces[index].url}}">
                <i class="icon-user {{spaceClass(index)}}"></i>
              </a>
            </div>
            <div ng-show="allSpaces[index].admin" class="dropdown oa-subspace-icon-center">
              <a class="" data-toggle="dropdown" href="#" title="<?php print t('Settings'); ?>"><i class="icon-cog"></i></a>
              <ul class="dropdown-menu" role="menu">
                <li><a ng-href="{{editURL(allSpaces[index])}}"><?php print t('Edit'); ?></a></li>
                <li><a ng-click="deleteSubspace(space, index)"><?php print t('Delete'); ?></a></li>
                <li><a ng-click="enableEditor(allSpaces[index])"><?php print t('Rename'); ?></a></li>
              </ul>
            </div>
            <div class="oa-subspace-icon-right">
              <a ng-href="{{allSpaces[index].url}}" title="<?php print t('Visit Space'); ?>">
                <i class="icon-eye-open"></i>
              </a>
            </div>
          </div>
          <h4 class="oa-subspace-title">
            <a ng-hide="allSpaces[index].editorEnabled" class="oa-subspace-link" ng-click='exploreSpace($parent.allSpaces[index].nid, 1)'
               ng-drop="true" ng-drop-success="onDropOnSpace($data,index,$event)">
              <span>{{$parent.allSpaces[index].title}}</span>
            </a>
            <div ng-show="allSpaces[index].editorEnabled">
              <textarea ng-model="editableTitle[index]"></textarea>
              <div class="oa-rename-actions">
                <a href="#" ng-click="saveTitle(allSpaces[index])"><?php print t('Save'); ?></a>
                or
                <a href="#" ng-click="disableEditor(allSpaces[index])"><?php print t('Cancel'); ?></a>.
              </div>
            </div>
          </h4>
        </div>
        <div ng-if="space.new_space" class="oa-subspace oa-new-space">
          <h4 class="oa-subspace-title">
            <a ng-href="{{newSpaceURL(space.nid)}}" ng-class="newSpaceClass(space.nid)" title="{{newSpaceTitle(space.nid)}}"
               ng-drop="true" ng-drop-id="[2]" ng-drop-success="onDropOnSpaceList($data,space.subspaces.length,-1,$event)">
              <span><i class="icon-plus"></i>{{newSpaceTitle(space.nid)}}</span>
            </a>
          </h4>
        </div>
      </section>

    </div>
  </div>
  <div id="oa-sitemap-footer">
    <a class="btn-none pull-right" ng-if="space.new_space && dragDrop" ng-click="toggleDrag(false)" href="#">
      <?php print t('Disable Drag/drop'); ?>
    </a>
    <a class="btn-none pull-right" ng-if="space.new_space && !dragDrop" ng-click="toggleDrag(true)" href="#">
      <?php print t('Enable Drag/drop'); ?>
    </a>
  </div>
</div>
