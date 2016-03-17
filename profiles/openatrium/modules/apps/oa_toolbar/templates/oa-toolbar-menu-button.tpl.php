<?php
/**
 * @file
 * Provides the view for the toolbar menu button.
 *
 * $oa_toolbar_btn_class - Style to append to button
 */
?>

<div id="toolbar-menu-button" class="toggle-tray <?php print $oa_toolbar_btn_class; ?>">
  <?php if (!empty($icon)): ?>
    <i class="<?php print $icon;?>"></i>
  <?php endif; ?>
  <span><?php print $caption; ?></span>
  <?php if (!empty($show_caret)): ?>
    <span class="caret"></span>
  <?php endif; ?>
</div>


