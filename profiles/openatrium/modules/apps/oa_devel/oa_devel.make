; Open Atrium Devel Makefile

api = 2
core = 7.x

; Devel
projects[devel][type] = module
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][branch] = 7.x-1.x
projects[devel][subdir] = contrib

; Coder
projects[coder][type] = module
projects[coder][version] = 2.0-beta2
projects[coder][subdir] = contrib

; Simpletest clone
projects[simpletest_clone][type] = module
projects[simpletest_clone][download][type] = git
projects[simpletest_clone][download][url] = http://git.drupal.org/project/simpletest_clone.git
projects[simpletest_clone][download][branch] = 7.x-1.x
projects[simpletest_clone][subdir] = contrib
projects[simpletest_clone][patch][1666560] = https://www.drupal.org/files/vars_refresh.patch

; Install profile test.
projects[installprofiletest][type] = module
projects[installprofiletest][version] = 1.x-dev
projects[installprofiletest][subdir] = contrib
