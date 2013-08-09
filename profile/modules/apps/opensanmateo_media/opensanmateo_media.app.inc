<?php
/**
 * @file
 *
 * Provide Apps integration via API hooks
 */

function opensanmateo_media_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_media_app_configure_form', // This form will be render on the app config pag
    'status callback' => 'opensanmateo_media_status',
  );
}

function opensanmateo_media_app_configure_form() {
  $form = array();
  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_media_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  return $status;
}
