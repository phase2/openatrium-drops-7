<?php
/**
 * @file
 * Provides view for tour dropown
 *
 * $tours - Rendered list for available site tours
 */
?>
<?php if ($tours): ?>
  <ul id="oa_tours">
    <li class="dropdown btn-group">
      <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="tours-dropdown" data-toggle="dropdown" href="#" title="<?php print $title?>">
        <i class="icon-question-sign"></i><span class="element-invisible"><?php print t('Site Tours');?></span>
      </a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="space-dropdown">
        <li class="dropdown-column">
          <?php print $tours; ?>
        </li>
      </ul>
    </li>
  </ul>
<?php endif; ?>
