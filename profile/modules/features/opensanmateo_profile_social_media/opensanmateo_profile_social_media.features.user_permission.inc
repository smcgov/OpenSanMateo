<?php
/**
 * @file
 * opensanmateo_profile_social_media.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opensanmateo_profile_social_media_user_default_permissions() {
  $permissions = array();

  // Exported permission: use text format obfuscate_email_link.
  $permissions['use text format obfuscate_email_link'] = array(
    'name' => 'use text format obfuscate_email_link',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
