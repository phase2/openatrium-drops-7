; Open Atrium Events Makefile

api = 2
core = 7.x

projects[calendar][type] = module
projects[calendar][subdir] = contrib
projects[calendar][download][url] = http://git.drupal.org/project/calendar.git
projects[calendar][download][type] = git
projects[calendar][download][version] = 3.4
projects[calendar][download][branch] = 7.x-3.x
projects[calendar][patch][1214940] = http://drupal.org/files/1214940-remove-resizeViewport.patch
projects[calendar][patch][1995062] = http://drupal.org/files/1995062-no-weekno-in-weekly_0.patch

projects[date_ical][type] = module
projects[date_ical][subdir] = contrib
projects[date_ical][version][branch] = 2.7
projects[date_ical][download][url] = http://git.drupal.org/project/date_ical.git
projects[date_ical][download][type] = git
projects[date_ical][download][branch] = 7.x-2.x

projects[geophp][type] = module
projects[geophp][subdir] = contrib
projects[geophp][download][version] = 1.7

projects[geofield][type] = module
projects[geofield][subdir] = contrib
projects[geofield][download][version] = 1.1

projects[geocoder][type] = module
projects[geocoder][subdir] = contrib
projects[geocoder][download][type] = git
projects[geocoder][download][url] = http://git.drupal.org/project/geocoder.git
projects[geocoder][download][branch] = 7.x-1.x
projects[geocoder][download][revision] = f6b34bc
projects[geocoder][patch][1996592] = http://drupal.org/files/1996592-geocoder_geocode_values.patch

