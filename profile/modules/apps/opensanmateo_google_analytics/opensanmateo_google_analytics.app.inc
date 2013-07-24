<?php

function opensanmateo_google_analytics_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_google_analytics_app_configure_form', // This form will be render on the app config pag
    'status callback' => 'opensanmateo_google_analytics_status',
  );
}

function opensanmateo_google_analytics_app_configure_form() {
  $form['account']['googleanalytics_account'] = array(
    '#title' => t('Web Property ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('googleanalytics_account', 'UA-'),
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => TRUE,
    '#description' => t('This ID is unique to each site you want to track separately, and is in the form of UA-xxxxxxx-yy. To get a Web Property ID, <a href="@analytics">register your site with Google Analytics</a>, or if you already have registered your site, go to your Google Analytics Settings page to see the ID next to every site profile. <a href="@webpropertyid">Find more information in the documentation</a>.', array('@analytics' => 'http://www.google.com/analytics/', '@webpropertyid' => url('https://developers.google.com/analytics/resources/concepts/gaConceptsAccounts', array('fragment' => 'webProperty')))),
  );
  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_google_analytics_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  //set up the solr server status item
  $status['items']['google_analytics'] = array(
    'title' => 'Google Analytics web property ID',
    'action' => array(l("View analytics", "path/to/thing/to/do",  array('query'  => drupal_get_destination()))),
    'description' => t("Google Analytics ID has been set."),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );
  $id = variable_get('googleanalytics_account', 'UA-');
  if ($id == 'UA-' || empty($id)) {
    $status['items']['google_analytics']['description'] = t("Missing / invalid Web Property ID");
    $status['items']['google_analytics']['severity'] = REQUIREMENT_WARNING;
    $status['items']['google_analytics']['action'] = array(l("Configure the web property ID", "admin/apps/openpublic/app/opensanmateo_google_analytics/configure",  array('query' => drupal_get_destination())));
  }
  return $status;
}
