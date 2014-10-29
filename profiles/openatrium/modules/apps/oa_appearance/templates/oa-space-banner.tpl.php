<?php
/**
 * @file
 * Provides template for space banner
 *
 * $banner - Banner image.
 * $text - Banner text
 */
?>

<?php if (!empty($banner)): ?>
<div class='oa-banner <?php print $banner_class?>' data-width='<?php print $width?>' data-height='<?php print $height?>'>
  <?php print $banner?>
  <?php if (!empty($slogan)): ?>
  <div class='<?php print $banner_slogan_class?>'>
    <?php print $slogan; ?>
  </div>
  <?php endif; ?>
  <?php if (!empty($text)): ?>
  <div class='<?php print $banner_text_class?>'>
    <?php print $text; ?>
  </div>
  <?php endif; ?>
</div>
<?php endif; ?>
