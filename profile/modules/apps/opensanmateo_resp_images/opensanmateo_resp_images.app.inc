<?php
/**
 * @file
 * Code for OpenSanMateo Responsive Images apps integration.
 */

/**
 * Implements hook_apps_app_info
 */
function opensanmateo_resp_images_apps_app_info() {
  return array(
    'configure form' => 'opensanmateo_resp_images_app_configure_form', // This form will be render on the app config pag
  );
}

/**
 * Configuration form callback for app
 */
function opensanmateo_resp_images_app_configure_form() {
  $form = array();

  // Present field formatter settings to use for responsive image fields
  $fake_instance = array(
    'display' => array(
      'full' => array(
        'settings' => variable_get('opensanmateo_resp_images_formatter_settings', _opensanmateo_resp_images_get_picture_defaults()),
      ),
    )
  );
  $fake_form_state = array();
  $form['opensanmateo_resp_images_formatter_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Picture formatter settings'),
    '#description' => t('Define the formatter settings to use for the responsive image elements selected below'),
    '#tree' => TRUE,
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );
  $form['opensanmateo_resp_images_formatter_settings'] += picture_field_formatter_settings_form(array(), $fake_instance, 'full', array(), $fake_form_state);

  // Build checkbox list of image field instances in system
  $entities = entity_get_info();
  $fields = field_info_field_map();
  $image_fields = array();
  foreach ($fields as $name => $field) {
    if ('image' === $field['type']) {
      foreach ($field['bundles'] as $entity_type => $bundles) {
        foreach ($bundles as $bundle) {
          $field_instance = field_info_instances($entity_type, $bundle);
          $image_fields[$field_instance[$name]['id']] = implode(' : ', array($entities[$entity_type]['label'], $entities[$entity_type]['bundles'][$bundle]['label'], $field_instance[$name]['label']));
        }
      }
    }
  }
  asort($image_fields);
  $form['opensanmateo_resp_images_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Please select which image field instances you would like to be responsive'),
    '#options' => $image_fields,
    '#default_value' => variable_get('opensanmateo_resp_images_fields', array()),
  );

  return system_settings_form($form);
}
