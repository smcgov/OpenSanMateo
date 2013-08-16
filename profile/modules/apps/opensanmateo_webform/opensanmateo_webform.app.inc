<?php

function opensanmateo_webform_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_webform_app_configure_form', // This form will be render on the app config pag
  );
}

function opensanmateo_webform_app_configure_form() {
  $form = array();

  // Add perms we want configurable from the apps page
  $perms = array(
    'create webform content',
    'edit own webform content',
    'edit any webform content',
    'delete own webform content',
    'delete any webform content',
    'access all webform results',
    'access own webform results',
    'edit all webform submissions',
    'delete all webform submissions',
    'access own webform submissions',
    'edit own webform submissions',
    'delete own webform submissions',
  );
  opensanmateo_roles_add_perms($form, $perms);

  // Pull in View listing of Webforms in the system
  $form['opensanmateo_webform_list'] = array(
    '#prefix' => '<h2>' . t('Webforms') . '</h2>',
    '#markup' => views_embed_view('opensanmateo_webform', 'block'),
  );

  return system_settings_form($form);
}
