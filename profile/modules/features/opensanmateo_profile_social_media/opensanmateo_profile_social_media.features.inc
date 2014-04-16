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
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function opensanmateo_profile_social_media_field_default_field_instances_alter(&$data) {
  if (isset($data['node-profile-field_profile_social_media'])) {
    unset($data['node-profile-field_profile_social_media']);
  }
}
