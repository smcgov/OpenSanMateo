<?php
/**
 * @file
 * opensanmateo_crawler.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opensanmateo_crawler_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function opensanmateo_crawler_node_info() {
  $items = array(
    'external_page' => array(
      'name' => t('External Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'external_site' => array(
      'name' => t('External Site'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
