<?php

function opensanmateo_workflow_access_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_workflow_access_configure_form',
    'status callback' => 'opensanmateo_workflow_access_status',
  );
}

function opensanmateo_workflow_access_configure_form() {
  $form = array();
  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_status()
 */
function opensanmateo_workflow_access_status() {
  //setup the status table
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );


  $status['items']['workbench_access'] = array(
    'title' => 'Workbench Access',
    'action' => array(l("Administer settings", "admin/config/workbench/access/settings",  array('query'  => drupal_get_destination()))),
    'description' => t("Workbench access seems to be configured."),
    'severity' =>    REQUIREMENT_OK, //REQUIREMENT_OK REQUIREMENT_INFO,REQUIREMENT_WARNING, REQUIREMENT_ERROR
  );
  
  // Get the user options.
  $options = workbench_access_active_options();
  
  if (empty($options) && !variable_get('workbench_access', FALSE)) {
    $status['items']['workbench_access']['description'] = workbench_access_configuration_needed_message();
    $status['items']['workbench_access']['severity'] = REQUIREMENT_ERROR;
  }
  else {
    $status['items']['users'] = array(
      'title' => 'Users',
      'action' => array(l("Change users for sections", "admin/config/workbench/access",  array('query'  => drupal_get_destination()))),
      'description' => t("Administer which users can edit which sections."),
      'severity' =>    REQUIREMENT_INFO,
    );
    $status['items']['roles'] = array(
      'title' => 'Roles',
      'action' => array(l("Change roles for sections", "admin/config/workbench/access/roles",  array('query'  => drupal_get_destination()))),
      'description' => t("Administer which roles can edit which sections."),
      'severity' =>    REQUIREMENT_INFO,
    );
    $status['items']['sections'] = array(
      'title' => 'Sections',
      'action' => array(l("Change editors for sections", "admin/config/workbench/access/sections",  array('query'  => drupal_get_destination()))),
      'description' => t("Administer your sections."),
      'severity' =>    REQUIREMENT_INFO,
    );
  }
  return $status;
}