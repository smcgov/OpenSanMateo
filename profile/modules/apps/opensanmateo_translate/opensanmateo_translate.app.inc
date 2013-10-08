<?php

/**
 * Implements hook_app_info().
 */
function opensanmateo_translate_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_translate_app_configure_form',
    'status callback' => 'opensanmateo_translate_status',
  );
}

/**
 * Provide app spectific settings.
 */
function opensanmateo_translate_app_configure_form() {
  return google_translator_settings_page();
}


/**
 * Provide the app status callback.
 */
function opensanmateo_translate_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  //set up the solr server status item
  $status['items']['menu_link'] = array(
    'title' => 'Translation link in footer',
    'action' => '',
    'description' => t("Create a menu link with &lt;google-translate&gt; as the path."),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );

  $query = db_select('menu_links', 'm')
           ->fields('m', array('mlid'))
           ->condition('menu_name', 'menu-footer-utility')
           ->condition('link_path', '<google-translate>')
           ->execute();

  $result = $query->rowCount();

  if (empty($result)) {
    $status['items']['menu_link']['severity'] = REQUIREMENT_WARNING;
    $status['items']['menu_link']['action'][] = l("Add the link", "admin/structure/menu/manage/menu-footer-utility/add",  array('query' => drupal_get_destination()));

  }

  return $status;
}
