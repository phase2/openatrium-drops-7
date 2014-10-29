<?php
/**
 * @file
 * Template for OA Navigation.
 */
?>
<?php if (!empty($menu) || !empty($banner)): ?>
  <div class="oa-navigation clearfix">
    <div class="mobile-menu-icons clearfix">
      <button type="button" class="navbar-toggle user" data-toggle="collapse" data-target="#oa-navbar-user">
      </button>

      <button type="button" class="navbar-toggle" data-toggle="collapse"
              data-target="#oa-navbar-header">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>

      <button type="button" class="navbar-toggle spaces" data-toggle="collapse"
              data-target="#oa-navbar-spaces">
        <span class="sr-only">Toggle navigation</span>
        <span class="fa fa-square odd first"></span>
        <span class="fa fa-square even second"></span>
        <span class="fa fa-square odd third"></span>
        <span class="fa fa-square even fourth"></span>
      </button>

      <button type="button" class="navbar-toggle search" data-toggle="collapse"
              data-target="#oa-navbar-search">
        <span class="sr-only">Toggle navigation</span>
        <span class="fa fa-search"></span>
      </button>

      <button type="button" class="navbar-toggle admin" data-toggle="collapse"
              data-target="#oa-navbar-admin">
        <span class="sr-only">Toggle navigation</span>
        <span class="fa fa-drupal"></span>
      </button>
    </div>


    <div class="collapse navbar-collapse" id="oa-navbar-header">
      <nav class="main-menu pull-left" role="navigation">
        <?php if (!empty($banner)): ?>
          <div class='oa-banner oa-menu-banner oa-banner-before'
               data-width='<?php print $width ?>'
               data-height='<?php print $height ?>'>
            <?php print $banner ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($menu)): ?>
          <?php print render($menu); ?>
        <?php endif; ?>
      </nav>
    </div>
  <div class="collapse navbar-collapse" id="oa-navbar-spaces"></div>
  <div class="collapse navbar-collapse" id="oa-navbar-admin"></div>
  <div class="collapse navbar-collapse" id="oa-navbar-search"></div>
  <div class="collapse navbar-collapse" id="oa-navbar-user"></div>
  </div>
<?php endif; ?>