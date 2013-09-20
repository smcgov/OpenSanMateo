<?php
/**
 * @file
 * opensanmateo_overrides.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function opensanmateo_overrides_field_default_field_instances_alter(&$data) {
  if (isset($data['node-site_page-field_files'])) {
    $data['node-site_page-field_files']['settings']['description_field'] = 1; /* WAS: 0 */
  }
}
