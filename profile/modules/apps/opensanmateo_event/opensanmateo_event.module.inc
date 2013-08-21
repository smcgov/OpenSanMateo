<?php
/**
 * @file
 * Contains module-level code we don't want to risk Features overwriting if something went wrong with a Feature update or recreate
 */

/**
 * Implements hook_features_template_info
 */
function opensanmateo_event_features_template_info() {
  $content_types = variable_get('opensanmateo_event_content_types_with_event', array());
  $data = array();
  foreach($content_types as $content_type => $present) {
    $data[] = array(
      'entity_type' => 'node',
      'bundle_type' => $content_type,
      'field' => 'field_event',
      'plugin' => 'field_instance',
      'deleted' => !$present,
      'template' => 'opensanmateo_event_features_template_field_event'
    );
  }
  return $data;
}

