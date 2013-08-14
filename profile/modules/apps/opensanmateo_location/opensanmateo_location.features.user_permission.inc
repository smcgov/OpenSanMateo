<?php
/**
 * @file
 * opensanmateo_location.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opensanmateo_location_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit quick search tags.
  $permissions['edit quick search tags'] = array(
    'name' => 'edit quick search tags',
    'roles' => array(),
    'module' => 'opensanmateo_location',
  );

  return $permissions;
}
