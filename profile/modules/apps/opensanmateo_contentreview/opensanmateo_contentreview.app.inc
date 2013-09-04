<?php

/**
 * Implements hook_app_info().
 */
function opensanmateo_contentreview_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_contentreview_app_configure_form',
  );
}

/**
 * Provide app spectific settings.
 */
function opensanmateo_contentreview_app_configure_form() {
  $node_types = node_type_get_types();
  $options = array();
  foreach ($node_types as $type => $definition) {
    $options[$type] = $definition->name;
  }

  $form = array(
    'opensanmateo_contentreview_enabled_types' => array(
      '#title' => t('Enable Content Review for the following types'),
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => variable_get('opensanmateo_contentreview_enabled_types', '')
    ),
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'opensanmateo_contentreview_app_configure_form_submit';
  return $form;
}


/**
 * Submit handler for the app config form.
 */
function opensanmateo_contentreview_app_configure_form_submit($form, $form_state) {
  features_template_revert();
}
