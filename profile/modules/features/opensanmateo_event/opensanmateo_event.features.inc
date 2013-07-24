<?php
/**
 * @file
 * opensanmateo_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_event_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function opensanmateo_event_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Events are used to populate calendar views. Events must have a date associated to them, and optionally, may have a location.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
