<?php
/**
 * @file
 * Provides theming for oa_related_files widget.
 *
 * $files - Array of files to display.
 */
?>

<div class="oa-related-files">
  <?php foreach ($files as $file):?>
    <div class="oa-related-file">
      <div class="oa-related-image"><?php print $file['render'];?></div>
      <div class="oa-related-title"><?php print $file['title'];?></div>
      <div class="oa-related-size"><?php print $file['size'];?></div>
    </div>
  <?php endforeach; ?>
</div>
