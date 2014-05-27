<?php
/**
 * @file
 * opensanmateo_crawler.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function opensanmateo_crawler_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'opensanmateo_crawler';
  $feeds_importer->config = array(
    'name' => 'Opensanmateo Crawler Fetcher',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserHTML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => '//h1/text()',
          'xpathparser:1' => '//html/body/*',
        ),
        'rawXML' => array(
          'xpathparser:1' => 'xpathparser:1',
          'xpathparser:0' => 0,
        ),
        'context' => '//html',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsSelfNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_external_summary',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 2,
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'external_page',
      ),
    ),
    'content_type' => 'external_page',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['opensanmateo_crawler'] = $feeds_importer;

  return $export;
}
