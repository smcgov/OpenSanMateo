<?php
/**
 * @file
 * opensanmateo_overrides.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opensanmateo_overrides_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
