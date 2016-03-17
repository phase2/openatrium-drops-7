<?php
/**
 * @file
 * This template handles the layout of oa_space_nav pane.
 */
?>
<?php if (!empty($space_label)): ?>
<ul class="oa-space-nav oa_toolbar">
  <li class="btn-group oa-no-separator dropdown oa-space-list">
    <a href="<?php print $space_url; ?>" class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" data-toggle="dropdown" data-target="#">
      <?php print $space_label; ?>
    </a>
    <ul class="dropdown-menu" id="oa-subspace-menu" role="menu" aria-labelledby="subspace-dropdown">
      <?php if (!empty($parent_list)): ?>
        <li class="oa-hierarchy"><?php print $parent_list; ?>
        <ul>
      <?php endif; ?>
      <li class="oa-hierarchy"><?php print $current_space; ?>
      <ul>
        <?php if (!empty($sections_list)): ?>
          <li class="oa-hierarchy oa-sections"><?php print $sections_list; ?></li>
        <?php endif; ?>
        <?php if (!empty($subspace_list)): ?>
          <li class="oa-hierarchy oa-subspaces"><?php print $subspace_list; ?></li>
        <?php endif; ?>
      </ul></li>
      <?php if (!empty($parent_list)): ?>
        </ul></li>
      <?php endif; ?>
    </ul>
  </li>
  <?php if (!empty($section_label)): ?>
    <li class="btn-group oa-separator">
    </li>
    <li class="btn-group oa-no-separator dropdown oa-section-list">
      <a href="<?php print $section_url; ?>" class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" data-toggle="dropdown" data-target="#">
        <?php print $section_label; ?>
      </a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="subspace-dropdown">
        <?php if (!empty($sections_list)): ?>
          <li><?php print $sections_list; ?></li>
        <?php endif; ?>
      </ul>
    </li>
  <?php endif; ?>
</ul>
<?php endif; ?>
