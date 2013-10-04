<?php

/**
 * Implementation of hook_apps_app_info().
 */
function opensanmateo_contact_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_contact_app_configure_form', // This form will be render on the app config pag
  );
}

/**
 * OpenSanMateo Content app configuration form.
 */
function opensanmateo_contact_app_configure_form() {
  $form = array();
  // Get available node options.
  $node_types = node_type_get_types();
  $options = array();
  foreach ($node_types as $type => $definition) {
    $options[$type] = $definition->name;
  }

  $form['opensanmateo_contact_enabled_types'] = array(
    '#title' => t('Enable Contact for the following content types'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('opensanmateo_contact_enabled_types', ''),
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_contact_app_configure_form_submit';
  return $form;
}


/**
 * Submit handler for the app config form.
 */
function opensanmateo_contact_app_configure_form_submit($form, $form_state) {
  features_template_revert();
}

