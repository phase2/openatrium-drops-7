; Open Atrium Radix theme Makefile

api = 2
core = 7.x

; Parent Theme Radix
projects[radix][type] = theme
projects[radix][version] = 3.x-dev
projects[radix][download][type] = git
projects[radix][download][branch] = 7.x-3.x
projects[radix][download][revision] = 38eb2d99
projects[radix][patch][2339395] = http://www.drupal.org/files/issues/radix-checkbox-labels-2339395-5.patch
projects[radix][patch][2194335] = http://www.drupal.org/files/issues/radix-screen-css-2194335-13_0.patch
projects[radix][patch][2426513] = https://www.drupal.org/files/issues/radix-hash-usage-throwing-errors-2426513-11.patch
projects[radix][patch][2568163] = https://www.drupal.org/files/issues/radix_form_element_label_after-2568163-2.patch

; Bootstrap Library
projects[bootstrap_library][version] = 1.4
projects[bootstrap_library][subdir] = contrib

libraries[bootstrap][download][type] = get
libraries[bootstrap][download][url] = https://github.com/twbs/bootstrap/releases/download/v3.1.1/bootstrap-3.1.1-dist.zip
libraries[bootstrap][directory_name] = bootstrap
