<?php

/**
 * @file
 * Self-test diagnostic test functions for _acquia_purge_get_diagnosis().
 */

/**
 * Test whether the current hosting environment is Acquia Cloud.
 *
 * @param string $t
 *   Name of the t() function to call.
 *
 * @returns
 *   Associative array with the following elements:
 *   - title: The name of the requirement.
 *   - value: The current value (e.g., version, time, level, etc).
 *   - description: The description of the requirement/status.
 *   - severity: ACQUIA_PURGE_SEVLEVEL_INFO, _OK, _WARNING, _ERROR
 */
function _acquia_purge_get_diagnosis_acquiacloud($t) {
  $site = _acquia_purge_get_site_name();
  $test = array('title' => $t('Hosting environment'));
  if (_acquia_purge_are_we_on_acquiacloud()) {
    $test['value'] = $t('Acquia Cloud: @site', array('@site' => $site));
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_OK;
  }
  else {
    $test['value'] = $t('Third-party environment.');
    $test['description'] = $t('You are not running on Acquia Cloud, this is a'
      . ' mandatory requirement for this module. The module will not process'
      . ' scheduled purges, once deployed scheduled purges will be processed.');
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
  }
  return $test;
}

/**
 * Test the amount of load balancers configured.
 *
 * @param string $t
 *   Name of the t() function to call.
 *
 * @returns
 *   Associative array with the following elements:
 *   - title: The name of the requirement.
 *   - value: The current value (e.g., version, time, level, etc).
 *   - description: The description of the requirement/status.
 *   - severity: ACQUIA_PURGE_SEVLEVEL_INFO, _OK, _WARNING, _ERROR
 */
function _acquia_purge_get_diagnosis_balancers($t) {
  $balancers = _acquia_purge_get_balancers();
  $balancers_c = count($balancers);
  $test = array(
    'value' => implode(', ', $balancers),
    'title' => $t('Load balancers'),
  );

  // Determine whether the amount of load balancers is healthy.
  if (!$balancers_c) {
    $test['value'] = $t('No load balancers detected.');
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('There are no load balancers detected which makes'
      . ' it impossible to purge your site. Please contact Acquia Support!');
  }
  elseif ($balancers_c < 2) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_WARNING;
    $test['description'] = $t('You have only one load balancer, this means your'
      . ' site can not be failed over by us. Please contact Acquia Support.');
  }
  elseif ($balancers_c >= 6) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_WARNING;
    $test['description'] = $t('Your website is running behind @no load'
      . ' balancers, which will put severe stress on your database. Please pay'
      . ' attention to the number of items in the queue table.',
      array('@no' => $balancers_c));
  }
  else {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_OK;
  }
  return $test;
}

/**
 * Test against known conflicting modules such as varnish, boost and purge.
 *
 * @param string $t
 *   Name of the t() function to call.
 *
 * @returns
 *   Associative array with the following elements:
 *   - title: The name of the requirement.
 *   - value: The current value (e.g., version, time, level, etc).
 *   - description: The description of the requirement/status.
 *   - severity: ACQUIA_PURGE_SEVLEVEL_INFO, _OK, _WARNING, _ERROR
 */
function _acquia_purge_get_diagnosis_conflicts($t) {
  $test = array(
    'severity' => ACQUIA_PURGE_SEVLEVEL_OK,
    'value' => $t('No issues detected.'),
    'title' => $t('Module conflicts'),
  );

  // Detect expire's "Include base URL in expires" setting, which causes issues.
  if (variable_get('expire_include_base_url', FALSE)) {
    $test['value'] = 'expire';
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_WARNING;
    $test['description'] = $t("We detected that you enabled the 'Include base"
      . " URL in expires'-setting offered by the expire module, this is known"
      . " to (potentially) cause issues. The setting causes hook_expire_cache()"
      . " to be given full urls that breaks its own API and Acquia Purge is not"
      . " always able to strip these. Check your logs to see if purges execute"
      . " properly.");
  }

  // Detect the existence of the Boost module which is incompatible.
  if (module_exists('boost')) {
    $test['value'] = 'boost';
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('Your site has the boost module enabled which is'
      . ' known to cause issues on Acquia Cloud. Because of its heavy'
      . ' interactions with the file system it will destabilize your site.');
  }

  // Detect the existence of the Purge module which is incompatible for now.
  if (module_exists('purge')) {
    $test['value'] = 'purge';
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('Your site has the Purge module enabled which'
      . ' is incompatible with this version of Acquia Purge. However, this'
      . ' module will depend on it in the future. Please, remove it for now!');
  }

  // Detect if the Varnish module is enabled, which isn't necessary.
  if (module_exists('varnish')) {
    $test['value'] = 'varnish';
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_WARNING;
    $test['description'] = $t('Your site runs with the varnish module enabled,'
      . ' which is known to not work on Acquia Cloud. As Acquia Purge does its'
      . ' work already for you we strongly encourage you to remove it.');
  }

  return $test;
}

/**
 * Test whether the amount of domain names is healthy.
 *
 * @param string $t
 *   Name of the t() function to call.
 *
 * @returns
 *   Associative array with the following elements:
 *   - title: The name of the requirement.
 *   - value: The current value (e.g., version, time, level, etc).
 *   - description: The description of the requirement/status.
 *   - severity: ACQUIA_PURGE_SEVLEVEL_INFO, _OK, _WARNING, _ERROR
 */
function _acquia_purge_get_diagnosis_domains($t) {
  $domains_link = drupal_get_path('module', 'acquia_purge') . '/DOMAINS.txt';
  $domains_link = url($domains_link);
  $domains = _acquia_purge_get_domains();
  $domains_c = count($domains);
  $test = array(
    'value' => implode(', ', $domains),
    'title' => $t('Purged domains'),
    'description' => $t('The domains for which content gets cleared from your'
      . ' load balancers. Every domain name multiplies the purging work to be'
      . ' done, it is therefore important to <a href="!link" target="_blank">'
      . 'specify your domains</a> when the automatically detected list exceeds'
      . ' 4 domains or when it is incorrect.', array('!link' => $domains_link)),
  );

  // Start evaluating the list of domain names.
  if (!$domains_c) {
    $test['value'] = $t('0 domains detected.');
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('No domains have been detected which implies that'
      . ' something is seriously wrong. Pending purges will not be processed.');
  }
  elseif ((php_sapi_name() === 'cli') && in_array('default', $domains)) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('The domain name "default" has been found'
      . ' indicating that you are running via Drush. Either you will need to'
      . ' specify your domains or provide --uri for the right site.');
  }
  elseif ($domains_c <= 6) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_OK;
  }
  elseif (($domains_c > 6) && ($domains_c <= 8)) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_WARNING;
    $test['description'] = $t('Because you have @no domain names there is a'
      . ' <b>high risk</b> that purging your site will put stress on your'
      . ' servers, it is <b>strongly recommended</b> to <a href="!link"'
      . ' target="_blank">specify your domains</a> to not exceed 6 domains.',
      array('!link' => $domains_link, '@no' => $domains_c));
  }
  else {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('Because you have @no domain names there is a'
      . ' <b>very high risk</b> that purging your site will put stress on your'
      . ' servers, it is <b>strongly recommended</b> to <a href="!link"'
      . ' target="_blank">specify your domains</a> to not exceed 6 domains. To'
      . ' prevent system failure, pending purges will not be processed!',
      array('!link' => $domains_link, '@no' => $domains_c));
  }
  return $test;
}

/**
 * Test if anonymous page caching is enabled.
 *
 * @param string $t
 *   Name of the t() function to call.
 *
 * @returns
 *   Associative array with the following elements:
 *   - title: The name of the requirement.
 *   - value: The current value (e.g., version, time, level, etc).
 *   - description: The description of the requirement/status.
 *   - severity: ACQUIA_PURGE_SEVLEVEL_INFO, _OK, _WARNING, _ERROR
 */
function _acquia_purge_get_diagnosis_page_cache($t) {
  $cache = variable_get('cache', 0);
  $test = array(
    'severity' => ACQUIA_PURGE_SEVLEVEL_OK,
    'value' => $cache ? $t('Enabled') : $t('Disabled'),
    'title' => $t('Cache pages for anonymous users'));
  if (!$cache) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('Your site has Drupal page caching disabled,'
      . ' which is of extreme importance to every website that gets traffic.'
      . ' Once enabled your load balancer will be instructed to start serving'
      . ' pages from its cache to offload traffic from your web servers. The'
      . ' more traffic served from your load balancer, the faster your'
      . ' site will be!');
  }
  return $test;
}

/**
 * Test if the page_cache_maximum_age setting is configured in a healthy way.
 *
 * @param string $t
 *   Name of the t() function to call.
 *
 * @returns
 *   Associative array with the following elements:
 *   - title: The name of the requirement.
 *   - value: The current value (e.g., version, time, level, etc).
 *   - description: The description of the requirement/status.
 *   - severity: ACQUIA_PURGE_SEVLEVEL_INFO, _OK, _WARNING, _ERROR
 */
function _acquia_purge_get_diagnosis_page_cache_age($t) {
  $age = (int) variable_get('page_cache_maximum_age', 0);
  $test = array('title' => $t('Expiration of cached pages'));

  // Set the value label.
  $test['value'] = $t('Disabled');
  if ($age !== 0) {
    $test['value'] = array('@age' => round($age / 60 / 60, 2));
    $test['value'] = $t('@age hours', $test['value']);
  }

  // Determine what "find out more" link we can provide.
  $link = 'http://blog.merge.nl/20120118/how-does-caching-work-drupal';
  if (user_access('administer site configuration')) {
    $link = url('admin/config/development/performance');
  }

  // Users without a TTL configured won't put our module to much use.
  if ($age === 0) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_ERROR;
    $test['description'] = $t('The "<a href="!link" target="_blank">expiration'
    . ' of cached pages</a>"-setting of your website is disabled, while we'
    . ' strongly recommend to put it to 6 hours or longer in combination with'
    . ' the Acquia Purge module. The setting determines how long external'
    . ' caches (like our load balancers) are instructed to keep a cached copy'
    . ' of content. With your current setting your load balancer is not being'
    . ' used and your web servers will likely be under constant stress,'
    . ' causing a slow site and  system resources being wasted.',
    array('!link' => $link));
  }

  // We have picked 6 hours as a safe zone to be in, everything above is better!
  elseif ($age < 21600) {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_WARNING;
    $test['description'] = $t('The "<a href="!link" target="_blank">expiration'
    . ' of cached pages</a>"-setting of your website is set to @age, while we'
    . ' strongly recommend to put it to 6 hours or longer in combination with'
    . ' the Acquia Purge module. The setting determines how long external'
    . ' caches (like our load balancers) are instructed to keep a cached copy'
    . ' of content. With your current configuration, your load balancer is not'
    . ' used effectively and your web servers will likely be under stress,'
    . ' causing a slow site and system resources being wasted.',
    array('!link' => $link, '@age' => $test['value']));
  }

  // Everything above 6 hours is good although longer is still better obviously.
  else {
    $test['severity'] = ACQUIA_PURGE_SEVLEVEL_OK;
  }

  return $test;
}

/**
 * Report on the current status of the system.
 *
 * @param string $t
 *   Name of the t() function to call.
 *
 * @returns
 *   Associative array with the following elements:
 *   - title: The name of the requirement.
 *   - value: The current value (e.g., version, time, level, etc).
 *   - description: The description of the requirement/status.
 *   - severity: ACQUIA_PURGE_SEVLEVEL_INFO, _OK, _WARNING, _ERROR
 */
function _acquia_purge_get_diagnosis_status($t) {
  $stats = _acquia_purge_queue_stats();
  $test = array(
    'title' => $t('Status'),
    'severity' => ACQUIA_PURGE_SEVLEVEL_INFO,
  );

  // Determine the status message.
  $status = $t('Idle, accepting purges');
  if ($stats['running']) {
    $status = $t('Active ongoing purges, @remaining items to go...', array(
        '@remaining' => $stats['remaining'],
      )
    );
  }

  // Set the status on the plain-text and HTML versions.
  $test['value'] = $test['value_plain'] = $status;

  // Insert a HTML status widget into the description field if its running.
  if ($stats['running']) {
    $test['description'] = theme('acquia_purge_status_bar_widget', $stats);
  }

  return $test;
}
