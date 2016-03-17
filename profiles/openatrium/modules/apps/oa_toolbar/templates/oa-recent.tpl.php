<?php
/**
 * @file
 * This template handles the layout of oa_recent pane.
 */
?>
<ul class="oa-recent oa_toolbar">
  <li class="btn-group oa-no-separator dropdown">
    <a href="#" class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" title="<?php print $icon_title; ?>" data-toggle="dropdown">
      <i class="<?php print $icon; ?>"></i><span class='element-invisible'><?php print $icon_title; ?></span>
    </a>
    <?php if (!empty($home_spaces)): ?>
      <ul class="dropdown-menu" id="oa-space-menu" role="menu">
        <li class="oa-multicolumn">
        <?php if (!empty($home_spaces)): ?>
          <div class="oa-column">
            <?php print $home_spaces; ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($spaces_favorite)): ?>
          <div class="oa-column">
            <?php print $spaces_favorite; ?>
          </div>
        <?php endif; ?>
        </li>
      </ul>
    <?php endif; ?>
  </li>
</ul>
