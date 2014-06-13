<?php

include_once('PHPCrawl_082_MODIFIED/libs/PHPCrawler.class.php');

class SiteCrawler extends PHPCrawler {
  protected $crawler_id = 0;
  
  public $nodes_created = array();
  public $nodes_updated = array();
  
  public $urls_processed = array();
  
  /**
   * Initiates a new crawler.
   */
  public function __construct($crawler_id) {
    $this->crawler_id = $crawler_id;
    
    parent::__construct();
  }

  function handleDocumentInfo($DocInfo) {
    $this->urls_processed[$DocInfo->http_status_code][] = $DocInfo->url;
    
    if (200 != $DocInfo->http_status_code) {
      return;
    }
    
    $nid = db_select('field_data_field_sitecrawler_url', 'fdfsu')
      ->fields('fdfsu', array('entity_id'))
      ->condition('fdfsu.field_sitecrawler_url_url', $DocInfo->url)
      ->execute()
      ->fetchField();
  
    if (!!$nid) {
      $node = node_load($nid);
      $this->nodes_updated++;
    }
    else {
      $node = new stdClass();
      $node->type = 'sitecrawler_page';
      node_object_prepare($node);
      $this->nodes_created++;
    }
    
    $node->title = 
      preg_match('#<head.*?<title>(.*?)</title>.*?</head>#is', $DocInfo->source, $matches)
      ? $matches[1]
      : $DocInfo->url;
      
    $node->language = LANGUAGE_NONE;

    $node->field_sitecrawler_url[$node->language][0]['title'] = $node->title;
    $node->field_sitecrawler_url[$node->language][0]['url'] = $DocInfo->url;
      
//     $node->field_sitecrawler_summary[$node->language][0]['value'] = 
    $node->body = 
      preg_match('#<body.*?>(.*?)</body>#is', $DocInfo->source, $matches)
      ? $matches[1]
      : $DocInfo->source;
      
    // store the Drupal crawler ID from the opensanmateo_sitecrawler_sites table
    $node->field_sitecrawler_id[$node->language][0]['value'] = $this->crawler_id;
    
    // store the PHPCrawler ID for this pull of the site
    $node->field_sitecrawler_instance_id[$node->language][0]['value'] = $this->getCrawlerId();
  
    node_save($node);
    
    $this->{'nodes_' . (!!$nid ? 'updated' : 'created')}[$node->nid] = $node->title . ' :: ' . $DocInfo->url;
  }
  
  /**
   * Return present abort status.
   *
   * @return int NULL if the process hasn't been aborted yet, otherwise one of the PHPCrawlerAbortReasons::ABORTREASON-constants.
   */
  public function getCurrentAbortStatus() {
    $crawler_status = $this->CrawlerStatusHandler->getCrawlerStatus();
    return $crawler_status->abort_reason;
  }
  
  /**
   * Return present abort status.
   *
   * @return int NULL if the process hasn't been aborted yet, otherwise one of the PHPCrawlerAbortReasons::ABORTREASON-constants.
   */
  public function getPreviousAbortStatus() {
    $crawler_status = $this->CrawlerStatusHandler->getCrawlerStatus();
    return $crawler_status->previous_abort_reason;
  }
  
}