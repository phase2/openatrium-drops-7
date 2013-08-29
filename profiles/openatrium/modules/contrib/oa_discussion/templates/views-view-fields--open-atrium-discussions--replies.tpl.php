<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<div class='oa-list oa-discussion-reply well clearfix <?php print $current_class; ?> <?php print $status_class; ?> <?php print $nid_class; ?>'>
  <div class='pull-right user-badge no-border'>
    <?php print $name; ?>
    <?php print $field_user_picture; ?>
  </div>
  <div class="accordion" id="oa-reply-accordion-<?php print $index; ?>">
    <div class="accordion-heading">
      <?php print $counter; ?>
      <div class="accordion-toggle" data-toggle="collapse" data-parent="#oa-reply-accordion-<?php print $index; ?>" href="#oa-reply-body-<?php print $index; ?>">
        <div class='oa-list-header oa-description '>
          <div class='pull-right'>
            <?php if (!empty($unpublished)): ?>
              <span class="status"><?php print $unpublished; ?></span>
            <?php endif; ?>
            <?php print $timestamp; ?>
            <?php print $created; ?>
          </div>
        </div>
        <h5>
          <?php print empty($body_1) ? $title : $body_1; ?>
        </h5>
      </div>
      <div id="oa-reply-body-<?php print $index; ?>" class="accordion-body collapse <?php print $in; ?>">
        <div class="accordion-inner">
          <?php print $body; ?>
          <?php print $field_oa_media; ?>
          <div class="links">
            <?php print $edit_node; ?>
            <?php if (!empty($remove_link)): print $remove_link; endif; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
