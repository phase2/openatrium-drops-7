<?php
/**
 * @file
 * Template to control the add content individual links in the add content modal.
 */
?>
<div class="content-type-button clearfix">
  <?php if (isset($icon_text_button)) {
    print $icon_text_button;
  } else {
    print $image_button; ?>
    <div><?php print $text_button; ?></div>
  <?php  } ?>
</div>
