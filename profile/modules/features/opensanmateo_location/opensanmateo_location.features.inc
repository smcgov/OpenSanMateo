<?php
/**
 * @file
 * opensanmateo_location.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_location_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function opensanmateo_location_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => t('A content type for creating and defining a specific location, such as a park, office, or even a city. Locations can be defined as points (street address) as well as areas (parks, zones) to appear on a map.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
