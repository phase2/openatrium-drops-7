<?php
/**
 * @file
 * This template handles the mobile buttons for oa_toolbar.
 */
?>
<div class="panel-panel clearfix">
  <div class="pane-oa-mobile">
    <div class="mobile-menu-icons clearfix">
      <?php if (user_is_logged_in()): ?>
        <button type="button" class="navbar-toggle user" data-toggle="collapse" data-target="#oa-navbar-user">
        </button>
      <?php else: ?>
        <div class="navbar-toggle user" data-target="#oa-navbar-user">
        </div>
      <?php endif; ?>

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
    <div class="collapse navbar-collapse" id="oa-navbar-spaces"></div>
    <div class="collapse navbar-collapse" id="oa-navbar-admin"></div>
    <div class="collapse navbar-collapse" id="oa-navbar-search"></div>
    <div class="collapse navbar-collapse" id="oa-navbar-user"></div>
  </div>
</div>

