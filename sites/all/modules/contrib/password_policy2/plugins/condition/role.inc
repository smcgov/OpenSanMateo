<?php
$plugin = array(
  'admin form callback' => 'password_policy_role_admin_form',
  'condition callback' =>  'password_policy_role_condition',
  'prime value' => 'role_char_count',
  'config' => array(
    'roles' => array(),
  ),
);
function password_policy_role_admin_form($form, &$form_state, $condition) {
  $sub_form['role_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('By role'),
  );
  $sub_form['role_fieldset']['roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enabled for the following roles:'),
    '#default_value' => $condition->config['roles'],
    '#options' => user_roles(TRUE),
  );
  return $sub_form;
}
function password_policy_role_condition($account, $condition) {
  $match = FALSE;
  foreach ($account->roles as $id => $name) {
    if (isset($condition->config['roles'][$id])) {
      $match = $match || $condition->config['roles'][$id];
    }
  }
  return $match;
}
