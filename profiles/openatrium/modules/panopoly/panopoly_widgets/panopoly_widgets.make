; Panopoly Widgets Makefile

api = 2
core = 7.x

; Panopoly - Contrib - Fields

projects[tablefield][version] = 2.2
projects[tablefield][subdir] = contrib
projects[tablefield][patch][2050657] = "http://drupal.org/files/tablefield_event_click_conflict.patch"

projects[simple_gmap][version] = 1.2
projects[simple_gmap][subdir] = contrib

; Panopoly - Contrib - Widgets

projects[menu_block][version] = 2.3
projects[menu_block][subdir] = contrib

; Panopoly - Contrib - Files & Media

projects[file_entity][version] = 2.0-alpha3
projects[file_entity][subdir] = contrib

projects[media][version] = 2.x-dev
projects[media][subdir] = contrib
projects[media][download][type] = git
projects[media][download][revision] = 4a88319
projects[media][download][branch] = 7.x-2.x

projects[media_youtube][version] = 2.0-rc4
projects[media_youtube][subdir] = contrib

projects[media_vimeo][version] = 2.0-rc1
projects[media_vimeo][subdir] = contrib
