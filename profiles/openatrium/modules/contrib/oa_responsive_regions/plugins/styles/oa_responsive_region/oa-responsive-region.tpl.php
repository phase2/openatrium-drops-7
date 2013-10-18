<?php
/**
 * @file
 * Template file for OA Responsive Region.
 */
?>
<div class="responsive-panels-region responsive-panels-region-<?php print $settings['position']; ?> <?php print $settings['css_classes']; ?>">
  <div class="responsive-panels-region-inner">
    <?php print implode('<div class="panel-separator"></div>', $panes); ?>
  </div>
</div>
