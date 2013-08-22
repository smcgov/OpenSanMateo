<?php
/**
 * @file
 * opensanmateo_wysiwyg.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opensanmateo_wysiwyg_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format raw.
  $permissions['use text format raw'] = array(
    'name' => 'use text format raw',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'site manager' => 'site manager',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
