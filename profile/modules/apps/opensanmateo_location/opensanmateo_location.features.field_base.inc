<?php
/**
 * @file
 * opensanmateo_location.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function opensanmateo_location_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_address'
  $field_bases['field_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_address',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'addressfield',
    'settings' => array(
      'non_empty_fields' => array(
        'administrative_area' => 0,
        'country' => 0,
        'data' => 0,
        'dependent_locality' => 'dependent_locality',
        'first_name' => 0,
        'last_name' => 0,
        'locality' => 0,
        'name_line' => 0,
        'organisation_name' => 0,
        'postal_code' => 0,
        'premise' => 0,
        'sub_administrative_area' => 0,
        'sub_premise' => 0,
        'thoroughfare' => 0,
      ),
    ),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_location'
  $field_bases['field_location'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_location',
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
        'display_name' => 'block_1',
        'view_name' => 'opensanmateo_lookup',
      ),
    ),
    'translatable' => 0,
    'type' => 'search_api_reference',
  );

  // Exported field_base: 'field_location_address'
  $field_bases['field_location_address'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_location_address',
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

  // Exported field_base: 'field_text_hours'
  $field_bases['field_text_hours'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_text_hours',
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
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
