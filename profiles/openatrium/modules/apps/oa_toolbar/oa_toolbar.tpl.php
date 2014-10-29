<?php
/**
 * @file
 * This template handles the layout of oa_toolbar.
 */
?>
<ul id="oa_toolbar" class="oa_toolbar">
  <?php if (!empty($space_label)): ?>
    <li class="btn-group">
      <a href="<?php print $home_url; ?>"><i class="icon-home"></i><span class='element-invisible'>Home</span></a>
    </li>
    <li class="dropdown btn-group">
      <a href="<?php print $space_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $space_label; ?></a>
      <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="space-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="space-dropdown">
        <li class="dropdown-column"><?php print $spaces_favorite; ?></li>
        <li class="dropdown-column"><?php print $spaces_recent; ?></li>
      </ul>
    </li>
    <?php if (!empty($section_label)): ?>
    <li class="dropdown btn-group">
      <a href="<?php print $section_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $section_label; ?></a>
      <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="section-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
        <li class="dropdown-column"><?php print $sections_list; ?></li>
      </ul>
    </li>
    <?php endif; ?>
  <?php endif; ?>
</ul>
