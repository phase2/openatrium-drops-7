<?php
/**
 * @file
 * Template for Panopoly Brenham.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display brenham clearfix container <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="brenham-container brenham-header clearfix panel-panel row-fluid">
    <div class="brenham-container-inner brenham-header-inner panel-panel-inner span12">
      <?php print $content['header']; ?>
    </div>
  </div>
  
  <div class="brenham-container brenham-column-content clearfix row-fluid">
    <div class="brenham-column-content-region brenham-sidebar panel-panel span3">
      <div class="brenham-column-content-region-inner brenham-sidebar-inner panel-panel-inner">
        <?php print $content['sidebar']; ?>
      </div>
    </div>
    <div class="brenham-column-content-region brenham-content panel-panel span9">
      <div class="brenham-column-content-region-inner brenham-content-inner panel-panel-inner">
        <?php print $content['contentmain']; ?>
      </div>
    </div>
  </div>
</div><!-- /.brenham -->
