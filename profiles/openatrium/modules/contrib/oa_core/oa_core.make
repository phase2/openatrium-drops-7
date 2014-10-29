; Open Atrium Core Makefile

api = 2
core = 7.x

; ************************************************
; ************** PANOPOLY OVERRIDES **************

; Views
; Override panopoly_core.make: 3.8
projects[views][version] = 3.8
projects[views][subdir] = contrib
; patches from Panopoly
projects[views][patch][2037469] = http://drupal.org/files/views-exposed-sorts-2037469-1.patch
; additional patches for OA
projects[views][patch][1979926] = http://drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = http://drupal.org/files/1735096-views-mltiple-instance-exposed-form-8.patch

; CTools
; Override panopoly_core.make: 1.4
projects[ctools][version] = 1.4
projects[ctools][subdir] = contrib
; patches from Panopoly
projects[ctools][patch][2280875] = http://drupal.org/files/issues/ctools-icon-text-renderer-2280875-5.patch
projects[ctools][patch][581670] = http://drupal.org/files/fix-autocomplete-581670.patch
; additional patches for OA
projects[ctools][patch][1910608] = http://drupal.org/files/issues/1910608-views_content-ajax-13.patch
projects[ctools][patch][1901106] = http://drupal.org/files/issues/ctools-views_content-exposed_form_override-1901106-24.patch
projects[ctools][patch][2023705] = http://drupal.org/files/2023705-ctools-autosubmit-2_0.patch
projects[ctools][patch][2195471] = http://drupal.org/files/issues/ctools-n2195471-1.patch

; Entity API
; Override panopoly_core.make: 1.5
projects[entity][version] = 1.5
projects[entity][subdir] = contrib
; additional patches for OA
projects[entity][patch][1782134] = http://drupal.org/files/entity-translatable_fields_not_overriding_und_with_empty_values-1782134-5.patch

; Panelizer
; Override panopoly_core.make: 3.1 -> 3.x-dev
projects[panelizer][version] = 3.x-dev
projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][branch] = 7.x-3.x
projects[panelizer][download][revision] = 66d184
; additional patches for OA
projects[panelizer][patch][1982654] = http://drupal.org/files/1982654-panelizer-dontaskmethatagain-2.patch

; Token
; Override panopoly_core.make: 1.5
projects[token][version] = 1.5
projects[token][subdir] = contrib
; additional patches for OA
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch

; Field Group
; Override panopoly_core.make: 1.4
projects[field_group][version] = 1.4
projects[field_group][subdir] = contrib
;following patch not ready yet
;projects[field_group][patch][1278618] = http://drupal.org/files/issues/field_group-panels-integration-1278618-58.patch

; File Entity
; Override panopoly_widgets.make: 20f3070
projects[file_entity][version] = 2.x-dev
projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = git
projects[file_entity][download][revision] = 20f3070
projects[file_entity][download][branch] = 7.x-2.x
; additional patches for OA
projects[file_entity][patch][2360043] = https://www.drupal.org/files/issues/file_entity-destination-token-decode-2360043-1.patch

; ************ End Panopoly Overrides ************
; ************************************************

; Advagg
projects[advagg][version] = 2.6
projects[advagg][subdir] = contrib

; Chosen
projects[chosen][version] = 2.x-dev
projects[chosen][subdir] = contrib
projects[chosen][download][type] = git
projects[chosen][download][branch] = 7.x-2.x
projects[chosen][download][revision] = c48c8a

libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/1.0.0/chosen_v1.0.0.zip"
libraries[chosen][directory_name] = "chosen"
libraries[chosen][destination] = "libraries"

; Colorizer
projects[colorizer][version] = 1.4
projects[colorizer][subdir] = contrib

; Command buttons
projects[command_buttons][version] = 1.3
projects[command_buttons][subdir] = contrib

; Conditional Fields
projects[conditional_fields][version] = 3.x-dev
projects[conditional_fields][subdir] = contrib
projects[conditional_fields][download][type] = git
projects[conditional_fields][download][branch] = 7.x-3.x
projects[conditional_fields][download][revision] = cd29b00
projects[conditional_fields][patch][1982276] = http://drupal.org/files/conditional_fields-typo-in-if-condition-1982276-1.patch
projects[conditional_fields][patch][2027307] = https://www.drupal.org/files/issues/2027307-conditional_fields-export-clean-3.patch
projects[conditional_fields][patch][1916988] = http://drupal.org/files/1916988-conditional-fields-alter-3.patch
projects[conditional_fields][patch][1542706] = http://drupal.org/files/issues/conditional-fields-1542706-values-not-saving-72.patch
projects[conditional_fields][patch][2362507] = https://www.drupal.org/files/issues/2362507-conditional_fields-export-1.patch

; Conditional Style Sheets
projects[conditional_styles][version] = 2.2
projects[conditional_styles][subdir] = contrib

; Date Facets
projects[date_facets][version] = 1.x-dev
projects[date_facets][subdir] = contrib
projects[date_facets][download][type] = git
projects[date_facets][download][branch] = 7.x-1.x
projects[date_facets][download][revision] = a7a35f8

; Diff
projects[diff][version] = 3.2
projects[diff][subdir] = contrib

; Features Override
projects[features_override][version] = 2.0-rc2
projects[features_override][subdir] = contrib

; Feeds - latest dev needed by date_ical v3.1
projects[feeds][version] = 2.x-dev
projects[feeds][subdir] = contrib
projects[feeds][download][type] = git
projects[feeds][download][branch] = 7.x-2.x
projects[feeds][download][revision] = a8468a
projects[feeds][patch][2223853] = http://drupal.org/files/issues/2223853-fix_installing_taxonomy_module-7_0.patch

; SimplePie library used by Feeds
libraries[simplepie][download][type] = file
libraries[simplepie][download][url] = http://simplepie.org/downloads/simplepie_1.3.1.compiled.php
libraries[simplepie][download][filename] = simplepie.compiled.php
libraries[simplepie][directory_name] = simplepie

; Flag
projects[flag][version] = 2.x-dev
projects[flag][subdir] = contrib
projects[flag][download][type] = git
projects[flag][download][branch] = 7.x-2.x
projects[flag][download][revision] = b8d94e
projects[flag][patch][471212] = http://drupal.org/files/471212-14-flag-all-bundles.patch
projects[flag][patch][2027091] = http://drupal.org/files/flag-default-flags-alter-hook-2027091-03.patch

; HTML Mail
projects[htmlmail][version] = 2.65
projects[htmlmail][subdir] = contrib

; Job Scheduler
projects[job_scheduler][version] = 2.0-alpha3
projects[job_scheduler][subdir] = contrib

; Jquery Update
projects[jquery_update][version] = 2.4
projects[jquery_update][subdir] = contrib

; Mail System
projects[mailsystem][version] = 2.34
projects[mailsystem][subdir] = contrib

; Message
projects[message][version] = 1.x-dev
projects[message][subdir] = contrib
projects[message][download][type] = git
projects[message][download][branch] = 7.x-1.x
projects[message][download][revision] = 3bbdd5e
projects[message][patch][2046591] = http://drupal.org/files/message-token_replace-2046591-1.patch
projects[message][patch][2040735] = http://drupal.org/files/message.target_bundles.2040735-3.patch

; Message Digest
projects[message_digest][version] = 1.0
projects[message_digest][subdir] = contrib

; Message Notify
projects[message_notify][version] = 2.5
projects[message_notify][subdir] = contrib

; Message Subscribe
projects[message_subscribe][version] = 1.0-rc1
projects[message_subscribe][subdir] = contrib
projects[message_subscribe][patch][2094129] = http://drupal.org/files/message_subscribe_empty_array_2094129_1.patch

; MimeMail
projects[mimemail][version] = 1.x-dev
projects[mimemail][subdir] = contrib
projects[mimemail][download][type] = git
projects[mimemail][download][branch] = 7.x-1.x
projects[mimemail][download][revision] = e742766

; OA Responsive Regions
projects[oa_responsive_regions][version] = 1.0-beta1
projects[oa_responsive_regions][subdir] = contrib

; Organic Groups
projects[og][version] = 2.7
projects[og][subdir] = contrib

; Og menu single
projects[og_menu_single][version] = 1.0-beta1
projects[og_menu_single][subdir] = contrib

; OG Session Context
projects[og_session_context][version] = 1.0-beta1
projects[og_session_context][subdir] = contrib

; Og Variables
projects[og_variables][version] = 1.0-beta1
projects[og_variables][subdir] = contrib

; Organic Groups Vocabulary
projects[og_vocab][version] = 1.2
projects[og_vocab][subdir] = contrib
; patch to support subgroups
projects[og_vocab][patch][2039009] = http://drupal.org/files/issues/2039009-allow-shared-vocabularies-13.patch

; Panels Custom Error
projects[panels_customerror][version] = 1.0
projects[panels_customerror][subdir] = contrib

; Real Name
projects[realname][version] = 1.2
projects[realname][subdir] = contrib

; Reference Option Limit
projects[reference_option_limit][version] = 1.x-dev
projects[reference_option_limit][subdir] = contrib
projects[reference_option_limit][download][type] = git
projects[reference_option_limit][download][branch] = 7.x-1.x
projects[reference_option_limit][download][revision] = 0ea5303
projects[reference_option_limit][patch][1986532] = http://drupal.org/files/1986532_reference_option_limit_og-5.patch
projects[reference_option_limit][patch][1986526] = http://drupal.org/files/1986526_reference_option_limit_12.patch

; Variable
projects[variable][version] = 2.3
projects[variable][subdir] = contrib

; Views Load More
projects[views_load_more][version] = 1.x-dev
projects[views_load_more][subdir] = contrib
projects[views_load_more][download][type] = git
projects[views_load_more][download][branch] = 7.x-1.x
projects[views_load_more][download][revision] = 28de384

; Ultimate Cron
projects[ultimate_cron][version] = 2.0-beta7
projects[ultimate_cron][subdir] = contrib

