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

; Radix Layouts
projects[radix_layouts][version] = 3.3
projects[radix_layouts][subdir] = contrib

; Bootstrap Library
projects[bootstrap_library][version] = 1.4
projects[bootstrap_library][subdir] = contrib

libraries[bootstrap][download][type] = get
libraries[bootstrap][download][url] = https://github.com/twbs/bootstrap/releases/download/v3.1.1/bootstrap-3.1.1-dist.zip
libraries[bootstrap][directory_name] = bootstrap
