<?php
/**
 * @file
 * opensanmateo_overrides.features.inc
 */

/**
 * Implements hook_field_default_fields_alter().
 */
function opensanmateo_overrides_field_default_fields_alter(&$data) {
  if (isset($data['node-profile-field_profile_leadership'])) {
    $data['node-profile-field_profile_leadership']['field_config']['active'] = 1; /* WAS: 1 */
    $data['node-profile-field_profile_leadership']['field_config']['cardinality'] = 1; /* WAS: 1 */
    $data['node-profile-field_profile_leadership']['field_config']['deleted'] = 0; /* WAS: 0 */
    $data['node-profile-field_profile_leadership']['field_config']['translatable'] = 1; /* WAS: 1 */
    $data['node-profile-field_profile_leadership']['field_instance']['deleted'] = 0; /* WAS: 0 */
    $data['node-profile-field_profile_leadership']['field_instance']['description'] = 'Indicate whether or not this person is either a Department Head or an Elected Official.'; /* WAS: 'Indicate whether or not this person holds a leadership position.' */
    $data['node-profile-field_profile_leadership']['field_instance']['display']['default']['weight'] = 0; /* WAS: 0 */
    $data['node-profile-field_profile_leadership']['field_instance']['display']['editors_choice']['weight'] = 11; /* WAS: 11 */
    $data['node-profile-field_profile_leadership']['field_instance']['display']['teaser']['weight'] = 0; /* WAS: 0 */
    $data['node-profile-field_profile_leadership']['field_instance']['label'] = 'Department Head'; /* WAS: 'Leadership' */
    $data['node-profile-field_profile_leadership']['field_instance']['widget']['weight'] = 14; /* WAS: 14 */
    $data['node-profile-field_profile_leadership']['field_instance']['workbench_access_field'] = 0; /* WAS: '' */
  }
  if (isset($data['node-profile-field_profile_staff'])) {
    $data['node-profile-field_profile_staff']['field_config']['active'] = 1; /* WAS: 1 */
    $data['node-profile-field_profile_staff']['field_config']['cardinality'] = 1; /* WAS: 1 */
    $data['node-profile-field_profile_staff']['field_config']['deleted'] = 0; /* WAS: 0 */
    $data['node-profile-field_profile_staff']['field_config']['translatable'] = 1; /* WAS: 1 */
    $data['node-profile-field_profile_staff']['field_instance']['deleted'] = 0; /* WAS: 0 */
    $data['node-profile-field_profile_staff']['field_instance']['description'] = 'This is used to indicate whether this is a San Mateo County Employee. This is helpful when creating lists of profiles for staff directories, while excluding special cases such as Commissioners or Consultants.'; /* WAS: 'This is used to indicate whether this is a staff member. This is helpful when creating lists of profiles for staff directories, while excluding special cases such as guest bloggers or businesses.' */
    $data['node-profile-field_profile_staff']['field_instance']['display']['default']['weight'] = 7; /* WAS: 7 */
    $data['node-profile-field_profile_staff']['field_instance']['display']['editors_choice']['weight'] = 10; /* WAS: 10 */
    $data['node-profile-field_profile_staff']['field_instance']['display']['teaser']['weight'] = 0; /* WAS: 0 */
    $data['node-profile-field_profile_staff']['field_instance']['label'] = 'Employee'; /* WAS: 'Staff Member' */
    $data['node-profile-field_profile_staff']['field_instance']['widget']['weight'] = 10; /* WAS: 10 */
    $data['node-profile-field_profile_staff']['field_instance']['workbench_access_field'] = 0; /* WAS: '' */
  }
}

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
  if (isset($data['node-profile-field_profile_leadership'])) {
    $data['node-profile-field_profile_leadership']['description'] = 'Indicate whether or not this person is either a Department Head or an Elected Official.'; /* WAS: 'Indicate whether or not this person holds a leadership position.' */
    $data['node-profile-field_profile_leadership']['label'] = 'Department Head'; /* WAS: 'Leadership' */
    $data['node-profile-field_profile_leadership']['widget']['weight'] = 14; /* WAS: 13 */
    $data['node-profile-field_profile_leadership']['workbench_access_field'] = 0; /* WAS: '' */
  }
  if (isset($data['node-profile-field_profile_staff'])) {
    $data['node-profile-field_profile_staff']['description'] = 'This is used to indicate whether this is a San Mateo County Employee. This is helpful when creating lists of profiles for staff directories, while excluding special cases such as Commissioners or Consultants.'; /* WAS: 'This is used to indicate whether this is a staff member. This is helpful when creating lists of profiles for staff directories, while excluding special cases such as guest bloggers or businesses.' */
    $data['node-profile-field_profile_staff']['label'] = 'Employee'; /* WAS: 'Staff Member' */
    $data['node-profile-field_profile_staff']['widget']['weight'] = 10; /* WAS: 11 */
    $data['node-profile-field_profile_staff']['workbench_access_field'] = 0; /* WAS: '' */
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
