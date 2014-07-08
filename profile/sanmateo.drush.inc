<?php
/**
 * @file
 *
 * Implements profile-specific drush commands
 */

/**
 * Implements hook_drush_command
 */
function sanmateo_drush_command() {
  $items = array();

  $items['osm-to-prod'] = array(
    'description' => 'Makes one-time updates to site when deployed to the production environment.',
    'examples' => array(
      'drush osm-to-prod' => dt('Makes one-time updates to site when deployed to the production environment.'),
    ),
  );

  $items['osm-from-prod'] = array(
    'description' => 'Makes one-time updates to site when moved from the production environment.',
    'examples' => array(
      'drush osm-from-prod' => dt('Makes one-time updates to site when moved from the production environment.'),
    ),
  );

  return $items;
}

/**
 * Implements validate callback for drush command "osm-to-prod"
 */
function drush_sanmateo_osm_to_prod_validate() {
  if (variable_get('sanmateo_osm_to_prod', FALSE)) {
    return drush_set_error('sanmateo_osm_to_prod', dt('osm-to-prod: Command has already been executed on this site'));
  }
}

/**
 * Implements command callback for drush command "osm-to-prod"
 */
function drush_sanmateo_osm_to_prod() {
  //$sanmateo_info = drupal_parse_info_file(drupal_get_path('profile', 'sanmateo') . '/sanmateo.info'); drush_print_r($sanmateo_info);
  // Pull together info from drush context
  $base_url = 'http://rbates.sanmateo.p2devcloud.com';//drush_get_context('DRUSH_URI');

  // Enable all prod-only modules
  $prod_mods = array(
    'memcache_admin',
    'expire',
    'purge',
    'securepages',
    'xmlsitemap',
    'xmlsitemap_menu',
    'xmlsitemap_engines',
    'acquia_agent',
    'acquia_spi',
  );
  module_enable($prod_mods);
  drush_log(dt('Enabled production-only modules: @modules', array('@modules' => implode(', ', $prod_mods))), 'success');

  // Disable development modules
  $dev_mods = array(
    'devel',
    'dblog',
    'backup_migrate',
  );
  module_disable($dev_mods);
  drush_log(dt('Disabled development modules: @modules', array('@modules' => implode(', ', $dev_mods))), 'success');

  // Set securepages settings
  $form_state = array('values' => array(
    'securepages_enable' => 1,
  ));
  module_load_include('inc', 'securepages', 'securepages.admin');
  drupal_form_submit('securepages_settings', $form_state);
  drush_log(dt('Configured securepages'), 'success');

  // Set cache settings
  $form_state = array('values' => array(
    'cache' => 1,
    'cache_lifetime' => 0,
    'page_cache_maximum_age' => 3600,
    'block_cache' => 1,
    'preprocess_css' => 1,
    'preprocess_js' => 1,
  ));
  module_load_include('inc', 'system', 'system.admin');
  drupal_form_submit('system_performance_settings', $form_state);
  drush_log(dt('Configured caching'), 'success');

  // Set purge settings
  $form_state = array('values' => array(
    'purge_proxy_urls' => $base_url . '/?purge_method=ah',
  ));
  drupal_form_submit('purge_admin_settings_form', $form_state);
  drush_log(dt('Configured purge'), 'success');

  // Set XML Sitemap settings
  $form_state = array('values' => array(
    'xmlsitemap_base_url' => $base_url,
  ));
  module_load_include('inc', 'xmlsitemap', 'xmlsitemap.admin');
  drupal_form_submit('xmlsitemap_settings_form', $form_state);
  drush_log(dt('Configured xmlsitemap'), 'success');

  // Make sure all master-client settings are kosher
  sanmateo_update_master_client();
  drush_log(dt('Refreshed master-client settings'), 'success');

  // Re-sync with Acquia subscription servers
  if (function_exists('acquia_agent_check_subscription')) {
    acquia_agent_check_subscription();
    drush_log(dt('Resync with Acquia subscription'), 'success');
  }

  // Flush all Drupal caches
  drupal_flush_all_caches();
  drush_log(dt('Flushed all caches'), 'success');

  variable_set('sanmateo_osm_to_prod', TRUE);
}

/**
 * Implements validate callback for drush command "osm-from-prod"
 */
function drush_sanmateo_osm_from_prod_validate() {
  if (!variable_get('sanmateo_osm_to_prod', FALSE)) {
    return drush_set_error('sanmateo_osm_from_prod', dt('osm-from-prod: Command has already been executed on this site'));
  }
}

/**
 * Implements command callback for drush command "osm-from-prod"
 */
function drush_sanmateo_osm_from_prod() {
  // Disable all prod-only modules
  $prod_mods = array(
    'memcache_admin',
    'expire',
    'purge',
    'securepages',
    'xmlsitemap',
    'xmlsitemap_menu',
    'xmlsitemap_engines',
    'acquia_agent',
    'acquia_spi',
  );
  module_disable($prod_mods);
  drush_log(dt('Disabled production-only modules: @modules', array('@modules' => implode(', ', $prod_mods))), 'success');

  // Make sure all master-client settings are kosher
  sanmateo_update_master_client();
  drush_log(dt('Refreshed master-client settings'), 'success');

  // Resync with Acquia subscription
  acquia_agent_check_subscription();
  drush_log(dt('Resync with Acquia subscription'), 'success');

  // Flush all Drupal caches
  drupal_flush_all_caches();
  drush_log(dt('Flushed all caches'), 'success');

  variable_del('sanmateo_osm_to_prod');
}
