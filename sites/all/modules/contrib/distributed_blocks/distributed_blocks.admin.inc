<?php
/**
 * @file
 * 
 * Contains admin page code for the distributed blocks module.
 */

/**
 * Admin form generation callback 
 */
function distributed_blocks_admin_form($form, &$form_state) {
  $form['distributed_blocks_expose'] = array(
    '#type' => 'checkbox',
    '#title' => t('This site exposes its blocks for sharing'),
    '#description' => t('If checked, this site will be designated the master that client sites will sync against.'),
    '#default_value' => variable_get('distributed_blocks_expose', FALSE),
  );
  $form['distributed_blocks_force_absolute_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Force absolute links in exposed blocks'),
    '#description' => t('If checked, links in exposed blocks will be parsed and reformatted into absolute URLs.'),
    '#default_value' => variable_get('distributed_blocks_force_absolute_links', FALSE),
  );
  $form['distributed_blocks_master'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select exposed blocks from this site'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  // Get all blocks available on this site for the current theme
  $options_blocks = _distributed_blocks_get_all_blocks();
 
  $form['distributed_blocks_master']['distributed_blocks_exposed_blocks'] = array(
    '#type' => 'checkboxes',
    '#title' => t("Exposed Blocks"),
    '#description' => t('Select blocks from this site that should be exposed individually.'),
    '#options' => $options_blocks,
    '#default_value' => variable_get('distributed_blocks_exposed_blocks', array()),
  );  
  
  $form['distributed_blocks_client'] = array(
    '#type' => 'fieldset',
    '#title' => t('Client settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  
  //TODO: Do a fancypants AJAX version of this
  $form['distributed_blocks_client']['distributed_blocks_master_url'] = array(
    '#type' => 'textfield',
    '#title' => t("Master site URL"),
    '#description' => t('This is the full URL (ie http://www.example.com) of the site you want to fetch exposed
    blocks from. Only set this if this is a client site.'),
    '#default_value' => variable_get('distributed_blocks_master_url', ''),
  );
  
  // Fetch Cron frequency since this will be tied to that
  $freq_cron = variable_get('cron_safe_threshold', DRUPAL_CRON_DEFAULT_THRESHOLD);
  $intervals = drupal_map_assoc(array(3600, 10800, 21600, 43200, 86400, 604800), 'format_interval');
  
  if (isset($intervals[$freq_cron])) {
    $freq_cron = $intervals[$freq_cron];
  }
  else {
    $freq_cron = t('Never');
  }
  $freq_options = array(
    0 => t('Never'),
    1 => t('Every time Cron runs (@freq_cron)', array('@freq_cron' => $freq_cron)),
  );
  $freq_options += $intervals;
  
  $form['distributed_blocks_client']['distributed_blocks_update_freq'] = array(
    '#type' => 'select',
    '#title' => t('Frequency of updates'),
    '#options' => $freq_options,
    '#default_value' => variable_get('distributed_blocks_update_freq', 0),
    '#description' => t('How often should the blocks be fetched from the master site.'),
  );
  
  // Only display available blocks if the master site is set and valid
  if (variable_get('distributed_blocks_master_url', '')) {
    $form['distributed_blocks_client']['distributed_blocks_fetched_blocks'] = array(
      '#type' => 'checkboxes',
      '#title' => t("Fetched Blocks"),
      '#description' => t('Select blocks that you want to fetch from the master site.'),
      '#options' => variable_get('distributed_blocks_available_blocks', ''),
      '#default_value' => variable_get('distributed_blocks_fetched_blocks', array()),
    );
    $form['distributed_blocks_client']['fetch'] = array(
      '#type' => 'submit',
      '#value' => t('Fetch blocks now'),
      '#submit' => array('distributed_blocks_fetch_submit'),
    );   
  }
  
  return system_settings_form($form);
}

/**
 * Admin form validation callback 
 */
function distributed_blocks_admin_form_validate($form, &$form_state) {
  // Validate source URL
  $master_url = $form_state['values']['distributed_blocks_master_url'];
  
  // If this value is not set, you are considered the master site
  if (empty($master_url)) {
    return;
  }
  
  if (!empty($master_url) && !valid_url($master_url, TRUE)) {
    form_set_error('distributed_blocks_master_url', t('Invalid URL given.'));
    return;
  }
  
  // Verify that Distributed Blocks is enabled and listing shared blocks there
  $url = $master_url . '/distributed_blocks/list';
  $response = drupal_http_request($url);
  $failure = FALSE;
  
  if ($response->code != '200') {
    $message = t('Request failed, returned HTTP status code @code. Please check that your master site has Distributed Blocks enabled.', array('@code' => $response->code));
    $failure = TRUE;
  }
  else {
    $resp_array = drupal_json_decode($response->data);
  
    if (!$resp_array) {
      $message = t('Failed to decode JSON data retrieved from master site.');
      $failure = TRUE;
    }
    else {
      if ($resp_array == 'NO_EXPOSED_BLOCKS') {
        $message = t('No exposed blocks on the master site.');
        $failure = TRUE;
      }
    }
  }  
  if ($failure) {
    form_set_error('distributed_blocks_master_url', $message);
    watchdog('distributed_blocks', $message, NULL, WATCHDOG_WARNING);
    return;
  }
  
  foreach ($resp_array as $block) {
    $block_array = explode('|', $block);
    $available_blocks[$block] = $block_array[2] . ' (' . $block_array[1] . ')';
  }
  variable_set('distributed_blocks_available_blocks', $available_blocks);
}

/**
 * Submit callback to trigger block fetching from settings screen.
 */
function distributed_blocks_fetch_submit($form, &$form_state) {
  $res = distributed_blocks_fetch_blocks();
  if ($res['status']) {
    drupal_set_message($res['message']);
  }
  else {
    drupal_set_message($res['message'], 'error');
  }
  drupal_goto('admin/config/system/distributed_blocks');
}
