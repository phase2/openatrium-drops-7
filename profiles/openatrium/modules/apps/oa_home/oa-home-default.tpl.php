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
    <h2></h2>
    <?php if (empty($login)): ?>
      <div class="create-btn"><a href="<?php print url('sitemap'); ?>" class="btn btn-lg btn-success">Create Content</a></div>
    <?php endif; ?>
  </div><!--/hero-->

  <div class="modules">

    <div class="entry-placeholder">&nbsp;
    </div><!--/entry-->

  <?php if (!empty($login)): ?>
    <div class="user-login">
      <?php print render($login); ?>
    </div>
  <?php endif; ?>

    <div class="entry-placeholder">&nbsp;
    </div><!--/entry-->

  </div><!--/modules-->

</div><!--/big wrapper-->
