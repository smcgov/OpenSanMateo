<?php
/**
 * @file
 * test.features.field_instance.inc
 */

/**
 * Template callback for features_template
 */
function opensanmateo_event_features_template_field_event() {
  $field_instances = array();

  // Exported field_instance: 'node-media-field_event'
  $field_instances['field_event'] = array(
    'bundle' => 'media',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'search_api_reference',
        'settings' => array(
          'view' => array(
            'args' => array(),
            'display_name' => '',
            'view_name' => '',
          ),
        ),
        'type' => 'search_api_reference_views',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_event',
    'label' => 'Event',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'search_api_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'search_api_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'search_api_reference_autocomplete',
      'weight' => 8,
    ),
  );

  return $field_instances;
}
