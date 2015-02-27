api = 2
core = 7.x

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush 5 concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.
; NOTE: If you are running Drush 6, this section should be placed at the TOP

projects[panopoly_core][version] = 1.18
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][patch][2426337] = https://www.drupal.org/files/issues/2426337-panopoly_core-panelizer-1.patch

projects[panopoly_images][version] = 1.18
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.18
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.18
projects[panopoly_magic][subdir] = panopoly

projects[panopoly_widgets][version] = 1.18
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.18
projects[panopoly_admin][subdir] = panopoly

projects[panopoly_users][version] = 1.18
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.18
projects[panopoly_pages][subdir] = panopoly

projects[panopoly_wysiwyg][version] = 1.18
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.18
projects[panopoly_search][subdir] = panopoly

; ***************** End Panopoly *****************
; ************************************************
