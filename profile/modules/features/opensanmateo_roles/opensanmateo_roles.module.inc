<?php
/**
 * @file
 * Contains module-level code we don't want to risk Features overwriting if something went wrong with a Feature update or recreate
 */

/**
 * Add permissions to an app config form.
 * Borrowed HEAVILY from user_admin_permissions
 *
 * @param form        App config form to add permissions to
 * @param cfg_perms   Array of app-specific permissions we want to make available on the config form
 */
function opensanmateo_roles_add_perms(&$form, $cfg_perms) {
  // Create new element tree to contain the perms portion of the form
  $form['app_config_perms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Permissions'),
    '#description' => t("These are the system permissions that control this app's behavior"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#theme' => 'user_admin_permissions',
    '#tree' => TRUE,
  );
  $perm_form = &$form['app_config_perms'];

  // Load all permissions from site
  $permissions = module_invoke_all('permission');

  // Load all role-perm mappings
  $role_names = user_roles();
  $role_permissions = user_role_permissions($role_names);

  // Store $role_names for use when saving the data.
  $perm_form['role_names'] = array(
    '#type' => 'value',
    '#value' => $role_names,
  );

  // Render role/permission overview:
  $options = array();
  $hide_descriptions = system_admin_compact_mode();

  // Iterate over our desired perms and add them to the form
  foreach ($cfg_perms as $perm) {
    // This is here to catch cases of fat-fingering or perms that have gone away for some reason (i.e. some associated but not dependency module has been disabled)
    if (!isset($permissions[$perm])) {
      continue;
    }
    $perm_item = $permissions[$perm];

    // Fill in default values for the permission.
    $perm_item += array(
      'description' => '',
      'restrict access' => FALSE,
      'warning' => !empty($perm_item['restrict access']) ? t('Warning: Give to trusted roles only; this permission has security implications.') : '',
    );
    $options[$perm] = '';
    $perm_form['permission'][$perm] = array(
      '#type' => 'item',
      '#markup' => $perm_item['title'],
      '#description' => theme('user_permission_description', array('permission_item' => $perm_item, 'hide' => $hide_descriptions)),
    );
    foreach ($role_names as $rid => $name) {
      // Builds arrays for checked boxes for each role
      if (isset($role_permissions[$rid][$perm])) {
        $status[$rid][] = $perm;
      }
    }
  }

  // Have to build checkboxes here after checkbox arrays are built
  foreach ($role_names as $rid => $name) {
    $perm_form['checkboxes'][$rid] = array(
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => isset($status[$rid]) ? $status[$rid] : array(),
      '#attributes' => array('class' => array('rid-' . $rid)),
    );
    $perm_form['role_names'][$rid] = array('#markup' => check_plain($name), '#tree' => TRUE);
  }

  // Add core JS code and our own custom submit handler
  $form['#attached']['js'][] = drupal_get_path('module', 'user') . '/user.permissions.js';
  $form['#submit'][] = 'opensanmateo_roles_submit_perms';
}

/**
 * Submit callback for app config permissions.
 * Copied almost verbatim from user_admin_permissions_submit, sans confirmation message.
 *
 * NOTE that the app_config_perms value tree is removed after processing so that any use of system_settings_form doesn't wind up saving our values out.
 */
function opensanmateo_roles_submit_perms($form, &$form_state) {
  foreach ($form_state['values']['app_config_perms']['role_names'] as $rid => $name) {
    user_role_change_permissions($rid, $form_state['values']['app_config_perms']['checkboxes'][$rid]);
  }
  unset($form_state['values']['app_config_perms']);
}

/**
 * Implements hook_user_role_insert
 *
 * Perform one-time initializations when a role is added
 */
function opensanmateo_roles_user_role_insert($role) {
  opensanmateo_roles_set_default_perms();
}

/**
 * Implements hook_modules_enabled
 *
 * Perform one-time initializations when a module is installed
 */
function opensanmateo_roles_modules_enabled() {
  opensanmateo_roles_set_default_perms();
}

/**
 * Implements hook_modules_uninstalled
 *
 * Perform one-time un-initializations when a module is uninstalled
 */
function opensanmateo_roles_modules_uninstalled($modules) {
  $cfg = _opensanmateo_roles_cfg();

  // Clear our status info for modules being uninstalled
  foreach ($modules as $module) {
    if (isset($cfg['$module'])) {
      unset($cfg['$module']);
    }
  }
  _opensanmateo_roles_cfg($cfg);
}

/**
 * Implements hook_taxonomy_vocabulary_insert
 */
function hook_taxonomy_vocabulary_insert($vocabulary) {
  opensanmateo_roles_set_default_perms();
}

/**
 * Implements hook_taxonomy_vocabulary_update
 */
function hook_taxonomy_vocabulary_update($vocabulary) {
  opensanmateo_roles_set_default_perms();
}

/**
 * Util method to abstract perms setup
 */
function opensanmateo_roles_set_default_perms() {
  register_shutdown_function('_opensanmateo_roles_set_default_perms_shutdown');
}

/**
 * Public method to enable default module perms
 */
function _opensanmateo_roles_set_default_perms_shutdown() {
  module_load_include('inc', 'opensanmateo_roles', 'opensanmateo_roles.defperms');
  $cfg = _opensanmateo_roles_cfg();

  // Force a reload of modules and perms hooks, retrieve all perms
  module_implements('permission', FALSE, TRUE);
  $all_perms = user_permission_get_modules();

  // Iterate over modules-perms-roles and set default perms
  $def_perms = _opensanmateo_roles_def_perms();
  $roles = array_flip(user_roles());
  foreach ($def_perms as $module => $perms) {
    foreach ($perms as $perm => $perm_roles) {
      if (isset($all_perms[$perm])) {
        foreach ($perm_roles as $role => $perm_val) {
          if (isset($roles[$role]) && !isset($cfg[$module][$perm][$role])) {
            // Set the perm
            _opensanmateo_roles_debug("$perm: $role = " . ($perm_val ? 'TRUE' : 'FALSE'));
            user_role_change_permissions($roles[$role], array($perm => $perm_val));

            // Flag this perm as being defaulted so we don't do it again until the module is uninstalled
            $cfg[$module][$perm][$role] = $perm_val;
          }
        }
      }
    }
  }

  // Update module status variable
  _opensanmateo_roles_cfg($cfg);
}

/**
 * Helper function for perms config variable
 */
function _opensanmateo_roles_cfg($cfg = NULL) {
  if (NULL !== $cfg) {
    variable_set('opensanmateo_roles_def_perms', $cfg);
  }
  return variable_get('opensanmateo_roles_def_perms', array());
}

/**
 * Util function for devel
 */
function _opensanmateo_roles_debug($msg) {
  if (!variable_get('opensanmateo_debug', FALSE)) {
    return;
  }
  $fmt_msg = (!is_string($msg) && (is_array($msg) || is_object($msg))) ? '<pre>' . print_r($msg, TRUE) . '</pre>' : $msg;
  if (function_exists('dpm')) {
    dpm(msg);
  }
  else {
    drupal_set_message($fmt_msg);
  }
  if (function_exists('watchdog')) {
    watchdog('opensanmateo_roles', $fmt_msg, array(), WATCHDOG_DEBUG);
  }
  file_put_contents('./opensanmateo_roles.log', "$fmt_msg\n", FILE_APPEND);
}
