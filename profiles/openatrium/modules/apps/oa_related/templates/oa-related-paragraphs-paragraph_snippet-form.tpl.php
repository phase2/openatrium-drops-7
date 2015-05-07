<?php
/**
 * @file
 * Template for the paragraph_snippet bundle.
 *
 * Available variables:
 * - $title: The parent comment for a reply.
 * - $content: Upload widget for adding media.
 * - $lock_revision: Checkbox to lock the revision with help text.
 * - $show_title: Checkbox to allow user to show title.
 * - $title_override: Text field used to override the title.
 * - $view_mode: Selector to display the part of the snippet you want to see.
 * - $layout: Layout selector field.
 * - $action_links: Submit buttons.
 */
?>
<div class="oa-related-paragraph-form paragraph-snippet">
  <div class="paragraph-title">
    <?php print $title; ?>
  </div>
  <div class="row">
    <div class="row-same-height">
      <div class="col-sm-8  col-xs-12 text-center">
        <div class="snippet-content">
          <?php print $content; ?>
        </div>
        <div class="snippet-show-title pull-left">
          <?php print $show_title; ?>
        </div>
        <div class="snippet-title-override">
          <?php print $title_override; ?>
        </div>
      </div>

      <div class="col-sm-4 col-xs-12">
        <div class="text-center">
          <div class="view-mode">
            <?php print $view_mode; ?>
          </div>
          <div class="layout-select margin-top">
            <?php print $layout; ?>
          </div>
        </div>
        <div class="snippet-lock-revision margin-top">
          <?php print $lock_revision; ?>
        </div>
        <?php if ($action_links): ?>
          <div class="paragraph-action-links related-snippet">
            <?php print $action_links; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
