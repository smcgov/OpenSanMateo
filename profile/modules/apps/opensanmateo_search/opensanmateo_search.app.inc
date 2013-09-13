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

  $form['opensanmateo_search_content_types_to_not_index'] = array(
    '#title' => t('Content to exclude from Index'),
    '#type' => 'checkboxes',
    '#options' => array_map(function($i) {return $i->name;}, node_type_get_types()),
    '#default_value' => variable_get('opensanmateo_search_content_types_to_not_index', array())
  );
  $types = array('image' => 'Image');
  $form['opensanmateo_search_file_types_to_index'] = array(
    '#title' => t('File Types to Index'),
    '#type' => 'checkboxes',
    '#options' => $types,
    '#default_value' => variable_get('opensanmateo_search_file_types_to_index', array())
  );

  $form['opensanmateo_search_term_facets'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('opensanmateo_search_term_facets', ''),
    '#title' => t('Term Facets'),
    '#description' => t('Here one can create new term facets, please put the Administrative title of the facet one per line, then a block will be create for this facet'),
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_search_app_configure_form_submit';
  return $form;
}
function opensanmateo_search_app_configure_form_submit($form,$form_state) {
  features_template_revert();
  foreach(opensanmateo_search_get_term_facets() as $id => $name) {
    $adapter = facetapi_adapter_load('search_api@san_mateo_content_index');
    $facet = facetapi_facet_load($id, 'search_api@san_mateo_content_index');
    $realm = facetapi_realm_load('block');
    facetapi_save_facet_status($adapter, $realm, $facet, 1, FALSE, FALSE);

  }

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
  $qs_index = search_api_index_load('san_mateo_quick_search_index');
  $status['items']['index'] = array(
      #'severity' =>    REQUIREMENT_WARNING, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
      'title' => 'Default State of Indexes',
      'action' => array(
        l("Edit Content Index", "admin/config/search/search_api/index/san_mateo_content_index/edit",  array('query'  => drupal_get_destination())),
        l("Edit Quick Search Index", "admin/config/search/search_api/index/san_mateo_quick_search_index/edit",  array('query'  => drupal_get_destination()))
      ),
      'description' => t("All Indexes are Default"),
      'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
    );
  

  if (($index->status & ENTITY_OVERRIDDEN) == ENTITY_OVERRIDDEN) {
    $status['items']['index']['descriptions']['content'] = t("The content Server settings are not in the default state this could make thing not work properly");
    $status['items']['index']['severity'] = REQUIREMENT_WARNING;
    $status['items']['index']['action'][] = l("Revert Content Index", "admin/config/search/search_api/index/san_mateo_content_index/delete",  array('query' => drupal_get_destination()));

  }
  if (($qs_index->status & ENTITY_OVERRIDDEN) == ENTITY_OVERRIDDEN) {
    $status['items']['index']['descriptions']['qs'] = t("The content Server settings are not in the default state this could make thing not work properly");
    $status['items']['index']['severity'] = REQUIREMENT_WARNING;
    $status['items']['index']['action'][] = l("Revert Quick Search Index", "admin/config/search/search_api/index/san_mateo_quick_search_index/delete",  array('query' => drupal_get_destination()));

  }
  if(isset($status['items']['index']['descriptions'])) {
    $status['items']['index']['description'] = implode("<br />", $status['items']['index']['descriptions']);
  
  }

  $istatus = search_api_index_status($index);
  $percentage = ($istatus['total']) ? (int) (100 * $istatus['indexed'] / $istatus['total']) : 0;
  $status['items']['index_status'] = array(
    'title' => 'Content Index Status',
    'action'=> array(l("Index/re-index Items", "admin/config/search/search_api/index/san_mateo_content_index/status",  array('query' => drupal_get_destination()))),
    'description' => t('About @percentage% of all items have been indexed in their latest version (@indexed / @total).', array('@indexed' => $istatus['indexed'], '@total' => $istatus['total'], '@percentage' => $percentage)),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
  );
  if ($percentage == 0) {
    $status['items']['index_status']['severity'] = REQUIREMENT_ERROR;
  }
  elseif ($percentage <100) {
    $status['items']['index_status']['severity'] = REQUIREMENT_WARNING;
  }

  $istatus = search_api_index_status($qs_index);
  $percentage = ($istatus['total']) ? (int) (100 * $istatus['indexed'] / $istatus['total']) : 0;
  $status['items']['qs_index_status'] = array(
    'title' => 'Quick Search Index Status',
    'action'=> array(l("Index/re-index Items", "admin/config/search/search_api/index/san_mateo_quick_search_index/status",  array('query' => drupal_get_destination()))),
    'description' => t('About @percentage% of all items have been indexed in their latest version (@indexed / @total).', array('@indexed' => $istatus['indexed'], '@total' => $istatus['total'], '@percentage' => $percentage)),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO, REQUIREMENT_ERROR
  );
  if ($percentage == 0) {
    $status['items']['qs_index_status']['severity'] = REQUIREMENT_ERROR;
  }
  elseif ($percentage <100) {
    $status['items']['qs_index_status']['severity'] = REQUIREMENT_WARNING;
  }






  return $status;
}
