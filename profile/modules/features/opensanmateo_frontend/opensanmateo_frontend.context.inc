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
  $context->name = 'opensanmateo_header_footer';
  $context->description = '';
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
        'opensanmateo_search-header_search' => array(
          'module' => 'opensanmateo_search',
          'delta' => 'header_search',
          'region' => 'header',
          'weight' => '-10',
        ),
        'google_translator-active_languages' => array(
          'module' => 'google_translator',
          'delta' => 'active_languages',
          'region' => 'header',
          'weight' => '-8',
        ),
        'distributed_blocks-d_b--menu-department-menu' => array(
          'module' => 'distributed_blocks',
          'delta' => 'd_b--menu-department-menu',
          'region' => 'highlighted',
          'weight' => '0',
        ),
        'menu-menu-footer-utility' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-utility',
          'region' => 'footer',
          'weight' => '0',
        ),
        'distributed_blocks-d_b--menu-platform-menu' => array(
          'module' => 'distributed_blocks',
          'delta' => 'd_b--menu-platform-menu',
          'region' => 'footer',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('opensanmateo');
  $export['opensanmateo_header_footer'] = $context;

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
