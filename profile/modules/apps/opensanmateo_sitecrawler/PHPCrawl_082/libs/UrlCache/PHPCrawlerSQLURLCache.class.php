<?php
/**
 * Class for caching/storing URLs/links in a SQL-database-file.
 *
 * @package phpcrawl
 * @internal
 */
class PHPCrawlerSQLURLCache extends PHPCrawlerURLCacheBase
{
  protected $table = false;
  
  protected $conn = false;
  
  protected $crawler_id = false;
  
  /**
   * Initiates an SQL-URL-cache.
   *
   * @param string $file            The SQL-fiel to use.
   * @param bool   $create_tables   Defines whether all necessary tables should be created
   */
  public function __construct($conn, $table, $crawler_id)
  {
    $this->table = $table;
    $this->conn = $conn;
    $this->crawler_id = $crawler_id;
  }
  
  public function getUrlCount()
  {
    return $this->conn->query("SELECT count(id) AS sum FROM " . $this->table . " WHERE processed = 0 AND crawler_id = '" . $this->crawler_id . "';")->fetchField();
  }
  
  /**
   * Returns the next URL from the cache that should be crawled.
   *
   * @return PhpCrawlerURLDescriptor An PhpCrawlerURLDescriptor or NULL if currently no
   *                                 URL to process.
   */
  public function getNextUrl()
  {
    PHPCrawlerBenchmark::start("fetching_next_url_from_sqlcache"); 
    
    // Get row with max priority-level
    $max_priority_level = $this->conn->query("SELECT max(priority_level) AS max_priority_level FROM " . $this->table . " WHERE in_process = 0 AND processed = 0 AND crawler_id = '" . $this->crawler_id . "';")->fetchField();
    
    if ($max_priority_level == null) 
    {
      return null;
    }
    

    $row = $this->conn->query("SELECT * FROM " . $this->table . " WHERE priority_level = ".$max_priority_level." AND in_process = 0 AND processed = 0 AND crawler_id = '" . $this->crawler_id . "';")->fetchAssoc();
     
    // Update row (set in process-flag)
    $this->conn->query("UPDATE " . $this->table . " SET in_process = 1 WHERE id = ".$row["id"].";")
    
    PHPCrawlerBenchmark::stop("fetching_next_url_from_sqlcache");
     
    // Return URL
    return new PHPCrawlerURLDescriptor($row["url_rebuild"], $row["link_raw"], $row["linkcode"], $row["linktext"], $row["refering_url"]);
  }
  
  /**
   * Has no function in this class
   */
  public function getAllURLs()
  {
  }
  
  /**
   * Removes all URLs and all priority-rules from the URL-cache.
   */
  public function clear()
  {
    $this->conn->query("DELETE FROM " . $this->table . " WHERE crawler_id = '" . $this->crawler_id . "';");
  }
  
  /**
   * Adds an URL to the url-cache
   *
   * @param PHPCrawlerURLDescriptor $UrlDescriptor      
   */
  public function addURL(PHPCrawlerURLDescriptor $UrlDescriptor)
  {
    if ($UrlDescriptor == null) return;
    
    // Hash of the URL
    $map_key = md5($UrlDescriptor->url_rebuild);
    
    // Get priority of URL
    $priority_level = $this->getUrlPriority($UrlDescriptor->url_rebuild);
    
    $this->conn->query(
      "INSERT INTO " . $this->table
      . " ("
        . "crawler_id,"
        . "priority_level,"
        . "distinct_hash,"
        . "link_raw,"
        . "linkcode,"
        . "linktext,"
        . "refering_url,"
        . "url_rebuild,"
        . "is_redirect_url"
      . ") "
      . "VALUES"
      . " ("
        . "'" . $this->crawler_id . "',"
        . "'" . $priority_level . "',"
        . "'" . $map_key . "',"
        . "'" . $UrlDescriptor->link_raw . "',"
        . "'" . $UrlDescriptor->linkcode . "',"
        . "'" . $UrlDescriptor->linktext . "',"
        . "'" . $UrlDescriptor->refering_url . "',"
        . "'" . $UrlDescriptor->url_rebuild . "',"
        . "'" . $UrlDescriptor->is_redirect_url) . "'"
      . ");";
  }
  
  /**
   * Adds an bunch of URLs to the url-cache
   *
   * @param array $urls  A numeric array containing the URLs as PHPCrawlerURLDescriptor-objects
   */
  public function addURLs($urls)
  {
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
    PHPCrawlerBenchmark::start("marking_url_as_followes");
    $hash = md5($UrlDescriptor->url_rebuild);
    $this->conn->query("UPDATE " . $this->table . " SET processed = 1, in_process = 0 WHERE distinct_hash = '".$hash."' AND crawler_id = '" . $this->crawler_id . "';")
    PHPCrawlerBenchmark::stop("marking_url_as_followes"); 
  }
  
  /**
   * Checks whether there are URLs left in the cache that should be processed or not.
   *
   * @return bool
   */
  public function containsURLs()
  {
    PHPCrawlerBenchmark::start("checking_for_urls_in_cache");
    
    $has_columns = $this->conn->query("SELECT id FROM " . $this->table . " WHERE (processed = 0 OR in_process = 1) AND crawler_id = '" . $this->crawler_id . "' LIMIT 1;")->fetchField();
    
    PHPCrawlerBenchmark::stop("checking_for_urls_in_cache");
    
    return !!$has_columns;
  }
  
  /**
   * Cleans/purges the URL-cache from inconsistent entries.
   */
  public function purgeCache()
  {
    // Set "in_process" to 0 for all URLs
    $this->conn->query("UPDATE " . $this->table . " SET in_process = 0 WHERE crawler_id = '" . $this->crawler_id . "';")
  }
  
  /**
   * Cleans up the cache after is it not needed anymore.
   */
  public function cleanup()
  {
    $this->clear();
  }
}