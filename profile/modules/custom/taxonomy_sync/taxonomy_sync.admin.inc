<?php
/**
 * @file
 *
 * Contains admin page code and other related callbacks that are not used often
 */

/**
 * Admin form generation callback
 */
function taxonomy_sync_admin_form($form, &$form_state) {
  // Load up the JS code to support the form
  drupal_add_js(drupal_get_path('module', 'taxonomy_sync') . '/taxonomy_sync.admin.js');

  // Build form array
  $form[GTA_TERMS_SYNC_MASTER] = array(
    '#type' => 'checkbox',
    '#title' => t('This server is the vocabulary master'),
    '#description' => t('If checked, this site will be designated the master that client sites will sync against.'),
    '#default_value' => variable_get(GTA_TERMS_SYNC_MASTER, 0),
  );

  $form[GTA_TERMS_SYNC_MASTER_URL] = array(
    '#type' => 'textfield',
    '#title' => t("Vocabulary master's base URL"),
    '#description' => t('This is the base URL to use for term synchronization, e.g. %sample.  Only used for client sites.', array('%sample' => 'http://www.georgia.gov')),
    '#default_value' => variable_get(GTA_TERMS_SYNC_MASTER_URL, ''),
  );

  // Load vocabs in system, sort 'em before generating the field element
  $vocabs_by_id = taxonomy_get_vocabularies();
  $options = array();
  foreach ($vocabs_by_id as $vid => $vocab) {
    $options[$vid] = $vocab->name;
  }
  asort($options);
  //$options = array(-1 => t('-- Select --')) + $options;

  $form[GTA_TERMS_SYNC_VOCAB] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary to use for synchronization'),
    '#description' => t('If the master site, this is the vocabulary to provide terms from.  If a client site, the vocabulary to merge new terms from the master site into.'),
    '#options' => $options,
    '#default_value' => variable_get(GTA_TERMS_SYNC_VOCAB, NULL),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Admin form validation callback
 */
function taxonomy_sync_admin_form_validate($form, &$form_state) {
  $values = $form_state['values'];

  // Make sure we have a valid base url if a client site:
  if (!$values[GTA_TERMS_SYNC_MASTER] && (empty($values[GTA_TERMS_SYNC_MASTER_URL]) || !valid_url($values[GTA_TERMS_SYNC_MASTER_URL], TRUE))) {
    form_set_error(GTA_TERMS_SYNC_MASTER_URL, t('Invalid base URL given.  Please correct the errors and submit again.'));
  }

  // Make sure we have a target vocabulary
  /*
  if ($values[GTA_TERMS_SYNC_VOCAB] < 0) {
    form_set_error(GTA_TERMS_SYNC_VOCAB, t('Please select a target vocabulary and submit again.'));
  }
  */
}
