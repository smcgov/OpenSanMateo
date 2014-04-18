<?php

/**
 * @file
 * Configuration file for Drupal's multi-site directory aliasing feature.
 *
 * This file allows you to define a set of aliases that map hostnames, ports, and
 * pathnames to configuration directories in the sites directory. These aliases
 * are loaded prior to scanning for directories, and they are exempt from the
 * normal discovery rules. See default.settings.php to view how Drupal discovers
 * the configuration directory when no alias is found.
 *
 * Aliases are useful on development servers, where the domain name may not be
 * the same as the domain of the live server. Since Drupal stores file paths in
 * the database (files, system table, etc.) this will ensure the paths are
 * correct when the site is deployed to a live server.
 *
 * To use this file, copy and rename it such that its path plus filename is
 * 'sites/sites.php'. If you don't need to use multi-site directory aliasing,
 * then you can safely ignore this file, and Drupal will ignore it too.
 *
 * Aliases are defined in an associative array named $sites. The array is
 * written in the format: '<port>.<domain>.<path>' => 'directory'. As an
 * example, to map http://www.drupal.org:8080/mysite/test to the configuration
 * directory sites/example.com, the array should be defined as:
 * @code
 * $sites = array(
 *   '8080.www.drupal.org.mysite.test' => 'example.com',
 * );
 * @endcode
 * The URL, http://www.drupal.org:8080/mysite/test/, could be a symbolic link or
 * an Apache Alias directive that points to the Drupal root containing
 * index.php. An alias could also be created for a subdomain. See the
 * @link http://drupal.org/documentation/install online Drupal installation guide @endlink
 * for more information on setting up domains, subdomains, and subdirectories.
 *
 * The following examples look for a site configuration in sites/example.com:
 * @code
 * URL: http://dev.drupal.org
 * $sites['dev.drupal.org'] = 'example.com';
 *
 * URL: http://localhost/example
 * $sites['localhost.example'] = 'example.com';
 *
 * URL: http://localhost:8080/example
 * $sites['8080.localhost.example'] = 'example.com';
 *
 * URL: http://www.drupal.org:8080/mysite/test/
 * $sites['8080.www.drupal.org.mysite.test'] = 'example.com';
 * @endcode
 *
 * @see default.settings.php
 * @see conf_path()
 * @see http://drupal.org/documentation/install/multi-site
 */

/*
 * Map San Mateo sites to dev, staging and prod fayze2.com hostnames
 * Acquia domains: 
 *   *.smcdev-acquia.fayze.com
 *   *.smcstg-acquia.fayze.com
 *   *.smcprd-acquia.fayze.com
 */
$fayze2_sites = array(
  'test' => 'test.smcgov.org',
  'smcgov' => 'smcgov.org',
  '911dispatch' => '911dispatch.smcgov.org',
  'agwm' => 'agwm.smcgov.org',
  'bos' => 'bos.smcgov.org',
  'cmo' => 'cmo.smcgov.org',
  'coroner' => 'coroner.smcgov.org',
  'da' => 'da.smcgov.org',
  'green' => 'green.smcgov.org',
  'hr' => 'hr.smcgov.org',
  'isd' => 'isd.smcgov.org',
  'jobs' => 'jobs.smcgov.org',
  'parks' => 'parks.smcgov.org',
  'planning' => 'planning.smcgov.org',
  'probation' => 'probation.smcgov.org',
  'housing' => 'housing.smcgov.org',
  'controller' => 'controller.smcgov.org',
  'taxcollector' => 'taxcollector.smcgov.org',
  'publicworks' => 'publicworks.smcgov.org',
  'bnc' => 'bnc.smcgov.org',
  'countycounsel' => 'countycounsel.smcgov.org',
  'hsa' => 'hsa.smcgov.org',
  'dcss' => 'dcss.smcgov.org',
  'csw' => 'csw.smcgov.org',
);

foreach ($fayze2_sites as $short_name => $site_name) {
  $sites["{$short_name}.smcdev-acquia.fayze2.com"] = $site_name;
  $sites["{$short_name}.smcstg-acquia.fayze2.com"] = $site_name;
  $sites["{$short_name}.smcprd-acquia.fayze2.com"] = $site_name;
}
//added www.smcgov.org to point at main site
$sites["www.smcgov.org"] = "smcgov.org";

/*
 * Additional mappings for staging
 */

/*
 * Additional mappings for prod
 */
