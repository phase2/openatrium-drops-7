; Panopoly Admin Makefile

api = 2
core = 7.x

; UX/UI Improvements

projects[backports][version] = 1.0-alpha1
projects[backports][subdir] = contrib

projects[module_filter][version] = 1.7
projects[module_filter][subdir] = contrib

projects[simplified_menu_admin][version] = 1.0-beta2
projects[simplified_menu_admin][subdir] = contrib

projects[date_popup_authored][version] = 1.1
projects[date_popup_authored][subdir] = contrib

projects[admin_views][version] = 1.1
projects[admin_views][subdir] = contrib

projects[save_draft][version] = 1.4
projects[save_draft][subdir] = contrib

; Admin Toolbar Modules

projects[admin][version] = 2.0-beta3
projects[admin][subdir] = contrib
projects[admin][patch][1334804] = http://drupal.org/files/1334804-admin-jquery-updated-6.patch

projects[navbar][version] = 1.0-alpha3
projects[navbar][subdir] = contrib
projects[navbar][patch][1875254] = http://drupal.org/files/navbar_has_mismatching_closing_tag_1875254_1.patch

projects[admin_menu][version] = 3.0-rc3
projects[admin_menu][subdir] = contrib

projects[jquery_update][version] = 2.3
projects[jquery_update][subdir] = contrib
