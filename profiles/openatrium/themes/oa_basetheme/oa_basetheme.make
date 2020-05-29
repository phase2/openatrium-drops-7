; Open Atrium Basetheme theme Makefile

api = 2
core = 7.x

; Bootstrap Library
projects[bootstrap_library][version] = 1.4
projects[bootstrap_library][subdir] = contrib
projects[bootstrap_library][patch][2244553] = https://www.drupal.org/files/issues/bootstrap_library-jquery_version_check-2244553-8.patch

libraries[bootstrap][download][type] = get
libraries[bootstrap][download][url] = https://github.com/twbs/bootstrap/releases/download/v3.4.1/bootstrap-3.4.1-dist.zip
libraries[bootstrap][directory_name] = bootstrap
