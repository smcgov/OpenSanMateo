<?php
$plugin = array(
  'embed callback' => 'embed_node'
);
function embed_node($info) {
  $nid = $info['nid'];
  $view_mode = isset($info['view_mode']) ? $info['view_mode'] : 'embed';
  $node = node_load($nid);
  
  // If the user is not allowed to view this node, do not render it
  if (!node_access('view', $node)) {
    return '';
  }
  
  //check to make sure the rules are being followed
  $allowed_bundles = variable_get('embeddable_default_node_bundles', array());
  if($allowed_bundles && !in_array($node->type, $allowed_bundles)){
    return ''; //we don't want to render this node
  }
  $allowed_modes = variable_get('embeddable_default_view_modes', array());
  //this has an extra thing to let people do 'embed' even if its not allowed (or real for that matter)
  if($allowed_modes && !in_array($view_mode, $allowed_modes) && $view_mode != 'embed'){
    return ''; //we dont want to render this
  }
  
  // Necessary to avoid notice in strict mode
  $render = node_view($node, $view_mode);
  
  //hide the links
  if(variable_get('embeddable_default_hide_links', 0)){
    unset($render['links']);
  }
  
  //hide the title
  if(variable_get('embeddable_default_hide_title', 0)){
    $render['#node']->title = '';
  }
  
  return drupal_render($render);
}

function node_wysiwyg_form(&$form, &$form_state) {
  //Restrict by bundle if configured
  $allowed_bundles = variable_get('embeddable_default_node_bundles', array());
  $path = 'entity-autocomplete/node';
  $allowed_bundles = array_filter($allowed_bundles);

  if ($allowed_bundles) {
    $path = 'entity-autocomplete/bundle/node/' . implode('+', $allowed_bundles);
  }
  
  $form['nid'] = array(
    '#type' => 'textfield',
    '#title' => 'Content',
    '#autocomplete_path' => $path
  );
  
  //restrict view_modes if configured
  $allowed_modes = variable_get('embeddable_default_view_modes', array());
  $allowed_modes = array_filter($allowed_modes);

  $info = entity_get_info("node");
  $view_mode_options = array();
  foreach($info['view modes'] as $key => $mode) {
    //only add the view_mode to the list if its in the allowed modes or allowed modes is empty
    if(!$allowed_modes || in_array($key, $allowed_modes)){
      $view_mode_options[$key] = $mode['label'];
    }
  }
  
  $form['view_mode'] = array(
    '#type' => 'select',
    '#options' => $view_mode_options,
    '#title' => 'View Mode',
  );
  
  //TODO: possibly add a validation function for the view_mode and bundle 
  //however, i think this is low on the list of needed as we've made it difficult to specify something invalide
}
// return array that of data that can be used to build
// node
function node_wysiwyg_submit(&$form, &$form_state) {
  $data['nid'] = entity_autocomplete_get_id($form_state['values']['nid']);
  $data['view_mode'] = $form_state['values']['view_mode'];
  return $data;
}

function node_wysiwyg_title($data) {
  $nid = entity_autocomplete_get_id($data['nid']);
  $node = node_load($nid);
  return "CONTENT: " . $node->title . " (". $node->type . ")";

}

