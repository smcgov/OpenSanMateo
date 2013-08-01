<?php
/**
 * The following items are settings common to all OpenSanMateo platform sites
 * For env var reference: https://docs.acquia.com/cloud/configure/env-variable
 */

ini_set('memory_limit', '512M');

$common_settings_env_map = array(
  'dev' => 'smc:amc@dev',
  'test' => 'smc:smc@staging',
  'prod' => 'prod',
);
$common_settings_url_prefix = $common_settings_env_map[$_ENV['AH_SITE_ENVIRONMENT']];

if (isset($_ENV['AH_NON_PRODUCTION'])) {
  if ($_ENV['AH_SITE_ENVIRONMENT'] == 'dev') {
    error_reporting(E_ALL & ~E_NOTICE & ~E_STRICT);
    ini_set("display_errors", 1);
  }
}
else {
  $conf['error_level'] = 0;
  $conf['cron_safe_threshold'] = 0;
  //$conf['acquia_identifier'] = 'DJLY-22058';
  //$conf['acquia_key'] = '8602956dedbe389973bc17de9f1eb5eb';
}

//$conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
//$conf['cache_default_class'] = 'MemCacheDrupal';
//$conf['cache_class_form'] = 'DrupalDatabaseCache';

