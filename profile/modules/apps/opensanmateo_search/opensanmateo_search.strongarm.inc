<?php
/**
 * @file
 * opensanmateo_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opensanmateo_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_allow_insecure_derivatives';
  $strongarm->value = '1';
  $export['image_allow_insecure_derivatives'] = $strongarm;

  return $export;
}
