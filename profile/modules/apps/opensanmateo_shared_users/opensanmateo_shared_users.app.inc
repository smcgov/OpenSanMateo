<?php

/**
 * implements hook_apps_app_info()
 */
function opensanmateo_shared_users_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_shared_users_app_configure_form', // This form will be render on the app config pag
  );
}

