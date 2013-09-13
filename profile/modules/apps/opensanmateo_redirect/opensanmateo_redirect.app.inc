<?php
function opensanmateo_redirect_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_redirect_app_configure_form', // This form will be render on the app config pag
  );
}

function opensanmateo_redirect_app_configure_form() {
  $form = array();

  $form['config_link'] = array(
    '#markup' => '<p>' . l(t('Manage Redirects'), 'admin/config/search/redirect') . '</p>',
  );

  $form['url_config'] = array(
    '#markup' => '<p>' . l(t('Manage URL Aliases'), 'admin/config/search/path/patterns'). '</p>',
  );

  return $form;
}

