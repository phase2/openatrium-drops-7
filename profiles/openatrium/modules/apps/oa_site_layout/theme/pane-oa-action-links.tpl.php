<?php
/**
 * @file
 *
 * Theme implementation to display the action_links.
 *
 * Additional items can be added via theme_preprocess_pane_action_links(). See
 * template_preprocess_pane_action_links() for examples.
 */
?>
<?php if (!empty($action_links)): ?><?php print $action_links; ?><?php endif; ?>
