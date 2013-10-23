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
    $data['node-site_page-field_files']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(),
      'source_attach' => array(
        'absolute' => 0,
        'attach_mode' => 'move',
        'path' => 'file_attach',
      ),
      'source_imce' => array(
        'imce_mode' => 0,
      ),
      'source_reference' => array(
        'autocomplete' => 0,
      ),
    ); /* WAS: '' */
  }
}
