<?php
/**
 * @file
 * opensanmateo_resp_images.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function opensanmateo_resp_images_default_picture_mapping() {
  $export = array();

  $picture_mapping = new stdClass();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 1;
  $picture_mapping->machine_name = 'opensanmateo_resp_images';
  $picture_mapping->breakpoint_group = 'opensanmateo_resp_images';
  $picture_mapping->mapping = array(
    'custom.user.mobile' => array(
      '1x' => 'opensanmateo_resp_images_small',
    ),
    'custom.user.narrow' => array(
      '1x' => 'opensanmateo_resp_images_medium',
    ),
    'custom.user.wide' => array(
      '1x' => 'opensanmateo_resp_images_large',
    ),
  );
  $export['opensanmateo_resp_images'] = $picture_mapping;

  return $export;
}
