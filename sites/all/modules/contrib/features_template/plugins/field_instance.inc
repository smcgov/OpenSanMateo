<?php
$plugin = array(
  'component' => 'field_instance',
  'implement callback' => 'features_template_field_instance',
  'features info callback' => 'features_template_field_instance_info',
  'deleted callback' => 'features_template_field_instance_delete',
);
function features_template_field_instance_info(&$info, $datum) {
  $key = features_template_field_instance_key($datum);
  if(!isset($info['features']['field_instance']) || !in_array($key, $info['features']['field_instance'])) {
    $info['features']['field_instance'][] = $key;
  }
}
function features_template_field_instance($template, $datum) {
  $key = features_template_field_instance_key($datum);
  $fields[$key] = reset($template);
  $fields[$key]['bundle'] = $datum['bundle_type'];
  $fields[$key]['entity_type'] = $datum['entity_type'];
  return $fields;
}

function features_template_field_instance_delete($datum) {
  $key = features_template_field_instance_key($datum);
  $instance = field_info_instance($datum['entity_type'], $datum['field'], $datum['bundle_type']);
  field_delete_instance($instance, FALSE);
}

function features_template_field_instance_key($datum) {
  return implode('-', array($datum['entity_type'], $datum['bundle_type'], $datum['field']));

}
