<?php
/**
 * @file
 * Template for Radix Webb.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display webb clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container">
    <div class="row">
      <div class="col-md-12 header panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['header']; ?>
        </div>
      </div>
    </div>

    <div class="row">
      <div class="col-md-8 content panel-panel">
        <div class="row">
          <div class="col-md-12 content-header panel-panel">
            <div class="panel-panel-inner">
              <?php print $content['contentheader']; ?>
            </div>
          </div>
        </div>
        <div class="row">
          <div class="col-md-6 contentcolumn1 panel-panel">
            <div class="panel-panel-inner">
              <?php print $content['contentcolumn1']; ?>
            </div>
          </div>
          <div class="col-md-6 contentcolumn2 panel-panel">
            <div class="panel-panel-inner">
              <?php print $content['contentcolumn2']; ?>
            </div>
          </div>
        </div>
      </div>
      <div class="col-md-4 sidebar panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['sidebar']; ?>
        </div>
      </div>
    </div>
  </div>

</div><!-- /.webb -->
