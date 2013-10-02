<?php
/**
 * @file
 * Contains module-level code we don't want to risk Features overwriting if something went wrong with a Feature update or recreate
 */

/**
 * Implements hook_field_display_alter
 */
function opensanmateo_resp_images_field_display_alter(&$display, $context) {
  // We're only interested in full view mode on our selected fields. Additionally
  // we want to ensure we are only overriding default core formatters, and
  // not formatters provided by other modules.
  $default_formatters = array(
    'file_download_link',
    'file_rendered',
    'image',
  );

  $image_fields = variable_get('opensanmateo_resp_images_fields', array());
  if ('full' !== $context['view_mode'] || !in_array($context['instance']['id'], $image_fields) || !in_array($display['type'], $default_formatters)) {
    return;
  }

  // Retrieve our field formatter display overrides and set them
  $settings = variable_get('opensanmateo_resp_images_formatter_settings', _opensanmateo_resp_images_get_picture_defaults());
  $display['type'] = 'picture';
  $display['module'] = 'picture';
  $display['settings'] = $settings;
  //dpm($display);
}

/**
 * Util function to retrieve default Picture field formatter settings
 */
function _opensanmateo_resp_images_get_picture_defaults() {
  $formatters = picture_field_formatter_info();
  return $formatters['picture']['settings'];
}
