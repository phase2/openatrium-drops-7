; Panopoly Core Makefile

api = 2
core = 7.x

; Panels and Chaos Tools Magic

projects[ctools][version] = 1.4
projects[ctools][subdir] = contrib

projects[panels][version] = 3.4
projects[panels][subdir] = contrib

projects[panels_breadcrumbs][version] = 2.1
projects[panels_breadcrumbs][subdir] = contrib

projects[panelizer][version] = 3.1
projects[panelizer][subdir] = contrib

projects[fieldable_panels_panes][version] = 1.5
projects[fieldable_panels_panes][subdir] = contrib

projects[pm_existing_pages][version] = 1.4
projects[pm_existing_pages][subdir] = contrib

projects[fape][version] = 1.2
projects[fape][subdir] = contrib

; Views Magic

projects[views][version] = 3.8
projects[views][subdir] = contrib
projects[views][patch][2037469] = http://drupal.org/files/views-exposed-sorts-2037469-1.patch

projects[views_autocomplete_filters][version] = 1.1
projects[views_autocomplete_filters][subdir] = contrib

projects[views_bulk_operations][version] = 3.2
projects[views_bulk_operations][subdir] = contrib

; The Usual Suspects

projects[pathauto][version] = 1.2
projects[pathauto][subdir] = contrib
projects[pathauto][patch][936222] = http://drupal.org/files/issues/pathauto-persist-936222-195-pathauto-state.patch

projects[token][version] = 1.5
projects[token][subdir] = contrib

projects[entity][version] = 1.5
projects[entity][subdir] = contrib

projects[libraries][version] = 2.2
projects[libraries][subdir] = contrib

; Field modules

projects[date][version] = 2.7
projects[date][subdir] = contrib

projects[entityreference][version] = 1.1
projects[entityreference][subdir] = contrib

projects[field_group][version] = 1.3
projects[field_group][subdir] = contrib

projects[link][version] = 1.2
projects[link][subdir] = contrib

; Harness the Power of Features and Apps with Default Content

projects[apps][version] = 1.x-dev
projects[apps][subdir] = contrib
projects[apps][download][type] = git
projects[apps][download][branch] = 7.x-1.x
projects[apps][download][revision] = b9d82b7
projects[apps][patch][1790902] = http://drupal.org/files/1790902.4-check-last-modified-existing.patch

projects[features][version] = 2.0
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

projects[migrate][version] = "2.5"
projects[migrate][type] = "module"
projects[migrate][subdir] = "contrib"

projects[migrate_extras][version] = "2.5"
projects[migrate_extras][type] = "module"
projects[migrate_extras][subdir] = "contrib"

; Recommended Modules
projects[devel][version] = 1.5
projects[devel][subdir] = contrib

projects[uuid][version] = 1.0-alpha5
projects[uuid][subdir] = contrib
