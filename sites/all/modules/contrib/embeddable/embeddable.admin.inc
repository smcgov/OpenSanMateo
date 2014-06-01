<?php
/**
 *  Provide the admin configuration form for embeddable
 */
function embeddable_admin_form ($form, &$form_state){
  $nodes = entity_get_info('node');
  
  $bundles = $nodes['bundles'];
  
  $bundle_options = array();
  foreach($bundles as $key => $value){
    $bundle_options[$key] = $value['label'];
  }
  
  //allowed content types
  $form['embeddable_default_node_bundles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allowed Content Types'),
    '#description' => t('Limits the content types that can be embedded.  To allow all content types, simply leave this field blank (check no options).'),
    '#options' => $bundle_options,
    '#default_value' => variable_get('embeddable_default_node_bundles', array()),
  );  
  
  $view_mode_options = array();
  foreach($nodes['view modes'] as $key => $mode) {
    $view_mode_options[$key] = $mode['label'];
  }
  
  $form['embeddable_default_view_modes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allowed View Modes'),
    '#description' => t('Limits the view modes that can be used to render an embedded node. To allow all view modes, simply leave this field blank (check no options).'),
    '#options' => $view_mode_options,
    '#default_value' => variable_get('embeddable_default_view_modes', array()),
  );
  
  $form['embeddable_default_hide_title'] = array(
    '#title' => t('Hide Title'),
    '#description' => t('Hide the title of a rendered node.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('embeddable_default_hide_title', 0),
  );
  
  $form['embeddable_default_hide_links'] = array(
    '#title' => t('Hide Links'),
    '#description' => t('Hide the read more, ect links on a rendered node.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('embeddable_default_hide_links', 0),
  );
  
  return system_settings_form($form);
}