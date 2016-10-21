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
    <h1><span>Team.</span> Work.</h1>
    <h2>Welcome <?php if (!empty($username)) {print '<span>' . $username . '</span>'; } ?> to Atrium!</h2>
    <?php if (!empty($login)): ?>
      <div class="create-btn"></div>
    <?php else: ?>
      <div class="create-btn"><a href="<?php print url('sitemap'); ?>" class="btn btn-lg btn-success">Create Content</a></div>
    <?php endif; ?>
  </div><!--/hero-->

  <div class="modules">

  <div class="entry">
    <div class="module-header"><h4>just getting started?</h4></div><!--/module-header-->
    <div class="module-content">
      <a href="http://docs.openatrium.com/" class="icon icon-documentation"></a>
      <p>Read <a href="http://docs.openatrium.com/">documentation</a> to help you get going with Atrium, or Visit the open source <a href="https://drupal.org/project/openatrium">Atrium project</a> at <a href="https://drupal.org">DRUPAL.ORG.</a></p>
    </div><!--/module content-->
  </div><!--/entry-->

  <?php if (!empty($login)): ?>
    <div class="user-login">
      <?php print render($login); ?>
    </div>
  <?php else: ?>
    <div class="entry">
      <div class="module-header"><h4>Tell us your story!</h4></div><!--/module-header-->
      <div class="module-content">
        <a href="http://landing.phase2technology.com/atrium-product-feedback" class="icon icon-got-issues"></a>
        <p>Help us improve Atrium by <br \> <a href="http://landing.phase2technology.com/atrium-product-feedback">telling us about your site</a>.</p>
      </div><!--/module content-->
    </div><!--/entry-->
  <?php endif; ?>

    <div class="entry entry-last">
      <div class="module-header"><h4>need the pros?</h4></div><!--/module-header-->
      <div class="module-content">
        <a href="http://www.phase2technology.com/contact-us/start-a-project-with-phase2/" class="icon icon-pros"></a>
        <p>Find <a href="http://www.phase2technology.com/contact-us/start-a-project-with-phase2/">Best-in-Class Professional Services</a> to build out your Atrium solution.</p>
      </div><!--/module content-->
    </div><!--/entry-->

  </div><!--/modules-->

</div><!--/big wrapper-->
