<?php
/**
 * @file
 *
 * Theme implementation to display the page messages.
 *
 * Additional items can be added via theme_preprocess_pane_messages(). See
 * template_preprocess_pane_messages() for examples.
 */
?>
<?php if (!empty($messages)): ?><?php print $messages; ?><?php endif; ?>
