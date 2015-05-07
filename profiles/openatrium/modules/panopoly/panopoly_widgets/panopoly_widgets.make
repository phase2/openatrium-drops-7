; Panopoly Widgets Makefile

api = 2
core = 7.x

; Panopoly - Contrib - Fields

projects[tablefield][version] = 2.3
projects[tablefield][subdir] = contrib

projects[simple_gmap][version] = 1.2
projects[simple_gmap][subdir] = contrib

; Panopoly - Contrib - Widgets

projects[menu_block][version] = 2.4
projects[menu_block][subdir] = contrib
projects[menu_block][patch][2418803] = https://www.drupal.org/files/issues/menu_block-ctools-1.6-2418803-2.patch

; Panopoly - Contrib - Files & Media

projects[file_entity][version] = 2.0-beta1
projects[file_entity][subdir] = contrib
projects[file_entity][patch][2360043] = https://www.drupal.org/files/issues/file_entity-destination-token-decode-2360043-1.patch
projects[file_entity][patch][2386015] = https://www.drupal.org/files/issues/2386015-file_entity-trigger-1.patch

projects[media][version] = 2.x-dev
projects[media][subdir] = contrib
projects[media][download][type] = git
projects[media][download][revision] = 6382429
projects[media][download][branch] = 7.x-2.x
projects[media][patch][2192981] = http://drupal.org/files/issues/media-restore-edit-button-2192981-13.patch
projects[media][patch][2126697] = http://drupal.org/files/issues/media-wysiwyg-alt-title-handling-2126697-27.patch
projects[media][patch][2308487] = http://drupal.org/files/issues/media-alt-title-double-encoded-2308487-1.patch
projects[media][patch][2084287] = http://www.drupal.org/files/issues/media-file-name-focus-2084287-2.patch
projects[media][patch][2421589] = http://www.drupal.org/files/issues/media-library-preview-overflow-2421589-2.patch
projects[media][patch][951004] = https://www.drupal.org/files/issues/allow_selecting_of-951004-136.patch
projects[media][patch][2473481] = http://drupal.org/files/issues/clicking_images_in-2473481-1.patch

projects[media_youtube][version] = 2.x-dev
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = d0377b3
projects[media_youtube][download][branch] = 7.x-2.x

projects[media_vimeo][version] = 2.0
projects[media_vimeo][subdir] = contrib
projects[media_vimeo][patch][2446199] = https://www.drupal.org/files/issues/no_exception_handling-2446199-1.patch
