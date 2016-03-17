<?php
/**
 * @file
 * Provides view for contexual tabs.
 *
 */
?>
<ul id="contextual-tabs">
  <?php foreach ($buttons as $button): ?>
  <?php if (!empty($button['link'])): ?>
  <li>
    <a class="btn <?php print $btn_class; ?>" href="<?php print $button['link'];?>" title="<?php print $button['title'];?>">
      <?php if (!empty($button['icon'])): ?>
        <i class="<?php print $button['icon'];?>"></i>
      <?php endif; ?>
      <?php if ($show_captions): ?>
        &nbsp;<?php print $button['title'];?>
      <?php endif; ?>
    </a>
  </li>
  <?php elseif (!empty($button['render'])): ?>
  <li>
    <?php print $button['render']; ?>
  </li>
  <?php endif; ?>
  <?php endforeach; ?>
  <?php if (!empty($links)): ?>
    <li class="dropdown <?php print $direction;?> <?php print $alignment;?> btn-group">
      <a class="dropdown-toggle btn <?php print $btn_class; ?>" id="contextual-dropdown" data-toggle="dropdown" href="#" title="<?php print $title?>">
        <i class="<?php print $icon_class;?>"></i><span><?php print $menu_caption;?></span>
      </a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="contextual-dropdown">
        <li class="dropdown-column"><?php print $links; ?></li>
      </ul>
    </li>
  <?php endif; ?>
</ul>
