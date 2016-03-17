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
  <?php foreach ($notifications as $type => $list): ?>
    <?php if (!empty($list)): ?>
      <ul class="notification-group">
        <?php foreach ($list as $item): ?>
          <?php
            $attributes = array();
            if (isset($item['access']) && !$item['access']) {
              $attributes = array(
                'class' => array('label', 'label-important'),
                'data-toggle' => 'tooltip',
                'title' => t('User does not have access to this page'),
              );
            }
          elseif (!empty($item['blocked'])) {
            $attributes = array(
              'class' => array('oa-user-blocked'),
              'data-toggle' => 'tooltip',
              'title' => t('User has notifications disabled'),
            );
          }
          ?>
          <li title="<?php print !empty($item['title']) ? $item['title'] : $item['name']; ?>"
              data-remove="<?php print !empty($item['data']) ? $item['data'] : ''; ?>"
              class="oa-notify-item <?php print !empty($item['class']) ? $item['class'] : ''; ?>">
            <?php if (!empty($item['picture'])): ?>
              <span class="user-picture"><?php print $item['picture']; ?></span>&nbsp;
            <?php endif; ?>
            <?php if (!empty($item['icon'])): ?>
              <i class="<?php print $item['icon']; ?>"></i>&nbsp;
            <?php endif; ?>
            <?php print l($item['name'], $item['url'], array('attributes' => $attributes)); ?>
            <?php if (!empty($item['remove_link'])): ?>
              <span class="remove-link"><?php print $item['remove_link']; ?></span>
            <?php endif; ?>
          </li>
        <?php endforeach; ?>
      </ul>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
