<?php

function opensanmateo_layout_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_layout_app_configure_form', // This form will be render on the app config pag
    'status callback' => 'opensanmateo_layout_status',
  );
}

function opensanmateo_layout_app_configure_form() {
  $form = array();
  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_layout_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );

  //set up the solr server status item
  $status['items']['master_site'] = array(
    'title' => 'Master Site',
    'action' => array(l("Change this setting", "admin/config/system/distributed_blocks",  array('query'  => drupal_get_destination()))),
    'description' => t("This is the master site (certain blocks may be exposed)."),
    'severity' =>    REQUIREMENT_INFO, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );
  
  if (variable_get('distributed_blocks_expose', FALSE) == FALSE) {
    $status['items']['master_site']['description'] = t("This is not a master site (no blocks are exposed).");
  }
  else {
    // This is only something we worry about on the master site
    $status['items']['banner_block'] = array(
      'title' => 'Banner Block',
      'action' => array(l("Change the block's contents", "admin/structure/block/manage/opensanmateo_layout/opensanmateo_layout_banner/configure",  array('query'  => drupal_get_destination()))),
      'description' => t("The banner block has content."),
      'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
    );
    if (variable_get('opensanmateo_layout_banner_content', '') == '') {
      $status['items']['banner_block']['description'] = t('The banner has no content.');
      $status['items']['banner_block']['severity'] = REQUIREMENT_WARNING;
    }
    $status['items']['banner_block_exposed'] = array(
      'title' => 'Banner Block Exposed',
      'action' => '',
      'description' => t("The banner block is exposed."),
      'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
    );
    $exposed_blocks = variable_get('distributed_blocks_exposed_blocks', array());
    
    if (empty($exposed_blocks) || empty($exposed_blocks['opensanmateo_layout|opensanmateo_layout_banner|Shared Banner'])) {
      $status['items']['banner_block_exposed']['description'] = t('The banner block is not exposed.');
      $status['items']['banner_block_exposed']['severity'] = REQUIREMENT_ERROR;
      $status['items']['banner_block_exposed']['action'] = array(l("Change this setting", "admin/config/system/distributed_blocks",  array('query'  => drupal_get_destination())));
    }
  }
  return $status;
}
