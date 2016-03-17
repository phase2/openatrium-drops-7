<?php
/**
 * @file
 * Template for OA Navigation.
 */
?>
<?php if (!empty($menu) || !empty($banner)): ?>
  <div class="oa-navigation">
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
<?php endif; ?>
