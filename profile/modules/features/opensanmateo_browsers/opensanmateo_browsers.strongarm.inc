<?php
/**
 * @file
 * opensanmateo_browsers.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opensanmateo_browsers_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jreject_browser_config';
  $strongarm->value = array(
    'msie' => array(
      5 => 1,
      6 => 1,
      7 => 1,
      8 => 1,
      9 => 0,
    ),
    'firefox' => array(
      2 => 1,
      3 => 1,
      4 => 1,
      5 => 1,
      6 => 1,
      7 => 1,
      8 => 1,
      9 => 1,
      10 => 0,
      11 => 0,
      12 => 0,
    ),
    'chrome' => array(
      1 => 1,
      2 => 1,
      3 => 1,
      4 => 1,
      5 => 1,
      6 => 1,
      7 => 1,
      8 => 1,
      9 => 1,
      10 => 1,
      11 => 1,
      12 => 1,
      13 => 1,
      14 => 1,
      15 => 1,
      16 => 0,
      17 => 0,
      18 => 0,
    ),
    'safari' => array(
      1 => 1,
      2 => 1,
      3 => 1,
      4 => 1,
      5 => 0,
    ),
    'opera' => array(
      1 => 1,
      2 => 1,
      3 => 1,
      4 => 1,
      5 => 1,
      6 => 1,
      7 => 1,
      8 => 1,
      9 => 1,
      10 => 0,
    ),
  );
  $export['jreject_browser_config'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jreject_enable';
  $strongarm->value = 1;
  $export['jreject_enable'] = $strongarm;

  return $export;
}
