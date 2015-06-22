<?php
/**
 * @file
 * Template for Open Atrium sitemap App.
 * $link - link for full sitemap
 * $search - search dropdown list
 * $data - JSON data
 */
?>
<div style="display:none;"><?php print $sitemap_search; ?></div>
<div ng-app="oaSitemap" ng-view></div>
