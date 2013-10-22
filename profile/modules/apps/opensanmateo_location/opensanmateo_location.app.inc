<?php

/**
 * Implements hook_apps_app_info().
 */
function opensanmateo_location_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_location_app_configure_form', // This form will be render on the app config page
    'status callback' => 'opensanmateo_location_status',
  );
}

/**
 * App config form.
 */
function opensanmateo_location_app_configure_form() {
  $options = array_map(function($i) {return $i->name;}, node_type_get_types());
  // Prevent locations from being added to themselves.
  if (!empty($options['location'])) {
    unset($options['location']);
  }

  $form['opensanmateo_location_content_types_with_location'] = array(
    '#title' => t('Content with Location'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('opensanmateo_location_content_types_with_location', array())
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_location_app_configure_form_submit';
  return $form;
}

/**
 * App config submit function.
 */
function opensanmateo_location_app_configure_form_submit($form,$form_state) {
  features_template_revert();
}


/**
 * App status callback.
 */
function opensanmateo_location_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );
  $types_with_location = variable_get('opensanmateo_location_content_types_with_location', array());


  //set up the solr server status item
  $status['items']['event'] = array(
    'title' => 'Location Enabled on Event',
    'action' => array(),
    'description' => t("Location is currently enabled on event"),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );

   //set up the solr server status item
  $status['items']['services'] = array(
    'title' => 'Location Enabled on Services',
    'action' => array(),
    'description' => t("Location is currently enabled on services"),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );

  if (empty($types_with_location['event'])) {
    $status['items']['event']['description'] = t("Location is NOT currently enabled on event.");
    $status['items']['event']['severity'] = REQUIREMENT_WARNING;
    $status['items']['event']['action'][] = '';
  }

  if (empty($types_with_location['services'])) {
    $status['items']['services']['description'] = t("Location is NOT currently enabled on services.");
    $status['items']['services']['severity'] = REQUIREMENT_WARNING;
    $status['items']['services']['action'][] = '';
  }

  return $status;
}
