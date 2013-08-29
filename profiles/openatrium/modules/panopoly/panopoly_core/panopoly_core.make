; Panopoly Core Makefile

api = 2
core = 7.x

; Panels and Chaos Tools Magic

projects[ctools][version] = 1.3
projects[ctools][subdir] = contrib
projects[ctools][patch][1925018] = http://drupal.org/files/ctools-1925018-61.patch

projects[panels][version] = 3.x-dev
projects[panels][subdir] = contrib
projects[panels][download][type] = git
projects[panels][download][revision] = 2bb470e
projects[panels][download][branch] = 7.x-3.x

projects[panels_breadcrumbs][version] = 2.1
projects[panels_breadcrumbs][subdir] = contrib

projects[panelizer][version] = 3.1
projects[panelizer][subdir] = contrib

projects[fieldable_panels_panes][version] = 1.x-dev
projects[fieldable_panels_panes][subdir] = contrib
projects[fieldable_panels_panes][download][type] = git
projects[fieldable_panels_panes][download][revision] = 3b9c8b6
projects[fieldable_panels_panes][download][branch] = 7.x-1.x

projects[pm_existing_pages][version] = 1.4
projects[pm_existing_pages][subdir] = contrib

projects[fape][version] = 1.x-dev
projects[fape][subdir] = contrib
projects[fape][download][type] = git
projects[fape][download][revision] = 1143ee2
projects[fape][download][branch] = 7.x-1.x

; Views Magic

projects[views][version] = 3.7
projects[views][subdir] = contrib

projects[views_autocomplete_filters][version] = 1.0
projects[views_autocomplete_filters][subdir] = contrib

projects[views_bulk_operations][version] = 3.1
projects[views_bulk_operations][subdir] = contrib

; The Usual Suspects

projects[pathauto][version] = 1.2
projects[pathauto][subdir] = contrib
projects[pathauto][patch][936222] = http://drupal.org/files/pathauto-persist-936222-130-pathauto-state.patch

projects[token][version] = 1.5
projects[token][subdir] = contrib

projects[entity][version] = 1.1
projects[entity][subdir] = contrib

projects[libraries][version] = 2.1
projects[libraries][subdir] = contrib

; Field modules

projects[date][version] = 2.6
projects[date][subdir] = contrib

projects[entityreference][version] = 1.0
projects[entityreference][subdir] = contrib

projects[field_group][version] = 1.1
projects[field_group][subdir] = contrib

projects[link][version] = 1.1
projects[link][subdir] = contrib

; Harness the Power of Features and Apps with Default Content

projects[apps][version] = 1.0-beta7
projects[apps][subdir] = contrib
projects[apps][patch][1790902] = http://drupal.org/files/1790902-check-last-modified-existing.patch

projects[features][version] = 2.0-rc1
projects[features][subdir] = contrib

projects[strongarm][version] = 2.0
projects[strongarm][subdir] = contrib

projects[defaultconfig][version] = 1.0-alpha9
projects[defaultconfig][subdir] = contrib

projects[defaultcontent][version] = 1.0-alpha9
projects[defaultcontent][subdir] = contrib
projects[defaultcontent][patch][1754428] = http://drupal.org/files/1754428-allow-node-export-alter.patch
projects[defaultcontent][patch][1757782] = http://drupal.org/files/1757782-cannot-import-menu-hierarchy-8.patch

; Recommended Modules
projects[devel][version] = 1.3
projects[devel][subdir] = contrib

projects[uuid][version] = 1.0-alpha5
projects[uuid][subdir] = contrib
