<?php
/**
 * @file
 *
 * Theme implementation to display the help text for a page
 *
 * Additional items can be added via theme_preprocess_pane_help(). See
 * template_preprocess_pane_help() for examples.
 */
?>
<?php if (!empty($help)): ?><?php print $help; ?><?php endif; ?>
