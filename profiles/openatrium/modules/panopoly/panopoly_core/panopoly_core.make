; Panopoly Core Makefile

api = 2
core = 7.x

; Panels and Chaos Tools Magic

projects[ctools][version] = 1.6
projects[ctools][subdir] = contrib
projects[ctools][patch][2416589] = http://www.drupal.org/files/issues/ctools-illegal-offset-views-add-contextual-links-2416589-1.patch
projects[ctools][patch][2119357] = http://www.drupal.org/files/issues/2119357-6_0.patch

projects[panels][version] = 3.5
projects[panels][subdir] = contrib

projects[panels_breadcrumbs][version] = 2.2
projects[panels_breadcrumbs][subdir] = contrib

projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][branch] = 7.x-3.x
projects[panelizer][download][revision] = 66d184
projects[panelizer][patch][1623536] = http://drupal.org/files/issues/array-to-object-on-update-1623536-26.patch
projects[panelizer][patch][2416505] = http://www.drupal.org/files/issues/panelizer-search_api-2416505-3.patch
projects[panelizer][patch][1982654] = http://drupal.org/files/1982654-panelizer-dontaskmethatagain-2.patch

projects[fieldable_panels_panes][version] = 1.5
projects[fieldable_panels_panes][subdir] = contrib
projects[fieldable_panels_panes][patch][2283263] = http://drupal.org/files/issues/fieldable_panels_panes-n2283263-5.patch
projects[fieldable_panels_panes][patch][2256503] = http://www.drupal.org/files/issues/fieldable_panels_panes-n2256503-12-backport-fpp15.patch

projects[pm_existing_pages][version] = 1.4
projects[pm_existing_pages][subdir] = contrib

projects[fape][version] = 1.2
projects[fape][subdir] = contrib

; Views Magic

projects[views][version] = 3.10
projects[views][subdir] = contrib
projects[views][patch][2037469] = http://drupal.org/files/views-exposed-sorts-2037469-1.patch

projects[views_autocomplete_filters][version] = 1.1
projects[views_autocomplete_filters][subdir] = contrib
projects[views_autocomplete_filters][patch][2277453] = http://drupal.org/files/issues/ViewsAutocompleteFilters-no_results_on_some_environments-2277453-1.patch
projects[views_autocomplete_filters][patch][2374709] = http://www.drupal.org/files/issues/views_autocomplete_filters-cache-2374709-2.patch
projects[views_autocomplete_filters][patch][2317351] = http://www.drupal.org/files/issues/views_autocomplete_filters-content-pane-2317351-4.patch

projects[views_bulk_operations][version] = 3.2
projects[views_bulk_operations][subdir] = contrib
projects[views_bulk_operations][patch][2192775] = http://drupal.org/files/issues/views-bulk-operations-2192775-1_0.patch

; The Usual Suspects

projects[pathauto][version] = 1.2
projects[pathauto][subdir] = contrib
projects[pathauto][patch][936222] = http://drupal.org/files/issues/pathauto-persist-936222-195-pathauto-state.patch

projects[token][version] = 1.5
projects[token][subdir] = contrib

projects[entity][version] = 1.6
projects[entity][subdir] = contrib

projects[libraries][version] = 2.2
projects[libraries][subdir] = contrib

projects[transliteration][version] = 3.2
projects[transliteration][subdir] = contrib

; Field modules

projects[date][version] = 2.8
projects[date][subdir] = contrib

projects[entityreference][version] = 1.1
projects[entityreference][subdir] = contrib

projects[field_group][version] = 1.4
projects[field_group][subdir] = contrib

projects[link][version] = 1.3
projects[link][subdir] = contrib

; Harness the Power of Features and Apps with Default Content

projects[apps][version] = 1.0-beta20
projects[apps][subdir] = contrib
projects[apps][patch][2430915] = https://www.drupal.org/files/issues/apps-drush-default-apps-2430915-1.patch

projects[features][version] = 2.3
projects[features][subdir] = contrib

projects[strongarm][version] = 2.0
projects[strongarm][subdir] = contrib

projects[defaultconfig][version] = 1.0-alpha9
projects[defaultconfig][subdir] = contrib
projects[defaultconfig][patch][2042799] = http://drupal.org/files/default_config_delete_only_if_overriden.patch
projects[defaultconfig][patch][2043307] = http://drupal.org/files/defaultconfig_include_features_file.patch
projects[defaultconfig][patch][2008178] = http://drupal.org/files/defaultconfig-rebuild-filters-2008178-4_0.patch
projects[defaultconfig][patch][1861054] = http://drupal.org/files/fix-defaultconfig_rebuild_all.patch

projects[defaultcontent][version] = 1.0-alpha9
projects[defaultcontent][subdir] = contrib
projects[defaultcontent][patch][1754428] = http://drupal.org/files/1754428-allow-node-export-alter.patch
projects[defaultcontent][patch][1757782] = http://drupal.org/files/1757782-cannot-import-menu-hierarchy-8.patch

projects[migrate][version] = "2.7"
projects[migrate][type] = "module"
projects[migrate][subdir] = "contrib"

projects[migrate_extras][version] = "2.5"
projects[migrate_extras][type] = "module"
projects[migrate_extras][subdir] = "contrib"

; Recommended Modules
projects[devel][version] = 1.5
projects[devel][subdir] = contrib

projects[distro_update][version] = 1.0-beta4
projects[distro_update][subdir] = contrib

projects[features_override][version] = 2.0-rc2
projects[features_override][subdir] = contrib

projects[uuid][version] = 1.0-alpha6
projects[uuid][subdir] = contrib
