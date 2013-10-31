<?php
/**
 * @file
 * opensanmateo_frontend.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opensanmateo_frontend_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fonts_com_filter_choices';
  $strongarm->value = array(
    'filters' => array(
      'Designer' => array(),
      'Foundry' => array(),
      'Classification' => array(),
      'Language' => array(),
      'Alpha' => array(),
      'FreeOrPaid' => array(),
    ),
    'updated' => 1383228417,
  );
  $export['fonts_com_filter_choices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fonts_com_project';
  $strongarm->value = '1b4ab7ba-bb64-4f70-bd43-9f3401f4dd20';
  $export['fonts_com_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fonts_com_token';
  $strongarm->value = '6d12dd61-db4f-4253-be2d-59f6f2969fed--62591c3d-2da5-4539-a3a2-e08e7cc6611d2C-E2-6E-80-5A-CE-2E-E5-BE-39-36-4F-54-3A-C5-95';
  $export['fonts_com_token'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fontyourface_css_md5';
  $strongarm->value = 'd41d8cd98f00b204e9800998ecf8427e';
  $export['fontyourface_css_md5'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_compression_type';
  $strongarm->value = 'min';
  $export['jquery_update_compression_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_cdn';
  $strongarm->value = 'none';
  $export['jquery_update_jquery_cdn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.7';
  $export['jquery_update_jquery_version'] = $strongarm;

  return $export;
}
