; Open Atrium Mailhandler Makefile

api = 2
core = 7.x

projects[mailhandler][version] = 2.11
projects[mailhandler][subdir] = contrib
projects[mailhandler][patch][2931124] = https://www.drupal.org/files/issues/2931124-remove-make-2.patch


projects[mailcomment][version] = 2.x-dev
projects[mailcomment][subdir] = contrib
projects[mailcomment][download][type] = git
projects[mailcomment][download][branch] = 7.x-2.x
projects[mailcomment][download][revision] = 2a7b52

projects[feeds_comment_processor][version] = 1.0
projects[feeds_comment_processor][subdir] = contrib

