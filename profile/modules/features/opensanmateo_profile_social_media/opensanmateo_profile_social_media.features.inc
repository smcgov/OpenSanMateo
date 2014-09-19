<?php
/**
 * @file
 * opensanmateo_profile_social_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_profile_social_media_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_field_bases_alter().
 */
function opensanmateo_profile_social_media_field_default_field_bases_alter(&$data) {
  if (isset($data['field_profile_social_media'])) {
    unset($data['field_profile_social_media']);
  }
  if (isset($data['field_social_media_type'])) {
    unset($data['field_social_media_type']['settings']['allowed_values']['instagram']);
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function opensanmateo_profile_social_media_field_default_field_instances_alter(&$data) {
  if (isset($data['field_collection_item-field_social_media-field_social_media_title'])) {
    $data['field_collection_item-field_social_media-field_social_media_title']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['field_collection_item-field_social_media-field_social_media_title']['display']['default']['type'] = 'text_plain'; /* WAS: 'text_default' */
  }
  if (isset($data['field_collection_item-field_social_media-field_social_media_type'])) {
    $data['field_collection_item-field_social_media-field_social_media_type']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['field_collection_item-field_social_media-field_social_media_type']['display']['default']['type'] = 'list_key'; /* WAS: 'list_default' */
  }
  if (isset($data['field_collection_item-field_social_media-field_social_media_value'])) {
    $data['field_collection_item-field_social_media-field_social_media_value']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['field_collection_item-field_social_media-field_social_media_value']['display']['default']['type'] = 'text_plain'; /* WAS: 'text_default' */
  }
  if (isset($data['node-profile-field_profile_social_media'])) {
    unset($data['node-profile-field_profile_social_media']);
  }
  if (isset($data['node-profile-field_social_media'])) {
    $data['node-profile-field_social_media']['display']['default']['label'] = 'hidden'; /* WAS: 'above' */
    $data['node-profile-field_social_media']['display']['default']['weight'] = 2; /* WAS: 17 */
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function opensanmateo_profile_social_media_strongarm_alter(&$data) {
  if (isset($data['field_bundle_settings_field_collection_item__field_social_media'])) {
    $data['field_bundle_settings_field_collection_item__field_social_media']->value['view_modes']['diff_standard'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_field_collection_item__field_social_media']->value['view_modes']['full'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
    $data['field_bundle_settings_field_collection_item__field_social_media']->value['view_modes']['token'] = array(
      'custom_settings' => FALSE,
    ); /* WAS: '' */
  }
}
