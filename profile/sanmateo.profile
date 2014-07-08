<?php

/**
 * Implements hook_apps_servers_info
*/
function sanmateo_apps_servers_info() {
 return array(
   'openpublic' => array(
     'title' => 'OpenPublic',
     'description' => "Apps for the Openpublic distribution",
     'manifest' => 'http://appserver.openpublicapp.com/app/query/opensanmateo',
     'profile' => 'openpublic',
     'profile_version' => '7.x-1.0-beta5',
     'server_name' => $_SERVER['SERVER_NAME'],
     'server_ip' => $_SERVER['SERVER_ADDR'],
   ),
 );
}

/**
 * Implements hook_install_tasks().
 */
function sanmateo_install_tasks($install_state) {
  // Load default task list for OpenPublic distro
  require_once(drupal_get_path('module', 'apps') . '/apps.profile.inc');
  $server = array(
    'machine name' => 'openpublic',
    'default apps' => array(
      'phase2_page',
      'opensanmateo_search',
      'phase2_document',
      'openpublic_service',
      'opensanmateo_event',
      'opensanmateo_location',
      'opensanmateo_shared_content',
      'opensanmateo_search',
      'opensanmateo_shared_users',
      'opensanmateo_layout',
      'opensanmateo_wysiwyg',
      'opensanmateo_rotator',
      'opensanmateo_socialmedia',
      'opensanmateo_contentreview',
      'opensanmateo_redirect',
      'opensanmateo_translate'
    ),
    'required apps' => array(
      'opensanmateo_security',
      'opensanmateo_resp_images',
      'opensanmateo_google_analytics'
    ),
    'default content callback' => '',
  );
  $tasks = apps_profile_install_tasks($install_state, $server);


  // Remove undesired OPIC install tasks
  $skip_tasks = array(
    'apps_install_verify',
  //  'apps_profile_apps_select_form_openpublic',
  );
  foreach ($skip_tasks as $task) {
    if (isset($tasks[$task])) {
      unset($tasks[$task]);
    }
  }

  // Add our own profile tasks here
  $tasks['sanmateo_update_master_client'] = array(
    'function' => 'sanmateo_update_master_client',
    'display' => TRUE,
    'display_name' => st('Finalize master-client settings'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  $tasks['sanmateo_features_template_revert'] = array(
    'function' => 'features_template_revert',
    'display' => TRUE,
    'display_name' => st('Enable templated components'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  $tasks['sanmateo_features_template_revert2'] = array(
    'function' => 'features_template_revert',
    'display' => FALSE,
    'display_name' => st('Enable templated components'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  $tasks['sanmateo_create_basic_pages'] = array(
    'function' => 'sanmateo_create_basic_pages',
    'display' => TRUE,
    'display_name' => st('Create Default Pages'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  return $tasks;
}

function sanmateo_create_basic_pages() {
   $node = sanmateo_create_node('site_page', "Home Page", array("field_custom_layout"=>1));
   variable_set("site_frontpage", "node/{$node->nid}");
}

function sanmateo_update_master_client() {
  sanmateo_is_master();
  sanmateo_master_is();
}

function sanmateo_is_master($is_master = NULL) {
  if(isset($is_master)) {
    variable_set("sanmateo_is_master", $is_master);
  }
  $is_master = variable_get("sanmateo_is_master", FALSE);
  module_invoke_all("sanmateo_is_master_set", $is_master);
  return $is_master;
}

function sanmateo_master_is($master = NULL) {
  if(isset($master)) {
    variable_set("sanmateo_master_is", $master);
  }
  $master = variable_get("sanmateo_master_is", $master);
  module_invoke_all("sanmateo_master_is_set", $master);
  return $master;
}

/**
 * Implementation of hook_form_FORM_ID_alter().
 * Alter the installation form to set United States as the default country and PT as the timezone
 */
function sanmateo_form_install_configure_form_alter(&$form, $form_state) {
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Los_Angeles';
  $form['server_settings']['date_default_timezone']['#attributes']['class'] = array();

  $form['update_notifications']['update_status_module']['#default_value'] = array();
}

/**
 * Implements hook_taxonomy_default_vocabularies_alter().
 *
 * Remove openpublic vocabularies we don't want.
 */
function sanmateo_taxonomy_default_vocabularies_alter(&$vocabularies) {
  if (!empty($vocabularies['document_terms'])) {
    unset($vocabularies['document_terms']);
  }

  if (!empty($vocabularies['blog_terms'])) {
    unset($vocabularies['blog_terms']);
  }
}
/**
 * Create a node programticly
 */
function sanmateo_create_node($type = 'site_page', $title = '', $fields = array()) {
  $node = new stdClass(); // Create a new node object
  $node->type = $type; // Or page, or whatever content type you like
  node_object_prepare($node); // Set some default values
  // If you update an existing node instead of creating a new one,
  // comment out the three lines above and uncomment the following:
  // $node = node_load($nid); // ...where $nid is the node id

  $node->title    = $title;
  $node->language = LANGUAGE_NONE; // Or e.g. 'en' if locale is enabled

  $node->uid = 1; // UID of the author of the node; or use $node->name

  foreach($fields as $field=>$value) {
    if($field == 'body') {
      $node->body[$node->language][0]['value']   = $bodytext;
      $node->body[$node->language][0]['summary'] = text_summary($bodytext);
      $node->body[$node->language][0]['format']  = 'filtered_html';
    }
    else {
      $node->{$field}[$node->language][0]['value'] = $value;
      
    }

  }
  if($node = node_submit($node)) { // Prepare node for saving
      node_save($node);
  }
  return $node;
}

