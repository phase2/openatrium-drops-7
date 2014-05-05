Import From DB
==============

This is not a module.  It is a helper file to be added to your Drupal install
profile that will add an option to import your site from an existing database
dump.

Installation
------------

1) Extract the files in this repo to the "install_from_db" folder within your
ROOT/profiles/profile-name directory.

2) Add an include statement to your profile-name.profile file like this:

include_once 'install_from_db/install_from_db.profile';

3) Implement the hook_install_tasks_alter() and call the
install_from_db_install_tasks_alter() function like this:

/**
 * Implements hook_install_tasks_alter()
 */
function profile-name_install_tasks_alter(&$tasks, $install_state) {
  install_from_db_install_tasks_alter($tasks, $install_state);
}

4) Use mysqldump (or drush sql-dump) to create a dump of the database you
wish to import.  Typically this is created from a normal clean install of
the profile you want to clone.

5) Place the mysql dump into the ROOT/profiles/profile-name/db directory with
the filename: profile-name.sql  (replace "profile-name" with the actual
name of your profile)
