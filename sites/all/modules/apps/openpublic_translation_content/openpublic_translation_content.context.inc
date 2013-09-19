<?php
/**
 * @file
 * openpublic_translation_content.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function openpublic_translation_content_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'language_switch';
  $context->description = '';
  $context->tag = 'OpenPublic Translation';
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
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('OpenPublic Translation');
  $export['language_switch'] = $context;

  return $export;
}
