api = 2
core = 7.x

; ************************************************
; ************* Open Atrium Plugins RELEASE ******

projects[oa_core][subdir] = contrib
projects[oa_core][version] = 2.16

projects[oa_discussion][subdir] = contrib
projects[oa_discussion][version] = 2.16

projects[oa_wiki][subdir] = contrib
projects[oa_wiki][version] = 2.16

projects[oa_events][subdir] = contrib
projects[oa_events][version] = 2.16

projects[oa_events_import][subdir] = contrib
projects[oa_events_import][version] = 2.16

projects[oa_worktracker][subdir] = contrib
projects[oa_worktracker][version] = 2.0-beta12

projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][version] = 2.16

projects[oa_notifications][subdir] = contrib
projects[oa_notifications][version] = 2.17

projects[oa_media][subdir] = contrib
projects[oa_media][version] = 2.16

projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][version] = 2.16

projects[oa_radix][type] = theme
projects[oa_radix][version] = 2.16

; ************************************************
; ************* Open Atrium Modules **************
; (Modules in distro, not yet their own separate projects)

; ##### oa_markdown #####
; Markdown
projects[markdown][version] = 1.1
projects[markdown][subdir] = contrib

; ##### oa_analytics #####
; Google Analytics
projects[google_analytics][version] = 1.3
projects[google_analytics][subdir] = contrib

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.

; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][version] = 1.0-rc5
; but, Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][version] = 1.2
projects[panopoly_core][subdir] = panopoly

; Panopoly Images 1.2+
projects[panopoly_images][version] = 1.x-dev
projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][branch] = 7.x-1.x
projects[panopoly_images][download][revision] = d5f5fa

projects[panopoly_theme][version] = 1.2
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.2
projects[panopoly_magic][subdir] = panopoly

; Panopoly Widgets 1.2+
projects[panopoly_widgets][version] = 1.x-dev
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][branch] = 7.x-1.x
projects[panopoly_widgets][download][revision] = 78acd5

; Panopoly Admin 1.2+
projects[panopoly_admin][version] = 1.x-dev
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][branch] = 7.x-1.x
projects[panopoly_admin][download][revision] = 7beafc

projects[panopoly_users][version] = 1.2
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.2
projects[panopoly_pages][subdir] = panopoly

; Panopoly WYSIWYG 1.2+
projects[panopoly_wysiwyg][version] = 1.x-dev
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x
projects[panopoly_wysiwyg][download][revision] = af6afc

projects[panopoly_search][version] = 1.2
projects[panopoly_search][subdir] = panopoly

; ***************** End Panopoly *****************
; ************************************************
