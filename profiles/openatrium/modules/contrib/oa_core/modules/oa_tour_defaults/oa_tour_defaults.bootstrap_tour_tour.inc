<?php
/**
 * @file
 * oa_tour_defaults.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function oa_tour_defaults_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'banners';
  $bootstrap_tour->title = 'Banners';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Adding banners to the site';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#edit-field-oa-banner-position-und',
      'path' => 'node/add/oa-space',
      'placement' => 'right',
      'title' => 'Space Banner',
      'content' => '<p><span>Select a banner image to be uploaded. &nbsp;</span></p><p><span>Banner images should have an aspect ratio appropriate for streching across the full width of the site.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#edit-field-oa-banner-position-und',
      'path' => '',
      'placement' => 'right',
      'title' => 'Banner Position',
      'content' => '<p><span>You can choose to show the banner above or below the main Open Atrium toolbar.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-field-oa-banner-text-und-0-value',
      'path' => '',
      'placement' => 'right',
      'title' => 'Banner Text',
      'content' => '<p><span>You can optionally add text to be overlayed on top of the image.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#toolbar-menu-button',
      'path' => '<front>',
      'placement' => 'right',
      'title' => 'Site Banners',
      'content' => '<p><span>To change banners for the entire site, select the Open Atrium Plugin Settings from the main Drupal Admin menu.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-oa-site-banner-file-remove-button',
      'path' => 'admin/openatrium/setting',
      'placement' => 'right',
      'title' => 'Sitewide Banner',
      'content' => '<p><span>Upload an image to be shown as the banner for the entire web site.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#edit-oa-site-banner-position',
      'path' => '',
      'placement' => 'right',
      'title' => 'Banner Position',
      'content' => '<p>Like Space banners, you can select to display the Site banner above or below the main toolbar.</p><p>If you display the Site banner in the same location as the Space banner, the Space banner will override the Site banner. &nbsp;Otherwise both will appear.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '.form-item-oa-banner-stretch label',
      'path' => '',
      'placement' => 'right',
      'title' => 'Stretching Banners',
      'content' => '<p><span>Unlike Space banners, the Site banner can either Stretch to fill the full width of the site, or it can be left un-stretched.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '.form-item-oa-banner-sitename label',
      'path' => '',
      'placement' => 'right',
      'title' => 'Banner Text',
      'content' => '<p><span>Optionally display the site Name and Slogan over the banner image.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['banners'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'colorizing_a_space';
  $bootstrap_tour->title = 'Colorizing a Space';
  $bootstrap_tour->roles = 2;
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'How to change theme colors';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#contextual-dropdown',
      'path' => '<front>',
      'placement' => 'left',
      'title' => 'Customizing Colors',
      'content' => '<p><span>To change the Colors of a Space, select the Config option from the contextual drop-down menu.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '',
      'path' => 'node/4/group',
      'placement' => 'right',
      'title' => 'Change Appearance',
      'content' => '<p><span>Click the Appearance link to change the Colors for the Space.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-scheme',
      'path' => 'group/node/4/admin/appearance',
      'placement' => 'right',
      'title' => 'Colorizer Settings',
      'content' => '<p>Select a pre-defined color scheme for your Space.</p><p>Or, click on a spacific color to change it.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.farbtastic',
      'path' => 'group/node/4/admin/appearance',
      'placement' => 'right',
      'title' => 'Changing Colors',
      'content' => '<p><span>As you change the color using the color picker, the colors on the page will change automatically.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-colorizer-clearcache',
      'path' => 'group/node/4/admin/appearance',
      'placement' => 'right',
      'title' => 'Save your Changes',
      'content' => '<p>When you are finished customizing the colors, click Save.</p><p>The Clear Colorizer Cache is used to refresh the colors if the underlying theme files are updated.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '.form-item-colorizer-reset label',
      'path' => 'group/node/4/admin/appearance',
      'placement' => 'right',
      'title' => 'Resetting Colors',
      'content' => '<p><span>To reset colors back to the default theme, click this box and then Save.</span></p><p></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['colorizing_a_space'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'configuring_layout';
  $bootstrap_tour->title = 'Configuring Layout';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#ajax-link',
      'path' => 'firstnode/oa_space/spaces',
      'placement' => 'bottom',
      'title' => 'Configure Layout',
      'content' => '<p>When you create a space, you have the option of configuring the layout according to a number of built in templates.&nbsp;</p><p>Click "Change this Layout" to choose from 31 built in content layouts.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#panels-ipe-customize-page',
      'path' => '',
      'placement' => 'left',
      'title' => 'Customizing Your Page',
      'content' => '<p>In addition, &nbsp;you have full control over which widgets you wish to have in your space.</p><p>Click the "Customize this Page" to access the ability to drag and drop different widgets to different locations on the space.</p><p>In addition, you can control the theming of the individual widgets and edit the content within them.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['configuring_layout'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'content_visibility';
  $bootstrap_tour->title = 'Content Visibility';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This will discuss content visibility with the user';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.pane-node-group-access',
      'path' => 'node/add/oa-space',
      'placement' => 'left',
      'title' => 'Content Visibility',
      'content' => '<p>You have the ability to determine whether or not your content is public or private.</p><p>This can be done all the way from your highest level space to your most heavily nested section.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#edit-group-access-und :nth-child(1) .option',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Public Visibility',
      'content' => '<p>If a space is considered "public," this means that all authenticated users of your site as well as anonymous internet users will be able to&nbsp;<em>view</em> your content.</p><p>Only authorized users will have write access.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-group-access-und :nth-child(2) .option',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Private Visibility',
      'content' => '<p>If your space is "private," this means that only authenticated users of your site will be able to view your content.</p><p></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.pane-node-group-access',
      'path' => '',
      'placement' => 'left',
      'title' => 'Site Wide Visibility',
      'content' => '<p>The visibility of your site can range from completely public, completely private, or mixed mode.</p><p>Mixed mode merely means that your top level space is public, but additional subspaces or sections nested beneath are a mixture of public/private.</p><p>In addition, your top level space can be private with further divisions of permissions throughout.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Section Visibility',
      'content' => '<p>For more information on specific permissions, visit our <a href="oa-section?tour=section_visibility" target="_blank">Section Visibility Tour</a>.</p>',
      'format' => 'panopoly_html_text',
    ),
  );
  $export['content_visibility'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'groups';
  $bootstrap_tour->title = 'Groups';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This walks the user through the basic concept and creation of a group';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#toolbar-menu-button',
      'path' => '<front>',
      'placement' => 'right',
      'title' => 'Creating a Group',
      'content' => '<p>The site admin has the ability to create groups for the whole OA2 site.</p><p>This is because groups are meant to be collection of users that span a related purpose across multiple spaces.</p><p>To create your first group, you\'d click the Drupal "Admin" button and click "Add Content."</p><p>For now, click "next."</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => 'dt:nth-child(9) a',
      'path' => 'node/add',
      'placement' => 'right',
      'title' => 'Creating a Group',
      'content' => '<p>Select the "groups" option.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-title',
      'path' => 'node/add/oa-group',
      'placement' => 'bottom',
      'title' => 'Title',
      'content' => '<p>Provide your group with an appropriate name.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#edit-body',
      'path' => '',
      'placement' => 'top',
      'title' => 'Description',
      'content' => '<p>You also have the option to provide your group with a description.</p><p>The WYSIWYG includes the ability for embedding images and videos if you wish.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-path-alias',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Permalink',
      'content' => '<p>You can customize your permalink or let the site automatically generate it from the title.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '.pane-node-field-featured-image',
      'path' => '',
      'placement' => 'left',
      'title' => 'Featured Image',
      'content' => '<p>Select a featured image if you so choose.</p><p>Acceptable file formats include .jpg, .png, and .gif.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '#edit-group-access label:nth-child(1)',
      'path' => '',
      'placement' => 'top',
      'title' => 'Group Visibility',
      'content' => '<p>Decide whether or not you would like your group to be publicly visible or private.</p><p>Groups that are visible to the public can allow non-members to request membership.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'left',
      'title' => 'Save!',
      'content' => '<p>Hit "Publish" to save your first group!</p><p>You will be redirected to the main landing page of your group where you can add, remove, and manage the members of your group. This page can be accessed at any time through the following path: Admin &gt; Open Atrium &gt; Groups &gt; Select your group.</p><p>To continue, check out our <a href="/?tour=teams" target="_blank">Teams Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['groups'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'menus';
  $bootstrap_tour->title = 'Menus';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This tour walks the user through the basic structure of menus on their OA2 site.';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#toolbar-menu-button',
      'path' => '<front>',
      'placement' => 'right',
      'title' => 'Main Menu',
      'content' => '<p><span>To display the Main Menu at the top of the site, select Open Atrium Plugin Settings from the Drupal Admin menu.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '.form-item-oa-mainmenu label',
      'path' => 'admin/openatrium/setting',
      'placement' => 'right',
      'title' => 'Show Main Menu',
      'content' => '<p>Enable this option and Save to display the Main Menu at the top of the page.</p><p>Note that it only displays if you have added items to the Menu.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.pane-node-form-menu',
      'path' => 'node/add/oa-space',
      'placement' => 'left',
      'title' => 'Adding Items to Menu',
      'content' => '<p><span>To add something to the menu, edit the item and enable the menu link option, then select Main Menu in the Parent dropdown.</span></p><p><span>You can add items to menus at the space as well as the section level. Merely give menu link the title you\'d like and nest it appropriately.&nbsp;</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#contextual-dropdown',
      'path' => '<front>',
      'placement' => 'left',
      'title' => 'Space Menus',
      'content' => '<p><span>To display the space-specific menu, select Config from the contextual drop-down.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => 'dt:nth-child(7) a',
      'path' => 'node/4/group',
      'placement' => 'right',
      'title' => 'Space Menu',
      'content' => '<p><span>Select the Menu option.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '.form-item-oa-space-menu label',
      'path' => 'group/node/4/admin/menu',
      'placement' => 'right',
      'title' => 'Space Menu',
      'content' => '<p><span>Check this box and Save to display the Space-specific menu below the toolbar.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['menus'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'notifications';
  $bootstrap_tour->title = 'Notifications';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Talking about notifications';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.pane-node-form-oa-notifications .pane-title',
      'path' => 'node/add/oa-space',
      'placement' => 'left',
      'title' => 'Notifications',
      'content' => '<p>You have the ability to add notifications at the space, subspace, section, and content level.</p><p>They work the same way regardless of what level you happen to be at.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '.form-item-oa-notifications-notifications-group label',
      'path' => '',
      'placement' => 'left',
      'title' => 'Groups',
      'content' => '<p>You can identify specific groups you\'d like to receive push notifications from your space, sections, or content.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.form-item-oa-notifications-notifications-team label',
      'path' => '',
      'placement' => 'left',
      'title' => 'Teams',
      'content' => '<p>In addition, you can select specific teams for push notifications as well.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.form-item-oa-notifications-notifications-user label',
      'path' => '',
      'placement' => 'left',
      'title' => 'Individual Users',
      'content' => '<p>You could also specify individual users that should receive push notifications or add them in addition to the groups and teams that have been selected.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#notifications-fields .option',
      'path' => '',
      'placement' => 'left',
      'title' => 'Do Not Send',
      'content' => '<p>If you don\'t wish to send a notification around the changes that you\'ve made, make sure to check the box.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '.pane-node-form-oa-notifications .pane-title',
      'path' => '',
      'placement' => 'left',
      'title' => 'Pull Notifications',
      'content' => '<p>Once you have created content, users will also have the option to subscripe to that content to receive pull notifications.</p><p>When receiving notifications via email, users can respond in the email to post back to discussions etc.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['notifications'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'sandbox_mode';
  $bootstrap_tour->title = 'Sandbox Mode';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Describes how to use Sandbox Mode';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#toolbar-menu-button',
      'path' => '<front>',
      'placement' => 'right',
      'title' => 'Sandbox Mode',
      'content' => '<p>Sandbox Mode allows you to enter test content and easily remove it later.</p><p>To start Sandbox Mode, select it from the Drupal Admin menu, within the Open Atrium section.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#oa-sandbox-settings-form .form-item-toggle label',
      'path' => 'admin/openatrium/sandbox',
      'placement' => 'right',
      'title' => 'Enable Sandbox',
      'content' => '<p><span>To enable Sandbox mode, check this box and click Save.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#oa-sandbox-indicator',
      'path' => '',
      'placement' => 'right',
      'title' => 'Sandbox Indicator',
      'content' => '<p>When you are in Sandbox mode, this indicator is displayed on all pages.</p><p>Click this indicator to return to this page to toggle sandbox mode.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.main-tabs ul li:nth-child(2) a',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Delete Sandbox',
      'content' => '<p><span>To delete content created while in Sandbox mode, click the Delete tab.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-submit',
      'path' => 'admin/openatrium/sandbox/delete',
      'placement' => 'bottom',
      'title' => 'Delete Content',
      'content' => '<p>Click this Delete button to confirm you wish to remove your test content.</p><p>All content created while you are in Sandbox mode will be removed. &nbsp;<strong>This cannot be undone!</strong></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '.form-item-sandbox',
      'path' => 'node/add/oa-wiki-page',
      'placement' => 'left',
      'title' => 'Creating Sandbox Content',
      'content' => '<p>When creating new content in Sandbox Mode, the "Test content" option will automatically be selected.</p><p>If you want to enter content that is preserved when you exit Sandbox you can uncheck this option.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['sandbox_mode'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'section_visibility';
  $bootstrap_tour->title = 'Section Visibility';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This walks the user through the basics of more specific permissions per section.';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.pane-node-field-oa-group-ref .pane-title',
      'path' => 'node/add/oa-section',
      'placement' => 'left',
      'title' => 'Section Visibility',
      'content' => '<p>As the space admin, you have the ability to determine exactly who has access to your section and the content within.</p><p>(Curious about sections, visit the <a href="oa-section?tour=sections_overview" target="_blank">Sections Overview Tour</a> first.)</p>',
      'format' => 'panopoly_html_text',
    ),
    1 => array(
      'selector' => '.form-item-field-oa-group-ref-und',
      'path' => '',
      'placement' => 'left',
      'title' => 'Groups',
      'content' => '<p>A group is a collection of users that span a related purpose across multiple spaces. (For example, a group for a company\'s leadership.)</p><p>You can select any relevant groups that would need private access to this section or leave it blank to allow all authenticated space members access to the content.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.form-item-field-oa-team-ref-und',
      'path' => '',
      'placement' => 'left',
      'title' => 'Teams',
      'content' => '<p>Teams are an ad-hoc collection of users specific to one space. (For example, a product launch team.)</p><p>You can select any relevant teams that would need private access to this section or leave it blank to allow all authenticated space members access to the content.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.pane-node-field-oa-user-ref',
      'path' => '',
      'placement' => 'left',
      'title' => 'Individual Users',
      'content' => '<p>Lastly, you can identify individual users that would require access to this space.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '.pane-node-field-oa-group-ref .pane-title',
      'path' => '',
      'placement' => 'left',
      'title' => 'Section Visibility',
      'content' => '<p>Sections can become private through any combination of groups, teams, and users. This allows for incredibly granular permissions across your site, spaces, and sections.</p><p>For more information on how content hierarchy and permissions work together, check out this handy <a href="http://docs.openatrium.com/content/oa2-terminology-privacy-diagram" target="_blank">OA2 Terminology &amp; Privacy Diagram</a> on the <a href="http://docs.openatrium.com/" target="_blank">OA2 Documentation Site</a>.</p><p>You can also continue by taking our <a href="/?tour=groups" target="_blank">Groups Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['section_visibility'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'sections_overview';
  $bootstrap_tour->title = 'Sections Overview';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This will walk the user through how to create their first section';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => 'node/add/oa-section',
      'placement' => 'top',
      'title' => 'Creating a Section',
      'content' => '<p>Any space or subspace can house sections.</p><p>Sections are where the actual content of your site lives.&nbsp;</p><p>Normally you\'ll hit this dropdown next to the space and select "create new section."</p><p>For now, hit "next" to create your first section.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '',
      'path' => '',
      'placement' => 'right',
      'title' => 'Editing Your Section',
      'content' => '<p>Filing out the basic information for a section is very similar to that of a space.</p><p>Enter in a title, body, and, if you\'d like, customize the permalink.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.pane-node-field-oa-group-ref .pane-title',
      'path' => '',
      'placement' => 'left',
      'title' => 'Section Visibility',
      'content' => '<p>You can set specific permissions for your section via the section visibility widget.&nbsp;</p><p>For a more indepth look at the section visibility widget, visit the <a href="oa-section?tour=section_visibility" target="_blank">Section Visibility Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.pane-node-form-oa-notifications .pane-title',
      'path' => '',
      'placement' => 'left',
      'title' => 'Section Notifications',
      'content' => '<p>Similar to spaces, sections can have their own set of notifications.</p><p>Visit the <a href="oa-space?tour=notifications" target="_blank">Notifications Tour</a> for more information.</p>',
      'format' => 'panopoly_html_text',
    ),
    4 => array(
      'selector' => '.pane-node-form-menu .pane-title',
      'path' => '',
      'placement' => 'left',
      'title' => 'Section Menu',
      'content' => '<p>Each of your sections can also have a menu that\'s nested beneath the larger space menu.</p><p>For more information visit the <a href="/?tour=menus" target="_blank">Menus Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '.pane-node-form-publishing .pane-title',
      'path' => '',
      'placement' => 'left',
      'title' => 'Publishing Workflow',
      'content' => '<p>Same as any space, you can determine whether or not you\'d like to create a revision history of your space.</p><p>In addition, you can select your section to be included in the test content repository within Sandbox Mode.</p><p>For more information visit the <a href="/?tour=sandbox_mode" target="_blank">Sandbox Mode Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '#edit-field-oa-section-weight-und-0-value',
      'path' => '',
      'placement' => 'right',
      'title' => 'Weight',
      'content' => '<p>When you have multiple sections within a space, you can determine the order in which they are listed on your main space page via the weight.</p><p>The lower the number, the higher in the list the section will be listed. (i.e. a section weighted -10 will be listed before a section weighted 0)</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '#edit-field-oa-section-und',
      'path' => '',
      'placement' => 'right',
      'title' => 'Section Type',
      'content' => '<p>Sections can take on many different forms.</p><p>OA2 ships standard with news, discussions, calendars, and tasks sections.&nbsp;</p><p>(The news sections work particularly well for wikis, document management, and content updates that need to be a bit more visible than discussions.)</p><p></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    8 => array(
      'selector' => '.selected a',
      'path' => '',
      'placement' => 'right',
      'title' => 'Comments',
      'content' => '<p>You can also determine whether or not you\'d like to allow comments across the section here.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    9 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'left',
      'title' => 'Save!',
      'content' => '<p>Be sure to alter the authoring information as appropriate and hit "publish" to save your first section.&nbsp;</p><p>Now that you\'ve got the basics of content creation, let\'s create your first user via the <a href="/?tour=user_creation" target="_blank">User Creation Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['sections_overview'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'setting_your_home';
  $bootstrap_tour->title = 'Setting Your Home';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This allows users to understand how to link a specific space to their home icon';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.btn-home',
      'path' => '<front>',
      'placement' => 'bottom',
      'title' => 'Setting Your Home',
      'content' => '<p>Once you\'ve created a number of spaces and content, you\'ll likely want to change the page the home icon goes to.</p><p>To do so, use the following path: Drupal Admin &gt; Configuration &gt; System &gt; Site Information.</p><p>For now, just hit "next."</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#edit-site-frontpage',
      'path' => 'admin/config/system/site-information',
      'placement' => 'right',
      'title' => 'Select Your Default Home',
      'content' => '<p>Here, you can enter in the relative path for the page you\'d like to be your default home.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['setting_your_home'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'site_tours';
  $bootstrap_tour->title = 'Site Tours';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'How to create a site tour';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#tours-dropdown',
      'path' => '<front>',
      'placement' => 'bottom',
      'title' => 'Site Tours',
      'content' => '<p><span>Click this help button from any page to see a list of Help Tutorials. &nbsp;</span></p><p><span>Choose a tutorial from the list to get popup help about that topic.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#toolbar-menu-button',
      'path' => '',
      'placement' => 'right',
      'title' => 'Editing Tours',
      'content' => '<p><span>To create or edit tours, select the "Site Tours" option from the main Drupal Admin menu.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.action-links a',
      'path' => 'admin/structure/tours',
      'placement' => 'bottom',
      'title' => 'Create New Tour',
      'content' => '<p><span>To create a new tour, click the Add Tour link.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#edit-title',
      'path' => 'admin/structure/tours/add',
      'placement' => 'right',
      'title' => 'Creating a Tour',
      'content' => '<p><span>A tour consists of a title, description, and then multiple steps of popup help.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-0-path',
      'path' => '',
      'placement' => 'right',
      'title' => 'Tour Path',
      'content' => '<p>Each Step in a Tour starts with a Path.</p><p>A Path is the URL of the page you want the popup to appear. &nbsp;Use &lt;front&gt; for the home page. &nbsp;Do not put a / at the beginning.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#edit-0-selector',
      'path' => '',
      'placement' => 'right',
      'title' => 'Tour Selector',
      'content' => '<p>Each step in the Tour needs a CSS Selector. &nbsp;This specifies the page element that the popup should appear over.</p><p>Getting the correct CSS Selector can be a bit tricky and might require some CSS knowledge. &nbsp;Usually you can right-click the element and select "Inspect Element" to open the browser debugger. &nbsp;Enter an #id or .class for the item. &nbsp;You can use any full jQuery selector here.</p><p>Browser plugins such as&nbsp;<a href="http://selectorgadget.com/">SelectorGadget&nbsp;</a>can help with this.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '#edit-0-placement',
      'path' => '',
      'placement' => 'right',
      'title' => 'Tour Position',
      'content' => '<p><span>Select where you want the popup to appear relative to the CSS element.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '#edit-0-title',
      'path' => '',
      'placement' => 'right',
      'title' => 'Tour Step Title',
      'content' => '<p><span>Each step in the tour has a Title that appears in the caption for the popup.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    8 => array(
      'selector' => '.form-item-0-content-value label',
      'path' => '',
      'placement' => 'top',
      'title' => 'Tour Text',
      'content' => '<p><span>Finally, each step in the Tour has a full WYSIWYG to edit the body of the popup.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    9 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'right',
      'title' => 'Add Steps',
      'content' => '<p>You can add additional steps to the Tour by clicking the "Add another step" button.</p><p>Or just click "Save" to save the Tour.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['site_tours'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'spaces';
  $bootstrap_tour->title = 'Spaces Overview';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This is the basic overview of the most commonly used fields when creating a space.';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#page-title',
      'path' => 'node/add/oa-space',
      'placement' => 'bottom',
      'title' => 'Spaces Overview',
      'content' => '<p>Every OA2 site is a unique mixture of content and users.&nbsp;</p><p>We\'ll begin by first creating the structure for your content. &nbsp;</p><p>At the highest level, you have spaces, which are large collections of content.</p><p><em>(You may have been redirected here if you have attempted to access other tours that require a space to exist before you can run them. </em></p><p><em><strong>Please be sure to create and save your first space</strong>.)</em></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#edit-title',
      'path' => '',
      'placement' => 'right',
      'title' => 'Title',
      'content' => '<p>At a minimum, each space requires a title.&nbsp;</p><p>Go ahead and add in the title for your first space and click "next."&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.text-format-wrapper',
      'path' => '',
      'placement' => 'top',
      'title' => 'Description',
      'content' => '<p>You also have the ability to write out a description.</p><p>Note that the description field is a full fledged WYSIWYG with multiple formatting options and image/video embed.</p><p>However, you are free to switch it to HTML, Full HTML, or Plain Text. (Switched below the edit form.)</p><p>Go ahead and add in a description if you\'d like and hit "next."</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.pane-node-form-path',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Permalink',
      'content' => '<p><span>You have the option to either customize the URL of your space or allow it to be automatically generated from the title.</span></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '.pane-node-group-access',
      'path' => '',
      'placement' => 'left',
      'title' => 'Content Visibility',
      'content' => '<p>This field allows you to determine whether your space is "public" or "private."</p><p>For additional information on the differences between these two options, check out the <a href="oa-space?tour=content_visibility" target="_blank">Content Visibility Tour</a>.</p>',
      'format' => 'panopoly_html_text',
    ),
    5 => array(
      'selector' => '.pane-node-field-featured-image',
      'path' => '',
      'placement' => 'left',
      'title' => 'Featured Image',
      'content' => '<p>Next, you can select a featured image for your space.</p><p>Acceptable file formats include .jpg, .png, and .gif.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '.pane-node-form-oa-notifications',
      'path' => '',
      'placement' => 'left',
      'title' => 'Notifications',
      'content' => '<p>Notifications allow you to keep your users, groups, and teams up to date.</p><p>For a more indepth look, visit the <a href="oa-space?tour=notifications" target="_blank">Notifications Tour</a>.&nbsp;</p>',
      'format' => 'panopoly_html_text',
    ),
    7 => array(
      'selector' => '.pane-node-form-menu',
      'path' => '',
      'placement' => 'left',
      'title' => 'Menus',
      'content' => '<p>If you have a space that requires a more robust menu system, you can define the menu link for your space here.</p><p>For more information on menus, visit the <a href="/?tour=menus" target="_blank">Menus Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    8 => array(
      'selector' => '.pane-node-form-publishing',
      'path' => '',
      'placement' => 'left',
      'title' => 'Publishing Workflow',
      'content' => '<p>There is also basic workflow steps built into OA2, which allows you to keep a revision history of the space.</p><p>In addition, if you\'re working in sandbox mode as a developer, this is where you can choose to turn this space into test content or not.</p><p>For more information on sandbox mode, visit our <a href="/?tour=sandbox_mode" target="_blank">Sandbox Mode Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    9 => array(
      'selector' => '.fieldset-title',
      'path' => '',
      'placement' => 'right',
      'title' => 'Banners',
      'content' => '<p>Have a banner image you\'d like to apply to your space? You can do so here!</p><p>For more information, visit the <a href="oa-space?tour=banners" target="_blank">Banners Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    10 => array(
      'selector' => '.pane-node-form-author',
      'path' => '',
      'placement' => 'left',
      'title' => 'Authoring & Save',
      'content' => '<p>Lastly, you can save your brand new space.&nbsp;</p><p>If you so choose, you can override the author, date, and time.&nbsp;</p><p>You also have the option to publish it, save as a draft, or preview what it will look like.&nbsp;</p><p>Make sure to hit "publish" and you\'ll have created your first space!</p><p>To continue, check out the <a href="/temp-space?tour=subspaces" target="_blank">Subspaces Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['spaces'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'subspaces';
  $bootstrap_tour->title = 'Subspaces';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Walks a user through how to create a subspace';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#parent-dropdown',
      'path' => 'firstnode/oa_space/spaces',
      'placement' => 'bottom',
      'title' => 'Creating a Subspace',
      'content' => '<p>Welcome to your new space!&nbsp;</p><p>Some organizations will require an additional large collection of content nested within their space.&nbsp;We call these subspaces.&nbsp;</p><p>We create a subspace by going to "Create new Space."&nbsp;</p><p>For now, click "next" to get started with your first subspace.</p><p></p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '#page-title',
      'path' => 'node/add/oa-space',
      'placement' => 'bottom',
      'title' => 'Editing Your Subspace',
      'content' => '<p>You\'ll come to the same edit form as you do for any space.&nbsp;</p><p>Feel free to fill out any relevant information as necessary. (Visit the <a href="oa-space?tour=spaces" target="_blank">Spaces Overview</a> tour for more information.)</p><p>Then click "next."</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.form-item-oa-parent-space-und-0-default',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Nesting Your Subspace',
      'content' => '<p>Now that you\'ve filled out all relevant fields you\'ll select the appropriate "parent" space for your subspace.</p><p>Select whichever space you\'d like the subspace to be directly nested underneath.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'left',
      'title' => 'Save!',
      'content' => '<p>Now hit "Publish" and you\'ll have created your first subsapce.</p><p>To continue, check out the <a href="oa-section?tour=sections_overview" target="_blank">Sections Overview Tour</a>.</p>',
      'format' => 'panopoly_html_text',
    ),
  );
  $export['subspaces'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'teams';
  $bootstrap_tour->title = 'Teams';
  $bootstrap_tour->roles = 2;
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This walks the user through the basics of creating a team.';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#toolbar-menu-button',
      'path' => '<front>',
      'placement' => 'right',
      'title' => 'Creating a Team',
      'content' => '<p>Teams are ad-hoc collection of users specific to one space.</p><p>They can be created in a similar manner as groups by going to the Drupal "Admin" button and hitting "Add Content."</p><p>For now, click "next."</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => 'dt:nth-child(21) a',
      'path' => 'node/add',
      'placement' => 'right',
      'title' => 'Creating a Team',
      'content' => '<p>Select the "Team" option.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '',
      'path' => 'node/add/oa-team',
      'placement' => 'top',
      'title' => 'Create a Team',
      'content' => '<p>Similar to a Group, all that is required of a Team is a Title.</p><p>In addition, you have the option of adding a description.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '.form-item-field-oa-team-users-und',
      'path' => '',
      'placement' => 'left',
      'title' => 'Team Members',
      'content' => '<p>Once you\'ve created additional users on your site, you can select which users to include in the team here.</p><p>(For more information on how to create users, visit our <a href="/?tour=user_creation" target="_blank">User Creation Tour</a>.)</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#edit-og-group-ref-und-0-default',
      'path' => '',
      'placement' => 'right',
      'title' => 'Select the Space for the Team',
      'content' => '<p>Lastly, make sure that you select the space the team should be nested beneath.</p><p>If you create the team within the space, this should automatically populate with the correct team.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'left',
      'title' => 'Save!',
      'content' => '<p>Hit "Publish" and save your first team!</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['teams'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'toolbar';
  $bootstrap_tour->title = 'Toolbar';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This walks the user through the toolbar';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#tours-dropdown',
      'path' => '<front>',
      'placement' => 'bottom',
      'title' => 'Toolbar',
      'content' => '<p>This black toolbar exists throughout your entire Open Atrium 2 site.</p><p>One of the main features of the toolbar is the Help Button ("?"). This is where all your site tours live.</p><p>For more information on tours, visit the <a href="/?tour=site_tours" target="_blank">Site Tours</a> walkthrough.</p>',
      'format' => 'panopoly_html_text',
    ),
    1 => array(
      'selector' => '#favorites-dropdown',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Favorites',
      'content' => '<p>You also have the option to favorite spaces and sections with the Favorites Button.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '.pane-oa-toolbar-search',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Search',
      'content' => '<p>The search bar can be used to search all spaces, a specific space, or by users.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#user-badge-dropdown',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'User Profile',
      'content' => '<p>This badge allows you to access your user dashboard and profile.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '#oa_breadcrumb',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Breadcrumbs',
      'content' => '<p>This menu dynamically changes as you move throughout the site and acts as your breadcrumbs.</p><p>We are currently on home, but hitting the Home Button will always take you back here.</p><p>In addition, the drop down next to "Spaces" will have a list of the spaces you create as well as allow you to create new spaces.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '.oa-breadcrumb:nth-child(2)',
      'path' => 'firstnode/oa_space/spaces',
      'placement' => 'bottom',
      'title' => 'Breadcrumbs Shift',
      'content' => '<p>As you move through your spaces and sections, notice that the breadcrumbs shift to the left.</p><p>Spaces nest down into subspaces, which nest down into sections and specific pieces of content.</p><p>When your current space is listed, the dropdown will list any sections and allow you to create new sections.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '.oa-buttons',
      'path' => 'firstnode/oa_section/sections_overview',
      'placement' => 'bottom',
      'title' => 'Adding Content',
      'content' => '<p>Also note that once you\'ve created a section the "+" button will show up, which will allow you to add content to your sections.</p><p>This will also show up at the space level once you\'ve created a section.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['toolbar'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'user_creation';
  $bootstrap_tour->title = 'User Creation';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'This walks an admin through how to add users to their site';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#toolbar-menu-button',
      'path' => '<front>',
      'placement' => 'right',
      'title' => 'Creating a User',
      'content' => '<p>To create a new user on your OA2 site, follow the same steps you would as a normal Drupal admin.</p><p>Click the Drupal "Admin" button" and select "People."</p><p>(For now, just hit "next.")</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    1 => array(
      'selector' => '.action-links a',
      'path' => 'admin/people',
      'placement' => 'right',
      'title' => 'Add User',
      'content' => '<p>Next, select "add user."</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    2 => array(
      'selector' => '#edit-name',
      'path' => 'admin/people/create',
      'placement' => 'right',
      'title' => 'Username',
      'content' => '<p>Give the new user an appropriate username.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    3 => array(
      'selector' => '#edit-mail',
      'path' => '',
      'placement' => 'right',
      'title' => 'Email',
      'content' => '<p>Then provide an email address that will be associated with their account.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    4 => array(
      'selector' => '.password-parent',
      'path' => '',
      'placement' => 'right',
      'title' => 'Password',
      'content' => '<p>Provide them with a password and verify that it\'s accurate.</p><p>You can determine the strength of your password via the "password strength" meter to the right of the password field.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    5 => array(
      'selector' => '#edit-status :nth-child(2) .option',
      'path' => '',
      'placement' => 'right',
      'title' => 'Status',
      'content' => '<p>Note that when creating a new user, the status will automatically default to "active."</p><p>However, you can return here to block a user in the future.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    6 => array(
      'selector' => '.form-disabled .option',
      'path' => '',
      'placement' => 'right',
      'title' => 'User Roles',
      'content' => '<p>Next, identify any roles beyond "authenticated user" the new space member will need.</p><p>Or just leave them blank.&nbsp;</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    7 => array(
      'selector' => '#edit-field-user-display-name-und-0-value',
      'path' => '',
      'placement' => 'right',
      'title' => 'Display Name',
      'content' => '<p>Lastly identify the display name for your user.&nbsp;</p><p>If it\'s the same as the username, feel free to copy and paste that informtion here.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
    8 => array(
      'selector' => '#edit-submit',
      'path' => '',
      'placement' => 'right',
      'title' => 'Submit',
      'content' => '<p>All that\'s left to do is save and you\'ve created a new user!</p><p>To continue, check out the <a href="/?tour=groups" target="_blank">Groups Tour</a>.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['user_creation'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'welcome_to_oa2_';
  $bootstrap_tour->title = 'Welcome to OA2!';
  $bootstrap_tour->roles = '';
  $bootstrap_tour->autorun = 1;
  $bootstrap_tour->description = 'Welcomes first time installers to OA2 and gives them options for tours.';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '',
      'path' => '<front>',
      'placement' => 'bottom',
      'title' => 'Welcome to OA2!',
      'content' => '<p>Hi there!&nbsp;</p><p>Thanks for installing Open Atrium 2!&nbsp;</p><p>If you\'d like us to help you get your feet wet around creating your first OA2 site, <a href="?tour=spaces">click here</a>.</p><p>If you\'re not quite ready for that and would like to see a tour about OA2 on a pre-built site, <a href="http://docs.openatrium.com/?tour=welcome_to_the_oa2_doc_site_" target="_blank">click here</a>.</p><p>If you don\'t wish to take any tours right now, just hit "End Tour" below. These tours will always be available via the "?" button on the main toolbar.</p>',
      'format' => 'panopoly_wysiwyg_text',
    ),
  );
  $export['welcome_to_oa2_'] = $bootstrap_tour;

  return $export;
}
