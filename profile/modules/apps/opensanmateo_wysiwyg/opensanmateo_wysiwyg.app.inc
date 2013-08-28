<?php
/**
 * @file
 *
 * Provide Apps integration via API hooks
 */

function opensanmateo_wysiwyg_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_wysiwyg_app_configure_form', // This form will be render on the app config pag
    //'status callback' => 'opensanmateo_wysiwyg_status',
  );
}

function opensanmateo_wysiwyg_app_configure_form() {
  $form = array();

  // Add perms we want configurable from the apps page
  $perms = array(
    'administer filters',
    'use text format raw',
    'use text format full_html',
  );
  opensanmateo_roles_add_perms($form, $perms);

  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_wysiwyg_status() {
  //setup the status table
  $status = array(
    'title' => t('Status'),
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  return $status;
}
