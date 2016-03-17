<?php
/**
 * @file
 * Template for oa_space_config pane.
 */
?>
<ul class="oa-space-config oa_toolbar">
  <div class='dropdown btn-group'>
    <a href="#" class='dropdown-toggle <?php print $btn_class; ?> <?php print $direction; ?>' data-toggle='dropdown' title="<?php print $title?>">
      <i class="<?php print $icon; ?>"></i><span class="element-invisible"><?php print $title;?></span>
    </a>
    <ul class="dropdown-menu" role="menu">
      <li class="dropdown-column">
        <?php if (!empty($top_links)): ?>
          <div class="item-list oa-border-bottom">
            <?php if (!empty($title)): ?>
              <h4><?php print t('Page tasks'); ?></h4>
            <?php endif; ?>
            <?php print $top_links; ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($admin_links)): ?>
          <div class="item-list">
            <h3><a href="<?php print $space_url; ?>"><?php print $space_title; ?></a></h3>
            <h4><?php print t('Space tasks'); ?></h4>
            <?php if (!empty($admin_links)): ?>
              <?php print $admin_links; ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <?php if (!empty($config_links)): ?>
          <div class="item-list">
            <h4 class="oa-border-top"><?php print t('Space configuration'); ?></h4>
              <?php print $config_links; ?>
          </div>
        <?php endif; ?>
      </li>
    </ul>
  </div>
</ul>
