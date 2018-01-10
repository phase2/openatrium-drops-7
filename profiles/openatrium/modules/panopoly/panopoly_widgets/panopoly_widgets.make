; Panopoly Widgets Makefile

api = 2
core = 7.x

; Panopoly - Contrib - Fields

projects[tablefield][version] = 2.4
projects[tablefield][subdir] = contrib

projects[simple_gmap][version] = 1.2
projects[simple_gmap][subdir] = contrib

; Panopoly - Contrib - Widgets

projects[menu_block][version] = 2.7
projects[menu_block][subdir] = contrib

; Panopoly - Contrib - Files & Media

projects[file_entity][version] = 2.15
projects[file_entity][subdir] = contrib
projects[file_entity][patch][2360043] = https://www.drupal.org/files/issues/file_entity-destination-token-decode-2360043-1.patch
projects[file_entity][patch][2386015] = https://www.drupal.org/files/issues/2386015-file_entity-trigger-1.patch
projects[file_entity][patch][2067671] = https://www.drupal.org/files/issues/file_entity-REVERT_2067671-EntityFieldQuery-altering-35.patch
 

projects[media][version] = 2.13
projects[media][subdir] = contrib
projects[media][patch][2372907] = https://www.drupal.org/files/issues/media-replace-fake-button-2372907-2.patch
projects[media][patch][2473481] = https://www.drupal.org/files/issues/clicking_images_in-2473481-1.patch
projects[media][patch][2528428] = https://www.drupal.org/files/issues/media_browser_view_javascript_not_loaded-2528428-4.patch

projects[media_youtube][version] = 3.0
projects[media_youtube][subdir] = contrib

projects[media_vimeo][version] = 2.1
projects[media_vimeo][subdir] = contrib
projects[media_vimeo][patch][2446199] = https://www.drupal.org/files/issues/no_exception_handling-2446199-1.patch
