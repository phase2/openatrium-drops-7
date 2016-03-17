<?php
/**
 * @file
 *
 * Theme implementation to display the messages area, which is normally
 * included roughly in the content area of a page.
 *
 * This utilizes the following variables thata re normally found in
 * page.tpl.php:
 * - $main_menu
 * - $secondary_menu
 * - $breadcrumb
 * - $mission
 *
 * Additional items can be added via theme_preprocess_pane_messages(). See
 * template_preprocess_pane_messages() for examples.
 */
?>
<div id="navigation" class="menu <?php if (!empty($main_menu)) { print "withprimary"; } if (!empty($secondary_menu)) { print " withsecondary"; } ?> ">
  <?php if (!empty($main_menu)): ?>
    <div id="primary" class="clearfix">
      <?php print $main_menu; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($secondary_menu)): ?>
    <div id="secondary" class="clearfix">
      <?php print $secondary_menu; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($breadcrumb)): ?>
    <div id="breadcrumb"><?php print $breadcrumb; ?></div>
  <?php endif; ?>
  <?php if (!empty($mission)): ?>
    <div id="mission"><?php print $mission; ?></div>
  <?php endif; ?>

</div> <!-- /navigation -->
