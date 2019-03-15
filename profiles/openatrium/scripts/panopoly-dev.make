api = 2
core = 7.x

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush 5 concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.
; NOTE: If you are running Drush 6, this section should be placed at the TOP

projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][patch][2477347] = https://www.drupal.org/files/issues/2019-03-14/2477347-panopoly_core-views-12.patch
projects[panopoly_core][patch][2477363] = https://www.drupal.org/files/issues/2018-12-12/2477363-panopoly_core-ctools-28.patch
projects[panopoly_core][patch][2477369] = https://www.drupal.org/files/issues/2477369-panopoly_core-entity-7.patch
projects[panopoly_core][patch][2477375] = https://www.drupal.org/files/issues/2477375-panopoly_core-entityreference-9.patch
projects[panopoly_core][patch][2477379] = https://www.drupal.org/files/issues/2477379-panopoly_core-token-1.patch
projects[panopoly_core][patch][2592821] = https://www.drupal.org/files/issues/2018-12-12/2592821-panopoly_core-apps-5.patch

projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][branch] = 7.x-1.x

projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][branch] = 7.x-1.x
projects[panopoly_theme][patch][2656920] = https://www.drupal.org/files/issues/2656920-panopoly-theme-radix-layouts-4.patch

projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][branch] = 7.x-1.x

projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][branch] = 7.x-1.x
projects[panopoly_widgets][patch][2477397] = https://www.drupal.org/files/issues/2018-05-08/2477397-panopoly_widgets-file_entity-7.patch

projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][branch] = 7.x-1.x

projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][type] = git
projects[panopoly_users][download][branch] = 7.x-1.x

projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][branch] = 7.x-1.x

projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x

projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][branch] = 7.x-1.x

; ***************** End Panopoly *****************
; ************************************************
