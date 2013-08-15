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
 * Util function for app/module/feature install hooks to set default perms once
 *
 * @param perms   Array keyed by role name, with array of perms to grant as the value
 */
function opensanmateo_roles_set_perms($perms) {
  // Pull roles, flip array to be name => rid
  $roles = array_flip(user_roles());

  // Iterate over roles and add permissions
  foreach ($perms as $role => $perms) {
    if (isset($roles[$role])) {
      user_role_change_permissions($roles[$role], array_fill_keys($perms, TRUE));
    }
  }
}