<?php
/**
 * @file
 * This template handles the theme output of command buttons.
 * $items - array of list items
 * $use_dropdowns - TRUE to use dropdown menus, false for just list
 * $wrapper_class - classes for dropdown wrapper
 * $label - caption of main button
 */
?>
<?php if ($use_dropdowns): ?>
<ul class="command-button-wrapper">
  <li class="dropdown btn-group">
    <a class="dropdown-toggle <?php print $wrapper_class; ?>" data-toggle="dropdown" title="<?php print $label; ?>" href="#"><?php print $label; ?>
      <span class="caret"></span>
    </a>
    <?php if (!empty($items)):?>
      <ul class="command-buttons dropdown-menu">
        <?php print implode('', $items); ?>
      </ul>
    <?php endif; ?>
  </li>
</ul>
<?php elseif (!empty($items)): ?>
  <div class="btn-group">
    <ul class="command-buttons"><?php print implode('', $items); ?></ul>
  </div>
<?php endif; ?>
