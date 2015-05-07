<?php
/**
 * @file
 * Template for the paragraph_text bundle.
 *
 * Available variables:
 * - $title: The parent comment for a reply.
 * - $text: Wysiwyg text area for the text with format selector.
 * - $layout: Layout selector field.
 * - $action_links: Submit buttons.
 */
?>
<div class="oa-related-paragraph-form paragraph-text">
  <div class="paragraph-title">
    <?php print $title; ?>
  </div>
  <div class="row">
    <div class="col-xs-12">
      <div class="text-content">
        <?php print $text; ?>
      </div>
      <div class="text-layout">
        <?php print $layout; ?>
      </div>
      <?php if ($action_links): ?>
        <div class="paragraph-action-links related-text">
          <?php print $action_links; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
