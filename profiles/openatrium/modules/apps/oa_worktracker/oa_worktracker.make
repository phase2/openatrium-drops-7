; Open Atrium Work Tracker Makefile

api = 2
core = 7.x

; Comment Alter
projects[comment_alter][version] = 1.x-dev
projects[comment_alter][subdir] = contrib
projects[comment_alter][download][type] = git
projects[comment_alter][download][branch] = 7.x-1.x
projects[comment_alter][download][revision] = a25dfa0
projects[comment_alter][patch][2540782] = https://www.drupal.org/files/issues/comment_alter_overwrites_fields-2540782-1.patch

; Options Element
projects[options_element][version] = 1.12
projects[options_element][subdir] = contrib
