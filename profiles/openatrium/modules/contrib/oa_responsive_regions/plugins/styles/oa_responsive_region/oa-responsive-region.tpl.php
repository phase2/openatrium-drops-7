<?php
/**
 * @file
 * Template file for OA Responsive Region.
 */
?>
<div class="<?php print $classes; ?> <?php print $settings['css_classes']; ?>" data-position="<?php print $settings['position']; ?>">
  <div class="oa-responsive-region-inner">
    <?php print implode('<div class="panel-separator"></div>', $panes); ?>
  </div>
</div>
