api = 2
core = 7.x

; ************************************************
; ************* Open Atrium Plugins RELEASE ******

projects[oa_core][subdir] = contrib
projects[oa_core][version] = 2.15

projects[oa_discussion][subdir] = contrib
projects[oa_discussion][version] = 2.14

projects[oa_wiki][subdir] = contrib
projects[oa_wiki][version] = 2.14

projects[oa_events][subdir] = contrib
projects[oa_events][version] = 2.14

projects[oa_events_import][subdir] = contrib
projects[oa_events_import][version] = 2.14

projects[oa_worktracker][subdir] = contrib
projects[oa_worktracker][version] = 2.0-beta11

projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][version] = 2.14

projects[oa_notifications][subdir] = contrib
projects[oa_notifications][version] = 2.14

projects[oa_media][subdir] = contrib
projects[oa_media][version] = 2.14

projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][version] = 2.14

projects[oa_radix][type] = theme
projects[oa_radix][version] = 2.14

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

projects[panopoly_core][version] = 1.x-dev
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][download][revision] = fe9fc2

projects[panopoly_images][version] = 1.1
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.x-dev
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][branch] = 7.x-1.x
projects[panopoly_theme][download][revision] = d409de

projects[panopoly_magic][version] = 1.1
projects[panopoly_magic][subdir] = panopoly

projects[panopoly_widgets][version] = 1.1
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.x-dev
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][branch] = 7.x-1.x
projects[panopoly_admin][download][revision] = daaf69

projects[panopoly_users][version] = 1.x-dev
projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][type] = git
projects[panopoly_users][download][branch] = 7.x-1.x
projects[panopoly_users][download][revision] = aa8e72

projects[panopoly_pages][version] = 1.x-dev
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][branch] = 7.x-1.x
projects[panopoly_pages][download][revision] = d45361

projects[panopoly_wysiwyg][version] = 1.x-dev
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x
projects[panopoly_wysiwyg][download][revision] = 7f1f37

projects[panopoly_search][version] = 1.x-dev
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][branch] = 7.x-1.x
projects[panopoly_search][download][revision] = f7e1fa

; ***************** End Panopoly *****************
; ************************************************
