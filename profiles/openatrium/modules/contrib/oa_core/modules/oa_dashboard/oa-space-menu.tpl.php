<?php
/**
 * @file
 * Template for OA Space Menu.
 */
?>
<?php if (!empty($menu)): ?>
<div class='navbar navbar-inverse oa-space-menu'>
  <div class='navbar-inner'>
    <nav class="oa-space-menu pull-left" role="navigation">
      <?php if (!empty($banner)): ?>
      <div class='oa-menu-banner'>
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
