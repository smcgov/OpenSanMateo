<?php
/**
 * @file
 * opensanmateo_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function opensanmateo_roles_user_default_roles() {
  $roles = array();

  // Exported role: content creator.
  $roles['content creator'] = array(
    'name' => 'content creator',
    'weight' => 3,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 5,
  );

  // Exported role: event creator.
  $roles['event creator'] = array(
    'name' => 'event creator',
    'weight' => 4,
  );

  // Exported role: site manager.
  $roles['site manager'] = array(
    'name' => 'site manager',
    'weight' => 6,
  );

  return $roles;
}
