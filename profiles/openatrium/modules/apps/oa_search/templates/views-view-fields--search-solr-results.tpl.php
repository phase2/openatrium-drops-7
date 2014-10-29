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
 * - $field_feature_image: space image.
 * - $title: Title of the space.
 * - $created: How long user has been a member.
 * - $sections: Array of sections belonging to the space.
 *    - 'title': Title of the section.
 *    - 'href': Path to the section.
 *
 * @ingroup views_templates
 */
?>
<div class='oa-list well oa_search_row clearfix oa-list-header'>
  <h3><?php print $title; ?></h3>
  <?php if (isset($field_featured_image)): ?>
    <div><?php print $field_featured_image; ?></div>
  <?php endif; ?>
  <div><?php print $body; ?></div>
</div>
