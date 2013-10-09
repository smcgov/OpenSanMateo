<?php
/**
 * @file
 * opensanmateo_search.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function opensanmateo_search_field_default_field_instances_topic_template() {
  $field_instances = array();


  // Exported field_instance: 'node-site_page-field_topic'
  $field_instances['node-site_page-field_topic'] = array(
    'bundle' => 'site_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_topic',
    'label' => 'Topic',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 35,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Topic');


  return $field_instances;
}
