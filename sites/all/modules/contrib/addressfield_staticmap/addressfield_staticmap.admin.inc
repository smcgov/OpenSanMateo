<?php
/**
 * @file
 * 
 * Contains admin page code for the addressfield static map module.
 */

/**
 * Admin form generation callback 
 */
function addressfield_staticmap_admin_form($form, &$form_state) {
  $address_fields = array(
    '' => t('None'),
  );
  $kml_fields = $address_fields;
  
  $fields = field_info_fields();
  foreach ($fields as $name => $field) {
    // Only display addressfields for this setting
    if ($field['type'] == 'addressfield') {
      $address_fields[$name] = $name;
    }
    
    // Only display file fields that only accept KML uploads
    if ($field['type'] != 'file') {
      continue;
    }
    if (!isset($field['bundles']['node'])) {
      continue;
    }
    foreach ($field['bundles']['node'] as $bundle_name) {
      $field_instance = field_info_instance('node', $name, $bundle_name);
      if ($field_instance['settings']['file_extensions'] == 'kml') {
        $kml_fields[$bundle_name . '|' . $name] = $name . ' (' . $bundle_name . ')';
      }
    }
  }
  
  $apis = array(
    'google_maps' => t('Google Static Maps'),
    'google_maps_api' => t('regular Google Maps with fallback to Static Map'),
    'mapquest' => t('Mapquest'),
  );
  
  $blocks = array('addressfield_block_1', 'addressfield_block_2');
  
  $form['addressfield_staticmap_field_names'] = array(
    '#type' => 'select',
    '#title' => t("Address Field"),
    '#description' => t('The address field(s) that should be used to generate the static map block.'),
    '#default_value' => variable_get('addressfield_staticmap_field_names', ''),
    '#options' => $address_fields,
    '#multiple' => TRUE,
  );
  $form['addressfield_staticmap_field_kml'] = array(
    '#type' => 'select',
    '#title' => t("KML File Field"),
    '#description' => t('The file field(s) and specific bundles that should be used to attach KML files. 
      Will only list file fields that only accept .kml files.'),
    '#default_value' => variable_get('addressfield_staticmap_field_kml', array()),
    '#options' => $kml_fields,
    '#multiple' => TRUE,
  );
  
  foreach ($blocks as $i => $block) {
    $form[$block] = array(
      '#type' => 'fieldset',
      '#title' => t(str_replace("_", " ", $block)),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE
    );
    $form[$block]['addressfield_staticmap_api_key_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t("API Key"),
      '#description' => t('Some services (ex: Mapquest) require an API key to be used.'),
      '#default_value' => variable_get('addressfield_staticmap_api_key_' . $i, ''),
    );
    $form[$block]['addressfield_staticmap_api_' . $i] = array(
      '#type' => 'select',
      '#title' => t("Mapping API"),
      '#description' => t('The API service to use to render static images. Some may require an API key.'),
      '#default_value' => variable_get('addressfield_staticmap_api_' . $i, 'google_maps'),
      '#options' => $apis,
    );
      $form[$block]['addressfield_staticmap_gmap_zoom_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t("Zoom Level"),
      '#description' => t('The resolution of the zoom level to use on the map. Can be between 0 and 21 for Google Static Maps API, and 1 and 16 for Mapquest. Default is 14.'),
      '#default_value' => variable_get('addressfield_staticmap_gmap_zoom_' . $i, 14),
      '#required' => TRUE,
    );
    $form[$block]['addressfield_staticmap_gmap_size_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t("Image Size"),
      '#description' => t('Output size of the map image. Default is 400x400, must be defined in WIDTHxHEIGHT format.'),
      '#default_value' => variable_get('addressfield_staticmap_gmap_size_' . $i, '400x400'),
      '#required' => TRUE,
    );
    $form[$block]['addressfield_staticmap_gmap_type_' . $i] = array(
      '#type' => 'select',
      '#title' => t("Map Type"),
      '#description' => t('The format to use for the rendered map. Hybrid blends satellite and roadmap.'),
      '#default_value' => variable_get('addressfield_staticmap_gmap_type_' . $i, 'roadmap'),
      '#options' => drupal_map_assoc(array('roadmap', 'satellite', 'terrain', 'hybrid')),
    );
    $form[$block]['addressfield_staticmap_gmap_link_' . $i] = array(
      '#type' => 'checkbox',
      '#title' => t("Link to actual Google map"),
      '#description' => t('Check this option to link the static image to a Google map.'),
      '#default_value' => variable_get('addressfield_staticmap_gmap_link_' . $i, FALSE),
    );
    $form[$block]['addressfield_staticmap_gmap_link_target_' . $i] = array(
      '#type' => 'select',
      '#title' => t("Link Target"),
      '#description' => t('The setting for the link.'),
      '#default_value' => variable_get('addressfield_staticmap_gmap_link_target_' . $i, ''),
      '#options' => array(
        '' => t('Default (no target attribute)'),
        '_top' => t('Open link in window root'),
        '_blank' => t('Open link in new window'),
      ),
    );
    $form[$block]['addressfield_staticmap_gmap_icon_url_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t("Custom Google Map Icon URL"),
      '#description' => t('Optional URL for custom icon to use instead of the regular Google map marker. Must be smaller than 64x64.'),
      '#default_value' => variable_get('addressfield_staticmap_gmap_icon_url_' . $i, ''),
    );
    $form[$block]['addressfield_staticmap_directions_' . $i] = array(
      '#type' => 'fieldset',
      '#title' => t("Get Directions link"),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form[$block]['addressfield_staticmap_directions_' . $i]['addressfield_staticmap_directions_link_' . $i] = array(
      '#type' => 'checkbox',
      '#title' => t("Display Get Directions"),
      '#description' => t('Check this option to display a text link to a Google map.'),
      '#default_value' => variable_get('addressfield_staticmap_directions_link_' . $i, FALSE),
    );
    $form[$block]['addressfield_staticmap_directions_' . $i]['addressfield_staticmap_directions_text_' . $i] = array(
      '#type' => 'textfield',
      '#title' => t("Get Directions text"),
      '#description' => t('What this link should use as text.'),
      '#default_value' => variable_get('addressfield_staticmap_directions_text_' . $i, 'Get Directions'),
      '#required' => TRUE,
    );
  }
  return system_settings_form($form);
}

/**
 * Admin form validation callback 
 */
function addressfield_staticmap_admin_form_validate($form, &$form_state) {
  for ($index = 0; $index <= 1; $index++) {
    $zoom = $form_state['values']['addressfield_staticmap_gmap_zoom_' . $index];
    $api = $form_state['values']['addressfield_staticmap_api_' . $index];
    if ($api == 'google_maps') {
      if (empty($zoom) || $zoom < 0 || $zoom > 21 || !is_numeric($zoom)) {
        form_set_error('addressfield_staticmap_gmap_zoom_' . $index, t('Invalid zoom level. Please enter a value from 0 and 21.'));
        return;
      }
    }
    elseif ($api == 'mapquest') {
      if (empty($zoom) || $zoom < 1 || $zoom > 16 || !is_numeric($zoom)) {
        form_set_error('addressfield_staticmap_gmap_zoom_' . $index, t('Invalid zoom level. Please enter a value from 1 and 16.'));
        return;
      }
    }
    
    $size = $form_state['values']['addressfield_staticmap_gmap_size_' . $index];
    if (empty($size) && !preg_match('/^([0-9]+)x([0-9]+)$/', $size)) {
      form_set_error('addressfield_staticmap_gmap_size_' . $index, t('Invalid image size. Please enter a validly formatted dimension (ex: 400x400).'));
      return;
    }
    
    $icon_url = $form_state['values']['addressfield_staticmap_gmap_icon_url_' . $index];
    if (!empty($icon_url) && !valid_url($icon_url)) {
      form_set_error('addressfield_staticmap_gmap_icon_url_' . $index, t('Invalid icon URL.'));
      return;
    }
  
    // Mapquest requires an API key
    $api_key = $form_state['values']['addressfield_staticmap_api_key_' . $index];
    if ($api == 'mapquest' && empty($api_key)) {
      form_set_error('addressfield_staticmap_api_key_' . $index, t('Mapquest requires an API key.'));
      return;
    }
  }
}