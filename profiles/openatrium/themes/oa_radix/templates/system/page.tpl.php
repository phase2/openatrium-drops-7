<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>
<?php if (!empty($oa_toolbar_panel)): ?>
  <div class="responsive-panels-region responsive-panels-region-top">
    <div id="oa-navbar" class="navbar <?php print $oa_toolbar_class; ?> <?php print $oa_toolbar_sticky; ?>">
      <div class="navbar-inner">
        <?php print $oa_toolbar_panel; ?>
      </div>
    </div>
    <?php if (!empty($oa_banner)): ?>
      <?php print $oa_banner; ?>
    <?php endif; ?>
    <?php if (!empty($oa_space_menu)): ?>
      <?php print $oa_space_menu; ?>
    <?php endif; ?>
  </div>
<?php else: ?>
  <header id="header" class="header" role="header">
    <div class="container">
      <div class="row">
        <div class="span12">
          <div id="navigation" class="navbar">
            <div class="navbar-inner">
              <div class="container clearfix">
                <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
                <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
                  <span class="icon-bar"></span>
                  <span class="icon-bar"></span>
                  <span class="icon-bar"></span>
                </a>

                <?php if ($logo): ?>
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo" class="pull-left brand">
                     <img src="<?php print $logo; ?>"><div id="site-name"><?php print $site_name; ?></div>
                  </a>
                <?php endif; ?>

                <nav id="main-nav" class="pull-left" role="navigation">
                  <?php print render($page['navigation']); ?>
                </nav>

                <?php if ($user_badge): ?>
                  <?php print $user_badge; ?>
                <?php endif; ?>

                <?php if ($search_form): ?>
                  <?php // print $search_form; ?>
                <?php endif; ?>

                <?php if ($main_menu): ?>
                  <nav id="main-menu" class="main-menu" role="navigation">
                    <?php print render($main_menu); ?>
                  </nav> <!-- /#main-menu -->
                <?php endif; ?>
              </div>
            </div>
          </div> <!-- /#navigation -->
        </div>
      </div>
    </div>
    <?php if (!empty($oa_banner)): ?>
      <?php print $oa_banner; ?>
    <?php endif; ?>
    <?php if (!empty($oa_space_menu)): ?>
      <?php print $oa_space_menu; ?>
    <?php endif; ?>
  </header>
<?php endif; ?>

<div id="main-wrapper">
  <div id="main" class="main container">
    <?php if ($breadcrumb && (arg(0) == 'admin')): ?>
      <div id="breadcrumb" class="visible-desktop">
        <div class="container">
          <?php print $breadcrumb; ?>
        </div>
      </div>
    <?php endif; ?>
    <?php if ($messages): ?>
      <div id="messages">
        <?php print $messages; ?>
      </div>
    <?php endif; ?>
    <div id="content">
      <div class="row">
        <div class="span12 inner">
          <?php if (!empty($primarytabs)): ?><?php print $primarytabs; ?><?php endif; ?>
          <a id="main-content"></a>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if (!empty($tabs['#primary']) || !empty($tabs['#secondary'])): ?><div class="tabs main-tabs"><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <?php print render($page['content']); ?>
        </div>
      </div>
    </div>
  </div>
  <div id="push"></div>
</div>

<footer id="footer" class="footer" role="footer">
  <div class="container">
    <div class="row">
      <div class="span12">
        <div class="footer-inner">
          <?php if (!empty($oa_footer_panel)): ?>
            <?php print $oa_footer_panel; ?>
          <?php else: ?>
            <?php print render($page['footer']); ?>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
</footer>
