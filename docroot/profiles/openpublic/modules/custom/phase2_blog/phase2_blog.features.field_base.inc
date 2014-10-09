<?php
/**
 * @file
 * phase2_blog.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function phase2_blog_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_blog_author'
  $field_bases['field_blog_author'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_blog_author',
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
        'editors_choice' => 0,
        'home_page_feature' => 0,
        'media_gallery' => 0,
        'photo' => 0,
        'press_release' => 0,
        'profile' => 'profile',
        'resource' => 0,
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
    'translatable' => 1,
    'type' => 'node_reference',
  );

  return $field_bases;
}
