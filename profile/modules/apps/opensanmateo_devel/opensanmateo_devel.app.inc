<?php

/**
 * implements hook_apps_app_info()
 */
function opensanmateo_devel_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_devel_app_configure_form', // This form will be render on the app config pag
  );
}

/**
 * quasi hook_app_configure_form
 */
function opensanmateo_devel_app_configure_form() {
  $form = array();
  $form['taxonomy_sync']['opensanmateo_devel_is_master'] = array(
    '#type' => 'checkbox',
    '#description' => t('Is this the master site?'),
    '#default_value' =>  variable_get('opensanmateo_devel_is_master', FALSE),
    '#title' => t("Is This the master site"),

  );
  $form['taxonomy_sync']['opensanmateo_devel_master_is'] = array(
    '#type' => 'textfield',
    '#description' => t('If this site is not the master what is the master site (e.g. sanmateo.gov)'),
    '#default_value' =>  variable_get('opensanmateo_devel_master_is', FALSE),
    '#title' => t("URI of Master site"),
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_devel_app_configure_form_submit';
  return $form;
}

/**
 * submit for our app config page.
 *
 * We set the correct regex for the openid_autocreate module
 */
function opensanmateo_devel_app_configure_form_submit($form,$form_state) {
  sanmateo_set_is_master(variable_get('opensanmateo_devel_is_master', FALSE));
  sanmateo_set_master_is(variable_get('opensanmateo_devel_master_is', FALSE));
}
