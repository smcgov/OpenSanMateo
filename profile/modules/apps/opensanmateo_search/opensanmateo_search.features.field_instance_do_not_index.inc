<?php
/**
 * @file
 * opensanmateo_search.features.field_instance.inc
 */


/**
 * implements hook_features_template_info()
 */
function opensanmateo_search_features_template_info() {
  $content_types = variable_get('opesanmateo_search_content_types_to_index', array());
  $data = array();
  foreach($content_types as $content_type => $present) {
    $data[] = array(
      'entity_type' => 'node',
      'bundle_type' => $content_type,
      'field' => 'field_do_not_index',
      'plugin' => 'field_instance',
      'deleted' => !$present,
      'template' => 'opensanmateo_search_field_default_field_instances_dni_template'
    );
    $data[] = array(
      'entity_type' => 'node',
      'bundle_type' => $content_type,
      'field' => 'field_quicj_search',
      'plugin' => 'field_instance',
      'deleted' => !$present,
      'template' => 'opensanmateo_search_field_default_field_instances_qs_template'
    );
  }
  return $data;
}

/**
 * Implements hook_field_default_field_instances_template().
 */
function opensanmateo_search_field_default_field_instances_dni_template() {
  $field_instances = array();

  // Exported field_instance: 'node-site_page-field_do_not_index'
  $field_instances['node-site_page-field_do_not_index'] = array(
    'bundle' => 'site_page',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_do_not_index',
    'label' => 'Do Not Index',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Do Not Index');

  return $field_instances;
}
