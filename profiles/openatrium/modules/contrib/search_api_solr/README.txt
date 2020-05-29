Solr search
-----------

This module provides an implementation of the Search API which uses an Apache
Solr search server for indexing and searching. You can find detailed
instructions for setting up Solr in the module's handbook [1].

[1] https://www.drupal.org/node/1999280

Supported optional features
---------------------------

All Search API datatypes are supported by using appropriate Solr datatypes for
indexing them. By default, "String"/"URI" and "Integer"/"Duration" are defined
equivalently. However, through manual configuration of the used schema.xml this
can be changed arbitrarily. Using your own Solr extensions is thereby also
possible.

The "direct" parse mode for queries will result in the keys being directly used
as the query to Solr. For details about Lucene's query syntax, see [2]. There
are also some Solr additions to this, listed at [3]. Note however that, by
default, this module uses the dismax query handler, so searches like
"field:value" won't work with the "direct" mode.

[2] http://lucene.apache.org/java/2_9_1/queryparsersyntax.html
[3] http://wiki.apache.org/solr/SolrQuerySyntax

Regarding third-party features, the following are supported:

- search_api_autocomplete
  Introduced by module: search_api_autocomplete
  Lets you add autocompletion capabilities to search forms on the site. (See
  also "Hidden variables" below for Solr-specific customization.)
- search_api_facets
  Introduced by module: search_api_facetapi
  Allows you to create facetted searches for dynamically filtering search
  results.
- search_api_facets_operator_or
  Introduced by module: search_api_facetapi
  Allows the creation of OR facets.
- search_api_mlt
  Introduced by module: search_api_views
  Lets you display items that are similar to a given one. Use, e.g., to create
  a "More like this" block for node pages.
  NOTE: Due to a regression in Solr itself, "More like this" doesn't work with
  integer and float fields in Solr 4 versions lower than 4.6. As a work-around,
  you can index the fields (or copies of them) as string values. See [4] for
  details.
  Also, MLT with date fields isn't currently supported at all for any version.
- search_api_multi
  Introduced by module: search_api_multi
  Allows you to search multiple indexes at once, as long as they are on the same
  server. You can use this to let users simultaneously search all content on the
  site – nodes, comments, user profiles, etc.
- search_api_spellcheck
  Introduced by module: search_api_spellcheck
  Gives the option to display automatic spellchecking for searches.
- search_api_data_type_location
  Introduced by module: search_api_location
  Lets you index, filter and sort on location fields. Note, however, that only
  single-valued fields are currently supported for Solr 3.x.
- search_api_grouping
  Introduced by module: search_api_grouping [5]
  Lets you group search results based on indexed fields. For further information
  see the FieldCollapsing documentation in the solr wiki [6].

If you feel some service option is missing, or have other ideas for improving
this implementation, please file a feature request in the project's issue queue,
at [7].

[4] https://drupal.org/node/2004596
[5] https://drupal.org/sandbox/daspeter/1783280
[6] http://wiki.apache.org/solr/FieldCollapsing
[7] https://drupal.org/project/issues/search_api_solr

Specifics
---------

Please consider that, since Solr handles tokenizing, stemming and other
preprocessing tasks, activating any preprocessors in a search index' settings is
usually not needed or even cumbersome. If you are adding an index to a Solr
server you should therefore then disable all processors which handle such
classic preprocessing tasks. Enabling the HTML filter can be useful, though, as
the default config files included in this module don't handle stripping out HTML
tags.

Clean field identifiers:
  If your Solr server was created in a module version prior to 1.2, you will get
  the option to switch the server to "Clean field identifiers" (which is default
  for all new servers). This will change the Solr field names used for all
  fields whose Search API identifiers contain a colon (i.e., all nested fields)
  to support some advanced functionality, like sorting by distance, for which
  Solr is buggy when using field names with colons.
  The only downside of this change is that the data in Solr for these fields
  will become invalid, so all indexes on the server which contain such fields
  will be scheduled for re-indexing. (If you don't want to search on incomplete
  data until the re-indexing is finished, you can additionally manually clear
  the indexes, on their Status tabs, to prevent this.)

Hidden variables
----------------

- search_api_solr_autocomplete_max_occurrences (default: 0.9)
  By default, keywords that occur in more than 90% of results are ignored for
  autocomplete suggestions. This setting lets you modify that behaviour by
  providing your own ratio. Use 1 or greater to use all suggestions.
- search_api_solr_index_prefix (default: '')
  By default, the index ID in the Solr server is the same as the index's machine
  name in Drupal. This setting will let you specify a prefix for the index IDs
  on this Drupal installation. Only use alphanumeric characters and underscores.
  Since changing the prefix makes the currently indexed data inaccessible, you
  should change this vairable only when no indexes are currently on any Solr
  servers.
- search_api_solr_index_prefix_INDEX_ID (default: '')
  Same as above, but a per-index prefix. Use the index's machine name as
  INDEX_ID in the variable name. Per-index prefixing is done before the global
  prefix is added, so the global prefix will come first in the final name:
  (GLOBAL_PREFIX)(INDEX_PREFIX)(INDEX_ID)
  The same rules as above apply for setting the prefix.
- search_api_solr_http_get_max_length (default: 4000)
  The maximum number of bytes that can be handled as an HTTP GET query when
  HTTP method is AUTO. Typically Solr can handle up to 65355 bytes, but Tomcat
  and Jetty will error at slightly less than 4096 bytes.
- search_api_solr_cron_action (default: "spellcheck")
  The Search API Solr Search module can automatically execute some upkeep
  operations daily during cron runs. This variable determines what particular
  operation is carried out.
  - spellcheck: The "default" spellcheck dictionary used by Solr will be rebuilt
  so that spellchecking reflects the latest index state.
  - optimize: An "optimize" operation [8] is executed on the Solr server. As a
  result of this, all spellcheck dictionaries (that have "buildOnOptimize" set
  to "true") will be rebuilt, too.
  - none: No action is executed.
  If an unknown setting is encountered, it is interpreted as "none".
- search_api_solr_site_hash (default: random)
  A unique hash specific to the local site, created the first time it is needed.
  Only change this if you want to display another server's results and you know
  what you are doing. Old indexed items will be lost when the hash is changed
  and all items will have to be reindexed. Can only contain alphanumeric
  characters.
- search_api_solr_highlight_prefix (default: "tm_")
  The prefix of Solr fields for which field-level highlighting will be enabled.
  Since the prefix of fields is used to determine the field type (by default),
  this lets you enable highlighting for other field types. By default,
  highlighting will be possible for all fulltext fields.
- search_api_solr_connection_class (default: "SearchApiSolrConnection")
  The connection class to use for connecting to Solr. Needs to implement
  SearchApiSolrConnectionInterface.

[8] http://wiki.apache.org/solr/UpdateXmlMessages#A.22commit.22_and_.22optimize.22

Customizing your Solr server
----------------------------

The schema.xml and solrconfig.xml files contain extensive comments on how to
add additional features or modify behaviour, e.g., for adding a language-
specific stemmer or a stopword list.
If you are interested in further customizing your Solr server to your needs,
see the Solr wiki at [9] for documentation. When editing the schema.xml and
solrconfig.xml files, please only edit the copies in the Solr configuration
directory, not directly the ones provided with this module.

[9] http://wiki.apache.org/solr/

You'll have to restart your Solr server after making such changes, for them to
take effect.

Developers
----------

The SearchApiSolrService class has a few custom extensions, documented with its
code. Methods of note are deleteItems(), which treats the first argument
differently in certain cases, and the methods at the end of service.inc.

Also, when requesting facets with a search, you can use the custom
"solr_facet_query" key in the facet options to pass an array of facet queries to
Solr, which should be used instead of the default "facet.field" parameter. The
facet queries will automatically have "FIELD:" prepended to them. The returned
facets will have an additional "solr_facet_query" key in addition to "filter"
and "count", to spot them more easily.
