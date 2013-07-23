api = 2
core = 7.x

; ************************************************
; ************** PANOPOLY OVERRIDES **************

; Note that makefiles are parsed bottom-up and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY OVERRIDES need to be listed AT THE TOP of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.



; Overwrite wysiwyg to fix file_get_contents error
projects[wysiwyg][subdir] = contrib
projects[wysiwyg][download][type] = git
projects[wysiwyg][download][url] = http://git.drupal.org/project/wysiwyg.git
projects[wysiwyg][download][branch] = 7.x-1.x
projects[wysiwyg][download][revision] = cab91b85bbcc01b1cb3d15e357493af79b8f5faa
projects[wysiwyg][patch][1489096] = http://drupal.org/files/wysiwyg-table-format.patch
projects[wysiwyg][patch][1786732] = http://drupal.org/files/wysiwyg-arbitrary_image_paths_markitup-1786732-3.patch

; ##### oa_devel #####
; Devel
projects[devel][type] = module
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][branch] = 7.x-1.x
projects[devel][subdir] = contrib

; Override panopoly_core.make: a915408
; Patch Panels to fix issue with custom region styles (#1838544)
projects[panels][type] = module
projects[panels][subdir] = contrib
projects[panels][download][type] = git
projects[panels][download][url] = http://git.drupal.org/project/panels.git
projects[panels][download][revision] = a915408
projects[panels][download][branch] = 7.x-3.x
projects[panels][patch][1838544] = http://drupal.org/files/1838544-panels_ipe_region_style_0.patch
projects[panels][patch][2024441] = http://drupal.org/files/2024441-panels_standard_render_form_include-5.patch

projects[ctools][type] = module
projects[ctools][subdir] = contrib
projects[ctools][download][type] = git
projects[ctools][download][url] = http://git.drupal.org/project/ctools.git
projects[ctools][download][revision] = 83817fa
projects[ctools][download][branch] = 7.x-1.x
projects[ctools][patch][1901106] = http://drupal.org/files/1901106-ctools-views_content-exposed_form_override-13.patch
projects[ctools][patch][2016559] = http://drupal.org/files/ctools_views_content_numeric_pager_id.patch
projects[ctools][patch][2023705] = http://drupal.org/files/2023705-ctools-autosubmit-2.patch
projects[ctools][patch][1910608] = http://drupal.org/files/1910608-views_content-ajax-7.patch

; Override panopoly_core.make: 3.1
; Update Panelizer to latest dev version
projects[panelizer][type] = module
projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][url] = http://git.drupal.org/project/panelizer.git
projects[panelizer][download][branch] = 7.x-3.x
projects[panelizer][download][revision] = 1e050d3
projects[panelizer][patch][1992106] = http://drupal.org/files/1992106_panelizer_features_pipe-1.patch
projects[panelizer][patch][1982654] = http://drupal.org/files/1982654-panelizer-dontaskmethatagain-2.patch
projects[panelizer][patch][2022541] = http://drupal.org/files/2022541-panelizer-node-page-unpublished-1.patch

; Override panopoly_core.make: 1.0
; Update Entity Reference to work with Devel Generate (#1852112)
projects[entityreference][type] = module
projects[entityreference][subdir] = contrib
projects[entityreference][download][type] = git
projects[entityreference][download][url] = http://git.drupal.org/project/entityreference.git
projects[entityreference][download][branch] = 7.x-1.x
projects[entityreference][download][revision] = 1c176da

; Override panopoly_core.make: 1143ee2
; Patch FAPE to fix warnings (#1846156)
projects[fape][type] = module
projects[fape][subdir] = contrib
projects[fape][download][type] = git
projects[fape][download][url] = http://git.drupal.org/project/fape.git
projects[fape][download][branch] = 7.x-1.x
projects[fape][download][revision] = 1143ee2
projects[fape][patch][1846156] = http://drupal.org/files/fape-1846156-5.patch

; Override panopoly_widgets.make: 5418cbe
; Update Media Youtube to work with private filesystem (#1946002)
projects[media_youtube][type] = module
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][url] = http://git.drupal.org/project/media_youtube.git
projects[media_youtube][download][branch] = 7.x-2.x
projects[media_youtube][download][revision] = c53660c

; Override panopoly_core.make: 72f3d17
; Update token to allow disabling of empty token errors during test runs
projects[token][type] = module
projects[token][subdir] = contrib
projects[token][download][type] = git
projects[token][download][url] = http://git.drupal.org/project/token.git
projects[token][download][branch] = 7.x-1.x
projects[token][download][revision] = 72f3d17
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch


; Fix undefined did bug and installation issues.
projects[defaultconfig][subdir] = contrib
projects[defaultconfig][version] = 1.0-alpha9
projects[defaultconfig][patch][2042799] = http://drupal.org/files/default_config_delete_only_if_overriden.patch
projects[defaultconfig][patch][2043307] = http://drupal.org/files/defaultconfig_include_features_file.patch


; ************ End Panopoly Overrides ************
; ************************************************

; ************************************************
; ********** OPEN ATRIUM'S DEPENDENCIES **********

; Features Override
projects[features_override][type] = module
projects[features_override][download][type] = git
projects[features_override][subdir] = contrib
projects[features_override][download][url] = http://git.drupal.org/project/features_override.git
projects[features_override][download][branch] = 7.x-2.x
; Remove array_filter warning
projects[features_override][download][revision] = 73b3437d7fc692ec1020c39048acfd7faed79a26

; Features
projects[features][subdir] = contrib
projects[features][download][type] = git
projects[features][download][url] = http://git.drupal.org/project/features.git
projects[features][download][branch] = 7.x-2.x
projects[features][patch][2027023] = http://drupal.org/files/features_conflict_components.patch

projects[views][version] = 3.7
projects[views][subdir] = contrib
projects[views][patch][1979926] = http://drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = http://drupal.org/files/1735096-views-mltiple-instance-exposed-form-8.patch

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
; ************* Open Atrium Plugins **************

projects[oa_core][type] = module
projects[oa_core][subdir] = contrib
projects[oa_core][download][type] = git
projects[oa_core][download][url] = http://git.drupal.org/project/oa_core.git
projects[oa_core][download][branch] = 7.x-2.x

projects[oa_discussion][type] = module
projects[oa_discussion][subdir] = contrib
projects[oa_discussion][download][type] = git
projects[oa_discussion][download][url] = http://git.drupal.org/project/oa_discussion.git
projects[oa_discussion][download][branch] = 7.x-2.x

projects[oa_wiki][type] = module
projects[oa_wiki][subdir] = contrib
projects[oa_wiki][download][type] = git
projects[oa_wiki][download][url] = http://git.drupal.org/project/oa_wiki.git
projects[oa_wiki][download][branch] = 7.x-2.x

projects[oa_events][type] = module
projects[oa_events][subdir] = contrib
projects[oa_events][download][type] = git
projects[oa_events][download][url] = http://git.drupal.org/project/oa_events.git
projects[oa_events][download][branch] = 7.x-2.x

projects[oa_events_import][type] = module
projects[oa_events_import][subdir] = contrib
projects[oa_events_import][download][type] = git
projects[oa_events_import][download][url] = http://git.drupal.org/project/oa_events_import.git
projects[oa_events_import][download][branch] = 7.x-2.x

projects[oa_contextual_tabs][type] = module
projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][download][type] = git
projects[oa_contextual_tabs][download][url] = http://git.drupal.org/project/oa_contextual_tabs.git
projects[oa_contextual_tabs][download][branch] = 7.x-2.x

projects[oa_notifications][type] = module
projects[oa_notifications][subdir] = contrib
projects[oa_notifications][download][type] = git
projects[oa_notifications][download][url] = http://git.drupal.org/project/oa_notifications.git
projects[oa_notifications][download][branch] = 7.x-2.x

projects[oa_media][type] = module
projects[oa_media][subdir] = contrib
projects[oa_media][download][type] = git
projects[oa_media][download][url] = http://git.drupal.org/project/oa_media.git
projects[oa_media][download][branch] = 7.x-2.x

projects[oa_subspaces][type] = module
projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][download][type] = git
projects[oa_subspaces][download][url] = http://git.drupal.org/project/oa_subspaces.git
projects[oa_subspaces][download][branch] = 7.x-2.x

projects[oa_radix][type] = theme
projects[oa_radix][download][type] = git
projects[oa_radix][download][url] = http://git.drupal.org/project/oa_radix.git
projects[oa_radix][download][branch] = 7.x-2.x

; ********** End Open Atrium's Plugins ***********
; ************************************************

; ************************************************
; ************* Open Atrium Modules **************
; (Modules in distro, not yet their own separate projects)

; ##### oa_subspaces #####
; Organic Groups Subgroups
projects[og_subgroups][subdir] = contrib
projects[og_subgroups][download][type] = git
projects[og_subgroups][download][url] = http://git.drupal.org/project/og_subgroups.git
projects[og_subgroups][download][branch] = 7.x-2.x
projects[og_subgroups][patch][2029123] = http://drupal.org/files/2029123-og_permission_and_cache-9.patch
projects[og_subgroups][patch][1995018] = http://drupal.org/files/1995018-og_subgroups_og_alter-5.patch

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

; Coder
projects[coder][type] = module
projects[coder][download][type] = git
projects[coder][download][url] = http://git.drupal.org/project/coder.git
projects[coder][download][branch] = 7.x-2.x
projects[coder][subdir] = contrib

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.

; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][download][type] = git
;projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
;projects[panopoly][download][branch] = 7.x-1.x

; Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][version] = 1.x-dev
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][revision] = 6a257ac
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][patch][1979558] = http://drupal.org/files/1979558-panopoly-core-update-patch-4.patch
projects[panopoly_core][patch][1816688] = http://drupal.org/files/1816688-panopoly_core-apps-6.patch
projects[panopoly_core][patch][2044425] = http://drupal.org/files/panopoly_core_defaultcontent_dep.patch

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
projects[panopoly_magic][download][revision] = 16add888f93577ad9a27379ca309fcf7bd870a80
projects[panopoly_magic][download][branch] = 7.x-1.x
projects[panopoly_magic][patch][2016527] = http://drupal.org/files/2016527-panopoly_magic_parents_exposed-2.patch
projects[panopoly_magic][patch][2016643] = http://drupal.org/files/2016643_panopoly_magic_screw_pre_render_with_2016527-3-do-not-test.patch
projects[panopoly_magic][patch][2017159] = http://drupal.org/files/2017159_panopoly_magic_preview_post_render-12.patch
projects[panopoly_magic][patch][2046055] = http://drupal.org/files/panopoly_magic_css_unfloat_labels.patch

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

projects[panopoly_pages][version] = 1.x-dev
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][revision] = 4125aa6
projects[panopoly_pages][download][branch] = 7.x-1.x
projects[panopoly_pages][patch][2008762] = http://drupal.org/files/2008762-panopoly_pages-missing-depedency-1.patch

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

; ***************** End Panopoly *****************
; ************************************************
