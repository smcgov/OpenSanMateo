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
}

// Set Acquia Connector keys
// From Acquia Ticket #15066-99152: Are we able to define multiple Solr instances for the different environments?
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'prod' :
      // Acquia production settings
      $conf['acquia_identifier'] = 'DEGK-36837';
      $conf['acquia_key'] = '5f90bbe305adff93b4ad6b1012e75183';
      $conf['opensanmateo_govdelivery_signup_url'] = 'https://public.govdelivery.com/accounts/CASMATEO/subscriber/new';

      break;
    case 'test' :
      // Acquia test environment
      $conf['acquia_identifier'] = 'LQUZ-41142';
      $conf['acquia_key'] = '1af18383d04d25f92ecbd2cd1547ed01';
      $conf['opensanmateo_govdelivery_signup_url'] = 'https://stage-public.govdelivery.com/accounts/CASMATEO/subscriber/new';
      break;
    case 'dev' :
    default :
      // Acquia dev and all other environments
      $conf['acquia_identifier'] = 'JKWZ-41140';
      $conf['acquia_key'] = '7e97476c37ef890227d54314c8444ef2';
      $conf['opensanmateo_govdelivery_signup_url'] = 'https://stage-public.govdelivery.com/accounts/CASMATEO/subscriber/new';
      break;
  }
} else {
  $conf['opensanmateo_govdelivery_signup_url'] = 'https://stage-public.govdelivery.com/accounts/CASMATEO/subscriber/new';
  // Getting here means site is not inside Acquia Hosting
  // ( $_ENV['AH_SITE_ENVIRONMENT'] is not set)
  // Add any desired code here.
}

// Global GovDelivery Settings
$conf['opensanmateo_govdelivery_account_name'] = 'CASMATEO';


// Set master-client settings that are common across client sites
$conf['sanmateo_master_is'] = $common_settings_url_prefix . '-acquia.fayze2.com';
$conf['distributed_blocks_master_url'] = 'http://' . $conf['sanmateo_master_is'];
$conf['distributed_blocks_update_freq'] = 1;

// Configure caching
//$conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
//$conf['cache_default_class'] = 'MemCacheDrupal';
//$conf['cache_class_form'] = 'DrupalDatabaseCache';

/**
 * Util function to derive private filesystem patch from the site settings path and env vars
 */
function smc_settings_file_private_path($sitedir) {
  global $_ENV;

  $smc_site = array_pop(explode('/', $sitedir));
  return "/mnt/files/{$_ENV['AH_SITE_GROUP']}.{$_ENV['AH_SITE_ENVIRONMENT']}/sites/{$smc_site}/files-private";
}
