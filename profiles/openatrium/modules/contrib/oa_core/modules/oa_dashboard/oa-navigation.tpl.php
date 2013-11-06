<?php
/**
 * @file
 * Template for OA Navigation.
 */
?>
<?php if (!empty($menu) || !empty($banner)): ?>
<div class="oa-navigation clearfix">
  <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
  <a class="btn btn-navbar btn-navbar-menu">
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
  </a>

  <div class="nav-collapse nav-menu-collapse">
    <nav class="main-menu pull-left" role="navigation">
      <?php if (!empty($banner)): ?>
      <div class='oa-banner oa-menu-banner oa-banner-before' data-width='<?php print $width?>' data-height='<?php print $height?>'>
        <?php print $banner?>
      </div>
      <?php endif; ?>
      <?php if (!empty($menu)): ?>
        <?php print render($menu); ?>
      <?php endif; ?>
    </nav>
  </div>
</div>
<?php endif; ?>
