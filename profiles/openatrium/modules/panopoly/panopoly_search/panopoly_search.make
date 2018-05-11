; Panopoly Search Makefile

api = 2
core = 7.x

; Search API and Facet API Modules

projects[facetapi][version] = 1.5
projects[facetapi][subdir] = contrib

projects[search_api][version] = 1.24
projects[search_api][subdir] = contrib

projects[search_api_solr][version] = 1.12
projects[search_api_solr][subdir] = contrib

projects[search_api_db][version] = 1.6
projects[search_api_db][subdir] = contrib
projects[search_api_db][patch][2855634] = https://www.drupal.org/files/issues/2855634-23--fix_update_7107_for_different_db.patch

; Solr PHP Client Library

libraries[SolrPhpClient][download][type] = get
libraries[SolrPhpClient][download][url] = https://github.com/PTCInc/solr-php-client/archive/master.zip
