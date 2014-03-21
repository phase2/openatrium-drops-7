<?php
/**
 * @file
 * Template for Panopoly Bartlett Flipped.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display bartlett-flipped clearfix container <?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row-fluid">
    <div class="bartlett-flipped-content-container bartlett-flipped-container span9">
      <div class="bartlett-flipped-content-container-inner bartlett-flipped-container-inner row-fluid">
        <div class="bartlett-flipped-column-content-region bartlett-flipped-content-header clearfix panel-panel span12">
          <div class="bartlett-flipped-column-content-region-inner bartlett-flipped-content-header-inner panel-panel-inner">
            <?php print $content['contentheader']; ?>
          </div>
        </div>

        <div class="bartlett-flipped-content-container-column-container clearfix row-fluid">
          <div class="bartlett-flipped-column-content-region bartlett-flipped-content-column1 bartlett-flipped-column panel-panel span6">
            <div class="bartlett-flipped-column-content-region-inner bartlett-flipped-content-column1-inner bartlett-flipped-column-inner panel-panel-inner">
              <?php print $content['contentcolumn1']; ?>
            </div>
          </div>
          <div class="bartlett-flipped-column-content-region bartlett-flipped-content-column2 bartlett-flipped-column panel-panel span6">
            <div class="bartlett-flipped-column-content-region-inner bartlett-flipped-content-column2-inner bartlett-flipped-column-inner panel-panel-inner">
              <?php print $content['contentcolumn2']; ?>
            </div>
          </div>
        </div><!-- /.bartlett-flipped-content-container-column-container -->
      </div>
    </div><!-- /.bartlett-flipped-content-container -->

    <div class="bartlett-flipped-column-content-region bartlett-flipped-column bartlett-flipped-container bartlett-flipped-sidebar panel-panel span3">
      <div class="bartlett-flipped-sidebar-inner bartlett-flipped-column-content-region-inner bartlett-flipped-column-inner bartlett-flipped-container-inner panel-panel-inner">
        <?php print $content['sidebar']; ?>
      </div>
    </div>
  </div>
</div><!-- /.bartlett-flipped -->
