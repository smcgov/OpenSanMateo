<?php
/**
 * @file
 *
 * Implements profile-specific drush commands
 */

/**
 * Implements hook_drush_command
 */
function opensanmateo_roles_drush_command() {
  $items = array();

  $items['osm-reset-perms'] = array(
    'description' => 'Resets permissions to defaults.',
    'examples' => array(
      'drush osm-reset-perms' => dt('Resets permissions to defaults.'),
    ),
  );

  $items['osm-update-perms'] = array(
    'description' => 'Updates permissions using defaults.',
    'examples' => array(
      'drush osm-update-perms' => dt('Updates permissions using defaults.'),
    ),
  );

  return $items;
}

/**
 * Implements command callback for drush command "osm-reset-perms"
 */
function drush_opensanmateo_roles_osm_reset_perms() {
  _opensanmateo_roles_cfg(array());
  opensanmateo_roles_set_default_perms();
  drush_log(dt('Permissions reset to defaults'), 'success');
}

/**
 * Implements command callback for drush command "osm-update-perms"
 */
function drush_opensanmateo_roles_osm_update_perms() {
  opensanmateo_roles_set_default_perms();
  drush_log(dt('Permissions updated using defaults'), 'success');
}
