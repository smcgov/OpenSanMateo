<?php
/**
 * Class for storing/caching cookies in a SQL-db-file.
 *
 * @package phpcrawl
 * @internal
 */
class PHPCrawlerSQLCookieCache extends PHPCrawlerCookieCacheBase
{
  protected $table = false;
  
  protected $conn = false;
  
  protected $crawler_id = false;
  
  public function __construct($conn, $table, $crawler_id)
  {
    $this->table = $table;
    $this->conn = $conn;
    $this->crawler_id = $crawler_id;
  }
   
  /**
   * Adds a cookie to the cookie-cache.
   *
   * @param PHPCrawlerCookieDescriptor $Cookie The cookie to add.
   */
  public function addCookie(PHPCrawlerCookieDescriptor $Cookie)
  {
    /// NOTE: this needs to be an insert or update operation
    $this->conn->query(
      "INSERT INTO " . $this->table
      . " ("
        . "crawler_id,"
        . "cookie_hash,"
        . "source_domain,"
        . "source_url,"
        . "name,"
        . "value,"
        . "domain,"
        . "path,"
        . "expires,"
        . "expire_timestamp,"
        . "cookie_send_time"
      . ") "
      . "VALUES"
      . " ("
        . "'" . $this->crawler_id . "',"
        . "'" . md5($Cookie->domain."_".$Cookie->path."_".$Cookie->name) . "',"
        . "'" . $Cookie->source_domain . "',"
        . "'" . $Cookie->source_url . "',"
        . "'" . $Cookie->name . "',"
        . "'" . $Cookie->value . "',"
        . "'" . $Cookie->domain . "',"
        . "'" . $Cookie->path . "',"
        . "'" . $Cookie->expires . "',"
        . "'" . $Cookie->expire_timestamp . "',"
        . "'" . $Cookie->cookie_send_time . "'"
      . ");";
      
  }
  
  /**
   * Adds a bunch of cookies to the cookie-cache.
   *
   * @param array $cookies  Numeric array conatining the cookies to add as PHPCrawlerCookieDescriptor-objects
   */
  public function addCookies($cookies)
  {
    PHPCrawlerBenchmark::start("adding_cookies_to_cache");
    
    // err... why isn't this a foreach?
    for ($x=0; $x<count($cookies); $x++)
    {
      $this->addCookie($cookies[$x]);
    }
    
    PHPCrawlerBenchmark::stop("adding_cookies_to_cache");
  }
  
  /**
   * Returns all cookies from the cache that are adressed to the given URL
   *
   * @param string $target_url The target-URL
   * @return array  Numeric array conatining all matching cookies as PHPCrawlerCookieDescriptor-objects
   */
  public function getCookiesForUrl($target_url)
  {
    PHPCrawlerBenchmark::start("getting_cookies_from_cache");
    
    $url_parts = PHPCrawlerUtils::splitURL($target_url);
    
    $return_cookies = array();

    $rows = $this->conn->query("SELECT * FROM " . $this->table . " WHERE source_domain = '".$url_parts["domain"]."' AND crawler_id = '" . $this->crawler_id . "';")->fetchAllAssoc('id');
    
    $cnt = count($rows);
    for ($x=0; $x<$cnt; $x++)
    {
      // Does the cookie-domain match?
      // Tail-matching, see http://curl.haxx.se/rfc/cookie_spec.html:
      // A domain attribute of "acme.com" would match host names "anvil.acme.com" as well as "shipping.crate.acme.com"
      if ($rows[$x]["domain"] == $url_parts["host"] || preg_match("#".preg_quote($rows[$x]["domain"])."$#", $url_parts["host"]))
      {
        // Does the path match?
        if (preg_match("#^".preg_quote($rows[$x]["path"])."#", $url_parts["path"]))
        {
          $Cookie = new PHPCrawlerCookieDescriptor($rows[$x]["source_url"], $rows[$x]["name"], $rows[$x]["value"], $rows[$x]["expires"], $rows[$x]["path"], $rows[$x]["domain"]);
          $return_cookies[$Cookie->name] = $Cookie; // Use cookie-name as index to avoid double-cookies
        }
      }
    }
    
    // Convert to numeric array
    $return_cookies = array_values($return_cookies);
    
    PHPCrawlerBenchmark::stop("getting_cookies_from_cache");
    
    return $return_cookies;
  }

  /**
   * Cleans up the cache after it is not needed anymore.
   */
  public function cleanup()
  {
    $this->conn->query("DELETE FROM " . $this->table . " WHERE crawler_id = '" . $this->crawler_id . "';");
  }
}