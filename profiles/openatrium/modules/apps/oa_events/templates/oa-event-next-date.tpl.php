<?php
/**
 * @file
 * Default template for next event date.
 */
?>
<div class='oa-event-date-next-wrapper'>
  <div class='oa-event-date-next-wrapper'>
    <span class='oa-event-label'>
      <?php print t('When'); ?>:
    </span>
    <span class="oa-event-item oa-date"><span class="oa-event-day"><?php print $variables['date'] . ','; ?></span>
        <span class="oa-event-time"><?php print $variables['time']?></span></span>
  </div>
  <?php if (!empty($rrule)) : ?>
    <div class='oa-event-date-rrule oa-event-item'>
      <?php print $rrule; ?>
    </div>
  <?php endif; ?>
</div>
