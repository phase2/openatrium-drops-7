api = 2
core = 7.x

; Panopoly Core
; Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here
; #################### Panopoly #######################
projects[panopoly_core][version] = 1.x-dev
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][revision] = 6a257ac
projects[panopoly_core][download][branch] = 7.x-1.x

projects[panopoly_images][version] = 1.x-dev
projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][revision] = b57b48f
projects[panopoly_images][download][branch] = 7.x-1.x

projects[panopoly_theme][version] = 1.x-dev
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][revision] = 7715ded
projects[panopoly_theme][download][branch] = 7.x-1.x

projects[panopoly_magic][version] = 1.x-dev
projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][revision] = 623c6ff
projects[panopoly_magic][download][branch] = 7.x-1.x

projects[panopoly_widgets][version] = 1.x-dev
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][revision] = 6ca2f97
projects[panopoly_widgets][download][branch] = 7.x-1.x

projects[panopoly_admin][version] = 1.x-dev
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][revision] = 4d9d071
projects[panopoly_admin][download][branch] = 7.x-1.x

projects[panopoly_users][version] = 1.x-dev
projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][type] = git
projects[panopoly_users][download][revision] = cb4ca09
projects[panopoly_users][download][branch] = 7.x-1.x

; The Panopoly Toolset

projects[panopoly_pages][version] = 1.x-dev
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][revision] = 4125aa6
projects[panopoly_pages][download][branch] = 7.x-1.x

projects[panopoly_wysiwyg][version] = 1.x-dev
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][revision] = 227335f
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x

projects[panopoly_search][version] = 1.x-dev
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][revision] = c981ec3
projects[panopoly_search][download][branch] = 7.x-1.x
; #################### END Panopoly #######################
; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][download][type] = git
;projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
;projects[panopoly][download][branch] = 7.x-1.x

; **** Panopoly Overrides ****
; Update Panels to fix issue with custom region styles
projects[panels][version] = 3.x-dev
projects[panels][subdir] = contrib
projects[panels][download][type] = git
projects[panels][download][revision] = a915408
projects[panels][download][branch] = 7.x-3.x
projects[panels][patch][] = http://drupal.org/files/1838544-panels_ipe_region_style_0.patch

; Update Panelizer to latest with features override patch
projects[panelizer][type] = module
projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][url] = http://git.drupal.org/project/panelizer.git
projects[panelizer][download][branch] = 7.x-3.x
projects[panelizer][download][revision] = 1e050d3

; Update File entity to handle private content
projects[file_entity][type] = module
projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = git
projects[file_entity][download][url] = http://git.drupal.org/project/file_entity.git
projects[file_entity][download][branch] = 7.x-2.x
projects[file_entity][download][revision] = e6f091e

; Entityreference to work with Devel Generate
projects[entityreference][type] = module
projects[entityreference][subdir] = contrib
projects[entityreference][download][type] = git
projects[entityreference][download][url] = http://git.drupal.org/project/entityreference.git
projects[entityreference][download][branch] = 7.x-1.x
projects[entityreference][download][revision] = 1c176da

; Private file system fix
projects[media_youtube][version] = 2.x-dev
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = c53660c
projects[media_youtube][download][branch] = 7.x-2.x

;
; **** end of overrides ****

; Parent Theme
projects[radix][download][type] = git
projects[radix][download][url] = http://git.drupal.org/project/radix.git
projects[radix][download][branch] = 7.x-2.x
projects[radix][download][revision] = d92c98b

; Parent Theme
;projects[radix][download][type] = git
;projects[radix][download][url] = http://git.drupal.org/project/radix.git
;projects[radix][download][branch] = 7.x-2.x
;projects[radix][download][revision] = fbcbc725ba78792efc4fe2aee78d37b1cc567fc6
;projects[radix][patch][] = http://drupal.org/files/radix_button_parent-1975516.patch

; Features Override
projects[features_override][subdir] = contrib
projects[features_override][version] = 2.0-beta2

; Organic Groups
projects[og][subdir] = contrib
projects[og][version] = 2.2

; Organic Groups Vocabulary
projects[og_vocab][subdir] = contrib
projects[og_vocab][version] = 1.1

; Organic Groups Subgroups
projects[og_subgroups][subdir] = contrib
projects[og_subgroups][download][type] = git
projects[og_subgroups][download][url] = http://git.drupal.org/project/og_subgroups.git
projects[og_subgroups][download][branch] = 7.x-2.x
projects[og_subgroups][download][revision] = 7693f8915cb4bd45ae01c39d7abd5b54128e6d31
projects[og_subgroups][patch][] = http://drupal.org/files/og_subgroup-1985514-1.patch

; Rules
projects[rules][subdir] = contrib
projects[rules][version] = 2.3

; Message
projects[message][subdir] = contrib
projects[message][version] = 1.8

; Message Notify
projects[message_notify][subdir] = contrib
projects[message_notify][version] = 2.5

; Message Subscribe
projects[message_subscribe][subdir] = contrib
projects[message_subscribe][version] = 1.0-alpha5

; Flag
projects[flag][subdir] = contrib
projects[flag][version] = 2.0
projects[flag][download][type] = git
projects[flag][download][url] = http://git.drupal.org/project/flag.git
projects[flag][download][branch] = 7.x-2.x
projects[flag][download][revision] = 32cac54
projects[flag][patch][] = http://drupal.org/files/flag-all-bundles-7.x-2.x-471212-13.patch

; RealName
projects[realname][subdir] = contrib
projects[realname][version] = 1.1

; Chosen
projects[chosen][subdir] = contrib
projects[chosen][version] = 2.0-alpha1

; Twitter Bootstrap UI
;; Currently removed Twitter Bootstrap because of license issue:
;; http://drupal.org/node/1449452 http://drupal.org/node/1445226#comment-7343538
;; Instead, we load the Bootstrap JS via external CDN in template.php
;;projects[twitter_bootstrap_ui][type] = module
;;projects[twitter_bootstrap_ui][subdir] = contrib
;;projects[twitter_bootstrap_ui][download][type] = git
;;projects[twitter_bootstrap_ui][download][url] = http://git.drupal.org/project/twitter_bootstrap_ui.git
;;projects[twitter_bootstrap_ui][download][branch] = 7.x-2.x
;;projects[twitter_bootstrap_ui][patch][] = http://drupal.org/files/twitter_bootstrap_ui-allow_admin_configuration-1906722-5.patch
; tie to previous commit before the (2.x) was added to libraries
; since that doesn't work when module is patched in inherited profile
;;projects[twitter_bootstrap_ui][download][revision] = 0328b6ff027287fe7e62b058fc4dea12362956f5

;;libraries[twitter_bootstrap][download][type] = file
;;libraries[twitter_bootstrap][download][url] = http://twitter.github.com/bootstrap/assets/bootstrap.zip

; Make file for oa_media
; Colorbox
projects[colorbox][subdir] = contrib
projects[colorbox][version] = 2.4

projects[media_colorbox][subdir] = contrib
projects[media_colorbox][version] = 1.0-rc3

libraries[colorbox][download][type] = file
libraries[colorbox][download][url] = https://github.com/jackmoore/colorbox/archive/1.x.zip
libraries[colorbox][directory_name] = colorbox

; Devel
projects[devel][type] = module
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][branch] = 7.x-1.x
projects[devel][subdir] = contrib

; Diff
projects[diff][subdir] = contrib
projects[diff][version] = 3.2

; Job Scheduler
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha3

; Feeds
projects[feeds][subdir] = contrib
projects[feeds][version] = 2.0-alpha8

; Mailhandler
projects[mailhandler][subdir] = contrib
projects[mailhandler][download][type] = git
projects[mailhandler][download][url] = http://git.drupal.org/project/mailhandler.git
projects[mailhandler][download][branch] = 7.x-2.x
projects[mailhandler][download][revision] = c57579b
projects[mailhandler][patch][] = http://drupal.org/files/mailhandler-version-requirement-1961780-1.patch

; Views Load More
projects[views_load_more][subdir] = contrib
projects[views_load_more][download][type] = git
projects[views_load_more][download][url] = http://git.drupal.org/project/views_load_more.git
projects[views_load_more][download][branch] = 7.x-1.x
projects[views_load_more][download][revision] = 28de384

; Mail System
projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

; HTML Mail
projects[htmlmail][subdir] = contrib
projects[htmlmail][version] = 2.65

; Date Facets
projects[date_facets][subdir] = contrib
projects[date_facets][download][type] = git
projects[date_facets][download][url] = http://git.drupal.org/project/date_facets.git
projects[date_facets][download][branch] = 7.x-1.x
projects[date_facets][download][revision] = a7a35f8

; Og menu single
projects[og_menu_single][subdir] = contrib
projects[og_menu_single][download][type] = git
projects[og_menu_single][download][url] = http://git.drupal.org/project/og_menu_single.git
projects[og_menu_single][download][branch] = 7.x-1.x
projects[og_menu_single][download][revision] = 83dcd08
projects[og_menu_single][type] = module
