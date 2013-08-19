<?php

function opensanmateo_event_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_event_app_configure_form', // This form will be render on the app config pag
  );
}

function opensanmateo_event_app_configure_form() {
  $form = array();

  // Add perms we want configurable from the apps page
  $perms = array(
    'create event content',
    'edit own event content',
    'edit any event content',
    'delete own event content',
    'delete any event content',
  );
  opensanmateo_roles_add_perms($form, $perms);

  // Add content type selectors to add field_event to
  $form['opensanmateo_event_content_types_with_event'] = array(
    '#title' => t('Content with Event'),
    '#type' => 'checkboxes',
    '#options' => array_map(function($i) {return $i->name;}, node_type_get_types()),
    '#default_value' => variable_get('opensanmateo_event_content_types_with_event', array())
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_event_app_configure_form_submit';
  return $form;
}

function opensanmateo_event_app_configure_form_submit($form,$form_state) {
  features_template_revert();
}
