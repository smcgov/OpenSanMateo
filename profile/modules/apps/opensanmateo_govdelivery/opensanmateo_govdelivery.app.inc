<?php

/**
 * Implements hook_app_info().
 */
function opensanmateo_govdelivery_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_govdelivery_app_configure_form',
  );
}

/**
 * Provide app spectific settings.
 */
function opensanmateo_govdelivery_app_configure_form() {
  $form = array();
  // Get available node options.
  $node_types = node_type_get_types();
  $options = array();
  foreach ($node_types as $type => $definition) {
    $options[$type] = $definition->name;
  }

  $form['opensanmateo_govdelivery_enabled_types'] = array(
    '#title' => t('Enable GovDelivery for the following content types'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('opensanmateo_govdelivery_enabled_types', ''),
  );

  // Get available vocabulary options.
  $vocabs = taxonomy_vocabulary_get_names();
  $vocab_options = array();
  foreach ($vocabs as $machine_name => $definition) {
    if ($machine_name != 'govdelivery_topics') {
      $vocab_options[$machine_name] = $definition->name;
    }
  }

  $form['opensanmateo_govdelivery_enabled_vocabs'] = array(
    '#title' => t('Enable GovDelivery for the following vocabularies'),
    '#type' => 'checkboxes',
    '#options' => $vocab_options,
    '#default_value' => variable_get('opensanmateo_govdelivery_enabled_vocabs', '')
  );


  $form['opensanmateo_govdelivery_base_url'] = array(
    '#title' => t('GovDelivery API URL'),
    '#type' => 'textfield',
    '#description' => t('The base url for the GovDelivery API, i.e. !url', array('!url' => opensanmateo_govdelivery_variable_defaults('opensanmateo_govdelivery_base_url'))),
    '#default_value' => variable_get('opensanmateo_govdelivery_base_url', opensanmateo_govdelivery_variable_defaults('opensanmateo_govdelivery_base_url')),
  );

  $form['opensanmateo_govdelivery_email_topic'] = array(
    '#title' => t('GovDelivery Email Topic'),
    '#type' => 'textfield',
    '#description' => t('You may use tokens from the list below'),
    '#default_value' => variable_get('opensanmateo_govdelivery_email_topic', opensanmateo_govdelivery_variable_defaults('opensanmateo_govdelivery_email_topic')),
  );

  $form['opensanmateo_govdelivery_email_text'] = array(
    '#title' => t('GovDelivery Email Text'),
    '#type' => 'textarea',
    '#description' => t('You may use tokens from the list below'),
    '#default_value' => variable_get('opensanmateo_govdelivery_email_text', opensanmateo_govdelivery_variable_defaults('opensanmateo_govdelivery_email_text')),
  );

  // Add token module replacements fields.
  $form['tokens'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#weight' => 20,
    '#title' => t('Placeholder tokens'),
    '#description' => t("The following placeholder tokens can be used in both paths and titles. When used in a path or title, they will be replaced with the appropriate values."),
  );

  $form['tokens']['help'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node', 'term'),
    '#global_types' => TRUE,
    '#click_insert' => TRUE,
  );



  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_govdelivery_app_configure_form_submit';
  return $form;
}


/**
 * Submit handler for the app config form.
 */
function opensanmateo_govdelivery_app_configure_form_submit($form, $form_state) {
  features_template_revert();
}
