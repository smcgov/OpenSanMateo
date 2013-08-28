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

  // Exported field_instance: 'field_collection_item-field_coll_curated_item-field_curated_list_item'
  $field_instances['field_collection_item-field_coll_curated_item-field_curated_list_item'] = array(
    'bundle' => 'field_coll_curated_item',
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
            'display_name' => 'block_2',
            'view_name' => 'opensanmateo_search',
          ),
        ),
        'type' => 'search_api_reference_views',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_curated_list_item',
    'label' => 'List item',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_coll_curated_item-field_curated_list_title'
  $field_instances['field_collection_item-field_coll_curated_item-field_curated_list_title'] = array(
    'bundle' => 'field_coll_curated_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_curated_list_title',
    'label' => 'Title',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'fieldable_panels_pane-curated_list_pane-field_coll_curated_item'
  $field_instances['fieldable_panels_pane-curated_list_pane-field_coll_curated_item'] = array(
    'bundle' => 'curated_list_pane',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'hide_empty' => FALSE,
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'fieldable_panels_pane',
    'field_name' => 'field_coll_curated_item',
    'label' => 'Curated item',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Curated item');
  t('List item');
  t('Title');

  return $field_instances;
}
