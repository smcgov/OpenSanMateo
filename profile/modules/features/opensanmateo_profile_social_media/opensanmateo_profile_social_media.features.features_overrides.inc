<?php
/**
 * @file
 * opensanmateo_profile_social_media.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function opensanmateo_profile_social_media_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_base
  $overrides["field_base.field_profile_social_media.field_profile_social_media"]["DELETED"] = TRUE;
  $overrides["field_base.field_social_media_type.settings|allowed_values|instagram"]["DELETED"] = TRUE;

  // Exported overrides for: field_instance
  $overrides["field_instance.field_collection_item-field_social_media-field_social_media_title.display|default|label"] = 'hidden';
  $overrides["field_instance.field_collection_item-field_social_media-field_social_media_title.display|default|type"] = 'text_plain';
  $overrides["field_instance.field_collection_item-field_social_media-field_social_media_type.display|default|label"] = 'hidden';
  $overrides["field_instance.field_collection_item-field_social_media-field_social_media_type.display|default|type"] = 'list_key';
  $overrides["field_instance.field_collection_item-field_social_media-field_social_media_value.display|default|label"] = 'hidden';
  $overrides["field_instance.field_collection_item-field_social_media-field_social_media_value.display|default|type"] = 'text_plain';
  $overrides["field_instance.node-profile-field_profile_social_media.node-profile-field_profile_social_media"]["DELETED"] = TRUE;
  $overrides["field_instance.node-profile-field_social_media.display|default|label"] = 'hidden';
  $overrides["field_instance.node-profile-field_social_media.display|default|weight"] = 2;

  // Exported overrides for: variable
  $overrides["variable.field_bundle_settings_field_collection_item__field_social_media.value|view_modes|diff_standard"] = array(
    'custom_settings' => FALSE,
  );
  $overrides["variable.field_bundle_settings_field_collection_item__field_social_media.value|view_modes|full"] = array(
    'custom_settings' => FALSE,
  );
  $overrides["variable.field_bundle_settings_field_collection_item__field_social_media.value|view_modes|token"] = array(
    'custom_settings' => FALSE,
  );

 return $overrides;
}
