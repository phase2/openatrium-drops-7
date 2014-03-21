<?php
/**
 * @file
 * Provides view for nav bar user badge.
 *
 * $picture - Markup of the user's profile picture.
 * $realname - Real name field. Defaults to unique name if unavailable.
 * $name - Unique user name.
 * $links - Array of useful links.
 *    'dashboard' - Link to the user's page.
 *    'edit_profile' - Link to edit user's profile.
 *    'logout' - Logout link.
 */
?>
<?php if (user_is_logged_in()): ?>
<div id="oa-user-badge">
  <div class="dropdown oa-dropdown btn-group pull-right">
    <div class="dropdown-toggle btn clearfix pull-right user-badge <?php print $oa_toolbar_btn_class; ?>" id="user-badge-dropdown" data-toggle="dropdown">
        <?php print $realname; ?>
        <?php print $picture; ?>
    </div>
    <div class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
      <?php
        // Sort the links by 'weight' before rendering them.
        uasort($links['#links'], 'drupal_sort_weight');
        print render($links);
      ?>
    </div>
  </div>
</div>
<?php else: ?>
  <div>
    <a href="<?php print $login; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print t('Login'); ?></a>
  </div>
<?php endif; ?>
