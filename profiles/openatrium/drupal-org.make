api = 2
core = 7.x

; ******************** RELEASE *******************

projects[oa_core][subdir] = contrib
projects[oa_core][version] = 2.25

; ************************************************
; ************* Open Atrium Builtin Apps *********

projects[oa_discussion][subdir] = apps
projects[oa_discussion][version] = 2.22

projects[oa_events][subdir] = apps
projects[oa_events][version] = 2.23

projects[oa_wiki][subdir] = apps
projects[oa_wiki][version] = 2.21

projects[oa_worktracker][subdir] = apps
projects[oa_worktracker][version] = 2.0-beta16

; ******** End Open Atrium Builtin Apps **********
; ************************************************


; ************************************************
; ************* Open Atrium Core Addon Apps ******
; (Local optional apps that included by default)

projects[oa_admin][version] = 2.0-rc1
projects[oa_admin][subdir] = apps

projects[oa_analytics][version] = 2.0-rc2
projects[oa_analytics][subdir] = apps

projects[oa_appearance][version] = 2.0-rc1
projects[oa_appearance][subdir] = apps

projects[oa_archive][version] = 2.0-rc2
projects[oa_archive][subdir] = apps

projects[oa_clone][version] = 2.0-rc1
projects[oa_clone][subdir] = apps

projects[oa_contextual_tabs][subdir] = apps
projects[oa_contextual_tabs][version] = 2.22

projects[oa_devel][version] = 2.0-rc1
projects[oa_devel][subdir] = apps

projects[oa_domains][version] = 2.0-rc1
projects[oa_domains][subdir] = apps

projects[oa_events_import][subdir] = apps
projects[oa_events_import][version] = 2.21

projects[oa_favorites][version] = 2.0-rc1
projects[oa_favorites][subdir] = apps

projects[oa_home][version] = 2.0-rc3
projects[oa_home][subdir] = apps

projects[oa_htmlmail][version] = 2.0-rc2
projects[oa_htmlmail][subdir] = apps

projects[oa_mailhandler][version] = 2.15
projects[oa_mailhandler][subdir] = apps

projects[oa_markdown][version] = 2.0-rc1
projects[oa_markdown][subdir] = apps

projects[oa_media][subdir] = apps
projects[oa_media][version] = 2.21

projects[oa_messages_digest][version] = 2.0-rc2
projects[oa_messages_digest][subdir] = apps

projects[oa_notifications][subdir] = apps
projects[oa_notifications][version] = 2.21

projects[oa_sandbox][version] = 2.0-rc1
projects[oa_sandbox][subdir] = apps

projects[oa_search][version] = 2.0-rc1
projects[oa_search][subdir] = apps

projects[oa_sitemap][version] = 2.0-rc2
projects[oa_sitemap][subdir] = apps

projects[oa_styles][version] = 2.0-rc1
projects[oa_styles][subdir] = apps

projects[oa_subspaces][subdir] = apps
projects[oa_subspaces][version] = 2.22

projects[oa_toolbar][version] = 2.0-rc1
projects[oa_toolbar][subdir] = apps

projects[oa_tour][version] = 2.0-rc1
projects[oa_tour][subdir] = apps

projects[oa_tour_defaults][version] = 2.0-rc1
projects[oa_tour_defaults][subdir] = apps

projects[oa_wizard][version] = 2.0-rc1
projects[oa_wizard][subdir] = apps

; ***************** End Apps *********************
; ************************************************


; ************************************************
; ************** Open Atrium Themes **************

projects[oa_radix][type] = theme
projects[oa_radix][version] = 3.2

; *********** End Open Atrium Themes *************
; ************************************************


; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush 5 concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.
; NOTE: If you are running Drush 6, this section should be places at the TOP

; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][version] = 1.10
; but, Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][version] = 1.13
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][patch][2361927] = https://www.drupal.org/files/issues/2361927-apps-beta18.patch

projects[panopoly_images][version] = 1.13
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.13
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.13
projects[panopoly_magic][subdir] = panopoly

projects[panopoly_widgets][version] = 1.13
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.13
projects[panopoly_admin][subdir] = panopoly

projects[panopoly_users][version] = 1.13
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.13
projects[panopoly_pages][subdir] = panopoly

projects[panopoly_wysiwyg][version] = 1.13
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.13
projects[panopoly_search][subdir] = panopoly


; ***************** End Panopoly *****************
; ************************************************

