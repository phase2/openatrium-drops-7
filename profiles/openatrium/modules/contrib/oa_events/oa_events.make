; Open Atrium Events Makefile

api = 2
core = 7.x

projects[fullcalendar][type] = module
projects[fullcalendar][subdir] = contrib
projects[fullcalendar][download][url] = http://git.drupal.org/project/fullcalendar.git
projects[fullcalendar][download][type] = git
projects[fullcalendar][version] = 2.0
projects[fullcalendar][download][branch] = 7.x-2.x
projects[fullcalendar][patch][2044391] = http://drupal.org/files/fullcalendar-legend-entityreference_taxonomy-2044391-1.patch

projects[colors][type] = module
projects[colors][subdir] = contrib
projects[colors][download][url] = http://git.drupal.org/project/colors.git
projects[colors][download][type] = git
projects[colors][version] = 1.0-rc1
projects[colors][patch][1814972] = http://drupal.org/files/og-7.x-2.x_0.patch
projects[colors][patch][2044395] = http://drupal.org/files/colors-entityreference_taxonomy-2044395-1.patch
projects[colors][download][branch] = 7.x-1.x

projects[date_ical][type] = module
projects[date_ical][subdir] = contrib
projects[date_ical][download][url] = http://git.drupal.org/project/date_ical.git
projects[date_ical][download][type] = git
projects[date_ical][download][branch] = 7.x-2.x
projects[date_ical][download][revision] = 8da6542
projects[date_ical][patch][2038063] = http://drupal.org/files/date_ical-2038063-1.patch

projects[geophp][type] = module
projects[geophp][subdir] = contrib
projects[geophp][version] = 1.7

projects[geofield][type] = module
projects[geofield][subdir] = contrib
projects[geofield][version] = 1.2

projects[geocoder][type] = module
projects[geocoder][subdir] = contrib
projects[geocoder][download][type] = git
projects[geocoder][download][url] = http://git.drupal.org/project/geocoder.git
projects[geocoder][download][branch] = 7.x-1.x
projects[geocoder][download][revision] = f6b34bc
projects[geocoder][patch][1996592] = http://drupal.org/files/1996592-geocoder_geocode_values.patch

libraries[fullcalendar][download][type] = get
libraries[fullcalendar][download][url] = http://arshaw.com/fullcalendar/downloads/fullcalendar-1.6.1.zip
libraries[fullcalendar][directory_name] = fullcalendar
libraries[fullcalendar][destination] = libraries
libraries[fullcalendar][download][subtree] = fullcalendar-1.6.1/fullcalendar

