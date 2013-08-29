<?php
/**
 * @file
 * opensanmateo_frontend.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function opensanmateo_frontend_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'smc_mainmenu';
  $context->description = 'Places Main Menu';
  $context->tag = 'opensanmateo';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-sanmateo-primary-menu' => array(
          'module' => 'menu_block',
          'delta' => 'sanmateo-primary-menu',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  
  // Translatables
  // Included for use with string extractors like potx.
  t('Places Main Menu');
  t('opensanmateo');

  $export['smc_mainmenu'] = $context;

  return $export;
}
