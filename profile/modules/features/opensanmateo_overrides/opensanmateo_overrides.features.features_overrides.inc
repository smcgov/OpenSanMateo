<?php
/**
 * @file
 * opensanmateo_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function opensanmateo_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.label"] = 'Main Image';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.workbench_access_field"] = 0;
  $overrides["field_instance.node-press_release-field_thumbnail_image.label"] = 'Main Image';
  $overrides["field_instance.node-press_release-field_thumbnail_image.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-press_release-field_thumbnail_image.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-press_release-field_thumbnail_image.workbench_access_field"] = 0;
  $overrides["field_instance.node-site_page-field_files.settings|description_field"] = 1;
  $overrides["field_instance.node-site_page-field_files.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-site_page-field_thumbnail_image.label"] = 'Main Image';
  $overrides["field_instance.node-site_page-field_thumbnail_image.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-site_page-field_thumbnail_image.widget|settings|filefield_sources"] = array(
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
  );
  $overrides["field_instance.node-site_page-field_thumbnail_image.workbench_access_field"] = 0;

 return $overrides;
}
