<?php
/**
 * @file
 * Displays read-only list of notifications.
 *
 * $group - Groups to notify.
 * $team - Teams to notify.
 * $user - Users to notify.
 * $subscribe - Render array for subscribe button, if available.
 * $show_details - Render array for show details button / modal.
 */
?>

<div class="notifications">
  <?php if (empty($group) && empty($team) && empty($user)): ?>
    <div><?php print t('There are no notifications configured for this content'); ?></div>
  <?php endif; ?>
  <?php if (!empty($group)): ?>
    <div class="notification-group">
      <h5><?php print t('Groups'); ?></h5>
      <?php foreach ($group as $id => $o): ?>
        <?php print l($o, 'node/' . $id, array('attributes' => array('class' => array('label', 'label-info')))); ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($team)): ?>
    <div class="notification-group">
      <h5><?php print t('Teams'); ?></h5>
      <?php foreach ($team as $id => $t): ?>
        <?php print l($t, 'node/' . $id, array('attributes' => array('class' => array('label', 'label-info')))); ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($user)): ?>
    <div class="notification-group">
      <h5><?php print t('Users'); ?></h5>
      <?php foreach ($user as $u):
        $attributes = array('class' => array('label'));
        if ($u['access']) {
           $attributes['class'][] = 'label-info';
        }
        else {
          $attributes['class'][] = 'label-important';
          $attributes['data-toggle'] = 'tooltip';
          $attributes['title'] = t('Access has been revoked');
        }
        ?>
        <?php print l($u['name'], 'user/' . $u['uid'], array('attributes' => $attributes)); ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($subscribe)): ?>
    <?php print render($subscribe); ?>
  <?php endif; ?>
  <?php if (!empty($show_details)): ?>
    <?php print render($show_details); ?>
  <?php endif; ?>
</div>
