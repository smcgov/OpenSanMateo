<?php
/**
 * The following items are settings common to all OpenSanMateo platform sites
 * For env var reference: https://docs.acquia.com/cloud/configure/env-variable
 */

ini_set('memory_limit', '512M');

$common_settings_env_map = array(
  'dev' => 'smc:smc@smcgov.smcdev',
  'test' => 'smc:smc@smcgov.smcstg',
  'prod' => 'smcgov.smcprd',
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

  // Configure caching
  $conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
  $conf['cache_default_class'] = 'MemCacheDrupal';
  $conf['cache_class_form'] = 'DrupalDatabaseCache';
}
// Global GovDelivery Settings.
// These may be changed below.
$conf['opensanmateo_govdelivery_base_url']= 'https://bbowman@phase2technology.com:Simplepassword1@stage-api.govdelivery.com';
$conf['opensanmateo_govdelivery_account_name'] = 'CASMATEO';
$conf['opensanmateo_govdelivery_signup_url'] = 'https://stage-public.govdelivery.com/accounts/CASMATEO/subscriber/new';

// Set Acquia Connector keys
// From Acquia Ticket #15066-99152: Are we able to define multiple Solr instances for the different environments?
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'prod' :
      // Acquia production settings
      $conf['acquia_identifier'] = 'DEGK-36837';
      $conf['acquia_key'] = '5f90bbe305adff93b4ad6b1012e75183';

      // Set production specific GovDelivery settings.
      $conf['opensanmateo_govdelivery_base_url']= 'https://websupport@co.sanmateo.ca.us@:SD6Ru4562OJ3uvp@stage-api.govdelivery.com';
      $conf['opensanmateo_govdelivery_signup_url'] = 'https://public.govdelivery.com/accounts/CASMATEO/subscriber/new';

      break;
    case 'test' :
      // Acquia test environment
      $conf['acquia_identifier'] = 'LQUZ-41142';
      $conf['acquia_key'] = '1af18383d04d25f92ecbd2cd1547ed01';


      break;
    case 'dev' :
    default :
      // Acquia dev and all other environments
      $conf['acquia_identifier'] = 'JKWZ-41140';
      $conf['acquia_key'] = '7e97476c37ef890227d54314c8444ef2';

      break;
  }
} else {
  // Getting here means site is not inside Acquia Hosting
  // ( $_ENV['AH_SITE_ENVIRONMENT'] is not set)
  // Add any desired code here.
}

// Set master-client settings that are common across client sites
$master_host = $common_settings_url_prefix . '-acquia.fayze2.com';
if (empty($conf['sanmateo_is_master'])) {
  $conf['sanmateo_master_is'] = $master_host;
}
$conf['distributed_blocks_master_url'] = 'http://' . $master_host;
$conf['distributed_blocks_update_freq'] = 1;

/**
 * Util function to derive private filesystem patch from the site settings path and env vars
 */
function smc_settings_file_private_path($sitedir) {
  global $_ENV;

  $smc_site = array_pop(explode('/', $sitedir));
  return "/mnt/files/{$_ENV['AH_SITE_GROUP']}.{$_ENV['AH_SITE_ENVIRONMENT']}/sites/{$smc_site}/files-private";
}
