; Open Atrium Events Makefile

api = 2
core = 7.x

; Full Calendar
projects[fullcalendar][version] = 2.x-dev
projects[fullcalendar][subdir] = contrib
projects[fullcalendar][download][type] = git
projects[fullcalendar][download][branch] = 7.x-2.x
projects[fullcalendar][download][revision] = e416e7
projects[fullcalendar][patch][2044391] = http://drupal.org/files/fullcalendar-legend-entityreference_taxonomy-2044391-1.patch

libraries[fullcalendar][download][type] = get
libraries[fullcalendar][download][url] = http://arshaw.com/fullcalendar/downloads/fullcalendar-1.6.4.zip
libraries[fullcalendar][directory_name] = fullcalendar
libraries[fullcalendar][destination] = libraries
libraries[fullcalendar][download][subtree] = fullcalendar-1.6.4/fullcalendar

; Colors
projects[colors][version] = 1.0-rc1
projects[colors][subdir] = contrib
projects[colors][patch][1814972] = http://drupal.org/files/og-7.x-2.x_0.patch
projects[colors][patch][2044395] = http://drupal.org/files/colors-entityreference_taxonomy-2044395-1.patch

; Date ICal
projects[date_ical][version] = 3.x-dev
projects[date_ical][subdir] = contrib
projects[date_ical][download][type] = git
projects[date_ical][download][branch] = 7.x-3.x
projects[date_ical][download][revision] = 7afb13
projects[date_ical][patch][2206109] = http://drupal.org/files/issues/date_ical-irule-array-2206109-6.patch

; GeoPHP
projects[geophp][version] = 1.7
projects[geophp][subdir] = contrib

; GeoField
projects[geofield][version] = 2.1
projects[geofield][subdir] = contrib

; GeoCoder
projects[geocoder][version] = 1.x-dev
projects[geocoder][subdir] = contrib
projects[geocoder][download][type] = git
projects[geocoder][download][branch] = 7.x-1.x
projects[geocoder][download][revision] = c1a79d

