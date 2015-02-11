api = 2
core = 7.x

; BASE Make file for building Open Atrium dev.

; ********************** DEV *********************

projects[oa_core][version] = 2.x-dev
projects[oa_core][subdir] = contrib
projects[oa_core][download][type] = git
projects[oa_core][download][branch] = 7.x-2.x

projects[oa_test][version] = 2.x-dev
projects[oa_test][subdir] = contrib
projects[oa_test][download][type] = git
projects[oa_test][download][branch] = 7.x-2.x

projects[apps][version] = 1.x-dev
projects[apps][subdir] = contrib
projects[apps][download][type] = git
projects[apps][download][branch] = 7.x-1.x


; ************************************************
; ************* Open Atrium Builtin Apps *********

projects[oa_discussion][version] = 2.x-dev
projects[oa_discussion][subdir] = apps
projects[oa_discussion][download][type] = git
projects[oa_discussion][download][branch] = 7.x-2.x

projects[oa_events][version] = 2.x-dev
projects[oa_events][subdir] = apps
projects[oa_events][download][type] = git
projects[oa_events][download][branch] = 7.x-2.x

projects[oa_wiki][version] = 2.x-dev
projects[oa_wiki][subdir] = apps
projects[oa_wiki][download][type] = git
projects[oa_wiki][download][branch] = 7.x-2.x

projects[oa_worktracker][version] = 2.x-dev
projects[oa_worktracker][subdir] = apps
projects[oa_worktracker][download][type] = git
projects[oa_worktracker][download][branch] = 7.x-2.x

; ******** End Open Atrium Builtin Apps **********
; ************************************************


; ************************************************
; ************* Open Atrium Core Addon Apps ******
; (Local optional apps that included by default)

projects[oa_admin][version] = 2.x-dev
projects[oa_admin][subdir] = apps
projects[oa_admin][download][type] = git
projects[oa_admin][download][branch] = 7.x-2.x

projects[oa_analytics][version] = 2.x-dev
projects[oa_analytics][subdir] = apps
projects[oa_analytics][download][type] = git
projects[oa_analytics][download][branch] = 7.x-2.x

projects[oa_appearance][version] = 2.x-dev
projects[oa_appearance][subdir] = apps
projects[oa_appearance][download][type] = git
projects[oa_appearance][download][branch] = 7.x-2.x

projects[oa_archive][version] = 2.x-dev
projects[oa_archive][subdir] = apps
projects[oa_archive][download][type] = git
projects[oa_archive][download][branch] = 7.x-2.x

projects[oa_clone][version] = 2.x-dev
projects[oa_clone][subdir] = apps
projects[oa_clone][download][type] = git
projects[oa_clone][download][branch] = 7.x-2.x

projects[oa_contextual_tabs][version] = 2.x-dev
projects[oa_contextual_tabs][subdir] = apps
projects[oa_contextual_tabs][download][type] = git
projects[oa_contextual_tabs][download][branch] = 7.x-2.x

projects[oa_devel][version] = 2.x-dev
projects[oa_devel][subdir] = apps
projects[oa_devel][download][type] = git
projects[oa_devel][download][branch] = 7.x-2.x

projects[oa_domains][version] = 2.x-dev
projects[oa_domains][subdir] = apps
projects[oa_domains][download][type] = git
projects[oa_domains][download][branch] = 7.x-2.x

projects[oa_events_import][version] = 2.x-dev
projects[oa_events_import][subdir] = apps
projects[oa_events_import][download][type] = git
projects[oa_events_import][download][branch] = 7.x-2.x

projects[oa_favorites][version] = 2.x-dev
projects[oa_favorites][subdir] = apps
projects[oa_favorites][download][type] = git
projects[oa_favorites][download][branch] = 7.x-2.x

projects[oa_files][version] = 2.x-dev
projects[oa_files][subdir] = apps
projects[oa_files][type] = module
projects[oa_files][download][type] = git
projects[oa_files][download][branch] = 7.x-2.x

projects[oa_home][version] = 2.x-dev
projects[oa_home][subdir] = apps
projects[oa_home][download][type] = git
projects[oa_home][download][branch] = 7.x-2.x

projects[oa_htmlmail][version] = 2.x-dev
projects[oa_htmlmail][subdir] = apps
projects[oa_htmlmail][download][type] = git
projects[oa_htmlmail][download][branch] = 7.x-2.x

projects[oa_mailhandler][version] = 2.x-dev
projects[oa_mailhandler][subdir] = apps
projects[oa_mailhandler][download][type] = git
projects[oa_mailhandler][download][branch] = 7.x-2.x

projects[oa_markdown][version] = 2.x-dev
projects[oa_markdown][subdir] = apps
projects[oa_markdown][download][type] = git
projects[oa_markdown][download][branch] = 7.x-2.x

projects[oa_media][version] = 2.x-dev
projects[oa_media][subdir] = apps
projects[oa_media][download][type] = git
projects[oa_media][download][branch] = 7.x-2.x

projects[oa_messages_digest][version] = 2.x-dev
projects[oa_messages_digest][subdir] = apps
projects[oa_messages_digest][download][type] = git
projects[oa_messages_digest][download][branch] = 7.x-2.x

projects[oa_notifications][version] = 2.x-dev
projects[oa_notifications][subdir] = apps
projects[oa_notifications][download][type] = git
projects[oa_notifications][download][branch] = 7.x-2.x

projects[oa_related][version] = 2.x-dev
projects[oa_related][subdir] = apps
projects[oa_related][type] = module
projects[oa_related][download][type] = git
projects[oa_related][download][branch] = 7.x-2.x

projects[oa_sandbox][version] = 2.x-dev
projects[oa_sandbox][subdir] = apps
projects[oa_sandbox][download][type] = git
projects[oa_sandbox][download][branch] = 7.x-2.x

projects[oa_search][version] = 2.x-dev
projects[oa_search][subdir] = apps
projects[oa_search][download][type] = git
projects[oa_search][download][branch] = 7.x-2.x

projects[oa_sitemap][version] = 2.x-dev
projects[oa_sitemap][subdir] = apps
projects[oa_sitemap][download][type] = git
projects[oa_sitemap][download][branch] = 7.x-2.x

projects[oa_styles][version] = 2.x-dev
projects[oa_styles][subdir] = apps
projects[oa_styles][download][type] = git
projects[oa_styles][download][branch] = 7.x-2.x

projects[oa_subspaces][version] = 2.x-dev
projects[oa_subspaces][subdir] = apps
projects[oa_subspaces][download][type] = git
projects[oa_subspaces][download][branch] = 7.x-2.x

projects[oa_toolbar][version] = 2.x-dev
projects[oa_toolbar][subdir] = apps
projects[oa_toolbar][download][type] = git
projects[oa_toolbar][download][branch] = 7.x-2.x

projects[oa_tour][version] = 2.x-dev
projects[oa_tour][subdir] = apps
projects[oa_tour][download][type] = git
projects[oa_tour][download][branch] = 7.x-2.x

projects[oa_tour_defaults][version] = 2.x-dev
projects[oa_tour_defaults][subdir] = apps
projects[oa_tour_defaults][download][type] = git
projects[oa_tour_defaults][download][branch] = 7.x-2.x

projects[oa_wizard][version] = 2.x-dev
projects[oa_wizard][subdir] = apps
projects[oa_wizard][download][type] = git
projects[oa_wizard][download][branch] = 7.x-2.x

; ***************** End Apps *********************
; ************************************************


; ************************************************
; ************** Open Atrium Themes **************

projects[oa_radix][type] = theme
projects[oa_radix][version] = 3.x-dev
projects[oa_radix][download][type] = git
projects[oa_radix][download][branch] = 7.x-3.x

; *********** End Open Atrium Themes *************
; ************************************************



; ************************************************
; ************** Open Atrium Contrib *************

projects[bootstrap_tour][version] = 1.x-dev
projects[bootstrap_tour][subdir] = contrib
projects[bootstrap_tour][download][type] = git
projects[bootstrap_tour][download][branch] = 7.x-1.x

projects[command_buttons][version] = 1.x-dev
projects[command_buttons][subdir] = contrib
projects[command_buttons][download][type] = git
projects[command_buttons][download][branch] = 7.x-1.x

projects[contextual_tabs][version] = 1.x-dev
projects[contextual_tabs][subdir] = contrib
projects[contextual_tabs][download][type] = git
projects[contextual_tabs][download][branch] = 7.x-1.x

projects[oa_angular][version] = 1.x-dev
projects[oa_angular][subdir] = contrib
projects[oa_angular][download][type] = git
projects[oa_angular][download][branch] = 7.x-1.x

; *********** End Open Atrium Contrib ************
; ************************************************

