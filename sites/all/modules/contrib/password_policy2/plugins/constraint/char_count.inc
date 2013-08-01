<?php
$plugin = array(
  'admin form callback' => 'password_policy_char_count_admin_form',
  'constraint callback' =>  'password_policy_char_count_constraint',
  'message' => 'Password must have at least char_count total characters ',
  'default' => 0,
);

function password_policy_char_count_admin_form($form, &$form_state, $constraint) {
  $sub_form['char_count'] = array(
    '#type' => 'textfield',
    '#title' => 'Minimum Total Characters',
    '#default_value' => $constraint->config['char_count'],
    '#description' => "Password will be required to have this many Characters",
  );
  return $sub_form;
}

function password_policy_char_count_constraint($password, $account, $constraint) {
  $count = $constraint->config['char_count'];
  if ($count > 0) {
    $regex_string = "/.{" . $count . ",}/";
    return preg_match($regex_string, $password);
  }
  return TRUE;
}
