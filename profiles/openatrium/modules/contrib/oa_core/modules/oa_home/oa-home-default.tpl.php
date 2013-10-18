<?php
/**
 * @file
 * Template for Default Home page panel.
 */
?>
<div class="big-wrapper">
  <div class="hero">
    <div class="hero-left-graphic"></div><!--/hero-right-graphic-->
    <div class="hero-right-graphic"></div><!--/hero-right-graphic-->
    <h1>Powerful, Flexible, Open</h1>
    <h2>Welcome <?php if (!empty($username)) {print '<span>' . $username . '</span>'; } ?> to Open Atrium 2!</h2>
    <h3>What's next?  Dive in or check out some resources.</h3>
  </div><!--/hero-->

  <div class="modules">

  <?php if (!empty($login)): ?>
    <div class="entry">
      <div class="module-header"><h4>just getting started?</h4></div><!--/module-header-->
      <div class="module-content">
        <a href="http://docs.openatrium.com/" class="icon icon-documentation"></a>
        <p>Read <a href="http://docs.openatrium.com/">documentation</a> to help you get going with Open Atrium, or Visit the open source <a href="https://drupal.org/project/openatrium">Open Atrium project</a> at <a href="https://drupal.org">drupal.org.</a></p>
      </div><!--/module content-->
    </div><!--/entry-->
  <?php else: ?>
    <div class="entry">
      <div class="module-header"><h4>got issues?</h4></div><!--/module-header-->
      <div class="module-content">
        <a href="https://drupal.org/project/openatrium" class="icon icon-got-issues"></a>
        <p>Visit the open source <a href="https://drupal.org/project/openatrium">Open Atrium project</a> at <a href="https://drupal.org">drupal.org.</a></p>
      </div><!--/module content-->
    </div><!--/entry-->
  <?php endif; ?>

  <?php if (!empty($login)): ?>
    <div class="user-login">
      <?php print render($login); ?>
    </div>
  <?php else: ?>
    <div class="entry">
      <div class="module-header"><h4>just getting started?</h4></div><!--/module-header-->
      <div class="module-content">
        <a href="http://docs.openatrium.com/" class="icon icon-documentation"></a>
        <p>Read <a href="http://docs.openatrium.com/">documentation</a> to help you get going with Open Atrium.</p>
      </div><!--/module content-->
    </div><!--/entry-->
  <?php endif; ?>

    <div class="entry entry-last">
      <div class="module-header"><h4>need the pros?</h4></div><!--/module-header-->
      <div class="module-content">
        <a href="http://www.phase2technology.com/contact-us/start-a-project-with-phase2/" class="icon icon-pros"></a>
        <p>Find <a href="http://www.phase2technology.com/contact-us/start-a-project-with-phase2/">Best-in-Class Professional Services</a> to build out your Open Atrium solution.</p>
      </div><!--/module content-->
    </div><!--/entry-->

  </div><!--/modules-->

  <div class="subfooter">
    <div class="subfooter-graphic">
    </div><!--/subfooter graphic-->
  </div><!--/subfooter-->

</div><!--/big wrapper-->
