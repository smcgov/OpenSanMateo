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
  $tasks = openpublic_install_tasks($install_state);

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
/*
  // Add our own profile tasks here
  $tasks['sanmateo_enable_modules'] = array(
    'function' => '_sanmateo_enable_modules',
    'display' => TRUE,
    'display_name' => st('Enable remaining modules for OpenSanMateo'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  $tasks['sanmateo_db_records'] = array(
    'function' => '_sanmateo_db_records',
    'display' => TRUE,
    'display_name' => st('Generate custom DB records'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  $tasks['sanmateo_imce_roles'] = array(
    'function' => '_sanmateo_imce_roles',
    'display' => TRUE,
    'display_name' => st('Set the IMCE roles profile for OpenSanMateo'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );

  $tasks['sanmateo_imce_overwrite'] = array(
    'function' => '_sanmateo_imce_overwrite',
    'display' => TRUE,
    'display_name' => st('Sets IMCE settings default to overwrite file.'),
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
*/
  //datatables
  return $tasks;
}

/**
 * Implements callback for profile install task 'sanmateo_enable_modules'
 *
 * Responsible for enabling any problem modules that couldn't be installed via the .info file
 */
function _sanmateo_enable_modules() {
  module_enable(array(
  ));
}

/**
 * Manually sets custom table records
 */
function _sanmateo_db_records() {
}

/**
 * Sets the provided roles to a IMCE profile
 * TODO: This is a common task, build it so that only one code is used.
 */
function _sanmateo_imce_roles(){
  if (module_exists('imce') && module_exists('sanmateo_roles')) {
    $roles = array();
    foreach (user_roles() as $rid=>$role) {
      $roles[$rid] = array('weight'=> 0, 'public_pid'=> 1);
    }
    variable_set('imce_roles_profiles', $roles);
  }
}

/**
 * Sets IMCE File action default to overwrite
 */
function _sanmateo_imce_overwrite(){
  if (module_exists('imce')) {
    variable_set('imce_settings_replace', '1');
  }
}
