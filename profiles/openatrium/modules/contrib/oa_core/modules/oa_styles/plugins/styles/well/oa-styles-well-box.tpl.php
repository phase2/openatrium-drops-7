<?php
/**
 * @file
 * This template handles the layout of oa_well.
 */
?>
<div class="well style-region <?php if (isset($settings['well_modifier'])): print $settings['well_modifier']; endif; ?>">
  <?php print $content; ?>
</div>
