api = 2
core = 7.x

; MAKE file for Open Atrium 2 using Drush 5 or earlier

; Drush 5 parses bottom-up, so OA needs to come before Panopoly
includes[] = oa-base-dev.make
includes[] = panopoly.make
