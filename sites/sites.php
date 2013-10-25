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
 * Map San Mateo sites to dev host
 * Acquia domains defines *.smcdev-acquia.fayze.com
 */
$sites['demo1.smcdev-acquia.fayze2.com'] = 'demo1';
$sites['demo2.smcdev-acquia.fayze2.com'] = 'demo2';
$sites['demo3.smcdev-acquia.fayze2.com'] = 'demo3';

$sites['smcgov.smcdev-acquia.fayze2.com'] = 'smcgov.org';
$sites['hr.smcdev-acquia.fayze2.com'] = 'hr.smcgov.org';
$sites['planning.smcdev-acquia.fayze2.com'] = 'planning.smcgov.org';
$sites['parks.smcdev-acquia.fayze2.com'] = 'parks.smcgov.org';
$sites['isd.smcdev-acquia.fayze2.com'] = 'isd.smcgov.org';
$sites['da.smcdev-acquia.fayze2.com'] = 'da.smcgov.org';

/*
 * Map San Mateo sites to staging host
 * Acquia domains defines *.smcstg-acquia.fayze.com
 */
$sites['demo1.smcstg-acquia.fayze2.com'] = 'demo1';
$sites['demo2.smcstg-acquia.fayze2.com'] = 'demo2';
$sites['demo3.smcstg-acquia.fayze2.com'] = 'demo3';

$sites['smcgov.smcstg-acquia.fayze2.com'] = 'smcgov.org';
$sites['hr.smcstg-acquia.fayze2.com'] = 'hr.smcgov.org';
$sites['planning.smcstg-acquia.fayze2.com'] = 'planning.smcgov.org';
$sites['parks.smcstg-acquia.fayze2.com'] = 'parks.smcgov.org';
$sites['isd.smcstg-acquia.fayze2.com'] = 'isd.smcgov.org';
$sites['da.smcstg-acquia.fayze2.com'] = 'da.smcgov.org';
$sites['coroner.smcstg-acquia.fayze2.com'] = 'coroner.smcgov.org';

/*
 * Map San Mateo sites to prod host
 * Acquia domains defines *.smcprd-acquia.fayze.com
 */
$sites['demo1.smcprd-acquia.fayze2.com'] = 'demo1';
$sites['demo2.smcprd-acquia.fayze2.com'] = 'demo2';
$sites['demo3.smcprd-acquia.fayze2.com'] = 'demo3';

