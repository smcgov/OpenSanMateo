<?php
// Load common code
include_once('common.inc');

// Common alias values for this environment
$smc_docroot = '/var/www/html/sanmateo.dev/docroot';
$smc_remote_host = 'staging-5629.prod.hosting.acquia.com';
$smc_remote_user = 'sanmateo';
$smc_env = 'dev';

// We need to figure out which directory to scan based on what host we're running on
$smc_localhost = php_uname('n');
$smc_sites = get_smc_sites(($smc_localhost == $smc_remote_host) ? $smc_docroot : '/var/www/html/sanmateo/docroot');

// Generate alias for each agency site
foreach ($smc_sites as $site) {
  $aliases[$smc_env . '.' . $site] = array(
    'uri' => $site,
    'root' => $smc_docroot,
    'remote-host' => $smc_remote_host,
    'remote-user' => $smc_remote_user,
    'path-aliases' => array(
      '%files' => 'sites/' . $site . '/files',
      '%dump' => '/tmp/' . $site . '.sql',
    ),
  );
}

// Generate special case for demo sites
for ($i = 1; $i <= 3; ++$i) {
  $aliases[$smc_env . ".demo{$i}"] = array(
    'uri' => "demo{$i}.smcdev-acquia.fayze2.com",
    'root' => $smc_docroot,
    'remote-host' => $smc_remote_host,
    'remote-user' => $smc_remote_user,
    'path-aliases' => array(
      '%files' => 'sites/georgia/files',
      '%dump' => '/tmp/georgia.sql',
    ),
  );
}
