<?php
/**
 * @file
 * opensanmateo_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function opensanmateo_search_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function opensanmateo_search_default_search_api_index() {
  $items = array();
  $items['san_mateo_content_index'] = entity_import('search_api_index', '{
    "name" : "San Mateo Content Index",
    "machine_name" : "san_mateo_content_index",
    "description" : null,
    "server" : "san_mateo_solr_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "url" : { "type" : "uri" },
        "field_quick_search" : { "type" : "list\\u003Ctext\\u003E", "boost" : "5.0" },
        "field_event_calendar" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "search_api_multi_aggregation_1" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_3" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_2" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_4" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_5" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_6" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_7" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_8" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_9" : { "type" : "list\\u003Cdate\\u003E" },
        "search_api_multi_aggregation_10" : { "type" : "list\\u003Cdate\\u003E" },
        "search_api_multi_aggregation_11" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_12" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_13" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_14" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_15" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_16" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_17" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_multi_aggregation_18" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_site_hash" : { "type" : "uri" },
        "search_api_site_id" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "field_subject:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_sub_type:name" : { "type" : "text" },
        "field_topic:name" : { "type" : "string" },
        "field_event_calendar:name" : { "type" : "text" },
        "field_event_date:value" : { "type" : "date" },
        "field_event_date:value2" : { "type" : "date" },
        "field_event_type:name" : { "type" : "text" },
        "field_address:locality" : { "type" : "string" },
        "field_thumbnail_image:file:url" : { "type" : "string" },
        "field_thumbnail_image:file:field_file_image_alt_text" : { "type" : "string" },
        "field_thumbnail_image:file:field_file_image_title_text" : { "type" : "string" },
        "field_location_address:field_address:postal_code" : { "type" : "list\\u003Cstring\\u003E" }
      },
      "data_alter_callbacks" : {
        "site_index" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_multi_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_multi_aggregation_1" : {
                "name" : "Aggregated Teaser",
                "fields" : [ "field_blog_teaser", "field_summary", "body:summary" ],
                "description" : "A text aggregation of the following fields: Teaser, Summary, The main body text \\u00bb Summary."
              },
              "search_api_multi_aggregation_3" : {
                "name" : "Aggregated Author",
                "fields" : [ "author" ],
                "description" : "A text aggregation of the following fields: Author."
              },
              "search_api_multi_aggregation_2" : {
                "name" : "Aggregated Thumbnail",
                "fields" : [ "field_thumbnail_image:file:url" ],
                "description" : "A text aggregation of the following fields: Thumbnail Image \\u00bb The image file. \\u00bb URL."
              },
              "search_api_multi_aggregation_4" : {
                "name" : "Aggregated State",
                "fields" : [
                  "field_address:administrative_area",
                  "field_location_address:field_address:administrative_area"
                ],
                "description" : "A text aggregation of the following fields: Address \\u00bb Administrative area (i.e. State \\/ Province), Address \\u00bb Address \\u00bb Administrative area (i.e. State \\/ Province)."
              },
              "search_api_multi_aggregation_5" : {
                "name" : "Aggregated Postal",
                "fields" : [
                  "field_address:postal_code",
                  "field_location_address:field_address:postal_code"
                ],
                "description" : "A text aggregation of the following fields: Address \\u00bb Postal code, Address \\u00bb Address \\u00bb Postal code."
              },
              "search_api_multi_aggregation_6" : {
                "name" : "Aggregated Thoroughfare",
                "fields" : [
                  "field_address:thoroughfare",
                  "field_location_address:field_address:thoroughfare"
                ],
                "description" : "A text aggregation of the following fields: Address \\u00bb Thoroughfare (i.e. Street address), Address \\u00bb Address \\u00bb Thoroughfare (i.e. Street address)."
              },
              "search_api_multi_aggregation_7" : {
                "name" : "City",
                "fields" : [
                  "field_address:locality",
                  "field_location_address:field_address:locality"
                ],
                "description" : "A text aggregation of the following fields: Address \\u00bb Locality (i.e. City), Address \\u00bb Address \\u00bb Locality (i.e. City)."
              },
              "search_api_multi_aggregation_8" : {
                "name" : "Terms",
                "fields" : [
                  "field_subject:name",
                  "field_sub_type:name",
                  "field_event_calendar:name",
                  "field_event_type:name"
                  "field_topic:name"
                ],
                "description" : "A text aggregation of the following fields: Subject \\u00bb Name, Sub Type \\u00bb Name, Calendar \\u00bb Name, Event Type \\u00bb Name."
              },
              "search_api_multi_aggregation_9" : {
                "name" : "Aggregated Start Date",
                "fields" : [ "field_event_date:value" ],
                "description" : "A text aggregation of the following fields: Date \\u00bb Start date."
              },
              "search_api_multi_aggregation_10" : {
                "name" : "Aggregated End Date",
                "fields" : [ "field_event_date:value2" ],
                "description" : "A text aggregation of the following fields: Date \\u00bb End date."
              },
              "search_api_multi_aggregation_11" : {
                "name" : "Aggregated Sub Type",
                "fields" : [ "field_sub_type:name" ],
                "description" : "A text aggregation of the following fields: Sub Type \\u00bb Name."
              },
              "search_api_multi_aggregation_12" : {
                "name" : "Aggregated Event Type",
                "fields" : [ "field_event_type:name" ],
                "description" : "A text aggregation of the following fields: Event Type \\u00bb Name."
              },
              "search_api_multi_aggregation_13" : {
                "name" : "Aggregated Calendar",
                "fields" : [ "field_event_calendar:name" ],
                "description" : "A text aggregation of the following fields: Calendar \\u00bb Name."
              },
              "search_api_multi_aggregation_14" : {
                "name" : "Aggregated Subject",
                "fields" : [ "field_subject:name" ],
                "description" : "A text aggregation of the following fields: Subject \\u00bb Name."
              },
              "search_api_multi_aggregation_15" : {
                "name" : "Aggregated Thumbnail Title",
                "fields" : [ "field_thumbnail_image:file:field_file_image_title_text" ],
                "description" : "A text aggregation of the following fields: Thumbnail Image \\u00bb The image file. \\u00bb Title Text."
              },
              "search_api_multi_aggregation_16" : {
                "name" : "Aggregated Thumbnail ALt",
                "fields" : [ "field_thumbnail_image:file:field_file_image_alt_text" ],
                "description" : "A text aggregation of the following fields: Thumbnail Image \\u00bb The image file. \\u00bb Alt Text."
              },
              "search_api_multi_aggregation_17" : {
                "name" : "Aggregated Premise",
                "fields" : [
                  "field_address:premise",
                  "field_location_address:field_address:premise"
                ],
                "description" : "A text aggregation of the following fields: Address \\u00bb Premise (i.e. Apartment \\/ Suite number), Address \\u00bb Address \\u00bb Premise (i.e. Apartment \\/ Suite number)."
              },
              "search_api_multi_aggregation_18" : {
                "name" : "aggregated Release Date",
                "fields" : [ "field_release_date" ],
                "description" : "A text aggregation of the following fields: Release Date."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['san_mateo_file_index'] = entity_import('search_api_index', '{
    "name" : "San Mateo File Index",
    "machine_name" : "san_mateo_file_index",
    "description" : null,
    "server" : "san_mateo_solr_server",
    "item_type" : "file",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "fid" : { "type" : "integer" },
        "name" : { "type" : "string" },
        "mime" : { "type" : "string" },
        "url" : { "type" : "string" },
        "field_summary" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "search_api_multi_aggregation_1" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_multi_aggregation_2" : { "type" : "list\\u003Ctext\\u003E" },
        "search_api_site_hash" : { "type" : "string" },
        "search_api_site_id" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "site_index" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_multi_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_multi_aggregation_1" : {
                "name" : "Description",
                "type" : "fulltext",
                "fields" : [ "field_summary" ],
                "description" : "A Fulltext aggregation of the following fields: Summary."
              },
              "search_api_multi_aggregation_2" : {
                "name" : "Subject",
                "type" : "fulltext",
                "fields" : [ "field_subject:name" ],
                "description" : "A Fulltext aggregation of the following fields: Subject \\u00bb Name."
              }
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "teaser" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "field_summary" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_summary" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_summary" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_summary" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['san_mateo_quick_search_index'] = entity_import('search_api_index', '{
    "name" : "San Mateo Quick Search Index",
    "machine_name" : "san_mateo_quick_search_index",
    "description" : null,
    "server" : "san_mateo_solr_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "string" },
        "url" : { "type" : "uri" },
        "field_quick_search" : { "type" : "list\\u003Ctext\\u003E", "boost" : "21.0" },
        "search_api_language" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "site_index" : { "status" : 0, "weight" : "-50", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_multi_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_quick_search" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_quick_search" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_quick_search" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_quick_search" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function opensanmateo_search_default_search_api_server() {
  $items = array();
  $items['san_mateo_solr_server'] = entity_import('search_api_server', '{
    "name" : "San Mateo Solr Server",
    "machine_name" : "san_mateo_solr_server",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "scheme" : "http",
      "host" : "solrdev.p2devcloud.com",
      "port" : "8080",
      "path" : "\\/solr-sanmateo.p2devcloud.com",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 1,
      "highlight_data" : 0,
      "http_method" : "POST"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
