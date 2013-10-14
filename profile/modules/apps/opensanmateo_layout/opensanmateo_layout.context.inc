<?php
/**
 * @file
 * opensanmateo_layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function opensanmateo_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opensanmateo_global';
  $context->description = 'Provides global blocks for OpenSanMateo';
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
        'distributed_blocks-d_b--menu-department-menu' => array(
          'module' => 'distributed_blocks',
          'delta' => 'd_b--menu-department-menu',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'distributed_blocks-d_b--opensanmateo_layout_banner' => array(
          'module' => 'distributed_blocks',
          'delta' => 'd_b--opensanmateo_layout_banner',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'distributed_blocks-d_b--menu-platform-menu' => array(
          'module' => 'distributed_blocks',
          'delta' => 'd_b--menu-platform-menu',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-footer-utility' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-utility',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides global blocks for OpenSanMateo');
  t('opensanmateo');
  $export['opensanmateo_global'] = $context;

  return $export;
}
