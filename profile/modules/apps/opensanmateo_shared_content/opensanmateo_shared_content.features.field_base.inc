<?php
/**
 * @file
 * opensanmateo_shared_content.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function opensanmateo_shared_content_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_coll_curated_item'
  $field_bases['field_coll_curated_item'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_coll_curated_item',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_curated_list_item'
  $field_bases['field_curated_list_item'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_curated_list_item',
    'foreign keys' => array(),
    'indexes' => array(
      'search_item_key' => array(
        0 => 'search_item_key',
      ),
    ),
    'locked' => 0,
    'module' => 'search_api_reference',
    'settings' => array(
      'view' => array(
        'args' => array(),
        'display_name' => 'block_3',
        'view_name' => 'opensanmateo_lookup',
      ),
    ),
    'translatable' => 0,
    'type' => 'search_api_reference',
  );

  // Exported field_base: 'field_curated_list_title'
  $field_bases['field_curated_list_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_curated_list_title',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
