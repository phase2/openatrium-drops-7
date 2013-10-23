; Open Atrium Core Makefile

api = 2
core = 7.x

; ************************************************
; ************** PANOPOLY OVERRIDES **************

; Override panopoly_core.make: a915408
; Patch Panels to fix issue with custom region styles (#1838544)
projects[panels][type] = module
projects[panels][subdir] = contrib
projects[panels][download][type] = git
projects[panels][download][url] = http://git.drupal.org/project/panels.git
projects[panels][download][revision] = 2bb470e
projects[panels][download][branch] = 7.x-3.x
projects[panels][patch][1354572] = http://drupal.org/files/ipe-duplicate-1354572-7.patch
projects[panels][patch][2012188] = http://drupal.org/files/panels_ipe-title-ctools-2012188-3.patch
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
projects[media_youtube][subdir] = contrib
projects[media_youtube][version] = 2.0-rc3

; Override panopoly_core.make: 72f3d17
; Update token to allow disabling of empty token errors during test runs
projects[token][type] = module
projects[token][subdir] = contrib
projects[token][download][type] = git
projects[token][download][url] = http://git.drupal.org/project/token.git
projects[token][download][branch] = 7.x-1.x
projects[token][version] = 1.5
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch

; Fix undefined did bug and installation issues.
projects[defaultconfig][subdir] = contrib
projects[defaultconfig][version] = 1.0-alpha9
projects[defaultconfig][download][type] = git
projects[defaultconfig][download][branch] = 7.x-1.x
projects[defaultconfig][patch][2042799] = http://drupal.org/files/default_config_delete_only_if_overriden.patch
projects[defaultconfig][patch][2043307] = http://drupal.org/files/defaultconfig_include_features_file.patch
projects[defaultconfig][patch][2008178] = http://drupal.org/files/defaultconfig-rebuild-filters-2008178-4_0.patch

; Entity API
projects[entity][version] = 1.2
projects[entity][subdir] = contrib

; Features
projects[features][version] = 2.0
projects[features][subdir] = contrib

; Views
projects[views][version] = 3.7
projects[views][subdir] = contrib
projects[views][download][type] = git
projects[views][download][branch] = 7.x-3.x
projects[views][patch][1979926] = http://drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = http://drupal.org/files/1735096-views-mltiple-instance-exposed-form-8.patch

; ************ End Panopoly Overrides ************
; ************************************************

; Message
projects[message][subdir] = contrib
projects[message][version] = 1.8
projects[message][download][type] = git
projects[message][download][url] = http://git.drupal.org/project/message.git
projects[message][download][branch] = 7.x-1.x
projects[message][patch][2046591] = http://drupal.org/files/message-token_replace-2046591-1.patch
projects[message][patch][2040735] = http://drupal.org/files/message.target_bundles.2040735-3.patch

; Message Notify
projects[message_notify][subdir] = contrib
projects[message_notify][version] = 2.5

; Message Subscribe
projects[message_subscribe][subdir] = contrib
projects[message_subscribe][version] = 1.0-alpha5
projects[message_subscribe][patch][2094129] = http://drupal.org/files/message_subscribe_empty_array_2094129_1.patch

; Message Digest
projects[message_digest][subdir] = contrib
projects[message_digest][version] = 1.0-beta1

; Flag
projects[flag][subdir] = contrib
projects[flag][version] = 2.0
projects[flag][download][type] = git
projects[flag][download][url] = http://git.drupal.org/project/flag.git
projects[flag][download][branch] = 7.x-2.x
projects[flag][download][revision] = e37c2475
projects[flag][patch][471212] = http://drupal.org/files/471212-14-flag-all-bundles.patch
projects[flag][patch][2027091] = http://drupal.org/files/flag_hook_flag_default_flags_alter.patch

; MimeMail
projects[mimemail][type] = module
projects[mimemail][subdir] = contrib
projects[mimemail][download][type] = git
projects[mimemail][download][url] = http://git.drupal.org/project/mimemail.git
projects[mimemail][download][branch] = 7.x-1.x
projects[mimemail][download][revision] = e742766

projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

; RealName
projects[realname][subdir] = contrib
projects[realname][version] = 1.1

; Chosen
projects[chosen][subdir] = contrib
projects[chosen][version] = 2.0-alpha2

libraries[chosen][download][type]    = git
libraries[chosen][download][url]     = https://github.com/harvesthq/chosen.git
libraries[chosen][download][tag]     = v0.9.15

; Twitter Bootstrap UI
;; Currently removed Twitter Bootstrap because of license issue:
;; http://drupal.org/node/1449452 http://drupal.org/node/1445226#comment-7343538
;; Instead, we load the Bootstrap JS via external CDN in template.php
;;projects[twitter_bootstrap_ui][type] = module
;;projects[twitter_bootstrap_ui][subdir] = contrib
;;projects[twitter_bootstrap_ui][download][type] = git
;;projects[twitter_bootstrap_ui][download][url] = http://git.drupal.org/project/twitter_bootstrap_ui.git
;;projects[twitter_bootstrap_ui][download][branch] = 7.x-2.x
;;projects[twitter_bootstrap_ui][patch][1906722] = http://drupal.org/files/twitter_bootstrap_ui-allow_admin_configuration-1906722-5.patch
; tie to previous commit before the (2.x) was added to libraries
; since that doesn't work when module is patched in inherited profile
;;projects[twitter_bootstrap_ui][download][revision] = 0328b6ff027287fe7e62b058fc4dea12362956f5

;;libraries[twitter_bootstrap][download][type] = file
;;libraries[twitter_bootstrap][download][url] = http://twitter.github.com/bootstrap/assets/bootstrap.zip

; Feeds
projects[feeds][type] = module
projects[feeds][subdir] = contrib
projects[feeds][download][type] = git
projects[feeds][download][url] = http://git.drupal.org/project/feeds.git
projects[feeds][download][branch] = 7.x-2.x
projects[feeds][download][revision] = 7e6679d

libraries[simplepie][download][type] = file
libraries[simplepie][download][url] = http://simplepie.org/downloads/simplepie_1.3.1.compiled.php
libraries[simplepie][download][filename] = simplepie.compiled.php
libraries[simplepie][directory_name] = simplepie

; Command buttons
projects[command_buttons][subdir] = contrib
projects[command_buttons][version] = 1.0-beta1

; Contextual Tabs
projects[contextual_tabs][subdir] = contrib
projects[contextual_tabs][version] = 1.0-beta1

projects[panels_customerror][type] = module
projects[panels_customerror][subdir] = contrib
projects[panels_customerror][version] = 1.0-beta1

; Conditional Fields
projects[conditional_fields][subdir] = contrib
projects[conditional_fields][download][branch] = 7.x-3.x
projects[conditional_fields][download][revision] = cd29b00
projects[conditional_fields][download][type] = git
projects[conditional_fields][patch][1982276] = http://drupal.org/files/conditional_fields-typo-in-if-condition-1982276-1.patch
projects[conditional_fields][patch][2027307] = http://drupal.org/files/conditional_fields-export-0.patch
projects[conditional_fields][patch][1916988] = http://drupal.org/files/1916988-conditional-fields-alter-3.patch

; Reference Option Limit
projects[reference_option_limit][subdir] = contrib
projects[reference_option_limit][download][type] = git
projects[reference_option_limit][download][url] = http://git.drupal.org/project/reference_option_limit.git
projects[reference_option_limit][download][branch] = 7.x-1.x
projects[reference_option_limit][download][revision] = 74bee91
projects[reference_option_limit][type] = module
projects[reference_option_limit][patch][1986532] = http://drupal.org/files/1986532_reference_option_limit_og-2.patch
projects[reference_option_limit][patch][1986526] = http://drupal.org/files/1986526_reference_option_limit_3.patch

; Views Load More
projects[views_load_more][subdir] = contrib
projects[views_load_more][download][type] = git
projects[views_load_more][download][url] = http://git.drupal.org/project/views_load_more.git
projects[views_load_more][download][branch] = 7.x-1.x
projects[views_load_more][download][revision] = 28de384

; Trash Flag
projects[trash_flag][type] = module
projects[trash_flag][subdir] = contrib
projects[trash_flag][version] = 1.0-beta1

; Jquery Update
projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = 2.3
projects[jquery_update][download][type] = git
projects[jquery_update][download][branch] = 7.x-2.x
projects[jquery_update][patch][1448490] = http://drupal.org/files/jquery_update-fixes-states-js-1448490.patch

; Colorizer
projects[colorizer][subdir] = contrib
projects[colorizer][version] = 1.0-beta1

; OA Responsive Regions
projects[oa_responsive_regions][subdir] = contrib
projects[oa_responsive_regions][version] = 1.0-beta1


; ##### Organic Groups related #####
; Organic Groups
projects[og][download][type] = git
projects[og][subdir] = contrib
projects[og][download][url] = http://git.drupal.org/project/og.git
projects[og][download][branch] = 7.x-2.x
projects[og][download][revision] = 6c0afff

; Organic Groups Vocabulary
projects[og_vocab][subdir] = contrib
projects[og_vocab][version] = 1.1
projects[og_vocab][download][type] = git
projects[og_vocab][download][branch] = 7.x-1.x
projects[og_vocab][download][revision] = bd5b341
projects[og_vocab][patch][1985316] = http://drupal.org/files/1985316-og_vocab-menu_get_item-1.patch

; OG Session Context
projects[og_session_context][type] = module
projects[og_session_context][subdir] = contrib
projects[og_session_context][version] = 1.0-beta1

; Og menu single
projects[og_menu_single][type] = module
projects[og_menu_single][subdir] = contrib
projects[og_menu_single][version] = 1.0-beta1

; ##### oa_variables #####
; Variable
projects[variable][subdir] = contrib
projects[variable][version] = 2.3

; Og Variables
projects[og_variables][type] = module
projects[og_variables][subdir] = contrib
projects[og_variables][version] = 1.0-beta1

; Bootstrap Tour
projects[bootstrap_tour][type] = module
projects[bootstrap_tour][subdir] = contrib
projects[bootstrap_tour][version] = 1.0-beta2
