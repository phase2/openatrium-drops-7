api = 2
core = 7.x

; MAKE file for Open Atrium 2 using Drush 6 or later

; Drush 6 parses top-down, so OA needs to come after Panopoly
includes[] = panopoly.make
includes[] = oa-base-dev.make
