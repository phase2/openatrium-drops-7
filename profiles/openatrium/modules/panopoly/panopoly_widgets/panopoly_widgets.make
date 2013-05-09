; Panopoly Widgets Makefile

api = 2
core = 7.x

; Panopoly - Contrib - Fields

projects[tablefield][version] = 2.1
projects[tablefield][subdir] = contrib

projects[simple_gmap][version] = 1.0
projects[simple_gmap][subdir] = contrib

; Panopoly - Contrib - Widgets

projects[menu_block][version] = 2.3
projects[menu_block][subdir] = contrib

; Panopoly - Contrib - Files & Media

projects[file_entity][version] = 2.x-dev
projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = git
projects[file_entity][download][revision] = c2d5c3d
projects[file_entity][download][branch] = 7.x-2.x

projects[media][version] = 2.x-dev
projects[media][subdir] = contrib
projects[media][download][type] = git
projects[media][download][revision] = ecb9392
projects[media][download][branch] = 7.x-2.x
projects[media][patch][1319528] = http://drupal.org/files/media-browser-enter-submit-frontpage-1319528-11.patch

projects[media_youtube][version] = 2.x-dev
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = 5418cbe
projects[media_youtube][download][branch] = 7.x-2.x

projects[media_vimeo][version] = 2.x-dev
projects[media_vimeo][subdir] = contrib
projects[media_vimeo][download][type] = git
projects[media_vimeo][download][revision] = 204cc5f
projects[media_vimeo][download][branch] = 7.x-2.x
