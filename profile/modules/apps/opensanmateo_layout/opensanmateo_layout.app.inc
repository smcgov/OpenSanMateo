<?php
function opensanmateo_layout_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_layout_app_configure_form', // This form will be render on the app config pag
    'status callback' => 'opensanmateo_layout_status',
  );
}

function opensanmateo_layout_app_configure_form() {
  $form = array(
    'opensanmateo_layout_thing' => array(
      '#title' => t('Thing'),
      '#type' => 'textfield',
      '#default_value' => variable_get('opensanmateo_layout_thing', '')
    ),
  );
  $form['opesanmateo_layout_content_types_to_panelize'] = array(
    '#title' => t('Content to Index'),
    '#type' => 'checkboxes',
    '#options' => array_map(function($i) {return $i->name;}, node_type_get_types()),
    '#default_value' => variable_get('opesanmateo_layout_content_types_to_panelize', array())
  );
  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_layout_status() {
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
