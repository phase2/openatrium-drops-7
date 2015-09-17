<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output
 *     safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use.
 *     var_export to dump this object, as it can"t handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to
 *     use.
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
<div class="oa-media-list clearfix attachments">
  <div class="row">
    <div class="col-xs-12">
      <div class="col-xs-6 pull-left">
        <?php print $rendered; ?>
      </div>
      <div class="col-xs-6">
        <div class="row">
          <div class="pull-right user-badge">
            <?php print $name; ?>
            <?php print $picture; ?>
          </div>
        </div>
        <div class="row">
          <div class="pull-right filename">
            <?php print $download_link . '&nbsp;&nbsp;' . $thread_link; ?>
          </div>
        </div>
      </div>
    </div>

    <?php if (isset($subject)): ?>
    <div class="oa-list-header">
      <?php print $subject; ?>
    </div>
    <?php endif; ?>
  </div>
  <?php if ($count > 1): ?>
    <hr>
  <?php endif; ?>
</div>
