<?php
/**
 * @file
 * test.features.field_instance.inc
 */

/**
 * Template callback for features_template
 */
function opensanmateo_govdelivery_features_template_field_event() {
  $field_instances = array();


  // Exported field_instance: 'node-site_page-field_govdelivery_topic_ref'
  $field_instances['field_govdelivery_topic_ref'] = array(
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
    'field_name' => 'field_govdelivery_topic_ref',
    'label' => 'GovDelivery Topic',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 37,
    ),
  );

  return $field_instances;
}
