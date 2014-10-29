<?php
/**
 * @file
 * Default template for next event date.
 */
?>
<div class='oa-event-date-next-wrapper'>
  <div class='oa-event-date-next-wrapper'>
    <p class='oa-event-date'>
      <span class='oa-event-label'>
        <?php print t('Date'); ?>:
      </span>
      <?php print $variables['date']?>
    </p>
  </div>
  <div class='oa-event-date-day-wrapper'>
    <span class='oa-event-label'>
      <?php print t('Time'); ?>:
    </span>
    <span class='oa-event-time'>
      <?php print $variables['time']?>
    </span>
  </div>
  <?php if (!empty($rrule)) : ?>
    <div class='oa-event-date-rrule'>
      <?php print $rrule; ?>
    </div>
  <?php endif; ?>
</div>
