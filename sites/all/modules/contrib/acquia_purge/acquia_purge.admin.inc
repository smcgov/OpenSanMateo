<?php

/**
 * @file
 * Admin page callbacks and theme functions for the Acquia Purge module.
 */

/**
 * Menu callback; process a chunk of purge items via AJAX.
 *
 * @returns
 *   Statistics array encoded as JSON, including a 'widget' HTML snippet.
 */
function acquia_purge_ajax_processor() {
  $status = _acquia_purge_queue_stats();

  // Define a key 'error' that describes a potential error condition.
  $status['error'] = $status['locked'] = FALSE;

  // Lock acquiring assures us that nothing is purging the same paths at the
  // same time. All ways that trigger purging (ajax, drush) respect the locks.
  if (lock_acquire('acquia_purge_ajax_processor', ACQUIA_PURGE_QUEUE_LOCK_TIMEOUT)) {

    // Pop items from the queue and immediately process them.
    _acquia_purge_queue_pop('_acquia_purge_queue_processpurge');

    // Refresh the statistics post-run, so override most fields in $status.
    foreach (_acquia_purge_queue_stats() as $key => $value) {
      $status[$key] = $value;
    }

    // Ask our built-in diagnostics system to preliminary find issues that are
    // so risky we can expect problems. Everything starting with
    // ACQUIA_PURGE_SEVLEVEL_ERROR will cause purging to cease and log messages
    // to be written. Warn the user on any of them.
    if (!_acquia_purge_are_we_allowed_to_purge()) {
      $err = current(_acquia_purge_get_diagnosis(ACQUIA_PURGE_SEVLEVEL_ERROR));
      $status['error'] = $err['description'];
    }

    // If no obvious errors were found by the diagnostics system, check if the
    // history list is remaining empty: another bad symptom.
    elseif (empty($status['purgehistory'])) {
      $status['error'] = t("The system seems to be having difficulties
        refreshing recent content changes. Your work won't be lost, but please
        do ask your technical administrator to check the logs.");
    }

    // We're done so lets release the lock.
    lock_release('acquia_purge_ajax_processor');
  }

  // Instead of raising a very visual error condition: indicate the lock.
  else {
    $status['locked'] = TRUE;
  }

  // Render the status widget and add it to the statistics array.
  $status['widget'] = theme('acquia_purge_status_bar_widget', $status);

  // Return the status array with statistics...
  return drupal_json_output($status);
}

/**
 * Menu callback to fulfill autocompletes on acquia_purge_manualpurge_form.
 *
 * @returns
 *   A standard Form API form-array.
 */
function acquia_purge_manualpurge_autocomplete($string) {
  $query_limit = 10;
  $matches = array();

  // Overwrite $string and work around Drupal buggingly ignoring slashes.
  $string = implode('/', array_slice(explode('/', $_GET['q']), 6));

  // Scan for node/ lookups as they're quite common.
  if (substr($string, 0, 1) == 'n') {
    $query = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->range(0, $query_limit);

    // Lookup node IDs if the user entered node/, else limit on 15.
    if (strlen($string) > 5) {
      $string = (int) str_replace('node/', '', $string);
      $query->condition('n.nid', '%' . db_like($string) . '%', 'LIKE');
    }

    $results = $query->execute();
    foreach ($results as $nid) {
      $path = 'node/' . $nid->nid;
      $matches[] = $path;
    }
  }

  // Scan for URL aliases when the path module is enabled.
  if (module_exists('path')) {
    $query = db_select('url_alias', 'u')
      ->fields('u', array('alias'))
      ->condition('alias', db_like($string) . '%', 'LIKE')
      ->range(0, $query_limit)
      ->execute();
    foreach ($query as $alias) {
      $matches[] = $alias->alias;
    }
  }

  // Scan for menu_router paths, as long as they don't contain % characters.
  if (module_exists('menu')) {
    $query = db_select('menu_router', 'm')
      ->fields('m', array('path'))
      ->condition('path', db_like($string) . '%', 'LIKE')
      ->condition('path', 'acquia_purge_ajax_processor', '!=')
      ->condition('path', 'admin%', 'NOT LIKE')
      ->range(0, $query_limit)
      ->execute();
    foreach ($query as $path) {
      if (strpos($path->path, '%') !== FALSE) {
        continue;
      }
      $matches[] = $path->path;
    }
  }

  // Sort the values alphabetically.
  sort($matches);

  // Rewrite the matches array by copying the values into keys.
  $clean_url = variable_get('clean_url', 0);
  foreach ($matches as $key => $path) {
    if (!$clean_url) {
      $path = "index.php?q=$path";
    }
    unset($matches[$key]);
    $matches[$path] = $path;
  }

  // Return the output JSON'ed.
  drupal_json_output($matches);
}

/**
 * Menu callback to drupal_get_form; let users manual purge pages.
 *
 * @returns
 *   A standard Form API form-array.
 */
function acquia_purge_manualpurge_form($form, &$form_state) {
  $examples = array('&lt;front&gt;', 'node/1', 'news?page=1', 'contact');
  $schemes = _acquia_purge_get_protocol_schemes();
  $domains = _acquia_purge_get_domains();
  $form['description'] = array(
    '#markup' => t('<p>This form allows you to purge one or more paths from your
    Acquia Cloud load balancers. This form is not intended for day-to-day use
    and only meant for site administrators, for instance in emergency cases when
    a outdated copy of a page remains being served. It is highly recommended to
    automate these purges using rules so editorial users can rely on a fully
    fresh site instead of relying on this form.</p>'),
  );

  // Build up table rows with domains on the left and examples on the right.
  $rows = array();
  $rowsc = count($domains);
  if (count($examples) > count($domains)) {
    $rowsc = count($examples);
  }
  for ($i = 0; $i < $rowsc; $i++) {
    $row = array();
    $row[0] = isset($domains[$i]) ? $domains[$i] : '';
    $row[1] = isset($examples[$i]) ? $examples[$i] : '';
    $rows[] = $row;
  }

  // Add the guidance table to help the user understand.
  $form['guidancetable'] = array(
    '#theme' => 'table',
    '#header' => array(t('Domains to purge paths on'), t('Example paths')),
    '#rows' => $rows,
    '#empty' => '',
  );

  // Because we have many fields with the same values, we have to set
  // #tree to be able to access them.
  $form['#tree'] = TRUE;

  // We'll group all paths both in a HTML wrapper and logically in the form.
  $title = t('Paths to be purged:');
  $form['paths'] = array(
    '#prefix' => '<div id="paths-wrapper"><p><h3>' . $title . '</h3><ul>',
    '#suffix' => '</ul></p></div>',
  );

  // Fill paths with the right amount of form items according to num_paths.
  $ac_path = 'admin/config/development/performance/manualpurge/autocomplete';
  $prefix = sprintf('<b>%s://%s%s</b>', $schemes[0], $domains[0], base_path());
  if (empty($form_state['num_paths'])) {
    $form_state['num_paths'] = 1;
  }
  for ($i = 0; $i < $form_state['num_paths']; $i++) {
    $form['paths']['path'][$i] = array(
      '#type' => 'textfield',
      '#autocomplete_path' => $ac_path,
      '#field_prefix' => $prefix,
      '#size' => 30,
      '#prefix' => '<li>',
      '#suffix' => '</li>',
    );
  }

  // Declare the add and remove buttons.
  $form['paths']['add_path'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
    '#submit' => array('acquia_purge_manualpurge_form_add_one'),
    '#ajax' => array(
      'callback' => 'acquia_purge_manualpurge_form_callback',
      'wrapper' => 'paths-wrapper',
    ),
  );
  if ($form_state['num_paths'] > 1) {
    $form['paths']['remove_path'] = array(
      '#type' => 'submit',
      '#value' => t('Remove last item'),
      '#submit' => array('acquia_purge_manualpurge_form_remove_one'),
      '#limit_validation_errors' => array(),
      '#ajax' => array(
        'callback' => 'acquia_purge_manualpurge_form_callback',
        'wrapper' => 'paths-wrapper',
      ),
    );
  }

  // Render the submit button and return the form.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t("I know the risks, purge!"),
  );
  return $form;
}

/**
 * Callback to drupal_get_form: the AJAX callback to paths-wrapper.
 */
function acquia_purge_manualpurge_form_callback($form, $form_state) {
  return $form['paths'];
}

/**
 * Callback to drupal_get_form: add a path textfield.
 */
function acquia_purge_manualpurge_form_add_one($form, &$form_state) {
  $form_state['num_paths']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Callback to drupal_get_form: remove a path textfield.
 */
function acquia_purge_manualpurge_form_remove_one($form, &$form_state) {
  if ($form_state['num_paths'] > 1) {
    $form_state['num_paths']--;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Callback to drupal_get_form: validate the form.
 */
function acquia_purge_manualpurge_form_validate($form, &$form_state) {
  $paths = array();
  foreach ($form_state['values']['paths']['path'] as $id => $path) {
    if (empty($path)) {
      form_set_error('paths][path][' . $id,
        t('The path can not be empty, use &lt;front&gt; for your frontpage!'));
    }
    elseif (!is_string($path)) {
      form_set_error('paths][path][' . $id,
        t("The path has to be a string!"));
    }
    elseif (stristr($path, 'http:') || stristr($path, 'https:')) {
      form_set_error('paths][path][' . $id,
        t("You can't provide a URL, only paths!"));
    }
    elseif (preg_match('/\s/', $path)) {
      form_set_error('paths][path][' . $id,
        t('The path can not contain a space!'));
    }
    elseif (in_array($path, $paths)) {
      form_set_error('paths][path][' . $id,
        t('You have already listed this path!'));
    }
    $paths[] = $path;
  }
}

/**
 * Callback to drupal_get_form: handle the form submit.
 */
function acquia_purge_manualpurge_form_submit($form, &$form_state) {
  acquia_purge_purge_paths($form_state['values']['paths']['path']);
}

/**
 * Returns HTML for the Acquia Purge status widget.
 *
 * @param array $variables
 *   An associative array containing:
 *   - total: Total amount of actions initially queued for purging.
 *   - remaining: Remaining number of purge actions still to be processed.
 *   - processed: Number of purge actions that have already taken place.
 *   - percent: Value between 0-100 representing the progress percentage.
 *   - running: Whether URLs are being purged or not.
 *   - purgehistory: Array with recently purged URL's.
 *
 * @ingroup themeable
 */
function theme_acquia_purge_status_widget($variables) {
  if ($variables['running']) {
    return theme('acquia_purge_status_bar_widget', $variables);
  }
  else {
    $message = t('Idle, accepting purges');
    return "<div class=\"messages status\">\n$message</div>\n";
  }
}

/**
 * Returns HTML for the Acquia Purge progress bar widget.
 *
 * @param array $variables
 *   An associative array containing:
 *   - total: Total amount of actions initially queued for purging.
 *   - remaining: Remaining number of purge actions still to be processed.
 *   - processed: Number of purge actions that have already taken place.
 *   - percent: Value between 0-100 representing the progress percentage.
 *   - running: Whether URLs are being purged or not.
 *   - purgehistory: Array with recently purged URL's.
 *
 * @ingroup themeable
 */
function theme_acquia_purge_status_bar_widget($variables) {

  // Determine status messages based on what the statistics tells us.
  if ($variables['running']) {
    $message = t("Site content is being refreshed, please wait a moment...
    %remaining items to go...", array('%remaining' => $variables['remaining']));
  }
  else {
    $message = t("Content changes are now visible for everybody!");
  }

  return theme('progress_bar', array(
    'percent' => $variables['percent'], 'message' => $message));
}
