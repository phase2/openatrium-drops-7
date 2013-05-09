<?php
/**
 * @file
 * Template that provides the view for the space members widget.
 *
 * $owners - Array of owners.
 *   'title'    - Link to the owner user.
 *   'picture'  - Rendered image of the user.
 * $teams - Array of teams.
 *   'title'    - Link to the team node.
 * $users - Array of users.
 *   'title'    - Link to the owner user.
 *   'picture'  - Rendered image of the user.
 */
?>

<?php if (!empty($owners)): ?>
<div class='clearfix well well-small owners'>
  <h5><?php print $owner_title?></h5>
  <?php foreach ($owners as $owner): ?>
    <?php if (empty($links['remove-admin']) || empty($owner['uid'])): ?>
      <div class='pull-left user-badge'>
        <?php print $owner['picture']; ?>
        <?php print $owner['title']; ?>
      </div>
    <?php else: ?>
      <div class="dropdown oa-dropdown btn-group">
        <div class="dropdown-toggle btn pull-left user-badge" data-toggle="dropdown">
          <?php print $owner['picture']; ?>
          <?php print $owner['title']; ?>
          <i class='icon-chevron-down'></i>
        </div>
        <div class="dropdown-menu" role="menu" aria-labelledby="dropdownMenu">
          <ul>
            <li><?php print l(t('Dashboard'), $links['dashboard'] . $owner['uid']); ?></li>
            <li><?php print l(t('Remove as Admin'), $links['remove-admin'] . $owner['uid']); ?></li>
          </ul>
        </div>
      </div>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
<?php endif; ?>

<?php if (!empty($teams)): ?>
<div class='clearfix well well-small teams'>
  <h5>Teams</h5>
  <?php foreach ($teams as $team): ?>
    <div class='pull-left team label'>
      <?php print $team['title']; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif; ?>

<?php if (!empty($members)): ?>
<div class='clearfix members'>
  <?php foreach ($members as $member): ?>
    <?php if (empty($links['add-admin']) || empty($member['uid'])): ?>
      <div class='pull-left user-badge'>
        <?php print $member['picture']; ?>
        <?php print $member['title']; ?>
      </div>
    <?php else: ?>
      <div class="dropdown oa-dropdown btn-group">
        <div class="dropdown-toggle btn pull-left user-badge" data-toggle="dropdown">
          <?php print $member['picture']; ?>
          <?php print $member['title']; ?>
          <i class='icon-chevron-down'></i>
        </div>
        <div class="dropdown-menu" role="menu" aria-labelledby="dropdownMenu">
          <ul>
            <li><?php print l(t('Dashboard'), $links['dashboard'] . $member['uid']); ?></li>
            <li><?php print l(t('Remove from ') . $space_title, $links['remove'] . $member['uid']); ?></li>
            <li><?php print l(t('Add as Admin'), $links['add-admin'] . $member['uid']); ?></li>
          </ul>
        </div>
      </div>
    <?php endif; ?>
  <?php endforeach; ?>
  <div class="clear-both more">
    <?php print $see_all_link; ?>
  </div>
</div>
<?php endif; ?>
