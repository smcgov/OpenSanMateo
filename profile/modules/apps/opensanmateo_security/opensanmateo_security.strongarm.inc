<?php
/**
 * @file
 * opensanmateo_security.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function opensanmateo_security_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_failed_login_user_limit';
  $strongarm->value = '5';
  $export['user_failed_login_user_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_failed_login_user_window';
  $strongarm->value = '43200';
  $export['user_failed_login_user_window'] = $strongarm;

  return $export;
}
