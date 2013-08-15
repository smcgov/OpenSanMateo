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

  return system_settings_form($form);
}
