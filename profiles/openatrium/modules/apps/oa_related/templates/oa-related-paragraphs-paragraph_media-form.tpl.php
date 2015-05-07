<?php
/**
 * @file
 * Template for the paragraph_media bundle.
 *
 * Available variables:
 * - $title: The parent comment for a reply.
 * - $media_widget: Upload widget for adding media.
 * - $layout: Layout selector field.
 * - $action_links: Submit buttons.
 */
?>
<div class="oa-related-paragraph-form paragraph-media">
  <div class="paragraph-title">
    <?php print $title; ?>
  </div>
  <div class="row">
    <div class="row-same-height">
      <div class="col-sm-9 col-xs-12 text-center">
        <?php print $media_widget; ?>
      </div>
      <div class="col-sm-3 col-xs-12 text-center">
        <div class="layout-select">
          <?php print $layout; ?>
        </div>
        <?php if ($action_links): ?>
          <div class="paragraph-action-links related-media">
            <?php print $action_links; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
