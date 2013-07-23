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
    <a class="btn btn-small" href="<?php print $button['link'];?>" title="<?php print $button['title'];?>">
      <i class="<?php print $button['icon'];?>"></i>&nbsp;<?php print $button['title'];?>
    </a>
  </li>
  <?php elseif (!empty($button['render'])): ?>
  <li>
    <?php print $button['render']; ?>
  </li>
  <?php endif; ?>
  <?php endforeach; ?>
  <?php if (!empty($links)): ?>
    <li class="dropdown btn-group">
      <a class="dropdown-toggle btn btn-small" id="contextual-dropdown" data-toggle="dropdown" href="#" title="<?php print $title?>">
        <i class="icon-cog"></i><span><?php print t('Configure');?></span>
      </a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="contextual-dropdown">
        <li class="dropdown-column"><?php print $links; ?></li>
      </ul>
    </li>
  <?php endif; ?>
</ul>
