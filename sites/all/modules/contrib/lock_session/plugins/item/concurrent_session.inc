<?php
$plugin = array(
  'admin form callback' => 'lock_session_concurrent_admin_form',
  'config' => array(
    'lock_session_concurrent' => 0,
    'lock_session_concurrent_message' => 'There are too many active sessions',
    'lock_session_timeout_message' => 'Your session has timed out, please authenticate.',
    'lock_session_timeout' => 0,
  ),
  'class' => 'LockSessionConcurrent',
);

/**
 * lock_session_concurrent_admin_form()
 */
function lock_session_concurrent_admin_form($form, &$form_state, $item) {

  $sub_form['session_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'Session Management',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $sub_form['session_fieldset']['lock_session_timeout'] = array(
    '#type' => 'textfield',
    '#title' => 'Lock Session After',
    '#default_value' => $item->config['lock_session_timeout'],
  );
  $sub_form['session_fieldset']['lock_session_timeout_message'] = array(
    '#type' => 'textarea',
    '#title' => 'Lock Session Message',
    '#default_value' => $item->config['lock_session_timeout_message'],
  );
  $sub_form['session_fieldset']['lock_session_concurrent'] = array(
    '#type' => 'select',
    '#title' => 'Number of Concurrent Active Sessions',
    '#options' => array(
      0 => 'unlimited',
      1 => '1',
      2 => '2',
      3 => '3',
      4 => '4',
      5 => '5',
    ),
    '#default_value' => $item->config['lock_session_concurrent'],
  );
  $sub_form['session_fieldset']['lock_session_concurrent_message'] = array(
    '#type' => 'textarea',
    '#title' => 'Lock Session Message',
    '#default_value' => $item->config['lock_session_concurrent_message'],
  );
  return $sub_form;
}

class LockSessionConcurrent extends PasswordPolicyItem {
  public $pp_type = array('item', 'init');

  function _check_concurrent_sessions($account) {
    $session_query = db_select('sessions', 's');
    $session_query->condition('s.uid', $account->uid);
    $session_query->orderBy('s.timestamp', 'ASC');
    $session_query->fields('s');
    $result = $session_query->execute();
    //if there are not enough session to hit the limit exit;
    if($result->rowcount() <= $this->config['lock_session_concurrent']) {
      return;
    }
    $concurrent = array();

    $timeout = $this->interval_string_to_int($this->config['lock_session_timeout']);
    foreach($result as $row) {
      //$row->session = session_decode($row->session);
      //I would much rather not use a regex
      //second and third check is to make sure that the session shod not be locked
      if(!preg_match("/lock_session_locked\|b:1/", $row->session) &&
         $timeout && 
         ($row->timestamp+$timeout > REQUEST_TIME)
        ) {
        $concurrent[] = $row;
      }
    }
    //exit if there are not to many concurrent sessions
    if(count($concurrent) <= $this->config['lock_session_concurrent']) {
      return;
    }
 
    lock_session_lock('cocurrent');
    lock_session_redirect("admin/lock_session/cocurrent");
    lock_session_message($this->config['lock_session_concurrent_message']);
  }

  static function interval_string_to_int($interval_string) {
    $int = strtotime($interval_string, 0);

    if($int === FALSE) {
      // Let the user know we weren't able to parse the time string
      drupal_set_message(t('Unable to parse time string, please use a string formated like 
          ## [seconds|minutes|hours|days|years]'), 'error');
    }

    return $int;
  }

  /**
   * init()
   */
  function init($account) {
    //if we are not a user insure we are unlocked and exit
    if($account->uid <1) {
      lock_session_unlock();   
      return;
    }

    // log a last access if we do not have one.
    if (!isset($_SESSION['lock_session_last_access'])) {
      $_SESSION['lock_session_last_access'] = REQUEST_TIME;
    }

    // lock the session if enough time has transpierd
    $timeout = $this->interval_string_to_int($this->config['lock_session_timeout']);
    if($timeout && ($_SESSION['lock_session_last_access']+$timeout < REQUEST_TIME)) {
      lock_session_lock("timeout");   
      lock_session_message($this->config['lock_session_timeout_message']);
      lock_session_redirect("admin/lock_session/login");
    }

    //check if we have to mnay concurrent sessions active

    if($this->config['lock_session_concurrent']) {
      $this->_check_concurrent_sessions($account);
    }

    // If the session is locked recored the site and the $_POST data and
    // redirect to the login screen
    if(lock_session_locked()) {
      if(!preg_match("/^admin\/lock_session/", current_path())) {
      $_SESSION['lock_session_POST'] = $_POST;
      $_SESSION['lock_session_GET'] = $_GET;
      // we have to unset the destination ofr drupal goto use it
      unset($_GET['destination']);
      password_policy2_goto(lock_session_redirect());
      }
      else {
      }
    }
    //If we are not locked clear saved info
    elseif(isset($_SESSION['lock_session_GET'])) {
      $q = $_GET['q'];
      $_GET = $_SESSION['lock_session_GET'];
      $_GET['q'] = $q;
      $_POST = $_SESSION['lock_session_POST'];
      unset($_SESSION['lock_session_GET']);
      lock_session_message(FALSE);
    }
    //update last access
    $_SESSION['lock_session_last_access'] = REQUEST_TIME;
  }
}

