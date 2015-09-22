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
    }
    else {
      $node = new stdClass();
      $node->type = 'sitecrawler_page';
      node_object_prepare($node);
    }
    
    $node->title = 
      preg_match('#<head.*?<title>(.*?)</title>.*?</head>#is', $DocInfo->source, $matches)
      ? $matches[1]
      : $DocInfo->url;
      
    $node->language = LANGUAGE_NONE;

    $node->field_sitecrawler_url[$node->language][0]['title'] = $node->title;
    $node->field_sitecrawler_url[$node->language][0]['url'] = $DocInfo->url;

    $doc = new DOMDocument();
    // This line throws an error if there is malformed HTML. Use a source
    // validator to correct it. Ex:
    // * An unencoded ampersand
    // * An unexpected element inside another, like a <table> inside a <p>
    // * Multiple identical ID attributes on the same page.
    // * Invalid tags based on the specified Doctype.
    // The @ sign disables error reporting.
    @$doc->loadHTML($DocInfo->source);
    $doc->preserveWhiteSpace = FALSE;

    removeElementsByTagName('script', $doc);
    removeElementsByTagName('style', $doc);
    removeElementsByTagName('link', $doc);

    foreach($this->body_xpaths as $body_xpath) {
      $xpath = new DOMXpath($doc);
      // $body = $xpath->query('/html/body');
      // $body = $xpath->query('//div[@id="layout"]');
      $body = $xpath->query($body_xpath);
      if (!is_null($body)) {
        foreach ($body as $i => $element) {
          $node_body = trim($element->nodeValue);
          if (!empty($node_body)) {
            break 2;
          }
        }
      }
      else {
        watchdog('OpenSanMateo Site Crawler', 'No body content was found. Message: %message', array('%message' => 'This URL did not have body content: ' . $DocInfo->url));
      }
    }
    // This page doesn't have the selectors of a standard page. It's likely a
    // landing page or home page that doesn't follow the standard page content
    // xpath rule. Skip it.
    if (empty($node_body)) {
      return;
    }

    $node_body = mb_check_encoding($node_body, 'UTF-8') ? $node_body : utf8_encode($node_body);

    $node->body[$node->language][0]['value'] = $node_body;
    $node->body[$node->language][0]['summary'] = text_summary($node_body);
    // Filtered HTML doesn't allow script and style tags, etc.
    $node->body[$node->language][0]['format']  = 'filtered_html';
    
      
    // store the Drupal crawler ID from the opensanmateo_sitecrawler_sites table
    $node->field_sitecrawler_id[$node->language][0]['value'] = $this->crawler_id;
    
    // store the PHPCrawler ID for this pull of the site
    $node->field_sitecrawler_instance_id[$node->language][0]['value'] = $this->getCrawlerId();

    node_save($node);

    if ((bool) $nid) {
      $this->nodes_updated++;
    }
    else {
      $this->nodes_created++;
    }
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