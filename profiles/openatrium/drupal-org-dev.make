api = 2
core = 7.x

; ************************************************
; ************* Open Atrium Plugins DEV **********

projects[oa_core][version] = 2.x-dev
projects[oa_core][subdir] = contrib
projects[oa_core][download][type] = git
projects[oa_core][download][branch] = 7.x-2.x

projects[oa_discussion][version] = 2.x-dev
projects[oa_discussion][subdir] = contrib
projects[oa_discussion][download][type] = git
projects[oa_discussion][download][branch] = 7.x-2.x

projects[oa_wiki][version] = 2.x-dev
projects[oa_wiki][subdir] = contrib
projects[oa_wiki][download][type] = git
projects[oa_wiki][download][branch] = 7.x-2.x

projects[oa_events][version] = 2.x-dev
projects[oa_events][subdir] = contrib
projects[oa_events][download][type] = git
projects[oa_events][download][branch] = 7.x-2.x

projects[oa_events_import][version] = 2.x-dev
projects[oa_events_import][subdir] = contrib
projects[oa_events_import][download][type] = git
projects[oa_events_import][download][branch] = 7.x-2.x

projects[oa_worktracker][version] = 2.x-dev
projects[oa_worktracker][subdir] = contrib
projects[oa_worktracker][download][type] = git
projects[oa_worktracker][download][branch] = 7.x-2.x

projects[oa_contextual_tabs][version] = 2.x-dev
projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][download][type] = git
projects[oa_contextual_tabs][download][branch] = 7.x-2.x

projects[oa_notifications][version] = 2.x-dev
projects[oa_notifications][subdir] = contrib
projects[oa_notifications][download][type] = git
projects[oa_notifications][download][branch] = 7.x-2.x

projects[oa_media][version] = 2.x-dev
projects[oa_media][subdir] = contrib
projects[oa_media][download][type] = git
projects[oa_media][download][branch] = 7.x-2.x

projects[oa_subspaces][version] = 2.x-dev
projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][download][type] = git
projects[oa_subspaces][download][branch] = 7.x-2.x

projects[oa_mailhandler][version] = 2.x-dev
projects[oa_mailhandler][subdir] = contrib
projects[oa_mailhandler][download][type] = git
projects[oa_mailhandler][download][branch] = 7.x-2.x

projects[oa_radix][type] = theme
projects[oa_radix][version] = 2.x-dev
projects[oa_radix][download][type] = git
projects[oa_radix][download][branch] = 7.x-2.x

; ##### oa_devel #####
; Devel
projects[devel][version] = 1.4
projects[devel][subdir] = contrib

; Coder
projects[coder][version] = 2.1
projects[coder][subdir] = contrib

; ********** End Open Atrium's Plugins ***********
; ************************************************

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
;projects[panopoly][version] = 1.5
; but, Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][version] = 1.6
projects[panopoly_core][subdir] = panopoly

projects[panopoly_images][version] = 1.6
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.6
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.6
projects[panopoly_magic][subdir] = panopoly

projects[panopoly_widgets][version] = 1.6
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.6
projects[panopoly_admin][subdir] = panopoly

projects[panopoly_users][version] = 1.6
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.6
projects[panopoly_pages][subdir] = panopoly

projects[panopoly_wysiwyg][version] = 1.6
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.6
projects[panopoly_search][subdir] = panopoly

; ***************** End Panopoly *****************
; ************************************************
