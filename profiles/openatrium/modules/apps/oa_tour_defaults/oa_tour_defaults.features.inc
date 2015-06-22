<?php
/**
 * @file
 * oa_tour_defaults.features.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function oa_tour_defaults_default_bootstrap_tour() {
  $items = array();
  $items['banners'] = entity_import('bootstrap_tour', '{
    "title" : "Banners",
    "name" : "banners",
    "description" : "Adding banners to the site",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : "",
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"node\\/add\\/oa-space","selector":"#edit-field-oa-banner-position-und","placement":"right","title":"Space Banner","content":"\\u003Cp\\u003E\\u003Cspan\\u003ESelect a banner image to be uploaded. \\u0026nbsp;\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003Cspan\\u003EBanner images should have an aspect ratio appropriate for streching across the full width of the site.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-field-oa-banner-position-und","placement":"right","title":"Banner Position","content":"\\u003Cp\\u003E\\u003Cspan\\u003EYou can choose to show the banner above or below the main Open Atrium toolbar.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-field-oa-banner-text-und-0-value","placement":"right","title":"Banner Text","content":"\\u003Cp\\u003E\\u003Cspan\\u003EYou can optionally add text to be overlayed on top of the image.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"\\u003Cfront\\u003E","selector":"#toolbar-menu-button","placement":"right","title":"Site Banners","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo change banners for the entire site, select the Open Atrium Plugin Settings from the main Drupal Admin menu.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/openatrium\\/setting","selector":"#edit-oa-site-banner-file-remove-button","placement":"right","title":"Sitewide Banner","content":"\\u003Cp\\u003E\\u003Cspan\\u003EUpload an image to be shown as the banner for the entire web site.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-oa-site-banner-position","placement":"right","title":"Banner Position","content":"\\u003Cp\\u003ELike Space banners, you can select to display the Site banner above or below the main toolbar.\\u003C\\/p\\u003E\\u003Cp\\u003EIf you display the Site banner in the same location as the Space banner, the Space banner will override the Site banner. \\u0026nbsp;Otherwise both will appear.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-oa-banner-stretch label","placement":"right","title":"Stretching Banners","content":"\\u003Cp\\u003E\\u003Cspan\\u003EUnlike Space banners, the Site banner can either Stretch to fill the full width of the site, or it can be left un-stretched.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-oa-banner-sitename label","placement":"right","title":"Banner Text","content":"\\u003Cp\\u003E\\u003Cspan\\u003EOptionally display the site Name and Slogan over the banner image.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['colorizing_a_space'] = entity_import('bootstrap_tour', '{
    "title" : "Colorizing a Space",
    "name" : "colorizing_a_space",
    "description" : "How to change theme colors",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : "",
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"mynode\\/oa_space:spaces","selector":"#contextual-tabs","placement":"left","title":"Customizing Colors","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo change the Colors of a Space, select the Config option from the contextual drop-down menu.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"mynode\\/oa_space:spaces\\/group","selector":"","placement":"right","title":"Change Appearance","content":"\\u003Cp\\u003E\\u003Cspan\\u003EClick the Appearance link to change the Colors for the Space.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"mynode\\/oa_space:spaces\\/group\\/node\\/%\\/admin\\/appearance","selector":"#edit-scheme","placement":"right","title":"Colorizer Settings","content":"\\u003Cp\\u003ESelect a pre-defined color scheme for your Space.\\u003C\\/p\\u003E\\u003Cp\\u003EOr, click on a spacific color to change it.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".farbtastic","placement":"right","title":"Changing Colors","content":"\\u003Cp\\u003E\\u003Cspan\\u003EAs you change the color using the color picker, the colors on the page will change automatically.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-colorizer-clearcache","placement":"right","title":"Save your Changes","content":"\\u003Cp\\u003EWhen you are finished customizing the colors, click Save.\\u003C\\/p\\u003E\\u003Cp\\u003EThe Clear Colorizer Cache is used to refresh the colors if the underlying theme files are updated.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-colorizer-reset label","placement":"right","title":"Resetting Colors","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo reset colors back to the default theme, click this box and then Save.\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['configuring_layout'] = entity_import('bootstrap_tour', '{
    "title" : "Configuring Layout",
    "name" : "configuring_layout",
    "description" : "",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"mynode\\/oa_space:spaces","selector":"#ajax-link","placement":"bottom","title":"Configure Layout","content":"\\u003Cp\\u003EWhen you create a space, you have the option of configuring the layout according to a number of built in templates.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EClick \\u0022Change this Layout\\u0022 to choose from 31 built in content layouts.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#panels-ipe-customize-page","placement":"left","title":"Customizing Your Page","content":"\\u003Cp\\u003EIn addition, \\u0026nbsp;you have full control over which widgets you wish to have in your space.\\u003C\\/p\\u003E\\u003Cp\\u003EClick the \\u0022Customize this Page\\u0022 to access the ability to drag and drop different widgets to different locations on the space.\\u003C\\/p\\u003E\\u003Cp\\u003EIn addition, you can control the theming of the individual widgets and edit the content within them.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['content_visibility'] = entity_import('bootstrap_tour', '{
    "title" : "Content Visibility",
    "name" : "content_visibility",
    "description" : "This will discuss content visibility with the user",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"node\\/add\\/oa-space","selector":".pane-node-group-access","placement":"left","title":"Content Visibility","content":"\\u003Cp\\u003EYou have the ability to determine whether or not your content is public or private.\\u003C\\/p\\u003E\\u003Cp\\u003EThis can be done all the way from your highest level space to your most heavily nested section.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-group-access-und :nth-child(1) .option","placement":"bottom","title":"Public Visibility","content":"\\u003Cp\\u003EIf a space is considered \\u0022public,\\u0022 this means that all authenticated users of your site as well as anonymous internet users will be able to\\u0026nbsp;\\u003Cem\\u003Eview\\u003C\\/em\\u003E your content.\\u003C\\/p\\u003E\\u003Cp\\u003EOnly authorized users will have write access.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-group-access-und :nth-child(2) .option","placement":"bottom","title":"Private Visibility","content":"\\u003Cp\\u003EIf your space is \\u0022private,\\u0022 this means that only authenticated users of your site will be able to view your content.\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-group-access","placement":"left","title":"Site Wide Visibility","content":"\\u003Cp\\u003EThe visibility of your site can range from completely public, completely private, or mixed mode.\\u003C\\/p\\u003E\\u003Cp\\u003EMixed mode merely means that your top level space is public, but additional subspaces or sections nested beneath are a mixture of public\\/private.\\u003C\\/p\\u003E\\u003Cp\\u003EIn addition, your top level space can be private with further divisions of permissions throughout.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"","placement":"bottom","title":"Section Visibility","content":"\\u003Cp\\u003EFor more information on specific permissions, visit our \\u003Ca href=\\u0022oa-section?tour=section_visibility\\u0022 target=\\u0022_blank\\u0022\\u003ESection Visibility Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_html_text"}
    ]
  }');
  $items['groups'] = entity_import('bootstrap_tour', '{
    "title" : "Groups",
    "name" : "groups",
    "description" : "This walks the user through the basic concept and creation of a group",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"#toolbar-menu-button","placement":"right","title":"Creating a Group","content":"\\u003Cp\\u003EThe site admin has the ability to create groups for the whole OA2 site.\\u003C\\/p\\u003E\\u003Cp\\u003EThis is because groups are meant to be collection of users that span a related purpose across multiple spaces.\\u003C\\/p\\u003E\\u003Cp\\u003ETo create your first group, you\\u0027d click the Drupal \\u0022Admin\\u0022 button and click \\u0022Add Content.\\u0022\\u003C\\/p\\u003E\\u003Cp\\u003EFor now, click \\u0022next.\\u0022\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"node\\/add","selector":"dt:nth-child(9) a","placement":"right","title":"Creating a Group","content":"\\u003Cp\\u003ESelect the \\u0022groups\\u0022 option.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"node\\/add\\/oa-group","selector":"#edit-title","placement":"bottom","title":"Title","content":"\\u003Cp\\u003EProvide your group with an appropriate name.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-body","placement":"top","title":"Description","content":"\\u003Cp\\u003EYou also have the option to provide your group with a description.\\u003C\\/p\\u003E\\u003Cp\\u003EThe WYSIWYG includes the ability for embedding images and videos if you wish.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-path-alias","placement":"bottom","title":"Permalink","content":"\\u003Cp\\u003EYou can customize your permalink or let the site automatically generate it from the title.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-field-featured-image","placement":"left","title":"Featured Image","content":"\\u003Cp\\u003ESelect a featured image if you so choose.\\u003C\\/p\\u003E\\u003Cp\\u003EAcceptable file formats include .jpg, .png, and .gif.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-group-access label:nth-child(1)","placement":"top","title":"Group Visibility","content":"\\u003Cp\\u003EDecide whether or not you would like your group to be publicly visible or private.\\u003C\\/p\\u003E\\u003Cp\\u003EGroups that are visible to the public can allow non-members to request membership.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-submit","placement":"left","title":"Save!","content":"\\u003Cp\\u003EHit \\u0022Publish\\u0022 to save your first group!\\u003C\\/p\\u003E\\u003Cp\\u003EYou will be redirected to the main landing page of your group where you can add, remove, and manage the members of your group. This page can be accessed at any time through the following path: Admin \\u0026gt; Open Atrium \\u0026gt; Groups \\u0026gt; Select your group.\\u003C\\/p\\u003E\\u003Cp\\u003ETo continue, check out our \\u003Ca href=\\u0022\\/?tour=teams\\u0022 target=\\u0022_blank\\u0022\\u003ETeams Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['menus'] = entity_import('bootstrap_tour', '{
    "title" : "Menus",
    "name" : "menus",
    "description" : "This tour walks the user through the basic structure of menus on their OA2 site.",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"#toolbar-menu-button","placement":"right","title":"Main Menu","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo display the Main Menu at the top of the site, select Open Atrium Plugin Settings from the Drupal Admin menu.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/openatrium\\/setting","selector":".form-item-oa-mainmenu label","placement":"right","title":"Show Main Menu","content":"\\u003Cp\\u003EEnable this option and Save to display the Main Menu at the top of the page.\\u003C\\/p\\u003E\\u003Cp\\u003ENote that it only displays if you have added items to the Menu.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"node\\/add\\/oa-space","selector":".pane-node-form-menu","placement":"left","title":"Adding Items to Menu","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo add something to the menu, edit the item and enable the menu link option, then select Main Menu in the Parent dropdown.\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003Cspan\\u003EYou can add items to menus at the space as well as the section level. Merely give menu link the title you\\u0027d like and nest it appropriately.\\u0026nbsp;\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"mynode\\/oa_space:spaces","selector":"#contextual-dropdown","placement":"left","title":"Space Menus","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo display the space-specific menu, select Config from the contextual drop-down.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"mynode\\/oa_space:spaces\\/group","selector":"dt:nth-child(7) a","placement":"right","title":"Space Menu","content":"\\u003Cp\\u003E\\u003Cspan\\u003ESelect the Menu option.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"mynode\\/oa_space:spaces\\/group\\/node\\/%\\/admin\\/menu","selector":".form-item-oa-space-menu label","placement":"right","title":"Space Menu","content":"\\u003Cp\\u003E\\u003Cspan\\u003ECheck this box and Save to display the Space-specific menu below the toolbar.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['notifications'] = entity_import('bootstrap_tour', '{
    "title" : "Notifications",
    "name" : "notifications",
    "description" : "Talking about notifications",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"node\\/add\\/oa-space","selector":".pane-node-form-oa-notifications .pane-title","placement":"left","title":"Notifications","content":"\\u003Cp\\u003EYou have the ability to add notifications at the space, subspace, section, and content level.\\u003C\\/p\\u003E\\u003Cp\\u003EThey work the same way regardless of what level you happen to be at.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-oa-notifications-notifications-group label","placement":"left","title":"Groups","content":"\\u003Cp\\u003EYou can identify specific groups you\\u0027d like to receive push notifications from your space, sections, or content.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-oa-notifications-notifications-team label","placement":"left","title":"Teams","content":"\\u003Cp\\u003EIn addition, you can select specific teams for push notifications as well.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-oa-notifications-notifications-user label","placement":"left","title":"Individual Users","content":"\\u003Cp\\u003EYou could also specify individual users that should receive push notifications or add them in addition to the groups and teams that have been selected.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#notifications-fields .option","placement":"left","title":"Do Not Send","content":"\\u003Cp\\u003EIf you don\\u0027t wish to send a notification around the changes that you\\u0027ve made, make sure to check the box.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-form-oa-notifications .pane-title","placement":"left","title":"Pull Notifications","content":"\\u003Cp\\u003EOnce you have created content, users will also have the option to subscripe to that content to receive pull notifications.\\u003C\\/p\\u003E\\u003Cp\\u003EWhen receiving notifications via email, users can respond in the email to post back to discussions etc.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['sandbox_mode'] = entity_import('bootstrap_tour', '{
    "title" : "Sandbox Mode",
    "name" : "sandbox_mode",
    "description" : "Describes how to use Sandbox Mode",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"#toolbar-menu-button","placement":"right","title":"Sandbox Mode","content":"\\u003Cp\\u003ESandbox Mode allows you to enter test content and easily remove it later.\\u003C\\/p\\u003E\\u003Cp\\u003ETo start Sandbox Mode, select it from the Drupal Admin menu, within the Open Atrium section.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/openatrium\\/sandbox","selector":"#oa-sandbox-settings-form .form-item-toggle label","placement":"right","title":"Enable Sandbox","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo enable Sandbox mode, check this box and click Save.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#oa-sandbox-indicator","placement":"right","title":"Sandbox Indicator","content":"\\u003Cp\\u003EWhen you are in Sandbox mode, this indicator is displayed on all pages.\\u003C\\/p\\u003E\\u003Cp\\u003EClick this indicator to return to this page to toggle sandbox mode.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".main-tabs ul li:nth-child(2) a","placement":"bottom","title":"Delete Sandbox","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo delete content created while in Sandbox mode, click the Delete tab.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/openatrium\\/sandbox\\/delete","selector":"#edit-submit","placement":"bottom","title":"Delete Content","content":"\\u003Cp\\u003EClick this Delete button to confirm you wish to remove your test content.\\u003C\\/p\\u003E\\u003Cp\\u003EAll content created while you are in Sandbox mode will be removed. \\u0026nbsp;\\u003Cstrong\\u003EThis cannot be undone!\\u003C\\/strong\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"node\\/add\\/oa-wiki-page","selector":".form-item-sandbox","placement":"left","title":"Creating Sandbox Content","content":"\\u003Cp\\u003EWhen creating new content in Sandbox Mode, the \\u0022Test content\\u0022 option will automatically be selected.\\u003C\\/p\\u003E\\u003Cp\\u003EIf you want to enter content that is preserved when you exit Sandbox you can uncheck this option.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['section_visibility'] = entity_import('bootstrap_tour', '{
    "title" : "Section Visibility",
    "name" : "section_visibility",
    "description" : "This walks the user through the basics of more specific permissions per section.",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"node\\/add\\/oa-section","selector":".pane-node-field-oa-group-ref .pane-title","placement":"left","title":"Section Visibility","content":"\\u003Cp\\u003EAs the space admin, you have the ability to determine exactly who has access to your section and the content within.\\u003C\\/p\\u003E\\u003Cp\\u003E(Curious about sections, visit the \\u003Ca href=\\u0022oa-section?tour=sections_overview\\u0022 target=\\u0022_blank\\u0022\\u003ESections Overview Tour\\u003C\\/a\\u003E first.)\\u003C\\/p\\u003E","content_text_format":"panopoly_html_text"},
      {"path":"","selector":".form-item-field-oa-group-ref-und","placement":"left","title":"Groups","content":"\\u003Cp\\u003EA group is a collection of users that span a related purpose across multiple spaces. (For example, a group for a company\\u0027s leadership.)\\u003C\\/p\\u003E\\u003Cp\\u003EYou can select any relevant groups that would need private access to this section or leave it blank to allow all authenticated space members access to the content.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-field-oa-team-ref-und","placement":"left","title":"Teams","content":"\\u003Cp\\u003ETeams are an ad-hoc collection of users specific to one space. (For example, a product launch team.)\\u003C\\/p\\u003E\\u003Cp\\u003EYou can select any relevant teams that would need private access to this section or leave it blank to allow all authenticated space members access to the content.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-field-oa-user-ref","placement":"left","title":"Individual Users","content":"\\u003Cp\\u003ELastly, you can identify individual users that would require access to this space.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-field-oa-group-ref .pane-title","placement":"left","title":"Section Visibility","content":"\\u003Cp\\u003ESections can become private through any combination of groups, teams, and users. This allows for incredibly granular permissions across your site, spaces, and sections.\\u003C\\/p\\u003E\\u003Cp\\u003EFor more information on how content hierarchy and permissions work together, check out this handy \\u003Ca href=\\u0022http:\\/\\/docs.openatrium.com\\/content\\/oa2-terminology-privacy-diagram\\u0022 target=\\u0022_blank\\u0022\\u003EOA2 Terminology \\u0026amp; Privacy Diagram\\u003C\\/a\\u003E on the \\u003Ca href=\\u0022http:\\/\\/docs.openatrium.com\\/\\u0022 target=\\u0022_blank\\u0022\\u003EOA2 Documentation Site\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can also continue by taking our \\u003Ca href=\\u0022\\/?tour=groups\\u0022 target=\\u0022_blank\\u0022\\u003EGroups Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['sections_overview'] = entity_import('bootstrap_tour', '{
    "title" : "Sections Overview",
    "name" : "sections_overview",
    "description" : "This will walk the user through how to create their first section",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"node\\/add\\/oa-section","selector":"","placement":"top","title":"Creating a Section","content":"\\u003Cp\\u003EAny space or subspace can house sections.\\u003C\\/p\\u003E\\u003Cp\\u003ESections are where the actual content of your site lives.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003ENormally you\\u0027ll hit this dropdown next to the space and select \\u0022create new section.\\u0022\\u003C\\/p\\u003E\\u003Cp\\u003EFor now, hit \\u0022next\\u0022 to create your first section.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"","placement":"right","title":"Editing Your Section","content":"\\u003Cp\\u003EFiling out the basic information for a section is very similar to that of a space.\\u003C\\/p\\u003E\\u003Cp\\u003EEnter in a title, body, and, if you\\u0027d like, customize the permalink.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-field-oa-group-ref .pane-title","placement":"left","title":"Section Visibility","content":"\\u003Cp\\u003EYou can set specific permissions for your section via the section visibility widget.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EFor a more indepth look at the section visibility widget, visit the \\u003Ca href=\\u0022oa-section?tour=section_visibility\\u0022 target=\\u0022_blank\\u0022\\u003ESection Visibility Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-form-oa-notifications .pane-title","placement":"left","title":"Section Notifications","content":"\\u003Cp\\u003ESimilar to spaces, sections can have their own set of notifications.\\u003C\\/p\\u003E\\u003Cp\\u003EVisit the \\u003Ca href=\\u0022oa-space?tour=notifications\\u0022 target=\\u0022_blank\\u0022\\u003ENotifications Tour\\u003C\\/a\\u003E for more information.\\u003C\\/p\\u003E","content_text_format":"panopoly_html_text"},
      {"path":"","selector":".pane-node-form-menu .pane-title","placement":"left","title":"Section Menu","content":"\\u003Cp\\u003EEach of your sections can also have a menu that\\u0027s nested beneath the larger space menu.\\u003C\\/p\\u003E\\u003Cp\\u003EFor more information visit the \\u003Ca href=\\u0022\\/?tour=menus\\u0022 target=\\u0022_blank\\u0022\\u003EMenus Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-form-publishing .pane-title","placement":"left","title":"Publishing Workflow","content":"\\u003Cp\\u003ESame as any space, you can determine whether or not you\\u0027d like to create a revision history of your space.\\u003C\\/p\\u003E\\u003Cp\\u003EIn addition, you can select your section to be included in the test content repository within Sandbox Mode.\\u003C\\/p\\u003E\\u003Cp\\u003EFor more information visit the \\u003Ca href=\\u0022\\/?tour=sandbox_mode\\u0022 target=\\u0022_blank\\u0022\\u003ESandbox Mode Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-field-oa-section-weight-und-0-value","placement":"right","title":"Weight","content":"\\u003Cp\\u003EWhen you have multiple sections within a space, you can determine the order in which they are listed on your main space page via the weight.\\u003C\\/p\\u003E\\u003Cp\\u003EThe lower the number, the higher in the list the section will be listed. (i.e. a section weighted -10 will be listed before a section weighted 0)\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-field-oa-section-und","placement":"right","title":"Section Type","content":"\\u003Cp\\u003ESections can take on many different forms.\\u003C\\/p\\u003E\\u003Cp\\u003EOA2 ships standard with document, discussions, calendars, and tasks sections.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003E(The document sections work particularly well for wikis, document management, and content updates that need to be a bit more visible than discussions.)\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".selected a","placement":"right","title":"Comments","content":"\\u003Cp\\u003EYou can also determine whether or not you\\u0027d like to allow comments across the section here.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-submit","placement":"left","title":"Save!","content":"\\u003Cp\\u003EBe sure to alter the authoring information as appropriate and hit \\u0022publish\\u0022 to save your first section.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003ENow that you\\u0027ve got the basics of content creation, let\\u0027s create your first user via the \\u003Ca href=\\u0022\\/?tour=user_creation\\u0022 target=\\u0022_blank\\u0022\\u003EUser Creation Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['setting_your_home'] = entity_import('bootstrap_tour', '{
    "title" : "Setting Your Home",
    "name" : "setting_your_home",
    "description" : "This allows users to understand how to link a specific space to their home icon",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":".btn-home","placement":"bottom","title":"Setting Your Home","content":"\\u003Cp\\u003EOnce you\\u0027ve created a number of spaces and content, you\\u0027ll likely want to change the page the home icon goes to.\\u003C\\/p\\u003E\\u003Cp\\u003ETo do so, use the following path: Drupal Admin \\u0026gt; Configuration \\u0026gt; System \\u0026gt; Site Information.\\u003C\\/p\\u003E\\u003Cp\\u003EFor now, just hit \\u0022next.\\u0022\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/config\\/system\\/site-information","selector":"#edit-site-frontpage","placement":"right","title":"Select Your Default Home","content":"\\u003Cp\\u003EHere, you can enter in the relative path for the page you\\u0027d like to be your default home.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['site_tours'] = entity_import('bootstrap_tour', '{
    "title" : "Site Tours",
    "name" : "site_tours",
    "description" : "How to create a site tour",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : "",
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"#tours-dropdown","placement":"bottom","title":"Site Tours","content":"\\u003Cp\\u003E\\u003Cspan\\u003EClick this help button from any page to see a list of Help Tutorials. \\u0026nbsp;\\u003C\\/span\\u003E\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003Cspan\\u003EChoose a tutorial from the list to get popup help about that topic.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#toolbar-menu-button","placement":"right","title":"Editing Tours","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo create or edit tours, select the \\u0022Site Tours\\u0022 option from the main Drupal Admin menu.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/structure\\/tours","selector":".action-links li:nth-child(1) a","placement":"bottom","title":"Create New Tour","content":"\\u003Cp\\u003E\\u003Cspan\\u003ETo create a new tour, click the Add Tour link.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/structure\\/tours\\/add","selector":"#edit-title","placement":"right","title":"Creating a Tour","content":"\\u003Cp\\u003E\\u003Cspan\\u003EA tour consists of a title, description, and then multiple steps of popup help.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-0-path","placement":"right","title":"Tour Path","content":"\\u003Cp\\u003EEach Step in a Tour starts with a Path.\\u003C\\/p\\u003E\\u003Cp\\u003EA Path is the URL of the page you want the popup to appear. \\u0026nbsp;Use \\u0026lt;front\\u0026gt; for the home page. \\u0026nbsp;Do not put a \\/ at the beginning.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-0-selector","placement":"right","title":"Tour Selector","content":"\\u003Cp\\u003EEach step in the Tour needs a CSS Selector. \\u0026nbsp;This specifies the page element that the popup should appear over.\\u003C\\/p\\u003E\\u003Cp\\u003EGetting the correct CSS Selector can be a bit tricky and might require some CSS knowledge. \\u0026nbsp;Usually you can right-click the element and select \\u0022Inspect Element\\u0022 to open the browser debugger. \\u0026nbsp;Enter an #id or .class for the item. \\u0026nbsp;You can use any full jQuery selector here.\\u003C\\/p\\u003E\\u003Cp\\u003EBrowser plugins such as\\u0026nbsp;\\u003Ca href=\\u0022http:\\/\\/selectorgadget.com\\/\\u0022\\u003ESelectorGadget\\u0026nbsp;\\u003C\\/a\\u003Ecan help with this.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-0-placement","placement":"right","title":"Tour Position","content":"\\u003Cp\\u003E\\u003Cspan\\u003ESelect where you want the popup to appear relative to the CSS element.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-0-title","placement":"right","title":"Tour Step Title","content":"\\u003Cp\\u003E\\u003Cspan\\u003EEach step in the tour has a Title that appears in the caption for the popup.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-0-content-value label","placement":"top","title":"Tour Text","content":"\\u003Cp\\u003E\\u003Cspan\\u003EFinally, each step in the Tour has a full WYSIWYG to edit the body of the popup.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-bootstrap-tour-step-reference-und-actions-ief-add","placement":"right","title":"Add Steps","content":"\\u003Cp\\u003EYou can add additional steps to the Tour by clicking the \\u0022Add another step\\u0022 button.\\u003C\\/p\\u003E\\u003Cp\\u003EOr just click \\u0022Save\\u0022 to save the Tour.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['spaces'] = entity_import('bootstrap_tour', '{
    "title" : "Spaces Overview",
    "name" : "spaces",
    "description" : "This is the basic overview of the most commonly used fields when creating a space.",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"node\\/add\\/oa-space","selector":"#page-title","placement":"bottom","title":"Spaces Overview","content":"\\u003Cp\\u003EEvery OA2 site is a unique mixture of content and users.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EWe\\u0027ll begin by first creating the structure for your content. \\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EAt the highest level, you have spaces, which are large collections of content.\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003Cem\\u003E(You may have been redirected here if you have attempted to access other tours that require a space to exist before you can run them. \\u003C\\/em\\u003E\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003Cem\\u003E\\u003Cstrong\\u003EPlease be sure to create and save your first space\\u003C\\/strong\\u003E.)\\u003C\\/em\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-title","placement":"right","title":"Title","content":"\\u003Cp\\u003EAt a minimum, each space requires a title.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EGo ahead and add in the title for your first space and click \\u0022next.\\u0022\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".text-format-wrapper","placement":"top","title":"Description","content":"\\u003Cp\\u003EYou also have the ability to write out a description.\\u003C\\/p\\u003E\\u003Cp\\u003ENote that the description field is a full fledged WYSIWYG with multiple formatting options and image\\/video embed.\\u003C\\/p\\u003E\\u003Cp\\u003EHowever, you are free to switch it to HTML, Full HTML, or Plain Text. (Switched below the edit form.)\\u003C\\/p\\u003E\\u003Cp\\u003EGo ahead and add in a description if you\\u0027d like and hit \\u0022next.\\u0022\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-form-path","placement":"bottom","title":"Permalink","content":"\\u003Cp\\u003E\\u003Cspan\\u003EYou have the option to either customize the URL of your space or allow it to be automatically generated from the title.\\u003C\\/span\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-group-access","placement":"left","title":"Content Visibility","content":"\\u003Cp\\u003EThis field allows you to determine whether your space is \\u0022public\\u0022 or \\u0022private.\\u0022\\u003C\\/p\\u003E\\u003Cp\\u003EFor additional information on the differences between these two options, check out the \\u003Ca href=\\u0022oa-space?tour=content_visibility\\u0022 target=\\u0022_blank\\u0022\\u003EContent Visibility Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_html_text"},
      {"path":"","selector":".pane-node-field-featured-image","placement":"left","title":"Featured Image","content":"\\u003Cp\\u003ENext, you can select a featured image for your space.\\u003C\\/p\\u003E\\u003Cp\\u003EAcceptable file formats include .jpg, .png, and .gif.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-form-oa-notifications","placement":"left","title":"Notifications","content":"\\u003Cp\\u003ENotifications allow you to keep your users, groups, and teams up to date.\\u003C\\/p\\u003E\\u003Cp\\u003EFor a more indepth look, visit the \\u003Ca href=\\u0022oa-space?tour=notifications\\u0022 target=\\u0022_blank\\u0022\\u003ENotifications Tour\\u003C\\/a\\u003E.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_html_text"},
      {"path":"","selector":".pane-node-form-menu","placement":"left","title":"Menus","content":"\\u003Cp\\u003EIf you have a space that requires a more robust menu system, you can define the menu link for your space here.\\u003C\\/p\\u003E\\u003Cp\\u003EFor more information on menus, visit the \\u003Ca href=\\u0022\\/?tour=menus\\u0022 target=\\u0022_blank\\u0022\\u003EMenus Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-form-publishing","placement":"left","title":"Publishing Workflow","content":"\\u003Cp\\u003EThere is also basic workflow steps built into OA2, which allows you to keep a revision history of the space.\\u003C\\/p\\u003E\\u003Cp\\u003EIn addition, if you\\u0027re working in sandbox mode as a developer, this is where you can choose to turn this space into test content or not.\\u003C\\/p\\u003E\\u003Cp\\u003EFor more information on sandbox mode, visit our \\u003Ca href=\\u0022\\/?tour=sandbox_mode\\u0022 target=\\u0022_blank\\u0022\\u003ESandbox Mode Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".fieldset-title","placement":"right","title":"Banners","content":"\\u003Cp\\u003EHave a banner image you\\u0027d like to apply to your space? You can do so here!\\u003C\\/p\\u003E\\u003Cp\\u003EFor more information, visit the \\u003Ca href=\\u0022oa-space?tour=banners\\u0022 target=\\u0022_blank\\u0022\\u003EBanners Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-node-form-author","placement":"left","title":"Authoring \\u0026 Save","content":"\\u003Cp\\u003ELastly, you can save your brand new space.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EIf you so choose, you can override the author, date, and time.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EYou also have the option to publish it, save as a draft, or preview what it will look like.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EMake sure to hit \\u0022publish\\u0022 and you\\u0027ll have created your first space!\\u003C\\/p\\u003E\\u003Cp\\u003ECheck out the Subspaces Tour once published (via the ? by the search bar).\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['subspaces'] = entity_import('bootstrap_tour', '{
    "title" : "Subspaces",
    "name" : "subspaces",
    "description" : "Walks a user through how to create a subspace",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"mynode\\/oa_space:spaces","selector":"#parent-dropdown","placement":"bottom","title":"Creating a Subspace","content":"\\u003Cp\\u003EWelcome to your new space!\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003ESome organizations will require an additional large collection of content nested within their space.\\u0026nbsp;We call these subspaces.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EWe create a subspace by going to \\u0022Create new Space.\\u0022\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EFor now, click \\u0022next\\u0022 to get started with your first subspace.\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"node\\/add\\/oa-space","selector":"#page-title","placement":"bottom","title":"Editing Your Subspace","content":"\\u003Cp\\u003EYou\\u0027ll come to the same edit form as you do for any space.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EFeel free to fill out any relevant information as necessary. (Visit the \\u003Ca href=\\u0022oa-space?tour=spaces\\u0022 target=\\u0022_blank\\u0022\\u003ESpaces Overview\\u003C\\/a\\u003E tour for more information.)\\u003C\\/p\\u003E\\u003Cp\\u003EThen click \\u0022next.\\u0022\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-oa-parent-space-und-0-default","placement":"bottom","title":"Nesting Your Subspace","content":"\\u003Cp\\u003ENow that you\\u0027ve filled out all relevant fields you\\u0027ll select the appropriate \\u0022parent\\u0022 space for your subspace.\\u003C\\/p\\u003E\\u003Cp\\u003ESelect whichever space you\\u0027d like the subspace to be directly nested underneath.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-submit","placement":"left","title":"Save!","content":"\\u003Cp\\u003ENow hit \\u0022Publish\\u0022 and you\\u0027ll have created your first subsapce.\\u003C\\/p\\u003E\\u003Cp\\u003ETo continue, check out the \\u003Ca href=\\u0022oa-section?tour=sections_overview\\u0022 target=\\u0022_blank\\u0022\\u003ESections Overview Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_html_text"}
    ]
  }');
  $items['teams'] = entity_import('bootstrap_tour', '{
    "title" : "Teams",
    "name" : "teams",
    "description" : "This walks the user through the basics of creating a team.",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"#toolbar-menu-button","placement":"right","title":"Creating a Team","content":"\\u003Cp\\u003ETeams are ad-hoc collection of users specific to one space.\\u003C\\/p\\u003E\\u003Cp\\u003EThey can be created in a similar manner as groups by going to the Drupal \\u0022Admin\\u0022 button and hitting \\u0022Add Content.\\u0022\\u003C\\/p\\u003E\\u003Cp\\u003EFor now, click \\u0022next.\\u0022\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"node\\/add","selector":"dt:nth-child(21) a","placement":"right","title":"Creating a Team","content":"\\u003Cp\\u003ESelect the \\u0022Team\\u0022 option.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"node\\/add\\/oa-team","selector":"","placement":"top","title":"Create a Team","content":"\\u003Cp\\u003ESimilar to a Group, all that is required of a Team is a Title.\\u003C\\/p\\u003E\\u003Cp\\u003EIn addition, you have the option of adding a description.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-item-field-oa-team-users-und","placement":"left","title":"Team Members","content":"\\u003Cp\\u003EOnce you\\u0027ve created additional users on your site, you can select which users to include in the team here.\\u003C\\/p\\u003E\\u003Cp\\u003E(For more information on how to create users, visit our \\u003Ca href=\\u0022\\/?tour=user_creation\\u0022 target=\\u0022_blank\\u0022\\u003EUser Creation Tour\\u003C\\/a\\u003E.)\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-og-group-ref-und-0-default","placement":"right","title":"Select the Space for the Team","content":"\\u003Cp\\u003ELastly, make sure that you select the space the team should be nested beneath.\\u003C\\/p\\u003E\\u003Cp\\u003EIf you create the team within the space, this should automatically populate with the correct team.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-submit","placement":"left","title":"Save!","content":"\\u003Cp\\u003EHit \\u0022Publish\\u0022 and save your first team!\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['toolbar'] = entity_import('bootstrap_tour', '{
    "title" : "Toolbar",
    "name" : "toolbar",
    "description" : "This walks the user through the toolbar",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"#tours-dropdown","placement":"bottom","title":"Toolbar","content":"\\u003Cp\\u003EThis black toolbar exists throughout your entire Open Atrium 2 site.\\u003C\\/p\\u003E\\u003Cp\\u003EOne of the main features of the toolbar is the Help Button (\\u0022?\\u0022). This is where all your site tours live.\\u003C\\/p\\u003E\\u003Cp\\u003EFor more information on tours, visit the \\u003Ca href=\\u0022\\/?tour=site_tours\\u0022 target=\\u0022_blank\\u0022\\u003ESite Tours\\u003C\\/a\\u003E walkthrough.\\u003C\\/p\\u003E","content_text_format":"panopoly_html_text"},
      {"path":"","selector":"#favorites-dropdown","placement":"bottom","title":"Favorites","content":"\\u003Cp\\u003EYou also have the option to favorite spaces and sections with the Favorites Button.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".pane-oa-toolbar-search","placement":"bottom","title":"Search","content":"\\u003Cp\\u003EThe search bar can be used to search all spaces, a specific space, or by users.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#user-badge-dropdown","placement":"bottom","title":"User Profile","content":"\\u003Cp\\u003EThis badge allows you to access your user dashboard and profile.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#oa_breadcrumb","placement":"bottom","title":"Breadcrumbs","content":"\\u003Cp\\u003EThis menu dynamically changes as you move throughout the site and acts as your breadcrumbs.\\u003C\\/p\\u003E\\u003Cp\\u003EWe are currently on home, but hitting the Home Button will always take you back here.\\u003C\\/p\\u003E\\u003Cp\\u003EIn addition, the drop down next to \\u0022Spaces\\u0022 will have a list of the spaces you create as well as allow you to create new spaces.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"firstnode\\/oa_space\\/spaces","selector":".oa-breadcrumb:nth-child(2)","placement":"bottom","title":"Breadcrumbs Shift","content":"\\u003Cp\\u003EAs you move through your spaces and sections, notice that the breadcrumbs shift to the left.\\u003C\\/p\\u003E\\u003Cp\\u003ESpaces nest down into subspaces, which nest down into sections and specific pieces of content.\\u003C\\/p\\u003E\\u003Cp\\u003EWhen your current space is listed, the dropdown will list any sections and allow you to create new sections.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"firstnode\\/oa_section\\/sections_overview","selector":".oa-buttons","placement":"bottom","title":"Adding Content","content":"\\u003Cp\\u003EAlso note that once you\\u0027ve created a section the \\u0022+\\u0022 button will show up, which will allow you to add content to your sections.\\u003C\\/p\\u003E\\u003Cp\\u003EThis will also show up at the space level once you\\u0027ve created a section.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['user_creation'] = entity_import('bootstrap_tour', '{
    "title" : "User Creation",
    "name" : "user_creation",
    "description" : "This walks an admin through how to add users to their site",
    "roles" : "2",
    "autorun" : "0",
    "start_path" : null,
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"#toolbar-menu-button","placement":"right","title":"Creating a User","content":"\\u003Cp\\u003ETo create a new user on your OA2 site, follow the same steps you would as a normal Drupal admin.\\u003C\\/p\\u003E\\u003Cp\\u003EClick the Drupal \\u0022Admin\\u0022 button\\u0022 and select \\u0022People.\\u0022\\u003C\\/p\\u003E\\u003Cp\\u003E(For now, just hit \\u0022next.\\u0022)\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/people","selector":".action-links a","placement":"right","title":"Add User","content":"\\u003Cp\\u003ENext, select \\u0022add user.\\u0022\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"admin\\/people\\/create","selector":"#edit-name","placement":"right","title":"Username","content":"\\u003Cp\\u003EGive the new user an appropriate username.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-mail","placement":"right","title":"Email","content":"\\u003Cp\\u003EThen provide an email address that will be associated with their account.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".password-parent","placement":"right","title":"Password","content":"\\u003Cp\\u003EProvide them with a password and verify that it\\u0027s accurate.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can determine the strength of your password via the \\u0022password strength\\u0022 meter to the right of the password field.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-status :nth-child(2) .option","placement":"right","title":"Status","content":"\\u003Cp\\u003ENote that when creating a new user, the status will automatically default to \\u0022active.\\u0022\\u003C\\/p\\u003E\\u003Cp\\u003EHowever, you can return here to block a user in the future.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":".form-disabled .option","placement":"right","title":"User Roles","content":"\\u003Cp\\u003ENext, identify any roles beyond \\u0022authenticated user\\u0022 the new space member will need.\\u003C\\/p\\u003E\\u003Cp\\u003EOr just leave them blank.\\u0026nbsp;\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-field-user-display-name-und-0-value","placement":"right","title":"Display Name","content":"\\u003Cp\\u003ELastly identify the display name for your user.\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EIf it\\u0027s the same as the username, feel free to copy and paste that informtion here.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"},
      {"path":"","selector":"#edit-submit","placement":"right","title":"Submit","content":"\\u003Cp\\u003EAll that\\u0027s left to do is save and you\\u0027ve created a new user!\\u003C\\/p\\u003E\\u003Cp\\u003ETo continue, check out the \\u003Ca href=\\u0022\\/?tour=groups\\u0022 target=\\u0022_blank\\u0022\\u003EGroups Tour\\u003C\\/a\\u003E.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  $items['welcome_to_oa2_'] = entity_import('bootstrap_tour', '{
    "title" : "Welcome to OA2!",
    "name" : "welcome_to_oa2_",
    "description" : "Welcomes first time installers to OA2 and gives them options for tours.",
    "roles" : "2",
    "autorun" : "1",
    "start_path" : "\\u003Cfront\\u003E",
    "enabled" : "1",
    "field_bootstrap_tour_spaces" : [],
    "steps" : [
      {"path":"\\u003Cfront\\u003E","selector":"","placement":"bottom","title":"Welcome to OA2!","content":"\\u003Cp\\u003EHi there!\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EThanks for installing Open Atrium 2!\\u0026nbsp;\\u003C\\/p\\u003E\\u003Cp\\u003EIf you\\u0027d like us to help you get your feet wet around creating your first OA2 site, \\u003Ca href=\\u0022?tour=spaces\\u0022\\u003Eclick here\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\u003Cp\\u003EIf you\\u0027re not quite ready for that and would like to see a tour about OA2 on a pre-built site, \\u003Ca href=\\u0022http:\\/\\/docs.openatrium.com\\/?tour=welcome_to_the_oa2_doc_site_\\u0022 target=\\u0022_blank\\u0022\\u003Eclick here\\u003C\\/a\\u003E.\\u003C\\/p\\u003E\\u003Cp\\u003EIf you don\\u0027t wish to take any tours right now, just hit \\u0022End Tour\\u0022 below. These tours will always be available via the \\u0022?\\u0022 button on the main toolbar.\\u003C\\/p\\u003E","content_text_format":"panopoly_wysiwyg_text"}
    ]
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_tour_defaults_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bootstrap_tour" && $api == "bootstrap_tour_tour") {
    return array("version" => "1");
  }
}
