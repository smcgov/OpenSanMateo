<?php
/**
 * @file
 * opensanmateo_search.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function opensanmateo_search_field_default_field_instances_sub_type_template() {
  $field_instances = array();

  // Exported field_instance: 'node-site_page-field_sub_type'
  $field_instances['node-site_page-field_sub_type'] = array(
    'bundle' => 'site_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_sub_type',
    'label' => 'Sub Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Sub Type');

  return $field_instances;
}
