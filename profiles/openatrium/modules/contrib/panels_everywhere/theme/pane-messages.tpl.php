<?php
/**
 * @file
 *
 * Theme implementation to display the messages area, which is normally
 * included roughly in the content area of a page.
 *
 * This utilizes the following variables that are normally found in
 * page.tpl.php:
 * - $tabs
 * - $messages
 * - $help
 *
 * The $action_links is loaded from CTools and is a cleaned up version of the
 * core functionality.
 *
 * Additional items can be added via theme_preprocess_pane_messages(). See
 * template_preprocess_pane_messages() for examples.
 */
?>
<?php if (!empty($tabs) && (!empty($tabs['#primary']) || !empty($tabs['#secondary']))): ?>
  <div class="tabs"><?php print render($tabs); ?></div>
<?php endif; ?>
<?php if (!empty($action_links)): ?><?php print $action_links; ?><?php endif; ?>
<?php if (!empty($messages)): ?><?php print $messages; ?><?php endif; ?>
<?php if (!empty($help)): ?><?php print $help; ?><?php endif; ?>
