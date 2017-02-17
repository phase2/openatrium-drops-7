api = 2
core = 7.x

; MAKE file for Drupal core.  Used by the Drupal.org packager.

; Drupal Core
projects[drupal][type] = core
projects[drupal][version] = 7.54

; ***** Patches from Panopoly *******
; Bug with image styles on database update
projects[drupal][patch][1973278] = http://www.drupal.org/files/issues/image-accommodate_missing_definition-1973278-16.patch
; ***** End of Panopoly patches *****

; *********** PATCHES ************

; Patch for handling inherited profiles
projects[drupal][patch][1356276] = http://drupal.org/files/1356276-make-D7-21.patch

; Patch for fixing node_access across non-required Views relationships
projects[drupal][patch][1349080] = https://www.drupal.org/files/issues/1349080-195-d7-move-access-to-join-condition.patch

; Patch for simpletest
projects[drupal][patch][911354] = http://drupal.org/files/911354-drupal-profile-85.patch

; Patch to allow install profile enabling to enable dependencies correctly.
projects[drupal][patch][1093420] = http://drupal.org/files/1093420-22.patch

; Patch to prevent empty titles when menu_check_access called more than once
projects[drupal][patch][1697570] = http://drupal.org/files/drupal-menu_always_load_objects-1697570-5.patch

; Patch to move registry build so entity_get_info can be called during install.
projects[drupal][patch][1311820] = https://www.drupal.org/files/issues/1311820-drupal-registry_update-13.patch

; Make node access queries more performant
projects[drupal][patch][106721] = https://www.drupal.org/files/issues/drupal-106721-optimize_node_access_queries-115.patch

; Cache user grants.
projects[drupal][patch][2199001] = https://www.drupal.org/files/issues/node_access_grants-static-cache-11.patch

; Fix javascript error with angular
projects[drupal][patch][2492993] = https://www.drupal.org/files/issues/2492993-drupal-hash-1.patch

; Fixes sticky headers are not calculating the column widths properly.
projects[drupal][patch][2097081] = https://www.drupal.org/files/2097081-fix-sticky-header-column-width-7.x-6.patch

; Prevent Drupal from scanning node_module and bower_component directories in theme
projects[drupal][patch][2329453] = https://www.drupal.org/files/issues/ignore_front_end_vendor-2329453-111.patch

; Issues with "required, multiple" fields in forms.
projects[drupal][patch][980144] = https://www.drupal.org/files/issues/d7-issues_with_required-980144-76.patch
