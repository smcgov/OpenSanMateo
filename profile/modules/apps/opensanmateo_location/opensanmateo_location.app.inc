<?php

function opensanmateo_location_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_location_app_configure_form', // This form will be render on the app config pag
  );
}

function opensanmateo_location_app_configure_form() {
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
  features_template_revert();
}
