; Panopoly Core Makefile

api = 2
core = 7.x

; Panels and Chaos Tools Magic

projects[ctools][version] = 1.12
projects[ctools][subdir] = contrib
projects[ctools][patch][2607626] = https://www.drupal.org/files/issues/ctools-close-modal-2607626-5.patch
projects[ctools][patch][2787045] = https://www.drupal.org/files/issues/ctools-jquery_compatibility-2787045-14.patch
projects[ctools][patch][1901106] = https://www.drupal.org/files/issues/1901106-ctools-views_content-override-ajax-35.patch
projects[ctools][patch][2023705] = https://www.drupal.org/files/issues/2023705-ctools-autosubmit-15.patch
projects[ctools][patch][2448989] = https://www.drupal.org/files/issues/2448989-ctools-from_field_children-8.patch
projects[ctools][patch][2483415] = https://www.drupal.org/files/issues/ctools-more_than_one_comment_pager-2483415-1.patch
projects[ctools][patch][2555469] = https://www.drupal.org/files/issues/2555469-ctools-comments-node_tag_new-2.patch

projects[panels][version] = 3.8
projects[panels][subdir] = contrib
projects[panels][patch][2790075] = https://www.drupal.org/files/issues/not_authorized_when-2790075-26.patch
projects[panels][patch][2479879] = https://www.drupal.org/files/issues/panels-revert_allowed_types_to_variable-2479879-37.patch

projects[panels_breadcrumbs][version] = 2.2
projects[panels_breadcrumbs][subdir] = contrib

projects[panelizer][version] = 3.4
projects[panelizer][subdir] = contrib
projects[panelizer][patch][1549608] = https://www.drupal.org/files/issues/panelizer-n1549608-26.patch
projects[panelizer][patch][2788851] = https://www.drupal.org/files/issues/panelizer-administer-panelizer-2788851-2.patch

projects[fieldable_panels_panes][version] = 1.10
projects[fieldable_panels_panes][subdir] = contrib

projects[pm_existing_pages][version] = 1.4
projects[pm_existing_pages][subdir] = contrib

projects[fape][version] = 1.2
projects[fape][subdir] = contrib

; Views Magic

projects[views][version] = 3.15
projects[views][subdir] = contrib
projects[views][patch][2037469] = http://drupal.org/files/views-exposed-sorts-2037469-1.patch
projects[views][patch][1979926] = http://drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = https://www.drupal.org/files/issues/1735096-views-multiple-instance-exposed-form-15.patch
projects[views][patch][2411922] = https://www.drupal.org/files/issues/2411922-views-group_name-3.patch
projects[views][patch][2473389] = https://www.drupal.org/files/issues/2473389-views-exta-args-5.patch

projects[views_autocomplete_filters][version] = 1.2
projects[views_autocomplete_filters][subdir] = contrib
projects[views_autocomplete_filters][patch][2374709] = http://www.drupal.org/files/issues/views_autocomplete_filters-cache-2374709-2.patch
projects[views_autocomplete_filters][patch][2317351] = http://www.drupal.org/files/issues/views_autocomplete_filters-content-pane-2317351-4.patch
projects[views_autocomplete_filters][patch][2404893] = https://www.drupal.org/files/issues/2404893-grammar_correction-11.patch

projects[views_bulk_operations][version] = 3.3
projects[views_bulk_operations][subdir] = contrib

; The Usual Suspects

projects[pathauto][version] = 1.3
projects[pathauto][subdir] = contrib

projects[token][version] = 1.6
projects[token][subdir] = contrib
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch

projects[entity][version] = 1.6
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

projects[libraries][version] = 2.2
projects[libraries][subdir] = contrib

projects[transliteration][version] = 3.2
projects[transliteration][subdir] = contrib

; Field modules

projects[date][version] = 2.9
projects[date][subdir] = contrib
projects[date][patch][2375235] = https://www.drupal.org/files/issues/calendar_pager_broken-2375235-35.patch

projects[entityreference][version] = 1.x-dev
projects[entityreference][subdir] = contrib
projects[entityreference][download][type] = git
projects[entityreference][download][branch] = 7.x-1.x
projects[entityreference][download][revision] = c4bb9b
; Add revision support.  Related patches in Entity (1788568) and OG (2363599)
projects[entityreference][patch][1837650] = http://drupal.org/files/issues/entityreference-n1837650-47.patch
; Add autocomplete ability for group filters.
projects[entityreference][patch][1492260] = https://www.drupal.org/files/issues/1492260-54.patch


projects[field_group][version] = 1.5
projects[field_group][subdir] = contrib

projects[link][version] = 1.3
projects[link][subdir] = contrib

; Harness the Power of Features and Apps with Default Content

projects[apps][version] = 1.0
projects[apps][subdir] = contrib
projects[apps][patch][2753413] = https://www.drupal.org/files/issues/apps-manifest-2753413-3.patch
projects[apps][patch][2367191] = https://www.drupal.org/files/issues/apps_page_load_is_slow-2367191-5.patch

projects[features][version] = 2.10
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

projects[migrate][version] = "2.8"
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
projects[devel][version] = 1.5
projects[devel][subdir] = contrib

projects[distro_update][version] = 1.0-beta4
projects[distro_update][subdir] = contrib

projects[features_override][version] = 2.0-rc3
projects[features_override][subdir] = contrib

projects[uuid][version] = 1.0-alpha6
projects[uuid][subdir] = contrib
