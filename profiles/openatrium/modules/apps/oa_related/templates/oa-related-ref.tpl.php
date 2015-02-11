<?php
/**
 * @file
 * Provides theming for oa_related_files widget.
 *
 * $items - Array of nodes to display.
 */
?>

<div class="oa-related-ref">
  <?php foreach ($items as $node):?>
    <div class="oa-related-refitem">
      <div class="oa-related-title">
        <div class="oa-related-type"><?php print $node['type'];?></div>
        <?php print $node['title'];?></div>
    </div>
  <?php endforeach; ?>
</div>
