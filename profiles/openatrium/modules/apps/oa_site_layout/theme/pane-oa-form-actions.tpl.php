<?php
/**
 * @file
 *
 * Theme implementation to display the form_actions.
 *
 */
?>
<ul class="oa-form-actions">
  <?php foreach ($buttons as $button): ?>
    <?php if (!empty($button['link'])): ?>
      <li>
        <label for="<?php print $button['link'];?>" class="btn <?php print $button['class']; ?>" title="<?php print $button['title'];?>">
          <?php if (!empty($button['icon'])): ?>
            <i class="<?php print $button['icon'];?>"></i>&nbsp;
          <?php endif; ?>
          <?php if ($show_captions || empty($button['icon'])): ?>
            <?php print $button['title'];?>
          <?php endif; ?>
        </label>
      </li>
    <?php endif; ?>
  <?php endforeach; ?>
</ul>
