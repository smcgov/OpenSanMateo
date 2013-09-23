<?php
/**
 * @file
 * opensanmateo_search.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function opensanmateo_search_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-sub_type-field_view'
  $field_instances['taxonomy_term-sub_type-field_view'] = array(
    'bundle' => 'sub_type',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_views',
        'settings' => array(
          'view' => 'opensanmateo_search block_4',
        ),
        'type' => 'field_views_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_view',
    'label' => 'View',
    'required' => 0,
    'settings' => array(
      'local' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_views',
      'settings' => array(
        'widget_setting' => 'bob',
      ),
      'type' => 'field_views',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'taxonomy_term-subject-field_view'
  $field_instances['taxonomy_term-subject-field_view'] = array(
    'bundle' => 'subject',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_views',
        'settings' => array(
          'view' => 'opensanmateo_search block_3',
        ),
        'type' => 'field_views_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_view',
    'label' => 'View',
    'required' => FALSE,
    'settings' => array(
      'local' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_views',
      'settings' => array(
        'widget_setting' => 'bob',
      ),
      'type' => 'field_views',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'taxonomy_term-topic-field_view'
  $field_instances['taxonomy_term-topic-field_view'] = array(
    'bundle' => 'topic',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_views',
        'settings' => array(
          'view' => 'opensanmateo_search block_5',
        ),
        'type' => 'field_views_formatter',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_view',
    'label' => 'View',
    'required' => 0,
    'settings' => array(
      'local' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_views',
      'settings' => array(
        'widget_setting' => 'bob',
      ),
      'type' => 'field_views',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('View');

  return $field_instances;
}
