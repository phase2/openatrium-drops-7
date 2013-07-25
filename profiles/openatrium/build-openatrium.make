api = 2
core = 7.x
; Include the definition for how to build Drupal core directly, including patches:
includes[] = drupal-org-core.make
; Download the OpenAtrium install profile and recursively build all its dependencies:
projects[openatrium][type] = profile
projects[openatrium][download][type] = git
projects[openatrium][download][branch] = 7.x-2.x
