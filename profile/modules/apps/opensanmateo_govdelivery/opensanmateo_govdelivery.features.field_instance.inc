<?php
/**
 * @file
 * opensanmateo_govdelivery.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function opensanmateo_govdelivery_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-site_page-field_govdelivery_topic_ref'
  $field_instances['node-site_page-field_govdelivery_topic_ref'] = array(
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
        'weight' => 16,
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

  // Exported field_instance: 'taxonomy_term-govdelivery_topics-field_govdelivery_topic'
  $field_instances['taxonomy_term-govdelivery_topics-field_govdelivery_topic'] = array(
    'bundle' => 'govdelivery_topics',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_govdelivery_topic',
    'label' => 'GovDelivery Topic',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'taxonomy_term-govdelivery_topics-field_govdelivery_topic_url'
  $field_instances['taxonomy_term-govdelivery_topics-field_govdelivery_topic_url'] = array(
    'bundle' => 'govdelivery_topics',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_govdelivery_topic_url',
    'label' => 'GovDelivery Topic URL',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('GovDelivery Topic');
  t('GovDelivery Topic URL');

  return $field_instances;
}
