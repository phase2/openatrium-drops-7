; Panopoly Widgets Makefile

api = 2
core = 7.x

; Panopoly - Contrib - Fields

projects[tablefield][version] = 3.5
projects[tablefield][subdir] = contrib

projects[simple_gmap][version] = 1.4
projects[simple_gmap][subdir] = contrib
projects[simple_gmap][patch][2902178] = https://www.drupal.org/files/issues/simple_gmap-iframe-title-2902178-15.patch

; Panopoly - Contrib - Widgets

projects[menu_block][version] = 2.8
projects[menu_block][subdir] = contrib

; Panopoly - Contrib - Files & Media

projects[file_entity][version] = 2.25
projects[file_entity][subdir] = contrib
projects[file_entity][patch][2360043] = https://www.drupal.org/files/issues/file_entity-destination-token-decode-2360043-1.patch

projects[media][version] = 2.21
projects[media][subdir] = contrib

projects[media_youtube][version] = 3.7
projects[media_youtube][subdir] = contrib

projects[media_vimeo][version] = 2.1
projects[media_vimeo][subdir] = contrib
projects[media_vimeo][patch][2446199] = https://www.drupal.org/files/issues/no_exception_handling-2446199-1.patch
projects[media_vimeo][patch][2913855] = https://www.drupal.org/files/issues/media_vimeo_https-2913855-3.patch
