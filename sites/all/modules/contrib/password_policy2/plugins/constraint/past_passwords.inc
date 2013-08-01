<?php
$plugin = array(
  'admin form callback' => 'password_policy_past_passwords_count_admin_form',
  'constraint callback' =>  'password_policy_past_passwords_count_constraint',
  'message' => 'Password can not match past_passwords past passwords.',
  'default' => 0,
);

function password_policy_past_passwords_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['past_passwords'] = array(
    '#type' => 'textfield',
    '#title' => 'Check against Previous Passwords',
    '#default_value' => $constraint->config['past_passwords'],
    '#description' => "Password can not match this many previous passwords.",
  );
  return $sub_form;
}

function password_policy_past_passwords_count_constraint($password, $account, $constraint) {
  if (!$account) {
    $account = $user;
  }
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
  $count = $constraint->config['past_passwords'];
  $match = FALSE;
  //TODO: find out why the hook_user_load is not running correctly
  if (!isset($account->password_history)) {
    password_policy2_user_load(array($account->uid=>$account));
  }
  for ($i = 0 ; $i<$count ; $i++) {
    // if we have that level of depth see if we have a match
    if (isset($account->password_history[$i])) {
      $match = $match || user_check_password($password, $account->password_history[$i]);
    }
    // if we do not have that amount of history then break out
    else {
      break;
    }
  }
  return !$match;
}
