Panels Everywhere
-----------------
Panels Everywhere is an advanced method to completely do away with Drupal's
restrictive blocks system and instead use the much more freeing Panels Layout
system to control how your pages look. Panels Everywhere modifies the page as
it is being rendered to 'wrap' the content in a display and can even take over
your page theme to do away with the need for a page.tpl.php.

Doing this requires that you set up a few things properly, because Drupal is
not really designed for this kind of behavior.


Getting Started
------------------------------------------------------------------------------
Panels Everywhere requires CTools and Panels be installed, the latest stable
releases of each should be used.

Step 1
------
First, back up your site database, just in case. This will make it easy to
completely revert if you decide that Panels Everywhere is not for you. It is
also recommended that you first experiment with this on a small test site so
that you can get a feel for the effects this will have. Sites are best built
from the ground up on Panels Everywhere. Converting an existing site may be
quite difficult.

Step 2
------
Enable Panels Everywhere. If not using UID 1, be sure the user you're using has
'administer page manager' privileges.

Navigate to Structure >> Panels >> Settings >> Everywhere.

Check the box to enable the site template. 

Check the box to enable the sample variant.

You may check the box to override the page template, but only if you either
enable the sample variant, or have already created a site template variant
to handle page duties.

If you're still experimenting with Panels Everywhere, you can also enable it on
a theme by theme basis, making it easy to switch back and forth.

Step 3
------
Navigate to Structure >> Pages and edit the site_template
(Default site template) page.

Edit your new variant. Customize it if you like. There are some very
important parts of this sample variant:

  o The "Page content" pane is absolutely critical. That is the pane that will
    hold the actual content of the page you are looking at. If this pane does
    not exist, *no content will be rendered*, only the page template. Think of
    this as being the $content variable in your page.tpl.php -- you need that
    and cannot live without it.

  o The "Title type" is set to "From pane" and the Page content pane is
    selected as the title. (That is why that pane has a thicker border). This
    is how the title of the content gets to be the title of the page.

  o The Navigation, Header and Messages panes are conveniences that group
    common page navigation together. For customized sites it is highly likely
    that you will theme these or do away with them and use the individual
    pieces.

Step 4
------
You might also consider creating a completely blank theme, because existing 
themes will have CSS that expects different markup. To create a blank theme:

1) mkdir sites/all/themes/blank
2) Create the following five lines in a file named blank.info:

name = Blank
description = Blank
core = 7.x
stylesheets[all][] = blank.css
engine = phptemplate

3) Visit Appearance and change your theme to the blank theme.

Step 5
------
You can add additional variants and easily section off your site by using the
selection rules. In particular, there are two selection rules you should be
interested in:

  o You can easily add a String: comparison selection rule and write regular
    expressions against the URL to use that.

  o You can use the Context exists selection rule using the "Managed page"
    context. By using this, you can force the site_template to not run on
    actual Page Manager pages and use the site_template only as a wrapper for
    non Page Manager content. If you do this, you need to make sure that your
    other pages contain all the navigation they need.


Extras
------------------------------------------------------------------------------
For best results, customized layouts are the way to go - they can include as
much or as little of the page template as you need, and are easily selectable.
When you customize a layout, if it will be heavily styled, it is recommended
that you provide a separate admin layout (in the layout.inc there are 
'admin theme' and 'admin css' settings) to provide a less styled layout for the
purposes of editing. This will be critical to keep the editing UI from getting
too messy.

The navigation, header and messages blocks can be easily customized by copying
the appropriate pane-*.tpl.php files from the themes directory to your theme,
changing them, and clearing cache. If you need to add additional variables,
look at the theme.inc file. You can create similar preprocess functions in your
template.php. The token function can accept any variable that would normally
appear in your page.tpl.php.

You can easily add more variants and use the regular expressions in the String:
comparison selection rules to change which display gets used based on the URL.
You can also use the "Context: exists" selection rule to provide default panels
only for content that is not already in a panel by checking to see if the
"Managed page" context exists.

If you have a lot of different site templates or pages that include their own
navigation, you can also consider using Mini Panels to create common navigation 
sidebars for easier maintenance.

If you don't want to create your own layouts, you can also check the Panels
Everywhere project page for an up to date list of themes working with Panels
Everywhere.


Contexts
------------------------------------------------------------------------------
Your site template will now attempt to find contexts from the environment as
best as it can. It handles all of the default Drupal locations, and if using a
Page Manager page it can do some inheritance.

Currently Panels Everywhere can find the following contexts:

  o url: The internal URL of the page.
  
  o alias: The alias of the page. Most of the time this is the URL actually
    visited, but beware that if the page has multiple aliases, it will be the
    *first* alias Drupal finds. i.e, if foo has aliases of 'bar' and 'baz',
    when visiting 'bar' or 'baz' the alias will always appear as 'bar' because
    it comes first in the list.

  o user: The logged in user.

  o node: The node being viewed. If visiting node/% or if visiting a page 
    manager page that contains a node context, that node will be used. If the
    page manager page has multiple node contexts (due to relationships or
    multiple nid arguments) only the first node will appear in context.

  o account: A user context for the user being viewed. Will appear on profile
    pages and on any page manager page with a user context (not counting the
    logged in user).

  o term: The taxonomy term being viewed if on a taxonomy term page. This 
    won't work if viewing multiple terms (i.e, taxonomy/term/1,2) unless using
    a page manager page that derives a single term context.

In addition, before this is actually utilized you can use:
  hook_panels_everywhere_contexts_alter(&$contexts, $placeholders)

If you add contexts, use this function:
  panels_everywhere_site_template_add_context($contexts, $context, t('Human readable identifier'), 'keyword', 'internalid');

If $placeholders is TRUE, create your context using 
ctools_context_create_empty('type'); if $placeholders is FALSE, create your
context using ctools_context_create('type', $object). If no object exists,
create it as an empty context. It is important that an empty context appears
even if there is not an object to keep the UI consistent.


Making Panels Everywhere -aware themes
------------------------------------------------------------------------------
To make a theme PE aware, all that really matters is to provide a default site
template that matches what the theme's page.tpl.php should be. To do this, 
create a site template in your site. Export the handler via the bulk export 
mechanism. Edit your .info file to contain these lines:

; We provide default page manager pages for our site template.
api[page_manager][pages_default][version] = 1
api[page_manager][pages_default][path] = pages

The bulk export will give you a .pages_default.inc file -- just place that in 
the 'pages' directory. Your new site template should be immediately available.

It's a very good idea to add a 'selection criteria' so that this template will
only activate when your theme is the active theme.

You can also give your theme a hybrid mode where it will be smart and use its
normal page.tpl.php if the site_template is not in use, and use a stripped
down page.tpl.php if it is. Place the following code in your theme (chances
are you already have a preprocess page).

  function MYTHEME_preprocess_page(&$vars) {
    if (!empty($vars['panels_everywhere_site_template'])) {
      $vars['template_file'] = 'page-panels-everywhere';
    }
  }

Then copy panels_everywhere/theme/page.tpl.php to 
page-panels-everywhere.tpl.php in your theme. Once this is done, your theme
will play nice with Panels Everywhere even if the option to take over the page
template is not enabled.

There is rather a lot of information available via this variable if you like.
The actual template used will be in:
  $vars['panels_everywhere_site_template']['handler']
and the contexts will be in:
  $vars['panels_everywhere_site_template']['contexts']

Panels Everywhere modifies the global themes list in order to do its magic. If
the original theme list data is needed it may be obtained from
panels_everywhere_get_list_themes_copy().


Tips & Tricks
------------------------------------------------------------------------------
It is recommended to only enable Panels Everywhere for the theme used for the
public site and to not enable it for the admin theme.

Ensure that the "Page content" pane is added to every PE variant before saving
creation of a PE variant, this will help avoid locking out the admin from being
able to do anything.


Troubleshooting
------------------------------------------------------------------------------
The "Page content" pane must be added to the page, otherwise it's possible to
"lock out" the admin - if there's no way to see the admin settings thre's no
way to disable the module. If the site happens to be "locked out", the following
steps may help:
  * Delete the 'panels_everywhere_site_template_enabled' variable from the
    database' {variable} table or via Drush:
      drush vdel -y panels_everywhere_site_template_enabled
  * Load up the Panels Everywhere settings page:
      admin/structure/panels/settings/everywhere
  * Limit PE to only the theme used for visitors, do not enable it for the
    site's admin theme.
  * Save the settings.
  * Go to the Panels Everywhere section of the Page Manager admin:
      admin/structure/pages/edit/site_template
  * Go to the "Content" section of the new variant.
  * Add the "Page content" pane to the page.
  * Update and save the variant.


Credits / Contact
------------------------------------------------------------------------------
Currently maintained by Damien McKenna [1]. Originally written by Earl Miles
[2] with many contributions by Claes Gyllensvärd [3].

Ongoing development is sponsored by Mediacurrent [4]. All initial development
was sponsored by IO1 [5].

The best way to contact the authors is to submit an issue, be it a support
request, a feature request or a bug report, in the project issue queue:
  http://drupal.org/project/issues/panels_everywhere


References
------------------------------------------------------------------------------
1: https://drupal.org/user/108450
2: https://drupal.org/user/26979
3: https://drupal.org/user/373603
4: http://www.mediacurrent.com/
5: http://www.io1.biz/
