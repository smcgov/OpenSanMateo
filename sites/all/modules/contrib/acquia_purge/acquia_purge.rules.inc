<?php

/**
 * @file
 * Rules integration that provides a purge action as rule action.
 */

/**
 * Implements hook_rules_action_info().
 */
function acquia_purge_rules_action_info() {
  return array(
    '_acquia_purge_action_purge' => array(
      'label' => t('Purge a path from Varnish on Acquia Cloud'),
      'group' => t('System'),
      'parameter' => array(
        'path' => array(
          'type' => 'text',
          'label' => t('Path'),
          'description' => t('The Drupal path that needs to be purged as
          relative from the document root of the site. When provided multiple
          lines, multiple paths will be purged at once. Examples are "node/1"
          and "news" and there is no need to add a slash at the beginning or
          end.'),
        ),
      ),
    ),
  );
}

/**
 * Action callback to the "Purge a path from Varnish on Acquia Cloud" rule.
 */
function _acquia_purge_action_purge($configured_paths) {
  $paths = array();

  // As users can enter these paths, we are treating them as tainted input.
  foreach (explode("\n", $configured_paths) as $configured_path) {

    // We begin by copying a trimmed version of the given line.
    $path = trim($configured_path);

    // And we strip off starting or trailing slashes, not belonging to a path.
    $path = trim($path, '/');

    // And strip double slashes that slipped in accidentally.
    $path = str_replace('//', '/', $path);

    // Add if the string isn't empty and only when it is new in the list.
    if (!empty($path) && !in_array($path, $paths)) {
      $paths[] = $path;
    }
  }

  // Relay the purging of these paths to our API helper and we are done here.
  acquia_purge_purge_paths($paths);
}
