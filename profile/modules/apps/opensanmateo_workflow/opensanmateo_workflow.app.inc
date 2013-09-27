<?php

function opensanmateo_workflow_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_workflow_app_configure_form',
    'status callback' => 'opensanmateo_workflow_status',
  );
}

function opensanmateo_workflow_app_configure_form() {
  $form = array();
  return system_settings_form($form);
}

/**
 * implements pseudo hook appname_app_Status
 */
function opensanmateo_workflow_status() {
  $status = array(
    'title' =>'Status',
    'headers' => array('severity', 'title', 'description', 'action'),
    'items' => array(),
  );
  
  $content_types = node_type_get_types();
  ksort($content_types);  
  
  foreach ($content_types as $content_type) {
    $options = variable_get('node_options_' . $content_type->type);
    $workflow_enabled = in_array('moderation', $options) ? TRUE : FALSE;
    $status['items'][$content_type->type] = array(
      'title' => $content_type->name,
      'description' => $workflow_enabled ? t("Workflow enabled for this content type.") : t("Workflow is not enabled for this content type."),
      'severity' => $workflow_enabled ? REQUIREMENT_OK : REQUIREMENT_INFO,
      'action' => ''
    );
  } 
  $status['items']['workbench_conf'] = array(
    'title' => t("Workbench configuration"),
    'description' => t("Review Workbench states, transitions and check permissions."),
    'severity' => REQUIREMENT_INFO,
    'action' => array(l("settings", "admin/config/workbench/moderation",  array('query'  => drupal_get_destination()))),
  );
  return $status;
} 