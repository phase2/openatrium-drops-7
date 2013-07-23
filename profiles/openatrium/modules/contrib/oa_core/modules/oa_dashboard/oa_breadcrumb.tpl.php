<?php
/**
 * @file
 * This template handles the layout of oa_breadcrumb.
 */
?>
<ul id="oa_breadcrumb" class="oa_toolbar">
  <?php if (!empty($space_label)): ?>
    <li class="btn-group oa-breadcrumb">
      <a href="<?php print $home_url; ?>"><i class="icon-home"></i><span class='element-invisible'>Home</span></a>
    </li>
    <?php if (!empty($parent_list)): ?>
      <li class="btn-group dropdown no-breadcrumb">
        <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="parent-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
        <ul class="dropdown-menu" role="menu" aria-labelledby="parent-dropdown">
          <li class="dropdown-column"><?php print $parent_list; ?></li>
        </ul>
      </li>
    <?php endif; ?>
    <?php if (!empty($parent_label)): ?>
      <?php if (empty($sibling_list)): ?>
      <li class="btn-group oa-breadcrumb">
        <a href="<?php print $parent_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $parent_label; ?></a>
      </li>
      <?php else: ?>
      <li class="btn-group oa-breadcrumb dropdown">
        <a href="<?php print $parent_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $parent_label; ?></a>
        <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="sibling-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
        <ul class="dropdown-menu" role="menu" aria-labelledby="sibling-dropdown">
          <li class="dropdown-column"><?php print $sibling_list; ?></li>
        </ul>
      </li>
      <?php endif; ?>
    <?php endif; ?>
    <?php if (empty($spaces_recent)): ?>
      <li class="btn-group oa-breadcrumb">
        <a href="<?php print $space_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $space_label; ?></a>
      </li>
    <?php else: ?>
      <li class="btn-group oa-breadcrumb dropdown">
        <a href="<?php print $space_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $space_label; ?></a>
        <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="space-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
        <ul class="dropdown-menu" role="menu" aria-labelledby="space-dropdown">
          <li class="dropdown-column"><?php print $spaces_recent; ?></li>
        </ul>
      </li>
    <?php endif; ?>
    <?php if (!empty($section_label)): ?>
    <li class="dropdown btn-group oa-breadcrumb">
      <a href="<?php print $section_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $section_label; ?></a>
      <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="section-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
        <li class="dropdown-column"><?php print $sections_list; ?></li>
      </ul>
    </li>
    <?php endif; ?>
  <?php endif; ?>
</ul>
