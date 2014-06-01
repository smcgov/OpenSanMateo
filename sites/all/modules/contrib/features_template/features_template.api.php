<?php
/**
 * implements hook_features_template_info()
 *
 * RETURN an array of datum array that tell features template how 
 * and what items to make. they each have the following properties
 *   plugin: what features template template plugin to use
 *   template: where is the template that should be used to 
 *   construct components
 *   deleted: if marked true then features template will insure that 
 *   the component is removed.
 *   PLUGIN Variables:  Other items that are used by the plugin( 
 *   e.g. the field_instance plugin uses entity_type, buindle_type an field)
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
      'template' => 'opensanmateo_search_field_default_field_instances_template'
    );
  }
  return $data;
}


