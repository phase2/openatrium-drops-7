OPTIONAL. Enables site and space-specific banners and colors.
Fields for space banners (described below) are exported to this Feature module.

Colors
======

For Colors, the Space -> Config -> Appearance page is added to call the
Colorizer module.  A hook in oa_appearance sets the colorizer context based on
the current space id.  Inheritance of parent colors is supported.


Banners
=======

This submodule adds the oa_banner, oa_banner_position, and oa_banner_text fields
to Spaces.  These fields are used to render the Space Banner (oa_space_banner)
Panels Pane.  This widget has Banner Position option to determine which banners
are displayed:  banners above the toolbar, or banners below the toolbar.
Typically this widget is added to the OA Header mini panel to display the site
banners above the toolbar.  The oa_radix template.php theme function renders
this widget for the "below the toolbar" option and adds it to the content page
below the header.

Site banner fields are added via simple system variables via the
oa_appearance_oa_settings_form().  This allows modules to add
fields to the Open Atrium -> Plugin Settings form.  The following variables are
added:

- **Show main menu** (oa_mainmenu)
  Display the main menu in the oa_space_banner widget.

- **Show Site banner next to main menu** (oa_menu_banner)
  Displays the site image to the left of the main menu.  Only works for
  non-stretched site banner images and when Show Main Menu is enabled.

- **Replace Breadcrumb** (oa_breadcrumb_menu)
  Replace Breadcrumb toolbar with main menu (in oa_toolbar submodule)

- **Site banner image** (oa_site_banner_file)
  The image file used for the site banner

- **Banner Position** (oa_site_banner_position)
  Hidden/Above Toolbar/Below Toolbar.  Determines which oa_space_banner widget
  the banner appears in.

- **Stretch Banner** (oa_banner_stretch)
  If enabled, the banner will use the full width of the page.

- **Use Default Banner** (oa_banner_default)
  If enabled, the predefined Open Atrium logo will be used for the site banner.

- **Show site name** (oa_banner_sitename)
  If enabled, the Site Name from admin/config/system/site-information will be
  shown over the banner on the left.

- **Show site slogan** (oa_banner_siteslogan)
  If enabled, the Site Slogan from admin/config/system/site-information will be
  shown over the banner on the right.

Comments on Banners:

- Two banner positions are available: Above Toolbar and Below Toolbar.  If a Space
  banner is enabled in the same position as the site banner, the Space banner will
  be shown instead.  If the Site and Space banners use different positions, both
  will be shown.

- Supports full-width (stretched) banner images, or fixed-size "logo" images.
  When placed next to the main menu, the logo image will be scaled down to fit
  with the menu.  When used full-width the banner will be scaled up to the full
  browser width.  It is up to the user to upload image with proper resolution and
  aspect ratio for where they will be displayed.

- Banners are inherited from parent Spaces.

Javascript Details
------------------

Javascript is used to control the top-padding of the body element based on the
height of the banners.  The problem is that the stretched banner height is not
computed in the browser till after the page loads.  So the space for the banner
cannot be properly reserved in advance.  The NavBar module provides a
Drupal.displace function that automatically updates the top-padding on the body,
but if NavBar is disabled or the user does not have Admin permission the body
top-padding is set directly.  The original image size is passed via the
data-width and data-height properties on the oa-banner element.  Some CSS is
used to fade the banner in as it is resized.
