; Panopoly Search Makefile

api = 2
core = 7.x

; Search API and Facet API Modules

projects[facetapi][version] = 1.3
projects[facetapi][subdir] = contrib

projects[search_api][version] = 1.4
projects[search_api][subdir] = contrib

projects[search_api_solr][version] = 1.0-rc3
projects[search_api_solr][subdir] = contrib
projects[search_api_solr][patch][1407282] = http://drupal.org/files/1407282-variable_solr_connection_class-37.patch

projects[search_api_db][version] = 1.0-beta4
projects[search_api_db][subdir] = contrib

; Solr PHP Client Library

libraries[SolrPhpClient][download][type] = get
libraries[SolrPhpClient][download][url] = http://solr-php-client.googlecode.com/files/SolrPhpClient.r60.2011-05-04.zip
