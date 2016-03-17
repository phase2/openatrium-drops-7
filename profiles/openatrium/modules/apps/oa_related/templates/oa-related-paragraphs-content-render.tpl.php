<?php

/**
 * @file
 * Theme implementation for the paragraph_content bundle.
 *
 * Available variables:
 * - $oa_related_content: An array of content items keyed by the type.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php if (is_array($oa_related_content)): ?>
      <?php $count = count($oa_related_content) - 1; ?>
      <?php if (!empty($title)): ?>
        <div class="field-label-heading">
          <div class="field-label">
            <?php print $title; ?>
          </div>
        </div>
      <?php endif; ?>
      <?php foreach ($oa_related_content as $key => $array): ?>
        <?php foreach ($array as $type => $content): ?>
          <?php print $content; ?>
          <?php if ($type == 'node' && $key < $count): ?><hr><?php endif; ?>
        <?php endforeach; ?>
      <?php endforeach; ?>
    <?php else: ?>
      <?php print $oa_related_content; ?>
    <?php endif; ?>
  </div>
</div>
