Open Atrium Work Tracker
========================

A Work Tracker for Open Atrium 2.0 (similar to the Case tracker in Open Atrium
1.0) which allows you to create Tasks in order to collaborate on work.

Work Tracker is designed to fit seamlessly into the way Open Atrium 2.0 works
and it’s paradigm for flexibility. For example, Work Tracker has no concept of
"projects" - instead it groups Tasks together using Open Atrium Sections, which
allows users to define for themselves what a "project" is in a way that best
fits their organization.

Suggestions, bug reports and patches are welcome in the issue queue:

  https://drupal.org/project/issues/1972842?categories=All

Quick start
-----------

 * Install OpenAtrium 2.0 (version 2.0-rc1 and later install Work Tracker by
   default!)

 * Create a new Space
 
 * Create a new Section inside that space, and select "Tasks Section" under
   "Section Type" (it's below the body and "Weight" fields).

 * Using the add button in the header (looks like a '+' sign), create a new
   Task!

See the complete online documentation for more information:

  https://drupal.org/node/2112407

Extensions
----------

Additional features can be added to the Work Tracker by enabling extension
modules:

 * Work Tracker Open Atrium - Due Date: Adds a "Due date" field to Tasks.
   (Included with Work Tracker!)

See the complete "Extending Work Tracker" guide to learn how to create your own
extension:

  https://drupal.org/node/2112431

Optionally works with...
------------------------

 * AJAX Comments: https://drupal.org/project/ajax_comments

   Allows submitting a comment without reloading the page.

Dependencies
------------

If you want to install outside of Open Atrium, you'll need to install this
modules dependencies as well:

 * OpenAtrium 2.0: https://drupal.org/project/openatrium

 * Options Element: https://drupal.org/project/options_element

 * Comment Alter: https://drupal.org/project/comment_alter

As a shortcut, you can use "drush make" and the oa_worktracker.make file to
automatically install the required dependencies:

  drush make --no-core oa_worktracker.make

If you have any problems...
---------------------------

... first try reverting the feature.

You can do this in the admin UI by clicking Structure -> Features -> Open Atrium
-> Open Atrium Work Tracker selecting all the checkboxes and clicking the
"Revert components" button.

Or you can use drush:

  drush features-revert oa_worktracker --yes

