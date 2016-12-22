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
projects[fullcalendar][patch][2333883] = http://drupal.org/files/issues/fullcalendar-update-fullcalendar-download-url-2333883-1.patch

; Full Calendar Create
projects[fullcalendar_create][version] = 1.0-alpha1
projects[fullcalendar_create][subdir] = contrib

libraries[fullcalendar][download][type] = get
libraries[fullcalendar][download][url] = https://github.com/arshaw/fullcalendar/releases/download/v1.6.4/fullcalendar-1.6.4.zip
libraries[fullcalendar][directory_name] = fullcalendar
libraries[fullcalendar][destination] = libraries
libraries[fullcalendar][download][subtree] = fullcalendar-1.6.4/fullcalendar

; Colors
projects[colors][version] = 1.0-rc1
projects[colors][subdir] = contrib
projects[colors][patch][1814972] = http://drupal.org/files/og-7.x-2.x_0.patch
projects[colors][patch][2044395] = http://drupal.org/files/colors-entityreference_taxonomy-2044395-1.patch

; Date ICal
projects[date_ical][version] = 3.9
projects[date_ical][subdir] = contrib

; GeoPHP
projects[geophp][version] = 1.7
projects[geophp][subdir] = contrib
projects[geophp][patch][2144775] = https://www.drupal.org/files/issues/absolute-path_0.patch

; GeoField
projects[geofield][version] = 2.3
projects[geofield][subdir] = contrib
projects[geofield][patch][2757953] = https://www.drupal.org/files/issues/geofield-google-api-key-2757953-42.patch

; GeoCoder
projects[geocoder][version] = 1.x-dev
projects[geocoder][subdir] = contrib
projects[geocoder][download][type] = git
projects[geocoder][download][branch] = 7.x-1.x
projects[geocoder][download][revision] = c1a79d

