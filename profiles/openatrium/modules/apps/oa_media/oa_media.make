api = 2
core = 7.x

; Colorbox
projects[colorbox][version] = 2.10
projects[colorbox][subdir] = contrib

projects[media_colorbox][version] = 1.x-dev
projects[media_colorbox][subdir] = contrib
projects[media_colorbox][download][type] = git
projects[media_colorbox][download][branch] = 7.x-1.x
projects[media_colorbox][download][revision] = d01819
projects[media_colorbox][patch][2087565] = http://drupal.org/files/media_colorbox_private-file-permission-2087565-1.patch

projects[multiform][version] = 1.3
projects[multiform][subdir] = contrib

projects[plupload][version] = 1.7
projects[plupload][subdir] = contrib
projects[plupload][patch][2386741] = https://www.drupal.org/files/issues/2386741-plupload-modal-2.patch

libraries[colorbox][download][type] = file
libraries[colorbox][download][url] = https://github.com/jackmoore/colorbox/archive/1.x.zip
libraries[colorbox][directory_name] = colorbox

libraries[plupload][download][type] = get
libraries[plupload][download][url] = https://github.com/moxiecode/plupload/archive/v1.5.8.zip
libraries[plupload][directory_name] = plupload
libraries[plupload][destination] = libraries
libraries[plupload][patch][1903850] = https://www.drupal.org/files/issues/plupload-1_5_8-rm_examples-1903850-21.patch
