<?php

/**
 * @file
 * Theme implementation to display a slimmed down  page.
 */
?>

<?php if (isset($messages)) { print $messages; } ?>
<?php
  hide($page['content']['system_main']['tabset']);
  hide($page['content']['system_main']['title']);
  print render($page['content']);
?>
