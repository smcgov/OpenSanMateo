<?php
// Find Drush version to use based on Acquia environment variables.
if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}

$skip_items = array(
  '.',
  '..',
  'all',
  'default',
  'demo1',
  'demo2',
  'demo3',
  'test',
);
// Find all directories in the sites folder.
$sites_root = '/var/www/html/sanmateo.dev/docroot/sites';
$dirlist = scandir($sites_root);
$smc_sites = array();
foreach ($dirlist as $item) {
  if (!is_dir($sites_root . '/' . $item))
    continue;
  $smc_sites[] = $item;
}
$smc_sites = array_diff($smc_sites, $skip_items);

// Generate alias for each agency site
foreach ($smc_sites as $site) {
  // Find the site name. ex: the "parks" in the "parks.smcgov.org".
  if (strpos($site, 'smcgov.org') === 0) {
    // The main site, smcgov is different from the others.
    $site_name = 'dev';
  }
  else {
    // Ex: "parks.smcgov.org" minus 11 characters from end leaves just "parks".
    // $site_name becomes "staging.parks".
    $site_name = 'dev.' . substr($site, 0, -11);
  }
  // Ex: Drush alias name will be "@dev.parks".
  $aliases[$site_name] = array(
    'uri' => $site_name . '.smcgov.org',
    'root' => '/var/www/html/sanmateo.dev/docroot',
    'ac-site' => 'sanmateo',
    'ac-env' => 'dev',
    'ac-realm' => 'prod',
    'site' => 'sanmateo',
    'env' => 'dev',
    'path-aliases' => array(
      '%drush-script' => 'drush' . $drush_major_version,
    )
  );
}
