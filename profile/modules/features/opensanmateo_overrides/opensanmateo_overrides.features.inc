<?php
/**
 * @file
 * opensanmateo_overrides.features.inc
 */

/**
 * Implements hook_field_default_field_instances_alter().
 */
function opensanmateo_overrides_field_default_field_instances_alter(&$data) {
  if (isset($data['node-blog_entry-field_thumbnail_image'])) {
    $data['node-blog_entry-field_thumbnail_image']['label'] = 'Main Image'; /* WAS: 'Thumbnail Image' */
    $data['node-blog_entry-field_thumbnail_image']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-blog_entry-field_thumbnail_image']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(
        'attach' => 0,
        'clipboard' => 0,
        'imce' => 0,
        'opensanmateo_search' => 0,
        'osmremotefile' => 0,
        'plupload' => 0,
        'reference' => 0,
        'remote' => 0,
      ),
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
    $data['node-blog_entry-field_thumbnail_image']['workbench_access_field'] = 0; /* WAS: '' */
  }
  if (isset($data['node-press_release-field_thumbnail_image'])) {
    $data['node-press_release-field_thumbnail_image']['label'] = 'Main Image'; /* WAS: 'Thumbnail Image' */
    $data['node-press_release-field_thumbnail_image']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-press_release-field_thumbnail_image']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(
        'attach' => 0,
        'clipboard' => 0,
        'imce' => 0,
        'opensanmateo_search' => 0,
        'osmremotefile' => 0,
        'plupload' => 0,
        'reference' => 0,
        'remote' => 0,
      ),
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
    $data['node-press_release-field_thumbnail_image']['workbench_access_field'] = 0; /* WAS: '' */
  }
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
  if (isset($data['node-site_page-field_thumbnail_image'])) {
    $data['node-site_page-field_thumbnail_image']['label'] = 'Main Image'; /* WAS: 'Thumbnail Image' */
    $data['node-site_page-field_thumbnail_image']['settings']['image_field_caption'] = 0; /* WAS: '' */
    $data['node-site_page-field_thumbnail_image']['widget']['settings']['filefield_sources'] = array(
      'filefield_sources' => array(
        'attach' => 0,
        'clipboard' => 0,
        'imce' => 0,
        'opensanmateo_search' => 0,
        'osmremotefile' => 0,
        'plupload' => 0,
        'reference' => 0,
        'remote' => 0,
      ),
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
    $data['node-site_page-field_thumbnail_image']['workbench_access_field'] = 0; /* WAS: '' */
  }
}
