<?php
/**
 * @file
 * This template handles the layout of oa_breadcrumb.
 */
?>
<?php if (!empty($mainmenu)): ?>
  <?php print $mainmenu ?>
<?php else: ?>
<ul id="oa_breadcrumb" class="oa_toolbar">
  <?php if (!empty($space_label)): ?>
    <li class="btn-group oa-breadcrumb">
      <a href="<?php print $home_url; ?>" class="btn btn-home <?php print $oa_toolbar_btn_class; ?>"><i class="icon-home"></i><span class='element-invisible'>Home</span></a>
      <?php if (!empty($home_spaces)): ?>
        <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="parent-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
        <ul class="dropdown-menu" role="menu" aria-labelledby="home-dropdown">
          <li><?php print $home_spaces; ?></li>
        </ul>
      <?php endif; ?>
    </li>
    <?php if (!empty($parent_label)): ?>
      <?php if (empty($sibling_list) && empty($parent_list)): ?>
      <li class="btn-group oa-breadcrumb">
        <a href="<?php print $parent_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $parent_label; ?></a>
      </li>
      <?php else: ?>
      <li class="btn-group oa-breadcrumb dropdown">
        <a href="<?php print $parent_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $parent_label; ?></a>
        <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="sibling-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
        <ul class="dropdown-menu" role="menu" aria-labelledby="sibling-dropdown">
          <?php if (!empty($parent_list)): ?>
            <li><?php print $parent_list; ?></li>
          <?php endif; ?>
          <?php if (!empty($sibling_list)): ?>
            <li><?php print $sibling_list; ?></li>
          <?php endif; ?>
        </ul>
      </li>
      <?php endif; ?>
    <?php endif; ?>
    <li class="btn-group oa-breadcrumb">
      <a href="<?php print $space_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $space_label; ?></a>
      <?php if (!empty($subspaces) || !empty($sections_list)): ?>
        <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="subspace-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
        <ul class="dropdown-menu" role="menu" aria-labelledby="subspace-dropdown">
          <?php if (!empty($subspaces)): ?>
            <li><?php print $subspaces; ?></li>
          <?php endif; ?>
          <?php if (!empty($sections_list)): ?>
            <li><?php print $sections_list; ?></li>
          <?php endif; ?>
        </ul>
      <?php endif; ?>
    </li>
    <?php if (!empty($section_label)): ?>
    <li class="btn-group oa-breadcrumb">
      <?php if (!empty($section_label)): ?>
        <a href="<?php print $section_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $section_label; ?></a>
      <?php endif; ?>
    </li>
    <?php endif; ?>
  <?php endif; ?>
</ul>
<?php endif; ?>
