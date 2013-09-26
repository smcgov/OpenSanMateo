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
  $overrides["field_instance.node-site_page-field_files.settings|description_field"] = 1;

 return $overrides;
}
