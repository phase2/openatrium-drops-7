; Panopoly Core Makefile

api = 2
core = 7.x

; Panels and Chaos Tools Magic

projects[ctools][version] = 1.15
projects[ctools][subdir] = contrib
projects[ctools][patch][1910608] = https://www.drupal.org/files/issues/2018-03-27/views_content-keyword-substitution-1910608-56.patch
projects[ctools][patch][2843333] = https://www.drupal.org/files/issues/2018-05-21/ctools-views_content-ajax-settings-pane-rendering-fix-2843333-16.patch
projects[ctools][patch][1901106] = https://www.drupal.org/files/issues/2018-03-28/1901106-ctools-views_content-override-ajax-40.patch
projects[ctools][patch][2023705] = https://www.drupal.org/files/issues/2023705-ctools-autosubmit-15.patch
projects[ctools][patch][2448989] = https://www.drupal.org/files/issues/2448989-ctools-from_field_children-8.patch
projects[ctools][patch][2483415] = https://www.drupal.org/files/issues/ctools-more_than_one_comment_pager-2483415-1.patch

projects[panels][version] = 3.9
projects[panels][subdir] = contrib
projects[panels][patch][1570120] = https://www.drupal.org/files/issues/move-image-1570120-31.patch
projects[panels][patch][2897658] = https://www.drupal.org/files/issues/panels-menu-block-ipe-2897658-3.patch

projects[panels_breadcrumbs][version] = 2.4
projects[panels_breadcrumbs][subdir] = contrib

projects[panelizer][version] = 3.4
projects[panelizer][subdir] = contrib
projects[panelizer][patch][1549608] = https://www.drupal.org/files/issues/panelizer-n1549608-26.patch
projects[panelizer][patch][2788851] = https://www.drupal.org/files/issues/panelizer-administer-panelizer-2788851-2.patch

projects[fieldable_panels_panes][version] = 1.13
projects[fieldable_panels_panes][subdir] = contrib

projects[pm_existing_pages][version] = 1.4
projects[pm_existing_pages][subdir] = contrib

projects[fape][version] = 1.2
projects[fape][subdir] = contrib

; Views Magic

projects[views][version] = 3.24
projects[views][subdir] = contrib
projects[views][patch][2037469] = https://www.drupal.org/files/issues/views-exposed-sorts-2037469-26.patch
projects[views][patch][2977851] = https://www.drupal.org/files/issues/2019-09-23/2977851-views-php72-count-14_0.patch
projects[views][patch][2284423] = https://www.drupal.org/files/issues/2019-04-29/views-same_sort_twice-2284423-3.patch
projects[views][patch][3076826] = https://www.drupal.org/files/issues/2019-08-23/views-php7-3076826-2.patch
projects[views][patch][1979926] = https://www.drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = https://www.drupal.org/files/issues/2019-05-07/1735096-views-multiple-instance-exposed-form-31.patch

projects[views_autocomplete_filters][version] = 1.2
projects[views_autocomplete_filters][subdir] = contrib
projects[views_autocomplete_filters][patch][2374709] = http://www.drupal.org/files/issues/views_autocomplete_filters-cache-2374709-2.patch
projects[views_autocomplete_filters][patch][2317351] = http://www.drupal.org/files/issues/views_autocomplete_filters-content-pane-2317351-4.patch
projects[views_autocomplete_filters][patch][2404893] = https://www.drupal.org/files/issues/2404893-grammar_correction-11.patch

projects[views_bulk_operations][version] = 3.5
projects[views_bulk_operations][subdir] = contrib

; The Usual Suspects

projects[pathauto][version] = 1.3
projects[pathauto][subdir] = contrib

projects[token][version] = 1.7
projects[token][subdir] = contrib
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch

projects[entity][version] = 1.9
projects[entity][subdir] = contrib
projects[entity][patch][1782134] = http://drupal.org/files/entity-translatable_fields_not_overriding_und_with_empty_values-1782134-5.patch
; related to Entity Reference revisions patch (1837650)
projects[entity][patch][1788568] = http://drupal.org/files/issues/entity-1788568-21-entity_metadata_wrapper_revisions.patch
; fix for recursive entity views
projects[entity][patch][2407905] = http://drupal.org/files/issues/entity_unsupported_operand-2407905-1.patch
; fix for comment entity access
projects[entity][patch][2236229] = https://www.drupal.org/files/issues/add_create_op_to_metadata_comment_access-2236229-1.patch
; fix for simpletext and entity
projects[entity][patch][2289693] = https://www.drupal.org/files/issues/entity_undefined_entity_get_info-2289693-2.patch

projects[libraries][version] = 2.5
projects[libraries][subdir] = contrib

projects[transliteration][version] = 3.2
projects[transliteration][subdir] = contrib

; Field modules

projects[date][version] = 2.10
projects[date][subdir] = contrib
projects[date][patch][2449261] = https://www.drupal.org/files/issues/2018-08-30/date-cannot_create_references_to_from_string_offsets-2449261-14.patch
projects[date][patch][2889759] = https://www.drupal.org/files/issues/date-php7Offset-2889759-1.patch
projects[date][patch][2995679] = https://www.drupal.org/files/issues/2018-08-28/date-array_conversion-2995679-2-D7.patch
projects[date][patch][2843367-1] = https://www.drupal.org/files/issues/2019-01-16/2843367-php71-string-offset-47.patch
projects[date][patch][2843367-2] = https://www.drupal.org/files/issues/2843367-php71-string-offset-26.patch

projects[entityreference][version] = 1.5
projects[entityreference][subdir] = contrib
; Add revision support.  Related patches in Entity (1788568) and OG (2363599)
projects[entityreference][patch][1837650] = https://www.drupal.org/files/issues/1837650-142-entityreference-referencing-specific-revision-reroll-134_1.patch
; Add autocomplete ability for group filters.
projects[entityreference][patch][1492260] = https://www.drupal.org/files/issues/1492260-54.patch

projects[field_group][version] = 1.6
projects[field_group][subdir] = contrib

projects[link][version] = 1.7
projects[link][subdir] = contrib
projects[link][patch][2666912] = https://www.drupal.org/files/issues/2019-11-18/link-revert-url-validation-2666912-54.patch
projects[link][patch][3120382] = https://www.drupal.org/files/issues/2020-03-17/link-panopoly-magic-notice-3120382-2.patch

; Harness the Power of Features and Apps with Default Content

projects[apps][version] = 1.1
projects[apps][subdir] = contrib
projects[apps][patch][2945929] = https://www.drupal.org/files/issues/apps-php7-compat-2945929.patch
projects[apps][patch][2367191] = https://www.drupal.org/files/issues/apps_page_load_is_slow-2367191-5.patch

projects[features][version] = 2.11
projects[features][subdir] = contrib

projects[strongarm][version] = 2.0
projects[strongarm][subdir] = contrib

projects[defaultconfig][version] = 1.0-alpha11
projects[defaultconfig][subdir] = contrib
projects[defaultconfig][patch][1900574] = http://drupal.org/files/1900574.defaultconfig.undefinedindex_11.patch

projects[defaultcontent][version] = 1.0-alpha9
projects[defaultcontent][subdir] = contrib
projects[defaultcontent][patch][1754428] = http://drupal.org/files/1754428-allow-node-export-alter.patch
projects[defaultcontent][patch][1757782] = http://drupal.org/files/1757782-cannot-import-menu-hierarchy-8.patch
projects[defaultcontent][patch][2946138] = https://www.drupal.org/files/issues/defaultcontent-php7-compat-2946138.patch

projects[migrate][version] = "2.11"
projects[migrate][type] = "module"
projects[migrate][subdir] = "contrib"

projects[migrate_extras][version] = "2.5"
projects[migrate_extras][type] = "module"
projects[migrate_extras][subdir] = "contrib"

; jQuery Update was moved to Panopoly Core, but is left in Panopoly Admin's
; .make file to retain a stable 1.x branch of Panopoly. See the following URL
; for more information: http://drupal.org/node/2492811
projects[jquery_update][version] = 2.7
projects[jquery_update][subdir] = contrib

; Recommended Modules
projects[devel][version] = 1.7
projects[devel][subdir] = contrib

projects[distro_update][version] = 1.0-beta4
projects[distro_update][subdir] = contrib

projects[features_override][version] = 2.0-rc3
projects[features_override][subdir] = contrib

projects[uuid][version] = 1.3
projects[uuid][subdir] = contrib
