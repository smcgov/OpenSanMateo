<?php
/**
 * @file
 * opensanmateo_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_media_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function opensanmateo_media_image_default_styles() {
  $styles = array();

  // Exported image style: media_full.
  $styles['media_full'] = array(
    'name' => 'media_full',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'media_full',
  );

  // Exported image style: media_thumbnail.
  $styles['media_thumbnail'] = array(
    'name' => 'media_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'media_thumbnail',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function opensanmateo_media_node_info() {
  $items = array(
    'media' => array(
      'name' => t('Media'),
      'base' => 'node_content',
      'description' => t('The media type allows for both photos and videos. A collection of images and videos can be grouped by tag to create a simple gallery around a theme.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
