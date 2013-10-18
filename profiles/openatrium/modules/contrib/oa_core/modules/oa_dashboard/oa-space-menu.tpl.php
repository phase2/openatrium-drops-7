<?php
/**
 * @file
 * Template for OA Space Menu.
 */
?>
<?php if (!empty($menu)): ?>
<div class='navbar navbar-inverse oa-space-menu'>
  <div class='navbar-inner'>
    <nav class="oa-space-menu pull-left" role="navigation">
      <?php print render($menu); ?>
    </nav>
  </div>
</div>
<?php endif; ?>
