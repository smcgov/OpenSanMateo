<?php
/**
 * Class for caching/storing URLs/links in a D7's Database.
 *
 * @package phpcrawl
 * @internal
 */
class PHPCrawlerD7URLCache extends PHPCrawlerURLCacheBase
{
  protected $table = false;
  
  protected $crawler_id = false;
  
  /**
   * Initiates an D7-URL-cache.
   *
   * @param string $file            The D7-fiel to use.
   * @param bool   $create_tables   Defines whether all necessary tables should be created
   */
  public function __construct($table, $crawler_id)
  {
    $this->table = $table;
    $this->crawler_id = $crawler_id;
  }
  
  public function getUrlCount()
  {
    $result = db_query("SELECT count(id) AS sum FROM {" . $this->table . "} WHERE processed = 0 AND crawler_id = '" . $this->crawler_id . "';");
    return $result->fetchField();
  }
  
  /**
   * Returns the next URL from the cache that should be crawled.
   *
   * @return PhpCrawlerURLDescriptor An PhpCrawlerURLDescriptor or NULL if currently no
   *                                 URL to process.
   */
  public function getNextUrl()
  {
// drupal_set_message('<pre>PHPCrawlerD7URLCache::getNextUrl ' . print_r('', 1) . '</pre>');
    PHPCrawlerBenchmark::start("fetching_next_url_from_sqlcache"); 
    
    // Get row with max priority-level
//     $max_priority_level = $this->conn->query("SELECT max(priority_level) AS max_priority_level FROM " . $this->table . " WHERE in_process = 0 AND processed = 0 AND crawler_id = '" . $this->crawler_id . "';")->fetchField();
    $result = db_query("SELECT max(priority_level) AS max_priority_level FROM {" . $this->table . "} WHERE in_process = 0 AND processed = 0 AND crawler_id = '" . $this->crawler_id . "';");
    $max_priority_level = $result->fetchField();
    
    if ($max_priority_level == null) 
    {
      return null;
    }
    
// drupal_set_message('<pre>PHPCrawlerD7URLCache::getNextUrl ' . print_r('inside', 1) . '</pre>');

//     $row = $this->conn->query("SELECT * FROM " . $this->table . " WHERE priority_level = ".$max_priority_level." AND in_process = 0 AND processed = 0 AND crawler_id = '" . $this->crawler_id . "';")->fetchAssoc();
    $result = db_query("SELECT * FROM {" . $this->table . "} WHERE priority_level = ".$max_priority_level." AND in_process = 0 AND processed = 0 AND crawler_id = '" . $this->crawler_id . "';");
    $row = $result->fetchAssoc();
     
    // Update row (set in process-flag)
//     $this->conn->query("UPDATE " . $this->table . " SET in_process = 1 WHERE id = ".$row["id"].";");
    
    db_update($this->table)
      ->fields(array('in_process' => 1,))
      ->condition('id', $row['id'], '=')
      ->execute();
    
    PHPCrawlerBenchmark::stop("fetching_next_url_from_sqlcache");
     
    // Return URL
    return new PHPCrawlerURLDescriptor($row["url_rebuild"], $row["link_raw"], $row["linkcode"], $row["linktext"], $row["refering_url"]);
  }
  
  /**
   * Has no function in this class
   */
  public function getAllURLs()
  {
// die('getAllURLs');
  }
  
  /**
   * Removes all URLs and all priority-rules from the URL-cache.
   */
  public function clear()
  {
// die('clear');
// drupal_set_message('<pre>PHPCrawlerD7URLCache::clear ' . print_r('', 1) . '</pre>');
//     $this->conn->query("DELETE FROM " . $this->table . " WHERE crawler_id = '" . $this->crawler_id . "';");
    
    db_delete($this->table)
      ->condition('crawler_id', $this->crawler_id)
      ->execute();
  }
  
  /**
   * Adds an URL to the url-cache
   *
   * @param PHPCrawlerURLDescriptor $UrlDescriptor      
   */
  public function addURL(PHPCrawlerURLDescriptor $UrlDescriptor)
  {
// drupal_set_message('<pre>PHPCrawlerD7URLCache::addURL ' . print_r($UrlDescriptor, 1) . '</pre>');
    if ($UrlDescriptor == null) return;
    
    // Hash of the URL
    $map_key = md5($UrlDescriptor->url_rebuild);
    
    // Get priority of URL
    $priority_level = $this->getUrlPriority($UrlDescriptor->url_rebuild);
        
    try
    {
      db_insert($this->table)
        ->fields(array(
          'crawler_id' => $this->crawler_id,
          'priority_level' => $priority_level,
          'distinct_hash' => $map_key,
          'link_raw' => !!$UrlDescriptor->link_raw ? $UrlDescriptor->link_raw : '',
          'linkcode' => !!$UrlDescriptor->linkcode ? $UrlDescriptor->linkcode : '',
          'linktext' => !!$UrlDescriptor->linktext ? $UrlDescriptor->linktext : '',
          'refering_url' => !!$UrlDescriptor->refering_url ? $UrlDescriptor->refering_url : '',
          'url_rebuild' => !!$UrlDescriptor->url_rebuild ? $UrlDescriptor->url_rebuild : '',
          'is_redirect_url' => !!$UrlDescriptor->is_redirect_url ? 1 : 0,
        ))
        ->execute();
    }
    catch (Exception $e)
    {
      drupal_set_message('PHPCrawlerD7URLCache::addURL ERROR: ' . $e->getMessage(), 'error');
    }
  }
  
  /**
   * Adds an bunch of URLs to the url-cache
   *
   * @param array $urls  A numeric array containing the URLs as PHPCrawlerURLDescriptor-objects
   */
  public function addURLs($urls)
  {
// die('addURLs');
// drupal_set_message('<pre>PHPCrawlerD7URLCache::addURLs ' . print_r($urls, 1) . '</pre>');
    PHPCrawlerBenchmark::start("adding_urls_to_sqlcache"); 
    
    
    $cnt = count($urls);
    for ($x=0; $x<$cnt; $x++)
    {
      if ($urls[$x] != null)
      {
        $this->addURL($urls[$x]);
      }
      
    }
    
    PHPCrawlerBenchmark::stop("adding_urls_to_sqlcache"); 
  }
  
  /**
   * Marks the given URL in the cache as "followed"
   *
   * @param PHPCrawlerURLDescriptor $UrlDescriptor
   */
  public function markUrlAsFollowed(PHPCrawlerURLDescriptor $UrlDescriptor)
  {
// die('markUrlAsFollowed');
// drupal_set_message('<pre>PHPCrawlerD7URLCache::markUrlAsFollowed ' . print_r($UrlDescriptor, 1) . '</pre>');
    PHPCrawlerBenchmark::start("marking_url_as_followed");
//     $hash = md5($UrlDescriptor->url_rebuild);
//     $this->conn->query("UPDATE " . $this->table . " SET processed = 1, in_process = 0 WHERE distinct_hash = '".$hash."' AND crawler_id = '" . $this->crawler_id . "';");
    
    db_update($this->table)
      ->fields(array(
        'in_process' => 0,
        'processed' => 1,
      ))
      ->condition('distinct_hash', md5($UrlDescriptor->url_rebuild), '=')
      ->condition('crawler_id', $this->crawler_id, '=')
      ->execute();
      
    PHPCrawlerBenchmark::stop("marking_url_as_followed"); 
  }
  
  /**
   * Checks whether there are URLs left in the cache that should be processed or not.
   *
   * @return bool
   */
  public function containsURLs()
  {
// drupal_set_message('<pre>PHPCrawlerD7URLCache::containsURLs ' . print_r('', 1) . '</pre>');
    PHPCrawlerBenchmark::start("checking_for_urls_in_cache");
    
//     $has_columns = $this->conn->query("SELECT id FROM " . $this->table . " WHERE (processed = 0 OR in_process = 1) AND crawler_id = '" . $this->crawler_id . "' LIMIT 1;")->fetchField();
    $result = db_query("SELECT id FROM {" . $this->table . "} WHERE (processed = 0 OR in_process = 1) AND crawler_id = '" . $this->crawler_id . "' LIMIT 1;");
    $has_columns = $result->fetchField();
    
    PHPCrawlerBenchmark::stop("checking_for_urls_in_cache");
    
    return !!$has_columns;
  }
  
  /**
   * Cleans/purges the URL-cache from inconsistent entries.
   */
  public function purgeCache()
  {
// drupal_set_message('<pre>PHPCrawlerD7URLCache::purgeCache ' . print_r('', 1) . '</pre>');
    // Set "in_process" to 0 for all URLs
//     $this->conn->query("UPDATE " . $this->table . " SET in_process = 0 WHERE crawler_id = '" . $this->crawler_id . "';");
    
    db_update($this->table)
      ->fields(array('in_process' => 0,))
      ->condition('crawler_id', $this->crawler_id, '=')
      ->execute();
  }
  
  /**
   * Cleans up the cache after is it not needed anymore.
   */
  public function cleanup()
  {
// die('cleanup');
// drupal_set_message('<pre>PHPCrawlerD7URLCache::cleanup ' . print_r('', 1) . '</pre>');
    $this->clear();
  }
}