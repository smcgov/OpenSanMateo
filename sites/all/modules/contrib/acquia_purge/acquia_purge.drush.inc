<?php

/**
 * @file
 * Drush integration providing common maintenance tasks.
 */

/**
 * Implements hook_drush_help().
 */
function acquia_purge_drush_help($section) {
  switch ($section) {
    case 'meta:acquia_purge:title':
      return dt('Acquia Purge commands');

    case 'meta:acquia_purge:summary':
      return dt('Manage and create scheduled purges.');

  }
}

/**
 * Implements hook_drush_command().
 */
function acquia_purge_drush_command() {
  return array(

    // Define the 'ap-diagnosis' command.
    'ap-diagnosis' => array(
      'description' => 'Perform a series of diagnostic self-tests.',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
      'aliases' => array('apd'),
      'examples' => array('drush apd'),
    ),

    // Define the 'ap-domains' command.
    'ap-domains' => array(
      'description' => 'List all domains Acquia Purge will purge against.',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
      'aliases' => array('apdo'),
      'examples' => array('drush apdo'),
    ),

    // Define the 'ap-purge' command.
    'ap-purge' => array(
      'description' => 'Purge a specified path from your balancers.',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
      'aliases' => array('app'),
      'arguments' => array(
        'path' => 'The Drupal path to be purged, e.g.: "/news" or "<front>".',
      ),
      'examples' => array('drush app "/news"'),
    ),

    // Define the 'ap-forget' command.
    'ap-forget' => array(
      'description' => 'Forget all scheduled purges and empty the queue.',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
      'aliases' => array('apf'),
      'examples' => array('drush apf'),
    ),

    // Define the 'ap-list' command.
    'ap-list' => array(
      'description' => 'List all the items that are in the queue.',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
      'aliases' => array('apl'),
      'examples' => array('drush apl'),
    ),

    // Define the 'ap-process' command.
    'ap-process' => array(
      'description' => 'Purge all queued items from the command line.',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
      'aliases' => array('appr'),
      'examples' => array('drush appr'),
    ),
  );
}

/**
 * Perform a series of diagnostic self-tests.
 *
 * @param int $v
 *   Optional, the level of diagnostics presented. Test results that match or
 *   are higher than the given level are returned.
 */
function drush_acquia_purge_ap_diagnosis($v = ACQUIA_PURGE_SEVLEVEL_INFO) {
  $oldverbosity = drush_get_context('DRUSH_VERBOSE');

  // Define a mapping between install.inc's requirement states and drush_log().
  $severitymap = array(
    ACQUIA_PURGE_SEVLEVEL_INFO => 'notice',
    ACQUIA_PURGE_SEVLEVEL_OK   => 'ok',
    ACQUIA_PURGE_SEVLEVEL_WARNING => 'warning',
    ACQUIA_PURGE_SEVLEVEL_ERROR   => 'error',
  );

  // Tell Drush to be verbose.
  drush_set_context('DRUSH_VERBOSE', TRUE);

  // Iterate the tests and call drush_log with the appropriate message type.
  foreach (_acquia_purge_get_diagnosis($v) as $test) {
    drush_log($test['value_plain'], $severitymap[$test['severity']]);
    if ($test['severity'] >= ACQUIA_PURGE_SEVLEVEL_WARNING) {
      printf("%s\n\n\n", $test['description_plain']);
    }
  }

  // Set back the old verbosity state.
  drush_set_context('DRUSH_VERBOSE', $oldverbosity);
}

/**
 * List all detected domain names that Acquia Purge will purge.
 */
function drush_acquia_purge_ap_domains() {

  // Stop invocation if we are not detecting Acquia Cloud heuristics.
  if (!_acquia_purge_are_we_on_acquiacloud()) {
    return drush_set_error("You must be on Acquia Cloud to use Acquia Purge.");
  }

  foreach (_acquia_purge_get_domains() as $domain) {
    printf("%s\n", $domain);
  }
}

/**
 * Purge a specified path from your balancers.
 *
 * @param string $path
 *   The Drupal path (for example: '<front>', 'user/1' or a alias).
 */
function drush_acquia_purge_ap_purge($path = NULL) {

  // Stop invocation if we are not detecting Acquia Cloud heuristics.
  if (!_acquia_purge_are_we_on_acquiacloud()) {
    return drush_set_error("You must be on Acquia Cloud to use Acquia Purge.");
  }

  // Stop invocation if serious error conditions have been found.
  if (!_acquia_purge_are_we_allowed_to_purge()) {
    return drush_acquia_purge_ap_diagnosis(ACQUIA_PURGE_SEVLEVEL_ERROR);
  }

  // Check if the path was provided.
  if (!is_string($path)) {
    return drush_set_error("You haven't provided a path to be purged.");
  }

  // Block invocations with URL's instead of paths, we'll handle the URLs!
  if (stristr($path, 'http:') || stristr($path, 'https:')) {
    return drush_set_error("You can't provide a URL, only paths...");
  }

  // Strip the path and remove potentially added double paths.
  $path = trim($path, '/');
  $path = str_replace('//', '/', $path);

  // If the path is empty, assume <front>.
  if (empty($path)) {
    $path = '<front>';
  }

  // Add the given path to the queue and dispatch processing to ap-process.
  acquia_purge_purge_path($path);
  drush_acquia_purge_ap_process();
}

/**
 * Forget all scheduled purges and empty the queue.
 */
function drush_acquia_purge_ap_forget() {

  // Stop invocation if we are not detecting Acquia Cloud heuristics.
  if (!_acquia_purge_are_we_on_acquiacloud()) {
    return drush_set_error("You must be on Acquia Cloud to use Acquia Purge.");
  }

  // Retrieve statistics, clear the queue and log to Drush.
  $stats = _acquia_purge_queue_stats();
  _acquia_purge_queue_clear();
  drush_log(dt("Removed @remaining items from the queue.",
    array('@remaining' => $stats['remaining'])), 'ok');

  // If there was a lock acquired, free it up as the queue will be empty now.
  lock_release('acquia_purge_ajax_processor');
}

/**
 * List all the items that are in the queue.
 */
function drush_acquia_purge_ap_list() {

  // Stop invocation if we are not detecting Acquia Cloud heuristics.
  if (!_acquia_purge_are_we_on_acquiacloud()) {
    return drush_set_error("You must be on Acquia Cloud to use Acquia Purge.");
  }

  // Directly query the queue table and print all records.
  $items = db_select('queue', 'q')
    ->fields("q", array("data"))
    ->condition('name', 'acquia_purge')
    ->execute();
  while ($item = $items->fetchAssoc()) {
    if ($item = unserialize(current($item))) {
      printf(" - '%s'\n", current($item));
    }
  }
}

/**
 * Purge all queued items from the command line.
 */
function drush_acquia_purge_ap_process() {

  // Stop invocation if we are not detecting Acquia Cloud heuristics.
  if (!_acquia_purge_are_we_on_acquiacloud()) {
    return drush_set_error("You must be on Acquia Cloud to use Acquia Purge.");
  }

  // Acquire a lock and ensure nobody else is purging something.
  if (!lock_acquire('acquia_purge_ajax_processor', ACQUIA_PURGE_QUEUE_LOCK_TIMEOUT)) {
    return drush_set_error("Unable to acquire lock, ensure that all users "
      . "close their browser tabs as a different purge seems to be active!");
  }

  // Stop invocation if serious error conditions have been found.
  if (!_acquia_purge_are_we_allowed_to_purge()) {
    return drush_acquia_purge_ap_diagnosis(ACQUIA_PURGE_SEVLEVEL_ERROR);
  }

  // Retrieve the statistics and determine if processing is needed.
  $stats = _acquia_purge_queue_stats();
  if (!$stats['running']) {
    return drush_set_error("The purge queue seems to be empty!");
  }

  // Calculate how many iterations we need and start processing accordingly.
  $log = array();
  do {
    $items = _acquia_purge_queue_pop('_acquia_purge_queue_processpurge');

    // Retrieve the statistics and log the purged urls.
    $stats = _acquia_purge_queue_stats();
    foreach ($stats['purgehistory'] as $logitem) {
      if (!(in_array($logitem, $log))) {
        drush_log(dt("Purged: @url", array('@url' => $logitem)), 'ok');
        $log[] = $logitem;
      }
    }

  } while (count($items));

  // We are done so lets release the lock.
  lock_release('acquia_purge_ajax_processor');
}
