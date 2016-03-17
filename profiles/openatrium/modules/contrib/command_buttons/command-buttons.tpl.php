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
  <li class="dropdown btn-group <?php print $direction; ?>">
    <a class="dropdown-toggle <?php print $wrapper_class; ?>" data-toggle="dropdown" title="<?php print $btn_title; ?>" href="#">
      <?php if (!empty($icon)): ?>
        <i class="<?php print $icon;?>"></i>
      <?php endif; ?>
      <?php print $label; ?>
      <?php if (!empty($show_caret)): ?>
        <span class="caret"></span>
      <?php endif; ?>
    </a>
    <?php if (!empty($items)):?>
      <ul class="command-buttons dropdown-menu">
        <?php print implode('', $items); ?>
      </ul>
    <?php endif; ?>
  </li>
</ul>
<?php elseif (!empty($items)): ?>
  <div class="btn-group btn-group-justified">
    <ul class="command-buttons"><?php print implode('', $items); ?></ul>
  </div>
<?php endif; ?>
