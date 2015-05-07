<?php
/**
 * @file
 * Template for the paragraph_content bundle.
 *
 * Available variables:
 * - $title: The name of the type of paragraph item it is.
 * - $related_content: Auto-complete field and links to add new sections.
 * - $layout: Layout selector field.
 * - $action_links: Submit buttons.
 */
?>
<div class="oa-related-paragraph-form paragraph-content">
  <div class="paragraph-title">
    <?php print $title; ?>
  </div>
  <div class="row">
    <div class="row-same-height">
      <div class="col-sm-9 col-xs-12">
        <?php print $related_content; ?>
      </div>
      <div class="col-sm-3 col-xs-12 text-center">
        <div class="layout-select margin-top">
          <?php print $layout; ?>
        </div>
        <?php if ($action_links): ?>
          <div class="paragraph-action-links related-content">
            <?php print $action_links; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
