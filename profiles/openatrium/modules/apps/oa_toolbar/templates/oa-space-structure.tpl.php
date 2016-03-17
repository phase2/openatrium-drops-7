<?php
/**
 * @file
 * This template handles the layout of oa_space_structure pane.
 */
?>
<ul class="oa-space-structure oa_toolbar">
  <li class="dropdown btn-group">
    <a href="#" class="dropdown-toggle <?php print $oa_toolbar_btn_class; ?>" title="<?php print $icon_title; ?>" data-toggle="dropdown">
      <i class="<?php print $icon; ?>"></i><span class='element-invisible'><?php print $icon_title; ?></span>
    </a>
    <?php if (!empty($links)): ?>
      <ul class="dropdown-menu oa-noscroll" id="oa-space-menu" role="menu">
        <li><?php print $links; ?></li>
      </ul>
    <?php endif; ?>
  </li>
</ul>
