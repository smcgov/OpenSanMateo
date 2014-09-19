<?php
/**
 * @file
 * opensanmateo_profile_social_media.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function opensanmateo_profile_social_media_filter_default_formats() {
  $formats = array();

  // Exported format: Obfuscate Email Link.
  $formats['obfuscate_email_link'] = array(
    'format' => 'obfuscate_email_link',
    'name' => 'Obfuscate Email Link',
    'cache' => 0,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'geo_filter_filter' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'geo_filter_show_not_exists' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
