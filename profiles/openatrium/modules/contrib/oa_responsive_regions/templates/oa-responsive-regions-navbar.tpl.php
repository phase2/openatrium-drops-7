<?php
/**
 * @file
 * Template file for OA Responsive regions navbar.
 */
?>
<div id="oa-responsive-regions-navbar" class="navbar navbar-inverse navbar-fixed-top">
  <div class="navbar-inner">
    <?php foreach ($regions as $region): ?>
      <div class="btn btn-navbar btn-<?php print $region['settings']['position']; ?> responsive-panels-region-toggler" data-position="<?php print $region['settings']['position']; ?>">
        <span class="<?php print $region['icon']; ?>"></span>
      </div>
    <?php endforeach; ?>
  </div>
</div>
