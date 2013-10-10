<?php
/**
 * @file
 * opensanmateo_search.features.hierarchical_select.inc
 */

/**
 * Implements hook_hierarchical_select_default_configs().
 */
function opensanmateo_search_hierarchical_select_default_configs() {
$configs = array();
$config = array(
  'config_id'       => 'taxonomy-9',
  'save_lineage'    => 0,
  'enforce_deepest' => 0,
  'entity_count'    => 0,
  'require_entity'  => 0,
  'resizable'       => 0,
  'level_labels' => array(
    'status' => 0,
    'labels' => array(
      0 => '',
      1 => '',
      2 => '',
    ),
  ),
  'dropbox' => array(
    'status'    => 1,
    'title'     => 'All selections',
    'limit'     => 0,
    'reset_hs'  => 1,
  ),
  'editability' => array(
    'status' => 0,
    'item_types' => array(
      0 => '',
      1 => '',
      2 => '',
    ),
    'allowed_levels' => array(
      0 => 1,
      1 => 1,
      2 => 1,
    ),
    'allow_new_levels' => 0,
    'max_levels'       => 0,
  ),
);

$configs['taxonomy-9'] = $config;
return $configs;
}
