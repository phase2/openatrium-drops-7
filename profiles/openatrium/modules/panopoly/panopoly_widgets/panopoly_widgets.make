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

projects[menu_block][version] = 2.4
projects[menu_block][subdir] = contrib

; Panopoly - Contrib - Files & Media

projects[file_entity][version] = 2.x-dev
projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = git
projects[file_entity][download][revision] = 07411c4
projects[file_entity][download][branch] = 7.x-2.x

projects[media][version] = 2.x-dev
projects[media][subdir] = contrib
projects[media][download][type] = git
projects[media][download][revision] = 1f46a9a
projects[media][download][branch] = 7.x-2.x
projects[media][patch][2126755] = http://drupal.org/files/issues/media-improved-macro-handling-2126755-19.patch

projects[media_youtube][version] = 2.x-dev
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = d0377b3
projects[media_youtube][download][branch] = 7.x-2.x

projects[media_vimeo][version] = 2.0-rc1
projects[media_vimeo][subdir] = contrib
