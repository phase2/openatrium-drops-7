OPTIONAL but Recommended. Provides the widgets for the Breadcrumb navigation
toolbar, Main menu toolbar, Space menu toolbar, and the Drupal Admin menu
button.

Typically, the widgets and blocks in this module are placed onto the Toolbar
mini_panel (stored in oa_layouts).

Javascript in js/oa-toolbar.js is used to control the body top-margin to
account for the height needed by a static toolbar.

Main Menu widget
================

The oa_navigation widget is a custom Panels Pane for displaying the main menu,
optionally with the site banner as set in oa_appearance.  It has a single
configuration option to specific what Drupal menu to be shown in the widget.

Template for this widget is in oa_navigation.tpl.php.

Space Menu widget
=================

The oa_space_menu widget is a custom Panels Pane for displaying the
space-specific menu (og_single_menu).  It will optionally show the Space banner
image next to the menu.  No config options.  The Space Menu is enabled in the
Space -> Config -> Menu screen.

Template for this widget is in oa_space_menu.tpl.php.

Breadcrumb Navigator
====================

This is a custom Block that displays the Parent Space, Current Space, Current
Section, along with drop-down menus for navigating the spaces.  The
oa_toolbar_oa_settings_form() adds the following options to
the Admin ->Open Atrium -> Plugin Settings form:

- **Caption for space home page** (oa_toolbar_hometext) - Caption shown in toolbar
  when on a space landing page.  Only used in the old oa_toolbar block below.

- **Caption for Spaces** (oa_toolbar_spacetext) - Caption shown in dropdown for
  Spaces menu.  This is displayed in the Breadcrumb and old oa_toolbar when on the
  home page of the site and defaults to "Spaces".

- **Only show top-level spaces** (oa_toolbar_toplevel) - If enabled, the Home
  drop-down menu will only show top-level public spaces for anonymous users,
  rather than all public spaces.

There is also a banner setting to replace this breadcrumb with the Main Menu
widget shown above.

The template for the block is in oa_breadcrumb.tpl.php.  Extensive use of
Bootstrap class names to control the drop-down functionality.

User Badge
==========

This is a custom Block that displays the logged-in user's Name and Picture.  It
has a drop-down menu for Dashboard, Edit Profile, and Log Out.

Template for this widget is in oa_user_badge.tpl.php

Toolbar Menu Button
===================

This is a custom Block responsible for showing the Drupal Admin button.
Clicking this button displays the vertical NavBar menu.  Depends on the NavBar
module.  Javascript in js/toolbar-menu-toggle.js is used to control how the
Navbar is toggled and to put Shortcuts into the top of the menu.

Template for this button is in oa_toolbar_menu_button.tpl.php.

Old Toolbar
===========

A custom block called oa_toolbar was used prior to the Breadcrumb Navigator to
show a simple dropdown list of Spaces and Sections.  This block is deprecated.
