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

  // Exported overrides for: field
  $overrides["field.node-profile-field_profile_leadership.field_config|active"] = 1;
  $overrides["field.node-profile-field_profile_leadership.field_config|cardinality"] = 1;
  $overrides["field.node-profile-field_profile_leadership.field_config|deleted"] = 0;
  $overrides["field.node-profile-field_profile_leadership.field_config|translatable"] = 1;
  $overrides["field.node-profile-field_profile_leadership.field_instance|deleted"] = 0;
  $overrides["field.node-profile-field_profile_leadership.field_instance|description"] = 'Indicate whether or not this person is either a Department Head or an Elected Official.';
  $overrides["field.node-profile-field_profile_leadership.field_instance|display|default|weight"] = 1;
  $overrides["field.node-profile-field_profile_leadership.field_instance|display|editors_choice|weight"] = 11;
  $overrides["field.node-profile-field_profile_leadership.field_instance|display|teaser|weight"] = 0;
  $overrides["field.node-profile-field_profile_leadership.field_instance|label"] = 'Department Head';
  $overrides["field.node-profile-field_profile_leadership.field_instance|widget|weight"] = 14;
  $overrides["field.node-profile-field_profile_leadership.field_instance|workbench_access_field"] = 0;
  $overrides["field.node-profile-field_profile_staff.field_config|active"] = 1;
  $overrides["field.node-profile-field_profile_staff.field_config|cardinality"] = 1;
  $overrides["field.node-profile-field_profile_staff.field_config|deleted"] = 0;
  $overrides["field.node-profile-field_profile_staff.field_config|translatable"] = 1;
  $overrides["field.node-profile-field_profile_staff.field_instance|deleted"] = 0;
  $overrides["field.node-profile-field_profile_staff.field_instance|description"] = 'This is used to indicate whether this is a San Mateo County Employee. This is helpful when creating lists of profiles for staff directories, while excluding special cases such as Commissioners or Consultants.';
  $overrides["field.node-profile-field_profile_staff.field_instance|display|default|weight"] = 21;
  $overrides["field.node-profile-field_profile_staff.field_instance|display|editors_choice|weight"] = 10;
  $overrides["field.node-profile-field_profile_staff.field_instance|display|teaser|weight"] = 0;
  $overrides["field.node-profile-field_profile_staff.field_instance|label"] = 'Employee';
  $overrides["field.node-profile-field_profile_staff.field_instance|widget|weight"] = 10;
  $overrides["field.node-profile-field_profile_staff.field_instance|workbench_access_field"] = 0;

  // Exported overrides for: field_instance
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.label"] = 'Main Image';
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.settings|image_field_caption"] = 0;
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.widget|settings|filefield_sources"] = array(
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
  $overrides["field_instance.node-blog_entry-field_thumbnail_image.workbench_access_field"] = 0;
  $overrides["field_instance.node-location-field_files.settings|description_field"] = 1;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|attach"] = 0;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|clipboard"] = 0;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|imce"] = 0;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|opensanmateo_search"] = 0;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|osmremotefile"] = 0;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|plupload"] = 0;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|reference"] = 0;
  $overrides["field_instance.node-location-field_files.widget|settings|filefield_sources|filefield_sources|remote"] = 0;
  $overrides["field_instance.node-location-field_files.workbench_access_field"] = 0;
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
  $overrides["field_instance.node-profile-field_profile_address.display|default|weight"] = 9;
  $overrides["field_instance.node-profile-field_profile_division.display|default|weight"] = 6;
  $overrides["field_instance.node-profile-field_profile_email.display|default|label"] = 'above';
  $overrides["field_instance.node-profile-field_profile_email.display|default|module"] = 'text';
  $overrides["field_instance.node-profile-field_profile_email.display|default|type"] = 'text_default';
  $overrides["field_instance.node-profile-field_profile_email.display|default|weight"] = 7;
  $overrides["field_instance.node-profile-field_profile_leadership.description"] = 'Indicate whether or not this person is either a Department Head or an Elected Official.';
  $overrides["field_instance.node-profile-field_profile_leadership.label"] = 'Department Head';
  $overrides["field_instance.node-profile-field_profile_leadership.widget|weight"] = 14;
  $overrides["field_instance.node-profile-field_profile_leadership.workbench_access_field"] = 0;
  $overrides["field_instance.node-profile-field_profile_organization.display|default|weight"] = 5;
  $overrides["field_instance.node-profile-field_profile_phone.display|default|label"] = 'above';
  $overrides["field_instance.node-profile-field_profile_phone.display|default|module"] = 'text';
  $overrides["field_instance.node-profile-field_profile_phone.display|default|type"] = 'text_default';
  $overrides["field_instance.node-profile-field_profile_phone.display|default|weight"] = 8;
  $overrides["field_instance.node-profile-field_profile_staff.description"] = 'This is used to indicate whether this is a San Mateo County Employee. This is helpful when creating lists of profiles for staff directories, while excluding special cases such as Commissioners or Consultants.';
  $overrides["field_instance.node-profile-field_profile_staff.label"] = 'Employee';
  $overrides["field_instance.node-profile-field_profile_staff.widget|weight"] = 10;
  $overrides["field_instance.node-profile-field_profile_staff.workbench_access_field"] = 0;
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
