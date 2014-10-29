<?php
/**
 * @file
 * Template for Radix Selby.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display selby clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container">
    <div class="row">
      <div class="col-md-4 sidebar panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['sidebar']; ?>
        </div>
      </div>
      <div class="col-md-8 content panel-panel">
        <div class="row">
          <div class="col-md-12 header panel-panel">
            <?php print $content['contentheader']; ?>
          </div>
        </div>
        <div class="row">
          <div class="col-md-6 column1 panel-panel">
            <?php print $content['contentcolumn1']; ?>
          </div>
          <div class="col-md-6 column1 panel-panel">
            <?php print $content['contentcolumn1']; ?>
          </div>
        </div>
        <div class="row">
          <div class="col-md-12 footer panel-panel">
            <?php print $content['contentfooter']; ?>
          </div>
        </div>
      </div>
    </div>
  </div>

</div><!-- /.selby -->
