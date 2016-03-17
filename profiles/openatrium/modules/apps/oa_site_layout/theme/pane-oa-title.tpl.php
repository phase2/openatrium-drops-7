<?php
/**
 * @file
 *
 * Theme implementation to display the page title
 *
 */
?>
<?php print render($title_prefix); ?>
<?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
<?php print render($title_suffix); ?>
