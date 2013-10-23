api = 2
core = 7.x

; ************************************************
; ********** OPEN ATRIUM'S DEPENDENCIES **********

; Features Override
projects[features_override][version] = 2.0-rc1
projects[features_override][subdir] = contrib
projects[features_override][type] = module

; Diff
projects[diff][subdir] = contrib
projects[diff][version] = 3.2

; Job Scheduler
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha3

; Mail System
projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

; HTML Mail
projects[htmlmail][subdir] = contrib
projects[htmlmail][version] = 2.65

; ******** End Open Atrium's Dependencies ********
; ************************************************

; ************************************************
; ************* Open Atrium Plugins RELEASE ******

projects[oa_core][subdir] = contrib
projects[oa_core][version] = 2.0

projects[oa_discussion][subdir] = contrib
projects[oa_discussion][version] = 2.0

projects[oa_wiki][subdir] = contrib
projects[oa_wiki][version] = 2.0

projects[oa_events][subdir] = contrib
projects[oa_events][version] = 2.0

projects[oa_events_import][subdir] = contrib
projects[oa_events_import][version] = 2.0

projects[oa_worktracker][subdir] = contrib
projects[oa_worktracker][version] = 2.0-beta2

projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][version] = 2.0

projects[oa_notifications][subdir] = contrib
projects[oa_notifications][version] = 2.0

projects[oa_media][subdir] = contrib
projects[oa_media][version] = 2.0

projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][version] = 2.0

projects[oa_radix][type] = theme
projects[oa_radix][version] = 2.0

; ********** End Open Atrium's Plugins ***********
; ************************************************

; ************************************************
; ************* Open Atrium Modules **************
; (Modules in distro, not yet their own separate projects)

; ##### oa_markdown #####
; Markdown
projects[markdown][subdir] = contrib
projects[markdown][version] = 1.1

; ##### oa_search #####
; Date Facets
projects[date_facets][subdir] = contrib
projects[date_facets][download][type] = git
projects[date_facets][download][url] = http://git.drupal.org/project/date_facets.git
projects[date_facets][download][branch] = 7.x-1.x
projects[date_facets][download][revision] = a7a35f8

; ##### oa_analytics #####
; Google Analytics
projects[google_analytics][subdir] = contrib
projects[google_analytics][version] = 1.3

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

projects[panopoly_core][version] = 1.0-rc5
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][download][type] = git
projects[panopoly_core][patch][1837312] = http://drupal.org/files/panopoly_core-panelizer_default_permissions-1837312-26.patch

projects[panopoly_images][version] = 1.0-rc5
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.0-rc5
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.0-rc5
projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][branch] = 7.x-1.x
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][patch][2016527] = http://drupal.org/files/2016643_panopoly_magic_screw_pre_render_with_2016527-5.patch
projects[panopoly_magic][patch][2017159] = http://drupal.org/files/2017159_panopoly_magic_preview_post_render-22.patch

projects[panopoly_widgets][version] = 1.0-rc5
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.0-rc5
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][branch] = 7.x-1.x
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][patch][2071133] = http://drupal.org/files/panopoly_admin-2071133-3.patch

projects[panopoly_users][version] = 1.0-rc5
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.0-rc5
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][branch] = 7.x-1.x
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][patch][2008762] = http://drupal.org/files/2008762-panopoly_pages-missing-depedency-15.patch
projects[panopoly_pages][patch][1837312] = http://drupal.org/files/panopoly_pages-panelizer_default_permissions-1837312-26.patch

projects[panopoly_wysiwyg][version] = 1.0-rc5
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.0-rc5
projects[panopoly_search][subdir] = panopoly

; ***************** End Panopoly *****************
; ************************************************
