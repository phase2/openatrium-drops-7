<?php
/**
 * @file
 * Template for Open Atrium Site Layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<div class="panel-display oa-site-layout-default clearfix <?php if (!empty($classes)) { print $classes; } ?><?php if (!empty($class)) { print $class; } ?>" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="container-fluid oa-flex-column">
    <div class="row">
      <div class="col-md-12 oa-layout-traytop panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['traytop']; ?>
        </div>
      </div>
    </div>

    <div class="row">
      <header class="col-md-12 oa-layout-header panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['header']; ?>
        </div>
      </header>
    </div>

    <div class="row oa-flex-grow">
      <div class="col-md-3 oa-layout-sidebar1 panel-panel pull-left">
        <div class="panel-panel-inner">
          <?php print $content['sidebar1']; ?>
        </div>
      </div>

      <section id="main-wrapper" class="panel-panel oa-layout-fluid">
        <div id="main" class="main container row">
          <div class="col-md-12 oa-layout-contentheader panel-panel">
            <div class="panel-panel-inner">
              <?php print $content['contentheader']; ?>
            </div>
          </div>
          <a id="main-content"></a>
          <div class="col-md-12 oa-layout-content content panel-panel">
            <div class="panel-panel-inner">
              <?php print $content['content']; ?>
            </div>
          </div>
          <div class="col-md-12 oa-layout-contentfooter panel-panel">
            <div class="panel-panel-inner">
              <?php print $content['contentfooter']; ?>
            </div>
          </div>
        </div>
      </section>

      <div class="col-md-3 oa-layout-sidebar2 panel-panel pull-right">
        <div class="panel-panel-inner">
          <?php print $content['sidebar2']; ?>
        </div>
      </div>
    </div>

    <div id='footer' class="row">
      <footer class="col-md-12 oa-layout-footer panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['footer']; ?>
        </div>
      </footer>
    </div>

    <div class="row">
      <div class="col-md-12 oa-layout-traybottom panel-panel">
        <div class="panel-panel-inner">
          <?php print $content['traybottom']; ?>
        </div>
      </div>
    </div>

  </div>
</div>
