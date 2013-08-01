<?php
$plugin = array(
  'admin form callback' => 'password_policy_consecutive_admin_form',
  'constraint callback' =>  'password_policy_consecutive_constraint',
  'message' => 'Password can not have consecutive_char_count consecutive letters',
  'prime value' => 'consecutive_char_count',
  'config' => array(
    'consecutive_char_count' => NULL,
  ),
);

function password_policy_consecutive_admin_form($form, &$form_state, $constraint) {
  $sub_form['consecutive_char_count'] = array(
    '#type' => 'textfield',
    '#title' => ' Consecutive Character Count',
    '#default_value' => $constraint->config['consecutive_char_count'],
    '#description' => "Password can not have more than this number of identical consecutive characters",
  );
  return $sub_form;
}

function password_policy_consecutive_constraint($password, $account, $constraint) {
  $count = $constraint->config['consecutive_char_count'];
  $regex_string = "/(.)";
  if ($count && $count > 1) {
    for ($i = 1 ; $i<$count; $i++) {
      $regex_string .='\1';
    }
  }
  else {
    return TRUE;
  }
  $regex_string .= '/';
  return !preg_match($regex_string, $password);
  
}
