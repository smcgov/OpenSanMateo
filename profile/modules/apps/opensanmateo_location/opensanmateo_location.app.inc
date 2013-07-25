<?php
function opensanmateo_location_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_location_app_configure_form', // This form will be render on the app config pag
    'status callback' => 'opensanmateo_location_status',
  );
}

function opensanmateo_location_app_configure_form() {
  $form = array(
    'opensanmateo_location_thing' => array(
      '#title' => t('Thing'),
      '#type' => 'textfield',
      '#default_value' => variable_get('opensanmateo_location_thing', '')
    ),
  ); 
  $form['opensanmateo_location_content_types_with_location'] = array(
    '#title' => t('Content with Location'),
    '#type' => 'checkboxes',
    '#options' => array_map(function($i) {return $i->name;}, node_type_get_types()),
    '#default_value' => variable_get('opensanmateo_location_content_types_with_location', array())
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_location_app_configure_form_submit';
  return $form;
}
function opensanmateo_location_app_configure_form_submit($form,$form_state) {
  #features_template_revert();
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_location_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  //set up the solr server status item
  $status['items']['server'] = array(
    'title' => 'Example status',
    'action' => array(l("Do something", "path/to/thing/to/do",  array('query'  => drupal_get_destination()))),
    'description' => t("Tell us about the the current state"),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );
  if ("some test on the status"==FALSE) {
    $status['items']['server']['description'] = t("change the desc");
    $status['items']['server']['severity'] = REQUIREMENT_WARNING;
    $status['items']['server']['action'][] = l("different thing to do", "path/to/different/thing/to/do",  array('query' => drupal_get_destination()));

  }

  return $status;
}
