<?php
$plugin = array(
  'admin form callback' => 'password_policy_symbol_count_admin_form',
  'constraint callback' =>  'password_policy_symbol_count_constraint',
  'message' => 'Password must have at least symbol_count Symbols',
  'prime value' => 'symbol_count',
  'config' => array(
    'symbol_count' => 0,
    'symbol_count_symbols' => "!@#$%^&*()_+=-|}{\"?:><,./;'\[]",
  ),
);

function password_policy_symbol_count_admin_form($form, &$form_state, $constraint) {

  $sub_form['symbol_count_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Symbols',
  );
  $sub_form['symbol_count_fieldset']['symbol_count'] = array(
    '#type' => 'textfield',
    '#title' => 'Minimum Symbols',
    '#default_value' => $constraint->config['symbol_count'],
    '#description' => "Password will be required to have this many Symbols",
  );
  $sub_form['symbol_count_fieldset']['symbol_count_symobols'] = array(
    '#type' => 'textfield',
    '#title' => 'Symbol Chars.',
    '#default_value' => $constraint->config['symbol_count_symbols'],
    '#description' => "Which charaters are symbols",
  );
  return $sub_form;
}

function password_policy_symbol_count_constraint($password, $account, $constraint) {
  $count = $constraint->config['symbol_count'];
  $symbols = addcslashes($constraint->config['symbol_count_symbols'], ']^\-/');
  $regex_string = "/.*";
  if ($count && $count > 0) {
    for ($i = 1 ; $i<=$count; $i++) {
      $regex_string .='[' . $symbols . '].*';
    }
  }
  $regex_string .= '/';
  return preg_match($regex_string, $password);
}
