<?php
/**
 * @file
 * Default template for notification details.
 * $user - array of users.  'name' => username, 'mail', email address
 * $description - help text;
 * $no_users - text to show when there aren't any notifications
 */
?>
<?php if (!empty($description)): ?>
  <p><?php print $description; ?></p>
<?php endif; ?>
<?php if (!empty($users)): ?>
<ul>
  <?php foreach ($users as $uid => $user): ?>
    <li><?php print $user['name']; ?></li>
  <?php endforeach; ?>
</ul>
<?php else: ?>
  <?php print $no_users; ?>
<?php endif; ?>
<p>&nbsp;</p>
<p><a href="#" class="ctools-close-modal btn btn-default">Close</a></p>
