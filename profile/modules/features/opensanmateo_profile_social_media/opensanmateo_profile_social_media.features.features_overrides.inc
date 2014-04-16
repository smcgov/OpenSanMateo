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

  // Exported overrides for: field_instance
  $overrides["field_instance.node-profile-field_profile_social_media.node-profile-field_profile_social_media"]["DELETED"] = TRUE;

 return $overrides;
}
