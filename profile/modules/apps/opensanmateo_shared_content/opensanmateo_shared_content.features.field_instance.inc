<?php
/**
 * @file
 * opensanmateo_shared_content.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function opensanmateo_shared_content_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'fieldable_panels_pane-curated_list_pane-field_curated_list_item'
  $field_instances['fieldable_panels_pane-curated_list_pane-field_curated_list_item'] = array(
    'bundle' => 'curated_list_pane',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'search_api_reference',
        'settings' => array(
          'view' => array(
            'args' => array(),
            'display_name' => 'block_6',
            'view_name' => 'opensanmateo_search',
          ),
        ),
        'type' => 'search_api_reference_views',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_curated_list_item',
    'label' => 'List items',
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
      'weight' => -2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('List items');

  return $field_instances;
}
