<?php
/**
 * Possible cache-types for caching found URLs within the phpcrawl-system.
 *
 * @package phpcrawl.enums
 */
class PHPCrawlerUrlCacheTypes
{
  /**
   * URLs get cached in local RAM. Best performance.
   */
  const URLCACHE_MEMORY = 1;
  
  /**
   * URLs get cached in a SQLite-database-file. Recommended for spidering huge websites.
   */
  const URLCACHE_SQLITE = 2;
  
  /**
   * URLs get cached via DB calls to D7. Recommended for spidering huge websites.
   */
  const URLCACHE_D7 = 3;
  
  /**
   * Returns whether the provided value is a valid PHPCrawlerUrlCacheTypes enum value.
   *
   * @return bool
   */
  public static function isValidCacheType($url_cache_type)
  {
    return preg_match("#[1-3]#", $url_cache_type);
  }
}