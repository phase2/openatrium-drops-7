<?php
/**
 * @file
 *
 * Theme implementation to display the page tabs.
 *
 * This utilizes the following variables that are normally found in
 * page.tpl.php:
 * - $tabs
 *
 * Additional items can be added via theme_preprocess_pane_tabs(). See
 * template_preprocess_pane_tabs() for examples.
 */
?>
<?php if (!empty($breadcrumb)): ?>
  <div id="breadcrumb" class="visible-desktop">
    <?php print $breadcrumb; ?>
  </div>
<?php endif; ?>
