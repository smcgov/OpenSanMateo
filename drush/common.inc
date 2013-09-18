<?php
// Utility function to extract the site folders from the GTA environment docroot provided
function get_smc_sites($docroot) {
  $skip_items = array(
    '.',
    '..',
    'all',
    'default',
  );
  $sites_root = $docroot . '/sites';
  $dirlist = scandir($sites_root);
  $smc_sites = array();
  foreach ($dirlist as $item) {
    if (!is_dir($sites_root . '/' . $item))
      continue;
    $smc_sites[] = $item;
  }
  $smc_sites = array_diff($smc_sites, $skip_items);

  return $smc_sites;
}
