Date iCal

This module allows users to export iCal feeds using Views, and import iCal feeds
from other sites using Feeds. Any entity that contains a Date field can act as
the source of events for an iCal feed.

===============================================================================
INSTALLATION
===============================================================================
Date iCal has several required dependencies, and an optional one:
- The Views (version 3.5+), Entity API, Libraries API (version 2.0+), and Date
  modules are required.
- The iCalcreator library is required.
- PHP 5.3 is required for the iCalcreator library to properly handle timezones.
- The Feeds module is optional. It's needed only if you you wish to import iCal
  feeds from other sites.

To install the iCalcreator library, download it from the project's github:
http://github.com/iCalcreator/iCalcreator
Using either git clone or the "Download Zip" button, you'll find the file
iCalcreator.class.php inside. Copy that file to a folder in your Drupal site
named sites/all/libraries/iCalcreator.

Or, if you have drush, install iCalcreator by running this command from your
site's root directory:
drush make sites/all/modules/date_ical/date_ical.make --no-core

Then, clear the cache on your site by using either "drush cc all" or logging in
to your site and going to Configuration -> Development -> Performance and click
the "Clear all caches" button. This is necessary because libraries are cached,
and you may see confusing behavior from Date iCal if the iCalcreator library
gets cached at a bad time.

To confirm that iCalcreator is installed correctly, log in to your Drupal site
and navigate to the admin/reports/status page. If the row titled "Date iCal" is
green, Date iCal is ready to go. If it's red, the iCalcreator library is not
properly installed. If it's missing, you'll need to enable Date iCal.


===============================================================================
EXPORTING AN ICAL FEED USING Views
===============================================================================
There are two plugins that export iCal feeds. You can use either one, though
the iCal Fields plugin (described later) is a bit more versatile.

HOW TO EXPORT AN ICAL FEED USING THE iCal Entities PLUGIN

1.  Go to the Manage Display page for the content type you want to export in an
    iCal feed. On the "Default" tab, check the box for "iCal" in the section
    titled "Use custom display settings for the following view modes", then
    click Save.
2.  Click the new "iCal" tab that now appears in the upper-right corner of the
    Manage Display page for this content type.
3.  Set up the iCal view mode to contain whatever should be exported as the
    'Description' field for the iCal feed. You can trim the text to the desired
    size, include additional information from other fields, etc.
4.  Do this for each of the content types that you wish to include in your
    site's iCal feeds.
5.  Create a new View that displays the entities that you want to include in
    the iCal feed.
6.  Add a "Feed" display to the same View. Change the Format to "iCal Feed".
    When you click "Apply" from that dialog, you'll be given the option to name
    the calendar, which will appear in your users' calendar clients as the
    calendar's title.
7.  Change the Show setting to "iCal Entity".
8.  In the settings for iCal Entity, select the date field that should be used
    as the event date for the iCal feed. Make sure that you choose a field that
    is a part of every entity that your View displays. Otherwise, the entities
    which don't have that field will be left out of the iCal feed.
9.  You may optionally choose a field that will be used to populate the 
    Location property of events in your iCal feed. This field can be a text
    field, a Node Reference field, an Addressfield, or a Location field.
10. Give the Feed a path like 'calendar/%/export.ics', including a '/%/' for
    every contextual filter in the view.
11. Make sure the Pager options are set to "Display all items".
12. Add date filters or arguments that will constrain the view to the items you
    want to be included in the iCal feed.
13. Using the "Attach to:" setting in the Feed Settings panel, attach the feed
    to a another display in the same view (usually a Page display). Be aware,
    though, that the Feed will display exactly what its settings tell it to,
    regardless of how the Page display is set up. Thus, it's best to ensure
    that both displays are configured to include the same content.
14. Save the View.
15. Navigate to a page which displays the view (usually the Page display's
    "path" setting). You should see the iCal icon at the bottom of the view's
    output. Clicking on the icon will subscribe your calendar app to the iCal
    feed.
16. If you don't have a calendar app set up on your computer, or you want your
    users to download the ical feed rather than subscribe to it, you'll want to
    go back to the View settings page, click the Settings link next to
    "Format: iCal Feed", and check "Disable webcal://". Then save your View.
    This will make the iCal icon download a .ics file with the events, instead
    of loading the events directly into the user's calendar app.

HOW TO EXPORT AN ICAL FEED USING THE iCal Fields PLUGIN
1-6.These steps are the same as above.
7.  Add views fields for each piece of information that you want to populate
    your iCal feed with. A Date field is required, and fields that will act as
    the Title and Description of the events are reccomended. You can also
    include a Location field.
8.  Back in the FORMAT section, change the "Show" setting to 'iCal Fields'.
9.  In the settings for iCal Fields, choose which views fields you want to use
    for the Date, Title, Description, and Location.
10+ These steps are the same as above.


===============================================================================
IMPORTING AN ICAL FEED FROM ANOTHER SITE USING Feeds
===============================================================================
- Install the Feeds module, which is the framework upon which Date iCal's
  import functionality is built.
- Login to your Drupal site and navigate to the admin/structure/feeds page.
- Click the "Add importer" link, and give it a name and description.
- Clicking "Create" will bring you to the general Feeds importer settings page.
  This page displays some general information about making Feeds importers,
  which you should familiarize yourself with.
- In the left sidebar, you'll see "Basic settings", "Fetcher", "Parser", and
  "Processor". The Parser and Processor settings are what we're interested in.
- In the Parser section, click "change". This will bring up the Parser
  selection page, on which you should select the radio button for "iCal Parser"
  and then click Save.
- Now, under Processor, click the "Settings" link. Most of the time, you'll
  want to use the "Update existing nodes (slower than replacing them)" setting.
  Then select the Content type of the nodes you'd like to create from iCal
  events. You can leave the other settings as their defeaults, or change them
  as you need. Click Save.
- Now click the "Mapping" link at the bottom of the left sidebar. This page is
  where you'll define how iCal event properties get mapped into your nodes'
  fields. Expand the "Legend" for a detailed description of each source and
  target field. Sources are the attributes available in iCal event objects,
  and Targets are the fields in your nodes.
- Most of this setup is going to be dependant upon how your content type's
  fields are configured, but there are some universal requirements:
  1) You MUST map the "UID" source to the "GUID" target. Then, after clicking
     "Add", click the gear-shaped button that appears in the new table row,
     and check the "Unique" checkbox. Then click "Update", and then before
     you add any more mappings, click "Save" at the bottom of the page.
  2) It's a good idea to map the "Summary/Title" source to the "Title" target,
     and the "Description" source to whatever field is the "body" of the node.
  3) AS OF 2014/02/03 THERE IS A MAJOR BUG IN THE Feeds THAT LEAVES THE DATE
     VALUES ON ALL IMPORTED EVENTS BLACNK. YOU MUST UPDATE YOUR Feeds MODULE
     TO THE DEV RELEASE (https://drupal.org/node/927032) TO OVERCOME THIS BUG.
- Once you've completed all the mappings, click the "Save" button on the
  bottom left side of the page.
- Now you can import the iCal feed into nodes by going to the /import page of
  your site (e.g. http://www.exmaple.com/import). Click the link for the
  importer you just created, and enter the URL of the feed into the "URL"
  field. Click the "Import" button, and observe the progress.
- Once it's done, you should see a green message saying "Created X nodes." If
  you do, you've successfully set up your iCal importer. If you get some other
  message, you'll need to tweak the importer's settings.

Remember, you have to map the UID source to the GUID target, and make it
unique, or your imports won't work!

IMPORTANT NOTE:
If you're building a site that will be viewed by out-of-state users, and you
allow said users to set their own timezone, you'll want to set up your Date
fields to use the "Date's time zone" option. If you don't, then users who live
in a different timezone will be shown the times for your events in their local
timezone, rather than your events' timezone. This makes sense if your events
will be broadcast live to these out-of-state users, but if they need to travel
to your event, they may end up arriving at the wrong time.

===============================================================================
HOW TO FIX THE "not a valid timezone" ERROR
===============================================================================
If you are seeing a warning about invalid timezones when you import an iCal
feed, you'll need to implement hook_date_ical_import_timezone_alter() in a
custom module to fix it. To do so, either edit an existing custom module, or
make a new module and add this function to it:

<?php
/**
 * Implements hook_date_ical_import_timezone_alter().
 */
function <module>_date_ical_import_timezone_alter(&$tzid, $context) {
  if (!empty($tzid)) {
    // Do something to fix your invalid timezone.
    // For instance, if all your events take place in one timezone, find your
    // region's official TZID, and replace $tzid with it. Like this:
    // $tzid = 'America/Los_Angeles';
  }
}
?>

Replace <module> with the name of your module, change the code to do whatever
needs to be done to fix your timezones, and clear your Drupal cache.

===============================================================================
ADDITIONAL NOTES
===============================================================================
Date iCal only supports exporting iCal calendars by using Views.
To put an "Add to calendar" button on individual event nodes, try the
Add to Cal module (http://drupal.org/project/addtocal), or follow the
instructions created by the estimable nmc at:
http://nmc-codes.blogspot.ca/2012/11/creating-ical-feed-for-single-node-in.html

The Feeds Tamper module is useful for altering the data in imported iCal feeds.

Developers who wish to implement more powerful manipulation of event data can
read the date_ical.api.php file to learn about the various alter hooks that
date_ical exposes.

The libraries/windowsZones.json file, which Date iCal uses to map Windows-style
timezone names to real timezone IDs, is from Version24 of the Unicode CLDR:
http://cldr.unicode.org/.
