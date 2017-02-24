<?php
/**
 * @file
 * Enable Drupal 7 core "fast 404" behavior per Acquia.
 *
 * See at https://docs.acquia.com/articles/using-fast-404-drupal.
 */

if (function_exists('drupal_fast_404')) {
  drupal_fast_404();
}

/**
 * The following items are settings common to all OpenSanMateo platform sites.
 *
 * For env var reference: https://docs.acquia.com/cloud/configure/env-variable.
 */

ini_set('memory_limit', '512M');

$common_settings_env_map = array(
  'dev' => 'smc:smc@smcgov.smcdev',
  'test' => 'smc:smc@smcgov.smcstg',
  'prod' => 'smcgov.smcprd',
);
$common_settings_url_prefix = $common_settings_env_map[$_ENV['AH_SITE_ENVIRONMENT']];

// Disable poor man's cron.
$conf['cron_safe_threshold'] = 0;

if (isset($_ENV['AH_NON_PRODUCTION'])) {
  if ($_ENV['AH_SITE_ENVIRONMENT'] == 'dev') {
    error_reporting(E_ALL & ~E_NOTICE & ~E_STRICT);
    ini_set("display_errors", 1);
  }
}
else {
  $conf['error_level'] = 0;

  // Configure caching.
  $conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
  $conf['cache_default_class'] = 'MemCacheDrupal';
  $conf['cache_class_form'] = 'DrupalDatabaseCache';
}
// Global GovDelivery Settings.
// These may be changed below.
$conf['opensanmateo_govdelivery_base_url'] = 'https://bbowman@phase2technology.com:Simplepassword1@stage-api.govdelivery.com';
$conf['opensanmateo_govdelivery_account_name'] = 'CASMATEO';
$conf['opensanmateo_govdelivery_signup_url'] = 'https://stage-public.govdelivery.com/accounts/CASMATEO/subscriber/new';

// Set Acquia Connector keys
// From Acquia Ticket #15066-99152: Are we able to define multiple Solr
// instances for the different environments?
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  // If this is an Acquia environment, enable mixed mode HTTPS.
  // Combined with Securepages settings, this forces Authenticated traffic to
  // be directed to HTTPS pages, and directs anonymous traffic to HTTP.
  $conf['https'] = 1;

  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'prod':

      // Set production specific GovDelivery settings.
      $conf['opensanmateo_govdelivery_base_url'] = 'https://websupport@smcgov.org:SD6Ru4562OJ3uvp@api.govdelivery.com';
      $conf['opensanmateo_govdelivery_signup_url'] = 'https://public.govdelivery.com/accounts/CASMATEO/subscriber/new';
      $conf['plupload_temporary_uri'] = "/mnt/gfs/{$_ENV['AH_SITE_GROUP']}.{$_ENV['AH_SITE_ENVIRONMENT']}/tmp";

      break;

    // No default steps need to be taken.
  }
}
else {
  // Getting here means site is not inside Acquia Hosting
  // ( $_ENV['AH_SITE_ENVIRONMENT'] is not set)
  // Add any desired code here.
}

// Set master-client settings that are common across client sites.
$master_host = $common_settings_url_prefix . '-acquia.fayze2.com';
if (empty($conf['sanmateo_is_master'])) {
  $conf['sanmateo_master_is'] = $master_host;
}
$conf['distributed_blocks_master_url'] = 'prod' == $_ENV['AH_SITE_ENVIRONMENT'] ? 'http://www.smcgov.org' : 'http://' . $master_host;
$conf['distributed_blocks_update_freq'] = 1;

/**
 * Gets private filesystem patch from the site settings path and env vars.
 */
function smc_settings_file_private_path($sitedir) {
  global $_ENV;

  $path_parts = explode('/', $sitedir);
  $smc_site = array_pop($path_parts);
  return "/mnt/files/{$_ENV['AH_SITE_GROUP']}.{$_ENV['AH_SITE_ENVIRONMENT']}/sites/{$smc_site}/files-private";
}
