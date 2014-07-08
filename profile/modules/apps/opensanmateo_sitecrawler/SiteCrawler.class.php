<?php

include_once('PHPCrawl_082_MODIFIED/libs/PHPCrawler.class.php');

class SiteCrawler extends PHPCrawler {
  protected $crawler_id = 0;
  protected $body_xpaths = array();
  
  public $nodes_created = 0;
  public $nodes_updated = 0;
  
  public $urls_processed = array();
  
  /**
   * Initiates a new crawler.
   */
  public function __construct($crawler_id, $body_xpaths) {
    $this->crawler_id = $crawler_id;
    $this->body_xpaths = $body_xpaths;
    if (empty($this->body_xpaths)) {
      $this->body_xpaths = array('/html/body');
    }

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


// drupal_set_message('<pre style="border: 1px solid red;">body_xpaths: ' . print_r($this->body_xpaths,1) . '</pre>');
    $doc = new DOMDocument();
    $doc->loadHTML($DocInfo->source);
    foreach($this->body_xpaths as $body_xpath) {
      $xpath = new DOMXpath($doc);
      // $body = $xpath->query('/html/body');
      // $body = $xpath->query('//div[@id="layout"]');
      $body = $xpath->query($body_xpath);
      if (!is_null($body)) {
        break;
      }
    }

    if (!is_null($body)) {
      foreach ($body as $i => $element) {
        $node_body = $element->nodeValue;
        if (!empty($node_body)) {
// drupal_set_message('<pre style="border: 1px solid black;">$body $element: ' . print_r($element->nodeValue,1) . '</pre>');
          break;
        }
      }
    }

    if (empty($node_body)) {
      $node_body = 
        preg_match('#<body.*?>(.*?)</body>#is', $DocInfo->source, $matches)
        && !empty($matches[1])
        ? $matches[1]
        : $DocInfo->source;
    }

    $node_body = mb_check_encoding($node_body, 'UTF-8') ? $node_body : utf8_encode($node_body);
    
    $node->body[$node->language][0]['value'] = $node_body;
    $node->body[$node->language][0]['summary'] = text_summary($node_body);
    $node->body[$node->language][0]['format']  = filter_default_format();
    
      
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
  
  
  /**
   * Returns summarizing report-information from the parent about the 
   * crawling-process after it has finished, adding in node creation and update 
   * statistics.
   *
   * @return PHPCrawlerProcessReport PHPCrawlerProcessReport-object containing process-summary-information
   * @section 1 Basic settings
   */
//   public function getProcessReport() {
//     $report = parent::getProcessReport();
//     $report->nodes_created = $this->nodes_created;
//     $report->nodes_updated = $this->nodes_updated;
//   }
  
}