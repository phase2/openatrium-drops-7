api = 2
core = 7.x

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush 5 concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.
; NOTE: If you are running Drush 6, this section should be placed at the TOP

projects[panopoly_core][version] = 1.21
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][patch][2426337] = https://www.drupal.org/files/issues/2426337-panopoly_core-panelizer-1.patch
projects[panopoly_core][patch][2466935] = https://www.drupal.org/files/issues/2466935-panopoly_core-update_apps-1.patch
projects[panopoly_core][patch][2477347] = https://www.drupal.org/files/issues/2477347-panopoly_core-views-2.patch
projects[panopoly_core][patch][2477363] = https://www.drupal.org/files/issues/2477363-panopoly_core-ctools-4.patch
projects[panopoly_core][patch][2477369] = https://www.drupal.org/files/issues/2477369-panopoly_core-entity-1.patch
projects[panopoly_core][patch][2477375] = https://www.drupal.org/files/issues/2477375-panopoly_core-entityreference-1.patch
projects[panopoly_core][patch][2477379] = https://www.drupal.org/files/issues/2477379-panopoly_core-token-1.patch
projects[panopoly_core][patch][2477391] = https://www.drupal.org/files/issues/2477391-panopoly_core-features-2.patch

projects[panopoly_images][version] = 1.21
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.21
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.21
projects[panopoly_magic][subdir] = panopoly

projects[panopoly_widgets][version] = 1.21
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][patch][2473495] = https://www.drupal.org/files/issues/clicking_images_in_my-2473495-3.patch
projects[panopoly_widgets][patch][2477397] = https://www.drupal.org/files/issues/2477397-panopoly_widgets-file_entity-1.patch

projects[panopoly_admin][version] = 1.21
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][patch][2449855] = https://www.drupal.org/files/issues/2449855-panopoly_admin-breakpoints-1.patch
projects[panopoly_admin][patch][2235081] = https://www.drupal.org/files/issues/2235081-panopoly_admin-jquery_update-10.patch

projects[panopoly_users][version] = 1.21
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.21
projects[panopoly_pages][subdir] = panopoly

projects[panopoly_wysiwyg][version] = 1.21
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.21
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][patch][2469005] = https://www.drupal.org/files/issues/2469005-panopoly_search-search_api-1.patch

; ***************** End Panopoly *****************
; ************************************************
