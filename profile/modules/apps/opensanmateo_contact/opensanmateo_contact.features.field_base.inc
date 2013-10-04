<?php
/**
 * @file
 * opensanmateo_contact.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function opensanmateo_contact_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_contact'
  $field_bases['field_contact'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'blog_entry' => 0,
        'document' => 0,
        'event' => 0,
        'location' => 0,
        'media' => 0,
        'press_release' => 0,
        'profile' => 'profile',
        'services' => 0,
        'site_page' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  return $field_bases;
}
