Plugin App to provide Event and Calendar functionality.

This plugin integrates several Drupal modules, along with a custom content type
to provide Event and Calendar management with full geo-location support.

Calendars
=========

The FullCalendar module is used to provide the main calendar view of the custom
Event content type.  The Date module provides the Start and End datetime fields
for the event that are linked to the calendar display.  FullCalendar was
chosen over the typical Calendar module because it provides a more-modern
Google Calendar look and feel, allowing events to be drag/dropped to different
days and times, and switching between monthly, daily, weekly views without
refreshing the entire page.

The FullCalendar_Create sandbox project has been copied into Open Atrium as a
submodule of oa_event.  This adds the ability to click on a calendar day to
display a popup form to create a new event.

TODO: Currently the FullCalendar_Create popup does not use the custom Panelizer
layout for the node edit/add form and instead uses the default Drupal edit/add
form.

Color Coding
------------

The Colors module provides color coding for FullCalendar based on a variety
of conditions, including taxonomy terms and/or Organic Groups.  A Legend widget
is available to show the colors on the calendar page.

TODO: The Legend widget currently displays the full list of groups or taxonomy
terms and should be modified to only show the colors currently being used on
the calendar.  Options should be added for Sections and for only displaying
subspaces of the current space rather than all spaces on the site.

Event Locations
===============

Event Location is provided via the Geofield and GeoCoder modules.  A multiline
text field is used for the free-format location text.  This text is geocoded
and the resulting coordinates are stored in the Geofield.  By default Google
is used for the Geocoding service, which has limits around the number of
conversions per day from a given site.  On client sites which use event locations
extensively, an alternate geocoder is recommended.

TODO: A newer version of the GeoCoder module provides client-site conversion
and should be investigated.

A BREAK line in the location text field can be used to separate the data being
geocoded from other location data to be displayed.  For example, a virtual
webinar link can be added after the BREAK to provide a virtual location that
will not interfere with the geocoding of the physical location given before the
BREAK.  The BREAK uses the same button in the WYSIWYG editor as in the normal
Drupal body field to separate the summary.

Repeating Events
================

By default, the normal Date module is used for repeating events.  This creates
a single Drupal node for all of the events in the series.  For some use-cases
the client requires a unique node for each occurence of the event to allow
distinct meeting agendas or notes to be attached.  The [OA Date Repeat](https://github.com/phase2/oa_date_repeat)
module is available to add that option to each event.

The date_all_day module is used to add an option for All Day events.

Content Types
=============

oa_event
--------

Used for the Event nodes. Additional fields are:

- **field_oa_address** - A multiline text field used to enter the location of
  an event.

- **field_oa_geo_location** - A hidden field containing the coordinates from
  geocoding the field_oa_address field.

- **field_oa_date** - The datetime information for the event.

The full node detail page is panelized to show a Google map of the location
in the sidebar.  A custom formatter is used to display the start date of the
event in a visual box (month/day).

A link to the [AddThisEvent](http://addthisevent.com/) is shown (Add to Calendar).  The
javascript for AddThisEvent is copied into the js/atemay.js and has been
modified to support https connections.

A variant of the node/edit form is used to control the column layout of
fields, with the field_oa_date in the sidebar.

Messages
========

oa_event_notification
---------------------

An event fired from the cron task when an event has a start datetime within the
next oa_events_reminder_interval seconds.  Note that cron needs to run often
enough to provide the desired notification granularity.  The elysia_cron module
can be used to run the oa_events_cron more often than other system tasks.

Variables
=========

- **oa_events_send_reminders** - true/false to send event reminder message notifications
- **oa_events_reminder_interval** - number of seconds before the event start time
  to send a notification (via cron)

Views
=====

Open Atrium Calendar (oa_fullcalendar)
--------------------------------------

Contains the monthly, weekly, and daily views used to display the FullCalendar.
Each view is available as a separate widget with filters for space and section.
An iCal Feed display is used to place an iCal Export button link at the bottom
of the main calendar.

Open Atrium Event List (oa_event_list)
--------------------------------------

Provides several view display widgets for various event listings:

- Upcoming Events - A list of the next upcoming future events (displayed as a table)
- Past Events - A list of more recently passed evetns
- Upcoming Events Small - Similar to Upcoming Events but intended for sidebars
  with more limited space (displayed as an HTML list)
- iCal Feed - Attached to Upcoming Events to provide an iCal export feed

Open Atrium Event Detail (oa_event_detail)
------------------------------------------

Provides the widget that displays the details about the event, such as the
location and date (using the custom date formatter).  This widget is placed at
the top of the node detail panelizer template.
