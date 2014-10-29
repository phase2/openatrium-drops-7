<?php
/**
 * @file
 * Provides view for favorites button.
 *
 * $spaces_favorite - Rendered list for space favorites.
 */
?>
<ul id="oa_favorites">
  <li class="dropdown btn-group">
    <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="favorites-dropdown" data-toggle="dropdown" href="#" title="<?php print $title?>">
      <i class="icon-star"></i><span class="element-invisible"><?php print t('Favorites');?></span>
    </a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="space-dropdown">
      <li class="dropdown-column"><?php print $spaces_favorite; ?></li>
    </ul>
  </li>
</ul>
