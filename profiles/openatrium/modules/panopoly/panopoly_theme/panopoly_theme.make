; Panopoly Theme Makefile

api = 2
core = 7.x

; Summon the Power of Respond.js

projects[respondjs][version] = 1.1
projects[respondjs][subdir] = contrib

libraries[respondjs][download][type] = get
libraries[respondjs][download][url] = https://github.com/scottjehl/Respond/tarball/master

; Bundle a Few Panopoly Approved Themes

projects[responsive_bartik][version] = 1.x-dev
projects[responsive_bartik][type] = theme
projects[responsive_bartik][download][type] = git
projects[responsive_bartik][download][revision] = 194c16b
projects[responsive_bartik][download][branch] = 7.x-1.x
projects[responsive_bartik][patch][1966198] = http://drupal.org/files/1966198-remove-auto-width.patch

; projects[radix][version] = 1.x-dev
; projects[radix][type] = theme
; projects[radix][download][type] = git
; projects[radix][download][revision] = b873330
; projects[radix][download][branch] = 7.x-1.x
