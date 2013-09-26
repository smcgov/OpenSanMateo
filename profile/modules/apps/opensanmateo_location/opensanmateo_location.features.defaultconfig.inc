<?php
/**
 * @file
 * opensanmateo_location.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function opensanmateo_location_defaultconfig_features() {
  return array(
    'opensanmateo_location' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function opensanmateo_location_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addressfield_staticmap_field_names';
  $strongarm->value = array(
    'field_address' => 'field_address',
  );
  $export['addressfield_staticmap_field_names'] = $strongarm;

  return $export;
}
