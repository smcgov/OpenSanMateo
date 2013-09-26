<?php
/**
 * @file
 * opensanmateo_frontend.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function opensanmateo_frontend_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: wysiwyg
  $overrides["wysiwyg.full_html.settings|block_formats"] = 'p,h2,h3,h4,h5,h6,div';
  $overrides["wysiwyg.full_html.settings|css_path"] = '%bprofiles/sanmateo/themes/smc_base/css/elements/editor.css';
  $overrides["wysiwyg.full_html.settings|css_setting"] = 'self';

 return $overrides;
}
