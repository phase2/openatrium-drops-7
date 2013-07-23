<?php
/**
 * @file
 * Default template for notification details.
 */
?>
<ul>
<?php foreach ($users as $uid => $user): ?>
  <li><?php print $user['name']; ?></li>
<?php endforeach; ?>
</ul>


