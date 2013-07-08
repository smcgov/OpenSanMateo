<?php
function opensanmateo_search_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_search_app_configure_form', // This form will be render on the app config pag
    'status callback' => 'opensanmateo_search_status',
  );
}

function opensanmateo_search_app_configure_form() {
  $form = array(
    'opensanmateo_search_solr_url' => array(
      '#title' => t('Solr Url'),
      '#type' => 'textfield',
      '#default_value' => variable_get('opensanmateo_search_solr_url', '')
    ),
  );

  $form['opesanmateo_search_content_types_to_index'] = array(
    '#title' => t('Content to Index'),
    '#type' => 'checkboxes',
    '#options' => array_map(function($i) {return $i->name;}, node_type_get_types()),
    '#default_value' => variable_get('opesanmateo_search_content_types_to_index', array())
  );
  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_search_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  //set up the solr server status item
  $server = search_api_server_load('san_mateo_solr_server');
  $status['items']['server'] = array(
      #'severity' =>    REQUIREMENT_WARNING, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
      'title' => 'Solr Server',
      'action' => array(l("Edit", "admin/config/search/search_api/server/san_mateo_solr_server/edit",  array('query'  => drupal_get_destination()))),
      'description' => t("The solr Server settings are currently Default"),
      'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
    );
  if (($server->status & ENTITY_OVERRIDDEN) == ENTITY_OVERRIDDEN) {
    $status['items']['server']['description'] = t("The SOLR Server settings are not in the default state, this could prevent search from functioning properly.");
    $status['items']['server']['severity'] = REQUIREMENT_WARNING;
    $status['items']['server']['action'][] = l("Revert", "admin/config/search/search_api/server/san_mateo_solr_server/delete",  array('query' => drupal_get_destination()));

  }

  //set up the content index status item
  $index = search_api_index_load('san_mateo_content_index');
  $status['items']['index'] = array(
      #'severity' =>    REQUIREMENT_WARNING, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
      'title' => 'Content Index',
      'action' => array(l("Edit", "admin/config/search/search_api/index/san_mateo_content_index/edit",  array('query'  => drupal_get_destination()))),
      'description' => t("The content Server settings are currently Default"),
      'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
    );
  if (($index->status & ENTITY_OVERRIDDEN) == ENTITY_OVERRIDDEN) {
    $status['items']['index']['description'] = t("The content Server settings are not in the default state this could make thing not work properly");
    $status['items']['index']['severity'] = REQUIREMENT_WARNING;
    $status['items']['index']['action'][] = l("Revert", "admin/config/search/search_api/index/san_mateo_content_index/delete",  array('query' => drupal_get_destination()));

  }


  return $status;
}
